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
    INT_VAL = 310,
    DOUBLE_VAL = 311,
    STRING_VAL = 312,
    CHAR_VAL = 313,
    BOOL_VAL = 314,
    ELSE_IF = 315,
    FLOAT_VAL = 316,
    ID = 317,
    UNKNOWN = 318,
    MULTI_WS = 319,
    SINGLE_WS = 320
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 34 "./parser/Parser.y"

    YYSTYPEs *data;
    AstNode *tmp_id;

#line 225 "./parser/Parser.cpp"

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
#define YYFINAL  103
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1271

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  76
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  136
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  432

#define YYUNDEFTOK  2
#define YYMAXUTOK   320


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
      68,    69,     2,     2,     2,     2,    75,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    66,     2,
       2,    74,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    70,     2,    71,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    72,    67,    73,     2,     2,     2,     2,
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
      65
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   133,   133,   135,   137,   141,   145,   149,   153,   167,
     176,   183,   190,   198,   201,   204,   209,   216,   225,   232,
     243,   249,   254,   265,   266,   267,   268,   268,   270,   274,
     280,   283,   286,   289,   293,   298,   298,   300,   301,   302,
     305,   312,   320,   328,   336,   344,   354,   357,   360,   363,
     366,   369,   372,   375,   378,   381,   384,   389,   390,   391,
     392,   393,   394,   395,   398,   403,   407,   413,   413,   415,
     415,   417,   421,   424,   427,   430,   433,   436,   439,   442,
     445,   448,   454,   458,   462,   466,   472,   473,   473,   475,
     476,   479,   484,   487,   490,   493,   496,   499,   502,   510,
     513,   516,   519,   522,   525,   532,   535,   538,   544,   550,
     553,   556,   559,   562,   565,   568,   571,   574,   577,   580,
     583,   586,   590,   593,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   609,   611,   611
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
  "INT_VAL", "DOUBLE_VAL", "STRING_VAL", "CHAR_VAL", "BOOL_VAL", "ELSE_IF",
  "FLOAT_VAL", "ID", "UNKNOWN", "MULTI_WS", "SINGLE_WS", "':'", "'|'",
  "'('", "')'", "'['", "']'", "'{'", "'}'", "'='", "'.'", "$accept",
  "start", "end", "ifHead", "elseIfHead", "elseHead", "whileHead",
  "forloopHead", "paramList", "funcType", "functionHead", "funcRet",
  "functionCall", "ifBody", "elseIfBody", "elseBody", "elseIfChain",
  "whileStatement", "forloopStatement", "ifStatement",
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
     315,   316,   317,   318,   319,   320,    58,   124,    40,    41,
      91,    93,   123,   125,    61,    46
};
# endif

#define YYPACT_NINF (-169)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-70)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1199,  -169,    37,   -64,  -169,  -169,  -169,  -169,    37,    37,
      37,  -169,  -169,  -169,    37,  -169,  -169,  -169,  -169,  -169,
    -169,  -169,  -169,  -169,   314,    29,   -60,  1199,  1199,  1199,
    1199,    37,  1199,  -169,  -169,    28,  -169,  -169,  -169,  -169,
    -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,
     -24,  -169,   569,  -169,    -7,    37,   237,   237,   237,   237,
      37,    37,    37,    37,    37,    37,    37,    37,    37,    37,
      37,    37,    37,    37,    37,    37,    37,    37,    37,    37,
      37,    37,  -169,    50,  -169,   173,  -169,    11,   936,   794,
     995,  1046,    21,  1097,  -169,    37,    37,  1199,  1199,  -169,
      45,    38,   107,  -169,  -169,    37,    25,   640,    71,    71,
      71,   -24,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   153,    37,   237,    37,    37,    37,    37,   237,
     237,    21,    21,    21,   237,    21,    37,    37,  -169,    37,
     -15,   -28,  -169,  -169,  -169,  -169,    37,  -169,    61,   237,
     859,  1148,  -169,  -169,  -169,    69,    43,    46,    48,  -169,
      53,    81,    37,  -169,   103,   118,   108,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,   -24,   237,   237,
      93,   -24,    97,   102,   116,   117,    71,    71,    37,    37,
      37,    71,    37,  -169,   173,   173,   101,   173,    37,  -169,
    -169,    -3,   110,  -169,    71,  -169,    37,    37,    37,   237,
     237,   128,  -169,  -169,    37,   481,   237,   237,   237,   237,
     237,   237,   237,   237,   125,   -24,   -24,  -169,  -169,  -169,
    -169,  -169,   129,   237,   237,    87,   134,   131,   138,   372,
     147,  -169,  -169,  -169,    37,  -169,    37,  -169,   244,   133,
     237,   237,   237,   -29,     0,  -169,    21,  -169,  -169,  -169,
    -169,  -169,  -169,  -169,  -169,    37,    71,    71,    71,    71,
      71,    71,    71,    71,  -169,  -169,    71,   -17,    37,  -169,
      37,  -169,    22,    71,    37,   173,  -169,   115,    37,  -169,
     150,  -169,    71,    71,    71,  -169,  -169,    37,   148,   151,
     155,   158,   167,   168,   170,   172,   186,   187,  -169,   189,
      19,    37,   191,    27,    37,    37,   207,   122,   195,    37,
     206,   237,   237,   240,  -169,  -169,  -169,  -169,  -169,  -169,
    -169,  -169,  -169,  -169,  -169,    37,   481,   481,    37,   237,
    -169,    37,   481,   481,    37,   209,   481,  -169,  -169,   156,
     127,   481,  -169,    71,    71,  -169,   237,    37,    90,    37,
     237,   -10,   237,    99,    37,   237,  -169,    37,    37,    37,
     242,  -169,   212,   213,    71,   220,    37,   221,   263,    71,
      37,    71,    37,   265,    71,   262,   481,   481,  -169,  -169,
    -169,   231,    37,   237,    37,   228,   233,   234,   235,   237,
     241,   239,  -169,  -169,    37,  -169,   481,    71,   481,    37,
    -169,  -169,  -169,    71,    37,  -169,   275,  -169,   246,  -169,
     237,   247,   237,  -169,  -169,    71,  -169,    71,   249,   250,
    -169,  -169
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   134,    70,     0,    35,    36,   133,     2,     0,     0,
       0,    13,    14,    15,     0,    46,    47,    49,    50,    51,
      48,    71,    67,    68,     0,    70,    70,     0,     0,     0,
       0,     0,     0,   132,   123,     0,   127,   128,   126,   122,
     131,   109,   130,    52,    89,   125,   110,   112,   113,   116,
     124,   135,     0,    69,     0,    70,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,    70,    70,    70,    70,     0,     0,     0,     0,    70,
       0,    70,    54,    87,    88,     0,    56,     0,     0,     0,
       0,     0,     0,     0,    30,     0,     0,     0,     0,    26,
       0,     0,     0,     1,   136,    70,     0,     0,     0,     0,
       0,    20,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,     0,    70,    70,    70,    70,     0,
       0,     0,     0,     0,     0,     0,    70,    70,    37,    70,
       0,     0,     3,   129,    28,    29,    70,    34,     0,     0,
       0,     0,    33,    31,    27,     0,     0,     0,     0,   118,
       0,     0,    70,    91,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    70,    82,    69,    88,
       0,    83,     0,     0,     0,     0,    70,     0,     0,    70,
      70,    70,    70,    86,    69,    88,     0,     0,    70,    42,
      55,    45,     0,     6,     0,    32,    70,    70,    70,     0,
       0,     0,     4,     7,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,    85,    92,    93,    94,
      95,    96,     0,     0,     0,    70,     0,     0,     0,    69,
       0,    38,    39,    53,     0,    41,    70,    44,     0,     0,
       0,     0,     0,     0,     0,    90,     0,    57,    58,    59,
      60,    61,    62,    63,    64,    70,    70,    70,    70,    70,
      70,    70,    70,    70,   106,    97,    70,     0,    70,    21,
      70,   121,    70,    70,    70,     0,    43,     0,    70,    10,
       0,     5,    70,     0,     0,   119,   120,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   108,     0,
       0,     0,     0,     0,    70,    70,     0,    69,     0,    70,
       0,     0,     0,     0,   111,    99,   100,   101,   102,   103,
     104,   105,   107,    98,    22,     0,     0,     0,     0,     0,
      78,     0,     0,     0,     0,     0,     0,    18,    12,     0,
       0,     0,   114,    70,    70,     8,     0,    70,    70,     0,
       0,     0,     0,    70,     0,     0,    40,     0,    70,    70,
       0,     9,     0,     0,    70,     0,     0,     0,     0,    70,
      70,    70,     0,     0,    70,     0,     0,     0,    19,   115,
     117,     0,    70,     0,    70,     0,     0,     0,     0,     0,
       0,     0,    16,    11,     0,    74,     0,    70,     0,     0,
      72,    81,    75,    70,     0,    73,     0,    65,     0,    66,
       0,     0,     0,    17,    76,    70,    77,    70,     0,     0,
      79,    80
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,
    -169,  -169,  -169,  -169,   219,   222,  -169,  -169,  -169,  -169,
    -169,  -169,  -169,   180,  -169,   -83,  -168,   -20,   385,    -2,
     -91,  -169,   -62,   -19,    -4,  -169,  -169,  -169,  -169,  -169,
     587,   -34,   -13
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    27,   143,    28,    97,    98,    29,    30,   288,    31,
      32,    33,    34,    35,    99,   100,   101,    36,    37,    38,
      39,    40,   137,   140,   141,    41,   357,   358,    53,    83,
      43,    44,   123,   124,    87,    45,    46,    47,    48,    49,
      50,    51,    52
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      54,   146,   138,    55,    22,    23,    84,    84,   198,   125,
     126,   127,   128,    86,    88,    89,    90,    91,   104,    93,
     246,    85,   257,   258,   259,   260,   261,   262,   263,   264,
     257,   258,   259,   260,   261,   262,   263,   264,   295,   139,
     188,   189,   190,   162,   192,   200,   102,   265,   311,    22,
      23,   102,   308,   106,   104,   104,   104,   104,   102,   104,
     105,    22,    23,   380,    94,   102,    95,   296,   122,   122,
     122,   122,   122,   136,   153,   102,    95,   133,   139,   135,
     289,   152,   335,    21,   150,   151,    22,    23,    96,   336,
     341,   337,   163,    22,    23,    86,   203,   342,    96,   343,
      82,    22,    23,   122,   179,   205,   179,   179,   179,   179,
     206,   241,   242,   207,   244,   208,   104,   104,   195,   180,
     209,   182,   183,   184,   185,   257,   258,   259,   260,   261,
     262,   263,   264,   196,   193,    22,    23,   197,   212,   156,
     157,   158,   338,   179,   202,   344,   102,   159,   210,   348,
     214,    22,    23,   213,    22,    23,   -69,   290,   211,   160,
     161,   376,   227,    22,    23,   297,   228,    84,   291,   359,
     382,   229,   243,   278,   224,   364,   136,   248,   367,    22,
      23,   315,   232,   371,    21,   230,   231,   236,   237,   238,
     240,    22,    23,   369,   274,   255,   245,   280,   275,    11,
      12,    13,   314,   279,   250,   251,   252,   281,    15,    16,
      17,    18,    19,   284,    20,    21,   319,   324,   403,   404,
     325,   107,   368,    25,   326,    26,   349,   327,    15,    16,
      17,    18,    19,   122,    20,    21,   328,   329,   417,   330,
     419,   331,   347,    25,   286,    26,    84,   257,   258,   259,
     260,   261,   262,   263,   264,   332,   333,    84,   334,   179,
     340,   298,   350,    84,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   352,   309,   355,   366,   388,   310,   389,
     390,   312,   313,    11,    12,    13,   318,   392,   394,   395,
     320,   400,    15,    16,    17,    18,    19,   402,    20,    21,
     405,   409,   410,   411,   412,   107,    21,    25,   415,    26,
     423,   287,   345,   346,   414,   424,   426,   351,   430,   431,
     154,   201,   363,   155,     0,    60,    61,    62,    63,    64,
      65,    66,     0,    67,    68,    69,     0,     0,     0,     0,
       0,    70,    71,    72,    73,    74,     0,     0,     0,     0,
       0,   372,   373,     0,     0,   375,   377,    75,    76,    77,
       0,   377,     0,    78,    79,     0,   386,   387,    80,     0,
       0,     0,   391,     0,     0,     0,     0,   396,   397,   398,
       0,     0,   401,     0,     0,    42,     0,     0,    81,     0,
     406,     0,   408,    56,    57,    58,     0,     0,     0,    59,
       0,     0,     0,     0,     0,   418,     0,     0,     0,     0,
       0,   421,    42,    42,    42,    42,    92,    42,    11,    12,
      13,     0,     0,   428,     0,   429,     0,    15,    16,    17,
      18,    19,     0,    20,    21,     0,     0,    42,     0,     0,
     107,     0,    25,     0,   282,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,     0,     0,     0,     0,     0,
     129,   130,   131,   132,     0,   134,     0,     0,     0,     0,
       0,     0,     0,    42,    42,    42,    42,     0,    42,     0,
     148,   149,    42,    42,   257,   258,   259,   260,   261,   262,
     263,   264,     0,   164,   165,   166,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   178,     0,
     178,   178,   178,   178,     0,     0,     0,     0,     0,     0,
       0,     0,   194,     0,     0,   199,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    42,    42,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   178,     0,     0,
       0,     0,   215,   216,   217,   218,   219,   220,   221,   222,
     223,     0,     0,     0,     0,     0,     0,     0,     0,   103,
       1,     0,   233,   234,   235,     0,     0,   239,     0,     0,
       0,     0,     0,     0,     0,     0,   247,     2,     0,   249,
       0,     3,     4,     5,     6,     0,     0,     0,     0,   256,
       0,     0,     0,     0,     7,     0,     8,     0,     9,     0,
      10,     0,     0,     0,     0,    11,    12,    13,     0,     0,
      14,     0,     0,     0,    15,    16,    17,    18,    19,   285,
      20,    21,     0,    22,    23,     0,     0,    24,     0,    25,
       0,    26,     0,   108,   109,   110,   111,     0,     0,     0,
       0,    60,    61,    62,    63,    64,    65,    66,     0,    67,
      68,    69,     0,   178,     0,     0,     0,    70,    71,    72,
      73,    74,   316,   317,     0,     0,     0,     0,   321,   322,
       0,     0,   323,    75,    76,    77,     0,     0,     0,    78,
       0,     0,     0,     0,    80,     0,   339,     0,     0,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
       0,   181,     0,     0,     0,     0,   186,   187,     0,     0,
     356,   191,     0,   360,     0,     0,   362,     0,     0,   365,
       0,     0,     0,     0,     0,   370,   204,     0,     0,     0,
       0,     0,     0,     0,   378,     0,     0,     0,     0,   383,
       0,     0,   385,     0,     0,     0,     0,     0,     0,     0,
       0,   393,     0,     0,     0,   225,   226,   399,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   416,
       0,     0,     0,     0,   420,     1,   253,   254,     0,   422,
       0,     0,     0,   266,   267,   268,   269,   270,   271,   272,
     273,     0,     2,     0,     0,     0,     3,     4,     5,     6,
     276,   277,     0,     0,     0,     0,   283,     0,     0,     7,
     -23,     8,   -23,     9,     0,    10,     0,   292,   293,   294,
      11,    12,    13,     0,     0,    14,     0,     0,     0,    15,
      16,    17,    18,    19,   -23,    20,    21,     0,    22,    23,
       1,     0,    24,     0,    25,     0,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     2,     0,     0,
       0,     3,     4,     5,     6,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,   -24,     8,   -24,     9,     0,
      10,     0,     0,     0,     0,    11,    12,    13,   353,   354,
      14,     0,     0,     0,    15,    16,    17,    18,    19,   -24,
      20,    21,     0,    22,    23,     0,   361,    24,     0,    25,
       0,    26,     0,     0,     0,     0,     0,     1,     0,     0,
       0,     0,     0,   374,     0,     0,     0,   379,     0,   381,
       0,     0,   384,     0,     2,     0,     0,     0,     3,     4,
       5,     6,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,   142,     8,     0,     9,     0,    10,     0,     0,
     407,     0,    11,    12,    13,     0,   413,    14,     0,     0,
       0,    15,    16,    17,    18,    19,     1,    20,    21,     0,
      22,    23,     0,     0,    24,     0,    25,   425,    26,   427,
       0,     0,     0,     2,     0,     0,     0,     3,     4,     5,
       6,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,   144,     8,     0,     9,     0,    10,     0,     0,     0,
       0,    11,    12,    13,     0,     0,    14,     1,     0,     0,
      15,    16,    17,    18,    19,     0,    20,    21,     0,    22,
      23,     0,     0,    24,     2,    25,     0,    26,     3,     4,
       5,     6,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,   145,     8,     0,     9,     0,    10,     0,     0,
       0,     0,    11,    12,    13,     0,     0,    14,     1,     0,
       0,    15,    16,    17,    18,    19,     0,    20,    21,     0,
      22,    23,     0,     0,    24,     2,    25,     0,    26,     3,
       4,     5,     6,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,   147,     8,     0,     9,     0,    10,     0,
       0,     0,     0,    11,    12,    13,     0,     0,    14,     1,
       0,     0,    15,    16,    17,    18,    19,     0,    20,    21,
       0,    22,    23,     0,     0,    24,     2,    25,     0,    26,
       3,     4,     5,     6,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,   -25,     8,     0,     9,     0,    10,
       0,     0,     0,     0,    11,    12,    13,     0,     0,    14,
       1,     0,     0,    15,    16,    17,    18,    19,     0,    20,
      21,     0,    22,    23,     0,     0,    24,     2,    25,     0,
      26,     3,     4,     5,     6,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     0,     8,     0,     9,     0,
      10,     0,     0,     0,     0,    11,    12,    13,     0,     0,
      14,     0,     0,     0,    15,    16,    17,    18,    19,     0,
      20,    21,     0,    22,    23,     0,     0,    24,     0,    25,
       0,    26
};

static const yytype_int16 yycheck[] =
{
       2,    92,    85,    67,    64,    65,    25,    26,    23,    71,
      72,    73,    74,    73,    27,    28,    29,    30,    52,    32,
      23,    25,     3,     4,     5,     6,     7,     8,     9,    10,
       3,     4,     5,     6,     7,     8,     9,    10,    67,    67,
     131,   132,   133,   105,   135,    73,    75,   215,    26,    64,
      65,    75,    69,    55,    88,    89,    90,    91,    75,    93,
      67,    64,    65,    73,    36,    75,    38,    67,    70,    71,
      72,    73,    74,    23,    36,    75,    38,    79,    67,    81,
     248,    36,    63,    62,    97,    98,    64,    65,    60,    70,
      63,    72,    67,    64,    65,    73,    35,    70,    60,    72,
      71,    64,    65,   105,   123,    36,   125,   126,   127,   128,
      67,   194,   195,    67,   197,    67,   150,   151,   137,   123,
      67,   125,   126,   127,   128,     3,     4,     5,     6,     7,
       8,     9,    10,   137,   136,    64,    65,   139,    35,    32,
      33,    34,   310,   162,   146,   313,    75,    40,    67,   317,
      42,    64,    65,    35,    64,    65,    69,   248,   162,    52,
      53,    71,    69,    64,    65,   256,    69,   186,    35,   337,
      71,    69,    71,   235,   176,   343,    23,    67,   346,    64,
      65,    66,   186,   351,    62,    69,    69,   189,   190,   191,
     192,    64,    65,    66,    69,    67,   198,    66,    69,    46,
      47,    48,   285,    69,   206,   207,   208,    69,    55,    56,
      57,    58,    59,    66,    61,    62,    66,    69,   386,   387,
      69,    68,    66,    70,    69,    72,   317,    69,    55,    56,
      57,    58,    59,   235,    61,    62,    69,    69,   406,    69,
     408,    69,    35,    70,   246,    72,   265,     3,     4,     5,
       6,     7,     8,     9,    10,    69,    69,   276,    69,   278,
      69,   265,    67,   282,   266,   267,   268,   269,   270,   271,
     272,   273,   276,    67,   278,    35,    67,    35,   280,    67,
      67,   283,   284,    46,    47,    48,   288,    67,    67,    26,
     292,    26,    55,    56,    57,    58,    59,    35,    61,    62,
      69,    73,    69,    69,    69,    68,    62,    70,    69,    72,
      35,    67,   314,   315,    73,    69,    69,   319,    69,    69,
     101,   141,   342,   101,    -1,    11,    12,    13,    14,    15,
      16,    17,    -1,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    -1,    -1,    -1,    -1,
      -1,   353,   354,    -1,    -1,   357,   358,    43,    44,    45,
      -1,   363,    -1,    49,    50,    -1,   368,   369,    54,    -1,
      -1,    -1,   374,    -1,    -1,    -1,    -1,   379,   380,   381,
      -1,    -1,   384,    -1,    -1,     0,    -1,    -1,    74,    -1,
     392,    -1,   394,     8,     9,    10,    -1,    -1,    -1,    14,
      -1,    -1,    -1,    -1,    -1,   407,    -1,    -1,    -1,    -1,
      -1,   413,    27,    28,    29,    30,    31,    32,    46,    47,
      48,    -1,    -1,   425,    -1,   427,    -1,    55,    56,    57,
      58,    59,    -1,    61,    62,    -1,    -1,    52,    -1,    -1,
      68,    -1,    70,    -1,    72,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,
      75,    76,    77,    78,    -1,    80,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    89,    90,    91,    -1,    93,    -1,
      95,    96,    97,    98,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,   108,   109,   110,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,    -1,
     125,   126,   127,   128,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   137,    -1,    -1,   140,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   150,   151,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,    -1,    -1,
      -1,    -1,   167,   168,   169,   170,   171,   172,   173,   174,
     175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,
       1,    -1,   187,   188,   189,    -1,    -1,   192,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   201,    18,    -1,   204,
      -1,    22,    23,    24,    25,    -1,    -1,    -1,    -1,   214,
      -1,    -1,    -1,    -1,    35,    -1,    37,    -1,    39,    -1,
      41,    -1,    -1,    -1,    -1,    46,    47,    48,    -1,    -1,
      51,    -1,    -1,    -1,    55,    56,    57,    58,    59,   244,
      61,    62,    -1,    64,    65,    -1,    -1,    68,    -1,    70,
      -1,    72,    -1,    56,    57,    58,    59,    -1,    -1,    -1,
      -1,    11,    12,    13,    14,    15,    16,    17,    -1,    19,
      20,    21,    -1,   278,    -1,    -1,    -1,    27,    28,    29,
      30,    31,   287,   288,    -1,    -1,    -1,    -1,   293,   294,
      -1,    -1,   297,    43,    44,    45,    -1,    -1,    -1,    49,
      -1,    -1,    -1,    -1,    54,    -1,   311,    -1,    -1,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
      -1,   124,    -1,    -1,    -1,    -1,   129,   130,    -1,    -1,
     335,   134,    -1,   338,    -1,    -1,   341,    -1,    -1,   344,
      -1,    -1,    -1,    -1,    -1,   350,   149,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   359,    -1,    -1,    -1,    -1,   364,
      -1,    -1,   367,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   376,    -1,    -1,    -1,   178,   179,   382,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   404,
      -1,    -1,    -1,    -1,   409,     1,   209,   210,    -1,   414,
      -1,    -1,    -1,   216,   217,   218,   219,   220,   221,   222,
     223,    -1,    18,    -1,    -1,    -1,    22,    23,    24,    25,
     233,   234,    -1,    -1,    -1,    -1,   239,    -1,    -1,    35,
      36,    37,    38,    39,    -1,    41,    -1,   250,   251,   252,
      46,    47,    48,    -1,    -1,    51,    -1,    -1,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    -1,    64,    65,
       1,    -1,    68,    -1,    70,    -1,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,
      -1,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,    -1,
      41,    -1,    -1,    -1,    -1,    46,    47,    48,   321,   322,
      51,    -1,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    -1,    64,    65,    -1,   339,    68,    -1,    70,
      -1,    72,    -1,    -1,    -1,    -1,    -1,     1,    -1,    -1,
      -1,    -1,    -1,   356,    -1,    -1,    -1,   360,    -1,   362,
      -1,    -1,   365,    -1,    18,    -1,    -1,    -1,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    37,    -1,    39,    -1,    41,    -1,    -1,
     393,    -1,    46,    47,    48,    -1,   399,    51,    -1,    -1,
      -1,    55,    56,    57,    58,    59,     1,    61,    62,    -1,
      64,    65,    -1,    -1,    68,    -1,    70,   420,    72,   422,
      -1,    -1,    -1,    18,    -1,    -1,    -1,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,    37,    -1,    39,    -1,    41,    -1,    -1,    -1,
      -1,    46,    47,    48,    -1,    -1,    51,     1,    -1,    -1,
      55,    56,    57,    58,    59,    -1,    61,    62,    -1,    64,
      65,    -1,    -1,    68,    18,    70,    -1,    72,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    37,    -1,    39,    -1,    41,    -1,    -1,
      -1,    -1,    46,    47,    48,    -1,    -1,    51,     1,    -1,
      -1,    55,    56,    57,    58,    59,    -1,    61,    62,    -1,
      64,    65,    -1,    -1,    68,    18,    70,    -1,    72,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    36,    37,    -1,    39,    -1,    41,    -1,
      -1,    -1,    -1,    46,    47,    48,    -1,    -1,    51,     1,
      -1,    -1,    55,    56,    57,    58,    59,    -1,    61,    62,
      -1,    64,    65,    -1,    -1,    68,    18,    70,    -1,    72,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    36,    37,    -1,    39,    -1,    41,
      -1,    -1,    -1,    -1,    46,    47,    48,    -1,    -1,    51,
       1,    -1,    -1,    55,    56,    57,    58,    59,    -1,    61,
      62,    -1,    64,    65,    -1,    -1,    68,    18,    70,    -1,
      72,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    -1,    37,    -1,    39,    -1,
      41,    -1,    -1,    -1,    -1,    46,    47,    48,    -1,    -1,
      51,    -1,    -1,    -1,    55,    56,    57,    58,    59,    -1,
      61,    62,    -1,    64,    65,    -1,    -1,    68,    -1,    70,
      -1,    72
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    18,    22,    23,    24,    25,    35,    37,    39,
      41,    46,    47,    48,    51,    55,    56,    57,    58,    59,
      61,    62,    64,    65,    68,    70,    72,    77,    79,    82,
      83,    85,    86,    87,    88,    89,    93,    94,    95,    96,
      97,   101,   104,   106,   107,   111,   112,   113,   114,   115,
     116,   117,   118,   104,   105,    67,   104,   104,   104,   104,
      11,    12,    13,    14,    15,    16,    17,    19,    20,    21,
      27,    28,    29,    30,    31,    43,    44,    45,    49,    50,
      54,    74,    71,   105,   109,   110,    73,   110,   118,   118,
     118,   118,   104,   118,    36,    38,    60,    80,    81,    90,
      91,    92,    75,     0,   117,    67,   105,    68,   116,   116,
     116,   116,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   105,   108,   109,   108,   108,   108,   108,   104,
     104,   104,   104,   105,   104,   105,    23,    98,   101,    67,
      99,   100,    36,    78,    36,    36,   106,    36,   104,   104,
     118,   118,    36,    36,    90,    91,    32,    33,    34,    40,
      52,    53,   108,    67,   104,   104,   104,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   104,   109,
     110,   116,   110,   110,   110,   110,   116,   116,   106,   106,
     106,   116,   106,   105,   104,   109,   110,   105,    23,   104,
      73,    99,   105,    35,   116,    36,    67,    67,    67,    67,
      67,   110,    35,    35,    42,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   105,   116,   116,    69,    69,    69,
      69,    69,   110,   104,   104,   104,   105,   105,   105,   104,
     105,   101,   101,    71,   101,   105,    23,   104,    67,   104,
     105,   105,   105,   116,   116,    67,   104,     3,     4,     5,
       6,     7,     8,     9,    10,   102,   116,   116,   116,   116,
     116,   116,   116,   116,    69,    69,   116,   116,   108,    69,
      66,    69,    72,   116,    66,   104,   105,    67,    84,   102,
     106,    35,   116,   116,   116,    67,    67,   106,   110,   105,
     105,   105,   105,   105,   105,   105,   105,   110,    69,   110,
     105,    26,   105,   105,   101,    66,   104,   104,   105,    66,
     105,   104,   104,   104,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    63,    70,    72,   102,   104,
      69,    63,    70,    72,   102,   105,   105,    35,   102,   106,
      67,   105,    67,   116,   116,    35,   104,   102,   103,   102,
     104,   116,   104,   103,   102,   104,    67,   102,    66,    66,
     104,   102,   105,   105,   116,   105,    71,   105,   104,   116,
      73,   116,    71,   104,   116,   104,   105,   105,    35,    67,
      67,   105,    67,   104,    67,    26,   105,   105,   105,   104,
      26,   105,    35,   102,   102,    69,   105,   116,   105,    73,
      69,    69,    69,   116,    73,    69,   104,   102,   105,   102,
     104,   105,   104,    35,    69,   116,    69,   116,   105,   105,
      69,    69
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      84,    84,    84,    85,    85,    85,    86,    86,    86,    86,
      87,    88,    88,    89,    90,    91,    92,    92,    93,    94,
      95,    95,    95,    95,    96,    97,    97,    98,    98,    98,
      99,   100,   100,   100,   100,   100,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   102,   102,   102,
     102,   102,   102,   102,   102,   103,   103,   104,   104,   105,
     105,   106,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   108,   108,   108,   108,   109,   110,   110,   111,
     111,   111,   112,   112,   112,   112,   112,   112,   112,   113,
     113,   113,   113,   113,   113,   114,   114,   114,   115,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   118,   118
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
       0,     1,    12,    12,    12,    12,    14,    14,     8,    16,
      16,    12,     2,     2,     3,     3,     3,     1,     1,     1,
       6,     4,     5,     5,     5,     5,     5,     6,     8,     8,
       8,     8,     8,     8,     8,     8,     6,     8,     7,     1,
       1,     8,     1,     1,     8,    10,     1,    10,     3,     6,
       6,     6,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     2
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
#line 133 "./parser/Parser.y"
                                      { i.EatAst(MakeStartAst()); }
#line 1847 "./parser/Parser.cpp"
    break;

  case 3:
#line 135 "./parser/Parser.y"
                                    { i.EatAst(MakeEndScopeAst()); }
#line 1853 "./parser/Parser.cpp"
    break;

  case 4:
#line 137 "./parser/Parser.y"
                                                            {
                                    i.EatAst(MakeIfDeclAst((yyvsp[-2].tmp_id)));
                                }
#line 1861 "./parser/Parser.cpp"
    break;

  case 5:
#line 141 "./parser/Parser.y"
                                                                 {
                                    i.EatAst(MakeElifDeclAst((yyvsp[-2].tmp_id)));
                                }
#line 1869 "./parser/Parser.cpp"
    break;

  case 6:
#line 145 "./parser/Parser.y"
                                                 {
                                    i.EatAst(MakeElseDeclAst());
                                }
#line 1877 "./parser/Parser.cpp"
    break;

  case 7:
#line 149 "./parser/Parser.y"
                                                               {
                                    i.EatAst(MakeWhileDeclAst((yyvsp[-2].tmp_id)));
                                }
#line 1885 "./parser/Parser.cpp"
    break;

  case 8:
#line 153 "./parser/Parser.y"
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
#line 1903 "./parser/Parser.cpp"
    break;

  case 9:
#line 167 "./parser/Parser.y"
                                                    {
                                    auto param = MakeNode(FUNC_PARAM_CMD);
                                    param->AddToLeftNodes((yyvsp[-3].tmp_id));
                                    param->AddToRightNodes((yyvsp[0].tmp_id));
                                    auto list = new AstNode();
                                    list->AddToLeftNodes(param);
                                    (yyval.tmp_id) = list;

                                }
#line 1917 "./parser/Parser.cpp"
    break;

  case 10:
#line 176 "./parser/Parser.y"
                                        {
                                    auto param = MakeNode(FUNC_PARAM_CMD);
                                    param->AddToRightNodes((yyvsp[0].tmp_id));
                                    auto list = new AstNode();
                                    list->AddToLeftNodes(param);
                                    (yyval.tmp_id) = list;
                                }
#line 1929 "./parser/Parser.cpp"
    break;

  case 11:
#line 183 "./parser/Parser.y"
                                                                             {
                                    auto param = MakeNode(FUNC_PARAM_CMD);
                                    param->AddToLeftNodes((yyvsp[-3].tmp_id));
                                    param->AddToRightNodes((yyvsp[0].tmp_id));
                                    (yyvsp[-5].tmp_id)->AddToLeftNodes(param);
                                    (yyval.tmp_id) = (yyvsp[-5].tmp_id);
                                }
#line 1941 "./parser/Parser.cpp"
    break;

  case 12:
#line 190 "./parser/Parser.y"
                                                               {
                                    auto param = MakeNode(FUNC_PARAM_CMD);
                                    param->AddToRightNodes((yyvsp[0].tmp_id));
                                    (yyvsp[-2].tmp_id)->AddToLeftNodes(param);
                                    (yyval.tmp_id) = (yyvsp[-2].tmp_id);
                                }
#line 1952 "./parser/Parser.cpp"
    break;

  case 13:
#line 198 "./parser/Parser.y"
                                     {
                                    (yyval.tmp_id) = MakeNode(FUNC_SURO_TYPE);
                                }
#line 1960 "./parser/Parser.cpp"
    break;

  case 14:
#line 201 "./parser/Parser.y"
                                       {
                                    (yyval.tmp_id) = MakeNode(FUNC_FURO_TYPE);
                                }
#line 1968 "./parser/Parser.cpp"
    break;

  case 15:
#line 204 "./parser/Parser.y"
                                       {
                                    (yyval.tmp_id) = MakeNode(FUNC_FUNC_TYPE);
                                }
#line 1976 "./parser/Parser.cpp"
    break;

  case 16:
#line 209 "./parser/Parser.y"
                                                                                                {
                                    (yyval.tmp_id) = MakeNode(MAKE_FUNC_CMD);
                                    (yyval.tmp_id)->AddToLeftNodes((yyvsp[-8].tmp_id));
                                    (yyval.tmp_id)->AddToLeftNodes((yyvsp[-10].tmp_id));
                                    (yyval.tmp_id)->AddToRightNodes((yyvsp[-2].tmp_id));
                                    i.EatAst((yyval.tmp_id));
                                }
#line 1988 "./parser/Parser.cpp"
    break;

  case 17:
#line 216 "./parser/Parser.y"
                                                                                                                   {
                                    (yyval.tmp_id) = MakeNode(MAKE_FUNC_CMD);
                                    (yyval.tmp_id)->AddToLeftNodes((yyvsp[-10].tmp_id));
                                    (yyval.tmp_id)->AddToLeftNodes((yyvsp[-12].tmp_id));
                                    (yyval.tmp_id)->AddToMiddleNodes((yyvsp[-7].tmp_id));
                                    (yyval.tmp_id)->AddToRightNodes((yyvsp[-2].tmp_id));
                                    i.EatAst((yyval.tmp_id));
                                    (yyval.tmp_id) = nullptr;
                                }
#line 2002 "./parser/Parser.cpp"
    break;

  case 18:
#line 225 "./parser/Parser.y"
                                                                                 {
                                    (yyval.tmp_id) = MakeNode(MAKE_FUNC_CMD);
                                    (yyval.tmp_id)->AddToLeftNodes((yyvsp[-5].tmp_id));
                                    (yyval.tmp_id)->AddToLeftNodes((yyvsp[-7].tmp_id));
                                    (yyval.tmp_id)->AddToRightNodes(MakeDataTypeNode("int"));
                                    i.EatAst((yyval.tmp_id));
                                }
#line 2014 "./parser/Parser.cpp"
    break;

  case 19:
#line 232 "./parser/Parser.y"
                                                                                                  {
                                    (yyval.tmp_id) = MakeNode(MAKE_FUNC_CMD);
                                    (yyval.tmp_id)->AddToLeftNodes((yyvsp[-7].tmp_id));
                                    (yyval.tmp_id)->AddToLeftNodes((yyvsp[-9].tmp_id));
                                    (yyval.tmp_id)->AddToMiddleNodes((yyvsp[-4].tmp_id));
                                    (yyval.tmp_id)->AddToRightNodes(MakeDataTypeNode("int"));
                                    i.EatAst((yyval.tmp_id));
                                    (yyval.tmp_id) = nullptr;
                                }
#line 2028 "./parser/Parser.cpp"
    break;

  case 20:
#line 243 "./parser/Parser.y"
                                                     {
                                    auto node = MakeNode(FUNC_RETR_CMD);
                                    node->AddToLeftNodes((yyvsp[0].tmp_id));
                                    i.EatAst(node);
                                }
#line 2038 "./parser/Parser.cpp"
    break;

  case 21:
#line 249 "./parser/Parser.y"
                                                              {
                                    auto func_call = MakeNode(CALL_FUNC_CMD);
                                    func_call->AddToLeftNodes((yyvsp[-2].tmp_id));
                                    (yyval.tmp_id) = func_call;
                                }
#line 2048 "./parser/Parser.cpp"
    break;

  case 22:
#line 254 "./parser/Parser.y"
                                                                                      {
                                    auto func_call = MakeNode(CALL_FUNC_CMD);
                                    func_call->AddToLeftNodes((yyvsp[-4].tmp_id));
                                    auto end = (yyvsp[-2].tmp_id)->Extras();
                                    for(size_t iter = 0; iter < end; iter++) {
                                        func_call->AddToRightNodes((yyvsp[-2].tmp_id)->GetExtraNode(iter));
                                    }
                                    (yyval.tmp_id) = func_call;
                                }
#line 2062 "./parser/Parser.cpp"
    break;

  case 28:
#line 270 "./parser/Parser.y"
                                                   {
                                    i.EatAst(MakeEndCtrlScopeAst());
                                }
#line 2070 "./parser/Parser.cpp"
    break;

  case 29:
#line 274 "./parser/Parser.y"
                                                     {
                                    i.EatAst(MakeIncAst((yyvsp[-2].tmp_id)));
                                    i.EatAst(MakeEndCtrlScopeAst());
                                    i.EatAst(MakeEndScopeAst());  
                                }
#line 2080 "./parser/Parser.cpp"
    break;

  case 30:
#line 280 "./parser/Parser.y"
                                           {
                                    i.EatAst(MakeEndCtrlScopeAst());
                                }
#line 2088 "./parser/Parser.cpp"
    break;

  case 31:
#line 283 "./parser/Parser.y"
                                                         {
                                    i.EatAst(MakeEndCtrlScopeAst());
                                }
#line 2096 "./parser/Parser.cpp"
    break;

  case 32:
#line 286 "./parser/Parser.y"
                                                                  {
                                    i.EatAst(MakeEndCtrlScopeAst());
                                }
#line 2104 "./parser/Parser.cpp"
    break;

  case 33:
#line 289 "./parser/Parser.y"
                                                      {
                                    i.EatAst(MakeEndCtrlScopeAst());
                                }
#line 2112 "./parser/Parser.cpp"
    break;

  case 34:
#line 293 "./parser/Parser.y"
                                                      {
                                    (yyval.tmp_id) = MakeNode(FUNC_END_CMD);
                                }
#line 2120 "./parser/Parser.cpp"
    break;

  case 37:
#line 300 "./parser/Parser.y"
                                     { (yyval.tmp_id) = new AstNode(); (yyval.tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id)); }
#line 2126 "./parser/Parser.cpp"
    break;

  case 38:
#line 301 "./parser/Parser.y"
                                                          { (yyvsp[-2].tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id)); (yyval.tmp_id) = (yyvsp[-2].tmp_id); }
#line 2132 "./parser/Parser.cpp"
    break;

  case 39:
#line 302 "./parser/Parser.y"
                                                               {(yyvsp[-2].tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id)); (yyval.tmp_id) = (yyvsp[-2].tmp_id); }
#line 2138 "./parser/Parser.cpp"
    break;

  case 40:
#line 305 "./parser/Parser.y"
                                                                                   {
                                    (yyval.tmp_id) = new AstNode();
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[-4].tmp_id));
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[-2].tmp_id));
                                }
#line 2148 "./parser/Parser.cpp"
    break;

  case 41:
#line 312 "./parser/Parser.y"
                                                               {
                                    (yyval.tmp_id) = new AstNode();
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[-2].tmp_id)->GetExtraNode());
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[-2].tmp_id)->GetExtraNode(1));
                                    (yyvsp[-2].tmp_id)->NullExtraNode(0);
                                    (yyvsp[-2].tmp_id)->NullExtraNode(1);
                                    delete (yyvsp[-2].tmp_id);
                                }
#line 2161 "./parser/Parser.cpp"
    break;

  case 42:
#line 320 "./parser/Parser.y"
                                                         {
                                    (yyval.tmp_id) = new AstNode();
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[-1].tmp_id)->GetExtraNode());
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[-1].tmp_id)->GetExtraNode(1));
                                    (yyvsp[-1].tmp_id)->NullExtraNode(0);
                                    (yyvsp[-1].tmp_id)->NullExtraNode(1);
                                    delete (yyvsp[-1].tmp_id);
                                }
#line 2174 "./parser/Parser.cpp"
    break;

  case 43:
#line 328 "./parser/Parser.y"
                                                                               {
                                    (yyvsp[-3].tmp_id)->SaveAsExtraNode((yyvsp[-2].tmp_id)->GetExtraNode());
                                    (yyvsp[-3].tmp_id)->SaveAsExtraNode((yyvsp[-2].tmp_id)->GetExtraNode(1));
                                    (yyvsp[-2].tmp_id)->NullExtraNode(0);
                                    (yyvsp[-2].tmp_id)->NullExtraNode(1);
                                    delete (yyvsp[-2].tmp_id);
                                    (yyval.tmp_id) = (yyvsp[-3].tmp_id);
                                }
#line 2187 "./parser/Parser.cpp"
    break;

  case 44:
#line 336 "./parser/Parser.y"
                                                                       {
                                    (yyvsp[-2].tmp_id)->SaveAsExtraNode((yyvsp[-1].tmp_id)->GetExtraNode());
                                    (yyvsp[-2].tmp_id)->SaveAsExtraNode((yyvsp[-1].tmp_id)->GetExtraNode(1));
                                    (yyvsp[-1].tmp_id)->NullExtraNode(0);
                                    (yyvsp[-1].tmp_id)->NullExtraNode(1);
                                    delete (yyvsp[-1].tmp_id);
                                    (yyval.tmp_id) = (yyvsp[-2].tmp_id);
                                }
#line 2200 "./parser/Parser.cpp"
    break;

  case 45:
#line 344 "./parser/Parser.y"
                                                                {
                                    (yyvsp[-1].tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id)->GetExtraNode());
                                    (yyvsp[-1].tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id)->GetExtraNode(1));
                                    (yyvsp[0].tmp_id)->NullExtraNode(0);
                                    (yyvsp[0].tmp_id)->NullExtraNode(1);
                                    delete (yyvsp[0].tmp_id);
                                    (yyval.tmp_id) = (yyvsp[-1].tmp_id);
                                }
#line 2213 "./parser/Parser.cpp"
    break;

  case 46:
#line 354 "./parser/Parser.y"
                                                { 
                                       (yyval.tmp_id) = MakeTermNode((yyvsp[0].data)->int_val, INT_NODE_TYPE);            
                                }
#line 2221 "./parser/Parser.cpp"
    break;

  case 47:
#line 357 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeTermNode((yyvsp[0].data)->dou_val, DOUBLE_NODE_TYPE);          
                                }
#line 2229 "./parser/Parser.cpp"
    break;

  case 48:
#line 360 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeTermNode((yyvsp[0].data)->flo_val, FLOAT_NODE_TYPE);            
                                }
#line 2237 "./parser/Parser.cpp"
    break;

  case 49:
#line 363 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeTermNode((string)(yyvsp[0].data)->str_val, STRING_NODE_TYPE);                   
                                }
#line 2245 "./parser/Parser.cpp"
    break;

  case 50:
#line 366 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeTermNode((yyvsp[0].data)->char_val, CHAR_NODE_TYPE);
                                }
#line 2253 "./parser/Parser.cpp"
    break;

  case 51:
#line 369 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeTermNode((yyvsp[0].data)->bol_val, BOOL_NODE_TYPE);
                                }
#line 2261 "./parser/Parser.cpp"
    break;

  case 52:
#line 372 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = (yyvsp[0].tmp_id);       
                                }
#line 2269 "./parser/Parser.cpp"
    break;

  case 53:
#line 375 "./parser/Parser.y"
                                                                           {
                                    (yyval.tmp_id) = MakeArrayTermAst((yyvsp[-2].tmp_id));
                                }
#line 2277 "./parser/Parser.cpp"
    break;

  case 54:
#line 378 "./parser/Parser.y"
                                          {
                                    (yyval.tmp_id) = MakeTermNode(0, ARRAY_NODE_TYPE);
                                }
#line 2285 "./parser/Parser.cpp"
    break;

  case 55:
#line 381 "./parser/Parser.y"
                                                               {
                                    (yyval.tmp_id) = MakeMapTermAst((yyvsp[-1].tmp_id));
                                }
#line 2293 "./parser/Parser.cpp"
    break;

  case 56:
#line 384 "./parser/Parser.y"
                                          {
                                    (yyval.tmp_id) = MakeTermNode(0, MAP_NODE_TYPE);
                                }
#line 2301 "./parser/Parser.cpp"
    break;

  case 57:
#line 389 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types); }
#line 2307 "./parser/Parser.cpp"
    break;

  case 58:
#line 390 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types); }
#line 2313 "./parser/Parser.cpp"
    break;

  case 59:
#line 391 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types); }
#line 2319 "./parser/Parser.cpp"
    break;

  case 60:
#line 392 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types); }
#line 2325 "./parser/Parser.cpp"
    break;

  case 61:
#line 393 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types); }
#line 2331 "./parser/Parser.cpp"
    break;

  case 62:
#line 394 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types); }
#line 2337 "./parser/Parser.cpp"
    break;

  case 63:
#line 395 "./parser/Parser.y"
                                       {
                                    (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types);
                                }
#line 2345 "./parser/Parser.cpp"
    break;

  case 64:
#line 398 "./parser/Parser.y"
                                      {
                                    (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types);
                                }
#line 2353 "./parser/Parser.cpp"
    break;

  case 65:
#line 403 "./parser/Parser.y"
                                                                            {
                                   (yyval.tmp_id) = (yyvsp[-4].tmp_id);
                                   (yyval.tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id));
                                }
#line 2362 "./parser/Parser.cpp"
    break;

  case 66:
#line 407 "./parser/Parser.y"
                                                                           {
                                    (yyval.tmp_id) = (yyvsp[-4].tmp_id);
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id));
                                }
#line 2371 "./parser/Parser.cpp"
    break;

  case 71:
#line 417 "./parser/Parser.y"
                                   {
                                    (yyval.tmp_id) = MakeTermNode((string)(yyvsp[0].data)->id, ID_NODE_TYPE);
                                }
#line 2379 "./parser/Parser.cpp"
    break;

  case 72:
#line 421 "./parser/Parser.y"
                                                                                                    {
                                    (yyval.tmp_id) = MakeAssignAst((yyvsp[-8].tmp_id), (yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2387 "./parser/Parser.cpp"
    break;

  case 73:
#line 424 "./parser/Parser.y"
                                                                                                   {
                                    (yyval.tmp_id) = MakeAssignAst((yyvsp[-8].tmp_id), (yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2395 "./parser/Parser.cpp"
    break;

  case 74:
#line 427 "./parser/Parser.y"
                                                                                                        {
                                    (yyval.tmp_id) = MakeUnionAst((yyvsp[-8].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2403 "./parser/Parser.cpp"
    break;

  case 75:
#line 430 "./parser/Parser.y"
                                                                                                     {
                                    (yyval.tmp_id) = MakeUnionAst((yyvsp[-8].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2411 "./parser/Parser.cpp"
    break;

  case 76:
#line 433 "./parser/Parser.y"
                                                                                                                   {
                                    (yyval.tmp_id) = MakeUnionAst((yyvsp[-10].tmp_id), (yyvsp[-5].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2419 "./parser/Parser.cpp"
    break;

  case 77:
#line 436 "./parser/Parser.y"
                                                                                                                {
                                    (yyval.tmp_id) = MakeUnionAst((yyvsp[-10].tmp_id), (yyvsp[-5].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2427 "./parser/Parser.cpp"
    break;

  case 78:
#line 439 "./parser/Parser.y"
                                                                           {
                                   (yyval.tmp_id) = MakeReassignAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2435 "./parser/Parser.cpp"
    break;

  case 79:
#line 442 "./parser/Parser.y"
                                                                                                                         {
                                    (yyval.tmp_id) = MakeRefAst((yyvsp[-12].tmp_id), (yyvsp[-7].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2443 "./parser/Parser.cpp"
    break;

  case 80:
#line 445 "./parser/Parser.y"
                                                                                                                      {
                                    (yyval.tmp_id) = MakeRefAst((yyvsp[-12].tmp_id), (yyvsp[-7].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2451 "./parser/Parser.cpp"
    break;

  case 81:
#line 448 "./parser/Parser.y"
                                                                                              {
                                    (yyval.tmp_id) = MakeRebindRefAst((yyvsp[-8].tmp_id), (yyvsp[-3].tmp_id));
                                }
#line 2459 "./parser/Parser.cpp"
    break;

  case 82:
#line 454 "./parser/Parser.y"
                                           {
                                    (yyval.tmp_id) = new AstNode();
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id));
                                }
#line 2468 "./parser/Parser.cpp"
    break;

  case 83:
#line 458 "./parser/Parser.y"
                                                   {
                                    (yyval.tmp_id) = new AstNode();
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id));
                                }
#line 2477 "./parser/Parser.cpp"
    break;

  case 84:
#line 462 "./parser/Parser.y"
                                                             {  
                                    (yyvsp[-2].tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id));
                                    (yyval.tmp_id) = (yyvsp[-2].tmp_id);
                                }
#line 2486 "./parser/Parser.cpp"
    break;

  case 85:
#line 466 "./parser/Parser.y"
                                                                  {
                                    (yyvsp[-2].tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id));
                                    (yyval.tmp_id) = (yyvsp[-2].tmp_id);
                                }
#line 2495 "./parser/Parser.cpp"
    break;

  case 90:
#line 476 "./parser/Parser.y"
                                                                            { 
                                    (yyval.tmp_id) = MakePrintAst((yyvsp[-2].tmp_id));
                                }
#line 2503 "./parser/Parser.cpp"
    break;

  case 91:
#line 479 "./parser/Parser.y"
                                                     { Destroy(); return 0; (yyval.tmp_id) = nullptr; }
#line 2509 "./parser/Parser.cpp"
    break;

  case 92:
#line 484 "./parser/Parser.y"
                                                                        {
                                    Perform((yyval.tmp_id), (yyvsp[-2].tmp_id), ADDITION_CMD);
                                }
#line 2517 "./parser/Parser.cpp"
    break;

  case 93:
#line 487 "./parser/Parser.y"
                                                                         {
                                    Perform((yyval.tmp_id), (yyvsp[-2].tmp_id), SUBTRACTION_CMD);
                                }
#line 2525 "./parser/Parser.cpp"
    break;

  case 94:
#line 490 "./parser/Parser.y"
                                                                          {
                                    Perform((yyval.tmp_id), (yyvsp[-2].tmp_id), MULTIPLY_CMD);
                                }
#line 2533 "./parser/Parser.cpp"
    break;

  case 95:
#line 493 "./parser/Parser.y"
                                                                          {
                                    Perform((yyval.tmp_id), (yyvsp[-2].tmp_id), DIVIDE_CMD);
                                }
#line 2541 "./parser/Parser.cpp"
    break;

  case 96:
#line 496 "./parser/Parser.y"
                                                                          {
                                    Perform((yyval.tmp_id), (yyvsp[-2].tmp_id), POW_CMD);
                                }
#line 2549 "./parser/Parser.cpp"
    break;

  case 97:
#line 499 "./parser/Parser.y"
                                                                        {
                                    (yyval.tmp_id) = MakeIncAst((yyvsp[-2].tmp_id));
                                }
#line 2557 "./parser/Parser.cpp"
    break;

  case 98:
#line 502 "./parser/Parser.y"
                                                                                                {
                                    (yyval.tmp_id) = MakeModAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2565 "./parser/Parser.cpp"
    break;

  case 99:
#line 510 "./parser/Parser.y"
                                                                                           {
                                    (yyval.tmp_id) = MakeLessCompAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2573 "./parser/Parser.cpp"
    break;

  case 100:
#line 513 "./parser/Parser.y"
                                                                                                {
                                    (yyval.tmp_id) = MakeGreaterCompAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2581 "./parser/Parser.cpp"
    break;

  case 101:
#line 516 "./parser/Parser.y"
                                                                                                  {
                                    (yyval.tmp_id) = MakeLessEqualCompAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2589 "./parser/Parser.cpp"
    break;

  case 102:
#line 519 "./parser/Parser.y"
                                                                                                      {
                                    (yyval.tmp_id) = MakeGreaterEqualCompAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2597 "./parser/Parser.cpp"
    break;

  case 103:
#line 522 "./parser/Parser.y"
                                                                                             {
                                    (yyval.tmp_id) = MakeEqualCompAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2605 "./parser/Parser.cpp"
    break;

  case 104:
#line 525 "./parser/Parser.y"
                                                                                                  {
                                    (yyval.tmp_id) = MakeNotEqualCompAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2613 "./parser/Parser.cpp"
    break;

  case 105:
#line 532 "./parser/Parser.y"
                                                                                         {
                                    (yyval.tmp_id) = MakeAndAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2621 "./parser/Parser.cpp"
    break;

  case 106:
#line 535 "./parser/Parser.y"
                                                                 {
                                    (yyval.tmp_id) = MakeNotAst((yyvsp[-2].tmp_id));
                                }
#line 2629 "./parser/Parser.cpp"
    break;

  case 107:
#line 538 "./parser/Parser.y"
                                                                                           {
                                    (yyval.tmp_id) = MakeOrAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2637 "./parser/Parser.cpp"
    break;

  case 108:
#line 544 "./parser/Parser.y"
                                                                  {
                                    (yyval.tmp_id) = MakeGetFromCollectionAst((yyvsp[-3].tmp_id), (yyvsp[-1].tmp_id));
                                }
#line 2645 "./parser/Parser.cpp"
    break;

  case 109:
#line 550 "./parser/Parser.y"
                                     {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2653 "./parser/Parser.cpp"
    break;

  case 110:
#line 553 "./parser/Parser.y"
                                            {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2661 "./parser/Parser.cpp"
    break;

  case 111:
#line 556 "./parser/Parser.y"
                                                                                          {
                                    (yyval.tmp_id) = MakeCastAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2669 "./parser/Parser.cpp"
    break;

  case 112:
#line 559 "./parser/Parser.y"
                                               {
                                   (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2677 "./parser/Parser.cpp"
    break;

  case 113:
#line 562 "./parser/Parser.y"
                                           {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2685 "./parser/Parser.cpp"
    break;

  case 114:
#line 565 "./parser/Parser.y"
                                                                                           {
                                     (yyval.tmp_id) = MakeAddToListAst((yyvsp[-7].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2693 "./parser/Parser.cpp"
    break;

  case 115:
#line 568 "./parser/Parser.y"
                                                                                                          {
                                    (yyval.tmp_id) = MakeAddToMapAst((yyvsp[-9].tmp_id), (yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2701 "./parser/Parser.cpp"
    break;

  case 116:
#line 571 "./parser/Parser.y"
                                                {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2709 "./parser/Parser.cpp"
    break;

  case 117:
#line 574 "./parser/Parser.y"
                                                                                                            {
                                    (yyval.tmp_id) = MakeSetInCollectionAst((yyvsp[-9].tmp_id), (yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2717 "./parser/Parser.cpp"
    break;

  case 118:
#line 577 "./parser/Parser.y"
                                                      {
                                    (yyval.tmp_id) = MakeCollectionSizeAst((yyvsp[-2].tmp_id));
                                }
#line 2725 "./parser/Parser.cpp"
    break;

  case 119:
#line 580 "./parser/Parser.y"
                                                                       {
                                    (yyval.tmp_id) = MakeQueryContainerCmd((yyvsp[-5].tmp_id), (yyvsp[-1].tmp_id));
                                }
#line 2733 "./parser/Parser.cpp"
    break;

  case 120:
#line 583 "./parser/Parser.y"
                                                                           {
                                    (yyval.tmp_id) = MakeRemoveFromContainerCmd((yyvsp[-5].tmp_id), (yyvsp[-1].tmp_id));
                                }
#line 2741 "./parser/Parser.cpp"
    break;

  case 121:
#line 586 "./parser/Parser.y"
                                                                          {
                                    (yyval.tmp_id) = MakeNode(GET_TYPE_CMD);
                                    (yyval.tmp_id)->AddToLeftNodes((yyvsp[-2].tmp_id));
                                }
#line 2750 "./parser/Parser.cpp"
    break;

  case 122:
#line 590 "./parser/Parser.y"
                                                        {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2758 "./parser/Parser.cpp"
    break;

  case 123:
#line 593 "./parser/Parser.y"
                                               { (yyval.tmp_id) = (yyvsp[0].tmp_id); }
#line 2764 "./parser/Parser.cpp"
    break;

  case 124:
#line 596 "./parser/Parser.y"
                                     { i.EatAst((yyvsp[0].tmp_id)); (yyvsp[0].tmp_id) = nullptr; }
#line 2770 "./parser/Parser.cpp"
    break;

  case 125:
#line 597 "./parser/Parser.y"
                                            { i.EatAst((yyvsp[0].tmp_id)); (yyvsp[0].tmp_id) = nullptr; }
#line 2776 "./parser/Parser.cpp"
    break;

  case 133:
#line 605 "./parser/Parser.y"
                                       {
                                    Destroy();
                                    return 0;
                                }
#line 2785 "./parser/Parser.cpp"
    break;

  case 134:
#line 609 "./parser/Parser.y"
                                        { return 0; }
#line 2791 "./parser/Parser.cpp"
    break;


#line 2795 "./parser/Parser.cpp"

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
#line 612 "./parser/Parser.y"



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
