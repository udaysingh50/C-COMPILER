%{
    #include <stdio.h>
    #include <string.h>

    typedef struct SymbolTable {
        int lineNumber;
        char lexeme[1000];
        char tokenType[50];
    } SymbolTable;

    SymbolTable symbolTable[10000];
    int ind = 0;
    int lineNumber = 1;
%}

all_char .*

comment ([/][/]{all_char}[\n])|("/*"([^*]|\*+[^*/])*\*+"/")
identifier [a-zA-Z_][a-zA-Z0-9_]*
operator "=="|"<="|">="|"!="|"&&"|"\|\|"|[+\-*\/%=<>!]
numeric_literal [+\-]?[0-9]+([.][0-9]+)?([eE][+\-]?[0-9]+)?
keyword "printf"|"scanf"|"for"|"while"|"if"|"else"|"switch"|"case"|"break"|"continue"|"int"|"float"|"char"|"main"|"return"|"default"
punctuator [()\[\]\"'{};:,&]
character_literal ['].[']
string_literal ["]{all_char}["]
header "#include"{all_char}[>"]

%%

{keyword}           { 
                      symbolTable[ind].lineNumber = lineNumber; 
                      strcpy(symbolTable[ind].lexeme, yytext); 
                      strcpy(symbolTable[ind].tokenType,"KEYWORD"); 
                      ind++; 
                    }

{character_literal} { 
                      symbolTable[ind].lineNumber = lineNumber; 
                      strcpy(symbolTable[ind].lexeme, yytext); 
                      strcpy(symbolTable[ind].tokenType,"CHARACTER_LITERAL"); 
                      ind++; 
                    }

{string_literal}    { 
                      symbolTable[ind].lineNumber = lineNumber; 
                      strcpy(symbolTable[ind].lexeme, yytext); 
                      strcpy(symbolTable[ind].tokenType,"STRING_LITERAL"); 
                      ind++; 
                    }

{numeric_literal}   { 
                      symbolTable[ind].lineNumber = lineNumber; 
                      strcpy(symbolTable[ind].lexeme, yytext); 
                      strcpy(symbolTable[ind].tokenType,"NUMERIC_LITERAL"); 
                      ind++; 
                    }

{operator}          { 
                      symbolTable[ind].lineNumber = lineNumber; 
                      strcpy(symbolTable[ind].lexeme, yytext); 
                      strcpy(symbolTable[ind].tokenType,"OPERATOR"); 
                      ind++; 
                    }

{punctuator}        { 
                      symbolTable[ind].lineNumber = lineNumber; 
                      strcpy(symbolTable[ind].lexeme, yytext); 
                      strcpy(symbolTable[ind].tokenType,"PUNCTUATOR"); 
                      ind++; 
                    }

{identifier}        { 
                      symbolTable[ind].lineNumber = lineNumber; 
                      strcpy(symbolTable[ind].lexeme, yytext); 
                      strcpy(symbolTable[ind].tokenType,"IDENTIFIER"); 
                      ind++; 
                    }

"\n"                { lineNumber++; }


{comment}           {
                      for(int i=0; i<yyleng; i++) {
                        if(yytext[i] == '\n') {
                           lineNumber++;
                        }
                      }
                    }

{header}            ;

.                   ;

%%

int main() {
	yyin = fopen("code.txt", "r");
	
	yylex();	

  int printf_error[10000];
  int printf_ind = 0;

  for(int i=0; i<ind; i++) {
      printf("%d\t%s\t\t\t%s\n", symbolTable[i].lineNumber, symbolTable[i].lexeme, symbolTable[i].tokenType);

      if(strcmp(symbolTable[i].lexeme, "printf") == 0) {
          if(i+3 >= ind) { printf_error[printf_ind++] = symbolTable[i].lineNumber; }
          else {
              int is_ob = (strcmp(symbolTable[i+1].lexeme, "(") == 0);

              if(!is_ob) { printf_error[printf_ind++] = symbolTable[i].lineNumber; }
              else {
                int is_string = (strcmp(symbolTable[i+2].tokenType, "STRING_LITERAL") ==  0);
                
                if(!(is_string)) { printf_error[printf_ind++] = symbolTable[i].lineNumber; }
                else {
                  int num_percent = 0;
                  int is_valid_string = 1;

                  for(int j=0; j<strlen(symbolTable[i+2].lexeme); j++) {
                    if(symbolTable[i+2].lexeme[j] == '%') {
                      if(symbolTable[i+2].lexeme[j+1] == 'd' || symbolTable[i+2].lexeme[j+1] == 'f' || symbolTable[i+2].lexeme[j+1] == 'c') {
                        num_percent++;
                      }
                      else if(symbolTable[i+2].lexeme[j+1] == '%') {
                        j += 1;
                        continue;
                      }
                      else {
                        is_valid_string = 0;
                        break;
                      }
                    }
                  }

                  if(!(is_valid_string)) { printf_error[printf_ind++] = symbolTable[i].lineNumber; }
                  else {
                    int is_valid_vars = 1;

                    for(int j=0; j<2*num_percent; j+=2) {
                      if(i+4+j >= ind) { is_valid_vars = 0; break; }

                      if(symbolTable[i+3+j].lexeme[0] == ',' && strcmp(symbolTable[i+4+j].tokenType, "IDENTIFIER") == 0) {
                        continue;
                      }
                      else {
                        is_valid_vars = 0; break;
                      }
                    }

                    if(!(is_valid_vars)) { printf_error[printf_ind++] = symbolTable[i].lineNumber; }
                    else {
                      if(i+2*num_percent+3 >= ind) { printf_error[printf_ind++] = symbolTable[i].lineNumber; }
                      else {
                        int is_cb = (strcmp(symbolTable[i+2*num_percent+3].lexeme, ")") == 0);

                        if(!(is_cb)) { printf_error[printf_ind++] = symbolTable[i].lineNumber; }
                    }
                  }
                }
              }
          }
      }
    }
  }

  for(int i=0; i<printf_ind; i++) {
    printf("Invalid printf at line number: %d\n", printf_error[i]);
  }
}
