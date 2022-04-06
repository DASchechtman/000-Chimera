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
    START = 290,
    END = 291,
    IF = 292,
    ELSE = 293,
    WHILE = 294,
    SIZE = 295,
    REPEAT = 296,
    WITH = 297,
    INC = 298,
    MOD = 299,
    GET = 300,
    SURO = 301,
    FURO = 302,
    FUNC = 303,
    CALL = 304,
    ASSIGN = 305,
    FUNC_RET = 306,
    HAS = 307,
    REMOVE = 308,
    TYPEOF = 309,
    GETINPUT = 310,
    INT_VAL = 311,
    DOUBLE_VAL = 312,
    STRING_VAL = 313,
    CHAR_VAL = 314,
    BOOL_VAL = 315,
    ELSE_IF = 316,
    FLOAT_VAL = 317,
    ID = 318,
    UNKNOWN = 319,
    MULTI_WS = 320,
    SINGLE_WS = 321
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 34 "./parser/Parser.y"

    YYSTYPEs *data;
    AstNode *tmp_id;

#line 226 "./parser/Parser.cpp"

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
#define YYFINAL  104
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1356

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  77
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  138
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  441

#define YYUNDEFTOK  2
#define YYMAXUTOK   321


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
      69,    70,     2,     2,     2,     2,    76,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    67,     2,
       2,    75,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    71,     2,    72,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    73,    68,    74,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   134,   134,   136,   138,   142,   146,   150,   154,   168,
     177,   184,   191,   199,   202,   205,   210,   217,   226,   233,
     244,   250,   255,   266,   267,   268,   269,   269,   271,   275,
     281,   284,   287,   290,   294,   299,   299,   301,   302,   303,
     306,   313,   321,   329,   337,   345,   355,   358,   361,   364,
     367,   370,   373,   376,   379,   382,   385,   390,   391,   392,
     393,   394,   395,   396,   399,   404,   408,   414,   414,   416,
     416,   418,   422,   425,   428,   431,   434,   437,   440,   443,
     446,   449,   452,   458,   462,   466,   470,   476,   477,   477,
     479,   480,   483,   488,   491,   494,   497,   500,   503,   506,
     514,   517,   520,   523,   526,   529,   536,   539,   542,   548,
     554,   557,   560,   563,   566,   569,   572,   575,   578,   581,
     584,   587,   590,   594,   597,   598,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   617,   619,   619
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
  "DIV", "POW", "ADD_LIST", "ADD_MAP", "SET", "START", "END", "IF", "ELSE",
  "WHILE", "SIZE", "REPEAT", "WITH", "INC", "MOD", "GET", "SURO", "FURO",
  "FUNC", "CALL", "ASSIGN", "FUNC_RET", "HAS", "REMOVE", "TYPEOF",
  "GETINPUT", "INT_VAL", "DOUBLE_VAL", "STRING_VAL", "CHAR_VAL",
  "BOOL_VAL", "ELSE_IF", "FLOAT_VAL", "ID", "UNKNOWN", "MULTI_WS",
  "SINGLE_WS", "':'", "'|'", "'('", "')'", "'['", "']'", "'{'", "'}'",
  "'='", "'.'", "$accept", "start", "end", "ifHead", "elseIfHead",
  "elseHead", "whileHead", "forloopHead", "paramList", "funcType",
  "functionHead", "funcRet", "functionCall", "ifBody", "elseIfBody",
  "elseBody", "elseIfChain", "whileStatement", "forloopStatement",
  "ifStatement", "functionDeclStatement", "newline", "terms",
  "keyValPairs", "keyVals", "term", "types", "unionTypes", "any_ws",
  "opt_ws", "id", "assign", "exprList", "opt_newline", "opt_ws_or_nl",
  "statement", "math_expr", "compare_expr", "boolExpr", "indexAccessor",
  "expr", "prog", "line", YY_NULLPTR
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
     315,   316,   317,   318,   319,   320,   321,    58,   124,    40,
      41,    91,    93,   123,   125,    61,    46
};
# endif

#define YYPACT_NINF (-216)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-70)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1283,  -216,    46,   -42,  -216,  -216,  -216,  -216,    46,    46,
      46,  -216,  -216,  -216,    46,  -216,  -216,  -216,  -216,  -216,
    -216,  -216,  -216,  -216,   323,    23,   -19,  1283,  1283,  1283,
    1283,    46,  1283,  -216,  -216,   -18,  -216,  -216,  -216,  -216,
    -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,
     -74,  -216,   556,  -216,   -40,    46,   468,   468,   468,   468,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,  -216,    14,  -216,   194,  -216,   -29,  1023,
     828,  1075,  1127,    13,  1179,  -216,    46,    46,  1283,  1283,
    -216,    47,   -13,   125,  -216,  -216,    46,    19,   619,     8,
       8,     8,   -74,   468,   468,   468,   468,   468,   468,   468,
     468,   468,   468,   255,    46,   468,    46,    46,    46,    46,
     468,   468,   468,    13,    13,   468,   468,    13,    46,    46,
    -216,    46,   -14,   -24,  -216,  -216,  -216,  -216,    46,  -216,
      63,   468,   960,  1231,  -216,  -216,  -216,    66,    37,    49,
      53,  -216,    59,    61,    46,  -216,    79,    95,    96,     8,
       8,     8,     8,     8,     8,     8,     8,     8,     8,   -74,
     468,   468,    71,   -74,    74,    86,    92,    94,     8,     8,
       8,    46,    46,     8,     8,    46,  -216,   194,   194,    75,
     194,    46,  -216,  -216,    -9,   102,  -216,     8,  -216,    46,
      46,    46,   468,   468,   103,  -216,  -216,    46,   210,   468,
     468,   468,   468,   468,   468,   468,   468,   104,   -74,   -74,
    -216,  -216,  -216,  -216,  -216,   105,   468,   468,    43,   109,
     468,   106,   112,   113,   730,   118,  -216,  -216,  -216,    46,
    -216,    46,  -216,   218,   151,   468,   468,   468,   -52,    10,
    -216,    13,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,
      46,     8,     8,     8,     8,     8,     8,     8,     8,  -216,
    -216,     8,     9,    46,  -216,     8,    46,  -216,  -216,     1,
       8,    46,   194,  -216,    67,    46,  -216,   120,  -216,     8,
       8,     8,  -216,  -216,    46,   124,   126,   127,   128,   131,
     133,   134,   135,   136,   141,  -216,   159,   160,    26,    46,
     161,    55,    46,    46,   197,   235,   166,    46,   167,   468,
     468,   202,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,
    -216,  -216,  -216,  -216,    46,   210,   210,    46,   468,  -216,
      46,   210,   210,    46,   178,   210,  -216,  -216,   180,   101,
     210,  -216,     8,     8,  -216,   468,    46,    35,    46,   468,
     -57,   468,    77,    46,   468,  -216,    46,    46,    46,   213,
    -216,   187,   190,     8,   191,    46,   192,   169,     8,    46,
       8,    46,   236,     8,   226,   210,   210,  -216,  -216,  -216,
     193,    46,   468,    46,   206,   198,   212,   217,   468,   216,
     221,  -216,  -216,    46,  -216,   210,     8,   210,    46,  -216,
    -216,  -216,     8,    46,  -216,   229,  -216,   222,  -216,   468,
     225,   468,  -216,  -216,     8,  -216,     8,   230,   234,  -216,
    -216
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   136,    70,     0,    35,    36,   135,     2,     0,     0,
       0,    13,    14,    15,     0,    46,    47,    49,    50,    51,
      48,    71,    67,    68,     0,    70,    70,     0,     0,     0,
       0,     0,     0,   134,   124,     0,   129,   130,   128,   123,
     133,   110,   132,    52,    90,   127,   111,   113,   114,   117,
     126,   137,     0,    69,     0,    70,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,    70,    70,    70,    70,     0,     0,     0,     0,    70,
       0,     0,    70,    54,    88,    89,     0,    56,     0,     0,
       0,     0,     0,     0,     0,    30,     0,     0,     0,     0,
      26,     0,     0,     0,     1,   138,    70,     0,     0,     0,
       0,     0,    20,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    70,     0,    70,    70,    70,    70,
       0,     0,     0,     0,     0,     0,     0,     0,    70,    70,
      37,    70,     0,     0,     3,   131,    28,    29,    70,    34,
       0,     0,     0,     0,    33,    31,    27,     0,     0,     0,
       0,   119,     0,     0,    70,    92,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    70,    83,
      69,    89,     0,    84,     0,     0,     0,     0,    70,     0,
       0,    70,    70,    70,    70,    70,    87,    69,    89,     0,
       0,    70,    42,    55,    45,     0,     6,     0,    32,    70,
      70,    70,     0,     0,     0,     4,     7,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    85,    86,
      93,    94,    95,    96,    97,     0,     0,     0,    70,     0,
      69,     0,     0,     0,    69,     0,    38,    39,    53,     0,
      41,    70,    44,     0,     0,     0,     0,     0,     0,     0,
      91,     0,    57,    58,    59,    60,    61,    62,    63,    64,
      70,    70,    70,    70,    70,    70,    70,    70,    70,   107,
      98,    70,     0,    70,    21,    70,    70,   122,   125,    70,
      70,    70,     0,    43,     0,    70,    10,     0,     5,    70,
       0,     0,   120,   121,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   109,     0,     0,     0,     0,
       0,     0,    70,    70,     0,    69,     0,    70,     0,     0,
       0,     0,   112,   100,   101,   102,   103,   104,   105,   106,
     108,    99,    22,    73,     0,     0,     0,     0,     0,    79,
       0,     0,     0,     0,     0,     0,    18,    12,     0,     0,
       0,   115,    70,    70,     8,     0,    70,    70,     0,     0,
       0,     0,    70,     0,     0,    40,     0,    70,    70,     0,
       9,     0,     0,    70,     0,     0,     0,     0,    70,    70,
      70,     0,     0,    70,     0,     0,     0,    19,   116,   118,
       0,    70,     0,    70,     0,     0,     0,     0,     0,     0,
       0,    16,    11,     0,    75,     0,    70,     0,     0,    72,
      82,    76,    70,     0,    74,     0,    65,     0,    66,     0,
       0,     0,    17,    77,    70,    78,    70,     0,     0,    80,
      81
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,
    -216,  -216,  -216,  -216,   204,   207,  -216,  -216,  -216,  -216,
    -216,  -216,  -216,   153,  -216,   -82,  -215,   -43,   394,    -2,
     -92,  -216,   -66,    -4,    24,  -216,  -216,  -216,  -216,  -216,
     601,     2,   -17
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    27,   145,    28,    98,    99,    29,    30,   295,    31,
      32,    33,    34,    35,   100,   101,   102,    36,    37,    38,
      39,    40,   139,   142,   143,    41,   366,   367,    53,    84,
      43,    44,   124,   125,    88,    45,    46,    47,    48,    49,
      50,    51,    52
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      54,   148,   103,   270,   140,   126,   127,   128,   129,   201,
      89,    90,    91,    92,   251,    94,   302,   389,    95,   103,
      96,    85,    85,   155,   103,    96,    55,   319,   106,   262,
     263,   264,   265,   266,   267,   268,   269,   138,   296,   141,
     164,   191,   192,    97,   141,   195,    22,    23,    97,    86,
     203,    22,    23,   107,   105,    87,    22,    23,   262,   263,
     264,   265,   266,   267,   268,   269,    22,    23,   123,   123,
     123,   123,   123,    22,    23,    87,    21,   134,   303,   315,
     137,   152,   153,   154,   103,   103,   103,   165,    22,    23,
     344,   105,   105,   105,   105,    83,   105,   345,   206,   346,
      22,    23,   208,   347,   123,   209,   353,   385,    22,    23,
     357,    22,    23,   -69,   215,   246,   247,   210,   249,   350,
     181,   211,   181,   181,   181,   181,   351,   212,   352,   213,
     216,   368,    22,    23,   323,   198,   196,   373,   217,   200,
     376,   230,    22,    23,   231,   380,   205,   248,   182,   391,
     184,   185,   186,   187,   105,   105,   232,   158,   159,   160,
     181,   297,   233,   199,   234,   161,    22,    23,   378,   304,
     253,   260,   283,   286,   279,   280,   227,   162,   163,   284,
     412,   413,   287,   288,    85,   291,   298,   327,   214,   239,
     241,   242,   243,   245,   332,   404,   333,   334,   335,   250,
     426,   336,   428,   337,   338,   339,   340,   255,   256,   257,
     322,   341,   235,   262,   263,   264,   265,   266,   267,   268,
     269,   262,   263,   264,   265,   266,   267,   268,   269,   342,
     343,   349,   356,   358,   359,   361,   123,   364,   262,   263,
     264,   265,   266,   267,   268,   269,   375,   377,   397,   293,
      15,    16,    17,    18,    19,   398,    20,    21,   399,   401,
     403,   411,   409,   414,   432,    25,    85,    26,   419,   306,
     307,   308,   309,   310,   311,   312,   313,    85,   138,   181,
     418,    21,   420,   317,   318,    85,   294,   421,   320,   321,
     423,   424,   433,   326,   305,   435,   204,   328,    21,     0,
     439,    11,    12,    13,   440,   314,   156,   316,   372,   157,
       0,    15,    16,    17,    18,    19,     0,    20,    21,     0,
     354,   355,     0,     0,   108,   360,    25,     0,    26,     0,
       0,     0,     0,     0,    60,    61,    62,    63,    64,    65,
      66,     0,    67,    68,    69,     0,     0,     0,     0,     0,
      70,    71,    72,    73,    74,     0,     0,     0,     0,     0,
     381,   382,     0,     0,   384,   386,    75,    76,    77,     0,
     386,     0,    78,    79,     0,   395,   396,    80,    81,     0,
       0,   400,     0,     0,     0,     0,   405,   406,   407,     0,
       0,   410,     0,     0,    42,     0,     0,     0,    82,   415,
       0,   417,    56,    57,    58,     0,     0,     0,    59,     0,
       0,     0,     0,     0,   427,     0,     0,     0,     0,     0,
     430,    42,    42,    42,    42,    93,    42,     0,     0,     0,
       0,     0,   437,     0,   438,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    42,     0,     0,     0,
       0,     0,     0,     0,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,     0,     0,     0,     0,     0,   130,
     131,   132,   133,     0,   135,   136,     0,     0,     0,     0,
       0,     0,     0,    42,    42,    42,    42,     0,    42,     0,
     150,   151,    42,    42,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   166,   167,   168,     0,     0,     0,     0,
       0,     0,     0,     0,    11,    12,    13,     0,   180,     0,
     180,   180,   180,   180,    15,    16,    17,    18,    19,     0,
      20,    21,     0,   197,     0,     0,   202,   108,     0,    25,
       0,    26,     0,     0,     0,     0,    42,    42,     0,     0,
       0,     0,     0,     0,     0,     0,   104,     1,   180,     0,
       0,     0,     0,   218,   219,   220,   221,   222,   223,   224,
     225,   226,     0,     0,     2,     0,     0,     0,     3,     4,
       5,     6,     0,   236,   237,   238,   240,     0,     0,   244,
       0,     7,     0,     8,     0,     9,     0,    10,   252,     0,
       0,   254,    11,    12,    13,     0,     0,    14,     0,     0,
       0,   261,    15,    16,    17,    18,    19,     0,    20,    21,
       0,    22,    23,     0,     0,    24,     0,    25,     0,    26,
      60,    61,    62,    63,    64,    65,    66,     0,    67,    68,
      69,     0,     0,   292,     0,     0,    70,    71,    72,    73,
      74,     0,     0,     0,     0,     0,     0,   109,   110,   111,
     112,     0,    75,    76,    77,     0,     0,     0,    78,     0,
       0,     0,     0,    80,    81,     0,     0,   180,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   324,   325,
       0,     0,     0,     0,   329,   330,     0,     0,   331,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   348,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,     0,   183,     0,     0,     0,
       0,   188,   189,   190,     0,     0,   193,   194,   365,     0,
       0,   369,     0,     0,   371,     0,     0,   374,     0,     0,
       0,     0,   207,   379,     0,     0,     0,     0,     0,     0,
       0,     0,   387,     0,     0,     0,     0,   392,     0,     0,
     394,     0,     0,     0,     0,     0,    11,    12,    13,   402,
       0,   228,   229,     0,     0,   408,    15,    16,    17,    18,
      19,     0,    20,    21,     0,     0,     0,     0,     0,   108,
       0,    25,     0,   289,     0,     0,     0,   425,     0,     0,
       0,     0,   429,   258,   259,     0,     0,   431,     0,     0,
     271,   272,   273,   274,   275,   276,   277,   278,     0,     1,
       0,     0,     0,     0,     0,     0,     0,   281,   282,     0,
       0,   285,     0,     0,     0,   290,     2,     0,     0,     0,
       3,     4,     5,     6,     0,     0,   299,   300,   301,     0,
       0,     0,     0,     7,   -23,     8,   -23,     9,     0,    10,
       0,     0,     0,     0,    11,    12,    13,     0,     0,    14,
       0,     0,     0,     0,    15,    16,    17,    18,    19,   -23,
      20,    21,     0,    22,    23,     0,     0,    24,     0,    25,
       0,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     362,   363,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   370,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     0,     0,     0,   383,     0,     0,     0,
     388,     0,   390,     0,     0,   393,     0,     0,     2,     0,
       0,     0,     3,     4,     5,     6,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,   -24,     8,   -24,     9,
       0,    10,     0,   416,     0,     0,    11,    12,    13,   422,
       0,    14,     0,     0,     0,     0,    15,    16,    17,    18,
      19,   -24,    20,    21,     1,    22,    23,     0,     0,    24,
     434,    25,   436,    26,     0,     0,     0,     0,     0,     0,
       0,     2,     0,     0,     0,     3,     4,     5,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,   144,
       8,     0,     9,     0,    10,     0,     0,     0,     0,    11,
      12,    13,     0,     0,    14,     0,     1,     0,     0,    15,
      16,    17,    18,    19,     0,    20,    21,     0,    22,    23,
       0,     0,    24,     2,    25,     0,    26,     3,     4,     5,
       6,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,   146,     8,     0,     9,     0,    10,     0,     0,     0,
       0,    11,    12,    13,     0,     0,    14,     0,     1,     0,
       0,    15,    16,    17,    18,    19,     0,    20,    21,     0,
      22,    23,     0,     0,    24,     2,    25,     0,    26,     3,
       4,     5,     6,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,   147,     8,     0,     9,     0,    10,     0,
       0,     0,     0,    11,    12,    13,     0,     0,    14,     0,
       1,     0,     0,    15,    16,    17,    18,    19,     0,    20,
      21,     0,    22,    23,     0,     0,    24,     2,    25,     0,
      26,     3,     4,     5,     6,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,   149,     8,     0,     9,     0,
      10,     0,     0,     0,     0,    11,    12,    13,     0,     0,
      14,     0,     1,     0,     0,    15,    16,    17,    18,    19,
       0,    20,    21,     0,    22,    23,     0,     0,    24,     2,
      25,     0,    26,     3,     4,     5,     6,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     7,   -25,     8,     0,
       9,     0,    10,     0,     0,     0,     0,    11,    12,    13,
       0,     0,    14,     0,     1,     0,     0,    15,    16,    17,
      18,    19,     0,    20,    21,     0,    22,    23,     0,     0,
      24,     2,    25,     0,    26,     3,     4,     5,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     0,
       8,     0,     9,     0,    10,     0,     0,     0,     0,    11,
      12,    13,     0,     0,    14,     0,     0,     0,     0,    15,
      16,    17,    18,    19,     0,    20,    21,     0,    22,    23,
       0,     0,    24,     0,    25,     0,    26
};

static const yytype_int16 yycheck[] =
{
       2,    93,    76,   218,    86,    71,    72,    73,    74,    23,
      27,    28,    29,    30,    23,    32,    68,    74,    36,    76,
      38,    25,    26,    36,    76,    38,    68,    26,    68,     3,
       4,     5,     6,     7,     8,     9,    10,    23,   253,    68,
     106,   133,   134,    61,    68,   137,    65,    66,    61,    25,
      74,    65,    66,    55,    52,    74,    65,    66,     3,     4,
       5,     6,     7,     8,     9,    10,    65,    66,    70,    71,
      72,    73,    74,    65,    66,    74,    63,    79,    68,    70,
      82,    98,    99,    36,    76,    76,    76,    68,    65,    66,
      64,    89,    90,    91,    92,    72,    94,    71,    35,    73,
      65,    66,    36,   318,   106,    68,   321,    72,    65,    66,
     325,    65,    66,    70,    35,   197,   198,    68,   200,    64,
     124,    68,   126,   127,   128,   129,    71,    68,    73,    68,
      35,   346,    65,    66,    67,   139,   138,   352,    42,   141,
     355,    70,    65,    66,    70,   360,   148,    72,   124,    72,
     126,   127,   128,   129,   152,   153,    70,    32,    33,    34,
     164,   253,    70,   139,    70,    40,    65,    66,    67,   261,
      68,    68,   238,    67,    70,    70,   178,    52,    53,    70,
     395,   396,    70,    70,   188,    67,    35,    67,   164,   191,
     192,   193,   194,   195,    70,    26,    70,    70,    70,   201,
     415,    70,   417,    70,    70,    70,    70,   209,   210,   211,
     292,    70,   188,     3,     4,     5,     6,     7,     8,     9,
      10,     3,     4,     5,     6,     7,     8,     9,    10,    70,
      70,    70,    35,   325,    68,    68,   238,    35,     3,     4,
       5,     6,     7,     8,     9,    10,    68,    67,    35,   251,
      56,    57,    58,    59,    60,    68,    62,    63,    68,    68,
      68,    35,    26,    70,    35,    71,   270,    73,    70,   271,
     272,   273,   274,   275,   276,   277,   278,   281,    23,   283,
      74,    63,    70,   285,   286,   289,    68,    70,   290,   291,
      74,    70,    70,   295,   270,    70,   143,   299,    63,    -1,
      70,    46,    47,    48,    70,   281,   102,   283,   351,   102,
      -1,    56,    57,    58,    59,    60,    -1,    62,    63,    -1,
     322,   323,    -1,    -1,    69,   327,    71,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    11,    12,    13,    14,    15,    16,
      17,    -1,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,
     362,   363,    -1,    -1,   366,   367,    43,    44,    45,    -1,
     372,    -1,    49,    50,    -1,   377,   378,    54,    55,    -1,
      -1,   383,    -1,    -1,    -1,    -1,   388,   389,   390,    -1,
      -1,   393,    -1,    -1,     0,    -1,    -1,    -1,    75,   401,
      -1,   403,     8,     9,    10,    -1,    -1,    -1,    14,    -1,
      -1,    -1,    -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,
     422,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,   434,    -1,   436,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    75,
      76,    77,    78,    -1,    80,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    90,    91,    92,    -1,    94,    -1,
      96,    97,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   109,   110,   111,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    -1,   124,    -1,
     126,   127,   128,   129,    56,    57,    58,    59,    60,    -1,
      62,    63,    -1,   139,    -1,    -1,   142,    69,    -1,    71,
      -1,    73,    -1,    -1,    -1,    -1,   152,   153,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     0,     1,   164,    -1,
      -1,    -1,    -1,   169,   170,   171,   172,   173,   174,   175,
     176,   177,    -1,    -1,    18,    -1,    -1,    -1,    22,    23,
      24,    25,    -1,   189,   190,   191,   192,    -1,    -1,   195,
      -1,    35,    -1,    37,    -1,    39,    -1,    41,   204,    -1,
      -1,   207,    46,    47,    48,    -1,    -1,    51,    -1,    -1,
      -1,   217,    56,    57,    58,    59,    60,    -1,    62,    63,
      -1,    65,    66,    -1,    -1,    69,    -1,    71,    -1,    73,
      11,    12,    13,    14,    15,    16,    17,    -1,    19,    20,
      21,    -1,    -1,   249,    -1,    -1,    27,    28,    29,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      59,    -1,    43,    44,    45,    -1,    -1,    -1,    49,    -1,
      -1,    -1,    -1,    54,    55,    -1,    -1,   283,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   294,   295,
      -1,    -1,    -1,    -1,   300,   301,    -1,    -1,   304,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   319,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,    -1,   125,    -1,    -1,    -1,
      -1,   130,   131,   132,    -1,    -1,   135,   136,   344,    -1,
      -1,   347,    -1,    -1,   350,    -1,    -1,   353,    -1,    -1,
      -1,    -1,   151,   359,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   368,    -1,    -1,    -1,    -1,   373,    -1,    -1,
     376,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,   385,
      -1,   180,   181,    -1,    -1,   391,    56,    57,    58,    59,
      60,    -1,    62,    63,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    71,    -1,    73,    -1,    -1,    -1,   413,    -1,    -1,
      -1,    -1,   418,   212,   213,    -1,    -1,   423,    -1,    -1,
     219,   220,   221,   222,   223,   224,   225,   226,    -1,     1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,   237,    -1,
      -1,   240,    -1,    -1,    -1,   244,    18,    -1,    -1,    -1,
      22,    23,    24,    25,    -1,    -1,   255,   256,   257,    -1,
      -1,    -1,    -1,    35,    36,    37,    38,    39,    -1,    41,
      -1,    -1,    -1,    -1,    46,    47,    48,    -1,    -1,    51,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    -1,    65,    66,    -1,    -1,    69,    -1,    71,
      -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     329,   330,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   348,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     1,    -1,    -1,    -1,    -1,   365,    -1,    -1,    -1,
     369,    -1,   371,    -1,    -1,   374,    -1,    -1,    18,    -1,
      -1,    -1,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,
      -1,    41,    -1,   402,    -1,    -1,    46,    47,    48,   408,
      -1,    51,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,     1,    65,    66,    -1,    -1,    69,
     429,    71,   431,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    -1,    -1,    -1,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
      37,    -1,    39,    -1,    41,    -1,    -1,    -1,    -1,    46,
      47,    48,    -1,    -1,    51,    -1,     1,    -1,    -1,    56,
      57,    58,    59,    60,    -1,    62,    63,    -1,    65,    66,
      -1,    -1,    69,    18,    71,    -1,    73,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,    37,    -1,    39,    -1,    41,    -1,    -1,    -1,
      -1,    46,    47,    48,    -1,    -1,    51,    -1,     1,    -1,
      -1,    56,    57,    58,    59,    60,    -1,    62,    63,    -1,
      65,    66,    -1,    -1,    69,    18,    71,    -1,    73,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    36,    37,    -1,    39,    -1,    41,    -1,
      -1,    -1,    -1,    46,    47,    48,    -1,    -1,    51,    -1,
       1,    -1,    -1,    56,    57,    58,    59,    60,    -1,    62,
      63,    -1,    65,    66,    -1,    -1,    69,    18,    71,    -1,
      73,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36,    37,    -1,    39,    -1,
      41,    -1,    -1,    -1,    -1,    46,    47,    48,    -1,    -1,
      51,    -1,     1,    -1,    -1,    56,    57,    58,    59,    60,
      -1,    62,    63,    -1,    65,    66,    -1,    -1,    69,    18,
      71,    -1,    73,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,    -1,
      39,    -1,    41,    -1,    -1,    -1,    -1,    46,    47,    48,
      -1,    -1,    51,    -1,     1,    -1,    -1,    56,    57,    58,
      59,    60,    -1,    62,    63,    -1,    65,    66,    -1,    -1,
      69,    18,    71,    -1,    73,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,
      37,    -1,    39,    -1,    41,    -1,    -1,    -1,    -1,    46,
      47,    48,    -1,    -1,    51,    -1,    -1,    -1,    -1,    56,
      57,    58,    59,    60,    -1,    62,    63,    -1,    65,    66,
      -1,    -1,    69,    -1,    71,    -1,    73
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    18,    22,    23,    24,    25,    35,    37,    39,
      41,    46,    47,    48,    51,    56,    57,    58,    59,    60,
      62,    63,    65,    66,    69,    71,    73,    78,    80,    83,
      84,    86,    87,    88,    89,    90,    94,    95,    96,    97,
      98,   102,   105,   107,   108,   112,   113,   114,   115,   116,
     117,   118,   119,   105,   106,    68,   105,   105,   105,   105,
      11,    12,    13,    14,    15,    16,    17,    19,    20,    21,
      27,    28,    29,    30,    31,    43,    44,    45,    49,    50,
      54,    55,    75,    72,   106,   110,   111,    74,   111,   119,
     119,   119,   119,   105,   119,    36,    38,    61,    81,    82,
      91,    92,    93,    76,     0,   118,    68,   106,    69,   117,
     117,   117,   117,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   106,   109,   110,   109,   109,   109,   109,
     105,   105,   105,   105,   106,   105,   105,   106,    23,    99,
     102,    68,   100,   101,    36,    79,    36,    36,   107,    36,
     105,   105,   119,   119,    36,    36,    91,    92,    32,    33,
      34,    40,    52,    53,   109,    68,   105,   105,   105,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     105,   110,   111,   117,   111,   111,   111,   111,   117,   117,
     117,   107,   107,   117,   117,   107,   106,   105,   110,   111,
     106,    23,   105,    74,   100,   106,    35,   117,    36,    68,
      68,    68,    68,    68,   111,    35,    35,    42,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   106,   117,   117,
      70,    70,    70,    70,    70,   111,   105,   105,   105,   106,
     105,   106,   106,   106,   105,   106,   102,   102,    72,   102,
     106,    23,   105,    68,   105,   106,   106,   106,   117,   117,
      68,   105,     3,     4,     5,     6,     7,     8,     9,    10,
     103,   117,   117,   117,   117,   117,   117,   117,   117,    70,
      70,   117,   117,   109,    70,   117,    67,    70,    70,    73,
     117,    67,   105,   106,    68,    85,   103,   107,    35,   117,
     117,   117,    68,    68,   107,   111,   106,   106,   106,   106,
     106,   106,   106,   106,   111,    70,   111,   106,   106,    26,
     106,   106,   102,    67,   105,   105,   106,    67,   106,   105,
     105,   105,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    64,    71,    73,   103,   105,    70,
      64,    71,    73,   103,   106,   106,    35,   103,   107,    68,
     106,    68,   117,   117,    35,   105,   103,   104,   103,   105,
     117,   105,   104,   103,   105,    68,   103,    67,    67,   105,
     103,   106,   106,   117,   106,    72,   106,   105,   117,    74,
     117,    72,   105,   117,   105,   106,   106,    35,    68,    68,
     106,    68,   105,    68,    26,   106,   106,   106,   105,    26,
     106,    35,   103,   103,    70,   106,   117,   106,    74,    70,
      70,    70,   117,    74,    70,   105,   103,   106,   103,   105,
     106,   105,    35,    70,   117,    70,   117,   106,   106,    70,
      70
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      85,    85,    85,    86,    86,    86,    87,    87,    87,    87,
      88,    89,    89,    90,    91,    92,    93,    93,    94,    95,
      96,    96,    96,    96,    97,    98,    98,    99,    99,    99,
     100,   101,   101,   101,   101,   101,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   103,   103,   103,
     103,   103,   103,   103,   103,   104,   104,   105,   105,   106,
     106,   107,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   109,   109,   109,   109,   110,   111,   111,
     112,   112,   112,   113,   113,   113,   113,   113,   113,   113,
     114,   114,   114,   114,   114,   114,   115,   115,   115,   116,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   119,   119
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     5,     5,     3,     5,     9,     4,
       1,     6,     3,     1,     1,     1,    11,    13,     8,    10,
       3,     6,     8,     2,     2,     2,     1,     2,     3,     3,
       2,     3,     4,     3,     3,     1,     1,     1,     3,     3,
       7,     3,     2,     4,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     5,     2,     4,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     5,     1,     1,     1,
       0,     1,    12,     8,    12,    12,    12,    14,    14,     8,
      16,    16,    12,     2,     2,     3,     3,     3,     1,     1,
       1,     6,     4,     5,     5,     5,     5,     5,     6,     8,
       8,     8,     8,     8,     8,     8,     8,     6,     8,     7,
       1,     1,     8,     1,     1,     8,    10,     1,    10,     3,
       6,     6,     6,     1,     1,     6,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     2
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
#line 134 "./parser/Parser.y"
                                      { i.EatAst(MakeStartAst()); }
#line 1868 "./parser/Parser.cpp"
    break;

  case 3:
#line 136 "./parser/Parser.y"
                                    { i.EatAst(MakeEndScopeAst()); }
#line 1874 "./parser/Parser.cpp"
    break;

  case 4:
#line 138 "./parser/Parser.y"
                                                            {
                                    i.EatAst(MakeIfDeclAst((yyvsp[-2].tmp_id)));
                                }
#line 1882 "./parser/Parser.cpp"
    break;

  case 5:
#line 142 "./parser/Parser.y"
                                                                 {
                                    i.EatAst(MakeElifDeclAst((yyvsp[-2].tmp_id)));
                                }
#line 1890 "./parser/Parser.cpp"
    break;

  case 6:
#line 146 "./parser/Parser.y"
                                                 {
                                    i.EatAst(MakeElseDeclAst());
                                }
#line 1898 "./parser/Parser.cpp"
    break;

  case 7:
#line 150 "./parser/Parser.y"
                                                               {
                                    i.EatAst(MakeWhileDeclAst((yyvsp[-2].tmp_id)));
                                }
#line 1906 "./parser/Parser.cpp"
    break;

  case 8:
#line 154 "./parser/Parser.y"
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
#line 1924 "./parser/Parser.cpp"
    break;

  case 9:
#line 168 "./parser/Parser.y"
                                                    {
                                    auto param = MakeNode(FUNC_PARAM_CMD);
                                    param->AddToLeftNodes((yyvsp[-3].tmp_id));
                                    param->AddToRightNodes((yyvsp[0].tmp_id));
                                    auto list = new AstNode();
                                    list->AddToLeftNodes(param);
                                    (yyval.tmp_id) = list;

                                }
#line 1938 "./parser/Parser.cpp"
    break;

  case 10:
#line 177 "./parser/Parser.y"
                                        {
                                    auto param = MakeNode(FUNC_PARAM_CMD);
                                    param->AddToRightNodes((yyvsp[0].tmp_id));
                                    auto list = new AstNode();
                                    list->AddToLeftNodes(param);
                                    (yyval.tmp_id) = list;
                                }
#line 1950 "./parser/Parser.cpp"
    break;

  case 11:
#line 184 "./parser/Parser.y"
                                                                             {
                                    auto param = MakeNode(FUNC_PARAM_CMD);
                                    param->AddToLeftNodes((yyvsp[-3].tmp_id));
                                    param->AddToRightNodes((yyvsp[0].tmp_id));
                                    (yyvsp[-5].tmp_id)->AddToLeftNodes(param);
                                    (yyval.tmp_id) = (yyvsp[-5].tmp_id);
                                }
#line 1962 "./parser/Parser.cpp"
    break;

  case 12:
#line 191 "./parser/Parser.y"
                                                               {
                                    auto param = MakeNode(FUNC_PARAM_CMD);
                                    param->AddToRightNodes((yyvsp[0].tmp_id));
                                    (yyvsp[-2].tmp_id)->AddToLeftNodes(param);
                                    (yyval.tmp_id) = (yyvsp[-2].tmp_id);
                                }
#line 1973 "./parser/Parser.cpp"
    break;

  case 13:
#line 199 "./parser/Parser.y"
                                     {
                                    (yyval.tmp_id) = MakeNode(FUNC_SURO_TYPE);
                                }
#line 1981 "./parser/Parser.cpp"
    break;

  case 14:
#line 202 "./parser/Parser.y"
                                       {
                                    (yyval.tmp_id) = MakeNode(FUNC_FURO_TYPE);
                                }
#line 1989 "./parser/Parser.cpp"
    break;

  case 15:
#line 205 "./parser/Parser.y"
                                       {
                                    (yyval.tmp_id) = MakeNode(FUNC_FUNC_TYPE);
                                }
#line 1997 "./parser/Parser.cpp"
    break;

  case 16:
#line 210 "./parser/Parser.y"
                                                                                                {
                                    (yyval.tmp_id) = MakeNode(MAKE_FUNC_CMD);
                                    (yyval.tmp_id)->AddToLeftNodes((yyvsp[-8].tmp_id));
                                    (yyval.tmp_id)->AddToLeftNodes((yyvsp[-10].tmp_id));
                                    (yyval.tmp_id)->AddToRightNodes((yyvsp[-2].tmp_id));
                                    i.EatAst((yyval.tmp_id));
                                }
#line 2009 "./parser/Parser.cpp"
    break;

  case 17:
#line 217 "./parser/Parser.y"
                                                                                                                   {
                                    (yyval.tmp_id) = MakeNode(MAKE_FUNC_CMD);
                                    (yyval.tmp_id)->AddToLeftNodes((yyvsp[-10].tmp_id));
                                    (yyval.tmp_id)->AddToLeftNodes((yyvsp[-12].tmp_id));
                                    (yyval.tmp_id)->AddToMiddleNodes((yyvsp[-7].tmp_id));
                                    (yyval.tmp_id)->AddToRightNodes((yyvsp[-2].tmp_id));
                                    i.EatAst((yyval.tmp_id));
                                    (yyval.tmp_id) = nullptr;
                                }
#line 2023 "./parser/Parser.cpp"
    break;

  case 18:
#line 226 "./parser/Parser.y"
                                                                                 {
                                    (yyval.tmp_id) = MakeNode(MAKE_FUNC_CMD);
                                    (yyval.tmp_id)->AddToLeftNodes((yyvsp[-5].tmp_id));
                                    (yyval.tmp_id)->AddToLeftNodes((yyvsp[-7].tmp_id));
                                    (yyval.tmp_id)->AddToRightNodes(MakeDataTypeNode("int"));
                                    i.EatAst((yyval.tmp_id));
                                }
#line 2035 "./parser/Parser.cpp"
    break;

  case 19:
#line 233 "./parser/Parser.y"
                                                                                                  {
                                    (yyval.tmp_id) = MakeNode(MAKE_FUNC_CMD);
                                    (yyval.tmp_id)->AddToLeftNodes((yyvsp[-7].tmp_id));
                                    (yyval.tmp_id)->AddToLeftNodes((yyvsp[-9].tmp_id));
                                    (yyval.tmp_id)->AddToMiddleNodes((yyvsp[-4].tmp_id));
                                    (yyval.tmp_id)->AddToRightNodes(MakeDataTypeNode("int"));
                                    i.EatAst((yyval.tmp_id));
                                    (yyval.tmp_id) = nullptr;
                                }
#line 2049 "./parser/Parser.cpp"
    break;

  case 20:
#line 244 "./parser/Parser.y"
                                                     {
                                    auto node = MakeNode(FUNC_RETR_CMD);
                                    node->AddToLeftNodes((yyvsp[0].tmp_id));
                                    i.EatAst(node);
                                }
#line 2059 "./parser/Parser.cpp"
    break;

  case 21:
#line 250 "./parser/Parser.y"
                                                              {
                                    auto func_call = MakeNode(CALL_FUNC_CMD);
                                    func_call->AddToLeftNodes((yyvsp[-2].tmp_id));
                                    (yyval.tmp_id) = func_call;
                                }
#line 2069 "./parser/Parser.cpp"
    break;

  case 22:
#line 255 "./parser/Parser.y"
                                                                                      {
                                    auto func_call = MakeNode(CALL_FUNC_CMD);
                                    func_call->AddToLeftNodes((yyvsp[-4].tmp_id));
                                    auto end = (yyvsp[-2].tmp_id)->Extras();
                                    for(size_t iter = 0; iter < end; iter++) {
                                        func_call->AddToRightNodes((yyvsp[-2].tmp_id)->GetExtraNode(iter));
                                    }
                                    (yyval.tmp_id) = func_call;
                                }
#line 2083 "./parser/Parser.cpp"
    break;

  case 28:
#line 271 "./parser/Parser.y"
                                                   {
                                    i.EatAst(MakeEndCtrlScopeAst());
                                }
#line 2091 "./parser/Parser.cpp"
    break;

  case 29:
#line 275 "./parser/Parser.y"
                                                     {
                                    i.EatAst(MakeIncAst((yyvsp[-2].tmp_id)));
                                    i.EatAst(MakeEndCtrlScopeAst());
                                    i.EatAst(MakeEndScopeAst());  
                                }
#line 2101 "./parser/Parser.cpp"
    break;

  case 30:
#line 281 "./parser/Parser.y"
                                           {
                                    i.EatAst(MakeEndCtrlScopeAst());
                                }
#line 2109 "./parser/Parser.cpp"
    break;

  case 31:
#line 284 "./parser/Parser.y"
                                                         {
                                    i.EatAst(MakeEndCtrlScopeAst());
                                }
#line 2117 "./parser/Parser.cpp"
    break;

  case 32:
#line 287 "./parser/Parser.y"
                                                                  {
                                    i.EatAst(MakeEndCtrlScopeAst());
                                }
#line 2125 "./parser/Parser.cpp"
    break;

  case 33:
#line 290 "./parser/Parser.y"
                                                      {
                                    i.EatAst(MakeEndCtrlScopeAst());
                                }
#line 2133 "./parser/Parser.cpp"
    break;

  case 34:
#line 294 "./parser/Parser.y"
                                                      {
                                    (yyval.tmp_id) = MakeNode(FUNC_END_CMD);
                                }
#line 2141 "./parser/Parser.cpp"
    break;

  case 37:
#line 301 "./parser/Parser.y"
                                     { (yyval.tmp_id) = new AstNode(); (yyval.tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id)); }
#line 2147 "./parser/Parser.cpp"
    break;

  case 38:
#line 302 "./parser/Parser.y"
                                                          { (yyvsp[-2].tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id)); (yyval.tmp_id) = (yyvsp[-2].tmp_id); }
#line 2153 "./parser/Parser.cpp"
    break;

  case 39:
#line 303 "./parser/Parser.y"
                                                               {(yyvsp[-2].tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id)); (yyval.tmp_id) = (yyvsp[-2].tmp_id); }
#line 2159 "./parser/Parser.cpp"
    break;

  case 40:
#line 306 "./parser/Parser.y"
                                                                                   {
                                    (yyval.tmp_id) = new AstNode();
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[-4].tmp_id));
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[-2].tmp_id));
                                }
#line 2169 "./parser/Parser.cpp"
    break;

  case 41:
#line 313 "./parser/Parser.y"
                                                               {
                                    (yyval.tmp_id) = new AstNode();
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[-2].tmp_id)->GetExtraNode());
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[-2].tmp_id)->GetExtraNode(1));
                                    (yyvsp[-2].tmp_id)->NullExtraNode(0);
                                    (yyvsp[-2].tmp_id)->NullExtraNode(1);
                                    delete (yyvsp[-2].tmp_id);
                                }
#line 2182 "./parser/Parser.cpp"
    break;

  case 42:
#line 321 "./parser/Parser.y"
                                                         {
                                    (yyval.tmp_id) = new AstNode();
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[-1].tmp_id)->GetExtraNode());
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[-1].tmp_id)->GetExtraNode(1));
                                    (yyvsp[-1].tmp_id)->NullExtraNode(0);
                                    (yyvsp[-1].tmp_id)->NullExtraNode(1);
                                    delete (yyvsp[-1].tmp_id);
                                }
#line 2195 "./parser/Parser.cpp"
    break;

  case 43:
#line 329 "./parser/Parser.y"
                                                                               {
                                    (yyvsp[-3].tmp_id)->SaveAsExtraNode((yyvsp[-2].tmp_id)->GetExtraNode());
                                    (yyvsp[-3].tmp_id)->SaveAsExtraNode((yyvsp[-2].tmp_id)->GetExtraNode(1));
                                    (yyvsp[-2].tmp_id)->NullExtraNode(0);
                                    (yyvsp[-2].tmp_id)->NullExtraNode(1);
                                    delete (yyvsp[-2].tmp_id);
                                    (yyval.tmp_id) = (yyvsp[-3].tmp_id);
                                }
#line 2208 "./parser/Parser.cpp"
    break;

  case 44:
#line 337 "./parser/Parser.y"
                                                                       {
                                    (yyvsp[-2].tmp_id)->SaveAsExtraNode((yyvsp[-1].tmp_id)->GetExtraNode());
                                    (yyvsp[-2].tmp_id)->SaveAsExtraNode((yyvsp[-1].tmp_id)->GetExtraNode(1));
                                    (yyvsp[-1].tmp_id)->NullExtraNode(0);
                                    (yyvsp[-1].tmp_id)->NullExtraNode(1);
                                    delete (yyvsp[-1].tmp_id);
                                    (yyval.tmp_id) = (yyvsp[-2].tmp_id);
                                }
#line 2221 "./parser/Parser.cpp"
    break;

  case 45:
#line 345 "./parser/Parser.y"
                                                                {
                                    (yyvsp[-1].tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id)->GetExtraNode());
                                    (yyvsp[-1].tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id)->GetExtraNode(1));
                                    (yyvsp[0].tmp_id)->NullExtraNode(0);
                                    (yyvsp[0].tmp_id)->NullExtraNode(1);
                                    delete (yyvsp[0].tmp_id);
                                    (yyval.tmp_id) = (yyvsp[-1].tmp_id);
                                }
#line 2234 "./parser/Parser.cpp"
    break;

  case 46:
#line 355 "./parser/Parser.y"
                                                { 
                                       (yyval.tmp_id) = MakeTermNode((yyvsp[0].data)->int_val, INT_NODE_TYPE);            
                                }
#line 2242 "./parser/Parser.cpp"
    break;

  case 47:
#line 358 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeTermNode((yyvsp[0].data)->dou_val, DOUBLE_NODE_TYPE);          
                                }
#line 2250 "./parser/Parser.cpp"
    break;

  case 48:
#line 361 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeTermNode((yyvsp[0].data)->flo_val, FLOAT_NODE_TYPE);            
                                }
#line 2258 "./parser/Parser.cpp"
    break;

  case 49:
#line 364 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeTermNode((string)(yyvsp[0].data)->str_val, STRING_NODE_TYPE);                   
                                }
#line 2266 "./parser/Parser.cpp"
    break;

  case 50:
#line 367 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeTermNode((yyvsp[0].data)->char_val, CHAR_NODE_TYPE);
                                }
#line 2274 "./parser/Parser.cpp"
    break;

  case 51:
#line 370 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeTermNode((yyvsp[0].data)->bol_val, BOOL_NODE_TYPE);
                                }
#line 2282 "./parser/Parser.cpp"
    break;

  case 52:
#line 373 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = (yyvsp[0].tmp_id);       
                                }
#line 2290 "./parser/Parser.cpp"
    break;

  case 53:
#line 376 "./parser/Parser.y"
                                                                           {
                                    (yyval.tmp_id) = MakeArrayTermAst((yyvsp[-2].tmp_id));
                                }
#line 2298 "./parser/Parser.cpp"
    break;

  case 54:
#line 379 "./parser/Parser.y"
                                          {
                                    (yyval.tmp_id) = MakeTermNode(0, ARRAY_NODE_TYPE);
                                }
#line 2306 "./parser/Parser.cpp"
    break;

  case 55:
#line 382 "./parser/Parser.y"
                                                               {
                                    (yyval.tmp_id) = MakeMapTermAst((yyvsp[-1].tmp_id));
                                }
#line 2314 "./parser/Parser.cpp"
    break;

  case 56:
#line 385 "./parser/Parser.y"
                                          {
                                    (yyval.tmp_id) = MakeTermNode(0, MAP_NODE_TYPE);
                                }
#line 2322 "./parser/Parser.cpp"
    break;

  case 57:
#line 390 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types); }
#line 2328 "./parser/Parser.cpp"
    break;

  case 58:
#line 391 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types); }
#line 2334 "./parser/Parser.cpp"
    break;

  case 59:
#line 392 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types); }
#line 2340 "./parser/Parser.cpp"
    break;

  case 60:
#line 393 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types); }
#line 2346 "./parser/Parser.cpp"
    break;

  case 61:
#line 394 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types); }
#line 2352 "./parser/Parser.cpp"
    break;

  case 62:
#line 395 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types); }
#line 2358 "./parser/Parser.cpp"
    break;

  case 63:
#line 396 "./parser/Parser.y"
                                       {
                                    (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types);
                                }
#line 2366 "./parser/Parser.cpp"
    break;

  case 64:
#line 399 "./parser/Parser.y"
                                      {
                                    (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types);
                                }
#line 2374 "./parser/Parser.cpp"
    break;

  case 65:
#line 404 "./parser/Parser.y"
                                                                            {
                                   (yyval.tmp_id) = (yyvsp[-4].tmp_id);
                                   (yyval.tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id));
                                }
#line 2383 "./parser/Parser.cpp"
    break;

  case 66:
#line 408 "./parser/Parser.y"
                                                                           {
                                    (yyval.tmp_id) = (yyvsp[-4].tmp_id);
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id));
                                }
#line 2392 "./parser/Parser.cpp"
    break;

  case 71:
#line 418 "./parser/Parser.y"
                                   {
                                    (yyval.tmp_id) = MakeTermNode((string)(yyvsp[0].data)->id, ID_NODE_TYPE);
                                }
#line 2400 "./parser/Parser.cpp"
    break;

  case 72:
#line 422 "./parser/Parser.y"
                                                                                                    {
                                    (yyval.tmp_id) = MakeAssignAst((yyvsp[-8].tmp_id), (yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2408 "./parser/Parser.cpp"
    break;

  case 73:
#line 425 "./parser/Parser.y"
                                                                              {
                                    (yyval.tmp_id) = MakeAssignAst((yyvsp[-4].tmp_id), nullptr, (yyvsp[-2].tmp_id));
                                }
#line 2416 "./parser/Parser.cpp"
    break;

  case 74:
#line 428 "./parser/Parser.y"
                                                                                                   {
                                    (yyval.tmp_id) = MakeAssignAst((yyvsp[-8].tmp_id), (yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2424 "./parser/Parser.cpp"
    break;

  case 75:
#line 431 "./parser/Parser.y"
                                                                                                        {
                                    (yyval.tmp_id) = MakeUnionAst((yyvsp[-8].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2432 "./parser/Parser.cpp"
    break;

  case 76:
#line 434 "./parser/Parser.y"
                                                                                                     {
                                    (yyval.tmp_id) = MakeUnionAst((yyvsp[-8].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2440 "./parser/Parser.cpp"
    break;

  case 77:
#line 437 "./parser/Parser.y"
                                                                                                                   {
                                    (yyval.tmp_id) = MakeUnionAst((yyvsp[-10].tmp_id), (yyvsp[-5].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2448 "./parser/Parser.cpp"
    break;

  case 78:
#line 440 "./parser/Parser.y"
                                                                                                                {
                                    (yyval.tmp_id) = MakeUnionAst((yyvsp[-10].tmp_id), (yyvsp[-5].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2456 "./parser/Parser.cpp"
    break;

  case 79:
#line 443 "./parser/Parser.y"
                                                                           {
                                   (yyval.tmp_id) = MakeReassignAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2464 "./parser/Parser.cpp"
    break;

  case 80:
#line 446 "./parser/Parser.y"
                                                                                                                         {
                                    (yyval.tmp_id) = MakeRefAst((yyvsp[-12].tmp_id), (yyvsp[-7].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2472 "./parser/Parser.cpp"
    break;

  case 81:
#line 449 "./parser/Parser.y"
                                                                                                                      {
                                    (yyval.tmp_id) = MakeRefAst((yyvsp[-12].tmp_id), (yyvsp[-7].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2480 "./parser/Parser.cpp"
    break;

  case 82:
#line 452 "./parser/Parser.y"
                                                                                              {
                                    (yyval.tmp_id) = MakeRebindRefAst((yyvsp[-8].tmp_id), (yyvsp[-3].tmp_id));
                                }
#line 2488 "./parser/Parser.cpp"
    break;

  case 83:
#line 458 "./parser/Parser.y"
                                           {
                                    (yyval.tmp_id) = new AstNode();
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id));
                                }
#line 2497 "./parser/Parser.cpp"
    break;

  case 84:
#line 462 "./parser/Parser.y"
                                                   {
                                    (yyval.tmp_id) = new AstNode();
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id));
                                }
#line 2506 "./parser/Parser.cpp"
    break;

  case 85:
#line 466 "./parser/Parser.y"
                                                             {  
                                    (yyvsp[-2].tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id));
                                    (yyval.tmp_id) = (yyvsp[-2].tmp_id);
                                }
#line 2515 "./parser/Parser.cpp"
    break;

  case 86:
#line 470 "./parser/Parser.y"
                                                                  {
                                    (yyvsp[-2].tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id));
                                    (yyval.tmp_id) = (yyvsp[-2].tmp_id);
                                }
#line 2524 "./parser/Parser.cpp"
    break;

  case 91:
#line 480 "./parser/Parser.y"
                                                                            { 
                                    (yyval.tmp_id) = MakePrintAst((yyvsp[-2].tmp_id));
                                }
#line 2532 "./parser/Parser.cpp"
    break;

  case 92:
#line 483 "./parser/Parser.y"
                                                     { Destroy(); return 0; (yyval.tmp_id) = nullptr; }
#line 2538 "./parser/Parser.cpp"
    break;

  case 93:
#line 488 "./parser/Parser.y"
                                                                        {
                                    Perform((yyval.tmp_id), (yyvsp[-2].tmp_id), ADDITION_CMD);
                                }
#line 2546 "./parser/Parser.cpp"
    break;

  case 94:
#line 491 "./parser/Parser.y"
                                                                         {
                                    Perform((yyval.tmp_id), (yyvsp[-2].tmp_id), SUBTRACTION_CMD);
                                }
#line 2554 "./parser/Parser.cpp"
    break;

  case 95:
#line 494 "./parser/Parser.y"
                                                                          {
                                    Perform((yyval.tmp_id), (yyvsp[-2].tmp_id), MULTIPLY_CMD);
                                }
#line 2562 "./parser/Parser.cpp"
    break;

  case 96:
#line 497 "./parser/Parser.y"
                                                                          {
                                    Perform((yyval.tmp_id), (yyvsp[-2].tmp_id), DIVIDE_CMD);
                                }
#line 2570 "./parser/Parser.cpp"
    break;

  case 97:
#line 500 "./parser/Parser.y"
                                                                          {
                                    Perform((yyval.tmp_id), (yyvsp[-2].tmp_id), POW_CMD);
                                }
#line 2578 "./parser/Parser.cpp"
    break;

  case 98:
#line 503 "./parser/Parser.y"
                                                                        {
                                    (yyval.tmp_id) = MakeIncAst((yyvsp[-2].tmp_id));
                                }
#line 2586 "./parser/Parser.cpp"
    break;

  case 99:
#line 506 "./parser/Parser.y"
                                                                                                {
                                    (yyval.tmp_id) = MakeModAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2594 "./parser/Parser.cpp"
    break;

  case 100:
#line 514 "./parser/Parser.y"
                                                                                           {
                                    (yyval.tmp_id) = MakeLessCompAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2602 "./parser/Parser.cpp"
    break;

  case 101:
#line 517 "./parser/Parser.y"
                                                                                                {
                                    (yyval.tmp_id) = MakeGreaterCompAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2610 "./parser/Parser.cpp"
    break;

  case 102:
#line 520 "./parser/Parser.y"
                                                                                                  {
                                    (yyval.tmp_id) = MakeLessEqualCompAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2618 "./parser/Parser.cpp"
    break;

  case 103:
#line 523 "./parser/Parser.y"
                                                                                                      {
                                    (yyval.tmp_id) = MakeGreaterEqualCompAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2626 "./parser/Parser.cpp"
    break;

  case 104:
#line 526 "./parser/Parser.y"
                                                                                             {
                                    (yyval.tmp_id) = MakeEqualCompAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2634 "./parser/Parser.cpp"
    break;

  case 105:
#line 529 "./parser/Parser.y"
                                                                                                  {
                                    (yyval.tmp_id) = MakeNotEqualCompAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2642 "./parser/Parser.cpp"
    break;

  case 106:
#line 536 "./parser/Parser.y"
                                                                                         {
                                    (yyval.tmp_id) = MakeAndAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2650 "./parser/Parser.cpp"
    break;

  case 107:
#line 539 "./parser/Parser.y"
                                                                 {
                                    (yyval.tmp_id) = MakeNotAst((yyvsp[-2].tmp_id));
                                }
#line 2658 "./parser/Parser.cpp"
    break;

  case 108:
#line 542 "./parser/Parser.y"
                                                                                           {
                                    (yyval.tmp_id) = MakeOrAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2666 "./parser/Parser.cpp"
    break;

  case 109:
#line 548 "./parser/Parser.y"
                                                                                      {
                                    (yyval.tmp_id) = MakeGetFromCollectionAst((yyvsp[-3].tmp_id), (yyvsp[-1].tmp_id));
                                }
#line 2674 "./parser/Parser.cpp"
    break;

  case 110:
#line 554 "./parser/Parser.y"
                                     {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2682 "./parser/Parser.cpp"
    break;

  case 111:
#line 557 "./parser/Parser.y"
                                            {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2690 "./parser/Parser.cpp"
    break;

  case 112:
#line 560 "./parser/Parser.y"
                                                                                          {
                                    (yyval.tmp_id) = MakeCastAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2698 "./parser/Parser.cpp"
    break;

  case 113:
#line 563 "./parser/Parser.y"
                                               {
                                   (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2706 "./parser/Parser.cpp"
    break;

  case 114:
#line 566 "./parser/Parser.y"
                                           {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2714 "./parser/Parser.cpp"
    break;

  case 115:
#line 569 "./parser/Parser.y"
                                                                                           {
                                     (yyval.tmp_id) = MakeAddToListAst((yyvsp[-7].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2722 "./parser/Parser.cpp"
    break;

  case 116:
#line 572 "./parser/Parser.y"
                                                                                                          {
                                    (yyval.tmp_id) = MakeAddToMapAst((yyvsp[-9].tmp_id), (yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2730 "./parser/Parser.cpp"
    break;

  case 117:
#line 575 "./parser/Parser.y"
                                                {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2738 "./parser/Parser.cpp"
    break;

  case 118:
#line 578 "./parser/Parser.y"
                                                                                                            {
                                    (yyval.tmp_id) = MakeSetInCollectionAst((yyvsp[-9].tmp_id), (yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2746 "./parser/Parser.cpp"
    break;

  case 119:
#line 581 "./parser/Parser.y"
                                                      {
                                    (yyval.tmp_id) = MakeCollectionSizeAst((yyvsp[-2].tmp_id));
                                }
#line 2754 "./parser/Parser.cpp"
    break;

  case 120:
#line 584 "./parser/Parser.y"
                                                                       {
                                    (yyval.tmp_id) = MakeQueryContainerCmd((yyvsp[-5].tmp_id), (yyvsp[-1].tmp_id));
                                }
#line 2762 "./parser/Parser.cpp"
    break;

  case 121:
#line 587 "./parser/Parser.y"
                                                                           {
                                    (yyval.tmp_id) = MakeRemoveFromContainerCmd((yyvsp[-5].tmp_id), (yyvsp[-1].tmp_id));
                                }
#line 2770 "./parser/Parser.cpp"
    break;

  case 122:
#line 590 "./parser/Parser.y"
                                                                          {
                                    (yyval.tmp_id) = MakeNode(GET_TYPE_CMD);
                                    (yyval.tmp_id)->AddToLeftNodes((yyvsp[-2].tmp_id));
                                }
#line 2779 "./parser/Parser.cpp"
    break;

  case 123:
#line 594 "./parser/Parser.y"
                                                        {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2787 "./parser/Parser.cpp"
    break;

  case 124:
#line 597 "./parser/Parser.y"
                                               { (yyval.tmp_id) = (yyvsp[0].tmp_id); }
#line 2793 "./parser/Parser.cpp"
    break;

  case 125:
#line 598 "./parser/Parser.y"
                                                                           {
                                    (yyval.tmp_id) = MakeNode(INPUT_USER_DATA_CMD);
                                    (yyval.tmp_id)->AddToLeftNodes((yyvsp[-2].tmp_id));
                                }
#line 2802 "./parser/Parser.cpp"
    break;

  case 126:
#line 604 "./parser/Parser.y"
                                     { i.EatAst((yyvsp[0].tmp_id)); (yyvsp[0].tmp_id) = nullptr; }
#line 2808 "./parser/Parser.cpp"
    break;

  case 127:
#line 605 "./parser/Parser.y"
                                            { i.EatAst((yyvsp[0].tmp_id)); (yyvsp[0].tmp_id) = nullptr; }
#line 2814 "./parser/Parser.cpp"
    break;

  case 135:
#line 613 "./parser/Parser.y"
                                       {
                                    Destroy();
                                    return 0;
                                }
#line 2823 "./parser/Parser.cpp"
    break;

  case 136:
#line 617 "./parser/Parser.y"
                                        { return 0; }
#line 2829 "./parser/Parser.cpp"
    break;


#line 2833 "./parser/Parser.cpp"

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
#line 620 "./parser/Parser.y"



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
