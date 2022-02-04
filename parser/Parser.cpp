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
#line 2 "./parser/Parser.y"

#include <iostream>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include "Utils/UnionStruct.hpp"
#include "../src/Ast.hpp"
#include "../src/ChmrInterpreter.hpp"
#include "Utils/IntrBridge.hpp"

using namespace std;

int lineno = 0;
ChmrInterpreter i;
string scope_type;
AstNode *root = nullptr;
AstNode *loop_id = nullptr;
bool for_loop_made = false;

void PrintLineNo();
void yyerror(const char* err);
extern int yylex();
extern FILE *yyin;
extern void yyrestart(FILE* input);
extern char* yytext;

#line 97 "./parser/Parser.cpp"

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
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_PARSER_HPP_INCLUDED
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
    INT = 258,
    FLOAT = 259,
    DOUBLE = 260,
    BOOL = 261,
    CHAR = 262,
    STRING = 263,
    LIST = 264,
    MAP = 265,
    CAST = 266,
    LESS = 267,
    GREATER = 268,
    LESS_EQUAL = 269,
    GREATER_EQUAL = 270,
    EQUAL = 271,
    NOT_EQUAL = 272,
    PRINT = 273,
    AND = 274,
    OR = 275,
    NOT = 276,
    EXIT = 277,
    NEWLINE = 278,
    SEMICOLON = 279,
    EOPU = 280,
    REF = 281,
    ADD = 282,
    SUB = 283,
    MUL = 284,
    DIV = 285,
    POW = 286,
    ADD_LIST = 287,
    ADD_MAP = 288,
    SET = 289,
    GET = 290,
    POINTS_TO = 291,
    START = 292,
    END = 293,
    IF = 294,
    ELSE = 295,
    WHILE = 296,
    SIZE = 297,
    REPEAT = 298,
    WITH = 299,
    MULTI_WS = 300,
    SINGLE_WS = 301,
    INC = 302,
    MOD = 303,
    INT_VAL = 304,
    DOUBLE_VAL = 305,
    STRING_VAL = 306,
    CHAR_VAL = 307,
    BOOL_VAL = 308,
    ELSE_IF = 309,
    FLOAT_VAL = 310,
    ID = 311,
    UNKNOWN = 312
  };
#endif

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_PARSER_HPP_INCLUDED  */



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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  94
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   917

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  113
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  329

#define YYUNDEFTOK  2
#define YYMAXUTOK   312


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      67,    68,     2,     2,     2,     2,    69,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    63,     2,
      65,    64,    66,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    59,     2,    60,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    61,    58,    62,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   112,   112,   114,   116,   121,   126,   130,   135,   151,
     152,   153,   154,   154,   156,   160,   166,   169,   172,   175,
     179,   179,   181,   182,   183,   186,   193,   202,   211,   220,
     231,   235,   239,   243,   247,   251,   255,   259,   263,   267,
     271,   277,   278,   279,   280,   281,   282,   283,   287,   293,
     298,   305,   305,   307,   307,   309,   314,   318,   322,   326,
     330,   334,   341,   344,   347,   351,   357,   358,   358,   360,
     361,   365,   370,   374,   378,   382,   386,   390,   394,   403,
     407,   411,   415,   419,   423,   431,   435,   439,   446,   450,
     458,   462,   466,   470,   474,   478,   482,   486,   490,   494,
     500,   501,   502,   503,   504,   505,   506,   507,   508,   509,
     513,   514,   516,   516
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "DOUBLE", "BOOL", "CHAR",
  "STRING", "LIST", "MAP", "CAST", "LESS", "GREATER", "LESS_EQUAL",
  "GREATER_EQUAL", "EQUAL", "NOT_EQUAL", "PRINT", "AND", "OR", "NOT",
  "EXIT", "NEWLINE", "SEMICOLON", "EOPU", "REF", "ADD", "SUB", "MUL",
  "DIV", "POW", "ADD_LIST", "ADD_MAP", "SET", "GET", "POINTS_TO", "START",
  "END", "IF", "ELSE", "WHILE", "SIZE", "REPEAT", "WITH", "MULTI_WS",
  "SINGLE_WS", "INC", "MOD", "INT_VAL", "DOUBLE_VAL", "STRING_VAL",
  "CHAR_VAL", "BOOL_VAL", "ELSE_IF", "FLOAT_VAL", "ID", "UNKNOWN", "'|'",
  "'['", "']'", "'{'", "'}'", "':'", "'='", "'<'", "'>'", "'('", "')'",
  "'.'", "$accept", "start", "end", "ifHead", "elseIfHead", "elseHead",
  "whileHead", "forloopHead", "ifBody", "elseIfBody", "elseBody",
  "elseIfChain", "whileStatement", "forloopStatement", "ifStatement",
  "newline", "terms", "keyValPairs", "keyVals", "term", "types",
  "unionTypes", "any_ws", "opt_ws", "id", "assign", "exprList",
  "opt_newline", "opt_ws_or_nl", "statement", "math_expr", "compare_expr",
  "boolExpr", "indexAccessor", "expr", "prog", "line", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   124,    91,
      93,   123,   125,    58,    61,    60,    62,    40,    41,    46
};
# endif

#define YYPACT_NINF (-215)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-55)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     812,  -215,   103,   -46,  -215,  -215,  -215,  -215,   103,   103,
     103,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,
      68,    11,   869,   812,   812,   812,   812,    47,  -215,  -215,
    -215,  -215,  -215,  -215,    53,  -215,    96,  -215,  -215,  -215,
      23,   -16,  -215,   536,  -215,     5,   103,   164,   164,   164,
    -215,     3,  -215,   183,  -215,    12,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   628,   322,   674,   720,  -215,   103,   103,
     812,   812,  -215,    55,   106,   103,   103,    31,  -215,  -215,
     103,  -215,    91,  -215,  -215,  -215,   103,    50,    52,   -32,
     -32,   -32,   103,   103,  -215,  -215,   103,     6,    -4,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   164,    86,
       4,   164,   103,   103,   103,   103,   164,   164,  -215,  -215,
    -215,  -215,    78,   164,   582,   766,  -215,  -215,  -215,    84,
     164,    14,   103,   164,    76,    85,    94,  -215,   103,  -215,
      89,   117,   113,  -215,   183,   183,    98,   183,   103,  -215,
    -215,    32,   -32,   -32,   -32,   -32,   -32,   -32,   -32,   -32,
     -32,   -32,    90,  -215,   164,     3,   164,    90,   164,    93,
      97,    99,   100,   -32,   -32,  -215,   -32,  -215,   -32,  -215,
    -215,  -215,  -215,  -215,  -215,  -215,  -215,   103,   -35,   103,
     164,   -32,   103,   103,   103,   104,  -215,  -215,   103,  -215,
    -215,  -215,   103,  -215,   103,  -215,   171,   164,   164,   164,
     164,   164,   164,   164,   164,   119,    90,    90,  -215,  -215,
    -215,  -215,   120,   164,   127,   112,   102,   163,   -33,    22,
      10,   131,   164,   164,   164,  -215,   136,   157,  -215,   103,
     -32,   -32,   -32,   -32,   -32,   -32,   -32,   -32,  -215,  -215,
     -32,  -215,  -215,   103,   128,   103,   103,   103,   103,   172,
    -215,   -32,   -32,   -32,   103,   103,   135,   137,   138,   139,
     141,   143,   150,   153,   154,   156,   164,   103,   171,   164,
     171,   164,   174,   146,   164,   164,   192,   183,  -215,  -215,
    -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,    90,   166,
    -215,    90,  -215,    90,  -215,  -215,   -32,   -32,  -215,   103,
     103,   188,   189,   199,   164,  -215,  -215,  -215,    90
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,   111,    54,     0,    20,    21,   109,     2,     0,     0,
       0,    51,    52,    30,    31,    33,    34,    35,    32,    55,
      54,    54,     0,     0,     0,     0,     0,     0,   106,   107,
     105,   104,    90,   110,    36,    69,     0,    91,    93,    94,
      97,     0,   112,     0,    53,     0,    54,     0,     0,     0,
      38,    67,    68,     0,    40,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    54,    54,    54,    54,
      54,     0,     0,     0,     0,     0,     0,    16,     0,     0,
       0,     0,    12,     0,     0,    54,    54,     0,   103,   102,
      54,   101,     0,   100,     1,   113,    54,     0,    36,     0,
       0,     0,    54,    54,    22,    36,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      54,     0,    54,    54,    54,    54,     0,     0,     3,   108,
      14,    15,     0,     0,     0,     0,    19,    17,    13,     0,
       0,     0,    54,     0,     0,     0,     0,    99,    54,    71,
       0,     0,     0,    66,    53,    68,     0,     0,    54,    27,
      39,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    54,    62,    72,    53,     0,     0,    63,    68,     0,
       0,     0,     0,    54,     0,     6,     0,    18,    54,    41,
      42,    43,    44,    45,    46,    47,    48,    54,    54,    54,
       0,    54,    54,    54,    54,     0,     4,     7,     0,    23,
      24,    37,    54,    26,    54,    29,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    64,    65,    73,    74,
      75,    76,     0,     0,     0,     0,     0,     0,     0,     0,
      59,     0,     0,     0,     0,    70,     0,     0,    28,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    86,    77,
      54,     5,    88,    54,     0,    54,    54,    54,    54,     0,
      89,    54,     0,     0,     0,    54,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    54,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,    79,
      80,    81,    82,    83,    84,    85,    87,    78,    57,     0,
      49,    56,    50,    58,    61,    95,    54,    54,     8,    54,
      54,     0,     0,     0,     0,    96,    98,    25,    60
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,   175,
     176,  -215,  -215,  -215,  -215,     2,  -215,   129,  -215,   -52,
    -214,  -215,   382,    -2,    16,  -215,   -34,     7,    60,  -215,
    -215,  -215,  -215,  -215,   179,   -28,   -20
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    23,   129,    24,    80,    81,    25,    26,    27,    82,
      83,    84,    28,    29,    30,    31,   103,   107,   108,    32,
     198,   199,    44,    51,    98,    35,   120,   121,    53,    36,
      37,    38,    39,    40,    41,    42,    43
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,   104,   249,    73,    74,    75,    76,     4,     5,    91,
      11,    12,    46,    11,    12,    95,    34,   189,   190,   191,
     192,   193,   194,   195,   196,   265,   102,    52,    52,   158,
     237,   266,    87,   122,   123,   124,   125,    92,    89,    34,
      34,    34,    34,    93,    97,    95,    95,    95,    95,    11,
      12,    11,    12,    92,   106,   214,    11,    12,   160,    34,
     134,   135,   148,    96,   119,   119,   119,   119,   119,   105,
     106,   197,   173,    54,   310,   269,   312,    11,    12,    92,
     267,    55,    90,   140,   141,    77,   268,    78,   143,    34,
      34,    34,    34,   136,   119,   142,    34,    34,    11,    12,
     153,    79,   209,   210,   157,   212,    95,    95,   149,   102,
     155,    85,    85,    11,    12,   185,    86,   -54,   175,     4,
       5,    88,   187,   144,   145,   146,   206,   176,    50,   178,
     178,   178,   178,   147,   202,    13,    14,    15,    16,    17,
     200,    18,    19,   203,   137,    20,    78,    21,    11,    12,
      34,    34,   204,    22,   207,   178,   213,   208,   211,    92,
      79,   228,   245,   156,   261,   229,   263,   230,   231,   225,
     105,   105,   262,   105,   189,   190,   191,   192,   193,   194,
     195,   196,   179,   180,   181,   182,   235,   258,   259,   264,
      52,   270,    19,   275,   287,   236,   238,   239,   292,   241,
     242,   243,   244,   298,   315,   299,   300,   301,   205,   302,
     247,   303,   248,    13,    14,    15,    16,    17,   304,    18,
      19,   305,   306,    20,   307,    21,    99,   100,   101,   318,
     320,    22,    13,    14,    15,    16,    17,   161,    18,    19,
     314,     0,    20,   232,    21,   319,   325,   326,   277,   278,
     279,   280,   281,   282,   283,   284,    52,   327,     0,   138,
     139,   286,   274,   288,   289,   290,   291,    52,     0,   293,
       0,     0,     0,   297,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   309,     0,     0,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,     0,
     177,     0,     0,     0,     0,   183,   184,     0,     0,   276,
       0,     0,   186,   105,   321,   322,     0,   323,   324,   188,
     285,     0,   201,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     0,     0,     0,     3,     4,     5,     6,     0,     0,
       0,     0,     0,   226,     0,   227,     0,   227,     0,     7,
      -9,     8,    -9,     9,     0,    10,     0,    11,    12,     0,
       0,    13,    14,    15,    16,    17,    -9,    18,    19,   240,
       0,    20,    33,    21,     0,     0,     0,     0,     0,    22,
      47,    48,    49,     0,     0,     0,   250,   251,   252,   253,
     254,   255,   256,   257,     0,    33,    33,    33,    33,     0,
       0,     0,   260,     0,     0,     0,     0,     0,     0,     0,
       0,   271,   272,   273,     0,    33,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,     0,     0,
       0,     0,     0,   126,   127,    33,    33,    33,    33,     0,
     132,   133,    33,    33,     0,   308,     0,     0,   311,     0,
     313,     0,     0,   316,   317,     0,     0,     0,     0,     0,
       0,   150,   151,   152,     0,   154,     0,     0,     0,   159,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   174,   328,   174,   174,   174,   174,     0,     0,
       0,     0,     0,     0,     0,     0,    33,    33,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     174,     0,     0,     0,     0,     0,    94,     1,     0,     0,
       0,     0,     0,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,     0,     2,     0,     0,     0,     3,     4,
       5,     6,     0,     0,     0,     0,   233,     0,   234,     0,
       0,     0,     0,     7,     0,     8,     0,     9,     0,    10,
       0,    11,    12,     1,     0,    13,    14,    15,    16,    17,
     246,    18,    19,     0,     0,    20,     0,    21,     0,     0,
       2,     0,     0,    22,     3,     4,     5,     6,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
     -10,     8,   -10,     9,     0,    10,     0,    11,    12,     1,
       0,    13,    14,    15,    16,    17,   -10,    18,    19,     0,
       0,    20,     0,    21,     0,     0,     2,     0,     0,    22,
       3,     4,     5,     6,   294,   295,   296,     0,     0,     0,
       0,     0,     0,     0,     0,     7,   128,     8,     0,     9,
       0,    10,     0,    11,    12,     1,     0,    13,    14,    15,
      16,    17,     0,    18,    19,     0,     0,    20,     0,    21,
       0,     0,     2,     0,     0,    22,     3,     4,     5,     6,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,   130,     8,     0,     9,     0,    10,     0,    11,
      12,     1,     0,    13,    14,    15,    16,    17,     0,    18,
      19,     0,     0,    20,     0,    21,     0,     0,     2,     0,
       0,    22,     3,     4,     5,     6,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,   131,     8,
       0,     9,     0,    10,     0,    11,    12,     1,     0,    13,
      14,    15,    16,    17,     0,    18,    19,     0,     0,    20,
       0,    21,     0,     0,     2,     0,     0,    22,     3,     4,
       5,     6,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,   -11,     8,     0,     9,     0,    10,
       0,    11,    12,     1,     0,    13,    14,    15,    16,    17,
       0,    18,    19,     0,     0,    20,     0,    21,     0,     0,
       2,     0,     0,    22,     3,     4,     5,     6,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
       0,     8,     0,     9,     0,    10,     0,    11,    12,     0,
       0,    13,    14,    15,    16,    17,     0,    18,    19,     0,
       0,    20,     0,    21,     0,     0,     0,     0,     0,    22,
      56,    57,    58,    59,    60,    61,    62,     0,    63,    64,
      65,     0,     0,     0,     0,     0,    66,    67,    68,    69,
      70,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    71,    72
};

static const yytype_int16 yycheck[] =
{
       2,    53,   216,    23,    24,    25,    26,    23,    24,    25,
      45,    46,    58,    45,    46,    43,     0,     3,     4,     5,
       6,     7,     8,     9,    10,    58,    23,    20,    21,    23,
      65,    64,    34,    67,    68,    69,    70,    69,    36,    23,
      24,    25,    26,    41,    46,    73,    74,    75,    76,    45,
      46,    45,    46,    69,    58,    23,    45,    46,    62,    43,
      80,    81,    96,    58,    66,    67,    68,    69,    70,    53,
      58,    57,    68,    62,   288,    65,   290,    45,    46,    69,
      58,    21,    59,    85,    86,    38,    64,    40,    90,    73,
      74,    75,    76,    38,    96,    64,    80,    81,    45,    46,
     102,    54,   154,   155,   106,   157,   134,   135,    58,    23,
     103,    59,    59,    45,    46,    37,    63,    64,   120,    23,
      24,    25,    38,    32,    33,    34,    37,   120,    60,   122,
     123,   124,   125,    42,    58,    49,    50,    51,    52,    53,
     142,    55,    56,    58,    38,    59,    40,    61,    45,    46,
     134,   135,    58,    67,    37,   148,   158,    44,    60,    69,
      54,    68,    58,   103,    37,    68,    64,    68,    68,   171,
     154,   155,    60,   157,     3,     4,     5,     6,     7,     8,
       9,    10,   122,   123,   124,   125,   188,    68,    68,    26,
     183,    60,    56,    36,    66,   197,   198,   199,    26,   201,
     202,   203,   204,    68,    58,    68,    68,    68,   148,    68,
     212,    68,   214,    49,    50,    51,    52,    53,    68,    55,
      56,    68,    68,    59,    68,    61,    47,    48,    49,    37,
      64,    67,    49,    50,    51,    52,    53,   108,    55,    56,
      66,    -1,    59,   183,    61,   297,    58,    58,   250,   251,
     252,   253,   254,   255,   256,   257,   249,    58,    -1,    84,
      84,   263,   246,   265,   266,   267,   268,   260,    -1,   271,
      -1,    -1,    -1,   275,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   287,    -1,    -1,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,    -1,
     121,    -1,    -1,    -1,    -1,   126,   127,    -1,    -1,   249,
      -1,    -1,   133,   297,   316,   317,    -1,   319,   320,   140,
     260,    -1,   143,     1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    -1,    -1,    -1,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    -1,   174,    -1,   176,    -1,   178,    -1,    37,
      38,    39,    40,    41,    -1,    43,    -1,    45,    46,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,   200,
      -1,    59,     0,    61,    -1,    -1,    -1,    -1,    -1,    67,
       8,     9,    10,    -1,    -1,    -1,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,    23,    24,    25,    26,    -1,
      -1,    -1,   233,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   242,   243,   244,    -1,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    -1,    -1,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    76,    -1,
      78,    79,    80,    81,    -1,   286,    -1,    -1,   289,    -1,
     291,    -1,    -1,   294,   295,    -1,    -1,    -1,    -1,    -1,
      -1,    99,   100,   101,    -1,   103,    -1,    -1,    -1,   107,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   120,   324,   122,   123,   124,   125,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   134,   135,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     148,    -1,    -1,    -1,    -1,    -1,     0,     1,    -1,    -1,
      -1,    -1,    -1,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,    -1,    18,    -1,    -1,    -1,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,   184,    -1,   186,    -1,
      -1,    -1,    -1,    37,    -1,    39,    -1,    41,    -1,    43,
      -1,    45,    46,     1,    -1,    49,    50,    51,    52,    53,
     208,    55,    56,    -1,    -1,    59,    -1,    61,    -1,    -1,
      18,    -1,    -1,    67,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      38,    39,    40,    41,    -1,    43,    -1,    45,    46,     1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      -1,    59,    -1,    61,    -1,    -1,    18,    -1,    -1,    67,
      22,    23,    24,    25,   272,   273,   274,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    38,    39,    -1,    41,
      -1,    43,    -1,    45,    46,     1,    -1,    49,    50,    51,
      52,    53,    -1,    55,    56,    -1,    -1,    59,    -1,    61,
      -1,    -1,    18,    -1,    -1,    67,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    38,    39,    -1,    41,    -1,    43,    -1,    45,
      46,     1,    -1,    49,    50,    51,    52,    53,    -1,    55,
      56,    -1,    -1,    59,    -1,    61,    -1,    -1,    18,    -1,
      -1,    67,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,
      -1,    41,    -1,    43,    -1,    45,    46,     1,    -1,    49,
      50,    51,    52,    53,    -1,    55,    56,    -1,    -1,    59,
      -1,    61,    -1,    -1,    18,    -1,    -1,    67,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    38,    39,    -1,    41,    -1,    43,
      -1,    45,    46,     1,    -1,    49,    50,    51,    52,    53,
      -1,    55,    56,    -1,    -1,    59,    -1,    61,    -1,    -1,
      18,    -1,    -1,    67,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      -1,    39,    -1,    41,    -1,    43,    -1,    45,    46,    -1,
      -1,    49,    50,    51,    52,    53,    -1,    55,    56,    -1,
      -1,    59,    -1,    61,    -1,    -1,    -1,    -1,    -1,    67,
      11,    12,    13,    14,    15,    16,    17,    -1,    19,    20,
      21,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    18,    22,    23,    24,    25,    37,    39,    41,
      43,    45,    46,    49,    50,    51,    52,    53,    55,    56,
      59,    61,    67,    71,    73,    76,    77,    78,    82,    83,
      84,    85,    89,    92,    94,    95,    99,   100,   101,   102,
     103,   104,   105,   106,    92,    93,    58,    92,    92,    92,
      60,    93,    97,    98,    62,    98,    11,    12,    13,    14,
      15,    16,    17,    19,    20,    21,    27,    28,    29,    30,
      31,    47,    48,   106,   106,   106,   106,    38,    40,    54,
      74,    75,    79,    80,    81,    59,    63,    93,    25,    85,
      59,    25,    69,    85,     0,   105,    58,    93,    94,   104,
     104,   104,    23,    86,    89,    94,    58,    87,    88,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    93,
      96,    97,    96,    96,    96,    96,    92,    92,    38,    72,
      38,    38,    92,    92,   106,   106,    38,    38,    79,    80,
      93,    93,    64,    93,    32,    33,    34,    42,    96,    58,
      92,    92,    92,    93,    92,    97,    98,    93,    23,    92,
      62,    87,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,    68,    92,    93,    97,   104,    97,    98,
      98,    98,    98,   104,   104,    37,   104,    38,   104,     3,
       4,     5,     6,     7,     8,     9,    10,    57,    90,    91,
      93,   104,    58,    58,    58,    98,    37,    37,    44,    89,
      89,    60,    89,    93,    23,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    93,   104,   104,    68,    68,
      68,    68,    98,    92,    92,    93,    93,    65,    93,    93,
     104,    93,    93,    93,    93,    58,    92,    93,    93,    90,
     104,   104,   104,   104,   104,   104,   104,   104,    68,    68,
     104,    37,    60,    64,    26,    58,    64,    58,    64,    65,
      60,   104,   104,   104,    94,    36,    98,    93,    93,    93,
      93,    93,    93,    93,    93,    98,    93,    66,    93,    93,
      93,    93,    26,    93,    92,    92,    92,    93,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,   104,    93,
      90,   104,    90,   104,    66,    58,   104,   104,    37,    89,
      64,    93,    93,    93,    93,    58,    58,    58,   104
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    81,    82,    83,    84,    84,    84,    84,
      85,    85,    86,    86,    86,    87,    88,    88,    88,    88,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    90,    90,    90,    90,    90,    90,    90,    90,    91,
      91,    92,    92,    93,    93,    94,    95,    95,    95,    95,
      95,    95,    96,    96,    96,    96,    97,    98,    98,    99,
      99,    99,   100,   100,   100,   100,   100,   100,   100,   101,
     101,   101,   101,   101,   101,   102,   102,   102,   103,   103,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   106,   106
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     5,     5,     3,     5,     9,     2,
       2,     2,     1,     2,     3,     3,     2,     3,     4,     3,
       1,     1,     1,     3,     3,     9,     3,     2,     4,     3,
       1,     1,     1,     1,     1,     1,     1,     5,     2,     4,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       5,     1,     1,     1,     0,     1,     8,     8,     8,     5,
      11,     8,     2,     2,     3,     3,     3,     1,     1,     1,
       6,     4,     4,     5,     5,     5,     5,     6,     8,     8,
       8,     8,     8,     8,     8,     8,     6,     8,     6,     6,
       1,     1,     8,     1,     1,     8,    10,     1,    10,     3,
       2,     2,     2,     2,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     2
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
#line 112 "./parser/Parser.y"
                                      { i.EatAst(MakeStartAst()); }
#line 1702 "./parser/Parser.cpp"
    break;

  case 3:
#line 114 "./parser/Parser.y"
                                    { i.EatAst(MakeEndScopeAst()); }
#line 1708 "./parser/Parser.cpp"
    break;

  case 4:
#line 116 "./parser/Parser.y"
                                                            {
                                    root = nullptr;
                                    i.EatAst(MakeIfDeclAst((yyvsp[-2].tmp_id)));
                                }
#line 1717 "./parser/Parser.cpp"
    break;

  case 5:
#line 121 "./parser/Parser.y"
                                                                 {
                                    root = nullptr;
                                    i.EatAst(MakeElifDeclAst((yyvsp[-2].tmp_id)));
                                }
#line 1726 "./parser/Parser.cpp"
    break;

  case 6:
#line 126 "./parser/Parser.y"
                                                 {
                                    i.EatAst(MakeElseDeclAst());
                                }
#line 1734 "./parser/Parser.cpp"
    break;

  case 7:
#line 130 "./parser/Parser.y"
                                                               {
                                    root = nullptr;
                                    i.EatAst(MakeWhileDeclAst((yyvsp[-2].tmp_id)));
                                }
#line 1743 "./parser/Parser.cpp"
    break;

  case 8:
#line 135 "./parser/Parser.y"
                                                                                      {
                                    i.EatAst(MakeNode(START_BLOCK_CMD));

                                    auto type = MakeDataTypeNode("int");
                                    auto val = MakeTermNode(0, INT_NODE_TYPE);
                                    auto make = MakeAssignAst((yyvsp[-2].tmp_id), type, val);
                                    i.EatAst(make);

                                    auto less = MakeLessCompAst((yyvsp[-2].tmp_id)->Copy(), (yyvsp[-6].tmp_id));
                                    auto while_ast = MakeWhileDeclAst(less);
                                    i.EatAst(while_ast);
                                    
                                    root = nullptr;
                                    (yyval.tmp_id) = (yyvsp[-2].tmp_id)->Copy();
                                }
#line 1763 "./parser/Parser.cpp"
    break;

  case 14:
#line 156 "./parser/Parser.y"
                                                   {
                                    i.EatAst(MakeEndCtrlScopeAst());
                                }
#line 1771 "./parser/Parser.cpp"
    break;

  case 15:
#line 160 "./parser/Parser.y"
                                                     {
                                    i.EatAst(MakeIncAst((yyvsp[-2].tmp_id)));
                                    i.EatAst(MakeEndCtrlScopeAst());
                                    i.EatAst(MakeEndScopeAst());  
                                }
#line 1781 "./parser/Parser.cpp"
    break;

  case 16:
#line 166 "./parser/Parser.y"
                                           {
                                    i.EatAst(MakeEndCtrlScopeAst());
                                }
#line 1789 "./parser/Parser.cpp"
    break;

  case 17:
#line 169 "./parser/Parser.y"
                                                         {
                                    i.EatAst(MakeEndCtrlScopeAst());
                                }
#line 1797 "./parser/Parser.cpp"
    break;

  case 18:
#line 172 "./parser/Parser.y"
                                                                  {
                                    i.EatAst(MakeEndCtrlScopeAst());
                                }
#line 1805 "./parser/Parser.cpp"
    break;

  case 19:
#line 175 "./parser/Parser.y"
                                                      {
                                    i.EatAst(MakeEndCtrlScopeAst());
                                }
#line 1813 "./parser/Parser.cpp"
    break;

  case 20:
#line 179 "./parser/Parser.y"
                                        {i.EatAst(root); root = nullptr;}
#line 1819 "./parser/Parser.cpp"
    break;

  case 22:
#line 181 "./parser/Parser.y"
                                     { (yyval.tmp_id) = (yyvsp[0].tmp_id); }
#line 1825 "./parser/Parser.cpp"
    break;

  case 23:
#line 182 "./parser/Parser.y"
                                                          { (yyvsp[-2].tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id)); (yyval.tmp_id) = (yyvsp[-2].tmp_id); }
#line 1831 "./parser/Parser.cpp"
    break;

  case 24:
#line 183 "./parser/Parser.y"
                                                               {(yyvsp[-2].tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id)); (yyval.tmp_id) = (yyvsp[-2].tmp_id); }
#line 1837 "./parser/Parser.cpp"
    break;

  case 25:
#line 186 "./parser/Parser.y"
                                                                                                  {
                                    (yyval.tmp_id) = new AstNode();
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[-6].tmp_id));
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[-2].tmp_id));
                                }
#line 1847 "./parser/Parser.cpp"
    break;

  case 26:
#line 193 "./parser/Parser.y"
                                                               {
                                    (yyval.tmp_id) = new AstNode();
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[-2].tmp_id)->GetExtraNode());
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[-2].tmp_id)->GetExtraNode(1));
                                    (yyvsp[-2].tmp_id)->NullExtraNode(0);
                                    (yyvsp[-2].tmp_id)->NullExtraNode(1);
                                    delete (yyvsp[-2].tmp_id);
                                    root = (yyval.tmp_id);
                                }
#line 1861 "./parser/Parser.cpp"
    break;

  case 27:
#line 202 "./parser/Parser.y"
                                                         {
                                    (yyval.tmp_id) = new AstNode();
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[-1].tmp_id)->GetExtraNode());
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[-1].tmp_id)->GetExtraNode(1));
                                    (yyvsp[-1].tmp_id)->NullExtraNode(0);
                                    (yyvsp[-1].tmp_id)->NullExtraNode(1);
                                    delete (yyvsp[-1].tmp_id);
                                    root = (yyval.tmp_id);
                                }
#line 1875 "./parser/Parser.cpp"
    break;

  case 28:
#line 211 "./parser/Parser.y"
                                                                               {
                                    (yyvsp[-3].tmp_id)->SaveAsExtraNode((yyvsp[-2].tmp_id)->GetExtraNode());
                                    (yyvsp[-3].tmp_id)->SaveAsExtraNode((yyvsp[-2].tmp_id)->GetExtraNode(1));
                                    (yyvsp[-2].tmp_id)->NullExtraNode(0);
                                    (yyvsp[-2].tmp_id)->NullExtraNode(1);
                                    delete (yyvsp[-2].tmp_id);
                                    (yyval.tmp_id) = (yyvsp[-3].tmp_id);
                                    root = (yyval.tmp_id);
                                }
#line 1889 "./parser/Parser.cpp"
    break;

  case 29:
#line 220 "./parser/Parser.y"
                                                                       {
                                    (yyvsp[-2].tmp_id)->SaveAsExtraNode((yyvsp[-1].tmp_id)->GetExtraNode());
                                    (yyvsp[-2].tmp_id)->SaveAsExtraNode((yyvsp[-1].tmp_id)->GetExtraNode(1));
                                    (yyvsp[-1].tmp_id)->NullExtraNode(0);
                                    (yyvsp[-1].tmp_id)->NullExtraNode(1);
                                    delete (yyvsp[-1].tmp_id);
                                    (yyval.tmp_id) = (yyvsp[-2].tmp_id);
                                    root = (yyval.tmp_id);
                                }
#line 1903 "./parser/Parser.cpp"
    break;

  case 30:
#line 231 "./parser/Parser.y"
                                                { 
                                       (yyval.tmp_id) = MakeTermNode((yyvsp[0].int_val), INT_NODE_TYPE);
                                       root = (yyval.tmp_id);             
                                }
#line 1912 "./parser/Parser.cpp"
    break;

  case 31:
#line 235 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeTermNode((yyvsp[0].dou_val), DOUBLE_NODE_TYPE);
                                        root = (yyval.tmp_id);          
                                }
#line 1921 "./parser/Parser.cpp"
    break;

  case 32:
#line 239 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeTermNode((yyvsp[0].flo_val), FLOAT_NODE_TYPE);
                                        root = (yyval.tmp_id);            
                                }
#line 1930 "./parser/Parser.cpp"
    break;

  case 33:
#line 243 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeTermNode((string)(yyvsp[0].str_val), STRING_NODE_TYPE);
                                        root = (yyval.tmp_id);                    
                                }
#line 1939 "./parser/Parser.cpp"
    break;

  case 34:
#line 247 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeTermNode((yyvsp[0].char_val), CHAR_NODE_TYPE);
                                        root = (yyval.tmp_id);
                                }
#line 1948 "./parser/Parser.cpp"
    break;

  case 35:
#line 251 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeTermNode((yyvsp[0].bol_val), BOOL_NODE_TYPE);
                                        root = (yyval.tmp_id);
                                }
#line 1957 "./parser/Parser.cpp"
    break;

  case 36:
#line 255 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                        root = (yyval.tmp_id);         
                                }
#line 1966 "./parser/Parser.cpp"
    break;

  case 37:
#line 259 "./parser/Parser.y"
                                                                           {
                                    (yyval.tmp_id) = MakeArrayTermAst((yyvsp[-2].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 1975 "./parser/Parser.cpp"
    break;

  case 38:
#line 263 "./parser/Parser.y"
                                          {
                                    (yyval.tmp_id) = MakeTermNode(0, ARRAY_NODE_TYPE);
                                    root = (yyval.tmp_id);
                                }
#line 1984 "./parser/Parser.cpp"
    break;

  case 39:
#line 267 "./parser/Parser.y"
                                                               {
                                    (yyval.tmp_id) = MakeMapTermAst((yyvsp[-1].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 1993 "./parser/Parser.cpp"
    break;

  case 40:
#line 271 "./parser/Parser.y"
                                          {
                                    (yyval.tmp_id) = MakeTermNode(0, MAP_NODE_TYPE);
                                    root = (yyval.tmp_id);
                                }
#line 2002 "./parser/Parser.cpp"
    break;

  case 41:
#line 277 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].types)); root = (yyval.tmp_id); }
#line 2008 "./parser/Parser.cpp"
    break;

  case 42:
#line 278 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].types)); root = (yyval.tmp_id); }
#line 2014 "./parser/Parser.cpp"
    break;

  case 43:
#line 279 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].types)); root = (yyval.tmp_id); }
#line 2020 "./parser/Parser.cpp"
    break;

  case 44:
#line 280 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].types)); root = (yyval.tmp_id); }
#line 2026 "./parser/Parser.cpp"
    break;

  case 45:
#line 281 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].types)); root = (yyval.tmp_id); }
#line 2032 "./parser/Parser.cpp"
    break;

  case 46:
#line 282 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].types)); root = (yyval.tmp_id); }
#line 2038 "./parser/Parser.cpp"
    break;

  case 47:
#line 283 "./parser/Parser.y"
                                       {
                                    (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].types));
                                    root = (yyval.tmp_id);
                                }
#line 2047 "./parser/Parser.cpp"
    break;

  case 48:
#line 287 "./parser/Parser.y"
                                      {
                                    (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].types));
                                    root = (yyval.tmp_id);
                                }
#line 2056 "./parser/Parser.cpp"
    break;

  case 49:
#line 293 "./parser/Parser.y"
                                                                            {
                                   (yyval.tmp_id) = (yyvsp[-4].tmp_id);
                                   (yyval.tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id));
                                   root = (yyval.tmp_id);
                                }
#line 2066 "./parser/Parser.cpp"
    break;

  case 50:
#line 298 "./parser/Parser.y"
                                                                           {
                                    (yyval.tmp_id) = (yyvsp[-4].tmp_id);
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2076 "./parser/Parser.cpp"
    break;

  case 55:
#line 309 "./parser/Parser.y"
                                   {
                                    (yyval.tmp_id) = MakeTermNode((yyvsp[0].id), ID_NODE_TYPE);
                                    root = (yyval.tmp_id); 
                                }
#line 2085 "./parser/Parser.cpp"
    break;

  case 56:
#line 314 "./parser/Parser.y"
                                                                           {
                                    (yyval.tmp_id) = MakeAssignAst((yyvsp[-7].tmp_id), (yyvsp[-4].tmp_id), (yyvsp[0].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2094 "./parser/Parser.cpp"
    break;

  case 57:
#line 318 "./parser/Parser.y"
                                                                               {
                                    (yyval.tmp_id) = MakeUnionAst((yyvsp[-7].tmp_id), (yyvsp[0].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2103 "./parser/Parser.cpp"
    break;

  case 58:
#line 322 "./parser/Parser.y"
                                                                                  {
                                    (yyval.tmp_id) = MakeUnionAst((yyvsp[-7].tmp_id), (yyvsp[-4].tmp_id), (yyvsp[0].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2112 "./parser/Parser.cpp"
    break;

  case 59:
#line 326 "./parser/Parser.y"
                                                            {
                                   (yyval.tmp_id) = MakeReassignAst((yyvsp[-4].tmp_id), (yyvsp[0].tmp_id));
                                   root = (yyval.tmp_id);
                                }
#line 2121 "./parser/Parser.cpp"
    break;

  case 60:
#line 330 "./parser/Parser.y"
                                                                                         {
                                    (yyval.tmp_id) = MakeRefAst((yyvsp[-10].tmp_id), (yyvsp[-7].tmp_id), (yyvsp[0].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2130 "./parser/Parser.cpp"
    break;

  case 61:
#line 334 "./parser/Parser.y"
                                                                        {
                                    (yyval.tmp_id) = MakeRebindRefAst((yyvsp[-7].tmp_id), (yyvsp[-3].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2139 "./parser/Parser.cpp"
    break;

  case 62:
#line 341 "./parser/Parser.y"
                                           {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2147 "./parser/Parser.cpp"
    break;

  case 63:
#line 344 "./parser/Parser.y"
                                                   {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2155 "./parser/Parser.cpp"
    break;

  case 64:
#line 347 "./parser/Parser.y"
                                                             {  
                                    (yyvsp[-2].tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id));
                                    (yyval.tmp_id) = (yyvsp[-2].tmp_id);
                                }
#line 2164 "./parser/Parser.cpp"
    break;

  case 65:
#line 351 "./parser/Parser.y"
                                                                  {
                                    (yyvsp[-2].tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id));
                                    (yyval.tmp_id) = (yyvsp[-2].tmp_id);
                                }
#line 2173 "./parser/Parser.cpp"
    break;

  case 70:
#line 361 "./parser/Parser.y"
                                                                            { 
                                    (yyval.tmp_id) = MakePrintAst((yyvsp[-2].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2182 "./parser/Parser.cpp"
    break;

  case 71:
#line 365 "./parser/Parser.y"
                                                     { return 0; }
#line 2188 "./parser/Parser.cpp"
    break;

  case 72:
#line 370 "./parser/Parser.y"
                                                           {
                                    Perform((yyval.tmp_id), (yyvsp[-1].tmp_id), ADDITION_CMD);
                                    root = (yyval.tmp_id);
                                }
#line 2197 "./parser/Parser.cpp"
    break;

  case 73:
#line 374 "./parser/Parser.y"
                                                                         {
                                    Perform((yyval.tmp_id), (yyvsp[-2].tmp_id), SUBTRACTION_CMD);
                                    root = (yyval.tmp_id);
                                }
#line 2206 "./parser/Parser.cpp"
    break;

  case 74:
#line 378 "./parser/Parser.y"
                                                                          {
                                    Perform((yyval.tmp_id), (yyvsp[-2].tmp_id), MULTIPLY_CMD);
                                    root = (yyval.tmp_id);
                                }
#line 2215 "./parser/Parser.cpp"
    break;

  case 75:
#line 382 "./parser/Parser.y"
                                                                          {
                                    Perform((yyval.tmp_id), (yyvsp[-2].tmp_id), DIVIDE_CMD);
                                    root = (yyval.tmp_id);
                                }
#line 2224 "./parser/Parser.cpp"
    break;

  case 76:
#line 386 "./parser/Parser.y"
                                                                          {
                                    Perform((yyval.tmp_id), (yyvsp[-2].tmp_id), POW_CMD);
                                    root = (yyval.tmp_id);
                                }
#line 2233 "./parser/Parser.cpp"
    break;

  case 77:
#line 390 "./parser/Parser.y"
                                                                        {
                                    (yyval.tmp_id) = MakeIncAst((yyvsp[-2].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2242 "./parser/Parser.cpp"
    break;

  case 78:
#line 394 "./parser/Parser.y"
                                                                                                {
                                    (yyval.tmp_id) = MakeModAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2251 "./parser/Parser.cpp"
    break;

  case 79:
#line 403 "./parser/Parser.y"
                                                                                           {
                                    (yyval.tmp_id) = MakeLessCompAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2260 "./parser/Parser.cpp"
    break;

  case 80:
#line 407 "./parser/Parser.y"
                                                                                                {
                                    (yyval.tmp_id) = MakeGreaterCompAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2269 "./parser/Parser.cpp"
    break;

  case 81:
#line 411 "./parser/Parser.y"
                                                                                                  {
                                    (yyval.tmp_id) = MakeLessEqualCompAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2278 "./parser/Parser.cpp"
    break;

  case 82:
#line 415 "./parser/Parser.y"
                                                                                                      {
                                    (yyval.tmp_id) = MakeGreaterEqualCompAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2287 "./parser/Parser.cpp"
    break;

  case 83:
#line 419 "./parser/Parser.y"
                                                                                             {
                                    (yyval.tmp_id) = MakeEqualCompAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2296 "./parser/Parser.cpp"
    break;

  case 84:
#line 423 "./parser/Parser.y"
                                                                                                  {
                                    (yyval.tmp_id) = MakeNotEqualCompAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2305 "./parser/Parser.cpp"
    break;

  case 85:
#line 431 "./parser/Parser.y"
                                                                                         {
                                    (yyval.tmp_id) = MakeAndAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2314 "./parser/Parser.cpp"
    break;

  case 86:
#line 435 "./parser/Parser.y"
                                                                 {
                                    (yyval.tmp_id) = MakeNotAst((yyvsp[-2].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2323 "./parser/Parser.cpp"
    break;

  case 87:
#line 439 "./parser/Parser.y"
                                                                                           {
                                    (yyval.tmp_id) = MakeOrAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2332 "./parser/Parser.cpp"
    break;

  case 88:
#line 446 "./parser/Parser.y"
                                                              {
                                    (yyval.tmp_id) = MakeGetFromCollectionAst((yyvsp[-5].tmp_id), (yyvsp[-2].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2341 "./parser/Parser.cpp"
    break;

  case 89:
#line 450 "./parser/Parser.y"
                                                                                {
                                    (yyvsp[-5].tmp_id)->AddToMiddleNodes((yyvsp[-2].tmp_id));
                                    (yyval.tmp_id) = (yyvsp[-5].tmp_id);
                                    root = (yyval.tmp_id);
                                }
#line 2351 "./parser/Parser.cpp"
    break;

  case 90:
#line 458 "./parser/Parser.y"
                                     {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                    root = (yyval.tmp_id);
                                }
#line 2360 "./parser/Parser.cpp"
    break;

  case 91:
#line 462 "./parser/Parser.y"
                                            {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                    root = (yyval.tmp_id);
                                }
#line 2369 "./parser/Parser.cpp"
    break;

  case 92:
#line 466 "./parser/Parser.y"
                                                                                          {
                                    (yyval.tmp_id) = MakeCastAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2378 "./parser/Parser.cpp"
    break;

  case 93:
#line 470 "./parser/Parser.y"
                                               {
                                   (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                   root = (yyval.tmp_id);
                                }
#line 2387 "./parser/Parser.cpp"
    break;

  case 94:
#line 474 "./parser/Parser.y"
                                           {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                    root = (yyval.tmp_id);
                                }
#line 2396 "./parser/Parser.cpp"
    break;

  case 95:
#line 478 "./parser/Parser.y"
                                                                                           {
                                     (yyval.tmp_id) = MakeAddToListAst((yyvsp[-7].tmp_id), (yyvsp[-2].tmp_id));
                                     root = (yyval.tmp_id);
                                }
#line 2405 "./parser/Parser.cpp"
    break;

  case 96:
#line 482 "./parser/Parser.y"
                                                                                                          {
                                    (yyval.tmp_id) = MakeAddToMapAst((yyvsp[-9].tmp_id), (yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2414 "./parser/Parser.cpp"
    break;

  case 97:
#line 486 "./parser/Parser.y"
                                                {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                    root = (yyval.tmp_id);
                                }
#line 2423 "./parser/Parser.cpp"
    break;

  case 98:
#line 490 "./parser/Parser.y"
                                                                                                            {
                                    (yyval.tmp_id) = MakeSetInCollectionAst((yyvsp[-9].tmp_id), (yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2432 "./parser/Parser.cpp"
    break;

  case 99:
#line 494 "./parser/Parser.y"
                                                      {
                                    (yyval.tmp_id) = MakeCollectionSizeAst((yyvsp[-2].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2441 "./parser/Parser.cpp"
    break;

  case 109:
#line 509 "./parser/Parser.y"
                                       { 
                                    i.EatAst(root);
                                    return 0 ;
                                }
#line 2450 "./parser/Parser.cpp"
    break;

  case 111:
#line 514 "./parser/Parser.y"
                                        { return 0; }
#line 2456 "./parser/Parser.cpp"
    break;


#line 2460 "./parser/Parser.cpp"

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
#line 517 "./parser/Parser.y"



void PrintLineNo() {
    cout << "line num: " << lineno << "\n";
    lineno++;
}

void yyerror(const char* err) {
    cout << err << '\n';
}

#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
    bool in_file_mode = false;
    FILE *file = nullptr;
    
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        
        if (file != nullptr) {
            yyin = file;
            in_file_mode = true;
        }
        else {
            cout << "Error: file doesn't exist\n";
            return 1;
        }
    }
    int x = yyparse();
    while(x != 0 && !in_file_mode) {
        // makes sure to clear the token buffer
        // so that when a parser or interpreter error
        // happens, tokens aren't trying to be read again
        yyrestart(yyin);
        
        x = yyparse();
    }

    if (file != nullptr) {
        fclose(file);
    }
    return x;
}
