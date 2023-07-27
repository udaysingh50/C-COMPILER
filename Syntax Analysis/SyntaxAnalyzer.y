%{
#include <stdio.h> 

int yylex(void);
extern FILE *yyin;
%}

%token IDENTIFIER DECIMAL INTEGER STRING CHARACTER
%token INT FLOAT CHAR VOID
%token IF ELSE FOR WHILE SWITCH CASE DEFAULT
%token BREAK CONTINUE RETURN
%token MAIN PRINTF

%left OR
%left AND
%left EQ NE
%left '<' '>' GE LE
%left '+' '-'
%left '*' '/' '%'
%right '!'

%%
s       : program       { printf("valid input"); return 1; }

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

array_access    : IDENTIFIER '[' expression ']'
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
                        | IDENTIFIER '=' expression
                        ;

expression      : '!' expression
                | expression '+' expression
                | expression '-' expression
                | expression '*' expression
                | expression '/' expression
                | expression '%' expression
                | expression '<' expression
                | expression '>' expression
                | expression EQ expression
                | expression NE expression
                | expression GE expression
                | expression LE expression
                | expression AND expression
                | expression OR expression
                | '(' expression ')'
                | operand
                ;

operand         : variable
                | function_call
                | primitive_literal
                ;

assignment      : variable '=' expression
                ;

loop_expression         : expression
                        | assignment
                        | 
                        ;

for     : FOR '(' loop_expression ';' loop_expression ';' loop_expression ')' statement
        | FOR '(' declaration ';' loop_expression ';' loop_expression ')' statement
        ;

while   : WHILE '(' loop_expression ')' statement
        ;

switch  : SWITCH '(' expression ')' statement
        ;

case    : CASE integer_literal ':' statement
        | DEFAULT ':' statement
        ;

if      : IF '(' expression ')' statement
        | IF '(' expression ')' statement ELSE statement
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
    return 0;
}