%{
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
    
    void yyerror(const char *s);
    int yylex();
    int yywrap();
    extern FILE* yyin;
    extern int countn;
    extern char* yytext;
    struct Quadruple {
        int index;
        char Op[20];
        char arg1[20];
        char arg2[20];
        char result[20];
    } quad_node[1000];
    int cnt=0;
    int label = 0;
    int arr[100];
    int top = -1;
    int tempVariable = 0;
    char* genTempVariable(int id){
        char* temp = (char*)malloc(10*sizeof(char));
        temp[0] = 'T';
        snprintf(temp, 10, "T%d", id);
        return temp;
    }
    int gencode(char* lhs, char* op, char* rhs){
        //printf("T%d = %s%s%s\n", tempVariable, lhs, op, rhs);
        quad_node[cnt].index=cnt;
        strcpy(quad_node[cnt].Op,op);
        strcpy(quad_node[cnt].arg1,lhs);
        strcpy(quad_node[cnt].arg2,rhs);
        char temp_var[5]="T";
        char temp_1[5]="";
        sprintf(temp_1, "%d", tempVariable);
        strcat(temp_var,temp_1);
        strcpy(quad_node[cnt].result,temp_var);
        cnt++;
        return tempVariable;
    }
    void assignment(char* lhs, char* rhs){
        //printf("%s = %s \n", lhs, rhs);
        quad_node[cnt].index=cnt;
        strcpy(quad_node[cnt].Op,"=");
        strcpy(quad_node[cnt].arg1,rhs);
        strcpy(quad_node[cnt].arg2,"");
        strcpy(quad_node[cnt].result,lhs);
        cnt++;
    }
%}
%union{
    char* lexeme;
}
 
%token<lexeme> IDENTIFIER DECIMAL INTEGER STRING CHARACTER
%token<lexeme> INT FLOAT CHAR VOID
%token<lexeme> IF ELSE FOR WHILE SWITCH CASE DEFAULT
%token<lexeme> BREAK CONTINUE RETURN
%token<lexeme> MAIN PRINTF
 
%left<lexeme> OR
%left<lexeme> AND
%left<lexeme> EQ NE
%left<lexeme> '<' '>' GE LE
%left<lexeme> '+' '-'
%left<lexeme> '*' '/' '%'
%right <lexeme>'!'
%type <lexeme> s program functions main statements statement datatype primitive_literal integer_literal literal function formal_parameters formal_parameter variable actual_parameters array_access expression if non_if switch assignment declaration looping compound printf jump return case function_call while for declaration_list array_declaration non_array_declaration value_list value_block operand  loop_expression
%%
s       : program       { printf("valid input\n"); return 1; }
 
program         : functions main '(' ')' '{' statements '}'
                ;
 
statements      : statements statement 
                | 
                ;
 
datatype        : INT
                | FLOAT
                | CHAR
                ;
 
primitive_literal       : integer_literal
                        | DECIMAL
                        ;
 
integer_literal         : INTEGER
                        | CHARACTER
                        ;
 
literal         : primitive_literal
                | STRING
                ;
 
functions       : functions function 
                | 
                ;
 
function        : datatype IDENTIFIER '(' formal_parameters ')' '{' statements '}'
                | IDENTIFIER '(' formal_parameters ')' '{' statements '}'
                | VOID IDENTIFIER '(' formal_parameters ')' '{' statements '}'
                ;
 
formal_parameters       : formal_parameters ',' formal_parameter
                        | formal_parameter
                        | 
                        ;
 
formal_parameter        : datatype variable
                        ;
 
actual_parameters       : actual_parameters ',' variable
                        | variable
                        | 
                        ;
 
main    : datatype MAIN
        | VOID MAIN
        | MAIN
        ;
 
variable        : IDENTIFIER
                | MAIN
                | PRINTF
                | array_access
                ;
 
array_access    : IDENTIFIER '[' expression ']' {             
                        int a = gencode("4","*",$3);
                        char* tempVar = genTempVariable(a);
                        tempVariable++;
                        int b = gencode("","&",$1);
                        char* tempVar2 = genTempVariable(b);
                        tempVariable++;
                        int c = gencode(tempVar,"+",tempVar2);
                        char* tempVar3 = genTempVariable(c);
                        tempVariable++;
                        int d = gencode("","*",tempVar3);
                        char* tempVar4 = genTempVariable(d);
                        tempVariable++;
                        $$ = tempVar4;
                }
                | IDENTIFIER '[' expression ']' '[' expression ']'
                ;
 
statement       : if
                | non_if
                ;
 
non_if  : switch
	| expression ';'
        | assignment ';'
        | declaration ';'
        | looping
        | compound
        | printf ';'
        | jump ';'
        | return ';'
	| case
        | ';'
        ;
 
printf  : PRINTF '(' STRING ')'
        | PRINTF '(' STRING ',' actual_parameters ')'
        ;
 
compound        : '{' statements '}'
                ;
 
function_call   : IDENTIFIER '(' actual_parameters ')'
                ;
 
jump    : BREAK
        | CONTINUE
        ;
 
return  : RETURN STRING
        | RETURN expression
        | RETURN
        ;
 
looping         : while
                | for
                ;
 
declaration     : datatype declaration_list
                ;
 
declaration_list        : declaration_list ',' array_declaration
                        | declaration_list ',' non_array_declaration
                        | array_declaration
                        | non_array_declaration
                        ;
 
array_declaration       : array_access
                        | IDENTIFIER '[' expression ']' '=' '{' value_list '}'
                        | IDENTIFIER '[' ']' '=' '{' value_list '}'
                        | IDENTIFIER '[' expression ']' '[' expression ']' '=' '{' value_list '}'
                        | IDENTIFIER '[' ']' '[' expression ']' '=' '{' value_list '}'
                        | IDENTIFIER '[' expression ']' '[' expression ']' '=' '{' value_block '}'
                        | IDENTIFIER '[' ']' '[' expression ']' '=' '{' value_block '}'
			            | IDENTIFIER '[' ']' '[' expression ']'
                        | IDENTIFIER '[' expression ']' '=' STRING 
                        | IDENTIFIER '[' ']' '=' STRING 
                        ;
 
value_list      : primitive_literal
                | value_list ',' primitive_literal
                ;
 
value_block     : '{' value_list '}'
                | '{' value_list '}' ',' value_block
                ;
 
non_array_declaration   : IDENTIFIER
                        | IDENTIFIER '=' expression {
                                assignment($1,$3);
                                $$=$1;
                        }
                        ;
 
expression      : '!' expression{
                    int a = gencode("","!",$2);
                    char* tempVar = genTempVariable(a);
                    $$ = tempVar;
                    tempVariable++;   
                }
                | expression '+' expression{
                    int a = gencode($1,"+",$3);
                    char* tempVar = genTempVariable(a);
                    $$ = tempVar;
                    tempVariable++;
                }
                | expression '-' expression{
                        int a = gencode($1,"-",$3);
                        char* tempVar = genTempVariable(a);
                        $$ = tempVar;
                        tempVariable++;
                }
                | expression '*' expression{
                        int a = gencode($1,"*",$3);
                        char* tempVar = genTempVariable(a);
                        $$ = tempVar;
                        tempVariable++;
                }
                | expression '/' expression {
                        int a = gencode($1,"/",$3);
                        char* tempVar = genTempVariable(a);
                        $$ = tempVar;
                        tempVariable++;
                }
                | expression '%' expression {
                        int a = gencode($1,"%",$3);
                        char* tempVar = genTempVariable(a);
                        $$ = tempVar;
                        tempVariable++;
                }
                | expression '<' expression{
                        int a = gencode($1,"<",$3);
                        char* tempVar = genTempVariable(a);
                        $$ = tempVar;
                        tempVariable++;
                }
                | expression '>' expression{
                        int a = gencode($1,">",$3);
                        char* tempVar = genTempVariable(a);
                        $$ = tempVar;
                        tempVariable++;
                }
                | expression EQ expression{
                        int a = gencode($1,"==",$3);
                        char* tempVar = genTempVariable(a);
                        $$ = tempVar;
                        tempVariable++;
                }
                | expression NE expression{
                        int a = gencode($1,"!=",$3);
                        char* tempVar = genTempVariable(a);
                        $$ = tempVar;
                        tempVariable++;
                }
                | expression GE expression{
                        int a = gencode($1,">=",$3);
                        char* tempVar = genTempVariable(a);
                        $$ = tempVar;
                        tempVariable++;
                }
                | expression LE expression{
                        int a = gencode($1,"<=",$3);
                        char* tempVar = genTempVariable(a);
                        $$ = tempVar;
                        tempVariable++;
                }
                | expression AND expression {
                        int a = gencode($1,"&&",$3);
                        char* tempVar = genTempVariable(a);
                        $$ = tempVar;
                        tempVariable++;
                }
                | expression OR expression {
                        int a = gencode($1,"||",$3);
                        char* tempVar = genTempVariable(a);
                        $$ = tempVar;
                        tempVariable++;
                }
                | '(' expression ')'
                | operand
                ;
 
operand         : variable
                | function_call
                | primitive_literal
                ;
 
assignment      : variable '=' expression{
                    assignment($1,$3);
                    $$=$1;
}
                ;
 
loop_expression         : expression
                        | assignment
                        | 
                        ;
 
for     : FOR '(' {;} loop_expression {;} ';' { top++; printf("L%d: \n", label); arr[top] = label; label++; } loop_expression ';' loop_expression ')' '{' statements '}' {printf("iftrue(%s) goto L%d\n", $8, arr[top--]);}
        | FOR '(' {;} declaration {;} ';' { top++; printf("L%d: \n", label); arr[top] = label; label++; } loop_expression ';' loop_expression ')' '{'statements '}' {printf("iftrue(%s) goto L%d\n", $8, arr[top--]);}
        ;
 
while   : WHILE { top++; printf("L%d: \n", label); arr[top] = label; label++; } '(' loop_expression ')' '{'statements '}'  {printf("iftrue(%s) goto L%d\n", $4, arr[top--]);}
        ;        
 
switch  : SWITCH '(' expression ')' statements
        ;
 
case    : CASE integer_literal ':' statements
        | DEFAULT ':' statements
        ;
 
if      : IF '(' expression ')'{ top++; printf("iffalse(%s) goto L%d\n",$3,label); arr[top] = label; label++; } '{' statements '}' {printf("L%d: \n", arr[top--]);} elseStatment
;


elseStatment : ELSE '{' statements '}'
        |
        ;
%%
 
void yyerror(const char* s) {
    extern int yylineno;
    printf("syntax error");
    return;
}
 
int main() {
    yyin = fopen("code.txt", "r");
    yyparse();
    printf("ind\top\targ1\targ2\tres\n");
    for(int i=0;i<cnt;i++){
        printf("%d",quad_node[i].index);
        printf("\t");
        printf("%s",quad_node[i].Op);
        printf("\t");
        printf("%s",quad_node[i].arg1);
        printf("\t");
        printf("%s",quad_node[i].arg2);
        printf("\t");
        printf("%s",quad_node[i].result);
        printf("\n");
    }
    return 0;
}