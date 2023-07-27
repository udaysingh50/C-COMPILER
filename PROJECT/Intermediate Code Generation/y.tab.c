/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "CodeGeneration.y"

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

#line 125 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    VOID = 266,
    IF = 267,
    ELSE = 268,
    FOR = 269,
    WHILE = 270,
    SWITCH = 271,
    CASE = 272,
    DEFAULT = 273,
    BREAK = 274,
    CONTINUE = 275,
    RETURN = 276,
    MAIN = 277,
    PRINTF = 278,
    OR = 279,
    AND = 280,
    EQ = 281,
    NE = 282,
    GE = 283,
    LE = 284
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
#define VOID 266
#define IF 267
#define ELSE 268
#define FOR 269
#define WHILE 270
#define SWITCH 271
#define CASE 272
#define DEFAULT 273
#define BREAK 274
#define CONTINUE 275
#define RETURN 276
#define MAIN 277
#define PRINTF 278
#define OR 279
#define AND 280
#define EQ 281
#define NE 282
#define GE 283
#define LE 284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 55 "CodeGeneration.y"

    char* lexeme;

#line 239 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   837

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  119
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  255

#define YYUNDEFTOK  2
#define YYMAXUTOK   284


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,     2,     2,    36,     2,     2,
      38,    39,    34,    32,    42,    33,     2,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    47,    45,
      28,    46,    29,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,    44,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,    41,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    74,    74,    76,    79,    80,    83,    84,    85,    88,
      89,    92,    93,   100,   101,   104,   105,   106,   109,   110,
     111,   114,   117,   118,   119,   122,   123,   124,   127,   128,
     129,   130,   133,   148,   151,   152,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   168,   169,   172,
     175,   178,   179,   182,   183,   184,   187,   188,   191,   194,
     195,   196,   197,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   212,   213,   216,   217,   220,   221,   227,
     233,   239,   245,   251,   257,   263,   269,   275,   281,   287,
     293,   299,   305,   311,   312,   315,   316,   317,   320,   326,
     327,   328,   331,   331,   331,   331,   332,   332,   332,   332,
     335,   335,   338,   341,   342,   345,   345,   345,   349,   350
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "DECIMAL", "INTEGER",
  "STRING", "CHARACTER", "INT", "FLOAT", "CHAR", "VOID", "IF", "ELSE",
  "FOR", "WHILE", "SWITCH", "CASE", "DEFAULT", "BREAK", "CONTINUE",
  "RETURN", "MAIN", "PRINTF", "OR", "AND", "EQ", "NE", "'<'", "'>'", "GE",
  "LE", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'('", "')'", "'{'",
  "'}'", "','", "'['", "']'", "';'", "'='", "':'", "$accept", "s",
  "program", "statements", "datatype", "primitive_literal",
  "integer_literal", "functions", "function", "formal_parameters",
  "formal_parameter", "actual_parameters", "main", "variable",
  "array_access", "statement", "non_if", "printf", "compound",
  "function_call", "jump", "return", "looping", "declaration",
  "declaration_list", "array_declaration", "value_list", "value_block",
  "non_array_declaration", "expression", "operand", "assignment",
  "loop_expression", "for", "$@1", "$@2", "$@3", "$@4", "$@5", "$@6",
  "while", "$@7", "switch", "case", "if", "$@8", "$@9", "elseStatment", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    60,    62,
     283,   284,    43,    45,    42,    47,    37,    33,    40,    41,
     123,   125,    44,    91,    93,    59,    61,    58
};
# endif

#define YYPACT_NINF (-214)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-107)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -214,    45,  -214,   225,  -214,    14,  -214,  -214,  -214,    15,
    -214,    22,  -214,    27,    96,    41,  -214,    51,  -214,    44,
       7,     8,  -214,    96,    96,    82,    48,  -214,  -214,  -214,
    -214,    86,    96,    42,    59,  -214,    65,  -214,  -214,    88,
     103,   236,    28,  -214,  -214,  -214,    65,    65,  -214,  -214,
    -214,  -214,   648,  -214,   275,  -214,  -214,   114,   129,  -214,
     141,    26,   152,  -214,  -214,    55,   170,  -214,  -214,  -214,
     200,   163,  -214,  -214,   168,  -214,   169,   171,  -214,   172,
     160,   175,  -214,  -214,  -214,  -214,  -214,     7,  -214,   753,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,   167,  -214,   314,   353,    65,   147,   183,
      65,   176,  -214,  -214,   801,   218,   392,    77,  -214,   184,
    -214,  -214,    65,  -214,  -214,  -214,  -214,  -214,  -214,    91,
    -214,  -214,   235,   273,   310,   310,   137,   137,   137,   137,
     142,   142,  -214,  -214,  -214,    65,  -214,  -214,   769,    65,
      96,    65,   785,  -214,   626,    93,  -214,     4,    65,   200,
     801,  -214,     7,   669,  -214,   801,  -214,  -214,  -214,   186,
    -214,   626,  -214,     7,    94,   690,   801,  -214,  -214,  -214,
    -214,   187,   197,   204,   191,   626,   102,    65,     6,   104,
    -214,  -214,  -214,  -214,  -214,   711,  -214,    90,    65,    11,
     431,    65,    65,   470,   226,  -214,    58,   732,  -214,    90,
    -214,   230,   241,  -214,   192,  -214,    90,   242,   107,   297,
      65,    65,     9,  -214,   271,  -214,   274,  -214,   286,   288,
      90,   118,   306,     9,  -214,   308,   309,   156,  -214,  -214,
     165,   312,   509,  -214,  -214,   322,  -214,  -214,  -214,   548,
     587,   326,  -214,  -214,  -214
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      14,     0,     2,     0,     1,     0,     6,     7,     8,     0,
      27,     0,    13,     0,    20,     0,    26,     0,    25,     0,
       0,     0,    19,    20,    20,     0,    28,    29,    30,    21,
      31,     0,     0,     0,     0,     5,     0,     5,    18,     0,
       0,     0,    28,    10,    11,    12,     0,     0,    97,     9,
      95,    96,     0,    94,     0,     5,     5,     0,     0,   110,
       0,     0,     0,    51,    52,    55,    30,     5,     3,    46,
       0,    95,     4,    35,     0,    41,     0,     0,    40,     0,
       0,     0,    57,    56,    36,    45,    34,    24,    79,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    32,    16,     0,     0,     0,   102,     0,
       0,     0,     5,    53,    54,     0,     0,    77,    63,    58,
      61,    62,     0,    42,    43,    44,    39,    37,    38,     0,
      23,    93,    92,    91,    87,    88,    85,    86,    89,    90,
      80,    81,    82,    83,    84,     0,    17,    15,     0,   101,
       0,   101,     0,     5,   114,     0,    49,     0,     0,     0,
      98,    50,     0,     0,   115,    99,   100,   103,   107,     0,
       5,   113,    47,    24,     0,     0,    78,    59,    60,    22,
      33,     0,     0,     0,     0,   112,     0,     0,     0,    32,
       5,   104,   108,     5,    48,     0,    72,     0,     0,     0,
       0,   101,   101,     0,    70,    73,     0,     0,    71,     0,
     116,     0,     0,   111,     0,    65,     0,    33,     0,   119,
     101,   101,     0,    74,     0,    64,     0,   117,     0,     0,
       0,     0,     0,     0,     5,     0,     0,     0,    67,    69,
       0,     0,     0,     5,     5,    75,    66,    68,   118,     0,
       0,     0,   105,   109,    76
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -214,  -214,  -214,   -32,   122,  -194,   289,  -214,  -214,   140,
     345,   205,  -214,   -20,   -69,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,   229,  -214,   221,  -190,  -213,   222,    17,
    -214,  -147,  -145,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    41,    70,    48,    49,     3,    12,    21,
      22,   129,    13,    50,    30,    72,    73,    74,    75,    51,
      76,    77,    78,    79,   119,   120,   206,   232,   121,    80,
      53,    81,   167,    82,   149,   182,   201,   150,   183,   202,
      83,   109,    84,    85,    86,   181,   219,   227
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      29,   118,   166,   205,   166,    54,   169,    42,    43,    44,
      26,    45,   196,    43,    44,   205,    45,   208,    15,   218,
     241,    71,   223,   105,   106,    17,    27,    28,   205,    27,
      28,    44,   231,    45,    71,   116,   205,    16,   254,   205,
     237,    46,    47,   240,    18,     4,   197,    31,   174,   230,
      32,   209,    14,    52,   166,   166,   211,   212,    42,    43,
      44,   113,    45,    88,    89,    19,    87,   130,    42,    43,
      44,    36,    45,   166,   166,   228,   229,    27,    28,    23,
     154,    39,   114,    25,    32,    71,    71,    27,    28,    24,
     118,    36,    46,    47,    43,    44,    71,    45,    40,   215,
     216,    32,    46,    47,     6,     7,     8,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     157,   171,    35,   158,   148,    11,    37,   152,    55,    71,
     161,    71,   172,   162,    71,   173,    20,   187,   185,   160,
     188,   194,   179,    56,   162,    20,    20,   198,   225,   216,
     199,    71,   107,   130,    20,  -106,  -106,  -106,   200,   238,
     216,   203,   163,    33,    34,    71,   165,   108,   165,    98,
      99,   100,   101,   102,   175,   176,   100,   101,   102,   110,
      71,    71,    71,    71,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   245,   216,   112,
      71,    71,   242,   117,   195,   127,   246,   216,   115,   122,
     145,   249,   250,   123,   124,   207,   125,   126,   165,   165,
     128,   151,    71,   153,   155,   184,   159,   190,     5,    71,
      71,   193,   222,     6,     7,     8,     9,   165,   165,    42,
      43,    44,   191,    45,     6,     7,     8,    10,    57,   192,
      58,    59,    60,    61,    62,    63,    64,    65,    27,    66,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   214,    46,    47,   220,    67,    68,    42,    43,
      44,    69,    45,     6,     7,     8,   221,    57,   224,    58,
      59,    60,    61,    62,    63,    64,    65,    27,    66,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     226,   233,    46,    47,   234,    67,   104,    42,    43,    44,
      69,    45,     6,     7,     8,   235,    57,   236,    58,    59,
      60,    61,    62,    63,    64,    65,    27,    66,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   239,   243,   244,
     111,    46,    47,   247,    67,   146,    42,    43,    44,    69,
      45,     6,     7,     8,   251,    57,   230,    58,    59,    60,
      61,    62,    63,    64,    65,    27,    66,    38,   186,   168,
     177,   178,     0,     0,     0,     0,     0,     0,     0,     0,
      46,    47,     0,    67,   147,    42,    43,    44,    69,    45,
       6,     7,     8,     0,    57,     0,    58,    59,    60,    61,
      62,    63,    64,    65,    27,    66,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    46,
      47,     0,    67,   156,    42,    43,    44,    69,    45,     6,
       7,     8,     0,    57,     0,    58,    59,    60,    61,    62,
      63,    64,    65,    27,    66,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    46,    47,
       0,    67,   210,    42,    43,    44,    69,    45,     6,     7,
       8,     0,    57,     0,    58,    59,    60,    61,    62,    63,
      64,    65,    27,    66,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    46,    47,     0,
      67,   213,    42,    43,    44,    69,    45,     6,     7,     8,
       0,    57,     0,    58,    59,    60,    61,    62,    63,    64,
      65,    27,    66,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    46,    47,     0,    67,
     248,    42,    43,    44,    69,    45,     6,     7,     8,     0,
      57,     0,    58,    59,    60,    61,    62,    63,    64,    65,
      27,    66,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    46,    47,     0,    67,   252,
      42,    43,    44,    69,    45,     6,     7,     8,     0,    57,
       0,    58,    59,    60,    61,    62,    63,    64,    65,    27,
      66,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    46,    47,     0,    67,   253,    42,
      43,    44,    69,    45,     6,     7,     8,     0,    57,     0,
      58,    59,    60,    61,    62,    63,    64,    65,    27,    66,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    46,    47,     0,    67,     0,     0,     0,
       0,    69,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,     0,     0,     0,     0,     0,
       0,     0,   103,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,     0,
       0,     0,     0,   180,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,     0,     0,     0,
       0,     0,     0,     0,   189,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,     0,     0,
       0,     0,     0,     0,     0,   204,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,     0,
       0,     0,     0,     0,     0,     0,   217,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
       0,     0,   131,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,     0,     0,   164,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,     0,     0,   170,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102
};

static const yytype_int16 yycheck[] =
{
      20,    70,   149,   197,   151,    37,   151,     3,     4,     5,
       3,     7,     6,     4,     5,   209,     7,     6,     3,   209,
     233,    41,   216,    55,    56,     3,    22,    23,   222,    22,
      23,     5,   222,     7,    54,    67,   230,    22,   251,   233,
     230,    37,    38,   233,    22,     0,    40,    39,    44,    40,
      42,    40,    38,    36,   201,   202,   201,   202,     3,     4,
       5,     6,     7,    46,    47,    38,    38,    87,     3,     4,
       5,    43,     7,   220,   221,   220,   221,    22,    23,    38,
     112,    39,    65,    39,    42,   105,   106,    22,    23,    38,
     159,    43,    37,    38,     4,     5,   116,     7,    39,    41,
      42,    42,    37,    38,     8,     9,    10,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
      43,   153,    40,    46,   107,     3,    40,   110,    40,   149,
      39,   151,    39,    42,   154,    42,    14,    43,   170,   122,
      46,    39,   162,    40,    42,    23,    24,    43,    41,    42,
      46,   171,    38,   173,    32,     8,     9,    10,   190,    41,
      42,   193,   145,    23,    24,   185,   149,    38,   151,    32,
      33,    34,    35,    36,   157,   158,    34,    35,    36,    38,
     200,   201,   202,   203,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    41,    42,    47,
     220,   221,   234,     3,   187,    45,    41,    42,    38,    46,
      43,   243,   244,    45,    45,   198,    45,    45,   201,   202,
      45,    38,   242,    47,     6,    39,    42,    40,     3,   249,
     250,    40,    40,     8,     9,    10,    11,   220,   221,     3,
       4,     5,    45,     7,     8,     9,    10,    22,    12,    45,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    46,    37,    38,    45,    40,    41,     3,     4,
       5,    45,     7,     8,     9,    10,    45,    12,    46,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      13,    40,    37,    38,    40,    40,    41,     3,     4,     5,
      45,     7,     8,     9,    10,    39,    12,    39,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    41,    40,    40,
      61,    37,    38,    41,    40,    41,     3,     4,     5,    45,
       7,     8,     9,    10,    42,    12,    40,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    32,   173,   150,
     159,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    38,    -1,    40,    41,     3,     4,     5,    45,     7,
       8,     9,    10,    -1,    12,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      38,    -1,    40,    41,     3,     4,     5,    45,     7,     8,
       9,    10,    -1,    12,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      -1,    40,    41,     3,     4,     5,    45,     7,     8,     9,
      10,    -1,    12,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,
      40,    41,     3,     4,     5,    45,     7,     8,     9,    10,
      -1,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    40,
      41,     3,     4,     5,    45,     7,     8,     9,    10,    -1,
      12,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    40,    41,
       3,     4,     5,    45,     7,     8,     9,    10,    -1,    12,
      -1,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    -1,    40,    41,     3,
       4,     5,    45,     7,     8,     9,    10,    -1,    12,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    38,    -1,    40,    -1,    -1,    -1,
      -1,    45,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    39,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    39,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    49,    50,    55,     0,     3,     8,     9,    10,    11,
      22,    52,    56,    60,    38,     3,    22,     3,    22,    38,
      52,    57,    58,    38,    38,    39,     3,    22,    23,    61,
      62,    39,    42,    57,    57,    40,    43,    40,    58,    39,
      39,    51,     3,     4,     5,     7,    37,    38,    53,    54,
      61,    67,    77,    78,    51,    40,    40,    12,    14,    15,
      16,    17,    18,    19,    20,    21,    23,    40,    41,    45,
      52,    61,    63,    64,    65,    66,    68,    69,    70,    71,
      77,    79,    81,    88,    90,    91,    92,    38,    77,    77,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    44,    41,    51,    51,    38,    38,    89,
      38,    54,    47,     6,    77,    38,    51,     3,    62,    72,
      73,    76,    46,    45,    45,    45,    45,    45,    45,    59,
      61,    39,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    43,    41,    41,    77,    82,
      85,    38,    77,    47,    51,     6,    41,    43,    46,    42,
      77,    39,    42,    77,    39,    77,    79,    80,    71,    80,
      39,    51,    39,    42,    44,    77,    77,    73,    76,    61,
      44,    93,    83,    86,    39,    51,    59,    43,    46,    44,
      40,    45,    45,    40,    39,    77,     6,    40,    43,    46,
      51,    84,    87,    51,    44,    53,    74,    77,     6,    40,
      41,    80,    80,    41,    46,    41,    42,    44,    74,    94,
      45,    45,    40,    53,    46,    41,    13,    95,    80,    80,
      40,    74,    75,    40,    40,    39,    39,    74,    41,    41,
      74,    75,    51,    40,    40,    41,    41,    41,    41,    51,
      51,    42,    41,    41,    75
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    51,    51,    52,    52,    52,    53,
      53,    54,    54,    55,    55,    56,    56,    56,    57,    57,
      57,    58,    59,    59,    59,    60,    60,    60,    61,    61,
      61,    61,    62,    62,    63,    63,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    65,    65,    66,
      67,    68,    68,    69,    69,    69,    70,    70,    71,    72,
      72,    72,    72,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    74,    74,    75,    75,    76,    76,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    78,    78,    78,    79,    80,
      80,    80,    82,    83,    84,    81,    85,    86,    87,    81,
      89,    88,    90,    91,    91,    93,    94,    92,    95,    95
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     7,     2,     0,     1,     1,     1,     1,
       1,     1,     1,     2,     0,     8,     7,     8,     3,     1,
       0,     2,     3,     1,     0,     2,     2,     1,     1,     1,
       1,     1,     4,     7,     1,     1,     1,     2,     2,     2,
       1,     1,     2,     2,     2,     1,     1,     4,     6,     3,
       4,     1,     1,     2,     2,     1,     1,     1,     2,     3,
       3,     1,     1,     1,     8,     7,    11,    10,    11,    10,
       6,     6,     5,     1,     3,     3,     5,     1,     3,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     3,     1,
       1,     0,     0,     0,     0,    14,     0,     0,     0,    14,
       0,     8,     5,     4,     3,     0,     0,    10,     4,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 74 "CodeGeneration.y"
                        { printf("valid input\n"); return 1; }
#line 1703 "y.tab.c"
    break;

  case 32:
#line 133 "CodeGeneration.y"
                                                {             
                        int a = gencode("4","*",(yyvsp[-1].lexeme));
                        char* tempVar = genTempVariable(a);
                        tempVariable++;
                        int b = gencode("","&",(yyvsp[-3].lexeme));
                        char* tempVar2 = genTempVariable(b);
                        tempVariable++;
                        int c = gencode(tempVar,"+",tempVar2);
                        char* tempVar3 = genTempVariable(c);
                        tempVariable++;
                        int d = gencode("","*",tempVar3);
                        char* tempVar4 = genTempVariable(d);
                        tempVariable++;
                        (yyval.lexeme) = tempVar4;
                }
#line 1723 "y.tab.c"
    break;

  case 78:
#line 221 "CodeGeneration.y"
                                                    {
                                assignment((yyvsp[-2].lexeme),(yyvsp[0].lexeme));
                                (yyval.lexeme)=(yyvsp[-2].lexeme);
                        }
#line 1732 "y.tab.c"
    break;

  case 79:
#line 227 "CodeGeneration.y"
                                {
                    int a = gencode("","!",(yyvsp[0].lexeme));
                    char* tempVar = genTempVariable(a);
                    (yyval.lexeme) = tempVar;
                    tempVariable++;   
                }
#line 1743 "y.tab.c"
    break;

  case 80:
#line 233 "CodeGeneration.y"
                                           {
                    int a = gencode((yyvsp[-2].lexeme),"+",(yyvsp[0].lexeme));
                    char* tempVar = genTempVariable(a);
                    (yyval.lexeme) = tempVar;
                    tempVariable++;
                }
#line 1754 "y.tab.c"
    break;

  case 81:
#line 239 "CodeGeneration.y"
                                           {
                        int a = gencode((yyvsp[-2].lexeme),"-",(yyvsp[0].lexeme));
                        char* tempVar = genTempVariable(a);
                        (yyval.lexeme) = tempVar;
                        tempVariable++;
                }
#line 1765 "y.tab.c"
    break;

  case 82:
#line 245 "CodeGeneration.y"
                                           {
                        int a = gencode((yyvsp[-2].lexeme),"*",(yyvsp[0].lexeme));
                        char* tempVar = genTempVariable(a);
                        (yyval.lexeme) = tempVar;
                        tempVariable++;
                }
#line 1776 "y.tab.c"
    break;

  case 83:
#line 251 "CodeGeneration.y"
                                            {
                        int a = gencode((yyvsp[-2].lexeme),"/",(yyvsp[0].lexeme));
                        char* tempVar = genTempVariable(a);
                        (yyval.lexeme) = tempVar;
                        tempVariable++;
                }
#line 1787 "y.tab.c"
    break;

  case 84:
#line 257 "CodeGeneration.y"
                                            {
                        int a = gencode((yyvsp[-2].lexeme),"%",(yyvsp[0].lexeme));
                        char* tempVar = genTempVariable(a);
                        (yyval.lexeme) = tempVar;
                        tempVariable++;
                }
#line 1798 "y.tab.c"
    break;

  case 85:
#line 263 "CodeGeneration.y"
                                           {
                        int a = gencode((yyvsp[-2].lexeme),"<",(yyvsp[0].lexeme));
                        char* tempVar = genTempVariable(a);
                        (yyval.lexeme) = tempVar;
                        tempVariable++;
                }
#line 1809 "y.tab.c"
    break;

  case 86:
#line 269 "CodeGeneration.y"
                                           {
                        int a = gencode((yyvsp[-2].lexeme),">",(yyvsp[0].lexeme));
                        char* tempVar = genTempVariable(a);
                        (yyval.lexeme) = tempVar;
                        tempVariable++;
                }
#line 1820 "y.tab.c"
    break;

  case 87:
#line 275 "CodeGeneration.y"
                                          {
                        int a = gencode((yyvsp[-2].lexeme),"==",(yyvsp[0].lexeme));
                        char* tempVar = genTempVariable(a);
                        (yyval.lexeme) = tempVar;
                        tempVariable++;
                }
#line 1831 "y.tab.c"
    break;

  case 88:
#line 281 "CodeGeneration.y"
                                          {
                        int a = gencode((yyvsp[-2].lexeme),"!=",(yyvsp[0].lexeme));
                        char* tempVar = genTempVariable(a);
                        (yyval.lexeme) = tempVar;
                        tempVariable++;
                }
#line 1842 "y.tab.c"
    break;

  case 89:
#line 287 "CodeGeneration.y"
                                          {
                        int a = gencode((yyvsp[-2].lexeme),">=",(yyvsp[0].lexeme));
                        char* tempVar = genTempVariable(a);
                        (yyval.lexeme) = tempVar;
                        tempVariable++;
                }
#line 1853 "y.tab.c"
    break;

  case 90:
#line 293 "CodeGeneration.y"
                                          {
                        int a = gencode((yyvsp[-2].lexeme),"<=",(yyvsp[0].lexeme));
                        char* tempVar = genTempVariable(a);
                        (yyval.lexeme) = tempVar;
                        tempVariable++;
                }
#line 1864 "y.tab.c"
    break;

  case 91:
#line 299 "CodeGeneration.y"
                                            {
                        int a = gencode((yyvsp[-2].lexeme),"&&",(yyvsp[0].lexeme));
                        char* tempVar = genTempVariable(a);
                        (yyval.lexeme) = tempVar;
                        tempVariable++;
                }
#line 1875 "y.tab.c"
    break;

  case 92:
#line 305 "CodeGeneration.y"
                                           {
                        int a = gencode((yyvsp[-2].lexeme),"||",(yyvsp[0].lexeme));
                        char* tempVar = genTempVariable(a);
                        (yyval.lexeme) = tempVar;
                        tempVariable++;
                }
#line 1886 "y.tab.c"
    break;

  case 98:
#line 320 "CodeGeneration.y"
                                         {
                    assignment((yyvsp[-2].lexeme),(yyvsp[0].lexeme));
                    (yyval.lexeme)=(yyvsp[-2].lexeme);
}
#line 1895 "y.tab.c"
    break;

  case 102:
#line 331 "CodeGeneration.y"
                  {;}
#line 1901 "y.tab.c"
    break;

  case 103:
#line 331 "CodeGeneration.y"
                                      {;}
#line 1907 "y.tab.c"
    break;

  case 104:
#line 331 "CodeGeneration.y"
                                              { top++; printf("L%d: \n", label); arr[top] = label; label++; }
#line 1913 "y.tab.c"
    break;

  case 105:
#line 331 "CodeGeneration.y"
                                                                                                                                                                         {printf("iftrue(%s) goto L%d\n", (yyvsp[-6].lexeme), arr[top--]);}
#line 1919 "y.tab.c"
    break;

  case 106:
#line 332 "CodeGeneration.y"
                  {;}
#line 1925 "y.tab.c"
    break;

  case 107:
#line 332 "CodeGeneration.y"
                                  {;}
#line 1931 "y.tab.c"
    break;

  case 108:
#line 332 "CodeGeneration.y"
                                          { top++; printf("L%d: \n", label); arr[top] = label; label++; }
#line 1937 "y.tab.c"
    break;

  case 109:
#line 332 "CodeGeneration.y"
                                                                                                                                                                    {printf("iftrue(%s) goto L%d\n", (yyvsp[-6].lexeme), arr[top--]);}
#line 1943 "y.tab.c"
    break;

  case 110:
#line 335 "CodeGeneration.y"
                { top++; printf("L%d: \n", label); arr[top] = label; label++; }
#line 1949 "y.tab.c"
    break;

  case 111:
#line 335 "CodeGeneration.y"
                                                                                                                           {printf("iftrue(%s) goto L%d\n", (yyvsp[-4].lexeme), arr[top--]);}
#line 1955 "y.tab.c"
    break;

  case 115:
#line 345 "CodeGeneration.y"
                               { top++; printf("iffalse(%s) goto L%d\n",(yyvsp[-1].lexeme),label); arr[top] = label; label++; }
#line 1961 "y.tab.c"
    break;

  case 116:
#line 345 "CodeGeneration.y"
                                                                                                                                   {printf("L%d: \n", arr[top--]);}
#line 1967 "y.tab.c"
    break;


#line 1971 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 352 "CodeGeneration.y"

 
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
