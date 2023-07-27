/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    DECIMAL = 259,
    INTEGER = 260,
    STRING = 261,
    CHARACTER = 262,
    INT = 263,
    FLOAT = 264,
    CHAR = 265,
    IF = 266,
    ELSE = 267,
    FOR = 268,
    WHILE = 269,
    SWITCH = 270,
    CASE = 271,
    DEFAULT = 272,
    BREAK = 273,
    CONTINUE = 274,
    RETURN = 275,
    MAIN = 276,
    PRINTF = 277,
    OR = 278,
    AND = 279,
    EQ = 280,
    NE = 281,
    GE = 282,
    LE = 283
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define DECIMAL 259
#define INTEGER 260
#define STRING 261
#define CHARACTER 262
#define INT 263
#define FLOAT 264
#define CHAR 265
#define IF 266
#define ELSE 267
#define FOR 268
#define WHILE 269
#define SWITCH 270
#define CASE 271
#define DEFAULT 272
#define BREAK 273
#define CONTINUE 274
#define RETURN 275
#define MAIN 276
#define PRINTF 277
#define OR 278
#define AND 279
#define EQ 280
#define NE 281
#define GE 282
#define LE 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
