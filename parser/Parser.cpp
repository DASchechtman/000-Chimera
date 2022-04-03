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
    FURO = 303,
    FUNC = 304,
    CALL = 305,
    ASSIGN = 306,
    FUNC_RET = 307,
    INT_VAL = 308,
    DOUBLE_VAL = 309,
    STRING_VAL = 310,
    CHAR_VAL = 311,
    BOOL_VAL = 312,
    ELSE_IF = 313,
    FLOAT_VAL = 314,
    ID = 315,
    UNKNOWN = 316,
    MULTI_WS = 317,
    SINGLE_WS = 318
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 34 "./parser/Parser.y"

    YYSTYPEs *data;
    AstNode *tmp_id;

#line 223 "./parser/Parser.cpp"

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
#define YYFINAL  102
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1230

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  76
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  132
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  417

#define YYUNDEFTOK  2
#define YYMAXUTOK   318


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
      66,    67,     2,     2,     2,     2,    75,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    64,     2,
      73,    72,    74,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    68,     2,    69,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    70,    65,    71,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   131,   131,   133,   135,   139,   143,   147,   151,   165,
     174,   181,   188,   196,   199,   202,   207,   214,   223,   230,
     241,   247,   252,   263,   264,   265,   266,   266,   268,   272,
     278,   281,   284,   287,   291,   296,   296,   298,   299,   300,
     303,   310,   318,   326,   334,   344,   347,   350,   353,   356,
     359,   362,   365,   368,   371,   374,   379,   380,   381,   382,
     383,   384,   385,   388,   393,   397,   403,   403,   405,   405,
     407,   411,   414,   417,   420,   423,   426,   429,   432,   435,
     438,   444,   448,   452,   456,   462,   463,   463,   465,   466,
     469,   474,   477,   480,   483,   486,   489,   492,   500,   503,
     506,   509,   512,   515,   522,   525,   528,   534,   540,   543,
     546,   549,   552,   555,   558,   561,   564,   567,   570,   573,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     589,   591,   591
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
  "SURO", "FURO", "FUNC", "CALL", "ASSIGN", "FUNC_RET", "INT_VAL",
  "DOUBLE_VAL", "STRING_VAL", "CHAR_VAL", "BOOL_VAL", "ELSE_IF",
  "FLOAT_VAL", "ID", "UNKNOWN", "MULTI_WS", "SINGLE_WS", "':'", "'|'",
  "'('", "')'", "'['", "']'", "'{'", "'}'", "'='", "'<'", "'>'", "'.'",
  "$accept", "start", "end", "ifHead", "elseIfHead", "elseHead",
  "whileHead", "forloopHead", "paramList", "funcType", "functionHead",
  "funcRet", "functionCall", "ifBody", "elseIfBody", "elseBody",
  "elseIfChain", "whileStatement", "forloopStatement", "ifStatement",
  "functionDeclStatement", "newline", "terms", "keyValPairs", "keyVals",
  "term", "types", "unionTypes", "any_ws", "opt_ws", "id", "assign",
  "exprList", "opt_newline", "opt_ws_or_nl", "statement", "math_expr",
  "compare_expr", "boolExpr", "indexAccessor", "expr", "prog", "line", YY_NULLPTR
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
     315,   316,   317,   318,    58,   124,    40,    41,    91,    93,
     123,   125,    61,    60,    62,    46
};
# endif

#define YYPACT_NINF (-206)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-69)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1120,  -206,     4,   -56,  -206,  -206,  -206,  -206,     4,     4,
       4,  -206,  -206,  -206,     4,  -206,  -206,  -206,  -206,  -206,
    -206,  -206,  -206,  -206,   576,    64,    42,  1120,  1120,  1120,
    1120,     4,  1120,  -206,  -206,   -20,  -206,  -206,  -206,  -206,
    -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,
     -44,  -206,   688,  -206,    17,     4,   345,   345,   345,   345,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,  -206,    25,  -206,    30,  -206,    27,   875,   766,   924,
     973,    39,  1022,  -206,     4,     4,  1120,  1120,  -206,    78,
     -19,    62,  -206,  -206,     4,    36,  1180,   -30,   -30,   -30,
     -44,   345,   345,   345,   345,   345,   345,   345,   345,   345,
     345,   258,     4,   345,     4,     4,     4,     4,   345,   345,
      39,    39,    39,    39,     4,     4,  -206,     4,    11,   -25,
    -206,  -206,  -206,  -206,     4,  -206,    80,   345,   826,  1071,
    -206,  -206,  -206,    82,    60,    63,    65,  -206,     4,  -206,
      98,   113,    93,   -30,   -30,   -30,   -30,   -30,   -30,   -30,
     -30,   -30,   -30,   -44,   345,   345,    83,   -44,    88,    91,
      97,   101,   -30,   -30,     4,     4,     4,     4,  -206,    30,
      30,   102,    30,     4,  -206,  -206,    13,    95,  -206,   -30,
    -206,     4,     4,     4,   104,  -206,  -206,     4,   201,   345,
     345,   345,   345,   345,   345,   345,   345,   105,   -44,   -44,
    -206,  -206,  -206,  -206,  -206,   106,   345,   345,   100,   107,
     111,   345,   112,  -206,  -206,  -206,     4,  -206,     4,  -206,
      52,   141,   345,   345,   345,  -206,    39,  -206,  -206,  -206,
    -206,  -206,  -206,  -206,  -206,     4,   -30,   -30,   -30,   -30,
     -30,   -30,   -30,   -30,  -206,  -206,   -30,   -59,     4,  -206,
       4,   -30,     4,   145,  -206,     1,     4,  -206,   117,  -206,
     -30,   -30,   -30,     4,   115,   120,   122,   123,   125,   126,
     127,   128,   129,   130,  -206,   131,    20,    41,   211,     4,
       4,   166,   234,   147,     4,   157,   345,   345,   187,  -206,
    -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,
       4,   201,     4,  -206,   198,     4,   201,     4,    30,   201,
    -206,  -206,   161,    77,   201,  -206,   -30,   -30,  -206,   345,
       4,    75,   345,   154,   155,   345,    90,   345,   158,     4,
       4,     4,     4,   192,  -206,   165,   167,   -30,   168,     4,
     170,   -30,   220,     4,   -30,     4,   -30,   221,   183,   213,
     201,   201,  -206,  -206,  -206,   185,     4,   345,     4,   186,
     176,   196,   199,   345,   200,   191,  -206,  -206,  -206,     4,
    -206,   201,   -30,   201,  -206,     4,  -206,  -206,   -30,  -206,
       4,   235,  -206,   206,  -206,   345,   208,   345,  -206,  -206,
     -30,  -206,   -30,   210,   215,  -206,  -206
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   130,    69,     0,    35,    36,   129,     2,     0,     0,
       0,    13,    14,    15,     0,    45,    46,    48,    49,    50,
      47,    70,    66,    67,     0,    69,    69,     0,     0,     0,
       0,     0,     0,   128,   119,     0,   123,   124,   122,   118,
     127,   108,   126,    51,    88,   121,   109,   111,   112,   115,
     120,   131,     0,    68,     0,    69,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      69,    69,    69,    69,    69,     0,     0,     0,     0,    69,
      69,    53,    86,    87,     0,    55,     0,     0,     0,     0,
       0,     0,     0,    30,     0,     0,     0,     0,    26,     0,
       0,     0,     1,   132,    69,     0,     0,     0,     0,     0,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    69,     0,    69,    69,    69,    69,     0,     0,
       0,     0,     0,     0,    69,    69,    37,    69,     0,     0,
       3,   125,    28,    29,    69,    34,     0,     0,     0,     0,
      33,    31,    27,     0,     0,     0,     0,   117,    69,    90,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    69,    81,    68,    87,     0,    82,     0,     0,
       0,     0,    69,     0,     0,    69,    69,    69,    85,    68,
      87,     0,     0,    69,    42,    54,     0,     0,     6,     0,
      32,    69,    69,    69,     0,     4,     7,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    83,    84,
      91,    92,    93,    94,    95,     0,     0,     0,    69,     0,
       0,    68,     0,    38,    39,    52,    69,    41,    69,    44,
       0,     0,     0,     0,     0,    89,     0,    56,    57,    58,
      59,    60,    61,    62,    63,    69,    69,    69,    69,    69,
      69,    69,    69,    69,   105,    96,    69,     0,    69,    21,
      69,    69,    69,     0,    43,     0,    69,    10,     0,     5,
      69,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   107,     0,     0,     0,     0,    69,
      69,     0,    68,     0,    69,     0,     0,     0,     0,   110,
      98,    99,   100,   101,   102,   103,   104,   106,    97,    22,
       0,     0,    69,    77,     0,     0,     0,    69,     0,     0,
      18,    12,     0,     0,     0,   113,    69,    69,     8,     0,
      69,    69,    68,     0,     0,     0,    69,    68,     0,    69,
       0,    69,    69,     0,     9,     0,     0,    69,     0,     0,
       0,    69,     0,    69,    69,     0,    69,     0,     0,     0,
       0,     0,    19,   114,   116,     0,    69,     0,    69,     0,
       0,     0,     0,     0,     0,     0,    40,    16,    11,     0,
      73,     0,    69,     0,    71,     0,    80,    74,    69,    72,
       0,     0,    64,     0,    65,     0,     0,     0,    17,    75,
      69,    76,    69,     0,     0,    78,    79
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,
    -206,  -206,  -206,  -206,   180,   184,  -206,  -206,  -206,  -206,
    -206,  -206,  -206,   144,  -206,   -83,  -205,   -41,   357,    -2,
     -89,  -206,   -67,    -4,    21,  -206,  -206,  -206,  -206,  -206,
     454,   -38,   -17
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    27,   141,    28,    96,    97,    29,    30,   276,    31,
      32,    33,    34,    35,    98,    99,   100,    36,    37,    38,
      39,    40,   135,   138,   139,    41,   340,   341,    53,    82,
      43,    44,   122,   123,    84,    45,    46,    47,    48,    49,
      50,    51,    52
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      54,   136,   144,   255,   124,   125,   126,   127,   294,    55,
      87,    88,    89,    90,   103,    92,   101,    93,   151,    94,
      94,    83,    83,   247,   248,   249,   250,   251,   252,   253,
     254,   101,    22,    23,   193,   277,   238,   158,    95,    95,
     137,   184,   185,   186,   187,   101,   195,    86,   134,   103,
     103,   103,   103,   105,   103,   247,   248,   249,   250,   251,
     252,   253,   254,    22,    23,   300,    22,    23,   121,   121,
     121,   121,   121,    22,    23,    22,    23,   132,   133,   148,
     149,   320,   104,    15,    16,    17,    18,    19,   321,    20,
      21,   322,   137,   327,   154,   155,   156,   331,    25,    21,
      26,   159,   121,   157,    22,    23,   233,   234,   323,   236,
     103,   103,    21,    85,   324,   150,   198,   275,   175,   200,
     175,   175,   175,   175,   350,   201,    22,    23,   202,   354,
     203,   190,   188,    81,   205,   192,   207,    22,    23,    22,
      23,   352,   197,   176,   359,   178,   179,   180,   181,   206,
     220,   278,    22,    23,   175,   221,   191,   283,   222,   365,
     240,   268,    22,    23,   223,   388,   389,   -68,   224,   245,
     217,   235,   264,   265,   269,   270,   272,   279,    83,   204,
     299,   304,   309,   229,   230,   232,   402,   310,   404,   311,
     312,   237,   313,   314,   315,   316,   317,   318,   319,   242,
     243,   244,   330,   225,   247,   248,   249,   250,   251,   252,
     253,   254,   333,   332,   247,   248,   249,   250,   251,   252,
     253,   254,   335,   338,   344,   351,   121,   362,   372,   363,
     373,   367,   374,   376,   273,   378,   274,   247,   248,   249,
     250,   251,   252,   253,   254,   349,   380,   385,   386,   387,
     395,    83,   390,   394,   285,   286,   287,   288,   289,   290,
     291,   292,    83,   396,   175,   400,   397,   399,   296,   297,
     298,   408,   325,   409,   303,   411,   284,   415,   305,   326,
     152,   134,   416,   196,   153,   346,     0,   293,     0,   295,
       0,     0,     0,     0,    21,     0,     0,   328,   329,     0,
       0,     0,   334,     0,     0,    11,    12,    13,     0,     0,
       0,    15,    16,    17,    18,    19,     0,    20,    21,     0,
     343,     0,     0,     0,   106,   348,    25,     0,    26,     0,
       0,     0,     0,     0,   355,   356,     0,     0,   358,   360,
       0,     0,     0,     0,   360,     0,     0,   368,     0,   370,
     371,     0,     0,     0,     0,   375,     0,    42,     0,   379,
       0,   381,   382,     0,   384,    56,    57,    58,     0,     0,
       0,    59,     0,     0,   391,     0,   393,     0,     0,     0,
       0,     0,     0,     0,    42,    42,    42,    42,    91,    42,
     403,     0,    11,    12,    13,     0,   406,     0,    15,    16,
      17,    18,    19,     0,    20,    21,     0,     0,   413,    42,
     414,   106,     0,    25,     0,    26,     0,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,     0,     0,     0,
       0,     0,   128,   129,   130,   131,     0,     0,     0,     0,
       0,     0,     0,     0,    42,    42,    42,    42,     0,    42,
       0,   146,   147,    42,    42,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   160,   161,   162,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   174,
       0,   174,   174,   174,   174,     0,     0,     0,     0,     0,
       0,     0,   189,     0,     0,   194,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    42,    42,     0,     0,     0,
     107,   108,   109,   110,     0,   174,     0,     0,     0,     0,
     208,   209,   210,   211,   212,   213,   214,   215,   216,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     226,   227,   228,     0,   231,     0,     0,     0,     0,     0,
       0,     0,     0,   239,     0,     0,   241,     0,     0,     0,
       0,     0,     0,     0,   246,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,     0,   177,     0,     0,
       0,     0,   182,   183,     0,     0,     0,    60,    61,    62,
      63,    64,    65,    66,     0,    67,    68,    69,     0,     0,
       0,   199,     0,    70,    71,    72,    73,    74,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      75,    76,    77,     0,     0,   174,    78,    79,   218,   219,
       0,     0,   301,   302,     0,     0,     0,     0,   306,   307,
     308,     0,     0,     0,     0,     0,     0,     0,    80,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   256,   257,   258,   259,   260,   261,   262,
     263,     0,     0,     0,     0,     0,     0,   339,     0,   342,
     266,   267,   345,     0,   347,   271,     0,     0,   102,     1,
     353,     0,     0,     0,     0,     0,   280,   281,   282,     0,
       0,     0,     0,     0,     0,     0,     2,   369,     0,     0,
       3,     4,     5,     6,     0,     0,   377,     0,     0,     0,
       0,     0,   383,     0,     7,     0,     8,     0,     9,     0,
      10,     0,     0,     0,     0,    11,    12,    13,     0,     0,
      14,    15,    16,    17,    18,    19,   401,    20,    21,     0,
      22,    23,   405,     0,    24,     0,    25,   407,    26,     0,
     336,   337,     0,     0,     0,     0,     0,     1,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     0,     0,     0,     3,     4,
       5,     6,     0,   357,     0,     0,   361,     0,     0,   364,
       0,   366,     7,   -23,     8,   -23,     9,     0,    10,     0,
       0,     0,     0,    11,    12,    13,     0,     0,    14,    15,
      16,    17,    18,    19,   -23,    20,    21,     1,    22,    23,
       0,   392,    24,     0,    25,     0,    26,   398,     0,     0,
       0,     0,     0,     0,     2,     0,     0,     0,     3,     4,
       5,     6,     0,     0,     0,     0,     0,     0,     0,   410,
       0,   412,     7,   -24,     8,   -24,     9,     0,    10,     0,
       0,     0,     0,    11,    12,    13,     1,     0,    14,    15,
      16,    17,    18,    19,   -24,    20,    21,     0,    22,    23,
       0,     0,    24,     2,    25,     0,    26,     3,     4,     5,
       6,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,   140,     8,     0,     9,     0,    10,     0,     0,
       0,     0,    11,    12,    13,     1,     0,    14,    15,    16,
      17,    18,    19,     0,    20,    21,     0,    22,    23,     0,
       0,    24,     2,    25,     0,    26,     3,     4,     5,     6,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,   142,     8,     0,     9,     0,    10,     0,     0,     0,
       0,    11,    12,    13,     1,     0,    14,    15,    16,    17,
      18,    19,     0,    20,    21,     0,    22,    23,     0,     0,
      24,     2,    25,     0,    26,     3,     4,     5,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
     143,     8,     0,     9,     0,    10,     0,     0,     0,     0,
      11,    12,    13,     1,     0,    14,    15,    16,    17,    18,
      19,     0,    20,    21,     0,    22,    23,     0,     0,    24,
       2,    25,     0,    26,     3,     4,     5,     6,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,   145,
       8,     0,     9,     0,    10,     0,     0,     0,     0,    11,
      12,    13,     1,     0,    14,    15,    16,    17,    18,    19,
       0,    20,    21,     0,    22,    23,     0,     0,    24,     2,
      25,     0,    26,     3,     4,     5,     6,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,   -25,     8,
       0,     9,     0,    10,     0,     0,     0,     0,    11,    12,
      13,     1,     0,    14,    15,    16,    17,    18,    19,     0,
      20,    21,     0,    22,    23,     0,     0,    24,     2,    25,
       0,    26,     3,     4,     5,     6,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,     0,     8,     0,
       9,     0,    10,     0,     0,     0,     0,    11,    12,    13,
       0,     0,    14,    15,    16,    17,    18,    19,     0,    20,
      21,     0,    22,    23,     0,     0,    24,     0,    25,     0,
      26,    60,    61,    62,    63,    64,    65,    66,     0,    67,
      68,    69,     0,     0,     0,     0,     0,    70,    71,    72,
      73,    74,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    75,    76,    77,     0,     0,     0,
      78
};

static const yytype_int16 yycheck[] =
{
       2,    84,    91,   208,    71,    72,    73,    74,    67,    65,
      27,    28,    29,    30,    52,    32,    75,    37,    37,    39,
      39,    25,    26,     3,     4,     5,     6,     7,     8,     9,
      10,    75,    62,    63,    23,   240,    23,   104,    58,    58,
      65,   130,   131,   132,   133,    75,    71,    26,    23,    87,
      88,    89,    90,    55,    92,     3,     4,     5,     6,     7,
       8,     9,    10,    62,    63,    64,    62,    63,    70,    71,
      72,    73,    74,    62,    63,    62,    63,    79,    80,    96,
      97,    61,    65,    53,    54,    55,    56,    57,    68,    59,
      60,   296,    65,   298,    32,    33,    34,   302,    68,    60,
      70,    65,   104,    41,    62,    63,   189,   190,    67,   192,
     148,   149,    60,    71,    73,    37,    36,    65,   122,    37,
     124,   125,   126,   127,   329,    65,    62,    63,    65,   334,
      65,   135,   134,    69,    36,   137,    43,    62,    63,    62,
      63,    64,   144,   122,    69,   124,   125,   126,   127,    36,
      67,   240,    62,    63,   158,    67,   135,   246,    67,    69,
      65,   228,    62,    63,    67,   370,   371,    67,    67,    65,
     172,    69,    67,    67,    67,    64,    64,    36,   182,   158,
      35,    64,    67,   185,   186,   187,   391,    67,   393,    67,
      67,   193,    67,    67,    67,    67,    67,    67,    67,   201,
     202,   203,    36,   182,     3,     4,     5,     6,     7,     8,
       9,    10,    65,   302,     3,     4,     5,     6,     7,     8,
       9,    10,    65,    36,    26,    64,   228,    73,    36,    74,
      65,    73,    65,    65,   236,    65,   238,     3,     4,     5,
       6,     7,     8,     9,    10,   328,    26,    26,    65,    36,
      74,   255,    67,    67,   256,   257,   258,   259,   260,   261,
     262,   263,   266,    67,   268,    74,    67,    67,   270,   271,
     272,    36,    61,    67,   276,    67,   255,    67,   280,    68,
     100,    23,    67,   139,   100,   326,    -1,   266,    -1,   268,
      -1,    -1,    -1,    -1,    60,    -1,    -1,   299,   300,    -1,
      -1,    -1,   304,    -1,    -1,    47,    48,    49,    -1,    -1,
      -1,    53,    54,    55,    56,    57,    -1,    59,    60,    -1,
     322,    -1,    -1,    -1,    66,   327,    68,    -1,    70,    -1,
      -1,    -1,    -1,    -1,   336,   337,    -1,    -1,   340,   341,
      -1,    -1,    -1,    -1,   346,    -1,    -1,   349,    -1,   351,
     352,    -1,    -1,    -1,    -1,   357,    -1,     0,    -1,   361,
      -1,   363,   364,    -1,   366,     8,     9,    10,    -1,    -1,
      -1,    14,    -1,    -1,   376,    -1,   378,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
     392,    -1,    47,    48,    49,    -1,   398,    -1,    53,    54,
      55,    56,    57,    -1,    59,    60,    -1,    -1,   410,    52,
     412,    66,    -1,    68,    -1,    70,    -1,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,
      -1,    -1,    75,    76,    77,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    88,    89,    90,    -1,    92,
      -1,    94,    95,    96,    97,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,
      -1,   124,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   135,    -1,    -1,   138,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   148,   149,    -1,    -1,    -1,
      56,    57,    58,    59,    -1,   158,    -1,    -1,    -1,    -1,
     163,   164,   165,   166,   167,   168,   169,   170,   171,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     183,   184,   185,    -1,   187,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   196,    -1,    -1,   199,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   207,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,    -1,   123,    -1,    -1,
      -1,    -1,   128,   129,    -1,    -1,    -1,    11,    12,    13,
      14,    15,    16,    17,    -1,    19,    20,    21,    -1,    -1,
      -1,   147,    -1,    27,    28,    29,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    -1,    -1,   268,    50,    51,   174,   175,
      -1,    -1,   275,   276,    -1,    -1,    -1,    -1,   281,   282,
     283,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   209,   210,   211,   212,   213,   214,   215,
     216,    -1,    -1,    -1,    -1,    -1,    -1,   320,    -1,   322,
     226,   227,   325,    -1,   327,   231,    -1,    -1,     0,     1,
     333,    -1,    -1,    -1,    -1,    -1,   242,   243,   244,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,   350,    -1,    -1,
      22,    23,    24,    25,    -1,    -1,   359,    -1,    -1,    -1,
      -1,    -1,   365,    -1,    36,    -1,    38,    -1,    40,    -1,
      42,    -1,    -1,    -1,    -1,    47,    48,    49,    -1,    -1,
      52,    53,    54,    55,    56,    57,   389,    59,    60,    -1,
      62,    63,   395,    -1,    66,    -1,    68,   400,    70,    -1,
     306,   307,    -1,    -1,    -1,    -1,    -1,     1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,    22,    23,
      24,    25,    -1,   339,    -1,    -1,   342,    -1,    -1,   345,
      -1,   347,    36,    37,    38,    39,    40,    -1,    42,    -1,
      -1,    -1,    -1,    47,    48,    49,    -1,    -1,    52,    53,
      54,    55,    56,    57,    58,    59,    60,     1,    62,    63,
      -1,   377,    66,    -1,    68,    -1,    70,   383,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   405,
      -1,   407,    36,    37,    38,    39,    40,    -1,    42,    -1,
      -1,    -1,    -1,    47,    48,    49,     1,    -1,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    -1,    62,    63,
      -1,    -1,    66,    18,    68,    -1,    70,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    37,    38,    -1,    40,    -1,    42,    -1,    -1,
      -1,    -1,    47,    48,    49,     1,    -1,    52,    53,    54,
      55,    56,    57,    -1,    59,    60,    -1,    62,    63,    -1,
      -1,    66,    18,    68,    -1,    70,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    37,    38,    -1,    40,    -1,    42,    -1,    -1,    -1,
      -1,    47,    48,    49,     1,    -1,    52,    53,    54,    55,
      56,    57,    -1,    59,    60,    -1,    62,    63,    -1,    -1,
      66,    18,    68,    -1,    70,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    -1,    40,    -1,    42,    -1,    -1,    -1,    -1,
      47,    48,    49,     1,    -1,    52,    53,    54,    55,    56,
      57,    -1,    59,    60,    -1,    62,    63,    -1,    -1,    66,
      18,    68,    -1,    70,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38,    -1,    40,    -1,    42,    -1,    -1,    -1,    -1,    47,
      48,    49,     1,    -1,    52,    53,    54,    55,    56,    57,
      -1,    59,    60,    -1,    62,    63,    -1,    -1,    66,    18,
      68,    -1,    70,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      -1,    40,    -1,    42,    -1,    -1,    -1,    -1,    47,    48,
      49,     1,    -1,    52,    53,    54,    55,    56,    57,    -1,
      59,    60,    -1,    62,    63,    -1,    -1,    66,    18,    68,
      -1,    70,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    38,    -1,
      40,    -1,    42,    -1,    -1,    -1,    -1,    47,    48,    49,
      -1,    -1,    52,    53,    54,    55,    56,    57,    -1,    59,
      60,    -1,    62,    63,    -1,    -1,    66,    -1,    68,    -1,
      70,    11,    12,    13,    14,    15,    16,    17,    -1,    19,
      20,    21,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    -1,    -1,    -1,
      50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    18,    22,    23,    24,    25,    36,    38,    40,
      42,    47,    48,    49,    52,    53,    54,    55,    56,    57,
      59,    60,    62,    63,    66,    68,    70,    77,    79,    82,
      83,    85,    86,    87,    88,    89,    93,    94,    95,    96,
      97,   101,   104,   106,   107,   111,   112,   113,   114,   115,
     116,   117,   118,   104,   105,    65,   104,   104,   104,   104,
      11,    12,    13,    14,    15,    16,    17,    19,    20,    21,
      27,    28,    29,    30,    31,    44,    45,    46,    50,    51,
      72,    69,   105,   109,   110,    71,   110,   118,   118,   118,
     118,   104,   118,    37,    39,    58,    80,    81,    90,    91,
      92,    75,     0,   117,    65,   105,    66,   116,   116,   116,
     116,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   105,   108,   109,   108,   108,   108,   108,   104,   104,
     104,   104,   105,   105,    23,    98,   101,    65,    99,   100,
      37,    78,    37,    37,   106,    37,   104,   104,   118,   118,
      37,    37,    90,    91,    32,    33,    34,    41,   108,    65,
     104,   104,   104,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   104,   109,   110,   116,   110,   110,
     110,   110,   116,   116,   106,   106,   106,   106,   105,   104,
     109,   110,   105,    23,   104,    71,    99,   105,    36,   116,
      37,    65,    65,    65,   110,    36,    36,    43,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   105,   116,   116,
      67,    67,    67,    67,    67,   110,   104,   104,   104,   105,
     105,   104,   105,   101,   101,    69,   101,   105,    23,   104,
      65,   104,   105,   105,   105,    65,   104,     3,     4,     5,
       6,     7,     8,     9,    10,   102,   116,   116,   116,   116,
     116,   116,   116,   116,    67,    67,   116,   116,   108,    67,
      64,   116,    64,   105,   105,    65,    84,   102,   106,    36,
     116,   116,   116,   106,   110,   105,   105,   105,   105,   105,
     105,   105,   105,   110,    67,   110,   105,   105,   105,    35,
      64,   104,   104,   105,    64,   105,   104,   104,   104,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      61,    68,   102,    67,    73,    61,    68,   102,   105,   105,
      36,   102,   106,    65,   105,    65,   116,   116,    36,   104,
     102,   103,   104,   105,    26,   104,   103,   104,   105,   101,
     102,    64,    64,   104,   102,   105,   105,   116,   105,    69,
     105,   116,    73,    74,   116,    69,   116,    73,   105,   104,
     105,   105,    36,    65,    65,   105,    65,   104,    65,   105,
      26,   105,   105,   104,   105,    26,    65,    36,   102,   102,
      67,   105,   116,   105,    67,    74,    67,    67,   116,    67,
      74,   104,   102,   105,   102,   104,   105,   104,    36,    67,
     116,    67,   116,   105,   105,    67,    67
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      84,    84,    84,    85,    85,    85,    86,    86,    86,    86,
      87,    88,    88,    89,    90,    91,    92,    92,    93,    94,
      95,    95,    95,    95,    96,    97,    97,    98,    98,    98,
      99,   100,   100,   100,   100,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   102,   102,   102,   102,
     102,   102,   102,   102,   103,   103,   104,   104,   105,   105,
     106,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   108,   108,   108,   108,   109,   110,   110,   111,   111,
     111,   112,   112,   112,   112,   112,   112,   112,   113,   113,
     113,   113,   113,   113,   114,   114,   114,   115,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   118,   118
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     5,     5,     3,     5,     9,     4,
       1,     6,     3,     1,     1,     1,    11,    13,     8,    10,
       3,     6,     8,     2,     2,     2,     1,     2,     3,     3,
       2,     3,     4,     3,     3,     1,     1,     1,     3,     3,
       9,     3,     2,     4,     3,     1,     1,     1,     1,     1,
       1,     1,     5,     2,     4,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     5,     1,     1,     1,     0,
       1,    12,    12,    12,    12,    14,    14,     8,    16,    16,
      12,     2,     2,     3,     3,     3,     1,     1,     1,     6,
       4,     5,     5,     5,     5,     5,     6,     8,     8,     8,
       8,     8,     8,     8,     8,     6,     8,     7,     1,     1,
       8,     1,     1,     8,    10,     1,    10,     3,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     2
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
#line 131 "./parser/Parser.y"
                                      { i.EatAst(MakeStartAst()); }
#line 1830 "./parser/Parser.cpp"
    break;

  case 3:
#line 133 "./parser/Parser.y"
                                    { i.EatAst(MakeEndScopeAst()); }
#line 1836 "./parser/Parser.cpp"
    break;

  case 4:
#line 135 "./parser/Parser.y"
                                                            {
                                    i.EatAst(MakeIfDeclAst((yyvsp[-2].tmp_id)));
                                }
#line 1844 "./parser/Parser.cpp"
    break;

  case 5:
#line 139 "./parser/Parser.y"
                                                                 {
                                    i.EatAst(MakeElifDeclAst((yyvsp[-2].tmp_id)));
                                }
#line 1852 "./parser/Parser.cpp"
    break;

  case 6:
#line 143 "./parser/Parser.y"
                                                 {
                                    i.EatAst(MakeElseDeclAst());
                                }
#line 1860 "./parser/Parser.cpp"
    break;

  case 7:
#line 147 "./parser/Parser.y"
                                                               {
                                    i.EatAst(MakeWhileDeclAst((yyvsp[-2].tmp_id)));
                                }
#line 1868 "./parser/Parser.cpp"
    break;

  case 8:
#line 151 "./parser/Parser.y"
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
#line 1886 "./parser/Parser.cpp"
    break;

  case 9:
#line 165 "./parser/Parser.y"
                                                    {
                                    auto param = MakeNode(FUNC_PARAM_CMD);
                                    param->AddToLeftNodes((yyvsp[-3].tmp_id));
                                    param->AddToRightNodes((yyvsp[0].tmp_id));
                                    auto list = new AstNode();
                                    list->AddToLeftNodes(param);
                                    (yyval.tmp_id) = list;

                                }
#line 1900 "./parser/Parser.cpp"
    break;

  case 10:
#line 174 "./parser/Parser.y"
                                        {
                                    auto param = MakeNode(FUNC_PARAM_CMD);
                                    param->AddToRightNodes((yyvsp[0].tmp_id));
                                    auto list = new AstNode();
                                    list->AddToLeftNodes(param);
                                    (yyval.tmp_id) = list;
                                }
#line 1912 "./parser/Parser.cpp"
    break;

  case 11:
#line 181 "./parser/Parser.y"
                                                                             {
                                    auto param = MakeNode(FUNC_PARAM_CMD);
                                    param->AddToLeftNodes((yyvsp[-3].tmp_id));
                                    param->AddToRightNodes((yyvsp[0].tmp_id));
                                    (yyvsp[-5].tmp_id)->AddToLeftNodes(param);
                                    (yyval.tmp_id) = (yyvsp[-5].tmp_id);
                                }
#line 1924 "./parser/Parser.cpp"
    break;

  case 12:
#line 188 "./parser/Parser.y"
                                                               {
                                    auto param = MakeNode(FUNC_PARAM_CMD);
                                    param->AddToRightNodes((yyvsp[0].tmp_id));
                                    (yyvsp[-2].tmp_id)->AddToLeftNodes(param);
                                    (yyval.tmp_id) = (yyvsp[-2].tmp_id);
                                }
#line 1935 "./parser/Parser.cpp"
    break;

  case 13:
#line 196 "./parser/Parser.y"
                                     {
                                    (yyval.tmp_id) = MakeNode(FUNC_SURO_TYPE);
                                }
#line 1943 "./parser/Parser.cpp"
    break;

  case 14:
#line 199 "./parser/Parser.y"
                                       {
                                    (yyval.tmp_id) = MakeNode(FUNC_FURO_TYPE);
                                }
#line 1951 "./parser/Parser.cpp"
    break;

  case 15:
#line 202 "./parser/Parser.y"
                                       {
                                    (yyval.tmp_id) = MakeNode(FUNC_FUNC_TYPE);
                                }
#line 1959 "./parser/Parser.cpp"
    break;

  case 16:
#line 207 "./parser/Parser.y"
                                                                                                {
                                    (yyval.tmp_id) = MakeNode(MAKE_FUNC_CMD);
                                    (yyval.tmp_id)->AddToLeftNodes((yyvsp[-8].tmp_id));
                                    (yyval.tmp_id)->AddToLeftNodes((yyvsp[-10].tmp_id));
                                    (yyval.tmp_id)->AddToRightNodes((yyvsp[-2].tmp_id));
                                    i.EatAst((yyval.tmp_id));
                                }
#line 1971 "./parser/Parser.cpp"
    break;

  case 17:
#line 214 "./parser/Parser.y"
                                                                                                                   {
                                    (yyval.tmp_id) = MakeNode(MAKE_FUNC_CMD);
                                    (yyval.tmp_id)->AddToLeftNodes((yyvsp[-10].tmp_id));
                                    (yyval.tmp_id)->AddToLeftNodes((yyvsp[-12].tmp_id));
                                    (yyval.tmp_id)->AddToMiddleNodes((yyvsp[-7].tmp_id));
                                    (yyval.tmp_id)->AddToRightNodes((yyvsp[-2].tmp_id));
                                    i.EatAst((yyval.tmp_id));
                                    (yyval.tmp_id) = nullptr;
                                }
#line 1985 "./parser/Parser.cpp"
    break;

  case 18:
#line 223 "./parser/Parser.y"
                                                                                 {
                                    (yyval.tmp_id) = MakeNode(MAKE_FUNC_CMD);
                                    (yyval.tmp_id)->AddToLeftNodes((yyvsp[-5].tmp_id));
                                    (yyval.tmp_id)->AddToLeftNodes((yyvsp[-7].tmp_id));
                                    (yyval.tmp_id)->AddToRightNodes(MakeDataTypeNode("int"));
                                    i.EatAst((yyval.tmp_id));
                                }
#line 1997 "./parser/Parser.cpp"
    break;

  case 19:
#line 230 "./parser/Parser.y"
                                                                                                  {
                                    (yyval.tmp_id) = MakeNode(MAKE_FUNC_CMD);
                                    (yyval.tmp_id)->AddToLeftNodes((yyvsp[-7].tmp_id));
                                    (yyval.tmp_id)->AddToLeftNodes((yyvsp[-9].tmp_id));
                                    (yyval.tmp_id)->AddToMiddleNodes((yyvsp[-4].tmp_id));
                                    (yyval.tmp_id)->AddToRightNodes(MakeDataTypeNode("int"));
                                    i.EatAst((yyval.tmp_id));
                                    (yyval.tmp_id) = nullptr;
                                }
#line 2011 "./parser/Parser.cpp"
    break;

  case 20:
#line 241 "./parser/Parser.y"
                                                     {
                                    auto node = MakeNode(FUNC_RETR_CMD);
                                    node->AddToLeftNodes((yyvsp[0].tmp_id));
                                    i.EatAst(node);
                                }
#line 2021 "./parser/Parser.cpp"
    break;

  case 21:
#line 247 "./parser/Parser.y"
                                                              {
                                    auto func_call = MakeNode(CALL_FUNC_CMD);
                                    func_call->AddToLeftNodes((yyvsp[-2].tmp_id));
                                    (yyval.tmp_id) = func_call;
                                }
#line 2031 "./parser/Parser.cpp"
    break;

  case 22:
#line 252 "./parser/Parser.y"
                                                                                      {
                                    auto func_call = MakeNode(CALL_FUNC_CMD);
                                    func_call->AddToLeftNodes((yyvsp[-4].tmp_id));
                                    auto end = (yyvsp[-2].tmp_id)->Extras();
                                    for(size_t iter = 0; iter < end; iter++) {
                                        func_call->AddToRightNodes((yyvsp[-2].tmp_id)->GetExtraNode(iter));
                                    }
                                    (yyval.tmp_id) = func_call;
                                }
#line 2045 "./parser/Parser.cpp"
    break;

  case 28:
#line 268 "./parser/Parser.y"
                                                   {
                                    i.EatAst(MakeEndCtrlScopeAst());
                                }
#line 2053 "./parser/Parser.cpp"
    break;

  case 29:
#line 272 "./parser/Parser.y"
                                                     {
                                    i.EatAst(MakeIncAst((yyvsp[-2].tmp_id)));
                                    i.EatAst(MakeEndCtrlScopeAst());
                                    i.EatAst(MakeEndScopeAst());  
                                }
#line 2063 "./parser/Parser.cpp"
    break;

  case 30:
#line 278 "./parser/Parser.y"
                                           {
                                    i.EatAst(MakeEndCtrlScopeAst());
                                }
#line 2071 "./parser/Parser.cpp"
    break;

  case 31:
#line 281 "./parser/Parser.y"
                                                         {
                                    i.EatAst(MakeEndCtrlScopeAst());
                                }
#line 2079 "./parser/Parser.cpp"
    break;

  case 32:
#line 284 "./parser/Parser.y"
                                                                  {
                                    i.EatAst(MakeEndCtrlScopeAst());
                                }
#line 2087 "./parser/Parser.cpp"
    break;

  case 33:
#line 287 "./parser/Parser.y"
                                                      {
                                    i.EatAst(MakeEndCtrlScopeAst());
                                }
#line 2095 "./parser/Parser.cpp"
    break;

  case 34:
#line 291 "./parser/Parser.y"
                                                      {
                                    (yyval.tmp_id) = MakeNode(FUNC_END_CMD);
                                }
#line 2103 "./parser/Parser.cpp"
    break;

  case 37:
#line 298 "./parser/Parser.y"
                                     { (yyval.tmp_id) = new AstNode(); (yyval.tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id)); }
#line 2109 "./parser/Parser.cpp"
    break;

  case 38:
#line 299 "./parser/Parser.y"
                                                          { (yyvsp[-2].tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id)); (yyval.tmp_id) = (yyvsp[-2].tmp_id); }
#line 2115 "./parser/Parser.cpp"
    break;

  case 39:
#line 300 "./parser/Parser.y"
                                                               {(yyvsp[-2].tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id)); (yyval.tmp_id) = (yyvsp[-2].tmp_id); }
#line 2121 "./parser/Parser.cpp"
    break;

  case 40:
#line 303 "./parser/Parser.y"
                                                                                                  {
                                    (yyval.tmp_id) = new AstNode();
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[-6].tmp_id));
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[-2].tmp_id));
                                }
#line 2131 "./parser/Parser.cpp"
    break;

  case 41:
#line 310 "./parser/Parser.y"
                                                               {
                                    (yyval.tmp_id) = new AstNode();
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[-2].tmp_id)->GetExtraNode());
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[-2].tmp_id)->GetExtraNode(1));
                                    (yyvsp[-2].tmp_id)->NullExtraNode(0);
                                    (yyvsp[-2].tmp_id)->NullExtraNode(1);
                                    delete (yyvsp[-2].tmp_id);
                                }
#line 2144 "./parser/Parser.cpp"
    break;

  case 42:
#line 318 "./parser/Parser.y"
                                                         {
                                    (yyval.tmp_id) = new AstNode();
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[-1].tmp_id)->GetExtraNode());
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[-1].tmp_id)->GetExtraNode(1));
                                    (yyvsp[-1].tmp_id)->NullExtraNode(0);
                                    (yyvsp[-1].tmp_id)->NullExtraNode(1);
                                    delete (yyvsp[-1].tmp_id);
                                }
#line 2157 "./parser/Parser.cpp"
    break;

  case 43:
#line 326 "./parser/Parser.y"
                                                                               {
                                    (yyvsp[-3].tmp_id)->SaveAsExtraNode((yyvsp[-2].tmp_id)->GetExtraNode());
                                    (yyvsp[-3].tmp_id)->SaveAsExtraNode((yyvsp[-2].tmp_id)->GetExtraNode(1));
                                    (yyvsp[-2].tmp_id)->NullExtraNode(0);
                                    (yyvsp[-2].tmp_id)->NullExtraNode(1);
                                    delete (yyvsp[-2].tmp_id);
                                    (yyval.tmp_id) = (yyvsp[-3].tmp_id);
                                }
#line 2170 "./parser/Parser.cpp"
    break;

  case 44:
#line 334 "./parser/Parser.y"
                                                                       {
                                    (yyvsp[-2].tmp_id)->SaveAsExtraNode((yyvsp[-1].tmp_id)->GetExtraNode());
                                    (yyvsp[-2].tmp_id)->SaveAsExtraNode((yyvsp[-1].tmp_id)->GetExtraNode(1));
                                    (yyvsp[-1].tmp_id)->NullExtraNode(0);
                                    (yyvsp[-1].tmp_id)->NullExtraNode(1);
                                    delete (yyvsp[-1].tmp_id);
                                    (yyval.tmp_id) = (yyvsp[-2].tmp_id);
                                }
#line 2183 "./parser/Parser.cpp"
    break;

  case 45:
#line 344 "./parser/Parser.y"
                                                { 
                                       (yyval.tmp_id) = MakeTermNode((yyvsp[0].data)->int_val, INT_NODE_TYPE);            
                                }
#line 2191 "./parser/Parser.cpp"
    break;

  case 46:
#line 347 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeTermNode((yyvsp[0].data)->dou_val, DOUBLE_NODE_TYPE);          
                                }
#line 2199 "./parser/Parser.cpp"
    break;

  case 47:
#line 350 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeTermNode((yyvsp[0].data)->flo_val, FLOAT_NODE_TYPE);            
                                }
#line 2207 "./parser/Parser.cpp"
    break;

  case 48:
#line 353 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeTermNode((string)(yyvsp[0].data)->str_val, STRING_NODE_TYPE);                   
                                }
#line 2215 "./parser/Parser.cpp"
    break;

  case 49:
#line 356 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeTermNode((yyvsp[0].data)->char_val, CHAR_NODE_TYPE);
                                }
#line 2223 "./parser/Parser.cpp"
    break;

  case 50:
#line 359 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeTermNode((yyvsp[0].data)->bol_val, BOOL_NODE_TYPE);
                                }
#line 2231 "./parser/Parser.cpp"
    break;

  case 51:
#line 362 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = (yyvsp[0].tmp_id);       
                                }
#line 2239 "./parser/Parser.cpp"
    break;

  case 52:
#line 365 "./parser/Parser.y"
                                                                           {
                                    (yyval.tmp_id) = MakeArrayTermAst((yyvsp[-2].tmp_id));
                                }
#line 2247 "./parser/Parser.cpp"
    break;

  case 53:
#line 368 "./parser/Parser.y"
                                          {
                                    (yyval.tmp_id) = MakeTermNode(0, ARRAY_NODE_TYPE);
                                }
#line 2255 "./parser/Parser.cpp"
    break;

  case 54:
#line 371 "./parser/Parser.y"
                                                               {
                                    (yyval.tmp_id) = MakeMapTermAst((yyvsp[-1].tmp_id));
                                }
#line 2263 "./parser/Parser.cpp"
    break;

  case 55:
#line 374 "./parser/Parser.y"
                                          {
                                    (yyval.tmp_id) = MakeTermNode(0, MAP_NODE_TYPE);
                                }
#line 2271 "./parser/Parser.cpp"
    break;

  case 56:
#line 379 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types); }
#line 2277 "./parser/Parser.cpp"
    break;

  case 57:
#line 380 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types); }
#line 2283 "./parser/Parser.cpp"
    break;

  case 58:
#line 381 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types); }
#line 2289 "./parser/Parser.cpp"
    break;

  case 59:
#line 382 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types); }
#line 2295 "./parser/Parser.cpp"
    break;

  case 60:
#line 383 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types); }
#line 2301 "./parser/Parser.cpp"
    break;

  case 61:
#line 384 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types); }
#line 2307 "./parser/Parser.cpp"
    break;

  case 62:
#line 385 "./parser/Parser.y"
                                       {
                                    (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types);
                                }
#line 2315 "./parser/Parser.cpp"
    break;

  case 63:
#line 388 "./parser/Parser.y"
                                      {
                                    (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types);
                                }
#line 2323 "./parser/Parser.cpp"
    break;

  case 64:
#line 393 "./parser/Parser.y"
                                                                            {
                                   (yyval.tmp_id) = (yyvsp[-4].tmp_id);
                                   (yyval.tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id));
                                }
#line 2332 "./parser/Parser.cpp"
    break;

  case 65:
#line 397 "./parser/Parser.y"
                                                                           {
                                    (yyval.tmp_id) = (yyvsp[-4].tmp_id);
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id));
                                }
#line 2341 "./parser/Parser.cpp"
    break;

  case 70:
#line 407 "./parser/Parser.y"
                                   {
                                    (yyval.tmp_id) = MakeTermNode((string)(yyvsp[0].data)->id, ID_NODE_TYPE);
                                }
#line 2349 "./parser/Parser.cpp"
    break;

  case 71:
#line 411 "./parser/Parser.y"
                                                                                                    {
                                    (yyval.tmp_id) = MakeAssignAst((yyvsp[-8].tmp_id), (yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2357 "./parser/Parser.cpp"
    break;

  case 72:
#line 414 "./parser/Parser.y"
                                                                                                   {
                                    (yyval.tmp_id) = MakeAssignAst((yyvsp[-8].tmp_id), (yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2365 "./parser/Parser.cpp"
    break;

  case 73:
#line 417 "./parser/Parser.y"
                                                                                                        {
                                    (yyval.tmp_id) = MakeUnionAst((yyvsp[-8].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2373 "./parser/Parser.cpp"
    break;

  case 74:
#line 420 "./parser/Parser.y"
                                                                                                     {
                                    (yyval.tmp_id) = MakeUnionAst((yyvsp[-8].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2381 "./parser/Parser.cpp"
    break;

  case 75:
#line 423 "./parser/Parser.y"
                                                                                                                   {
                                    (yyval.tmp_id) = MakeUnionAst((yyvsp[-10].tmp_id), (yyvsp[-5].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2389 "./parser/Parser.cpp"
    break;

  case 76:
#line 426 "./parser/Parser.y"
                                                                                                                {
                                    (yyval.tmp_id) = MakeUnionAst((yyvsp[-10].tmp_id), (yyvsp[-5].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2397 "./parser/Parser.cpp"
    break;

  case 77:
#line 429 "./parser/Parser.y"
                                                                           {
                                   (yyval.tmp_id) = MakeReassignAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2405 "./parser/Parser.cpp"
    break;

  case 78:
#line 432 "./parser/Parser.y"
                                                                                                                         {
                                    (yyval.tmp_id) = MakeRefAst((yyvsp[-12].tmp_id), (yyvsp[-8].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2413 "./parser/Parser.cpp"
    break;

  case 79:
#line 435 "./parser/Parser.y"
                                                                                                                      {
                                    (yyval.tmp_id) = MakeRefAst((yyvsp[-12].tmp_id), (yyvsp[-8].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2421 "./parser/Parser.cpp"
    break;

  case 80:
#line 438 "./parser/Parser.y"
                                                                                              {
                                    (yyval.tmp_id) = MakeRebindRefAst((yyvsp[-8].tmp_id), (yyvsp[-6].tmp_id));
                                }
#line 2429 "./parser/Parser.cpp"
    break;

  case 81:
#line 444 "./parser/Parser.y"
                                           {
                                    (yyval.tmp_id) = new AstNode();
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id));
                                }
#line 2438 "./parser/Parser.cpp"
    break;

  case 82:
#line 448 "./parser/Parser.y"
                                                   {
                                    (yyval.tmp_id) = new AstNode();
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id));
                                }
#line 2447 "./parser/Parser.cpp"
    break;

  case 83:
#line 452 "./parser/Parser.y"
                                                             {  
                                    (yyvsp[-2].tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id));
                                    (yyval.tmp_id) = (yyvsp[-2].tmp_id);
                                }
#line 2456 "./parser/Parser.cpp"
    break;

  case 84:
#line 456 "./parser/Parser.y"
                                                                  {
                                    (yyvsp[-2].tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id));
                                    (yyval.tmp_id) = (yyvsp[-2].tmp_id);
                                }
#line 2465 "./parser/Parser.cpp"
    break;

  case 89:
#line 466 "./parser/Parser.y"
                                                                            { 
                                    (yyval.tmp_id) = MakePrintAst((yyvsp[-2].tmp_id));
                                }
#line 2473 "./parser/Parser.cpp"
    break;

  case 90:
#line 469 "./parser/Parser.y"
                                                     { Destroy(); return 0; (yyval.tmp_id) = nullptr; }
#line 2479 "./parser/Parser.cpp"
    break;

  case 91:
#line 474 "./parser/Parser.y"
                                                                        {
                                    Perform((yyval.tmp_id), (yyvsp[-2].tmp_id), ADDITION_CMD);
                                }
#line 2487 "./parser/Parser.cpp"
    break;

  case 92:
#line 477 "./parser/Parser.y"
                                                                         {
                                    Perform((yyval.tmp_id), (yyvsp[-2].tmp_id), SUBTRACTION_CMD);
                                }
#line 2495 "./parser/Parser.cpp"
    break;

  case 93:
#line 480 "./parser/Parser.y"
                                                                          {
                                    Perform((yyval.tmp_id), (yyvsp[-2].tmp_id), MULTIPLY_CMD);
                                }
#line 2503 "./parser/Parser.cpp"
    break;

  case 94:
#line 483 "./parser/Parser.y"
                                                                          {
                                    Perform((yyval.tmp_id), (yyvsp[-2].tmp_id), DIVIDE_CMD);
                                }
#line 2511 "./parser/Parser.cpp"
    break;

  case 95:
#line 486 "./parser/Parser.y"
                                                                          {
                                    Perform((yyval.tmp_id), (yyvsp[-2].tmp_id), POW_CMD);
                                }
#line 2519 "./parser/Parser.cpp"
    break;

  case 96:
#line 489 "./parser/Parser.y"
                                                                        {
                                    (yyval.tmp_id) = MakeIncAst((yyvsp[-2].tmp_id));
                                }
#line 2527 "./parser/Parser.cpp"
    break;

  case 97:
#line 492 "./parser/Parser.y"
                                                                                                {
                                    (yyval.tmp_id) = MakeModAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2535 "./parser/Parser.cpp"
    break;

  case 98:
#line 500 "./parser/Parser.y"
                                                                                           {
                                    (yyval.tmp_id) = MakeLessCompAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2543 "./parser/Parser.cpp"
    break;

  case 99:
#line 503 "./parser/Parser.y"
                                                                                                {
                                    (yyval.tmp_id) = MakeGreaterCompAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2551 "./parser/Parser.cpp"
    break;

  case 100:
#line 506 "./parser/Parser.y"
                                                                                                  {
                                    (yyval.tmp_id) = MakeLessEqualCompAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2559 "./parser/Parser.cpp"
    break;

  case 101:
#line 509 "./parser/Parser.y"
                                                                                                      {
                                    (yyval.tmp_id) = MakeGreaterEqualCompAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2567 "./parser/Parser.cpp"
    break;

  case 102:
#line 512 "./parser/Parser.y"
                                                                                             {
                                    (yyval.tmp_id) = MakeEqualCompAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2575 "./parser/Parser.cpp"
    break;

  case 103:
#line 515 "./parser/Parser.y"
                                                                                                  {
                                    (yyval.tmp_id) = MakeNotEqualCompAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2583 "./parser/Parser.cpp"
    break;

  case 104:
#line 522 "./parser/Parser.y"
                                                                                         {
                                    (yyval.tmp_id) = MakeAndAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2591 "./parser/Parser.cpp"
    break;

  case 105:
#line 525 "./parser/Parser.y"
                                                                 {
                                    (yyval.tmp_id) = MakeNotAst((yyvsp[-2].tmp_id));
                                }
#line 2599 "./parser/Parser.cpp"
    break;

  case 106:
#line 528 "./parser/Parser.y"
                                                                                           {
                                    (yyval.tmp_id) = MakeOrAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2607 "./parser/Parser.cpp"
    break;

  case 107:
#line 534 "./parser/Parser.y"
                                                                  {
                                    (yyval.tmp_id) = MakeGetFromCollectionAst((yyvsp[-3].tmp_id), (yyvsp[-1].tmp_id));
                                }
#line 2615 "./parser/Parser.cpp"
    break;

  case 108:
#line 540 "./parser/Parser.y"
                                     {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2623 "./parser/Parser.cpp"
    break;

  case 109:
#line 543 "./parser/Parser.y"
                                            {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2631 "./parser/Parser.cpp"
    break;

  case 110:
#line 546 "./parser/Parser.y"
                                                                                          {
                                    (yyval.tmp_id) = MakeCastAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2639 "./parser/Parser.cpp"
    break;

  case 111:
#line 549 "./parser/Parser.y"
                                               {
                                   (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2647 "./parser/Parser.cpp"
    break;

  case 112:
#line 552 "./parser/Parser.y"
                                           {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2655 "./parser/Parser.cpp"
    break;

  case 113:
#line 555 "./parser/Parser.y"
                                                                                           {
                                     (yyval.tmp_id) = MakeAddToListAst((yyvsp[-7].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2663 "./parser/Parser.cpp"
    break;

  case 114:
#line 558 "./parser/Parser.y"
                                                                                                          {
                                    (yyval.tmp_id) = MakeAddToMapAst((yyvsp[-9].tmp_id), (yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2671 "./parser/Parser.cpp"
    break;

  case 115:
#line 561 "./parser/Parser.y"
                                                {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2679 "./parser/Parser.cpp"
    break;

  case 116:
#line 564 "./parser/Parser.y"
                                                                                                            {
                                    (yyval.tmp_id) = MakeSetInCollectionAst((yyvsp[-9].tmp_id), (yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2687 "./parser/Parser.cpp"
    break;

  case 117:
#line 567 "./parser/Parser.y"
                                                      {
                                    (yyval.tmp_id) = MakeCollectionSizeAst((yyvsp[-2].tmp_id));
                                }
#line 2695 "./parser/Parser.cpp"
    break;

  case 118:
#line 570 "./parser/Parser.y"
                                                        {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2703 "./parser/Parser.cpp"
    break;

  case 119:
#line 573 "./parser/Parser.y"
                                               { (yyval.tmp_id) = (yyvsp[0].tmp_id); }
#line 2709 "./parser/Parser.cpp"
    break;

  case 120:
#line 576 "./parser/Parser.y"
                                     { i.EatAst((yyvsp[0].tmp_id)); (yyvsp[0].tmp_id) = nullptr; }
#line 2715 "./parser/Parser.cpp"
    break;

  case 121:
#line 577 "./parser/Parser.y"
                                            { i.EatAst((yyvsp[0].tmp_id)); (yyvsp[0].tmp_id) = nullptr; }
#line 2721 "./parser/Parser.cpp"
    break;

  case 129:
#line 585 "./parser/Parser.y"
                                       {
                                    Destroy();
                                    return 0;
                                }
#line 2730 "./parser/Parser.cpp"
    break;

  case 130:
#line 589 "./parser/Parser.y"
                                        { return 0; }
#line 2736 "./parser/Parser.cpp"
    break;


#line 2740 "./parser/Parser.cpp"

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
#line 592 "./parser/Parser.y"



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
