%{
    #include "y.tab.h"
    #include <string.h>
%}

%option yylineno

all_char .*

comment ([/][/]{all_char}[\n])|("/*"([^*]|\*+[^*/])*\*+"/")
identifier [a-zA-Z_][a-zA-Z0-9_]*
float [0-9]+([.][0-9]+)?[eE][+\-]?[0-9]+|[+\-]?[0-9]+[.][0-9]+
integer [0-9]+
punctuator [()\[\]\"'{};:,&]
character_literal ['].[']
string_literal ["]{all_char}["]
header "#include"{all_char}[>"]

%%

"if"  { return IF; }

"else"  { return ELSE; }

"for"   { return FOR; }

"while"   { return WHILE; }

"switch" { return SWITCH; }

"case"  { return CASE; }

"default"   { return DEFAULT; }

"break"   { return BREAK; }

"continue"  { return CONTINUE; }

"return"  { return RETURN; }

"int"   { return INT; }

"float"   { return FLOAT; }

"char"  { return CHAR; }   

"void" { return VOID; }

"main"  { return MAIN; }

"printf"    { return PRINTF; }

"!="  { return NE; }

"=="  { return EQ; }

">="  { return GE; }

"<="  { return LE; }

"&&"  { return AND; }

"||"  { return OR; }

"!"   { return yytext[0]; }

"*"   { return yytext[0]; }

"/"   { return yytext[0]; }

"%"   { return yytext[0]; }

"+"   { return yytext[0]; }

"-"   { return yytext[0]; }

"<"   { return yytext[0]; }

">"   { return yytext[0]; }

"="   { return yytext[0]; }

{character_literal}   { return CHARACTER; }

{string_literal}  { return STRING; }

{integer}   { return INTEGER; }

{float}   { return DECIMAL; }

{punctuator}  { return yytext[0]; }

{identifier}  { return IDENTIFIER; }

[\n]  { yylineno++; }

{comment}   ;

{header}  ;

.   ;

%%

yywrap()
{
	return(1);
}