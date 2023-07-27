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
#line 1 "SemanticAnalyzer.y"

#include <stdio.h> 
#include <string.h>
#include "ast.h"

int yylex(void);
extern FILE *yyin;

struct SymbolTable {
	char name[30];
	int return_type;
        int num_parameters;
        int parameter_types[100];
	struct Node* definition;

	char symbol[50][30];
};

struct SymbolTable symbol_table[100];
int num_symbols = 0;
int num_functions = 0;
int current_scope = 0;

struct Node* add_node(struct Node* root, struct Node* child) {
        root->children[root->num_child++] = child;
        return root;
}

void preorderTraversal(Node* root)
{
        if(!root)
                return;

        printf("%s\n", root->name);
        for(int i=0; i<root->num_child; i++)
        {
                preorderTraversal(root->children[i]);
        }
}

int dataType = -1;


#line 114 "y.tab.c"

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
#line 45 "SemanticAnalyzer.y"
 struct Node* node; 

#line 227 "y.tab.c"

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
#define YYLAST   759

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  111
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  247

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
       2,     2,     2,    38,     2,     2,     2,    37,     2,     2,
      39,    40,    35,    33,    43,    34,     2,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    47,    46,
      29,    24,    30,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    44,     2,    45,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    42,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    25,
      26,    27,    28,    31,    32
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    66,    66,    76,    87,    96,   102,   108,   114,   123,
     128,   136,   141,   149,   156,   160,   179,   198,   220,   228,
     234,   240,   248,   256,   262,   268,   279,   290,   304,   309,
     314,   319,   327,   334,   345,   350,   355,   360,   365,   370,
     375,   380,   385,   390,   395,   402,   407,   415,   421,   431,
     439,   448,   453,   461,   467,   475,   480,   488,   499,   508,
     518,   523,   531,   532,   533,   538,   543,   548,   553,   558,
     563,   564,   569,   577,   582,   592,   597,   607,   612,   620,
     626,   632,   638,   646,   654,   662,   670,   682,   690,   698,
     706,   714,   722,   730,   738,   746,   751,   759,   764,   769,
     777,   788,   793,   799,   805,   814,   826,   836,   846,   853,
     862,   869
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
  "RETURN", "MAIN", "PRINTF", "'='", "OR", "AND", "EQ", "NE", "'<'", "'>'",
  "GE", "LE", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'('", "')'",
  "'{'", "'}'", "','", "'['", "']'", "';'", "':'", "$accept", "s",
  "program", "statements", "datatype", "primitive_literal",
  "integer_literal", "functions", "function", "formal_parameters",
  "formal_parameter", "actual_parameters", "main", "variable",
  "array_access", "statement", "conditional", "printf", "compound",
  "function_call", "jump", "return", "looping", "declaration",
  "declaration_list", "array_declaration", "value_list", "value_block",
  "non_array_declaration", "expression", "operand", "assignment",
  "loop_expression", "for", "while", "switch", "case", "if", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,    61,   279,   280,   281,   282,    60,
      62,   283,   284,    43,    45,    42,    47,    37,    33,    40,
      41,   123,   125,    44,    91,    93,    59,    58
};
# endif

#define YYPACT_NINF (-208)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -208,    47,  -208,   201,  -208,    14,  -208,  -208,  -208,    15,
      22,    19,  -208,  -208,    78,    39,    43,    54,    56,    67,
      52,   102,  -208,    78,    72,    94,    78,   103,   105,  -208,
    -208,  -208,  -208,   152,    78,   104,   153,  -208,   108,   154,
      76,  -208,  -208,   155,  -208,   222,   158,  -208,    10,  -208,
    -208,  -208,    76,    76,    76,    76,  -208,  -208,  -208,  -208,
     546,  -208,   262,  -208,   302,   130,   166,   167,   181,   106,
     172,  -208,  -208,    76,   185,  -208,  -208,  -208,   230,   211,
    -208,  -208,   212,  -208,   213,   216,  -208,   227,   524,   229,
    -208,  -208,  -208,  -208,  -208,  -208,   342,    52,   118,   118,
    -208,   651,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,   242,  -208,   382,  -208,    76,
     169,    76,    76,   210,   502,   699,   281,   422,   -23,   245,
    -208,  -208,    76,  -208,  -208,  -208,  -208,  -208,  -208,   462,
    -208,   123,  -208,  -208,   711,   722,   217,   217,   180,   180,
     180,   180,   118,   118,  -208,  -208,  -208,    76,  -208,   667,
     243,   699,  -208,   244,   251,   683,   502,  -208,   128,  -208,
      76,    12,   230,   699,  -208,  -208,    52,   567,   502,    76,
      76,   502,   502,  -208,  -208,    52,   699,   -12,   588,  -208,
    -208,  -208,  -208,   279,   247,   248,  -208,  -208,   147,    -3,
      76,    -4,   502,    76,    76,  -208,  -208,   129,   609,    -2,
      76,  -208,   257,   258,  -208,   -29,   275,  -208,   129,   630,
     502,   502,  -208,   129,   261,   -15,   289,  -208,  -208,  -208,
      26,  -208,   274,   129,    75,   284,    26,   138,  -208,  -208,
     143,   285,   286,  -208,  -208,   287,  -208
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      14,     0,     2,     0,     1,     0,     6,     7,     8,     0,
       0,     0,    13,     3,    20,     0,     0,     0,     0,     0,
       0,     0,    19,    20,     0,     0,    20,     0,    28,    29,
      30,    21,    31,     0,     0,     0,     0,     5,     0,     0,
       0,     5,    18,     0,     5,     0,     0,     5,    28,    10,
      11,    12,     0,     0,     0,     0,    99,     9,    97,    98,
       0,    96,     0,     5,     0,     0,     0,     0,     0,     0,
       0,    51,    52,    54,    30,     5,    26,    44,     0,    97,
       4,    34,     0,    39,     0,     0,    38,     0,     0,     0,
      56,    55,    46,    43,    45,     5,     0,    24,    80,    81,
      79,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    32,    17,     0,    27,     0,
     103,   103,     0,     0,     0,    53,     0,     0,    77,    57,
      60,    61,     0,    40,    41,    42,    37,    35,    36,     0,
      25,     0,    23,    95,    94,    93,    89,    90,    87,    88,
      91,    92,    82,    83,    84,    85,    86,     0,    16,     0,
       0,   101,   102,     0,     0,     0,     0,   109,     0,    49,
       0,     0,     0,   100,    15,    50,     0,     0,     0,   103,
     103,     0,     0,   108,    47,    24,    78,     0,     0,    58,
      59,    22,    33,   110,     0,     0,   106,   107,     0,     0,
       0,    62,     0,   103,   103,    48,    72,     0,     0,     0,
       0,   111,     0,     0,    73,     0,    70,    71,     0,     0,
       0,     0,    65,     0,     0,     0,    63,   105,   104,    74,
       0,    64,     0,     0,     0,     0,     0,     0,    67,    69,
       0,     0,    75,    66,    68,     0,    76
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -208,  -208,  -208,   -39,    82,   -66,   263,  -208,  -208,    36,
     296,   146,  -208,   -20,  -208,  -118,  -208,  -208,  -208,  -208,
    -208,  -208,  -208,   214,  -208,   161,  -207,  -193,   165,    18,
    -208,  -111,  -114,  -208,  -208,  -208,  -208,  -208
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    45,    78,    56,    57,     3,    12,    21,
      22,   141,    13,    58,    32,    80,    81,    82,    83,    59,
      84,    85,    86,    87,   129,   130,   215,   235,   131,    88,
      61,    89,   163,    90,    91,    92,    93,    94
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      31,   170,    62,   206,   217,    64,   167,   164,    96,   162,
     162,   225,   199,   222,   223,    48,    49,    50,    15,    51,
     209,   171,    18,   234,   117,    79,   237,   231,   223,   240,
      49,    50,   200,    51,    29,    30,   127,    16,   207,   218,
     210,    19,    79,   241,    79,    52,    53,     4,   183,    97,
      54,    55,   246,    14,    40,    28,   139,   187,    60,    35,
     193,    17,    38,   196,   197,   194,   195,   233,   162,   162,
      98,    99,   100,   101,    29,    30,    79,   142,    23,    48,
      49,    50,    24,    51,   211,    11,     6,     7,     8,   212,
     213,   125,   162,   162,    25,    26,    20,    79,    29,    30,
      79,    79,   227,   228,    79,    20,    27,    79,    20,    52,
      53,    50,    36,    51,    54,    55,    20,   238,   223,    79,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,    49,    50,    37,    51,   159,   161,   161,
     165,   214,    33,    39,    43,    34,    79,    34,    46,    40,
     173,    34,   214,   112,   113,   114,   191,   229,    79,    79,
      79,    79,    79,   175,   214,   142,   176,   214,   184,   119,
     214,   185,    48,    49,    50,   177,    51,     6,     7,     8,
     242,   223,    79,    79,    79,   243,   223,   205,   186,   188,
     176,    29,    30,    41,    44,    47,    63,   161,   161,    95,
      79,    79,    52,    53,     5,   120,   121,    54,    55,     6,
       7,     8,     9,   110,   111,   112,   113,   114,   208,   124,
     122,   161,   161,    10,   126,    48,    49,    50,   219,    51,
       6,     7,     8,   128,    65,   132,    66,    67,    68,    69,
      70,    71,    72,    73,    29,    74,   106,   107,   108,   109,
     110,   111,   112,   113,   114,    52,    53,   166,   133,   134,
      54,    55,   135,    75,    76,    48,    49,    50,    77,    51,
       6,     7,     8,   136,    65,   138,    66,    67,    68,    69,
      70,    71,    72,    73,    29,    74,   157,   168,   172,   179,
     180,   181,   202,   203,   204,    52,    53,   220,   221,   224,
      54,    55,   230,    75,   116,    48,    49,    50,    77,    51,
       6,     7,     8,   232,    65,   236,    66,    67,    68,    69,
      70,    71,    72,    73,    29,    74,   239,   244,   233,   245,
      42,   198,   123,   189,   160,    52,    53,   190,     0,     0,
      54,    55,     0,    75,   118,    48,    49,    50,    77,    51,
       6,     7,     8,     0,    65,     0,    66,    67,    68,    69,
      70,    71,    72,    73,    29,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,    53,     0,     0,     0,
      54,    55,     0,    75,   140,    48,    49,    50,    77,    51,
       6,     7,     8,     0,    65,     0,    66,    67,    68,    69,
      70,    71,    72,    73,    29,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,    53,     0,     0,     0,
      54,    55,     0,    75,   158,    48,    49,    50,    77,    51,
       6,     7,     8,     0,    65,     0,    66,    67,    68,    69,
      70,    71,    72,    73,    29,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,    53,     0,     0,     0,
      54,    55,     0,    75,   169,    48,    49,    50,    77,    51,
       6,     7,     8,     0,    65,     0,    66,    67,    68,    69,
      70,    71,    72,    73,    29,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,    53,     0,     0,     0,
      54,    55,     0,    75,   174,    48,    49,    50,    77,    51,
       6,     7,     8,     0,    65,     0,    66,    67,    68,    69,
      70,    71,    72,    73,    29,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,    53,     0,     0,     0,
      54,    55,     0,    75,     0,     0,     0,     0,    77,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,     0,     0,     0,     0,     0,     0,     0,     0,
     137,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,     0,     0,     0,     0,     0,     0,
       0,   115,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,     0,     0,     0,     0,     0,
       0,     0,   192,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,     0,     0,     0,     0,
       0,     0,     0,   201,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,     0,     0,     0,
       0,     0,     0,     0,   216,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,     0,     0,
       0,     0,     0,     0,     0,   226,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,     0,
       0,   143,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,     0,     0,   178,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,     0,     0,   182,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114
};

static const yytype_int16 yycheck[] =
{
      20,    24,    41,     6,     6,    44,   124,   121,    47,   120,
     121,   218,    24,    42,    43,     3,     4,     5,     3,     7,
      24,    44,     3,   230,    63,    45,   233,    42,    43,   236,
       4,     5,    44,     7,    22,    23,    75,    22,    41,    41,
      44,    22,    62,   236,    64,    33,    34,     0,   166,    39,
      38,    39,   245,    39,    44,     3,    95,    45,    40,    23,
     178,    39,    26,   181,   182,   179,   180,    41,   179,   180,
      52,    53,    54,    55,    22,    23,    96,    97,    39,     3,
       4,     5,    39,     7,   202,     3,     8,     9,    10,   203,
     204,    73,   203,   204,    40,    39,    14,   117,    22,    23,
     120,   121,   220,   221,   124,    23,    39,   127,    26,    33,
      34,     5,    40,     7,    38,    39,    34,    42,    43,   139,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,     4,     5,    41,     7,   119,   120,   121,
     122,   207,    40,    40,    40,    43,   166,    43,    40,    44,
     132,    43,   218,    35,    36,    37,   176,   223,   178,   179,
     180,   181,   182,    40,   230,   185,    43,   233,    40,    39,
     236,    43,     3,     4,     5,   157,     7,     8,     9,    10,
      42,    43,   202,   203,   204,    42,    43,    40,   170,   171,
      43,    22,    23,    41,    41,    41,    41,   179,   180,    41,
     220,   221,    33,    34,     3,    39,    39,    38,    39,     8,
       9,    10,    11,    33,    34,    35,    36,    37,   200,    47,
      39,   203,   204,    22,    39,     3,     4,     5,   210,     7,
       8,     9,    10,     3,    12,    24,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    33,    34,    47,    46,    46,
      38,    39,    46,    41,    42,     3,     4,     5,    46,     7,
       8,     9,    10,    46,    12,    46,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    44,     6,    43,    46,
      46,    40,    13,    46,    46,    33,    34,    40,    40,    24,
      38,    39,    41,    41,    42,     3,     4,     5,    46,     7,
       8,     9,    10,    24,    12,    41,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    42,    42,    41,    43,
      34,   185,    69,   172,   120,    33,    34,   172,    -1,    -1,
      38,    39,    -1,    41,    42,     3,     4,     5,    46,     7,
       8,     9,    10,    -1,    12,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    -1,    -1,
      38,    39,    -1,    41,    42,     3,     4,     5,    46,     7,
       8,     9,    10,    -1,    12,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    -1,    -1,
      38,    39,    -1,    41,    42,     3,     4,     5,    46,     7,
       8,     9,    10,    -1,    12,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    -1,    -1,
      38,    39,    -1,    41,    42,     3,     4,     5,    46,     7,
       8,     9,    10,    -1,    12,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    -1,    -1,
      38,    39,    -1,    41,    42,     3,     4,     5,    46,     7,
       8,     9,    10,    -1,    12,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    -1,    -1,
      38,    39,    -1,    41,    -1,    -1,    -1,    -1,    46,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    40,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    40,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    40,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    49,    50,    55,     0,     3,     8,     9,    10,    11,
      22,    52,    56,    60,    39,     3,    22,    39,     3,    22,
      52,    57,    58,    39,    39,    40,    39,    39,     3,    22,
      23,    61,    62,    40,    43,    57,    40,    41,    57,    40,
      44,    41,    58,    40,    41,    51,    40,    41,     3,     4,
       5,     7,    33,    34,    38,    39,    53,    54,    61,    67,
      77,    78,    51,    41,    51,    12,    14,    15,    16,    17,
      18,    19,    20,    21,    23,    41,    42,    46,    52,    61,
      63,    64,    65,    66,    68,    69,    70,    71,    77,    79,
      81,    82,    83,    84,    85,    41,    51,    39,    77,    77,
      77,    77,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    45,    42,    51,    42,    39,
      39,    39,    39,    54,    47,    77,    39,    51,     3,    72,
      73,    76,    24,    46,    46,    46,    46,    46,    46,    51,
      42,    59,    61,    40,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    44,    42,    77,
      71,    77,    79,    80,    80,    77,    47,    63,     6,    42,
      24,    44,    43,    77,    42,    40,    43,    77,    40,    46,
      46,    40,    40,    63,    40,    43,    77,    45,    77,    73,
      76,    61,    45,    63,    80,    80,    63,    63,    59,    24,
      44,    45,    13,    46,    46,    40,     6,    41,    77,    24,
      44,    63,    80,    80,    53,    74,    45,     6,    41,    77,
      40,    40,    42,    43,    24,    74,    45,    63,    63,    53,
      41,    42,    24,    41,    74,    75,    41,    74,    42,    42,
      74,    75,    42,    42,    42,    43,    75
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    51,    51,    52,    52,    52,    53,
      53,    54,    54,    55,    55,    56,    56,    56,    57,    57,
      57,    58,    59,    59,    59,    60,    60,    60,    61,    61,
      61,    61,    62,    62,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    64,    64,    65,    65,    66,
      67,    68,    68,    69,    69,    70,    70,    71,    72,    72,
      72,    72,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    74,    74,    75,    75,    76,    76,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    78,    78,    78,
      79,    80,    80,    80,    81,    81,    82,    83,    84,    84,
      85,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     0,     1,     1,     1,     1,
       1,     1,     1,     2,     0,     8,     8,     7,     3,     1,
       0,     2,     3,     1,     0,     7,     6,     7,     1,     1,
       1,     1,     4,     7,     1,     2,     2,     2,     1,     1,
       2,     2,     2,     1,     1,     1,     1,     4,     6,     3,
       4,     1,     1,     2,     1,     1,     1,     2,     3,     3,
       1,     1,     4,     7,     8,     7,    11,    10,    11,    10,
       6,     6,     5,     1,     3,     3,     5,     1,     3,     2,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       3,     1,     1,     0,     9,     9,     5,     5,     4,     3,
       5,     7
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
#line 67 "SemanticAnalyzer.y"
        { 

                for(int i=0; i<num_functions; i++) {
                        preorderTraversal(symbol_table[i].definition);
                }
                return 1;    
        }
#line 1675 "y.tab.c"
    break;

  case 3:
#line 77 "SemanticAnalyzer.y"
        {
                // $$ = (Node*)malloc(sizeof(Node));
                // strcpy($$->name, "program");
                // add_node($$, $1);
                // add_node($$, $2);
                // preorderTraversal($$);
        }
#line 1687 "y.tab.c"
    break;

  case 4:
#line 88 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                strcpy((yyval.node)->name, "statements");
                (yyval.node)->num_child = 0;
                add_node((yyval.node), (yyvsp[-1].node));
                add_node((yyval.node), (yyvsp[0].node));
        }
#line 1699 "y.tab.c"
    break;

  case 5:
#line 96 "SemanticAnalyzer.y"
        {
                (yyval.node) = NULL;
        }
#line 1707 "y.tab.c"
    break;

  case 6:
#line 103 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
                dataType = 0;
        }
#line 1717 "y.tab.c"
    break;

  case 7:
#line 109 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
                dataType = 1;
        }
#line 1727 "y.tab.c"
    break;

  case 8:
#line 115 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
                dataType = 2;
        }
#line 1737 "y.tab.c"
    break;

  case 9:
#line 124 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 1746 "y.tab.c"
    break;

  case 10:
#line 129 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 1755 "y.tab.c"
    break;

  case 11:
#line 137 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 1764 "y.tab.c"
    break;

  case 12:
#line 142 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 1773 "y.tab.c"
    break;

  case 13:
#line 150 "SemanticAnalyzer.y"
        {
                // $$ = (Node*)malloc(sizeof(Node));
                // strcpy($$->name, "functions");
                // add_node($$, $1);
                // add_node($$, $2);
        }
#line 1784 "y.tab.c"
    break;

  case 15:
#line 161 "SemanticAnalyzer.y"
        { 
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-6].node);
                add_node((yyval.node), (yyvsp[-4].node));
                add_node((yyval.node), (yyvsp[-1].node));

                symbol_table[num_functions].definition = (yyval.node);
                strcpy(symbol_table[num_functions].name, (yyvsp[-6].node)->name);

                for(int i=0; i<num_functions; i++) {
                        if(strcmp(symbol_table[num_functions].name, symbol_table[i].name) == 0) {
                                yyerror("Redeclaration of function\n");
                                break;
                        }
                }

                num_functions++;
        }
#line 1807 "y.tab.c"
    break;

  case 16:
#line 180 "SemanticAnalyzer.y"
        { 
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-6].node);
                add_node((yyval.node), (yyvsp[-4].node));
                add_node((yyval.node), (yyvsp[-1].node));

                symbol_table[num_functions].definition = (yyval.node);
                strcpy(symbol_table[num_functions].name, (yyvsp[-6].node)->name);

                for(int i=0; i<num_functions; i++) {
                        if(strcmp(symbol_table[num_functions].name, symbol_table[i].name) == 0) {
                                yyerror("Redeclaration of function\n");
                                break;
                        }
                }

                num_functions++;
        }
#line 1830 "y.tab.c"
    break;

  case 17:
#line 199 "SemanticAnalyzer.y"
        { 
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-6].node);
                add_node((yyval.node), (yyvsp[-4].node));
                add_node((yyval.node), (yyvsp[-1].node));

                symbol_table[num_functions].definition = (yyval.node);
                strcpy(symbol_table[num_functions].name, (yyvsp[-6].node)->name);

                for(int i=0; i<num_functions; i++) {
                        if(strcmp(symbol_table[num_functions].name, symbol_table[i].name) == 0) {
                                yyerror("Redeclaration of function\n");
                                break;
                        }
                }

                num_functions++;
        }
#line 1853 "y.tab.c"
    break;

  case 18:
#line 221 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                strcpy((yyval.node)->name, "formal_parameters");
                (yyval.node)->num_child = 0;
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
        }
#line 1865 "y.tab.c"
    break;

  case 19:
#line 229 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 1874 "y.tab.c"
    break;

  case 20:
#line 234 "SemanticAnalyzer.y"
        {
                (yyval.node) = NULL;
        }
#line 1882 "y.tab.c"
    break;

  case 21:
#line 241 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
        }
#line 1891 "y.tab.c"
    break;

  case 22:
#line 249 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                strcpy((yyval.node)->name, "actual_parameters");
                (yyval.node)->num_child = 0;
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
        }
#line 1903 "y.tab.c"
    break;

  case 23:
#line 257 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 1912 "y.tab.c"
    break;

  case 24:
#line 262 "SemanticAnalyzer.y"
        {
                (yyval.node) = NULL;
        }
#line 1920 "y.tab.c"
    break;

  case 25:
#line 269 "SemanticAnalyzer.y"
        { 
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-5].node);
                add_node((yyval.node), (yyvsp[-1].node));

                symbol_table[num_functions].definition = (yyval.node);
                strcpy(symbol_table[num_functions].name, (yyvsp[-5].node)->name);

                num_functions++;
        }
#line 1935 "y.tab.c"
    break;

  case 26:
#line 280 "SemanticAnalyzer.y"
        { 
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-5].node);
                add_node((yyval.node), (yyvsp[-1].node));

                symbol_table[num_functions].definition = (yyval.node);
                strcpy(symbol_table[num_functions].name, (yyvsp[-5].node)->name);

                num_functions++;
        }
#line 1950 "y.tab.c"
    break;

  case 27:
#line 291 "SemanticAnalyzer.y"
        { 
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-5].node);
                add_node((yyval.node), (yyvsp[-1].node));

                symbol_table[num_functions].definition = (yyval.node);
                strcpy(symbol_table[num_functions].name, (yyvsp[-5].node)->name);

                num_functions++;
        }
#line 1965 "y.tab.c"
    break;

  case 28:
#line 305 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 1974 "y.tab.c"
    break;

  case 29:
#line 310 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 1983 "y.tab.c"
    break;

  case 30:
#line 315 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 1992 "y.tab.c"
    break;

  case 31:
#line 320 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2001 "y.tab.c"
    break;

  case 32:
#line 328 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-3].node);
                add_node((yyval.node), (yyvsp[-3].node));
                add_node((yyval.node), (yyvsp[-1].node));
        }
#line 2012 "y.tab.c"
    break;

  case 33:
#line 335 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-6].node);
                add_node((yyval.node), (yyvsp[-6].node));
                add_node((yyval.node), (yyvsp[-4].node));
                add_node((yyval.node), (yyvsp[-1].node));
        }
#line 2024 "y.tab.c"
    break;

  case 34:
#line 346 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2033 "y.tab.c"
    break;

  case 35:
#line 351 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
        }
#line 2042 "y.tab.c"
    break;

  case 36:
#line 356 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
        }
#line 2051 "y.tab.c"
    break;

  case 37:
#line 361 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
        }
#line 2060 "y.tab.c"
    break;

  case 38:
#line 366 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2069 "y.tab.c"
    break;

  case 39:
#line 371 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2078 "y.tab.c"
    break;

  case 40:
#line 376 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
        }
#line 2087 "y.tab.c"
    break;

  case 41:
#line 381 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
        }
#line 2096 "y.tab.c"
    break;

  case 42:
#line 386 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
        }
#line 2105 "y.tab.c"
    break;

  case 43:
#line 391 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2114 "y.tab.c"
    break;

  case 44:
#line 396 "SemanticAnalyzer.y"
        {
                (yyval.node) = NULL;
        }
#line 2122 "y.tab.c"
    break;

  case 45:
#line 403 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2131 "y.tab.c"
    break;

  case 46:
#line 408 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2140 "y.tab.c"
    break;

  case 47:
#line 416 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-3].node);
                add_node((yyval.node), (yyvsp[-1].node));
        }
#line 2150 "y.tab.c"
    break;

  case 48:
#line 422 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-5].node);
                add_node((yyval.node), (yyvsp[-3].node));
                add_node((yyval.node), (yyvsp[-1].node));
        }
#line 2161 "y.tab.c"
    break;

  case 49:
#line 432 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
        }
#line 2170 "y.tab.c"
    break;

  case 50:
#line 440 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-3].node);
                add_node((yyval.node), (yyvsp[-1].node));
        }
#line 2180 "y.tab.c"
    break;

  case 51:
#line 449 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2189 "y.tab.c"
    break;

  case 52:
#line 454 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2198 "y.tab.c"
    break;

  case 53:
#line 462 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
                add_node((yyval.node), (yyvsp[0].node));
        }
#line 2208 "y.tab.c"
    break;

  case 54:
#line 468 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2217 "y.tab.c"
    break;

  case 55:
#line 476 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2226 "y.tab.c"
    break;

  case 56:
#line 481 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2235 "y.tab.c"
    break;

  case 57:
#line 489 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                strcpy((yyval.node)->name, "declaration");
                (yyval.node)->num_child = 0;
                add_node((yyval.node), (yyvsp[-1].node));
                add_node((yyval.node), (yyvsp[0].node));            
        }
#line 2247 "y.tab.c"
    break;

  case 58:
#line 500 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                strcpy((yyval.node)->name, "declaration_list");
                (yyval.node)->num_child = 0;
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
                (yyval.node)->data_type = (yyvsp[-2].node)->data_type;
        }
#line 2260 "y.tab.c"
    break;

  case 59:
#line 509 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                strcpy((yyval.node)->name, "declaration_list");
                (yyval.node)->num_child = 0;
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));

                (yyval.node)->data_type = (yyvsp[-2].node)->data_type;
        }
#line 2274 "y.tab.c"
    break;

  case 60:
#line 519 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2283 "y.tab.c"
    break;

  case 61:
#line 524 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2292 "y.tab.c"
    break;

  case 64:
#line 534 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
        }
#line 2301 "y.tab.c"
    break;

  case 65:
#line 539 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
        }
#line 2310 "y.tab.c"
    break;

  case 66:
#line 544 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
        }
#line 2319 "y.tab.c"
    break;

  case 67:
#line 549 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
        }
#line 2328 "y.tab.c"
    break;

  case 68:
#line 554 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
        }
#line 2337 "y.tab.c"
    break;

  case 69:
#line 559 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
        }
#line 2346 "y.tab.c"
    break;

  case 71:
#line 565 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2355 "y.tab.c"
    break;

  case 72:
#line 570 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2364 "y.tab.c"
    break;

  case 73:
#line 578 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2373 "y.tab.c"
    break;

  case 74:
#line 583 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);

                (yyval.node)->data_type = (yyvsp[-2].node)->data_type;
        }
#line 2384 "y.tab.c"
    break;

  case 75:
#line 593 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
        }
#line 2393 "y.tab.c"
    break;

  case 76:
#line 598 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-3].node);

                (yyval.node)->data_type = (yyvsp[-3].node)->data_type;
        }
#line 2404 "y.tab.c"
    break;

  case 77:
#line 608 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2413 "y.tab.c"
    break;

  case 78:
#line 613 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node)->data_type = (yyvsp[0].node)->data_type;
        }
#line 2422 "y.tab.c"
    break;

  case 79:
#line 621 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
                add_node((yyval.node), (yyvsp[0].node));
        }
#line 2432 "y.tab.c"
    break;

  case 80:
#line 627 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
                add_node((yyval.node), (yyvsp[0].node));
        }
#line 2442 "y.tab.c"
    break;

  case 81:
#line 633 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
                add_node((yyval.node), (yyvsp[0].node));
        }
#line 2452 "y.tab.c"
    break;

  case 82:
#line 639 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
                (yyval.node)->data_type = (yyvsp[-2].node)->data_type;
        }
#line 2464 "y.tab.c"
    break;

  case 83:
#line 647 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
                (yyval.node)->data_type = (yyvsp[-2].node)->data_type;
        }
#line 2476 "y.tab.c"
    break;

  case 84:
#line 655 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
                (yyval.node)->data_type = (yyvsp[-2].node)->data_type;
        }
#line 2488 "y.tab.c"
    break;

  case 85:
#line 663 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
                (yyval.node)->data_type = (yyvsp[-2].node)->data_type;
        }
#line 2500 "y.tab.c"
    break;

  case 86:
#line 671 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));

                if((yyvsp[-2].node)->data_type != 1 || (yyvsp[0].node)->data_type != 0) {
                        yyerror("INT REQUIRED IN %");
                }
                (yyval.node)->data_type = (yyvsp[-2].node)->data_type;
        }
#line 2516 "y.tab.c"
    break;

  case 87:
#line 683 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
                (yyval.node)->data_type = (yyvsp[-2].node)->data_type;
        }
#line 2528 "y.tab.c"
    break;

  case 88:
#line 691 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
                (yyval.node)->data_type = (yyvsp[-2].node)->data_type;
        }
#line 2540 "y.tab.c"
    break;

  case 89:
#line 699 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
                (yyval.node)->data_type = (yyvsp[-2].node)->data_type;
        }
#line 2552 "y.tab.c"
    break;

  case 90:
#line 707 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
                (yyval.node)->data_type = (yyvsp[-2].node)->data_type;
        }
#line 2564 "y.tab.c"
    break;

  case 91:
#line 715 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
                (yyval.node)->data_type = (yyvsp[-2].node)->data_type;
        }
#line 2576 "y.tab.c"
    break;

  case 92:
#line 723 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
                (yyval.node)->data_type = (yyvsp[-2].node)->data_type;
        }
#line 2588 "y.tab.c"
    break;

  case 93:
#line 731 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
                (yyval.node)->data_type = (yyvsp[-2].node)->data_type;
        }
#line 2600 "y.tab.c"
    break;

  case 94:
#line 739 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
                (yyval.node)->data_type = (yyvsp[-2].node)->data_type;
        }
#line 2612 "y.tab.c"
    break;

  case 95:
#line 747 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-1].node);
        }
#line 2621 "y.tab.c"
    break;

  case 96:
#line 752 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2630 "y.tab.c"
    break;

  case 97:
#line 760 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2639 "y.tab.c"
    break;

  case 98:
#line 765 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2648 "y.tab.c"
    break;

  case 99:
#line 770 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2657 "y.tab.c"
    break;

  case 100:
#line 778 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyvsp[-2].node)->data_type = (yyvsp[-1].node)->data_type;
                (yyval.node) = (yyvsp[-1].node);
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
        }
#line 2669 "y.tab.c"
    break;

  case 101:
#line 789 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2678 "y.tab.c"
    break;

  case 102:
#line 794 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[0].node);
        }
#line 2687 "y.tab.c"
    break;

  case 103:
#line 799 "SemanticAnalyzer.y"
        {
                (yyval.node) = NULL;
        }
#line 2695 "y.tab.c"
    break;

  case 104:
#line 806 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-8].node);
                add_node((yyval.node), (yyvsp[-6].node));
                add_node((yyval.node), (yyvsp[-4].node));
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
        }
#line 2708 "y.tab.c"
    break;

  case 105:
#line 815 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-8].node);
                add_node((yyval.node), (yyvsp[-6].node));
                add_node((yyval.node), (yyvsp[-4].node));
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
        }
#line 2721 "y.tab.c"
    break;

  case 106:
#line 827 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-4].node);
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
        }
#line 2732 "y.tab.c"
    break;

  case 107:
#line 837 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-4].node);
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
        }
#line 2743 "y.tab.c"
    break;

  case 108:
#line 847 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-3].node);
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
        }
#line 2754 "y.tab.c"
    break;

  case 109:
#line 854 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-2].node);
                add_node((yyval.node), (yyvsp[0].node));
        }
#line 2764 "y.tab.c"
    break;

  case 110:
#line 863 "SemanticAnalyzer.y"
        { 
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-4].node);
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
        }
#line 2775 "y.tab.c"
    break;

  case 111:
#line 870 "SemanticAnalyzer.y"
        {
                (yyval.node) = (Node*)malloc(sizeof(Node));
                (yyval.node) = (yyvsp[-6].node);
                add_node((yyval.node), (yyvsp[-4].node));
                add_node((yyval.node), (yyvsp[-2].node));
                add_node((yyval.node), (yyvsp[0].node));
        }
#line 2787 "y.tab.c"
    break;


#line 2791 "y.tab.c"

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
#line 879 "SemanticAnalyzer.y"


void yyerror(const char* s) {
    printf("%s", s);
    exit(0);
    return;
}

int main() {
    yyin = fopen("code.txt", "r");
    yyparse();
    return 0;
}
