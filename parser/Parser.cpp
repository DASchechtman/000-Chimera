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
#line 6 "./parser/Parser.y"

#include <iostream>
#include <string>
#include <unistd.h>
#include <stdio.h>
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

#line 96 "./parser/Parser.cpp"

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
/* "%code requires" blocks.  */
#line 2 "./parser/Parser.y"

#include "Utils/UnionStruct.hpp"

#line 143 "./parser/Parser.cpp"

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
    POINTS_TO = 290,
    START = 291,
    END = 292,
    IF = 293,
    ELSE = 294,
    WHILE = 295,
    SIZE = 296,
    REPEAT = 297,
    WITH = 298,
    INC = 299,
    MOD = 300,
    GET = 301,
    SURO = 302,
    CALL = 303,
    ASSIGN = 304,
    FUNC_RET = 305,
    INT_VAL = 306,
    DOUBLE_VAL = 307,
    STRING_VAL = 308,
    CHAR_VAL = 309,
    BOOL_VAL = 310,
    ELSE_IF = 311,
    FLOAT_VAL = 312,
    ID = 313,
    UNKNOWN = 314,
    MULTI_WS = 315,
    SINGLE_WS = 316
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 34 "./parser/Parser.y"

    YYSTYPEs *data;
    AstNode *tmp_id;

#line 221 "./parser/Parser.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


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
#define YYFINAL  99
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1267

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  127
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  410

#define YYUNDEFTOK  2
#define YYMAXUTOK   316


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
      64,    65,     2,     2,     2,     2,    73,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    62,     2,
      71,    70,    72,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    66,     2,    67,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    68,    63,    69,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   128,   128,   130,   132,   136,   140,   144,   148,   162,
     171,   178,   185,   193,   199,   209,   215,   220,   231,   232,
     233,   234,   234,   236,   240,   246,   249,   252,   255,   259,
     268,   268,   270,   271,   272,   275,   282,   290,   298,   306,
     316,   319,   322,   325,   328,   331,   334,   337,   340,   343,
     346,   351,   352,   353,   354,   355,   356,   357,   360,   365,
     369,   375,   375,   377,   377,   379,   383,   386,   389,   392,
     395,   398,   401,   404,   407,   410,   416,   420,   424,   428,
     434,   435,   435,   437,   438,   441,   446,   449,   452,   455,
     458,   461,   464,   472,   475,   478,   481,   484,   487,   494,
     497,   500,   506,   512,   515,   518,   521,   524,   527,   530,
     533,   536,   539,   542,   545,   548,   549,   550,   551,   552,
     553,   554,   555,   556,   557,   561,   563,   563
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
  "DIV", "POW", "ADD_LIST", "ADD_MAP", "SET", "POINTS_TO", "START", "END",
  "IF", "ELSE", "WHILE", "SIZE", "REPEAT", "WITH", "INC", "MOD", "GET",
  "SURO", "CALL", "ASSIGN", "FUNC_RET", "INT_VAL", "DOUBLE_VAL",
  "STRING_VAL", "CHAR_VAL", "BOOL_VAL", "ELSE_IF", "FLOAT_VAL", "ID",
  "UNKNOWN", "MULTI_WS", "SINGLE_WS", "':'", "'|'", "'('", "')'", "'['",
  "']'", "'{'", "'}'", "'='", "'<'", "'>'", "'.'", "$accept", "start",
  "end", "ifHead", "elseIfHead", "elseHead", "whileHead", "forloopHead",
  "paramList", "functionHead", "funcRet", "functionCall", "ifBody",
  "elseIfBody", "elseBody", "elseIfChain", "whileStatement",
  "forloopStatement", "ifStatement", "functionDeclStatement", "newline",
  "terms", "keyValPairs", "keyVals", "term", "types", "unionTypes",
  "any_ws", "opt_ws", "id", "assign", "exprList", "opt_newline",
  "opt_ws_or_nl", "statement", "math_expr", "compare_expr", "boolExpr",
  "indexAccessor", "expr", "prog", "line", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,    58,   124,    40,    41,    91,    93,   123,   125,
      61,    60,    62,    46
};
# endif

#define YYPACT_NINF (-198)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-64)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1161,  -198,   -13,   -45,  -198,  -198,  -198,  -198,   -13,   -13,
     -13,   -13,   -13,  -198,  -198,  -198,  -198,  -198,  -198,  -198,
    -198,  -198,   817,    21,   -54,  1161,  1161,  1161,  1161,  1161,
    -198,  -198,   -10,  -198,  -198,  -198,  -198,  -198,  -198,  -198,
    -198,  -198,  -198,  -198,  -198,  -198,  -198,   -52,  -198,   563,
    -198,   -35,   -13,   353,   353,   353,   -20,   353,   -13,   -13,
     -13,   -13,   -13,   -13,   -13,   -13,   -13,   -13,   -13,   -13,
     -13,   -13,   -13,   -13,   -13,   -13,   -13,   -13,   -13,  -198,
      22,  -198,   256,  -198,   -14,   926,   758,   973,  1020,  1067,
    -198,   -13,   -13,  1161,  1161,  -198,    24,     4,    30,  -198,
    -198,   -13,    -5,  1219,   -57,   -57,   -57,   -13,   -52,   353,
     353,   353,   353,   353,   353,   353,   353,   353,   353,   157,
     -13,   353,   -13,   -13,   -13,   -13,   353,   353,   -20,   -20,
     -20,   -20,   -13,   -13,  -198,   -13,   -21,    29,  -198,  -198,
    -198,  -198,  -198,    23,   353,   868,  1114,  -198,  -198,  -198,
      35,    11,    41,    54,  -198,   -13,  -198,    48,    51,    79,
      60,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,   -52,   353,   353,    59,   -52,    61,    62,    63,    66,
     -57,   -57,   -13,   -13,   -13,   -13,  -198,   256,   256,    58,
     256,   -13,  -198,  -198,    -9,  -198,   -57,  -198,   -13,   -13,
     -13,    69,  -198,  -198,   -13,   232,   440,   353,   353,   353,
     353,   353,   353,   353,   353,    70,   -52,   -52,  -198,  -198,
    -198,  -198,  -198,    71,   353,   353,    50,    72,    76,   353,
      77,  -198,  -198,  -198,   -13,  -198,   -13,  -198,    98,   353,
     353,   353,  -198,   -20,  -198,  -198,  -198,  -198,  -198,  -198,
    -198,  -198,    84,   -13,  -198,    85,   -13,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,  -198,  -198,   -57,     0,   -13,
    -198,   -13,   -57,   -13,   106,  -198,  -198,   -57,   -57,   -57,
     -13,   -13,   296,    86,   -13,    83,    87,   100,   101,   104,
     105,   107,   108,   109,   112,  -198,   113,    27,    18,   154,
     -13,   116,   353,   353,   114,   440,  -198,   122,   123,   440,
    -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,
    -198,   -13,   440,   -13,  -198,   145,   -13,   440,   -13,   256,
    -198,   -57,   -57,  -198,   -13,   -13,   -13,  -198,   353,   -13,
      34,   353,   115,   119,   353,    36,   353,   124,   -13,   130,
     131,   151,   440,   440,   -57,   136,   -13,   138,   -57,   176,
     -13,   -57,   -13,   -57,   177,   142,  -198,  -198,  -198,  -198,
     -13,   141,   -13,   353,   -13,   152,   135,   153,   161,   353,
     162,   144,  -198,   183,  -198,   440,   -57,   440,  -198,   -13,
    -198,  -198,   -57,  -198,   -13,  -198,  -198,   163,  -198,   353,
     164,   353,  -198,   -57,  -198,   -57,   165,   168,  -198,  -198
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,   125,    64,     0,    30,    31,   124,     2,     0,     0,
       0,     0,     0,    40,    41,    43,    44,    45,    42,    65,
      61,    62,     0,    64,    64,     0,     0,     0,     0,     0,
     123,   114,     0,   118,   119,   117,   113,   122,   103,   121,
      46,    83,   116,   104,   106,   107,   110,   115,   126,     0,
      63,     0,    64,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    64,    64,
      64,    64,    64,     0,     0,     0,     0,    64,    64,    48,
      81,    82,     0,    50,     0,     0,     0,     0,     0,     0,
      25,     0,     0,     0,     0,    21,     0,     0,     0,     1,
     127,    64,     0,     0,     0,     0,     0,    64,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      64,     0,    64,    64,    64,    64,     0,     0,     0,     0,
       0,     0,    64,    64,    32,    64,     0,     0,     3,   120,
      23,    24,    29,     0,     0,     0,     0,    28,    26,    22,
       0,     0,     0,     0,   112,    64,    85,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      64,    76,    63,    82,     0,    77,     0,     0,     0,     0,
      64,     0,     0,    64,    64,    64,    80,    63,    82,     0,
       0,    64,    37,    49,     0,     6,     0,    27,    64,    64,
      64,     0,     4,     7,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    78,    79,    86,    87,
      88,    89,    90,     0,     0,     0,    64,     0,     0,    63,
       0,    33,    34,    47,    64,    36,    64,    39,     0,     0,
       0,     0,    84,     0,    51,    52,    53,    54,    55,    56,
      57,    58,     0,    64,    10,     0,    64,    64,    64,    64,
      64,    64,    64,    64,    64,   100,    91,    64,     0,    64,
      16,    64,    64,    64,     0,    38,     5,    64,     0,     0,
       0,    64,    63,     0,    64,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   102,     0,     0,     0,     0,
      64,     0,     0,     0,     0,     0,    12,     0,     0,     0,
     105,    93,    94,    95,    96,    97,    98,    99,   101,    92,
      17,     0,     0,    64,    72,     0,     0,     0,    64,     0,
     108,    64,    64,     8,     0,    64,    64,     9,     0,    64,
      64,    63,     0,     0,     0,    64,    63,     0,    64,     0,
       0,     0,     0,     0,    64,     0,     0,     0,    64,     0,
      64,    64,     0,    64,     0,     0,   109,   111,    13,    11,
       0,     0,    64,     0,    64,     0,     0,     0,     0,     0,
       0,     0,    35,     0,    68,     0,    64,     0,    66,     0,
      75,    69,    64,    67,     0,    14,    59,     0,    60,     0,
       0,     0,    70,    64,    71,    64,     0,     0,    73,    74
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,
    -198,  -198,  -198,   125,   146,  -198,  -198,  -198,  -198,  -198,
    -198,  -198,   110,  -198,   -81,  -197,   -83,   366,    -2,   -51,
    -198,   -59,    -4,    20,  -198,  -198,  -198,  -198,  -198,   538,
     -32,    -3
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,   139,    26,    93,    94,    27,    28,   253,    29,
      30,    31,    32,    95,    96,    97,    33,    34,    35,    36,
      37,   133,   136,   137,    38,   339,   340,    50,    80,    40,
      41,   120,   121,    82,    42,    43,    44,    45,    46,    47,
      48,    49
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      51,   134,   191,    20,    21,   107,    20,    21,   254,   256,
     122,   123,   124,   125,   236,    83,    98,   100,    52,    81,
      81,    98,    85,    86,    87,    88,    89,    90,   101,    91,
     244,   245,   246,   247,   248,   249,   250,   251,    19,    20,
      21,   148,   155,    91,    84,   132,    92,    20,    21,   135,
     102,    20,    21,   100,   100,   100,   100,   100,   156,   195,
      92,   147,   151,   152,   153,   295,   119,   119,   119,   119,
     119,   154,   197,    98,   198,   130,   131,   182,   183,   184,
     185,    20,    21,   324,   202,   306,   321,   203,    79,   325,
     145,   146,   135,   322,    20,    21,    20,    21,   193,   119,
     323,   356,   328,   362,   199,   160,   231,   232,   334,   234,
      20,    21,   337,   100,   100,   -63,   173,   200,   173,   173,
     173,   173,   204,   205,   218,   233,   219,   220,   221,   188,
     186,   222,   242,   190,   276,   265,   266,   270,   271,   273,
     174,   300,   176,   177,   178,   179,   281,   284,   310,   308,
     333,   173,   311,   189,   255,   369,   370,   244,   245,   246,
     247,   248,   249,   250,   251,   312,   313,   269,   215,   314,
     315,   343,   316,   317,   318,   201,    81,   319,   320,   330,
     132,   227,   228,   230,   335,   336,   359,   368,   396,   235,
     398,   360,   280,   366,   367,   364,   239,   240,   241,   372,
     223,   374,   376,   381,    11,   382,   384,   389,    13,    14,
      15,    16,    17,   326,    18,    19,   394,   388,   390,   395,
     327,   103,   149,    23,   119,    24,   391,   393,   402,   404,
     408,   307,   274,   409,   275,   244,   245,   246,   247,   248,
     249,   250,   251,   150,   345,     0,     0,   194,   348,     0,
       0,   283,    81,     0,     0,   286,   287,   288,   289,   290,
     291,   292,   293,    81,     0,   173,     0,     0,     0,   297,
     298,   299,     0,     0,     0,   301,   285,     0,     0,   305,
       0,     0,   309,     0,     0,     0,     0,   294,     0,   296,
      19,     0,     0,     0,     0,   252,     0,     0,   329,   244,
     245,   246,   247,   248,   249,   250,   251,    13,    14,    15,
      16,    17,     0,    18,    19,     0,     0,     0,     0,     0,
       0,   342,    23,     0,    24,     0,   347,     0,     0,   349,
     350,     0,     0,   352,   353,     0,     0,   355,   357,     0,
       0,     0,     0,   357,     0,     0,   365,     0,     0,     0,
       0,     0,   371,     0,    19,     0,   375,     0,   377,   378,
       0,   380,     0,     0,     0,     0,    39,     0,     0,     0,
     385,     0,   387,     0,    53,    54,    55,    56,    57,     0,
       0,     0,     0,     0,   397,     0,     0,     0,     0,     0,
     400,    39,    39,    39,    39,    39,     0,     0,     0,     0,
      11,   406,     0,   407,    13,    14,    15,    16,    17,     0,
      18,    19,     0,     0,     0,    39,     0,   103,     0,    23,
       0,    24,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,     0,     0,     0,     0,     0,   126,
     127,   128,   129,   244,   245,   246,   247,   248,   249,   250,
     251,    39,    39,    39,    39,    39,     0,   143,   144,    39,
      39,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     157,   158,   159,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   172,     0,   172,   172,
     172,   172,     0,     0,     0,     0,     0,     0,     0,   187,
       0,     0,   192,     0,     0,     0,     0,     0,     0,     0,
       0,    39,    39,     0,     0,     0,     0,     0,     0,     0,
       0,   172,     0,     0,     0,     0,     0,   206,   207,   208,
     209,   210,   211,   212,   213,   214,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   224,   225,   226,
       0,   229,     0,     0,     0,     0,     0,     0,     0,     0,
     237,     0,   238,    99,     1,     0,     0,     0,     0,     0,
     243,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     0,     0,     0,     3,     4,     5,     6,     0,
       0,   104,   105,   106,     0,   108,     0,     0,     0,     7,
       0,     8,     0,     9,     0,    10,     0,     0,     0,     0,
      11,     0,     0,    12,    13,    14,    15,    16,    17,   282,
      18,    19,     0,    20,    21,     0,     0,    22,     0,    23,
       0,    24,     0,     0,     0,   172,     0,     0,     0,     0,
       0,     0,     0,     0,   302,   303,   304,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,     0,   175,
       0,     0,     0,     0,   180,   181,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   196,     0,     0,     0,     0,   338,     0,   341,
       0,     0,   344,     0,   346,     0,     0,     0,     0,     0,
     351,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     216,   217,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   373,     0,     0,     0,     0,     0,   379,     0,
       0,     0,     0,     0,     0,     0,   383,     0,     0,     0,
       0,     0,     0,     0,     0,   257,   258,   259,   260,   261,
     262,   263,   264,     0,     0,   399,     0,     0,     0,     1,
     401,     0,   267,   268,     0,     0,     0,   272,     0,     0,
       0,     0,     0,     0,     0,     0,     2,   277,   278,   279,
       3,     4,     5,     6,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,   -18,     8,   -18,     9,     0,
      10,     0,     0,     0,     0,    11,     0,     0,    12,    13,
      14,    15,    16,    17,   -18,    18,    19,     0,    20,    21,
       0,     0,    22,     0,    23,     0,    24,     0,    58,    59,
      60,    61,    62,    63,    64,     0,    65,    66,    67,     0,
     331,   332,     0,     0,    68,    69,    70,    71,    72,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    73,    74,    75,     0,    76,    77,     0,     0,     1,
       0,     0,     0,     0,     0,     0,   354,     0,     0,   358,
       0,     0,   361,     0,   363,     0,     2,    78,     0,     0,
       3,     4,     5,     6,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,   -19,     8,   -19,     9,     0,
      10,   386,     0,     0,     0,    11,     0,   392,    12,    13,
      14,    15,    16,    17,   -19,    18,    19,     1,    20,    21,
       0,     0,    22,     0,    23,     0,    24,   403,     0,   405,
       0,     0,     0,     0,     2,     0,     0,     0,     3,     4,
       5,     6,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,   138,     8,     0,     9,     0,    10,     0,
       0,     0,     0,    11,     1,     0,    12,    13,    14,    15,
      16,    17,     0,    18,    19,     0,    20,    21,     0,     0,
      22,     2,    23,     0,    24,     3,     4,     5,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
     140,     8,     0,     9,     0,    10,     0,     0,     0,     0,
      11,     1,     0,    12,    13,    14,    15,    16,    17,     0,
      18,    19,     0,    20,    21,     0,     0,    22,     2,    23,
       0,    24,     3,     4,     5,     6,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,   141,     8,     0,
       9,     0,    10,     0,     0,     0,     0,    11,     1,     0,
      12,    13,    14,    15,    16,    17,     0,    18,    19,     0,
      20,    21,     0,     0,    22,     2,    23,     0,    24,     3,
       4,     5,     6,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,   142,     8,     0,     9,     0,    10,
       0,     0,     0,     0,    11,     1,     0,    12,    13,    14,
      15,    16,    17,     0,    18,    19,     0,    20,    21,     0,
       0,    22,     2,    23,     0,    24,     3,     4,     5,     6,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,   -20,     8,     0,     9,     0,    10,     0,     0,     0,
       0,    11,     1,     0,    12,    13,    14,    15,    16,    17,
       0,    18,    19,     0,    20,    21,     0,     0,    22,     2,
      23,     0,    24,     3,     4,     5,     6,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     0,     8,
       0,     9,     0,    10,     0,     0,     0,     0,    11,     0,
       0,    12,    13,    14,    15,    16,    17,     0,    18,    19,
       0,    20,    21,     0,     0,    22,     0,    23,     0,    24,
      58,    59,    60,    61,    62,    63,    64,     0,    65,    66,
      67,     0,     0,     0,     0,     0,    68,    69,    70,    71,
      72,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    73,    74,    75,     0,    76
};

static const yytype_int16 yycheck[] =
{
       2,    82,    23,    60,    61,    56,    60,    61,   205,   206,
      69,    70,    71,    72,    23,    69,    73,    49,    63,    23,
      24,    73,    25,    26,    27,    28,    29,    37,    63,    39,
       3,     4,     5,     6,     7,     8,     9,    10,    58,    60,
      61,    37,   101,    39,    24,    23,    56,    60,    61,    63,
      52,    60,    61,    85,    86,    87,    88,    89,    63,    36,
      56,    37,    32,    33,    34,    65,    68,    69,    70,    71,
      72,    41,    37,    73,    63,    77,    78,   128,   129,   130,
     131,    60,    61,    65,    36,   282,    59,    36,    67,    71,
      93,    94,    63,    66,    60,    61,    60,    61,    69,   101,
     297,    67,   299,    67,    63,   107,   187,   188,   305,   190,
      60,    61,   309,   145,   146,    65,   120,    63,   122,   123,
     124,   125,    43,    63,    65,    67,    65,    65,    65,   133,
     132,    65,    63,   135,    36,    65,    65,    65,    62,    62,
     120,    35,   122,   123,   124,   125,    62,    62,    65,    63,
      36,   155,    65,   133,   205,   352,   353,     3,     4,     5,
       6,     7,     8,     9,    10,    65,    65,   226,   170,    65,
      65,    26,    65,    65,    65,   155,   180,    65,    65,    63,
      23,   183,   184,   185,    62,    62,    71,    36,   385,   191,
     387,    72,   243,    63,    63,    71,   198,   199,   200,    63,
     180,    63,    26,    26,    47,    63,    65,    72,    51,    52,
      53,    54,    55,    59,    57,    58,    72,    65,    65,    36,
      66,    64,    97,    66,   226,    68,    65,    65,    65,    65,
      65,   282,   234,    65,   236,     3,     4,     5,     6,     7,
       8,     9,    10,    97,   327,    -1,    -1,   137,   329,    -1,
      -1,   253,   256,    -1,    -1,   257,   258,   259,   260,   261,
     262,   263,   264,   267,    -1,   269,    -1,    -1,    -1,   271,
     272,   273,    -1,    -1,    -1,   277,   256,    -1,    -1,   281,
      -1,    -1,   284,    -1,    -1,    -1,    -1,   267,    -1,   269,
      58,    -1,    -1,    -1,    -1,    63,    -1,    -1,   300,     3,
       4,     5,     6,     7,     8,     9,    10,    51,    52,    53,
      54,    55,    -1,    57,    58,    -1,    -1,    -1,    -1,    -1,
      -1,   323,    66,    -1,    68,    -1,   328,    -1,    -1,   331,
     332,    -1,    -1,   335,   336,    -1,    -1,   339,   340,    -1,
      -1,    -1,    -1,   345,    -1,    -1,   348,    -1,    -1,    -1,
      -1,    -1,   354,    -1,    58,    -1,   358,    -1,   360,   361,
      -1,   363,    -1,    -1,    -1,    -1,     0,    -1,    -1,    -1,
     372,    -1,   374,    -1,     8,     9,    10,    11,    12,    -1,
      -1,    -1,    -1,    -1,   386,    -1,    -1,    -1,    -1,    -1,
     392,    25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,
      47,   403,    -1,   405,    51,    52,    53,    54,    55,    -1,
      57,    58,    -1,    -1,    -1,    49,    -1,    64,    -1,    66,
      -1,    68,    -1,    -1,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    -1,    -1,    -1,    -1,    73,
      74,    75,    76,     3,     4,     5,     6,     7,     8,     9,
      10,    85,    86,    87,    88,    89,    -1,    91,    92,    93,
      94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     104,   105,   106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   133,
      -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   145,   146,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   155,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,
     164,   165,   166,   167,   168,   169,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,   182,   183,
      -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     194,    -1,   196,     0,     1,    -1,    -1,    -1,    -1,    -1,
     204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    -1,    -1,    -1,    22,    23,    24,    25,    -1,
      -1,    53,    54,    55,    -1,    57,    -1,    -1,    -1,    36,
      -1,    38,    -1,    40,    -1,    42,    -1,    -1,    -1,    -1,
      47,    -1,    -1,    50,    51,    52,    53,    54,    55,   253,
      57,    58,    -1,    60,    61,    -1,    -1,    64,    -1,    66,
      -1,    68,    -1,    -1,    -1,   269,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   278,   279,   280,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,    -1,   121,
      -1,    -1,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   144,    -1,    -1,    -1,    -1,   321,    -1,   323,
      -1,    -1,   326,    -1,   328,    -1,    -1,    -1,    -1,    -1,
     334,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     172,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   356,    -1,    -1,    -1,    -1,    -1,   362,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   370,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   207,   208,   209,   210,   211,
     212,   213,   214,    -1,    -1,   389,    -1,    -1,    -1,     1,
     394,    -1,   224,   225,    -1,    -1,    -1,   229,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,   239,   240,   241,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,    -1,
      42,    -1,    -1,    -1,    -1,    47,    -1,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    -1,    60,    61,
      -1,    -1,    64,    -1,    66,    -1,    68,    -1,    11,    12,
      13,    14,    15,    16,    17,    -1,    19,    20,    21,    -1,
     302,   303,    -1,    -1,    27,    28,    29,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    45,    46,    -1,    48,    49,    -1,    -1,     1,
      -1,    -1,    -1,    -1,    -1,    -1,   338,    -1,    -1,   341,
      -1,    -1,   344,    -1,   346,    -1,    18,    70,    -1,    -1,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,    -1,
      42,   373,    -1,    -1,    -1,    47,    -1,   379,    50,    51,
      52,    53,    54,    55,    56,    57,    58,     1,    60,    61,
      -1,    -1,    64,    -1,    66,    -1,    68,   399,    -1,   401,
      -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    37,    38,    -1,    40,    -1,    42,    -1,
      -1,    -1,    -1,    47,     1,    -1,    50,    51,    52,    53,
      54,    55,    -1,    57,    58,    -1,    60,    61,    -1,    -1,
      64,    18,    66,    -1,    68,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    -1,    40,    -1,    42,    -1,    -1,    -1,    -1,
      47,     1,    -1,    50,    51,    52,    53,    54,    55,    -1,
      57,    58,    -1,    60,    61,    -1,    -1,    64,    18,    66,
      -1,    68,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,    -1,
      40,    -1,    42,    -1,    -1,    -1,    -1,    47,     1,    -1,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    -1,
      60,    61,    -1,    -1,    64,    18,    66,    -1,    68,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    -1,    40,    -1,    42,
      -1,    -1,    -1,    -1,    47,     1,    -1,    50,    51,    52,
      53,    54,    55,    -1,    57,    58,    -1,    60,    61,    -1,
      -1,    64,    18,    66,    -1,    68,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    -1,    40,    -1,    42,    -1,    -1,    -1,
      -1,    47,     1,    -1,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    -1,    60,    61,    -1,    -1,    64,    18,
      66,    -1,    68,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    38,
      -1,    40,    -1,    42,    -1,    -1,    -1,    -1,    47,    -1,
      -1,    50,    51,    52,    53,    54,    55,    -1,    57,    58,
      -1,    60,    61,    -1,    -1,    64,    -1,    66,    -1,    68,
      11,    12,    13,    14,    15,    16,    17,    -1,    19,    20,
      21,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    -1,    48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    18,    22,    23,    24,    25,    36,    38,    40,
      42,    47,    50,    51,    52,    53,    54,    55,    57,    58,
      60,    61,    64,    66,    68,    75,    77,    80,    81,    83,
      84,    85,    86,    90,    91,    92,    93,    94,    98,   101,
     103,   104,   108,   109,   110,   111,   112,   113,   114,   115,
     101,   102,    63,   101,   101,   101,   101,   101,    11,    12,
      13,    14,    15,    16,    17,    19,    20,    21,    27,    28,
      29,    30,    31,    44,    45,    46,    48,    49,    70,    67,
     102,   106,   107,    69,   107,   115,   115,   115,   115,   115,
      37,    39,    56,    78,    79,    87,    88,    89,    73,     0,
     114,    63,   102,    64,   113,   113,   113,   103,   113,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   102,
     105,   106,   105,   105,   105,   105,   101,   101,   101,   101,
     102,   102,    23,    95,    98,    63,    96,    97,    37,    76,
      37,    37,    37,   101,   101,   115,   115,    37,    37,    87,
      88,    32,    33,    34,    41,   105,    63,   101,   101,   101,
     102,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   101,   106,   107,   113,   107,   107,   107,   107,
     113,   113,   103,   103,   103,   103,   102,   101,   106,   107,
     102,    23,   101,    69,    96,    36,   113,    37,    63,    63,
      63,   107,    36,    36,    43,    63,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   102,   113,   113,    65,    65,
      65,    65,    65,   107,   101,   101,   101,   102,   102,   101,
     102,    98,    98,    67,    98,   102,    23,   101,   101,   102,
     102,   102,    63,   101,     3,     4,     5,     6,     7,     8,
       9,    10,    63,    82,    99,   103,    99,   113,   113,   113,
     113,   113,   113,   113,   113,    65,    65,   113,   113,   105,
      65,    62,   113,    62,   102,   102,    36,   113,   113,   113,
     103,    62,   101,   102,    62,   107,   102,   102,   102,   102,
     102,   102,   102,   102,   107,    65,   107,   102,   102,   102,
      35,   102,   101,   101,   101,   102,    99,   103,    63,   102,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    59,    66,    99,    65,    71,    59,    66,    99,   102,
      63,   113,   113,    36,    99,    62,    62,    99,   101,    99,
     100,   101,   102,    26,   101,   100,   101,   102,    98,   102,
     102,   101,   102,   102,   113,   102,    67,   102,   113,    71,
      72,   113,    67,   113,    71,   102,    63,    63,    36,    99,
      99,   102,    63,   101,    63,   102,    26,   102,   102,   101,
     102,    26,    63,   101,    65,   102,   113,   102,    65,    72,
      65,    65,   113,    65,    72,    36,    99,   102,    99,   101,
     102,   101,    65,   113,    65,   113,   102,   102,    65,    65
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      82,    82,    82,    83,    83,    84,    85,    85,    86,    87,
      88,    89,    89,    90,    91,    92,    92,    92,    92,    93,
      94,    94,    95,    95,    95,    96,    97,    97,    97,    97,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    99,    99,    99,    99,    99,    99,    99,    99,   100,
     100,   101,   101,   102,   102,   103,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   105,   105,   105,   105,
     106,   107,   107,   108,   108,   108,   109,   109,   109,   109,
     109,   109,   109,   110,   110,   110,   110,   110,   110,   111,
     111,   111,   112,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   115,   115
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     5,     5,     3,     5,     9,     4,
       1,     6,     3,    11,    13,     3,     6,     8,     2,     2,
       2,     1,     2,     3,     3,     2,     3,     4,     3,     3,
       1,     1,     1,     3,     3,     9,     3,     2,     4,     3,
       1,     1,     1,     1,     1,     1,     1,     5,     2,     4,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       5,     1,     1,     1,     0,     1,    12,    12,    12,    12,
      14,    14,     8,    16,    16,    12,     2,     2,     3,     3,
       3,     1,     1,     1,     6,     4,     5,     5,     5,     5,
       5,     6,     8,     8,     8,     8,     8,     8,     8,     8,
       6,     8,     7,     1,     1,     8,     1,     1,     8,    10,
       1,    10,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     2
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
#line 128 "./parser/Parser.y"
                                      { i.EatAst(MakeStartAst()); }
#line 1828 "./parser/Parser.cpp"
    break;

  case 3:
#line 130 "./parser/Parser.y"
                                    { i.EatAst(MakeEndScopeAst()); }
#line 1834 "./parser/Parser.cpp"
    break;

  case 4:
#line 132 "./parser/Parser.y"
                                                            {
                                    i.EatAst(MakeIfDeclAst((yyvsp[-2].tmp_id)));
                                }
#line 1842 "./parser/Parser.cpp"
    break;

  case 5:
#line 136 "./parser/Parser.y"
                                                                 {
                                    i.EatAst(MakeElifDeclAst((yyvsp[-2].tmp_id)));
                                }
#line 1850 "./parser/Parser.cpp"
    break;

  case 6:
#line 140 "./parser/Parser.y"
                                                 {
                                    i.EatAst(MakeElseDeclAst());
                                }
#line 1858 "./parser/Parser.cpp"
    break;

  case 7:
#line 144 "./parser/Parser.y"
                                                               {
                                    i.EatAst(MakeWhileDeclAst((yyvsp[-2].tmp_id)));
                                }
#line 1866 "./parser/Parser.cpp"
    break;

  case 8:
#line 148 "./parser/Parser.y"
                                                                                      {
                                    i.EatAst(MakeNode(START_BLOCK_CMD));

                                    auto type = MakeDataTypeNode("int");
                                    auto val = MakeTermNode(0, INT_NODE_TYPE);
                                    auto make = MakeAssignAst((yyvsp[-2].tmp_id), type, val);
                                    i.EatAst(make);

                                    auto less = MakeLessCompAst((yyvsp[-2].tmp_id)->Copy(), (yyvsp[-6].tmp_id));
                                    auto while_ast = MakeWhileDeclAst(less);
                                    i.EatAst(while_ast);   
                                    (yyval.tmp_id) = (yyvsp[-2].tmp_id)->Copy();
                                }
#line 1884 "./parser/Parser.cpp"
    break;

  case 9:
#line 162 "./parser/Parser.y"
                                                    {
                                    auto param = MakeNode(FUNC_PARAM_CMD);
                                    param->AddToLeftNodes((yyvsp[-3].tmp_id));
                                    param->AddToRightNodes((yyvsp[0].tmp_id));
                                    auto list = new AstNode();
                                    list->AddToLeftNodes(param);
                                    (yyval.tmp_id) = list;

                                }
#line 1898 "./parser/Parser.cpp"
    break;

  case 10:
#line 171 "./parser/Parser.y"
                                        {
                                    auto param = MakeNode(FUNC_PARAM_CMD);
                                    param->AddToRightNodes((yyvsp[0].tmp_id));
                                    auto list = new AstNode();
                                    list->AddToLeftNodes(param);
                                    (yyval.tmp_id) = list;
                                }
#line 1910 "./parser/Parser.cpp"
    break;

  case 11:
#line 178 "./parser/Parser.y"
                                                                             {
                                    auto param = MakeNode(FUNC_PARAM_CMD);
                                    param->AddToLeftNodes((yyvsp[-3].tmp_id));
                                    param->AddToRightNodes((yyvsp[0].tmp_id));
                                    (yyvsp[-5].tmp_id)->AddToLeftNodes(param);
                                    (yyval.tmp_id) = (yyvsp[-5].tmp_id);
                                }
#line 1922 "./parser/Parser.cpp"
    break;

  case 12:
#line 185 "./parser/Parser.y"
                                                               {
                                    auto param = MakeNode(FUNC_PARAM_CMD);
                                    param->AddToRightNodes((yyvsp[0].tmp_id));
                                    (yyvsp[-2].tmp_id)->AddToLeftNodes(param);
                                    (yyval.tmp_id) = (yyvsp[-2].tmp_id);
                                }
#line 1933 "./parser/Parser.cpp"
    break;

  case 13:
#line 193 "./parser/Parser.y"
                                                                                            {
                                    (yyval.tmp_id) = MakeNode(MAKE_FUNC_CMD);
                                    (yyval.tmp_id)->AddToLeftNodes((yyvsp[-8].tmp_id));
                                    (yyval.tmp_id)->AddToRightNodes((yyvsp[-2].tmp_id));
                                    i.EatAst((yyval.tmp_id));
                                }
#line 1944 "./parser/Parser.cpp"
    break;

  case 14:
#line 199 "./parser/Parser.y"
                                                                                                               {
                                    (yyval.tmp_id) = MakeNode(MAKE_FUNC_CMD);
                                    (yyval.tmp_id)->AddToLeftNodes((yyvsp[-10].tmp_id));
                                    (yyval.tmp_id)->AddToMiddleNodes((yyvsp[-7].tmp_id));
                                    (yyval.tmp_id)->AddToRightNodes((yyvsp[-2].tmp_id));
                                    i.EatAst((yyval.tmp_id));
                                    (yyval.tmp_id) = nullptr;
                                }
#line 1957 "./parser/Parser.cpp"
    break;

  case 15:
#line 209 "./parser/Parser.y"
                                                     {
                                    auto node = MakeNode(FUNC_RETR_CMD);
                                    node->AddToLeftNodes((yyvsp[0].tmp_id));
                                    i.EatAst(node);
                                }
#line 1967 "./parser/Parser.cpp"
    break;

  case 16:
#line 215 "./parser/Parser.y"
                                                              {
                                    auto func_call = MakeNode(CALL_FUNC_CMD);
                                    func_call->AddToLeftNodes((yyvsp[-2].tmp_id));
                                    (yyval.tmp_id) = func_call;
                                }
#line 1977 "./parser/Parser.cpp"
    break;

  case 17:
#line 220 "./parser/Parser.y"
                                                                                      {
                                    auto func_call = MakeNode(CALL_FUNC_CMD);
                                    func_call->AddToLeftNodes((yyvsp[-4].tmp_id));
                                    auto end = (yyvsp[-2].tmp_id)->Extras();
                                    for(size_t iter = 0; iter < end; iter++) {
                                        func_call->AddToRightNodes((yyvsp[-2].tmp_id)->GetExtraNode(iter));
                                    }
                                    (yyval.tmp_id) = func_call;
                                }
#line 1991 "./parser/Parser.cpp"
    break;

  case 23:
#line 236 "./parser/Parser.y"
                                                   {
                                    i.EatAst(MakeEndCtrlScopeAst());
                                }
#line 1999 "./parser/Parser.cpp"
    break;

  case 24:
#line 240 "./parser/Parser.y"
                                                     {
                                    i.EatAst(MakeIncAst((yyvsp[-2].tmp_id)));
                                    i.EatAst(MakeEndCtrlScopeAst());
                                    i.EatAst(MakeEndScopeAst());  
                                }
#line 2009 "./parser/Parser.cpp"
    break;

  case 25:
#line 246 "./parser/Parser.y"
                                           {
                                    i.EatAst(MakeEndCtrlScopeAst());
                                }
#line 2017 "./parser/Parser.cpp"
    break;

  case 26:
#line 249 "./parser/Parser.y"
                                                         {
                                    i.EatAst(MakeEndCtrlScopeAst());
                                }
#line 2025 "./parser/Parser.cpp"
    break;

  case 27:
#line 252 "./parser/Parser.y"
                                                                  {
                                    i.EatAst(MakeEndCtrlScopeAst());
                                }
#line 2033 "./parser/Parser.cpp"
    break;

  case 28:
#line 255 "./parser/Parser.y"
                                                      {
                                    i.EatAst(MakeEndCtrlScopeAst());
                                }
#line 2041 "./parser/Parser.cpp"
    break;

  case 29:
#line 259 "./parser/Parser.y"
                                                      {
                                    auto node_type = i.MostRecentAst()->Type();
                                    (yyval.tmp_id) = nullptr;
                                    if (node_type != FUNC_RETR_CMD) {
                                        (yyval.tmp_id) = MakeNode(FUNC_RETR_CMD);
                                    }
                                }
#line 2053 "./parser/Parser.cpp"
    break;

  case 32:
#line 270 "./parser/Parser.y"
                                     { (yyval.tmp_id) = new AstNode(); (yyval.tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id)); }
#line 2059 "./parser/Parser.cpp"
    break;

  case 33:
#line 271 "./parser/Parser.y"
                                                          { (yyvsp[-2].tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id)); (yyval.tmp_id) = (yyvsp[-2].tmp_id); }
#line 2065 "./parser/Parser.cpp"
    break;

  case 34:
#line 272 "./parser/Parser.y"
                                                               {(yyvsp[-2].tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id)); (yyval.tmp_id) = (yyvsp[-2].tmp_id); }
#line 2071 "./parser/Parser.cpp"
    break;

  case 35:
#line 275 "./parser/Parser.y"
                                                                                                  {
                                    (yyval.tmp_id) = new AstNode();
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[-6].tmp_id));
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[-2].tmp_id));
                                }
#line 2081 "./parser/Parser.cpp"
    break;

  case 36:
#line 282 "./parser/Parser.y"
                                                               {
                                    (yyval.tmp_id) = new AstNode();
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[-2].tmp_id)->GetExtraNode());
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[-2].tmp_id)->GetExtraNode(1));
                                    (yyvsp[-2].tmp_id)->NullExtraNode(0);
                                    (yyvsp[-2].tmp_id)->NullExtraNode(1);
                                    delete (yyvsp[-2].tmp_id);
                                }
#line 2094 "./parser/Parser.cpp"
    break;

  case 37:
#line 290 "./parser/Parser.y"
                                                         {
                                    (yyval.tmp_id) = new AstNode();
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[-1].tmp_id)->GetExtraNode());
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[-1].tmp_id)->GetExtraNode(1));
                                    (yyvsp[-1].tmp_id)->NullExtraNode(0);
                                    (yyvsp[-1].tmp_id)->NullExtraNode(1);
                                    delete (yyvsp[-1].tmp_id);
                                }
#line 2107 "./parser/Parser.cpp"
    break;

  case 38:
#line 298 "./parser/Parser.y"
                                                                               {
                                    (yyvsp[-3].tmp_id)->SaveAsExtraNode((yyvsp[-2].tmp_id)->GetExtraNode());
                                    (yyvsp[-3].tmp_id)->SaveAsExtraNode((yyvsp[-2].tmp_id)->GetExtraNode(1));
                                    (yyvsp[-2].tmp_id)->NullExtraNode(0);
                                    (yyvsp[-2].tmp_id)->NullExtraNode(1);
                                    delete (yyvsp[-2].tmp_id);
                                    (yyval.tmp_id) = (yyvsp[-3].tmp_id);
                                }
#line 2120 "./parser/Parser.cpp"
    break;

  case 39:
#line 306 "./parser/Parser.y"
                                                                       {
                                    (yyvsp[-2].tmp_id)->SaveAsExtraNode((yyvsp[-1].tmp_id)->GetExtraNode());
                                    (yyvsp[-2].tmp_id)->SaveAsExtraNode((yyvsp[-1].tmp_id)->GetExtraNode(1));
                                    (yyvsp[-1].tmp_id)->NullExtraNode(0);
                                    (yyvsp[-1].tmp_id)->NullExtraNode(1);
                                    delete (yyvsp[-1].tmp_id);
                                    (yyval.tmp_id) = (yyvsp[-2].tmp_id);
                                }
#line 2133 "./parser/Parser.cpp"
    break;

  case 40:
#line 316 "./parser/Parser.y"
                                                { 
                                       (yyval.tmp_id) = MakeTermNode((yyvsp[0].data)->int_val, INT_NODE_TYPE);            
                                }
#line 2141 "./parser/Parser.cpp"
    break;

  case 41:
#line 319 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeTermNode((yyvsp[0].data)->dou_val, DOUBLE_NODE_TYPE);          
                                }
#line 2149 "./parser/Parser.cpp"
    break;

  case 42:
#line 322 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeTermNode((yyvsp[0].data)->flo_val, FLOAT_NODE_TYPE);            
                                }
#line 2157 "./parser/Parser.cpp"
    break;

  case 43:
#line 325 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeTermNode((string)(yyvsp[0].data)->str_val, STRING_NODE_TYPE);                   
                                }
#line 2165 "./parser/Parser.cpp"
    break;

  case 44:
#line 328 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeTermNode((yyvsp[0].data)->char_val, CHAR_NODE_TYPE);
                                }
#line 2173 "./parser/Parser.cpp"
    break;

  case 45:
#line 331 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeTermNode((yyvsp[0].data)->bol_val, BOOL_NODE_TYPE);
                                }
#line 2181 "./parser/Parser.cpp"
    break;

  case 46:
#line 334 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = (yyvsp[0].tmp_id);       
                                }
#line 2189 "./parser/Parser.cpp"
    break;

  case 47:
#line 337 "./parser/Parser.y"
                                                                           {
                                    (yyval.tmp_id) = MakeArrayTermAst((yyvsp[-2].tmp_id));
                                }
#line 2197 "./parser/Parser.cpp"
    break;

  case 48:
#line 340 "./parser/Parser.y"
                                          {
                                    (yyval.tmp_id) = MakeTermNode(0, ARRAY_NODE_TYPE);
                                }
#line 2205 "./parser/Parser.cpp"
    break;

  case 49:
#line 343 "./parser/Parser.y"
                                                               {
                                    (yyval.tmp_id) = MakeMapTermAst((yyvsp[-1].tmp_id));
                                }
#line 2213 "./parser/Parser.cpp"
    break;

  case 50:
#line 346 "./parser/Parser.y"
                                          {
                                    (yyval.tmp_id) = MakeTermNode(0, MAP_NODE_TYPE);
                                }
#line 2221 "./parser/Parser.cpp"
    break;

  case 51:
#line 351 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types); }
#line 2227 "./parser/Parser.cpp"
    break;

  case 52:
#line 352 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types); }
#line 2233 "./parser/Parser.cpp"
    break;

  case 53:
#line 353 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types); }
#line 2239 "./parser/Parser.cpp"
    break;

  case 54:
#line 354 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types); }
#line 2245 "./parser/Parser.cpp"
    break;

  case 55:
#line 355 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types); }
#line 2251 "./parser/Parser.cpp"
    break;

  case 56:
#line 356 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types); }
#line 2257 "./parser/Parser.cpp"
    break;

  case 57:
#line 357 "./parser/Parser.y"
                                       {
                                    (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types);
                                }
#line 2265 "./parser/Parser.cpp"
    break;

  case 58:
#line 360 "./parser/Parser.y"
                                      {
                                    (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types);
                                }
#line 2273 "./parser/Parser.cpp"
    break;

  case 59:
#line 365 "./parser/Parser.y"
                                                                            {
                                   (yyval.tmp_id) = (yyvsp[-4].tmp_id);
                                   (yyval.tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id));
                                }
#line 2282 "./parser/Parser.cpp"
    break;

  case 60:
#line 369 "./parser/Parser.y"
                                                                           {
                                    (yyval.tmp_id) = (yyvsp[-4].tmp_id);
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id));
                                }
#line 2291 "./parser/Parser.cpp"
    break;

  case 65:
#line 379 "./parser/Parser.y"
                                   {
                                    (yyval.tmp_id) = MakeTermNode((string)(yyvsp[0].data)->id, ID_NODE_TYPE);
                                }
#line 2299 "./parser/Parser.cpp"
    break;

  case 66:
#line 383 "./parser/Parser.y"
                                                                                                    {
                                    (yyval.tmp_id) = MakeAssignAst((yyvsp[-8].tmp_id), (yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2307 "./parser/Parser.cpp"
    break;

  case 67:
#line 386 "./parser/Parser.y"
                                                                                                   {
                                    (yyval.tmp_id) = MakeAssignAst((yyvsp[-8].tmp_id), (yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2315 "./parser/Parser.cpp"
    break;

  case 68:
#line 389 "./parser/Parser.y"
                                                                                                        {
                                    (yyval.tmp_id) = MakeUnionAst((yyvsp[-8].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2323 "./parser/Parser.cpp"
    break;

  case 69:
#line 392 "./parser/Parser.y"
                                                                                                     {
                                    (yyval.tmp_id) = MakeUnionAst((yyvsp[-8].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2331 "./parser/Parser.cpp"
    break;

  case 70:
#line 395 "./parser/Parser.y"
                                                                                                                   {
                                    (yyval.tmp_id) = MakeUnionAst((yyvsp[-10].tmp_id), (yyvsp[-5].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2339 "./parser/Parser.cpp"
    break;

  case 71:
#line 398 "./parser/Parser.y"
                                                                                                                {
                                    (yyval.tmp_id) = MakeUnionAst((yyvsp[-10].tmp_id), (yyvsp[-5].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2347 "./parser/Parser.cpp"
    break;

  case 72:
#line 401 "./parser/Parser.y"
                                                                           {
                                   (yyval.tmp_id) = MakeReassignAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2355 "./parser/Parser.cpp"
    break;

  case 73:
#line 404 "./parser/Parser.y"
                                                                                                                         {
                                    (yyval.tmp_id) = MakeRefAst((yyvsp[-12].tmp_id), (yyvsp[-8].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2363 "./parser/Parser.cpp"
    break;

  case 74:
#line 407 "./parser/Parser.y"
                                                                                                                      {
                                    (yyval.tmp_id) = MakeRefAst((yyvsp[-12].tmp_id), (yyvsp[-8].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2371 "./parser/Parser.cpp"
    break;

  case 75:
#line 410 "./parser/Parser.y"
                                                                                              {
                                    (yyval.tmp_id) = MakeRebindRefAst((yyvsp[-8].tmp_id), (yyvsp[-6].tmp_id));
                                }
#line 2379 "./parser/Parser.cpp"
    break;

  case 76:
#line 416 "./parser/Parser.y"
                                           {
                                    (yyval.tmp_id) = new AstNode();
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id));
                                }
#line 2388 "./parser/Parser.cpp"
    break;

  case 77:
#line 420 "./parser/Parser.y"
                                                   {
                                    (yyval.tmp_id) = new AstNode();
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id));
                                }
#line 2397 "./parser/Parser.cpp"
    break;

  case 78:
#line 424 "./parser/Parser.y"
                                                             {  
                                    (yyvsp[-2].tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id));
                                    (yyval.tmp_id) = (yyvsp[-2].tmp_id);
                                }
#line 2406 "./parser/Parser.cpp"
    break;

  case 79:
#line 428 "./parser/Parser.y"
                                                                  {
                                    (yyvsp[-2].tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id));
                                    (yyval.tmp_id) = (yyvsp[-2].tmp_id);
                                }
#line 2415 "./parser/Parser.cpp"
    break;

  case 84:
#line 438 "./parser/Parser.y"
                                                                            { 
                                    (yyval.tmp_id) = MakePrintAst((yyvsp[-2].tmp_id));
                                }
#line 2423 "./parser/Parser.cpp"
    break;

  case 85:
#line 441 "./parser/Parser.y"
                                                     { Destroy(); return 0; (yyval.tmp_id) = nullptr; }
#line 2429 "./parser/Parser.cpp"
    break;

  case 86:
#line 446 "./parser/Parser.y"
                                                                        {
                                    Perform((yyval.tmp_id), (yyvsp[-2].tmp_id), ADDITION_CMD);
                                }
#line 2437 "./parser/Parser.cpp"
    break;

  case 87:
#line 449 "./parser/Parser.y"
                                                                         {
                                    Perform((yyval.tmp_id), (yyvsp[-2].tmp_id), SUBTRACTION_CMD);
                                }
#line 2445 "./parser/Parser.cpp"
    break;

  case 88:
#line 452 "./parser/Parser.y"
                                                                          {
                                    Perform((yyval.tmp_id), (yyvsp[-2].tmp_id), MULTIPLY_CMD);
                                }
#line 2453 "./parser/Parser.cpp"
    break;

  case 89:
#line 455 "./parser/Parser.y"
                                                                          {
                                    Perform((yyval.tmp_id), (yyvsp[-2].tmp_id), DIVIDE_CMD);
                                }
#line 2461 "./parser/Parser.cpp"
    break;

  case 90:
#line 458 "./parser/Parser.y"
                                                                          {
                                    Perform((yyval.tmp_id), (yyvsp[-2].tmp_id), POW_CMD);
                                }
#line 2469 "./parser/Parser.cpp"
    break;

  case 91:
#line 461 "./parser/Parser.y"
                                                                        {
                                    (yyval.tmp_id) = MakeIncAst((yyvsp[-2].tmp_id));
                                }
#line 2477 "./parser/Parser.cpp"
    break;

  case 92:
#line 464 "./parser/Parser.y"
                                                                                                {
                                    (yyval.tmp_id) = MakeModAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2485 "./parser/Parser.cpp"
    break;

  case 93:
#line 472 "./parser/Parser.y"
                                                                                           {
                                    (yyval.tmp_id) = MakeLessCompAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2493 "./parser/Parser.cpp"
    break;

  case 94:
#line 475 "./parser/Parser.y"
                                                                                                {
                                    (yyval.tmp_id) = MakeGreaterCompAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2501 "./parser/Parser.cpp"
    break;

  case 95:
#line 478 "./parser/Parser.y"
                                                                                                  {
                                    (yyval.tmp_id) = MakeLessEqualCompAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2509 "./parser/Parser.cpp"
    break;

  case 96:
#line 481 "./parser/Parser.y"
                                                                                                      {
                                    (yyval.tmp_id) = MakeGreaterEqualCompAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2517 "./parser/Parser.cpp"
    break;

  case 97:
#line 484 "./parser/Parser.y"
                                                                                             {
                                    (yyval.tmp_id) = MakeEqualCompAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2525 "./parser/Parser.cpp"
    break;

  case 98:
#line 487 "./parser/Parser.y"
                                                                                                  {
                                    (yyval.tmp_id) = MakeNotEqualCompAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2533 "./parser/Parser.cpp"
    break;

  case 99:
#line 494 "./parser/Parser.y"
                                                                                         {
                                    (yyval.tmp_id) = MakeAndAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2541 "./parser/Parser.cpp"
    break;

  case 100:
#line 497 "./parser/Parser.y"
                                                                 {
                                    (yyval.tmp_id) = MakeNotAst((yyvsp[-2].tmp_id));
                                }
#line 2549 "./parser/Parser.cpp"
    break;

  case 101:
#line 500 "./parser/Parser.y"
                                                                                           {
                                    (yyval.tmp_id) = MakeOrAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2557 "./parser/Parser.cpp"
    break;

  case 102:
#line 506 "./parser/Parser.y"
                                                                  {
                                    (yyval.tmp_id) = MakeGetFromCollectionAst((yyvsp[-3].tmp_id), (yyvsp[-1].tmp_id));
                                }
#line 2565 "./parser/Parser.cpp"
    break;

  case 103:
#line 512 "./parser/Parser.y"
                                     {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2573 "./parser/Parser.cpp"
    break;

  case 104:
#line 515 "./parser/Parser.y"
                                            {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2581 "./parser/Parser.cpp"
    break;

  case 105:
#line 518 "./parser/Parser.y"
                                                                                          {
                                    (yyval.tmp_id) = MakeCastAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2589 "./parser/Parser.cpp"
    break;

  case 106:
#line 521 "./parser/Parser.y"
                                               {
                                   (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2597 "./parser/Parser.cpp"
    break;

  case 107:
#line 524 "./parser/Parser.y"
                                           {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2605 "./parser/Parser.cpp"
    break;

  case 108:
#line 527 "./parser/Parser.y"
                                                                                           {
                                     (yyval.tmp_id) = MakeAddToListAst((yyvsp[-7].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2613 "./parser/Parser.cpp"
    break;

  case 109:
#line 530 "./parser/Parser.y"
                                                                                                          {
                                    (yyval.tmp_id) = MakeAddToMapAst((yyvsp[-9].tmp_id), (yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2621 "./parser/Parser.cpp"
    break;

  case 110:
#line 533 "./parser/Parser.y"
                                                {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2629 "./parser/Parser.cpp"
    break;

  case 111:
#line 536 "./parser/Parser.y"
                                                                                                            {
                                    (yyval.tmp_id) = MakeSetInCollectionAst((yyvsp[-9].tmp_id), (yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2637 "./parser/Parser.cpp"
    break;

  case 112:
#line 539 "./parser/Parser.y"
                                                      {
                                    (yyval.tmp_id) = MakeCollectionSizeAst((yyvsp[-2].tmp_id));
                                }
#line 2645 "./parser/Parser.cpp"
    break;

  case 113:
#line 542 "./parser/Parser.y"
                                                        {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2653 "./parser/Parser.cpp"
    break;

  case 114:
#line 545 "./parser/Parser.y"
                                               { (yyval.tmp_id) = (yyvsp[0].tmp_id); }
#line 2659 "./parser/Parser.cpp"
    break;

  case 115:
#line 548 "./parser/Parser.y"
                                     { i.EatAst((yyvsp[0].tmp_id)); (yyvsp[0].tmp_id) = nullptr; }
#line 2665 "./parser/Parser.cpp"
    break;

  case 116:
#line 549 "./parser/Parser.y"
                                            { i.EatAst((yyvsp[0].tmp_id)); (yyvsp[0].tmp_id) = nullptr; }
#line 2671 "./parser/Parser.cpp"
    break;

  case 124:
#line 557 "./parser/Parser.y"
                                       {
                                    Destroy();
                                    return 0;
                                }
#line 2680 "./parser/Parser.cpp"
    break;

  case 125:
#line 561 "./parser/Parser.y"
                                        { return 0; }
#line 2686 "./parser/Parser.cpp"
    break;


#line 2690 "./parser/Parser.cpp"

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
#line 564 "./parser/Parser.y"



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
