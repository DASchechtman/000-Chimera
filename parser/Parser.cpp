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
    INT_VAL = 303,
    DOUBLE_VAL = 304,
    STRING_VAL = 305,
    CHAR_VAL = 306,
    BOOL_VAL = 307,
    ELSE_IF = 308,
    FLOAT_VAL = 309,
    ID = 310,
    UNKNOWN = 311,
    MULTI_WS = 312,
    SINGLE_WS = 313
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 34 "./parser/Parser.y"

    YYSTYPEs *data;
    AstNode *tmp_id;

#line 218 "./parser/Parser.cpp"

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
#define YYLAST   1092

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  121
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  374

#define YYUNDEFTOK  2
#define YYMAXUTOK   313


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
      65,    67,     2,     2,     2,     2,    70,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    59,     2,
      68,    66,    69,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,     2,    62,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    63,    60,    64,     2,     2,     2,     2,
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
      55,    56,    57,    58
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   125,   125,   127,   129,   133,   137,   141,   145,   159,
     168,   175,   182,   190,   196,   206,   211,   224,   225,   226,
     227,   227,   229,   233,   239,   242,   245,   248,   252,   257,
     257,   259,   260,   261,   264,   271,   279,   287,   295,   305,
     308,   311,   314,   317,   320,   323,   326,   329,   332,   335,
     340,   341,   342,   343,   344,   345,   346,   349,   354,   358,
     364,   364,   366,   366,   368,   372,   375,   378,   381,   384,
     387,   393,   397,   401,   405,   411,   412,   412,   414,   415,
     418,   423,   426,   429,   432,   435,   438,   441,   449,   452,
     455,   458,   461,   464,   471,   474,   477,   483,   489,   492,
     495,   498,   501,   504,   507,   510,   513,   516,   519,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   537,
     539,   539
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
  "SURO", "INT_VAL", "DOUBLE_VAL", "STRING_VAL", "CHAR_VAL", "BOOL_VAL",
  "ELSE_IF", "FLOAT_VAL", "ID", "UNKNOWN", "MULTI_WS", "SINGLE_WS", "':'",
  "'|'", "'['", "']'", "'{'", "'}'", "'('", "'='", "')'", "'<'", "'>'",
  "'.'", "$accept", "start", "end", "ifHead", "elseIfHead", "elseHead",
  "whileHead", "forloopHead", "paramList", "functionHead", "functionCall",
  "ifBody", "elseIfBody", "elseBody", "elseIfChain", "whileStatement",
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,    58,
     124,    91,    93,   123,   125,    40,    61,    41,    60,    62,
      46
};
# endif

#define YYPACT_NINF (-135)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-64)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     991,  -135,   -56,   -57,  -135,  -135,  -135,  -135,   -56,   -56,
     -56,   -56,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,
    -135,   -37,   -51,   559,   991,   991,   991,   991,   991,  -135,
     -11,  -135,  -135,  -135,  -135,  -135,  -135,  -135,    23,  -135,
    -135,  -135,  -135,  -135,  -135,   -35,  -135,   415,  -135,   -33,
     -56,   469,   469,   469,    -6,  -135,    21,  -135,   312,  -135,
      -9,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,
     771,   650,   815,   859,   903,  -135,   -56,   -56,   991,   991,
    -135,    31,    61,    30,   130,  -135,  -135,   -56,    39,  1046,
    -135,    34,    34,    34,   -56,   -56,   -56,  -135,   -56,    -4,
     -17,   469,   469,   469,   469,   469,   469,   469,   469,   469,
     469,   245,    17,   469,   -56,   -56,   -56,   -56,   469,   469,
      -6,    -6,  -135,  -135,  -135,  -135,  -135,    65,   469,   716,
     947,  -135,  -135,  -135,    68,    81,    49,    55,    59,  -135,
     -56,  -135,    93,    95,    74,    72,  -135,   312,   312,    71,
     312,   -56,  -135,  -135,    -1,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,   -35,  -135,   469,    21,   469,
     -35,   469,    70,    75,    80,    90,    34,    34,   -56,   -56,
    -135,    34,  -135,  -135,   -56,   -56,   -56,   -56,    98,  -135,
    -135,   -56,   226,  -135,  -135,  -135,   -56,  -135,   -56,  -135,
     492,   469,   469,   469,   469,   469,   469,   469,   469,    99,
     -35,   -35,  -135,  -135,  -135,  -135,   100,   469,   469,   469,
     101,   132,   109,   469,   469,   469,  -135,    -6,  -135,  -135,
    -135,  -135,  -135,  -135,  -135,  -135,   111,   -56,  -135,   116,
     141,  -135,   -56,    34,    34,    34,    34,    34,    34,    34,
      34,  -135,  -135,    34,   -12,    34,   -56,  -135,  -135,    34,
      34,    34,   -56,   -56,   118,   117,   -56,   -56,   112,   114,
     115,   119,   121,   122,   123,   124,   125,   129,  -135,   -44,
      57,   137,   469,   469,   147,   492,  -135,   126,   139,   492,
     312,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,
    -135,  -135,   158,   -56,   492,   -56,  -135,    34,    34,  -135,
     -56,   -56,   -56,  -135,   -56,   133,   469,   -56,    54,   469,
     131,   143,   145,   172,   492,   492,   149,   -56,    34,   151,
     -56,   152,    34,   187,  -135,  -135,  -135,  -135,   -56,  -135,
     148,   150,   -56,   469,   -56,   153,   154,   180,  -135,  -135,
     492,    34,   492,  -135,   -56,  -135,  -135,   157,  -135,   469,
    -135,    34,   160,  -135
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,   119,    63,     0,    29,    30,   118,     2,     0,     0,
       0,     0,    39,    40,    42,    43,    44,    41,    64,    60,
      61,    63,    63,     0,     0,     0,     0,     0,     0,   114,
       0,   112,   113,   111,   108,   117,    98,   116,    45,    78,
     110,    99,   101,   102,   105,   109,   120,     0,    62,     0,
      63,     0,     0,     0,     0,    47,    76,    77,     0,    49,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    63,    63,    63,    63,    63,     0,     0,     0,    63,
       0,     0,     0,     0,     0,    24,     0,     0,     0,     0,
      20,     0,     0,     0,     0,     1,   121,    63,     0,     0,
      45,     0,     0,     0,    63,    63,    63,    31,    63,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    63,     0,    63,    63,    63,    63,     0,     0,
       0,     0,     3,   115,    22,    23,    28,     0,     0,     0,
       0,    27,    25,    21,     0,    63,     0,     0,     0,   107,
      63,    80,     0,     0,     0,     0,    75,    62,    77,     0,
       0,    63,    36,    48,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    63,    71,    81,    62,     0,     0,
      72,    77,     0,     0,     0,     0,    63,     0,     0,    63,
       6,     0,    26,    15,    63,    63,    63,    63,     0,     4,
       7,     0,     0,    32,    33,    46,    63,    35,    63,    38,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      73,    74,    82,    83,    84,    85,     0,     0,     0,    62,
       0,     0,     0,     0,     0,     0,    79,     0,    50,    51,
      52,    53,    54,    55,    56,    57,     0,    63,    10,     0,
       0,    37,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    95,    86,    63,     0,    63,    63,     5,    16,    63,
       0,     0,     0,    63,    62,     0,    63,    63,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    97,     0,
       0,     0,     0,     0,     0,     0,    12,     0,     0,     0,
       0,   100,    88,    89,    90,    91,    92,    93,    94,    96,
      87,    68,     0,     0,     0,    63,   103,    63,    63,     8,
       0,    63,    63,     9,    63,     0,     0,    63,    63,    62,
       0,     0,     0,     0,     0,     0,     0,    63,    63,     0,
       0,     0,    63,     0,   104,   106,    13,    11,     0,    34,
       0,     0,    63,     0,    63,     0,     0,     0,    70,    66,
       0,    63,     0,    65,     0,    14,    58,     0,    59,     0,
      67,    63,     0,    69
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,
    -135,  -135,   127,   146,  -135,  -135,  -135,  -135,  -135,  -135,
    -135,   134,  -135,   -50,  -134,  -135,   321,    -2,     5,  -135,
     -63,    24,    28,  -135,  -135,  -135,  -135,  -135,   431,   -43,
     -10
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    24,   133,    25,    88,    89,    26,    27,   247,    28,
      29,    30,    90,    91,    92,    31,    32,    33,    34,    35,
     106,   109,   110,    36,   248,   328,    48,    56,   100,    39,
     122,   123,    58,    40,    41,    42,    43,    44,    45,    46,
      47
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    19,    20,    50,    96,    38,    19,    20,   107,   124,
     125,   126,   127,    59,    80,    81,    82,    83,    84,   161,
      19,    20,   208,   311,   312,    55,    85,    97,    86,    38,
      38,    38,    38,    38,   150,    94,    93,    96,    96,    96,
      96,    96,    87,   108,   105,    57,    57,   163,    98,    18,
      60,   108,    38,    19,    20,   288,    19,    20,    94,   104,
     238,   239,   240,   241,   242,   243,   244,   245,   141,   121,
     121,   121,   121,   121,    19,    20,   252,   131,   139,   140,
      19,    20,   194,   -63,   176,    38,    38,    38,    38,    38,
     145,    19,    20,    38,    38,   121,    96,    96,   142,   151,
      86,   190,   155,   156,    94,   192,   160,   203,   204,   195,
     206,    19,    20,   313,    87,   196,   340,   201,   314,   197,
     178,   238,   239,   240,   241,   242,   243,   244,   245,   199,
     158,   200,   202,   205,   159,   188,   189,   222,    19,    20,
     296,   193,   223,   121,    38,    38,   179,   224,   181,   181,
     181,   181,   182,   183,   184,   185,   315,   225,   236,   207,
     266,   320,   146,   147,   148,   323,   261,   262,   267,   268,
     273,   149,   219,    18,   181,   276,   277,   298,   198,   301,
     327,   302,   303,   319,   325,   321,   304,   230,   305,   306,
     307,   308,   309,   233,   234,   235,   310,   316,   322,   343,
     347,   348,   337,   344,   250,   345,   251,   249,   346,   349,
      57,   352,   354,   356,   226,   358,   365,   359,   181,   143,
     363,     0,   232,   364,   370,     0,   366,   373,   368,   238,
     239,   240,   241,   242,   243,   244,   245,     0,   144,     0,
       0,     0,   272,     0,   164,   275,     0,     0,     0,     0,
     324,   279,   280,   281,   282,   283,   284,   285,   286,     0,
       0,     0,     0,   289,   290,     0,     0,   291,   105,     0,
       0,   295,     0,     0,   299,   300,    57,     0,     0,   297,
     278,    18,     0,     0,     0,     0,   246,    57,     0,     0,
       0,   287,    11,    12,    13,    14,    15,    16,     0,    17,
      18,     0,     0,     0,     0,     0,    21,     0,    22,     0,
      99,     0,     0,   330,     0,   331,   332,     0,     0,   334,
     335,    37,   336,     0,     0,   339,   341,     0,     0,    51,
      52,    53,    54,     0,     0,   350,   351,     0,     0,     0,
     355,     0,     0,     0,     0,    37,    37,    37,    37,    37,
     360,     0,   362,     0,     0,     0,     0,     0,     0,   367,
      12,    13,    14,    15,    16,     0,    17,    18,    37,   372,
       0,     0,     0,    21,     0,    22,     0,     0,     0,     0,
       0,     0,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,     0,     0,     0,     0,     0,   128,   129,   130,
       0,    37,    37,    37,    37,    37,     0,   137,   138,    37,
      37,     0,     0,     0,     0,    95,     1,     0,     0,     0,
       0,     0,   152,   153,   154,     0,     0,   157,     0,     0,
     162,     0,     0,     2,     0,     0,     0,     3,     4,     5,
       6,     0,     0,   177,     0,   177,   177,   177,   177,     0,
       0,     7,     0,     8,     0,     9,     0,    10,     0,     0,
      37,    37,    11,    12,    13,    14,    15,    16,     0,    17,
      18,   177,    19,    20,     0,     0,    21,     0,    22,     0,
      23,     0,   101,   102,   103,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   238,   239,   240,   241,   242,
     243,   244,   245,     0,     0,     0,     0,     0,   227,   228,
     229,     0,   231,     0,     0,   177,    11,    12,    13,    14,
      15,    16,   237,    17,    18,     0,     0,     0,     0,     0,
      21,     0,    22,     0,    99,     0,     0,     0,     0,     0,
       0,     0,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,     0,   180,     0,     0,     0,     0,   186,
     187,     0,     0,     0,     0,     0,     0,     0,   274,   191,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,     0,     0,     0,     0,     0,    71,    72,    73,    74,
      75,   292,   293,   294,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    76,    77,    78,     0,     0,   220,     0,
     221,     0,   221,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    79,     0,     0,     0,     0,
       0,     0,     0,     0,   326,     0,   329,     0,     0,     0,
       0,   333,   253,   254,   255,   256,   257,   258,   259,   260,
       0,     1,     0,     0,     0,     0,     0,     0,   263,   264,
     265,   353,     0,     0,   269,   270,   271,     0,     2,   357,
       0,     0,     3,     4,     5,     6,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   369,     7,   -17,     8,   -17,
       9,     0,    10,     0,     0,     0,     0,    11,    12,    13,
      14,    15,    16,   -17,    17,    18,     0,    19,    20,     0,
       0,    21,     0,    22,     0,    23,     0,     1,     0,     0,
       0,     0,     0,   317,   318,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     0,     0,     0,     3,     4,
       5,     6,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,   -18,     8,   -18,     9,   338,    10,     0,
     342,     0,     0,    11,    12,    13,    14,    15,    16,   -18,
      17,    18,     1,    19,    20,     0,     0,    21,     0,    22,
       0,    23,     0,     0,   361,     0,     0,     0,     0,     2,
       0,     0,     0,     3,     4,     5,     6,     0,     0,     0,
     371,     0,     0,     0,     0,     0,     0,     7,   132,     8,
       0,     9,     0,    10,     0,     0,     1,     0,    11,    12,
      13,    14,    15,    16,     0,    17,    18,     0,    19,    20,
       0,     0,    21,     2,    22,     0,    23,     3,     4,     5,
       6,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,   134,     8,     0,     9,     0,    10,     0,     0,
       1,     0,    11,    12,    13,    14,    15,    16,     0,    17,
      18,     0,    19,    20,     0,     0,    21,     2,    22,     0,
      23,     3,     4,     5,     6,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,   135,     8,     0,     9,
       0,    10,     0,     0,     1,     0,    11,    12,    13,    14,
      15,    16,     0,    17,    18,     0,    19,    20,     0,     0,
      21,     2,    22,     0,    23,     3,     4,     5,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
     136,     8,     0,     9,     0,    10,     0,     0,     1,     0,
      11,    12,    13,    14,    15,    16,     0,    17,    18,     0,
      19,    20,     0,     0,    21,     2,    22,     0,    23,     3,
       4,     5,     6,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,   -19,     8,     0,     9,     0,    10,
       0,     0,     1,     0,    11,    12,    13,    14,    15,    16,
       0,    17,    18,     0,    19,    20,     0,     0,    21,     2,
      22,     0,    23,     3,     4,     5,     6,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     0,     8,
       0,     9,     0,    10,     0,     0,     0,     0,    11,    12,
      13,    14,    15,    16,     0,    17,    18,     0,    19,    20,
       0,     0,    21,     0,    22,     0,    23,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,     0,     0,
       0,     0,     0,    71,    72,    73,    74,    75,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      76,    77,    78
};

static const yytype_int16 yycheck[] =
{
       2,    57,    58,    60,    47,     0,    57,    58,    58,    72,
      73,    74,    75,    64,    24,    25,    26,    27,    28,    23,
      57,    58,    23,    67,    68,    62,    37,    60,    39,    24,
      25,    26,    27,    28,    97,    70,    38,    80,    81,    82,
      83,    84,    53,    60,    23,    21,    22,    64,    50,    55,
      22,    60,    47,    57,    58,    67,    57,    58,    70,    54,
       3,     4,     5,     6,     7,     8,     9,    10,    37,    71,
      72,    73,    74,    75,    57,    58,   210,    79,    88,    89,
      57,    58,   145,    60,    67,    80,    81,    82,    83,    84,
      60,    57,    58,    88,    89,    97,   139,   140,    37,    60,
      39,    36,   104,   105,    70,    37,   108,   157,   158,    60,
     160,    57,    58,    56,    53,    60,    62,    43,    61,    60,
     122,     3,     4,     5,     6,     7,     8,     9,    10,    36,
     106,    36,    60,    62,   106,   130,   131,    67,    57,    58,
     274,    60,    67,   145,   139,   140,   122,    67,   124,   125,
     126,   127,   124,   125,   126,   127,   290,    67,    60,   161,
      59,   295,    32,    33,    34,   299,    67,    67,    36,    60,
      59,    41,   174,    55,   150,    59,    35,    60,   150,    67,
     314,    67,    67,    36,    26,    59,    67,   189,    67,    67,
      67,    67,    67,   195,   196,   197,    67,    60,    59,    68,
     334,   335,    69,    60,   206,    60,   208,   202,    36,    60,
     186,    60,    60,    26,   186,    67,    36,    67,   194,    92,
      67,    -1,   194,    69,    67,    -1,   360,    67,   362,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    92,    -1,
      -1,    -1,   237,    -1,   110,   247,    -1,    -1,    -1,    -1,
     300,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,   266,    -1,    -1,   269,    23,    -1,
      -1,   273,    -1,    -1,   276,   277,   252,    -1,    -1,   274,
     252,    55,    -1,    -1,    -1,    -1,    60,   263,    -1,    -1,
      -1,   263,    47,    48,    49,    50,    51,    52,    -1,    54,
      55,    -1,    -1,    -1,    -1,    -1,    61,    -1,    63,    -1,
      65,    -1,    -1,   315,    -1,   317,   318,    -1,    -1,   321,
     322,     0,   324,    -1,    -1,   327,   328,    -1,    -1,     8,
       9,    10,    11,    -1,    -1,   337,   338,    -1,    -1,    -1,
     342,    -1,    -1,    -1,    -1,    24,    25,    26,    27,    28,
     352,    -1,   354,    -1,    -1,    -1,    -1,    -1,    -1,   361,
      48,    49,    50,    51,    52,    -1,    54,    55,    47,   371,
      -1,    -1,    -1,    61,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    -1,    -1,    -1,    -1,    -1,    76,    77,    78,
      -1,    80,    81,    82,    83,    84,    -1,    86,    87,    88,
      89,    -1,    -1,    -1,    -1,     0,     1,    -1,    -1,    -1,
      -1,    -1,   101,   102,   103,    -1,    -1,   106,    -1,    -1,
     109,    -1,    -1,    18,    -1,    -1,    -1,    22,    23,    24,
      25,    -1,    -1,   122,    -1,   124,   125,   126,   127,    -1,
      -1,    36,    -1,    38,    -1,    40,    -1,    42,    -1,    -1,
     139,   140,    47,    48,    49,    50,    51,    52,    -1,    54,
      55,   150,    57,    58,    -1,    -1,    61,    -1,    63,    -1,
      65,    -1,    51,    52,    53,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,   187,   188,
     189,    -1,   191,    -1,    -1,   194,    47,    48,    49,    50,
      51,    52,   201,    54,    55,    -1,    -1,    -1,    -1,    -1,
      61,    -1,    63,    -1,    65,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,   123,    -1,    -1,    -1,    -1,   128,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   247,   138,
      11,    12,    13,    14,    15,    16,    17,    -1,    19,    20,
      21,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,   270,   271,   272,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    -1,    -1,   177,    -1,
     179,    -1,   181,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   313,    -1,   315,    -1,    -1,    -1,
      -1,   320,   211,   212,   213,   214,   215,   216,   217,   218,
      -1,     1,    -1,    -1,    -1,    -1,    -1,    -1,   227,   228,
     229,   340,    -1,    -1,   233,   234,   235,    -1,    18,   348,
      -1,    -1,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   364,    36,    37,    38,    39,
      40,    -1,    42,    -1,    -1,    -1,    -1,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    -1,
      -1,    61,    -1,    63,    -1,    65,    -1,     1,    -1,    -1,
      -1,    -1,    -1,   292,   293,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    37,    38,    39,    40,   326,    42,    -1,
     329,    -1,    -1,    47,    48,    49,    50,    51,    52,    53,
      54,    55,     1,    57,    58,    -1,    -1,    61,    -1,    63,
      -1,    65,    -1,    -1,   353,    -1,    -1,    -1,    -1,    18,
      -1,    -1,    -1,    22,    23,    24,    25,    -1,    -1,    -1,
     369,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,    38,
      -1,    40,    -1,    42,    -1,    -1,     1,    -1,    47,    48,
      49,    50,    51,    52,    -1,    54,    55,    -1,    57,    58,
      -1,    -1,    61,    18,    63,    -1,    65,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    37,    38,    -1,    40,    -1,    42,    -1,    -1,
       1,    -1,    47,    48,    49,    50,    51,    52,    -1,    54,
      55,    -1,    57,    58,    -1,    -1,    61,    18,    63,    -1,
      65,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    37,    38,    -1,    40,
      -1,    42,    -1,    -1,     1,    -1,    47,    48,    49,    50,
      51,    52,    -1,    54,    55,    -1,    57,    58,    -1,    -1,
      61,    18,    63,    -1,    65,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    -1,    40,    -1,    42,    -1,    -1,     1,    -1,
      47,    48,    49,    50,    51,    52,    -1,    54,    55,    -1,
      57,    58,    -1,    -1,    61,    18,    63,    -1,    65,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    -1,    40,    -1,    42,
      -1,    -1,     1,    -1,    47,    48,    49,    50,    51,    52,
      -1,    54,    55,    -1,    57,    58,    -1,    -1,    61,    18,
      63,    -1,    65,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    38,
      -1,    40,    -1,    42,    -1,    -1,    -1,    -1,    47,    48,
      49,    50,    51,    52,    -1,    54,    55,    -1,    57,    58,
      -1,    -1,    61,    -1,    63,    -1,    65,    11,    12,    13,
      14,    15,    16,    17,    -1,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    18,    22,    23,    24,    25,    36,    38,    40,
      42,    47,    48,    49,    50,    51,    52,    54,    55,    57,
      58,    61,    63,    65,    72,    74,    77,    78,    80,    81,
      82,    86,    87,    88,    89,    90,    94,    97,    99,   100,
     104,   105,   106,   107,   108,   109,   110,   111,    97,    98,
      60,    97,    97,    97,    97,    62,    98,   102,   103,    64,
     103,    11,    12,    13,    14,    15,    16,    17,    19,    20,
      21,    27,    28,    29,    30,    31,    44,    45,    46,    66,
     111,   111,   111,   111,   111,    37,    39,    53,    75,    76,
      83,    84,    85,    98,    70,     0,   110,    60,    98,    65,
      99,   109,   109,   109,    99,    23,    91,    94,    60,    92,
      93,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    98,   101,   102,   101,   101,   101,   101,    97,    97,
      97,    98,    37,    73,    37,    37,    37,    97,    97,   111,
     111,    37,    37,    83,    84,    60,    32,    33,    34,    41,
     101,    60,    97,    97,    97,    98,    98,    97,   102,   103,
      98,    23,    97,    64,    92,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,    67,    97,    98,   102,
     109,   102,   103,   103,   103,   103,   109,   109,    99,    99,
      36,   109,    37,    60,   101,    60,    60,    60,   103,    36,
      36,    43,    60,    94,    94,    62,    94,    98,    23,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    98,
     109,   109,    67,    67,    67,    67,   103,    97,    97,    97,
      98,    97,   103,    98,    98,    98,    60,    97,     3,     4,
       5,     6,     7,     8,     9,    10,    60,    79,    95,    99,
      98,    98,    95,   109,   109,   109,   109,   109,   109,   109,
     109,    67,    67,   109,   109,   109,    59,    36,    60,   109,
     109,   109,    99,    59,    97,    98,    59,    35,   103,    98,
      98,    98,    98,    98,    98,    98,    98,   103,    67,    98,
      98,    98,    97,    97,    97,    98,    95,    99,    60,    98,
      98,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    68,    56,    61,    95,    60,   109,   109,    36,
      95,    59,    59,    95,    94,    26,    97,    95,    96,    97,
      98,    98,    98,    97,    98,    98,    98,    69,   109,    98,
      62,    98,   109,    68,    60,    60,    36,    95,    95,    60,
      98,    98,    60,    97,    60,    98,    26,    97,    67,    67,
      98,   109,    98,    67,    69,    36,    95,    98,    95,    97,
      67,   109,    98,    67
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      79,    79,    79,    80,    80,    81,    81,    82,    83,    84,
      85,    85,    86,    87,    88,    88,    88,    88,    89,    90,
      90,    91,    91,    91,    92,    93,    93,    93,    93,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      95,    95,    95,    95,    95,    95,    95,    95,    96,    96,
      97,    97,    98,    98,    99,   100,   100,   100,   100,   100,
     100,   101,   101,   101,   101,   102,   103,   103,   104,   104,
     104,   105,   105,   105,   105,   105,   105,   105,   106,   106,
     106,   106,   106,   106,   107,   107,   107,   108,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     111,   111
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     5,     5,     3,     5,     9,     4,
       1,     6,     3,    11,    13,     4,     6,     2,     2,     2,
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
#line 125 "./parser/Parser.y"
                                      { i.EatAst(MakeStartAst()); }
#line 1781 "./parser/Parser.cpp"
    break;

  case 3:
#line 127 "./parser/Parser.y"
                                    { i.EatAst(MakeEndScopeAst()); }
#line 1787 "./parser/Parser.cpp"
    break;

  case 4:
#line 129 "./parser/Parser.y"
                                                            {
                                    i.EatAst(MakeIfDeclAst((yyvsp[-2].tmp_id)));
                                }
#line 1795 "./parser/Parser.cpp"
    break;

  case 5:
#line 133 "./parser/Parser.y"
                                                                 {
                                    i.EatAst(MakeElifDeclAst((yyvsp[-2].tmp_id)));
                                }
#line 1803 "./parser/Parser.cpp"
    break;

  case 6:
#line 137 "./parser/Parser.y"
                                                 {
                                    i.EatAst(MakeElseDeclAst());
                                }
#line 1811 "./parser/Parser.cpp"
    break;

  case 7:
#line 141 "./parser/Parser.y"
                                                               {
                                    i.EatAst(MakeWhileDeclAst((yyvsp[-2].tmp_id)));
                                }
#line 1819 "./parser/Parser.cpp"
    break;

  case 8:
#line 145 "./parser/Parser.y"
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
#line 1837 "./parser/Parser.cpp"
    break;

  case 9:
#line 159 "./parser/Parser.y"
                                                    {
                                    auto param = new AstNode();
                                    param->AddToLeftNodes((yyvsp[-3].tmp_id));
                                    param->AddToRightNodes((yyvsp[0].tmp_id));
                                    auto list = new AstNode();
                                    list->AddToLeftNodes(param);
                                    (yyval.tmp_id) = list;

                                }
#line 1851 "./parser/Parser.cpp"
    break;

  case 10:
#line 168 "./parser/Parser.y"
                                        {
                                    auto param = new AstNode();
                                    param->AddToRightNodes((yyvsp[0].tmp_id));
                                    auto list = new AstNode();
                                    list->AddToLeftNodes(param);
                                    (yyval.tmp_id) = list;
                                }
#line 1863 "./parser/Parser.cpp"
    break;

  case 11:
#line 175 "./parser/Parser.y"
                                                                             {
                                    auto param = new AstNode();
                                    param->AddToLeftNodes((yyvsp[-3].tmp_id));
                                    param->AddToRightNodes((yyvsp[0].tmp_id));
                                    (yyvsp[-5].tmp_id)->AddToLeftNodes(param);
                                    (yyval.tmp_id) = (yyvsp[-5].tmp_id);
                                }
#line 1875 "./parser/Parser.cpp"
    break;

  case 12:
#line 182 "./parser/Parser.y"
                                                               {
                                    auto param = new AstNode();
                                    param->AddToRightNodes((yyvsp[0].tmp_id));
                                    (yyvsp[-2].tmp_id)->AddToLeftNodes(param);
                                    (yyval.tmp_id) = (yyvsp[-2].tmp_id);
                                }
#line 1886 "./parser/Parser.cpp"
    break;

  case 13:
#line 190 "./parser/Parser.y"
                                                                                            {
                                    (yyval.tmp_id) = MakeNode(MAKE_FUNC_CMD);
                                    (yyval.tmp_id)->AddToLeftNodes((yyvsp[-8].tmp_id));
                                    (yyval.tmp_id)->AddToRightNodes((yyvsp[-2].tmp_id));
                                    i.EatAst((yyval.tmp_id));
                                }
#line 1897 "./parser/Parser.cpp"
    break;

  case 14:
#line 196 "./parser/Parser.y"
                                                                                                               {
                                    (yyval.tmp_id) = MakeNode(MAKE_FUNC_CMD);
                                    (yyval.tmp_id)->AddToLeftNodes((yyvsp[-10].tmp_id));
                                    (yyval.tmp_id)->AddToMiddleNodes((yyvsp[-7].tmp_id));
                                    (yyval.tmp_id)->AddToRightNodes((yyvsp[-2].tmp_id));
                                    i.EatAst((yyval.tmp_id));
                                    (yyval.tmp_id) = nullptr;
                                }
#line 1910 "./parser/Parser.cpp"
    break;

  case 15:
#line 206 "./parser/Parser.y"
                                                  {
                                    auto func_call = MakeNode(CALL_FUNC_CMD);
                                    func_call->AddToLeftNodes((yyvsp[-3].tmp_id));
                                    (yyval.tmp_id) = func_call;
                                }
#line 1920 "./parser/Parser.cpp"
    break;

  case 16:
#line 211 "./parser/Parser.y"
                                                                          {
                                    auto func_call = MakeNode(CALL_FUNC_CMD);
                                    auto list = (yyvsp[-2].tmp_id);
                                    auto id = (yyvsp[-5].tmp_id);
                                    func_call->AddToLeftNodes((yyvsp[-5].tmp_id));
                                    auto end = (yyvsp[-2].tmp_id)->Extras();
                                    for(size_t iter = 0; iter < end; iter++) {
                                        func_call->AddToRightNodes((yyvsp[-2].tmp_id)->GetExtraNode(iter));
                                    }
                                    (yyval.tmp_id) = func_call;
                                }
#line 1936 "./parser/Parser.cpp"
    break;

  case 22:
#line 229 "./parser/Parser.y"
                                                   {
                                    i.EatAst(MakeEndCtrlScopeAst());
                                }
#line 1944 "./parser/Parser.cpp"
    break;

  case 23:
#line 233 "./parser/Parser.y"
                                                     {
                                    i.EatAst(MakeIncAst((yyvsp[-2].tmp_id)));
                                    i.EatAst(MakeEndCtrlScopeAst());
                                    i.EatAst(MakeEndScopeAst());  
                                }
#line 1954 "./parser/Parser.cpp"
    break;

  case 24:
#line 239 "./parser/Parser.y"
                                           {
                                    i.EatAst(MakeEndCtrlScopeAst());
                                }
#line 1962 "./parser/Parser.cpp"
    break;

  case 25:
#line 242 "./parser/Parser.y"
                                                         {
                                    i.EatAst(MakeEndCtrlScopeAst());
                                }
#line 1970 "./parser/Parser.cpp"
    break;

  case 26:
#line 245 "./parser/Parser.y"
                                                                  {
                                    i.EatAst(MakeEndCtrlScopeAst());
                                }
#line 1978 "./parser/Parser.cpp"
    break;

  case 27:
#line 248 "./parser/Parser.y"
                                                      {
                                    i.EatAst(MakeEndCtrlScopeAst());
                                }
#line 1986 "./parser/Parser.cpp"
    break;

  case 28:
#line 252 "./parser/Parser.y"
                                                      {
                                    (yyval.tmp_id) = MakeNode(FUNC_RETR_CMD);
                                }
#line 1994 "./parser/Parser.cpp"
    break;

  case 31:
#line 259 "./parser/Parser.y"
                                     { (yyval.tmp_id) = (yyvsp[0].tmp_id); }
#line 2000 "./parser/Parser.cpp"
    break;

  case 32:
#line 260 "./parser/Parser.y"
                                                          { (yyvsp[-2].tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id)); (yyval.tmp_id) = (yyvsp[-2].tmp_id); }
#line 2006 "./parser/Parser.cpp"
    break;

  case 33:
#line 261 "./parser/Parser.y"
                                                               {(yyvsp[-2].tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id)); (yyval.tmp_id) = (yyvsp[-2].tmp_id); }
#line 2012 "./parser/Parser.cpp"
    break;

  case 34:
#line 264 "./parser/Parser.y"
                                                                                                  {
                                    (yyval.tmp_id) = new AstNode();
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[-6].tmp_id));
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[-2].tmp_id));
                                }
#line 2022 "./parser/Parser.cpp"
    break;

  case 35:
#line 271 "./parser/Parser.y"
                                                               {
                                    (yyval.tmp_id) = new AstNode();
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[-2].tmp_id)->GetExtraNode());
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[-2].tmp_id)->GetExtraNode(1));
                                    (yyvsp[-2].tmp_id)->NullExtraNode(0);
                                    (yyvsp[-2].tmp_id)->NullExtraNode(1);
                                    delete (yyvsp[-2].tmp_id);
                                }
#line 2035 "./parser/Parser.cpp"
    break;

  case 36:
#line 279 "./parser/Parser.y"
                                                         {
                                    (yyval.tmp_id) = new AstNode();
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[-1].tmp_id)->GetExtraNode());
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[-1].tmp_id)->GetExtraNode(1));
                                    (yyvsp[-1].tmp_id)->NullExtraNode(0);
                                    (yyvsp[-1].tmp_id)->NullExtraNode(1);
                                    delete (yyvsp[-1].tmp_id);
                                }
#line 2048 "./parser/Parser.cpp"
    break;

  case 37:
#line 287 "./parser/Parser.y"
                                                                               {
                                    (yyvsp[-3].tmp_id)->SaveAsExtraNode((yyvsp[-2].tmp_id)->GetExtraNode());
                                    (yyvsp[-3].tmp_id)->SaveAsExtraNode((yyvsp[-2].tmp_id)->GetExtraNode(1));
                                    (yyvsp[-2].tmp_id)->NullExtraNode(0);
                                    (yyvsp[-2].tmp_id)->NullExtraNode(1);
                                    delete (yyvsp[-2].tmp_id);
                                    (yyval.tmp_id) = (yyvsp[-3].tmp_id);
                                }
#line 2061 "./parser/Parser.cpp"
    break;

  case 38:
#line 295 "./parser/Parser.y"
                                                                       {
                                    (yyvsp[-2].tmp_id)->SaveAsExtraNode((yyvsp[-1].tmp_id)->GetExtraNode());
                                    (yyvsp[-2].tmp_id)->SaveAsExtraNode((yyvsp[-1].tmp_id)->GetExtraNode(1));
                                    (yyvsp[-1].tmp_id)->NullExtraNode(0);
                                    (yyvsp[-1].tmp_id)->NullExtraNode(1);
                                    delete (yyvsp[-1].tmp_id);
                                    (yyval.tmp_id) = (yyvsp[-2].tmp_id);
                                }
#line 2074 "./parser/Parser.cpp"
    break;

  case 39:
#line 305 "./parser/Parser.y"
                                                { 
                                       (yyval.tmp_id) = MakeTermNode((yyvsp[0].data)->int_val, INT_NODE_TYPE);            
                                }
#line 2082 "./parser/Parser.cpp"
    break;

  case 40:
#line 308 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeTermNode((yyvsp[0].data)->dou_val, DOUBLE_NODE_TYPE);          
                                }
#line 2090 "./parser/Parser.cpp"
    break;

  case 41:
#line 311 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeTermNode((yyvsp[0].data)->flo_val, FLOAT_NODE_TYPE);            
                                }
#line 2098 "./parser/Parser.cpp"
    break;

  case 42:
#line 314 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeTermNode((string)(yyvsp[0].data)->str_val, STRING_NODE_TYPE);                   
                                }
#line 2106 "./parser/Parser.cpp"
    break;

  case 43:
#line 317 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeTermNode((yyvsp[0].data)->char_val, CHAR_NODE_TYPE);
                                }
#line 2114 "./parser/Parser.cpp"
    break;

  case 44:
#line 320 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeTermNode((yyvsp[0].data)->bol_val, BOOL_NODE_TYPE);
                                }
#line 2122 "./parser/Parser.cpp"
    break;

  case 45:
#line 323 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = (yyvsp[0].tmp_id);       
                                }
#line 2130 "./parser/Parser.cpp"
    break;

  case 46:
#line 326 "./parser/Parser.y"
                                                                           {
                                    (yyval.tmp_id) = MakeArrayTermAst((yyvsp[-2].tmp_id));
                                }
#line 2138 "./parser/Parser.cpp"
    break;

  case 47:
#line 329 "./parser/Parser.y"
                                          {
                                    (yyval.tmp_id) = MakeTermNode(0, ARRAY_NODE_TYPE);
                                }
#line 2146 "./parser/Parser.cpp"
    break;

  case 48:
#line 332 "./parser/Parser.y"
                                                               {
                                    (yyval.tmp_id) = MakeMapTermAst((yyvsp[-1].tmp_id));
                                }
#line 2154 "./parser/Parser.cpp"
    break;

  case 49:
#line 335 "./parser/Parser.y"
                                          {
                                    (yyval.tmp_id) = MakeTermNode(0, MAP_NODE_TYPE);
                                }
#line 2162 "./parser/Parser.cpp"
    break;

  case 50:
#line 340 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types); }
#line 2168 "./parser/Parser.cpp"
    break;

  case 51:
#line 341 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types); }
#line 2174 "./parser/Parser.cpp"
    break;

  case 52:
#line 342 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types); }
#line 2180 "./parser/Parser.cpp"
    break;

  case 53:
#line 343 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types); }
#line 2186 "./parser/Parser.cpp"
    break;

  case 54:
#line 344 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types); }
#line 2192 "./parser/Parser.cpp"
    break;

  case 55:
#line 345 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types); }
#line 2198 "./parser/Parser.cpp"
    break;

  case 56:
#line 346 "./parser/Parser.y"
                                       {
                                    (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types);
                                }
#line 2206 "./parser/Parser.cpp"
    break;

  case 57:
#line 349 "./parser/Parser.y"
                                      {
                                    (yyval.tmp_id) = MakeDataTypeNode((string)(yyvsp[0].data)->types);
                                }
#line 2214 "./parser/Parser.cpp"
    break;

  case 58:
#line 354 "./parser/Parser.y"
                                                                            {
                                   (yyval.tmp_id) = (yyvsp[-4].tmp_id);
                                   (yyval.tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id));
                                }
#line 2223 "./parser/Parser.cpp"
    break;

  case 59:
#line 358 "./parser/Parser.y"
                                                                           {
                                    (yyval.tmp_id) = (yyvsp[-4].tmp_id);
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id));
                                }
#line 2232 "./parser/Parser.cpp"
    break;

  case 64:
#line 368 "./parser/Parser.y"
                                   {
                                    (yyval.tmp_id) = MakeTermNode((string)(yyvsp[0].data)->id, ID_NODE_TYPE);
                                }
#line 2240 "./parser/Parser.cpp"
    break;

  case 65:
#line 372 "./parser/Parser.y"
                                                                                                 {
                                    (yyval.tmp_id) = MakeAssignAst((yyvsp[-8].tmp_id), (yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2248 "./parser/Parser.cpp"
    break;

  case 66:
#line 375 "./parser/Parser.y"
                                                                                                     {
                                    (yyval.tmp_id) = MakeUnionAst((yyvsp[-8].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2256 "./parser/Parser.cpp"
    break;

  case 67:
#line 378 "./parser/Parser.y"
                                                                                                                {
                                    (yyval.tmp_id) = MakeUnionAst((yyvsp[-10].tmp_id), (yyvsp[-5].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2264 "./parser/Parser.cpp"
    break;

  case 68:
#line 381 "./parser/Parser.y"
                                                                           {
                                   (yyval.tmp_id) = MakeReassignAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2272 "./parser/Parser.cpp"
    break;

  case 69:
#line 384 "./parser/Parser.y"
                                                                                                                      {
                                    (yyval.tmp_id) = MakeRefAst((yyvsp[-12].tmp_id), (yyvsp[-8].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2280 "./parser/Parser.cpp"
    break;

  case 70:
#line 387 "./parser/Parser.y"
                                                                                              {
                                    (yyval.tmp_id) = MakeRebindRefAst((yyvsp[-8].tmp_id), (yyvsp[-6].tmp_id));
                                }
#line 2288 "./parser/Parser.cpp"
    break;

  case 71:
#line 393 "./parser/Parser.y"
                                           {
                                    (yyval.tmp_id) = new AstNode();
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id));
                                }
#line 2297 "./parser/Parser.cpp"
    break;

  case 72:
#line 397 "./parser/Parser.y"
                                                   {
                                    (yyval.tmp_id) = new AstNode();
                                    (yyval.tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id));
                                }
#line 2306 "./parser/Parser.cpp"
    break;

  case 73:
#line 401 "./parser/Parser.y"
                                                             {  
                                    (yyvsp[-2].tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id));
                                    (yyval.tmp_id) = (yyvsp[-2].tmp_id);
                                }
#line 2315 "./parser/Parser.cpp"
    break;

  case 74:
#line 405 "./parser/Parser.y"
                                                                  {
                                    (yyvsp[-2].tmp_id)->SaveAsExtraNode((yyvsp[0].tmp_id));
                                    (yyval.tmp_id) = (yyvsp[-2].tmp_id);
                                }
#line 2324 "./parser/Parser.cpp"
    break;

  case 79:
#line 415 "./parser/Parser.y"
                                                                            { 
                                    (yyval.tmp_id) = MakePrintAst((yyvsp[-2].tmp_id));
                                }
#line 2332 "./parser/Parser.cpp"
    break;

  case 80:
#line 418 "./parser/Parser.y"
                                                     { Destroy(); return 0; (yyval.tmp_id) = nullptr; }
#line 2338 "./parser/Parser.cpp"
    break;

  case 81:
#line 423 "./parser/Parser.y"
                                                           {
                                    Perform((yyval.tmp_id), (yyvsp[-1].tmp_id), ADDITION_CMD);
                                }
#line 2346 "./parser/Parser.cpp"
    break;

  case 82:
#line 426 "./parser/Parser.y"
                                                                         {
                                    Perform((yyval.tmp_id), (yyvsp[-2].tmp_id), SUBTRACTION_CMD);
                                }
#line 2354 "./parser/Parser.cpp"
    break;

  case 83:
#line 429 "./parser/Parser.y"
                                                                          {
                                    Perform((yyval.tmp_id), (yyvsp[-2].tmp_id), MULTIPLY_CMD);
                                }
#line 2362 "./parser/Parser.cpp"
    break;

  case 84:
#line 432 "./parser/Parser.y"
                                                                          {
                                    Perform((yyval.tmp_id), (yyvsp[-2].tmp_id), DIVIDE_CMD);
                                }
#line 2370 "./parser/Parser.cpp"
    break;

  case 85:
#line 435 "./parser/Parser.y"
                                                                          {
                                    Perform((yyval.tmp_id), (yyvsp[-2].tmp_id), POW_CMD);
                                }
#line 2378 "./parser/Parser.cpp"
    break;

  case 86:
#line 438 "./parser/Parser.y"
                                                                        {
                                    (yyval.tmp_id) = MakeIncAst((yyvsp[-2].tmp_id));
                                }
#line 2386 "./parser/Parser.cpp"
    break;

  case 87:
#line 441 "./parser/Parser.y"
                                                                                                {
                                    (yyval.tmp_id) = MakeModAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2394 "./parser/Parser.cpp"
    break;

  case 88:
#line 449 "./parser/Parser.y"
                                                                                           {
                                    (yyval.tmp_id) = MakeLessCompAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2402 "./parser/Parser.cpp"
    break;

  case 89:
#line 452 "./parser/Parser.y"
                                                                                                {
                                    (yyval.tmp_id) = MakeGreaterCompAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2410 "./parser/Parser.cpp"
    break;

  case 90:
#line 455 "./parser/Parser.y"
                                                                                                  {
                                    (yyval.tmp_id) = MakeLessEqualCompAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2418 "./parser/Parser.cpp"
    break;

  case 91:
#line 458 "./parser/Parser.y"
                                                                                                      {
                                    (yyval.tmp_id) = MakeGreaterEqualCompAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2426 "./parser/Parser.cpp"
    break;

  case 92:
#line 461 "./parser/Parser.y"
                                                                                             {
                                    (yyval.tmp_id) = MakeEqualCompAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2434 "./parser/Parser.cpp"
    break;

  case 93:
#line 464 "./parser/Parser.y"
                                                                                                  {
                                    (yyval.tmp_id) = MakeNotEqualCompAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2442 "./parser/Parser.cpp"
    break;

  case 94:
#line 471 "./parser/Parser.y"
                                                                                         {
                                    (yyval.tmp_id) = MakeAndAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2450 "./parser/Parser.cpp"
    break;

  case 95:
#line 474 "./parser/Parser.y"
                                                                 {
                                    (yyval.tmp_id) = MakeNotAst((yyvsp[-2].tmp_id));
                                }
#line 2458 "./parser/Parser.cpp"
    break;

  case 96:
#line 477 "./parser/Parser.y"
                                                                                           {
                                    (yyval.tmp_id) = MakeOrAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2466 "./parser/Parser.cpp"
    break;

  case 97:
#line 483 "./parser/Parser.y"
                                                                  {
                                    (yyval.tmp_id) = MakeGetFromCollectionAst((yyvsp[-3].tmp_id), (yyvsp[-1].tmp_id));
                                }
#line 2474 "./parser/Parser.cpp"
    break;

  case 98:
#line 489 "./parser/Parser.y"
                                     {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2482 "./parser/Parser.cpp"
    break;

  case 99:
#line 492 "./parser/Parser.y"
                                            {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2490 "./parser/Parser.cpp"
    break;

  case 100:
#line 495 "./parser/Parser.y"
                                                                                          {
                                    (yyval.tmp_id) = MakeCastAst((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2498 "./parser/Parser.cpp"
    break;

  case 101:
#line 498 "./parser/Parser.y"
                                               {
                                   (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2506 "./parser/Parser.cpp"
    break;

  case 102:
#line 501 "./parser/Parser.y"
                                           {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2514 "./parser/Parser.cpp"
    break;

  case 103:
#line 504 "./parser/Parser.y"
                                                                                           {
                                     (yyval.tmp_id) = MakeAddToListAst((yyvsp[-7].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2522 "./parser/Parser.cpp"
    break;

  case 104:
#line 507 "./parser/Parser.y"
                                                                                                          {
                                    (yyval.tmp_id) = MakeAddToMapAst((yyvsp[-9].tmp_id), (yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2530 "./parser/Parser.cpp"
    break;

  case 105:
#line 510 "./parser/Parser.y"
                                                {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2538 "./parser/Parser.cpp"
    break;

  case 106:
#line 513 "./parser/Parser.y"
                                                                                                            {
                                    (yyval.tmp_id) = MakeSetInCollectionAst((yyvsp[-9].tmp_id), (yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id));
                                }
#line 2546 "./parser/Parser.cpp"
    break;

  case 107:
#line 516 "./parser/Parser.y"
                                                      {
                                    (yyval.tmp_id) = MakeCollectionSizeAst((yyvsp[-2].tmp_id));
                                }
#line 2554 "./parser/Parser.cpp"
    break;

  case 108:
#line 519 "./parser/Parser.y"
                                                        {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2562 "./parser/Parser.cpp"
    break;

  case 109:
#line 524 "./parser/Parser.y"
                                     { i.EatAst((yyvsp[0].tmp_id)); (yyvsp[0].tmp_id) = nullptr; }
#line 2568 "./parser/Parser.cpp"
    break;

  case 110:
#line 525 "./parser/Parser.y"
                                            { i.EatAst((yyvsp[0].tmp_id)); (yyvsp[0].tmp_id) = nullptr; }
#line 2574 "./parser/Parser.cpp"
    break;

  case 114:
#line 529 "./parser/Parser.y"
                                               { i.EatAst((yyvsp[0].tmp_id)); (yyvsp[0].tmp_id) = nullptr; }
#line 2580 "./parser/Parser.cpp"
    break;

  case 118:
#line 533 "./parser/Parser.y"
                                       {
                                    Destroy();
                                    return 0;
                                }
#line 2589 "./parser/Parser.cpp"
    break;

  case 119:
#line 537 "./parser/Parser.y"
                                        { return 0; }
#line 2595 "./parser/Parser.cpp"
    break;


#line 2599 "./parser/Parser.cpp"

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
#line 540 "./parser/Parser.y"



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
