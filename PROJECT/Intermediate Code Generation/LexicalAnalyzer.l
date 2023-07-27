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
 
"if"  { yylval.lexeme = strdup(yytext);return IF; }
 
"else"  {yylval.lexeme = strdup(yytext); return ELSE; }
 
"for"   { yylval.lexeme = strdup(yytext);return FOR; }
 
"while"   {yylval.lexeme = strdup(yytext); return WHILE; }
 
"switch" {yylval.lexeme = strdup(yytext); return SWITCH; }
 
"case"  {yylval.lexeme = strdup(yytext); return CASE; }
 
"default"   {yylval.lexeme = strdup(yytext); return DEFAULT; }
 
"break"   { yylval.lexeme = strdup(yytext);return BREAK; }
 
"continue"  { yylval.lexeme = strdup(yytext);return CONTINUE; }
 
"return"  {yylval.lexeme = strdup(yytext); return RETURN; }
 
"int"   {yylval.lexeme = strdup(yytext); return INT; }
 
"float"   { yylval.lexeme = strdup(yytext);return FLOAT; }
 
"char"  { yylval.lexeme = strdup(yytext);return CHAR; }   
 
"void" {yylval.lexeme = strdup(yytext); return VOID; }
 
"main"  {yylval.lexeme = strdup(yytext); return MAIN; }
 
"printf"    { yylval.lexeme = strdup(yytext);return PRINTF; }
 
"!="  {yylval.lexeme = strdup(yytext); return NE; }
 
"=="  {yylval.lexeme = strdup(yytext); return EQ; }
 
">="  {yylval.lexeme = strdup(yytext); return GE; }
 
"<="  { yylval.lexeme = strdup(yytext);return LE; }
 
"&&"  {yylval.lexeme = strdup(yytext); return AND; }
 
"||"  {yylval.lexeme = strdup(yytext); return OR; }
 
"!"   {yylval.lexeme = strdup(yytext); return yytext[0]; }
 
"*"   {yylval.lexeme = strdup(yytext); return yytext[0]; }
 
"/"   { yylval.lexeme = strdup(yytext);return yytext[0]; }
 
"%"   { yylval.lexeme = strdup(yytext);return yytext[0]; }
 
"+"   {yylval.lexeme = strdup(yytext); return yytext[0]; }
 
"-"   {yylval.lexeme = strdup(yytext); return yytext[0]; }
 
"<"   {yylval.lexeme = strdup(yytext); return yytext[0]; }
 
">"   {yylval.lexeme = strdup(yytext); return yytext[0]; }
 
"="   {yylval.lexeme = strdup(yytext); return yytext[0]; }
 
{character_literal}   {yylval.lexeme = strdup(yytext); return CHARACTER; }
 
{string_literal}  {yylval.lexeme = strdup(yytext); return STRING; }
 
{integer}   {yylval.lexeme = strdup(yytext); return INTEGER; }
 
{float}   {yylval.lexeme = strdup(yytext); return DECIMAL; }
 
{punctuator}  {yylval.lexeme = strdup(yytext); return yytext[0]; }
 
{identifier}  {yylval.lexeme = strdup(yytext); return IDENTIFIER; }
 
[\n]  { yylineno++; }
 
{comment}   ;
 
{header}  ;
 
.   ;
 
%%
 
int yywrap()
{
	return(1);
}
 
 
 