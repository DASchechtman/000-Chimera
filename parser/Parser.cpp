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
    INT_VAL = 304,
    DOUBLE_VAL = 305,
    STRING_VAL = 306,
    CHAR_VAL = 307,
    BOOL_VAL = 308,
    ELSE_IF = 309,
    FLOAT_VAL = 310,
    ID = 311,
    UNKNOWN = 312,
    MULTI_WS = 313,
    SINGLE_WS = 314
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 34 "./parser/Parser.y"

    YYSTYPEs *data;
    AstNode *tmp_id;

#line 219 "./parser/Parser.cpp"

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
#define YYFINAL  95
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1077

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  72
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  121
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  376

#define YYUNDEFTOK  2
#define YYMAXUTOK   314


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
      62,    63,     2,     2,     2,     2,    71,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    60,     2,
      69,    68,    70,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    64,     2,    65,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    66,    61,    67,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   126,   126,   128,   130,   134,   138,   142,   146,   160,
     169,   176,   183,   191,   197,   207,   212,   223,   224,   225,
     226,   226,   228,   232,   238,   241,   244,   247,   251,   256,
     256,   258,   259,   260,   263,   270,   278,   286,   294,   304,
     307,   310,   313,   316,   319,   322,   325,   328,   331,   334,
     339,   340,   341,   342,   343,   344,   345,   348,   353,   357,
     363,   363,   365,   365,   367,   371,   374,   377,   380,   383,
     386,   392,   396,   400,   404,   410,   411,   411,   413,   414,
     417,   422,   425,   428,   431,   434,   437,   440,   448,   451,
     454,   457,   460,   463,   470,   473,   476,   482,   488,   491,
     494,   497,   500,   503,   506,   509,   512,   515,   518,   523,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   536,
     538,   538
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
  "SURO", "CALL", "INT_VAL", "DOUBLE_VAL", "STRING_VAL", "CHAR_VAL",
  "BOOL_VAL", "ELSE_IF", "FLOAT_VAL", "ID", "UNKNOWN", "MULTI_WS",
  "SINGLE_WS", "':'", "'|'", "'('", "')'", "'['", "']'", "'{'", "'}'",
  "'='", "'<'", "'>'", "'.'", "$accept", "start", "end", "ifHead",
  "elseIfHead", "elseHead", "whileHead", "forloopHead", "paramList",
  "functionHead", "functionCall", "ifBody", "elseIfBody", "elseBody",
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
      58,   124,    40,    41,    91,    93,   123,   125,    61,    60,
      62,    46
};
# endif

#define YYPACT_NINF (-158)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-63)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1011,  -158,   -39,   -56,  -158,  -158,  -158,  -158,   -39,   -39,
     -39,   -39,  -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,
    -158,   264,    60,    24,  1011,  1011,  1011,  1011,  1011,  -158,
       8,  -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,
    -158,  -158,  -158,  -158,  -158,   -64,  -158,   589,  -158,   -40,
     -39,   147,   147,   147,   -10,   -39,   -39,   -39,   -39,   -39,
     -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,
     -39,   -39,   -39,   -39,   -39,  -158,    27,  -158,   380,  -158,
     -30,   786,   672,   831,   876,   921,  -158,   -39,   -39,  1011,
    1011,  -158,    15,    32,    88,  -158,  -158,   -39,     0,   361,
      22,    22,    22,   -39,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   249,    77,   147,   -39,   -39,   -39,
     -39,   147,   147,   -10,   -10,   -10,   -39,   -39,  -158,   -39,
     -17,   -12,  -158,  -158,  -158,  -158,  -158,    51,   147,   719,
     966,  -158,  -158,  -158,    31,    28,    39,    48,  -158,   -39,
    -158,    52,    56,    68,    55,    22,    22,    22,    22,    22,
      22,    22,    22,    22,    22,   -64,  -158,   147,    27,   147,
     -64,   147,    63,    69,    75,    81,    22,    22,   -39,   -39,
     -39,  -158,   380,   380,    58,   380,   -39,  -158,  -158,    -5,
    -158,    22,  -158,   -39,   -39,   -39,    84,  -158,  -158,   -39,
      29,   466,   147,   147,   147,   147,   147,   147,   147,   147,
      85,   -64,   -64,  -158,  -158,  -158,  -158,    86,   147,   147,
      83,    89,   147,    87,  -158,  -158,  -158,   -39,  -158,   -39,
    -158,   115,   147,   147,   147,  -158,   -10,  -158,  -158,  -158,
    -158,  -158,  -158,  -158,  -158,    93,   -39,  -158,    94,   -39,
      22,    22,    22,    22,    22,    22,    22,    22,  -158,  -158,
      22,   -20,   -39,  -158,    22,   -39,   121,  -158,  -158,    22,
      22,    22,   -39,   -39,   161,    96,   -39,    97,   109,   110,
     111,   112,   113,   118,   119,   120,   122,  -158,   124,     7,
      20,   -39,    98,   147,   147,   152,   466,  -158,   129,   130,
     466,  -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,
    -158,  -158,  -158,   169,   -39,   466,   -39,   380,  -158,    22,
      22,  -158,   -39,   -39,   -39,  -158,   131,   147,   -39,    72,
     147,   135,   -39,   145,   149,   172,   466,   466,   -39,    22,
     151,   -39,   153,    22,   189,   155,  -158,  -158,  -158,  -158,
     -39,   156,   157,   -39,   147,   -39,   158,   159,  -158,   186,
    -158,  -158,   466,    22,   466,  -158,   -39,  -158,  -158,   160,
    -158,   147,  -158,    22,   163,  -158
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,   119,    63,     0,    29,    30,   118,     2,     0,     0,
       0,     0,    39,    40,    42,    43,    44,    41,    64,    60,
      61,     0,    63,    63,     0,     0,     0,     0,     0,   114,
       0,   112,   113,   111,   108,   117,    98,   116,    45,    78,
     110,    99,   101,   102,   105,   109,   120,     0,    62,     0,
      63,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    63,    63,    63,    63,    63,
       0,     0,     0,     0,    63,    47,    76,    77,     0,    49,
       0,     0,     0,     0,     0,     0,    24,     0,     0,     0,
       0,    20,     0,     0,     0,     1,   121,    63,     0,     0,
       0,     0,     0,    63,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    63,     0,    63,    63,    63,
      63,     0,     0,     0,     0,     0,    63,    63,    31,    63,
       0,     0,     3,   115,    22,    23,    28,     0,     0,     0,
       0,    27,    25,    21,     0,     0,     0,     0,   107,    63,
      80,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    63,    71,    81,    62,     0,     0,
      72,    77,     0,     0,     0,     0,    63,     0,     0,    63,
      63,    75,    62,    77,     0,     0,    63,    36,    48,     0,
       6,     0,    26,    63,    63,    63,     0,     4,     7,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    73,    74,    82,    83,    84,    85,     0,     0,     0,
      63,     0,    62,     0,    32,    33,    46,    63,    35,    63,
      38,     0,     0,     0,     0,    79,     0,    50,    51,    52,
      53,    54,    55,    56,    57,     0,    63,    10,     0,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    95,    86,
      63,     0,    63,    15,    63,    63,     0,    37,     5,    63,
       0,     0,     0,    63,    62,     0,    63,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    97,     0,     0,
       0,    63,     0,     0,     0,     0,     0,    12,     0,     0,
       0,   100,    88,    89,    90,    91,    92,    93,    94,    96,
      87,    16,    68,     0,     0,     0,    63,     0,   103,    63,
      63,     8,     0,    63,    63,     9,     0,     0,    63,    63,
      62,     0,    63,     0,     0,     0,     0,     0,    63,    63,
       0,     0,     0,    63,     0,     0,   104,   106,    13,    11,
       0,     0,     0,    63,     0,    63,     0,     0,    34,     0,
      70,    66,     0,    63,     0,    65,     0,    14,    58,     0,
      59,     0,    67,    63,     0,    69
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,  -158,
    -158,  -158,   137,   138,  -158,  -158,  -158,  -158,  -158,  -158,
    -158,   101,  -158,   -75,  -157,  -158,   338,    -2,   -50,  -158,
     -57,   -21,   -15,  -158,  -158,  -158,  -158,  -158,   459,   -25,
     -11
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    24,   133,    25,    89,    90,    26,    27,   246,    28,
      29,    30,    91,    92,    93,    31,    32,    33,    34,    35,
     127,   130,   131,    36,   247,   329,    48,    76,    38,    39,
     115,   116,    78,    40,    41,    42,    43,    44,    45,    46,
      47
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    77,    77,   128,   103,    50,   186,    94,    80,   117,
     118,   119,   120,    81,    82,    83,    84,    85,   229,    19,
      20,    97,    96,   237,   238,   239,   240,   241,   242,   243,
     244,   129,   237,   238,   239,   240,   241,   242,   243,   244,
     149,    19,    20,   287,   249,    86,    18,    87,    98,   129,
     126,    94,   141,    19,    20,   188,    96,    96,    96,    96,
      96,   150,    88,   114,   114,   114,   114,   114,   192,   142,
     312,    87,   125,   178,   179,   180,   313,   314,   139,   140,
      19,    20,    19,    20,   315,    18,    88,   190,   197,   193,
     245,    79,   198,    94,   169,   114,   171,   171,   171,   171,
     194,   154,   172,   173,   174,   175,   183,   224,   225,   195,
     227,   199,   184,   168,    96,    96,   200,   297,    19,    20,
     145,   146,   147,   226,   181,    75,   213,   185,   171,   148,
      19,    20,   214,   316,   196,    19,    20,   341,   215,   322,
     166,    19,    20,   325,   216,   235,   -62,   265,   258,   259,
     248,   268,   263,   273,   276,    77,   291,   299,   328,   318,
     301,   217,   210,   262,   237,   238,   239,   240,   241,   242,
     243,   244,   302,   303,   304,   305,   306,   221,   223,   349,
     350,   307,   308,   309,   228,   310,   272,   311,   321,   323,
     324,   232,   233,   234,    11,   326,    12,    13,    14,    15,
      16,   338,    17,    18,   344,   368,   346,   370,   348,    99,
     347,    22,   353,    23,   355,   357,   358,    18,   114,   360,
     361,   365,   367,   372,   298,   266,   375,   267,    77,   366,
     143,   144,   189,     0,   277,     0,     0,     0,     0,    77,
       0,   171,   332,     0,   275,   286,     0,   288,   278,   279,
     280,   281,   282,   283,   284,   285,     0,     0,     0,     0,
       0,     0,   289,   290,     0,     0,     0,   292,     0,     0,
       0,   296,   126,     0,   300,    55,    56,    57,    58,    59,
      60,    61,     0,    62,    63,    64,     0,     0,     0,   317,
       0,    65,    66,    67,    68,    69,    11,     0,    12,    13,
      14,    15,    16,     0,    17,    18,     0,     0,    70,    71,
      72,    99,    73,    22,   331,    23,     0,   333,   334,     0,
       0,   336,   337,     0,     0,     0,   340,   342,     0,     0,
     345,     0,    74,     0,     0,     0,   351,   352,    37,     0,
       0,   356,     0,     0,     0,     0,    51,    52,    53,    54,
       0,   362,     0,   364,     0,     0,     0,     0,     0,     0,
       0,   369,    37,    37,    37,    37,    37,     0,     0,     0,
       0,   374,    55,    56,    57,    58,    59,    60,    61,     0,
      62,    63,    64,     0,     0,    37,     0,     0,    65,    66,
      67,    68,    69,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,     0,     0,    70,    71,    72,   121,   122,
     123,   124,     0,     0,     0,     0,     0,     0,     0,    37,
      37,    37,    37,    37,     0,   137,   138,    37,    37,    12,
      13,    14,    15,    16,     0,    17,    18,     0,   151,   152,
     153,     0,     0,     0,    22,     0,    23,     0,     0,     0,
       0,     0,     0,   167,     0,   167,   167,   167,   167,     0,
       0,     0,     0,     0,     0,   182,     0,     0,   187,   237,
     238,   239,   240,   241,   242,   243,   244,    37,    37,     0,
       0,     0,     0,     0,     0,     0,     0,   167,     0,     0,
       0,     0,     0,   201,   202,   203,   204,   205,   206,   207,
     208,   209,     0,     0,     0,     0,     0,     0,     0,     0,
     100,   101,   102,     0,     0,   218,   219,   220,   222,     0,
       0,     0,     0,     0,     0,     0,     0,   230,     0,   231,
       0,     0,     0,     0,     0,     0,     0,   236,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,     0,   170,     0,     0,     0,     0,
     176,   177,     0,     0,   274,     0,     0,     0,     0,    95,
       1,     0,     0,     0,     0,     0,     0,   191,     0,     0,
     167,     0,     0,     0,     0,     0,     0,     2,   293,   294,
     295,     3,     4,     5,     6,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,   211,     8,   212,     9,
     212,    10,     0,     0,     0,     0,    11,     0,    12,    13,
      14,    15,    16,     0,    17,    18,     0,    19,    20,     0,
       0,    21,   327,    22,   330,    23,     0,     0,     0,     0,
     335,   250,   251,   252,   253,   254,   255,   256,   257,     0,
       0,     0,     0,     1,     0,     0,     0,   260,   261,   354,
       0,   264,     0,     0,     0,     0,     0,     0,   359,     0,
       2,   269,   270,   271,     3,     4,     5,     6,     0,     0,
       0,     0,     0,     0,   371,     0,     0,     0,     7,   -17,
       8,   -17,     9,     0,    10,     0,     0,     0,     0,    11,
       1,    12,    13,    14,    15,    16,   -17,    17,    18,     0,
      19,    20,     0,     0,    21,     0,    22,     2,    23,     0,
       0,     3,     4,     5,     6,     0,     0,     0,     0,     0,
       0,     0,   319,   320,     0,     7,   -18,     8,   -18,     9,
       0,    10,     0,     0,     0,     0,    11,     0,    12,    13,
      14,    15,    16,   -18,    17,    18,     0,    19,    20,     0,
       0,    21,     0,    22,     0,    23,   339,     1,     0,   343,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     0,     0,     0,     3,     4,
       5,     6,     0,   363,     0,     0,     0,     0,     0,     0,
       0,     0,     7,   132,     8,     0,     9,     0,    10,     0,
     373,     0,     1,    11,     0,    12,    13,    14,    15,    16,
       0,    17,    18,     0,    19,    20,     0,     0,    21,     2,
      22,     0,    23,     3,     4,     5,     6,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,   134,     8,
       0,     9,     0,    10,     0,     0,     0,     1,    11,     0,
      12,    13,    14,    15,    16,     0,    17,    18,     0,    19,
      20,     0,     0,    21,     2,    22,     0,    23,     3,     4,
       5,     6,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,   135,     8,     0,     9,     0,    10,     0,
       0,     0,     1,    11,     0,    12,    13,    14,    15,    16,
       0,    17,    18,     0,    19,    20,     0,     0,    21,     2,
      22,     0,    23,     3,     4,     5,     6,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,   136,     8,
       0,     9,     0,    10,     0,     0,     0,     1,    11,     0,
      12,    13,    14,    15,    16,     0,    17,    18,     0,    19,
      20,     0,     0,    21,     2,    22,     0,    23,     3,     4,
       5,     6,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,   -19,     8,     0,     9,     0,    10,     0,
       0,     0,     1,    11,     0,    12,    13,    14,    15,    16,
       0,    17,    18,     0,    19,    20,     0,     0,    21,     2,
      22,     0,    23,     3,     4,     5,     6,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     0,     8,
       0,     9,     0,    10,     0,     0,     0,     0,    11,     0,
      12,    13,    14,    15,    16,     0,    17,    18,     0,    19,
      20,     0,     0,    21,     0,    22,     0,    23
};

static const yytype_int16 yycheck[] =
{
       2,    22,    23,    78,    54,    61,    23,    71,    23,    66,
      67,    68,    69,    24,    25,    26,    27,    28,    23,    58,
      59,    61,    47,     3,     4,     5,     6,     7,     8,     9,
      10,    61,     3,     4,     5,     6,     7,     8,     9,    10,
      97,    58,    59,    63,   201,    37,    56,    39,    50,    61,
      23,    71,    37,    58,    59,    67,    81,    82,    83,    84,
      85,    61,    54,    65,    66,    67,    68,    69,    37,    37,
      63,    39,    74,   123,   124,   125,    69,    57,    89,    90,
      58,    59,    58,    59,    64,    56,    54,    36,    36,    61,
      61,    67,    36,    71,   115,    97,   117,   118,   119,   120,
      61,   103,   117,   118,   119,   120,   127,   182,   183,    61,
     185,    43,   127,   115,   139,   140,    61,   274,    58,    59,
      32,    33,    34,    65,   126,    65,    63,   129,   149,    41,
      58,    59,    63,   290,   149,    58,    59,    65,    63,   296,
      63,    58,    59,   300,    63,    61,    63,    60,    63,    63,
     200,    36,    63,    60,    60,   176,    35,    61,   315,    61,
      63,   176,   164,   220,     3,     4,     5,     6,     7,     8,
       9,    10,    63,    63,    63,    63,    63,   179,   180,   336,
     337,    63,    63,    63,   186,    63,   236,    63,    36,    60,
      60,   193,   194,   195,    47,    26,    49,    50,    51,    52,
      53,    70,    55,    56,    69,   362,    61,   364,    36,    62,
      61,    64,    61,    66,    61,    26,    61,    56,   220,    63,
      63,    63,    36,    63,   274,   227,    63,   229,   249,    70,
      93,    93,   131,    -1,   249,    -1,    -1,    -1,    -1,   260,
      -1,   262,   317,    -1,   246,   260,    -1,   262,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,    -1,    -1,    -1,
      -1,    -1,   264,   265,    -1,    -1,    -1,   269,    -1,    -1,
      -1,   273,    23,    -1,   276,    11,    12,    13,    14,    15,
      16,    17,    -1,    19,    20,    21,    -1,    -1,    -1,   291,
      -1,    27,    28,    29,    30,    31,    47,    -1,    49,    50,
      51,    52,    53,    -1,    55,    56,    -1,    -1,    44,    45,
      46,    62,    48,    64,   316,    66,    -1,   319,   320,    -1,
      -1,   323,   324,    -1,    -1,    -1,   328,   329,    -1,    -1,
     332,    -1,    68,    -1,    -1,    -1,   338,   339,     0,    -1,
      -1,   343,    -1,    -1,    -1,    -1,     8,     9,    10,    11,
      -1,   353,    -1,   355,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   363,    24,    25,    26,    27,    28,    -1,    -1,    -1,
      -1,   373,    11,    12,    13,    14,    15,    16,    17,    -1,
      19,    20,    21,    -1,    -1,    47,    -1,    -1,    27,    28,
      29,    30,    31,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    -1,    44,    45,    46,    70,    71,
      72,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      82,    83,    84,    85,    -1,    87,    88,    89,    90,    49,
      50,    51,    52,    53,    -1,    55,    56,    -1,   100,   101,
     102,    -1,    -1,    -1,    64,    -1,    66,    -1,    -1,    -1,
      -1,    -1,    -1,   115,    -1,   117,   118,   119,   120,    -1,
      -1,    -1,    -1,    -1,    -1,   127,    -1,    -1,   130,     3,
       4,     5,     6,     7,     8,     9,    10,   139,   140,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,
      -1,    -1,    -1,   155,   156,   157,   158,   159,   160,   161,
     162,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    52,    53,    -1,    -1,   177,   178,   179,   180,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   189,    -1,   191,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   199,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,    -1,   116,    -1,    -1,    -1,    -1,
     121,   122,    -1,    -1,   246,    -1,    -1,    -1,    -1,     0,
       1,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,    -1,
     262,    -1,    -1,    -1,    -1,    -1,    -1,    18,   270,   271,
     272,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,   167,    38,   169,    40,
     171,    42,    -1,    -1,    -1,    -1,    47,    -1,    49,    50,
      51,    52,    53,    -1,    55,    56,    -1,    58,    59,    -1,
      -1,    62,   314,    64,   316,    66,    -1,    -1,    -1,    -1,
     322,   202,   203,   204,   205,   206,   207,   208,   209,    -1,
      -1,    -1,    -1,     1,    -1,    -1,    -1,   218,   219,   341,
      -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,   350,    -1,
      18,   232,   233,   234,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,   366,    -1,    -1,    -1,    36,    37,
      38,    39,    40,    -1,    42,    -1,    -1,    -1,    -1,    47,
       1,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      58,    59,    -1,    -1,    62,    -1,    64,    18,    66,    -1,
      -1,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   293,   294,    -1,    36,    37,    38,    39,    40,
      -1,    42,    -1,    -1,    -1,    -1,    47,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    59,    -1,
      -1,    62,    -1,    64,    -1,    66,   327,     1,    -1,   330,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,    22,    23,
      24,    25,    -1,   354,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    37,    38,    -1,    40,    -1,    42,    -1,
     371,    -1,     1,    47,    -1,    49,    50,    51,    52,    53,
      -1,    55,    56,    -1,    58,    59,    -1,    -1,    62,    18,
      64,    -1,    66,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      -1,    40,    -1,    42,    -1,    -1,    -1,     1,    47,    -1,
      49,    50,    51,    52,    53,    -1,    55,    56,    -1,    58,
      59,    -1,    -1,    62,    18,    64,    -1,    66,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    37,    38,    -1,    40,    -1,    42,    -1,
      -1,    -1,     1,    47,    -1,    49,    50,    51,    52,    53,
      -1,    55,    56,    -1,    58,    59,    -1,    -1,    62,    18,
      64,    -1,    66,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      -1,    40,    -1,    42,    -1,    -1,    -1,     1,    47,    -1,
      49,    50,    51,    52,    53,    -1,    55,    56,    -1,    58,
      59,    -1,    -1,    62,    18,    64,    -1,    66,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    37,    38,    -1,    40,    -1,    42,    -1,
      -1,    -1,     1,    47,    -1,    49,    50,    51,    52,    53,
      -1,    55,    56,    -1,    58,    59,    -1,    -1,    62,    18,
      64,    -1,    66,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    38,
      -1,    40,    -1,    42,    -1,    -1,    -1,    -1,    47,    -1,
      49,    50,    51,    52,    53,    -1,    55,    56,    -1,    58,
      59,    -1,    -1,    62,    -1,    64,    -1,    66
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    18,    22,    23,    24,    25,    36,    38,    40,
      42,    47,    49,    50,    51,    52,    53,    55,    56,    58,
      59,    62,    64,    66,    73,    75,    78,    79,    81,    82,
      83,    87,    88,    89,    90,    91,    95,    98,   100,   101,
     105,   106,   107,   108,   109,   110,   111,   112,    98,    99,
      61,    98,    98,    98,    98,    11,    12,    13,    14,    15,
      16,    17,    19,    20,    21,    27,    28,    29,    30,    31,
      44,    45,    46,    48,    68,    65,    99,   103,   104,    67,
     104,   112,   112,   112,   112,   112,    37,    39,    54,    76,
      77,    84,    85,    86,    71,     0,   111,    61,    99,    62,
     110,   110,   110,   100,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    99,   102,   103,   102,   102,   102,
     102,    98,    98,    98,    98,    99,    23,    92,    95,    61,
      93,    94,    37,    74,    37,    37,    37,    98,    98,   112,
     112,    37,    37,    84,    85,    32,    33,    34,    41,   102,
      61,    98,    98,    98,    99,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,    63,    98,    99,   103,
     110,   103,   104,   104,   104,   104,   110,   110,   100,   100,
     100,    99,    98,   103,   104,    99,    23,    98,    67,    93,
      36,   110,    37,    61,    61,    61,   104,    36,    36,    43,
      61,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      99,   110,   110,    63,    63,    63,    63,   104,    98,    98,
      98,    99,    98,    99,    95,    95,    65,    95,    99,    23,
      98,    98,    99,    99,    99,    61,    98,     3,     4,     5,
       6,     7,     8,     9,    10,    61,    80,    96,   100,    96,
     110,   110,   110,   110,   110,   110,   110,   110,    63,    63,
     110,   110,   102,    63,   110,    60,    99,    99,    36,   110,
     110,   110,   100,    60,    98,    99,    60,   104,    99,    99,
      99,    99,    99,    99,    99,    99,   104,    63,   104,    99,
      99,    35,    99,    98,    98,    98,    99,    96,   100,    61,
      99,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    69,    57,    64,    96,    99,    61,   110,
     110,    36,    96,    60,    60,    96,    26,    98,    96,    97,
      98,    99,    95,    99,    99,    98,    99,    99,    70,   110,
      99,    65,    99,   110,    69,    99,    61,    61,    36,    96,
      96,    99,    99,    61,    98,    61,    99,    26,    61,    98,
      63,    63,    99,   110,    99,    63,    70,    36,    96,    99,
      96,    98,    63,   110,    99,    63
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      80,    80,    80,    81,    81,    82,    82,    83,    84,    85,
      86,    86,    87,    88,    89,    89,    89,    89,    90,    91,
      91,    92,    92,    92,    93,    94,    94,    94,    94,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      96,    96,    96,    96,    96,    96,    96,    96,    97,    97,
      98,    98,    99,    99,   100,   101,   101,   101,   101,   101,
     101,   102,   102,   102,   102,   103,   104,   104,   105,   105,
     105,   106,   106,   106,   106,   106,   106,   106,   107,   107,
     107,   107,   107,   107,   108,   108,   108,   109,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     112,   112
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     5,     5,     3,     5,     9,     4,
       1,     6,     3,    11,    13,     6,     8,     2,     2,     2,
       1,     2,     3,     3,     2,     3,     4,     3,     3,     1,
       1,     1,     3,     3,     9,     3,     2,     4,     3,     1,
       1,     1,     1,     1,     1,     1,     5,     2,     4,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     5,
       1,     1,     1,     0,     1,    12,    12,    14,     8,    16,
      12,     2,     2,     3,     3,     3,     1,     1,     1,     6,
       4,     4,     5,     5,     5,     5,     6,     8,     8,     8,
       8,     8,     8,     8,     8,     6,     8,     7,     1,     1,
       8,     1,     1,     8,    10,     1,    10,     3,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     2
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
#line 126 "./parser/Parser.y"
                                      { i.EatAst(MakeStartAst()); }
#line 1778 "./parser/Parser.cpp"
    break;

  case 3:
#line 128 "./parser/Parser.y"
                                    { i.EatAst(MakeEndScopeAst()); }
#line 1784 "./parser/Parser.cpp"
    break;

  case 4:
#line 130 "./parser/Parser.y"
                                                            {
                                    i.EatAst(MakeIfDeclAst((yyvsp[-2].tmp_id)));
                                }
#line 1792 "./parser/Parser.cpp"
    break;

  case 5:
#line 134 "./parser/Parser.y"
                                                                 {
                                    i.EatAst(MakeElifDeclAst((yyvsp[-2].tmp_id)));
                                }
#line 1800 "./parser/Parser.cpp"
    break;

  case 6:
#line 138 "./parser/Parser.y"
                                                 {
                                    i.EatAst(MakeElseDeclAst());
                                }
#line 1808 "./parser/Parser.cpp"
    break;

  case 7:
#line 142 "./parser/Parser.y"
                                                               {
                                    i.EatAst(MakeWhileDeclAst((yyvsp[-2].tmp_id)));
                                }
#line 1816 "./parser/Parser.cpp"
    break;

  case 8:
#line 146 "./parser/Parser.y"
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
#line 1834 "./parser/Parser.cpp"
    break;

  case 9:
#line 160 "./parser/Parser.y"
                                                    {
                                    auto param = MakeNode(FUNC_PARAM_CMD);
                                    param->AddToLeftNodes((yyvsp[-3].tmp_id));
                                    param->AddToRightNodes((yyvsp[0].tmp_id));
                                    auto list = new AstNode();
                                    list->AddToLeftNodes(param);
                                    (yyval.tmp_id) = list;

                                }
#line 1848 "./parser/Parser.cpp"
    break;

  case 10:
#line 169 "./parser/Parser.y"
                                        {
                                    auto param = MakeNode(FUNC_PARAM_CMD);
                                    param->AddToRightNodes((yyvsp[0].tmp_id));
                                    auto list = new AstNode();
                                    list->AddToLeftNodes(param);
                                    (yyval.tmp_id) = list;
                                }
#line 1860 "./parser/Parser.cpp"
    break;

  case 11:
#line 176 "./parser/Parser.y"
                                                                             {
                                    auto param = MakeNode(FUNC_PARAM_CMD);
                                    param->AddToLeftNodes((yyvsp[-3].tmp_id));
                                    param->AddToRightNodes((yyvsp[0].tmp_id));
                                    (yyvsp[-5].tmp_id)->AddToLeftNodes(param);
                                    (yyval.tmp_id) = (yyvsp[-5].tmp_id);
                                }
#line 1872 "./parser/Parser.cpp"
    break;

  case 12:
#line 183 "./parser/Parser.y"
                                                               {
                                    auto param = MakeNode(FUNC_PARAM_CMD);
                                    param->AddToRightNodes((yyvsp[0].tmp_id));
                                    (yyvsp[-2].tmp_id)->AddToLeftNodes(param);
                                    (yyval.tmp_id) = (yyvsp[-2].tmp_id);
                                }
#line 1883 "./parser/Parser.cpp"
    break;

  case 13:
#line 191 "./parser/Parser.y"
                                                                                            {
                                    (yyval.tmp_id) = MakeNode(MAKE_FUNC_CMD);
                                    (yyval.tmp_id)->AddToLeftNodes((yyvsp[-8].tmp_id));
                                    (yyval.tmp_id)->AddToRightNodes((yyvsp[-2].tmp_id));
                                    i.EatAst((yyval.tmp_id));
                                }
#line 1894 "./parser/Parser.cpp"
    break;

  case 14:
#line 197 "./parser/Parser.y"
                                                                                                               {
                                    (yyval.tmp_id) = MakeNode(MAKE_FUNC_CMD);
                                    (yyval.tmp_id)->AddToLeftNodes((yyvsp[-10].tmp_id));
                                    (yyval.tmp_id)->AddToMiddleNodes((yyvsp[-7].tmp_id));
                                    (yyval.tmp_id)->AddToRightNodes((yyvsp[-2].tmp_id));
                                    i.EatAst((yyval.tmp_id));
                                    (yyval.tmp_id) = nullptr;
                                }
#line 1907 "./parser/Parser.cpp"
    break;

  case 15:
#line 207 "./parser/Parser.y"
                                                              {
                                    auto func_call = MakeNode(CALL_FUNC_CMD);
                                    func_call->AddToLeftNodes((yyvsp[-2].tmp_id));
                                    (yyval.tmp_id) = func_call;
                                }
#line 1917 "./parser/Parser.cpp"
    break;

  case 16:
#line 212 "./parser/Parser.y"
                                                                                      {
                                    auto func_call = MakeNode(CALL_FUNC_CMD);
                                    func_call->AddToLeftNodes((yyvsp[-4].tmp_id));
                                    auto end = (yyvsp[-2].tmp_id)->Extras();
                                    for(size_t iter = 0; iter < end; iter++) {
                                        func_call->AddToRightNodes((yyvsp[-2].tmp_id)->GetExtraNode(iter));
                                    }
                                    (yyval.tmp_id) = func_call;
                                }
#line 1931 "./parser/Parser.cpp"
    break;

  case 22:
#line 228 "./parser/Parser.y"
                                                   {
                                    i.EatAst(MakeEndCtrlScopeAst());
                                }
#line 1939 "./parser/Parser.cpp"
    break;

  case 23:
#line 232 "./parser/Parser.y"
                                                     {
                                    i.EatAst(MakeIncAst((yyvsp[-2].tmp_id)));
                                    i.EatAst(MakeEndCtrlScopeAst());
                                    i.EatAst(MakeEndScopeAst());  
                                }
#line 1949 "./parser/Parser.cpp"
    break;

  case 24:
#line 238 "./parser/Parser.y"
                                           {
                                    i.EatAst(MakeEndCtrlScopeAst());
                                }
#line 1957 "./parser/Parser.cpp"
    break;

  case 25:
#line 241 "./parser/Parser.y"
                                                         {
                                    i.EatAst(MakeEndCtrlScopeAst());
                                }
#line 1965 "./parser/Parser.cpp"
    break;

  case 26:
#line 244 "./parser/Parser.y"
                                                                  {
                                    i.EatAst(MakeEndCtrlScopeAst());
                                }
#line 1973 "./parser/Parser.cpp"
    break;

  case 27:
#line 247 "./parser/Parser.y"
                                                      {
                                    i.EatAst(MakeEndCtrlScopeAst());
                                }
#line 1981 "./parser/Parser.cpp"
    break;

  case 28:
#line 251 "./parser/Parser.y"
                                                      {
                                    (yyval.tmp_id) = MakeNode(FUNC_RETR_CMD);
                                }
#line 1989 "./parser/Parser.cpp"
    break;

  case 31:
#line 258 "./parser/Parser.y"
                                     { (yyval.tmp_id) = (yyvsp[0].tmp_id); }
#line 1995 "./parser/Parser.cpp"
    break;

  case 32:
#line 259 "./parser/Parser.y"
                                                          { (yyvsp[-2].tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id)); (yyval.tmp_id) = (yyvsp[-2].tmp_id); }
#line 2001 "./parser/Parser.cpp"
    break;

  case 33:
#line 260 "./parser/Parser.y"
                                                               {(yyvsp[-2].tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id)); (yyval.tmp_id) = (yyvsp[-2].tmp_id); }
#line 2007 "./parser/Parser.cpp"
    break;

  case 34:
#line 263 "./parser/Parser.y"
                                                                                                  {
                                    (yyval.tmp_id) = new AstNode();
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[-6].tmp_id));
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[-2].tmp_id));
                                }
#line 2017 "./parser/Parser.cpp"
    break;

  case 35:
#line 270 "./parser/Parser.y"
                                                               {
                                    (yyval.tmp_id) = new AstNode();
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[-2].tmp_id)->GetExtraNode());
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[-2].tmp_id)->GetExtraNode(1));
                                    (yyvsp[-2].tmp_id)->NullExtraNode(0);
                                    (yyvsp[-2].tmp_id)->NullExtraNode(1);
                                    delete (yyvsp[-2].tmp_id);
                                }
#line 2030 "./parser/Parser.cpp"
    break;

  case 36:
#line 278 "./parser/Parser.y"
                                                         {
                                    (yyval.tmp_id) = new AstNode();
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[-1].tmp_id)->GetExtraNode());
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[-1].tmp_id)->GetExtraNode(1));
                                    (yyvsp[-1].tmp_id)->NullExtraNode(0);
                                    (yyvsp[-1].tmp_id)->NullExtraNode(1);
                                    delete (yyvsp[-1].tmp_id);
                                }
#line 2043 "./parser/Parser.cpp"
    break;

  case 37:
#line 286 "./parser/Parser.y"
                                                                               {
                                    (yyvsp[-3].tmp_id)->SaveAsExtraNode((yyvsp[-2].tmp_id)->GetExtraNode());
                                    (yyvsp[-3].tmp_id)->SaveAsExtraNode((yyvsp[-2].tmp_id)->GetExtraNode(1));
                                    (yyvsp[-2].tmp_id)->NullExtraNode(0);
                                    (yyvsp[-2].tmp_id)->NullExtraNode(1);
                                    delete (yyvsp[-2].tmp_id);
                                    (yyval.tmp_id) = (yyvsp[-3].tmp_id);
                                }
#line 2056 "./parser/Parser.cpp"
    break;

  case 38:
#line 294 "./parser/Parser.y"
                                                                       {
                                    (yyvsp[-2].tmp_id)->SaveAsExtraNode((yyvsp[-1].tmp_id)->GetExtraNode());
                                    (yyvsp[-2].tmp_id)->SaveAsExtraNode((yyvsp[-1].tmp_id)->GetExtraNode(1));
                                    (yyvsp[-1].tmp_id)->NullExtraNode(0);
                                    (yyvsp[-1].tmp_id)->NullExtraNode(1);
                                    delete (yyvsp[-1].tmp_id);
                                    (yyval.tmp_id) = (yyvsp[-2].tmp_id);
                                }
#line 2069 "./parser/Parser.cpp"
    break;

  case 39:
#line 304 "./parser/Parser.y"
                                                { 
                                       (yyval.tmp_id) = MakeTermNode((yyvsp[0].data)->int_val, INT_NODE_TYPE);            
                                }
#line 2077 "./parser/Parser.cpp"
    break;

  case 40:
#line 307 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeTermNode((yyvsp[0].data)->dou_val, DOUBLE_NODE_TYPE);          
                                }
#line 2085 "./parser/Parser.cpp"
    break;

  case 41:
#line 310 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeTermNode((yyvsp[0].data)->flo_val, FLOAT_NODE_TYPE);            
                                }
#line 2093 "./parser/Parser.cpp"
    break;

  case 42:
#line 313 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeTermNode((string)(yyvsp[0].data)->str_val, STRING_NODE_TYPE);                   
                                }
#line 2101 "./parser/Parser.cpp"
    break;

  case 43:
#line 316 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeTermNode((yyvsp[0].data)->char_val, CHAR_NODE_TYPE);
                                }
#line 2109 "./parser/Parser.cpp"
    break;

  case 44:
#line 319 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeTermNode((yyvsp[0].data)->bol_val, BOOL_NODE_TYPE);
                                }
#line 2117 "./parser/Parser.cpp"
    break;

  case 45:
#line 322 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = (yyvsp[0].tmp_id);       
                                }
#line 2125 "./parser/Parser.cpp"
    break;

  case 46:
#line 325 "./parser/Parser.y"
                                                                           {
                                    (yyval.tmp_id) = MakeArrayTermAst((yyvsp[-2].tmp_id));
                                }
#line 2133 "./parser/Parser.cpp"
    break;

  case 47:
#line 328 "./parser/Parser.y"
                                          {
                                    (yyval.tmp_id) = MakeTermNode(0, ARRAY_NODE_TYPE);
                                }
#line 2141 "./parser/Parser.cpp"
    break;

  case 48:
#line 331 "./parser/Parser.y"
                                                               {
                                    (yyval.tmp_id) = MakeMapTermAst((yyvsp[-1].tmp_id));
                                }
#line 2149 "./parser/Parser.cpp"
    break;

  case 49:
#line 334 "./parser/Parser.y"
                                          {
                                    (yyval.tmp_id) = MakeTermNode(0, MAP_NODE_TYPE);
                                }
#line 2157 "./parser/Parser.cpp"
    break;

  case 50:
#line 339 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types); }
#line 2163 "./parser/Parser.cpp"
    break;

  case 51:
#line 340 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types); }
#line 2169 "./parser/Parser.cpp"
    break;

  case 52:
#line 341 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types); }
#line 2175 "./parser/Parser.cpp"
    break;

  case 53:
#line 342 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types); }
#line 2181 "./parser/Parser.cpp"
    break;

  case 54:
#line 343 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types); }
#line 2187 "./parser/Parser.cpp"
    break;

  case 55:
#line 344 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types); }
#line 2193 "./parser/Parser.cpp"
    break;

  case 56:
#line 345 "./parser/Parser.y"
                                       {
                                    (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types);
                                }
#line 2201 "./parser/Parser.cpp"
    break;

  case 57:
#line 348 "./parser/Parser.y"
                                      {
                                    (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types);
                                }
#line 2209 "./parser/Parser.cpp"
    break;

  case 58:
#line 353 "./parser/Parser.y"
                                                                            {
                                   (yyval.tmp_id) = (yyvsp[-4].tmp_id);
                                   (yyval.tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id));
                                }
#line 2218 "./parser/Parser.cpp"
    break;

  case 59:
#line 357 "./parser/Parser.y"
                                                                           {
                                    (yyval.tmp_id) = (yyvsp[-4].tmp_id);
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id));
                                }
#line 2227 "./parser/Parser.cpp"
    break;

  case 64:
#line 367 "./parser/Parser.y"
                                   {
                                    (yyval.tmp_id) = MakeTermNode((string)(yyvsp[0].data)->id, ID_NODE_TYPE);
                                }
#line 2235 "./parser/Parser.cpp"
    break;

  case 65:
#line 371 "./parser/Parser.y"
                                                                                                 {
                                    (yyval.tmp_id) = MakeAssignAst((yyvsp[-8].tmp_id), (yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2243 "./parser/Parser.cpp"
    break;

  case 66:
#line 374 "./parser/Parser.y"
                                                                                                     {
                                    (yyval.tmp_id) = MakeUnionAst((yyvsp[-8].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2251 "./parser/Parser.cpp"
    break;

  case 67:
#line 377 "./parser/Parser.y"
                                                                                                                {
                                    (yyval.tmp_id) = MakeUnionAst((yyvsp[-10].tmp_id), (yyvsp[-5].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2259 "./parser/Parser.cpp"
    break;

  case 68:
#line 380 "./parser/Parser.y"
                                                                           {
                                   (yyval.tmp_id) = MakeReassignAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2267 "./parser/Parser.cpp"
    break;

  case 69:
#line 383 "./parser/Parser.y"
                                                                                                                      {
                                    (yyval.tmp_id) = MakeRefAst((yyvsp[-12].tmp_id), (yyvsp[-8].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2275 "./parser/Parser.cpp"
    break;

  case 70:
#line 386 "./parser/Parser.y"
                                                                                              {
                                    (yyval.tmp_id) = MakeRebindRefAst((yyvsp[-8].tmp_id), (yyvsp[-6].tmp_id));
                                }
#line 2283 "./parser/Parser.cpp"
    break;

  case 71:
#line 392 "./parser/Parser.y"
                                           {
                                    (yyval.tmp_id) = new AstNode();
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id));
                                }
#line 2292 "./parser/Parser.cpp"
    break;

  case 72:
#line 396 "./parser/Parser.y"
                                                   {
                                    (yyval.tmp_id) = new AstNode();
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id));
                                }
#line 2301 "./parser/Parser.cpp"
    break;

  case 73:
#line 400 "./parser/Parser.y"
                                                             {  
                                    (yyvsp[-2].tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id));
                                    (yyval.tmp_id) = (yyvsp[-2].tmp_id);
                                }
#line 2310 "./parser/Parser.cpp"
    break;

  case 74:
#line 404 "./parser/Parser.y"
                                                                  {
                                    (yyvsp[-2].tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id));
                                    (yyval.tmp_id) = (yyvsp[-2].tmp_id);
                                }
#line 2319 "./parser/Parser.cpp"
    break;

  case 79:
#line 414 "./parser/Parser.y"
                                                                            { 
                                    (yyval.tmp_id) = MakePrintAst((yyvsp[-2].tmp_id));
                                }
#line 2327 "./parser/Parser.cpp"
    break;

  case 80:
#line 417 "./parser/Parser.y"
                                                     { Destroy(); return 0; (yyval.tmp_id) = nullptr; }
#line 2333 "./parser/Parser.cpp"
    break;

  case 81:
#line 422 "./parser/Parser.y"
                                                           {
                                    Perform((yyval.tmp_id), (yyvsp[-1].tmp_id), ADDITION_CMD);
                                }
#line 2341 "./parser/Parser.cpp"
    break;

  case 82:
#line 425 "./parser/Parser.y"
                                                                         {
                                    Perform((yyval.tmp_id), (yyvsp[-2].tmp_id), SUBTRACTION_CMD);
                                }
#line 2349 "./parser/Parser.cpp"
    break;

  case 83:
#line 428 "./parser/Parser.y"
                                                                          {
                                    Perform((yyval.tmp_id), (yyvsp[-2].tmp_id), MULTIPLY_CMD);
                                }
#line 2357 "./parser/Parser.cpp"
    break;

  case 84:
#line 431 "./parser/Parser.y"
                                                                          {
                                    Perform((yyval.tmp_id), (yyvsp[-2].tmp_id), DIVIDE_CMD);
                                }
#line 2365 "./parser/Parser.cpp"
    break;

  case 85:
#line 434 "./parser/Parser.y"
                                                                          {
                                    Perform((yyval.tmp_id), (yyvsp[-2].tmp_id), POW_CMD);
                                }
#line 2373 "./parser/Parser.cpp"
    break;

  case 86:
#line 437 "./parser/Parser.y"
                                                                        {
                                    (yyval.tmp_id) = MakeIncAst((yyvsp[-2].tmp_id));
                                }
#line 2381 "./parser/Parser.cpp"
    break;

  case 87:
#line 440 "./parser/Parser.y"
                                                                                                {
                                    (yyval.tmp_id) = MakeModAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2389 "./parser/Parser.cpp"
    break;

  case 88:
#line 448 "./parser/Parser.y"
                                                                                           {
                                    (yyval.tmp_id) = MakeLessCompAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2397 "./parser/Parser.cpp"
    break;

  case 89:
#line 451 "./parser/Parser.y"
                                                                                                {
                                    (yyval.tmp_id) = MakeGreaterCompAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2405 "./parser/Parser.cpp"
    break;

  case 90:
#line 454 "./parser/Parser.y"
                                                                                                  {
                                    (yyval.tmp_id) = MakeLessEqualCompAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2413 "./parser/Parser.cpp"
    break;

  case 91:
#line 457 "./parser/Parser.y"
                                                                                                      {
                                    (yyval.tmp_id) = MakeGreaterEqualCompAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2421 "./parser/Parser.cpp"
    break;

  case 92:
#line 460 "./parser/Parser.y"
                                                                                             {
                                    (yyval.tmp_id) = MakeEqualCompAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2429 "./parser/Parser.cpp"
    break;

  case 93:
#line 463 "./parser/Parser.y"
                                                                                                  {
                                    (yyval.tmp_id) = MakeNotEqualCompAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2437 "./parser/Parser.cpp"
    break;

  case 94:
#line 470 "./parser/Parser.y"
                                                                                         {
                                    (yyval.tmp_id) = MakeAndAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2445 "./parser/Parser.cpp"
    break;

  case 95:
#line 473 "./parser/Parser.y"
                                                                 {
                                    (yyval.tmp_id) = MakeNotAst((yyvsp[-2].tmp_id));
                                }
#line 2453 "./parser/Parser.cpp"
    break;

  case 96:
#line 476 "./parser/Parser.y"
                                                                                           {
                                    (yyval.tmp_id) = MakeOrAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2461 "./parser/Parser.cpp"
    break;

  case 97:
#line 482 "./parser/Parser.y"
                                                                  {
                                    (yyval.tmp_id) = MakeGetFromCollectionAst((yyvsp[-3].tmp_id), (yyvsp[-1].tmp_id));
                                }
#line 2469 "./parser/Parser.cpp"
    break;

  case 98:
#line 488 "./parser/Parser.y"
                                     {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2477 "./parser/Parser.cpp"
    break;

  case 99:
#line 491 "./parser/Parser.y"
                                            {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2485 "./parser/Parser.cpp"
    break;

  case 100:
#line 494 "./parser/Parser.y"
                                                                                          {
                                    (yyval.tmp_id) = MakeCastAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2493 "./parser/Parser.cpp"
    break;

  case 101:
#line 497 "./parser/Parser.y"
                                               {
                                   (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2501 "./parser/Parser.cpp"
    break;

  case 102:
#line 500 "./parser/Parser.y"
                                           {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2509 "./parser/Parser.cpp"
    break;

  case 103:
#line 503 "./parser/Parser.y"
                                                                                           {
                                     (yyval.tmp_id) = MakeAddToListAst((yyvsp[-7].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2517 "./parser/Parser.cpp"
    break;

  case 104:
#line 506 "./parser/Parser.y"
                                                                                                          {
                                    (yyval.tmp_id) = MakeAddToMapAst((yyvsp[-9].tmp_id), (yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2525 "./parser/Parser.cpp"
    break;

  case 105:
#line 509 "./parser/Parser.y"
                                                {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2533 "./parser/Parser.cpp"
    break;

  case 106:
#line 512 "./parser/Parser.y"
                                                                                                            {
                                    (yyval.tmp_id) = MakeSetInCollectionAst((yyvsp[-9].tmp_id), (yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2541 "./parser/Parser.cpp"
    break;

  case 107:
#line 515 "./parser/Parser.y"
                                                      {
                                    (yyval.tmp_id) = MakeCollectionSizeAst((yyvsp[-2].tmp_id));
                                }
#line 2549 "./parser/Parser.cpp"
    break;

  case 108:
#line 518 "./parser/Parser.y"
                                                        {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2557 "./parser/Parser.cpp"
    break;

  case 109:
#line 523 "./parser/Parser.y"
                                     { i.EatAst((yyvsp[0].tmp_id)); (yyvsp[0].tmp_id) = nullptr; }
#line 2563 "./parser/Parser.cpp"
    break;

  case 110:
#line 524 "./parser/Parser.y"
                                            { i.EatAst((yyvsp[0].tmp_id)); (yyvsp[0].tmp_id) = nullptr; }
#line 2569 "./parser/Parser.cpp"
    break;

  case 114:
#line 528 "./parser/Parser.y"
                                               { i.EatAst((yyvsp[0].tmp_id)); (yyvsp[0].tmp_id) = nullptr; }
#line 2575 "./parser/Parser.cpp"
    break;

  case 118:
#line 532 "./parser/Parser.y"
                                       {
                                    Destroy();
                                    return 0;
                                }
#line 2584 "./parser/Parser.cpp"
    break;

  case 119:
#line 536 "./parser/Parser.y"
                                        { return 0; }
#line 2590 "./parser/Parser.cpp"
    break;


#line 2594 "./parser/Parser.cpp"

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
#line 539 "./parser/Parser.y"



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
