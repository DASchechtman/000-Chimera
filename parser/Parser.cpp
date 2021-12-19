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
    INT_VAL = 302,
    DOUBLE_VAL = 303,
    STRING_VAL = 304,
    CHAR_VAL = 305,
    BOOL_VAL = 306,
    ELSE_IF = 307,
    FLOAT_VAL = 308,
    ID = 309,
    UNKNOWN = 310
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
#define YYFINAL  82
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   716

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  299

#define YYUNDEFTOK  2
#define YYMAXUTOK   310


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
      65,    66,     2,     2,     2,     2,    67,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    57,     2,
      59,    58,    60,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,     2,    62,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    63,    56,    64,     2,     2,     2,     2,
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
      55
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   106,   106,   108,   110,   119,   128,   135,   144,   172,
     173,   174,   175,   175,   177,   181,   197,   200,   203,   206,
     210,   210,   212,   216,   220,   224,   228,   232,   236,   242,
     243,   244,   245,   246,   247,   250,   255,   262,   262,   264,
     264,   266,   271,   278,   284,   295,   301,   308,   314,   321,
     329,   338,   341,   344,   348,   354,   355,   355,   359,   360,
     369,   374,   378,   382,   386,   390,   399,   405,   411,   417,
     423,   429,   444,   450,   455,   464,   468,   472,   478,   482,
     486,   492,   499,   505,   512,   519,   520,   521,   522,   523,
     524,   525,   526,   527,   528,   532,   533,   535,   535
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
  "SINGLE_WS", "INT_VAL", "DOUBLE_VAL", "STRING_VAL", "CHAR_VAL",
  "BOOL_VAL", "ELSE_IF", "FLOAT_VAL", "ID", "UNKNOWN", "'|'", "':'", "'='",
  "'<'", "'>'", "'['", "']'", "'{'", "'}'", "'('", "')'", "'.'", "$accept",
  "start", "end", "ifHead", "elseIfHead", "elseHead", "whileHead",
  "forloopHead", "ifBody", "elseIfBody", "elseBody", "elseIfChain",
  "whileStatement", "forloopStatement", "ifStatement", "newline", "term",
  "types", "unionTypes", "any_ws", "opt_ws", "id", "assign", "exprList",
  "opt_newline", "opt_ws_or_nl", "statement", "math_expr", "compare_expr",
  "boolExpr", "expr", "prog", "line", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   124,    58,    61,    60,
      62,    91,    93,   123,   125,    40,    41,    46
};
# endif

#define YYPACT_NINF (-164)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-41)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     651,  -164,    15,   -54,  -164,  -164,  -164,  -164,    15,    15,
      15,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,
     310,   651,   651,   651,   651,    14,  -164,  -164,  -164,  -164,
    -164,  -164,    58,  -164,    11,  -164,  -164,  -164,   111,  -164,
     370,  -164,   -49,    15,   140,   140,   140,    15,    15,    15,
      15,    15,    15,    15,    15,    15,    15,    15,    15,    15,
      15,    15,   515,   407,   549,   583,  -164,    15,    15,   651,
     651,  -164,     5,    29,    15,    15,    44,   -34,  -164,  -164,
    -164,  -164,  -164,  -164,    15,    23,   -14,    15,    15,    15,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     183,    15,   140,    15,    15,    15,    15,  -164,  -164,  -164,
    -164,    33,   140,   461,   617,  -164,  -164,  -164,    42,    13,
     140,    27,    45,    57,    62,    15,    15,  -164,    85,    94,
      77,    15,    15,    15,    15,    15,    15,    15,    15,    15,
      15,    15,  -164,   140,   114,   140,    75,  -164,    76,    86,
     102,   103,  -164,    15,  -164,  -164,  -164,  -164,  -164,  -164,
    -164,    91,    92,    15,   -17,    15,    15,    15,    15,    15,
     116,   140,   117,  -164,  -164,    15,   152,   140,   140,   140,
     140,   140,   140,   140,   140,   104,  -164,  -164,  -164,  -164,
    -164,  -164,  -164,  -164,   137,   152,   152,   118,   149,   -44,
     -31,   123,   140,   140,   140,  -164,   127,  -164,   138,    15,
      15,    15,    15,    15,    15,    15,    15,    15,  -164,  -164,
     135,    15,    15,   136,    15,    15,    15,    15,  -164,    15,
      15,    15,   173,    15,  -164,   134,   141,   150,   151,   155,
     160,   162,   163,   169,    15,   165,   140,    15,   152,   140,
     152,   140,   182,   140,   140,   158,   202,  -164,  -164,  -164,
    -164,  -164,  -164,  -164,  -164,  -164,   185,    15,  -164,   186,
    -164,  -164,  -164,  -164,  -164,    15,    15,  -164,  -164,    15,
     152,    15,   184,   194,    79,   181,   140,  -164,  -164,   190,
    -164,    15,  -164,  -164,   200,    15,   196,   197,  -164
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    96,    40,     0,    20,    21,    94,     2,     0,     0,
       0,    37,    38,    22,    23,    25,    26,    27,    24,    41,
       0,     0,     0,     0,     0,     0,    91,    92,    90,    89,
      75,    95,    28,    58,     0,    76,    78,    79,     0,    97,
       0,    39,     0,    40,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    40,    40,    40,
      40,    40,     0,     0,     0,     0,    16,     0,     0,     0,
       0,    12,     0,     0,    40,    40,     0,     0,    88,    87,
      86,    85,     1,    98,    40,     0,    28,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    40,     0,    40,    40,    40,    40,     3,    93,    14,
      15,     0,     0,     0,     0,    19,    17,    13,     0,     0,
       0,     0,     0,     0,     0,    40,    40,    60,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      40,    40,    51,    39,    56,    57,     0,    52,     0,     0,
       0,     0,     6,     0,    18,    29,    30,    31,    32,    33,
      34,     0,     0,    40,    40,    40,    40,    40,    40,    40,
       0,     0,     0,     4,     7,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    55,    53,    54,    61,
      62,    63,    64,    65,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,    45,    59,     0,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    73,     5,
       0,    40,    40,     0,    40,    40,    40,    40,    82,    40,
       0,     0,     0,     0,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    40,     0,     0,    40,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    77,    66,    67,
      68,    69,    70,    71,    72,    74,     0,    40,    43,     0,
      35,    42,    36,    44,    80,    40,    40,    50,     8,    40,
       0,    40,     0,     0,     0,     0,     0,    81,    83,     0,
      49,    40,    46,    47,     0,    40,     0,     0,    48
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,   187,
     189,  -164,  -164,  -164,  -164,    37,  -164,  -163,  -164,   247,
      -2,    84,  -164,   -10,  -100,   -95,  -164,  -164,  -164,  -164,
       0,   -25,    41
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    21,   108,    22,    69,    70,    23,    24,    25,    71,
      72,    73,    26,    27,    28,    29,    30,   164,   165,    41,
     144,    86,    33,   101,   102,   146,    34,    35,    36,    37,
      38,    39,    40
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,   145,    43,   145,   145,   145,   145,    84,   148,   149,
     150,   151,   224,   209,   225,    83,   155,   156,   157,   158,
     159,   160,   161,   162,   125,   226,   145,   227,    11,    12,
      77,   172,   220,   221,     4,     5,    78,    83,    83,    83,
      83,    85,   198,   115,    87,    88,    89,    75,   103,   104,
     105,   106,    66,    76,    67,   100,   100,   100,   100,   100,
      11,    12,    62,    63,    64,    65,    68,   116,   163,    67,
     152,    79,   119,   120,   126,    81,   121,   122,   123,   127,
     154,    68,   100,   167,    32,   270,   124,   272,    83,    83,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     142,   168,   147,    11,    12,    32,    32,    32,    32,   234,
     113,   114,   153,   169,   235,    74,   -40,   285,   170,    75,
     166,   175,   173,   171,    32,    76,    13,    14,    15,    16,
      17,   174,    18,    19,     4,     5,    80,   141,   185,   186,
     289,   189,   190,   187,    20,   188,    32,    32,    32,    32,
     195,   196,   191,    32,    32,   155,   156,   157,   158,   159,
     160,   197,   199,   200,   201,   202,   203,   204,   192,   193,
     218,   206,   205,   207,   219,   223,   222,   210,   211,   212,
     213,   214,   215,   216,   217,   228,   232,    13,    14,    15,
      16,    17,    19,    18,    19,   244,   247,    32,    32,   255,
     257,   267,   229,   230,   231,    20,   141,   258,   236,   237,
     238,   239,   240,   241,   242,   243,   259,   260,   277,   245,
     246,   261,   248,   249,   250,   251,   262,   252,   263,   264,
      13,    14,    15,    16,    17,   265,    18,    19,   274,   278,
     287,   291,   266,   279,   281,   269,   268,    31,    20,   271,
     288,   273,   293,   275,   276,    44,    45,    46,   295,   297,
     117,   298,   118,     0,     0,   280,     0,     0,    31,    31,
      31,    31,     0,   282,   283,     0,     0,   284,     0,   286,
       0,     0,     0,     0,   290,     0,   292,    31,     0,   294,
       0,     0,   233,   296,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,     0,     0,     0,     0,     0,    31,
      31,    31,    31,     0,   111,   112,    31,    31,     0,     0,
       0,    47,    48,    49,    50,    51,    52,    53,     0,    54,
      55,    56,     0,     0,   128,   129,   130,    57,    58,    59,
      60,    61,     0,     0,     0,     0,     0,     0,   143,     0,
     143,   143,   143,   143,     0,     0,     0,     0,     0,     0,
      31,    31,     0,     0,     0,     0,     0,     0,     0,     0,
      82,     1,     0,   143,     0,     0,     0,     0,   176,   177,
     178,   179,   180,   181,   182,   183,   184,     0,     2,     0,
       0,     0,     3,     4,     5,     6,     0,     0,     0,     0,
     194,     0,     0,     0,     0,     0,     0,     7,     1,     8,
       0,     9,     0,    10,     0,    11,    12,    13,    14,    15,
      16,    17,   208,    18,    19,     2,     0,     0,     0,     3,
       4,     5,     6,     0,     0,    20,     0,     0,     0,     0,
       0,     0,     0,     0,     7,    -9,     8,    -9,     9,     0,
      10,     0,    11,    12,    13,    14,    15,    16,    17,    -9,
      18,    19,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    20,     0,     0,     0,     0,   253,   254,     2,
     256,     0,     0,     3,     4,     5,     6,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,   -10,
       8,   -10,     9,     0,    10,     0,    11,    12,    13,    14,
      15,    16,    17,   -10,    18,    19,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    20,     0,     0,     0,
       0,     0,     0,     2,     0,     0,     0,     3,     4,     5,
       6,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     7,   107,     8,     0,     9,     0,    10,     0,
      11,    12,    13,    14,    15,    16,    17,     2,    18,    19,
       0,     3,     4,     5,     6,     0,     0,     0,     0,     0,
      20,     0,     0,     0,     1,     0,     7,   109,     8,     0,
       9,     0,    10,     0,    11,    12,    13,    14,    15,    16,
      17,     2,    18,    19,     0,     3,     4,     5,     6,     0,
       0,     0,     0,     0,    20,     0,     0,     0,     1,     0,
       7,   110,     8,     0,     9,     0,    10,     0,    11,    12,
      13,    14,    15,    16,    17,     2,    18,    19,     0,     3,
       4,     5,     6,     0,     0,     0,     0,     0,    20,     0,
       0,     0,     1,     0,     7,   -11,     8,     0,     9,     0,
      10,     0,    11,    12,    13,    14,    15,    16,    17,     2,
      18,    19,     0,     3,     4,     5,     6,     0,     0,     0,
       0,     0,    20,     0,     0,     0,     0,     0,     7,     0,
       8,     0,     9,     0,    10,     0,    11,    12,    13,    14,
      15,    16,    17,     0,    18,    19,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    20
};

static const yytype_int16 yycheck[] =
{
       2,   101,    56,   103,   104,   105,   106,    56,   103,   104,
     105,   106,    56,   176,    58,    40,     3,     4,     5,     6,
       7,     8,     9,    10,    58,    56,   126,    58,    45,    46,
      32,   126,   195,   196,    23,    24,    25,    62,    63,    64,
      65,    43,    59,    38,    44,    45,    46,    61,    58,    59,
      60,    61,    38,    67,    40,    57,    58,    59,    60,    61,
      45,    46,    21,    22,    23,    24,    52,    38,    55,    40,
      37,    34,    74,    75,    84,    38,    32,    33,    34,    56,
      38,    52,    84,    56,     0,   248,    42,   250,   113,   114,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,    56,   102,    45,    46,    21,    22,    23,    24,   209,
      69,    70,   112,    56,   209,    57,    58,   280,    56,    61,
     120,    44,    37,   125,    40,    67,    47,    48,    49,    50,
      51,    37,    53,    54,    23,    24,    25,    23,   140,   141,
      61,    66,    66,   143,    65,   145,    62,    63,    64,    65,
      59,    59,    66,    69,    70,     3,     4,     5,     6,     7,
       8,   163,   164,   165,   166,   167,   168,   169,    66,    66,
      66,   171,    56,    56,    37,    26,    58,   177,   178,   179,
     180,   181,   182,   183,   184,    62,    59,    47,    48,    49,
      50,    51,    54,    53,    54,    60,    60,   113,   114,    26,
      66,    36,   202,   203,   204,    65,    23,    66,   210,   211,
     212,   213,   214,   215,   216,   217,    66,    66,    60,   221,
     222,    66,   224,   225,   226,   227,    66,   229,    66,    66,
      47,    48,    49,    50,    51,    66,    53,    54,    56,    37,
      56,    60,   244,    58,    58,   247,   246,     0,    65,   249,
      56,   251,    62,   253,   254,     8,     9,    10,    58,    63,
      73,    64,    73,    -1,    -1,   267,    -1,    -1,    21,    22,
      23,    24,    -1,   275,   276,    -1,    -1,   279,    -1,   281,
      -1,    -1,    -1,    -1,   284,    -1,   286,    40,    -1,   291,
      -1,    -1,   208,   295,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,    62,
      63,    64,    65,    -1,    67,    68,    69,    70,    -1,    -1,
      -1,    11,    12,    13,    14,    15,    16,    17,    -1,    19,
      20,    21,    -1,    -1,    87,    88,    89,    27,    28,    29,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,
     103,   104,   105,   106,    -1,    -1,    -1,    -1,    -1,    -1,
     113,   114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       0,     1,    -1,   126,    -1,    -1,    -1,    -1,   131,   132,
     133,   134,   135,   136,   137,   138,   139,    -1,    18,    -1,
      -1,    -1,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
     153,    -1,    -1,    -1,    -1,    -1,    -1,    37,     1,    39,
      -1,    41,    -1,    43,    -1,    45,    46,    47,    48,    49,
      50,    51,   175,    53,    54,    18,    -1,    -1,    -1,    22,
      23,    24,    25,    -1,    -1,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    39,    40,    41,    -1,
      43,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    -1,    -1,    -1,    -1,   230,   231,    18,
     233,    -1,    -1,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      39,    40,    41,    -1,    43,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,     1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    -1,    -1,    -1,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       1,    -1,    37,    38,    39,    -1,    41,    -1,    43,    -1,
      45,    46,    47,    48,    49,    50,    51,    18,    53,    54,
      -1,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
      65,    -1,    -1,    -1,     1,    -1,    37,    38,    39,    -1,
      41,    -1,    43,    -1,    45,    46,    47,    48,    49,    50,
      51,    18,    53,    54,    -1,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,     1,    -1,
      37,    38,    39,    -1,    41,    -1,    43,    -1,    45,    46,
      47,    48,    49,    50,    51,    18,    53,    54,    -1,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    -1,    65,    -1,
      -1,    -1,     1,    -1,    37,    38,    39,    -1,    41,    -1,
      43,    -1,    45,    46,    47,    48,    49,    50,    51,    18,
      53,    54,    -1,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    37,    -1,
      39,    -1,    41,    -1,    43,    -1,    45,    46,    47,    48,
      49,    50,    51,    -1,    53,    54,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    65
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    18,    22,    23,    24,    25,    37,    39,    41,
      43,    45,    46,    47,    48,    49,    50,    51,    53,    54,
      65,    69,    71,    74,    75,    76,    80,    81,    82,    83,
      84,    87,    89,    90,    94,    95,    96,    97,    98,    99,
     100,    87,    88,    56,    87,    87,    87,    11,    12,    13,
      14,    15,    16,    17,    19,    20,    21,    27,    28,    29,
      30,    31,   100,   100,   100,   100,    38,    40,    52,    72,
      73,    77,    78,    79,    57,    61,    67,    88,    25,    83,
      25,    83,     0,    99,    56,    88,    89,    98,    98,    98,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      88,    91,    92,    91,    91,    91,    91,    38,    70,    38,
      38,    87,    87,   100,   100,    38,    38,    77,    78,    88,
      88,    32,    33,    34,    42,    58,    91,    56,    87,    87,
      87,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    23,    98,    87,    88,    92,    93,    98,    93,    93,
      93,    93,    37,    98,    38,     3,     4,     5,     6,     7,
       8,     9,    10,    55,    85,    86,    98,    56,    56,    56,
      56,    88,    93,    37,    37,    44,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    88,    88,    98,    98,    66,
      66,    66,    66,    66,    87,    59,    59,    88,    59,    88,
      88,    88,    88,    88,    88,    56,    98,    56,    87,    85,
      98,    98,    98,    98,    98,    98,    98,    98,    66,    37,
      85,    85,    58,    26,    56,    58,    56,    58,    62,    98,
      98,    98,    59,    89,    92,    93,    88,    88,    88,    88,
      88,    88,    88,    88,    60,    88,    88,    60,    88,    88,
      88,    88,    88,    87,    87,    26,    87,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    88,    36,    98,    88,
      85,    98,    85,    98,    56,    98,    98,    60,    37,    58,
      88,    58,    88,    88,    88,    85,    88,    56,    56,    61,
      98,    60,    98,    62,    88,    58,    88,    63,    64
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    79,    80,    81,    82,    82,    82,    82,
      83,    83,    84,    84,    84,    84,    84,    84,    84,    85,
      85,    85,    85,    85,    85,    86,    86,    87,    87,    88,
      88,    89,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    91,    91,    91,    91,    92,    93,    93,    94,    94,
      94,    95,    95,    95,    95,    95,    96,    96,    96,    96,
      96,    96,    97,    97,    97,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,   100,   100
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     5,     5,     3,     5,     9,     2,
       2,     2,     1,     2,     3,     3,     2,     3,     4,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     5,     1,     1,     1,
       0,     1,     8,     8,     8,     5,    11,    12,    16,    11,
       8,     2,     2,     3,     3,     3,     1,     1,     1,     6,
       4,     5,     5,     5,     5,     5,     8,     8,     8,     8,
       8,     8,     8,     6,     8,     1,     1,     8,     1,     1,
       8,    10,     6,    10,     5,     2,     2,     2,     2,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     2
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
#line 106 "./parser/Parser.y"
                                      { i.EatAst(MakeNode(START_BLOCK_CMD)); }
#line 1644 "./parser/Parser.cpp"
    break;

  case 3:
#line 108 "./parser/Parser.y"
                                    { i.EatAst(MakeNode(END_SCOPE_CMD)); }
#line 1650 "./parser/Parser.cpp"
    break;

  case 4:
#line 110 "./parser/Parser.y"
                                                            {
                                    auto control_block = MakeNode(CTRL_BLOCK_CMD);
                                    auto if_block = MakeNode(IF_BLOCK_CMD);
                                    if_block->SetLeft((yyvsp[-2].tmp_id));
                                    control_block->SetLeft(if_block);
                                    root = nullptr;
                                    i.EatAst(control_block);
                                }
#line 1663 "./parser/Parser.cpp"
    break;

  case 5:
#line 119 "./parser/Parser.y"
                                                                 {
                                    auto control_block = MakeNode(CTRL_BLOCK_CMD);
                                    auto if_block = MakeNode(ELIF_BLOCK_CMD);
                                    if_block->SetLeft((yyvsp[-2].tmp_id));
                                    control_block->SetLeft(if_block);
                                    root = nullptr;
                                    i.EatAst(control_block);
                                }
#line 1676 "./parser/Parser.cpp"
    break;

  case 6:
#line 128 "./parser/Parser.y"
                                                 {
                                    auto control_block = MakeNode(CTRL_BLOCK_CMD);
                                    auto if_block = MakeNode(ELSE_BLOCK_CMD);
                                    control_block->SetLeft(if_block);
                                    i.EatAst(control_block);
                                }
#line 1687 "./parser/Parser.cpp"
    break;

  case 7:
#line 135 "./parser/Parser.y"
                                                               {
                                    auto control_block = MakeNode(CTRL_BLOCK_CMD);
                                    auto while_block = MakeNode(WHILE_BLOCK_CMD);
                                    while_block->SetLeft((yyvsp[-2].tmp_id));
                                    control_block->SetLeft(while_block);
                                    root = nullptr;
                                    i.EatAst(control_block);
                                }
#line 1700 "./parser/Parser.cpp"
    break;

  case 8:
#line 144 "./parser/Parser.y"
                                                                                      {
                                    i.EatAst(MakeNode(START_BLOCK_CMD));
                                    auto make_var = MakeNode(BIND_CMD);
                                    auto type = MakeNode(RAW_DATA_CMD, string("int"), VAR_TYPE_NODE_TYPE);
                                    auto val = MakeNode(RAW_DATA_CMD, 0, INT_NODE_TYPE);
                                    
                                    make_var->SetLeft((yyvsp[-2].tmp_id));
                                    make_var->SetMiddle(type);
                                    make_var->SetRight(val);
                                    i.EatAst(make_var);
                                    root = nullptr;

                                    
                                    auto control_block = MakeNode(CTRL_BLOCK_CMD);
                                    auto while_block = MakeNode(WHILE_BLOCK_CMD);
                                    auto less_block = MakeNode(LESS_CMD);
                                    less_block->SetLeft((yyvsp[-2].tmp_id)->Copy());
                                    less_block->SetRight((yyvsp[-6].tmp_id));
                                    while_block->SetLeft(less_block);
                                    control_block->SetLeft(while_block);
                                    
                                    i.EatAst(control_block);
                                    
                                    root = nullptr;
                                    
                                    (yyval.tmp_id) = (yyvsp[-2].tmp_id)->Copy();
                                }
#line 1732 "./parser/Parser.cpp"
    break;

  case 14:
#line 177 "./parser/Parser.y"
                                                   {
                                    i.EatAst(MakeNode(END_BLOCK_CMD));
                                }
#line 1740 "./parser/Parser.cpp"
    break;

  case 15:
#line 181 "./parser/Parser.y"
                                                     {
                                   
                                    auto rebind = MakeNode(REBIND_CMD);
                                    rebind->SetLeft((yyvsp[-2].tmp_id));
                                    auto add = MakeNode(ADDITION_CMD);
                                    auto val = MakeNode(RAW_DATA_CMD, 1, INT_NODE_TYPE);
                                    add->SetLeft((yyvsp[-2].tmp_id)->Copy());
                                    add->SetRight(val);
                                    rebind->SetRight(add);
                                    i.EatAst(rebind);
                                    i.EatAst(MakeNode(END_BLOCK_CMD));
                                    i.EatAst(MakeNode(END_SCOPE_CMD));
                                       
                                    
                                }
#line 1760 "./parser/Parser.cpp"
    break;

  case 16:
#line 197 "./parser/Parser.y"
                                           {
                                    i.EatAst(MakeNode(END_BLOCK_CMD));
                                }
#line 1768 "./parser/Parser.cpp"
    break;

  case 17:
#line 200 "./parser/Parser.y"
                                                         {
                                    i.EatAst(MakeNode(END_BLOCK_CMD));
                                }
#line 1776 "./parser/Parser.cpp"
    break;

  case 18:
#line 203 "./parser/Parser.y"
                                                                  {
                                    i.EatAst(MakeNode(END_BLOCK_CMD));
                                }
#line 1784 "./parser/Parser.cpp"
    break;

  case 19:
#line 206 "./parser/Parser.y"
                                                      {
                                    i.EatAst(MakeNode(END_BLOCK_CMD));
                                }
#line 1792 "./parser/Parser.cpp"
    break;

  case 20:
#line 210 "./parser/Parser.y"
                                        {i.EatAst(root); root = nullptr;}
#line 1798 "./parser/Parser.cpp"
    break;

  case 22:
#line 212 "./parser/Parser.y"
                                                { 
                                       (yyval.tmp_id) = MakeNode(RAW_DATA_CMD, (yyvsp[0].int_val), INT_NODE_TYPE);
                                       root = (yyval.tmp_id);             
                                }
#line 1807 "./parser/Parser.cpp"
    break;

  case 23:
#line 216 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeNode(RAW_DATA_CMD, (yyvsp[0].dou_val), DOUBLE_NODE_TYPE);
                                        root = (yyval.tmp_id);          
                                }
#line 1816 "./parser/Parser.cpp"
    break;

  case 24:
#line 220 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeNode(RAW_DATA_CMD, (yyvsp[0].flo_val), FLOAT_NODE_TYPE);
                                        root = (yyval.tmp_id);            
                                }
#line 1825 "./parser/Parser.cpp"
    break;

  case 25:
#line 224 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeNode(RAW_DATA_CMD, (string)(yyvsp[0].str_val), STRING_NODE_TYPE);
                                        root = (yyval.tmp_id);                    
                                }
#line 1834 "./parser/Parser.cpp"
    break;

  case 26:
#line 228 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeNode(RAW_DATA_CMD, (yyvsp[0].char_val), CHAR_NODE_TYPE);
                                        root = (yyval.tmp_id);
                                }
#line 1843 "./parser/Parser.cpp"
    break;

  case 27:
#line 232 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeNode(RAW_DATA_CMD, (yyvsp[0].bol_val), BOOL_NODE_TYPE);
                                        root = (yyval.tmp_id);
                                }
#line 1852 "./parser/Parser.cpp"
    break;

  case 28:
#line 236 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                        root = (yyval.tmp_id);         
                                }
#line 1861 "./parser/Parser.cpp"
    break;

  case 29:
#line 242 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeNode(RAW_DATA_CMD, (string)(yyvsp[0].types), VAR_TYPE_NODE_TYPE); root = (yyval.tmp_id); }
#line 1867 "./parser/Parser.cpp"
    break;

  case 30:
#line 243 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeNode(RAW_DATA_CMD, (string)(yyvsp[0].types), VAR_TYPE_NODE_TYPE); root = (yyval.tmp_id); }
#line 1873 "./parser/Parser.cpp"
    break;

  case 31:
#line 244 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeNode(RAW_DATA_CMD, (string)(yyvsp[0].types), VAR_TYPE_NODE_TYPE); root = (yyval.tmp_id); }
#line 1879 "./parser/Parser.cpp"
    break;

  case 32:
#line 245 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeNode(RAW_DATA_CMD, (string)(yyvsp[0].types), VAR_TYPE_NODE_TYPE); root = (yyval.tmp_id); }
#line 1885 "./parser/Parser.cpp"
    break;

  case 33:
#line 246 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeNode(RAW_DATA_CMD, (string)(yyvsp[0].types), VAR_TYPE_NODE_TYPE); root = (yyval.tmp_id); }
#line 1891 "./parser/Parser.cpp"
    break;

  case 34:
#line 247 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeNode(RAW_DATA_CMD, (string)(yyvsp[0].types), VAR_TYPE_NODE_TYPE); root = (yyval.tmp_id); }
#line 1897 "./parser/Parser.cpp"
    break;

  case 35:
#line 250 "./parser/Parser.y"
                                                                            {
                                   (yyval.tmp_id) = (yyvsp[-4].tmp_id);
                                   (yyval.tmp_id)->PutInAdditional((yyvsp[0].tmp_id));
                                   root = (yyval.tmp_id);
                                }
#line 1907 "./parser/Parser.cpp"
    break;

  case 36:
#line 255 "./parser/Parser.y"
                                                                           {
                                    (yyval.tmp_id) = (yyvsp[-4].tmp_id);
                                    (yyval.tmp_id)->PutInAdditional((yyvsp[0].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 1917 "./parser/Parser.cpp"
    break;

  case 41:
#line 266 "./parser/Parser.y"
                                   {
                                    (yyval.tmp_id) = MakeNode(RAW_DATA_CMD, (yyvsp[0].id), ID_NODE_TYPE);
                                    root = (yyval.tmp_id); 
                                }
#line 1926 "./parser/Parser.cpp"
    break;

  case 42:
#line 271 "./parser/Parser.y"
                                                                           {
                                    (yyval.tmp_id) = MakeNode(BIND_CMD);                                    
                                    (yyval.tmp_id)->SetLeft((yyvsp[-7].tmp_id));
                                    (yyval.tmp_id)->SetMiddle((yyvsp[-4].tmp_id));
                                    (yyval.tmp_id)->SetRight((yyvsp[0].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 1938 "./parser/Parser.cpp"
    break;

  case 43:
#line 278 "./parser/Parser.y"
                                                                               {
                                    (yyval.tmp_id) = MakeNode(MAKE_UNION_CMD);
                                    (yyval.tmp_id)->SetLeft((yyvsp[-7].tmp_id));
                                    (yyval.tmp_id)->SetRight((yyvsp[0].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 1949 "./parser/Parser.cpp"
    break;

  case 44:
#line 284 "./parser/Parser.y"
                                                                                  {
                                    (yyval.tmp_id) = MakeNode(MAKE_UNION_CMD);
                                    (yyval.tmp_id)->SetLeft((yyvsp[-7].tmp_id));
                                    (yyval.tmp_id)->SetMiddle((yyvsp[-4].tmp_id));
                                    for(size_t index = 0; index < (yyvsp[-4].tmp_id)->Extras(); index++) {
                                        (yyval.tmp_id)->SetMiddle((yyvsp[-4].tmp_id)->GetAdditional(index));
                                        (yyvsp[-4].tmp_id)->NullAdditional(index);
                                    }
                                    (yyval.tmp_id)->SetRight((yyvsp[0].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 1965 "./parser/Parser.cpp"
    break;

  case 45:
#line 295 "./parser/Parser.y"
                                                            {
                                   (yyval.tmp_id) = MakeNode(REBIND_CMD);
                                   (yyval.tmp_id)->SetLeft((yyvsp[-4].tmp_id));
                                   (yyval.tmp_id)->SetRight((yyvsp[0].tmp_id));
                                   root = (yyval.tmp_id);
                                }
#line 1976 "./parser/Parser.cpp"
    break;

  case 46:
#line 301 "./parser/Parser.y"
                                                                                         {
                                    (yyval.tmp_id) = MakeNode(REFBIND_CMD);
                                    (yyval.tmp_id)->SetLeft((yyvsp[-10].tmp_id));
                                    (yyval.tmp_id)->SetMiddle((yyvsp[-7].tmp_id));
                                    (yyval.tmp_id)->SetRight((yyvsp[0].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 1988 "./parser/Parser.cpp"
    break;

  case 47:
#line 308 "./parser/Parser.y"
                                                                                             {
                                    (yyval.tmp_id) = MakeNode(MAKE_LIST_CMD);
                                    (yyval.tmp_id)->SetLeft((yyvsp[-11].tmp_id));
                                    (yyval.tmp_id)->SetRight((yyvsp[-6].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 1999 "./parser/Parser.cpp"
    break;

  case 48:
#line 314 "./parser/Parser.y"
                                                                                                                                    {
                                    (yyval.tmp_id) = MakeNode(MAKE_MAP_CMD);
                                    (yyval.tmp_id)->SetLeft((yyvsp[-15].tmp_id));
                                    (yyval.tmp_id)->SetMiddle((yyvsp[-10].tmp_id));
                                    (yyval.tmp_id)->SetRight((yyvsp[-6].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2011 "./parser/Parser.cpp"
    break;

  case 49:
#line 321 "./parser/Parser.y"
                                                                                          {
                                    (yyval.tmp_id) = MakeNode(MAKE_LIST_CMD);
                                    (yyval.tmp_id)->SetLeft((yyvsp[-10].tmp_id));
                                    (yyval.tmp_id)->SetMiddle((yyvsp[0].tmp_id));
                                    (yyval.tmp_id)->SetRight((yyvsp[-5].tmp_id));
                                    root = (yyval.tmp_id);

                                }
#line 2024 "./parser/Parser.cpp"
    break;

  case 50:
#line 329 "./parser/Parser.y"
                                                                        {
                                    (yyval.tmp_id) = MakeNode(REFBIND_CMD);
                                    (yyval.tmp_id)->SetLeft((yyvsp[-7].tmp_id));
                                    (yyval.tmp_id)->SetRight((yyvsp[-3].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2035 "./parser/Parser.cpp"
    break;

  case 51:
#line 338 "./parser/Parser.y"
                                           {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2043 "./parser/Parser.cpp"
    break;

  case 52:
#line 341 "./parser/Parser.y"
                                                   {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2051 "./parser/Parser.cpp"
    break;

  case 53:
#line 344 "./parser/Parser.y"
                                                             {  
                                    (yyvsp[-2].tmp_id)->PutInAdditional((yyvsp[0].tmp_id));
                                    (yyval.tmp_id) = (yyvsp[-2].tmp_id);
                                }
#line 2060 "./parser/Parser.cpp"
    break;

  case 54:
#line 348 "./parser/Parser.y"
                                                                  {
                                    (yyvsp[-2].tmp_id)->PutInAdditional((yyvsp[0].tmp_id));
                                    (yyval.tmp_id) = (yyvsp[-2].tmp_id);
                                }
#line 2069 "./parser/Parser.cpp"
    break;

  case 59:
#line 360 "./parser/Parser.y"
                                                                            { 
                                    (yyval.tmp_id) = MakeNode(PRINT_CMD);
                                    (yyval.tmp_id)->SetLeft((yyvsp[-2].tmp_id));
                                    for(size_t index = 0; index < (yyvsp[-2].tmp_id)->Extras(); index++) {
                                        (yyval.tmp_id)->SetLeft((yyvsp[-2].tmp_id)->GetAdditional(index));
                                        (yyvsp[-2].tmp_id)->NullAdditional(index);
                                    }
                                    root = (yyval.tmp_id);
                                }
#line 2083 "./parser/Parser.cpp"
    break;

  case 60:
#line 369 "./parser/Parser.y"
                                                     { return 0; }
#line 2089 "./parser/Parser.cpp"
    break;

  case 61:
#line 374 "./parser/Parser.y"
                                                                       {
                                    Perform((yyval.tmp_id), (yyvsp[-2].tmp_id), ADDITION_CMD);
                                    root = (yyval.tmp_id);
                                }
#line 2098 "./parser/Parser.cpp"
    break;

  case 62:
#line 378 "./parser/Parser.y"
                                                                         {
                                    Perform((yyval.tmp_id), (yyvsp[-2].tmp_id), SUBTRACTION_CMD);
                                    root = (yyval.tmp_id);
                                }
#line 2107 "./parser/Parser.cpp"
    break;

  case 63:
#line 382 "./parser/Parser.y"
                                                                          {
                                    Perform((yyval.tmp_id), (yyvsp[-2].tmp_id), MULTIPLY_CMD);
                                    root = (yyval.tmp_id);
                                }
#line 2116 "./parser/Parser.cpp"
    break;

  case 64:
#line 386 "./parser/Parser.y"
                                                                          {
                                    Perform((yyval.tmp_id), (yyvsp[-2].tmp_id), DIVIDE_CMD);
                                    root = (yyval.tmp_id);
                                }
#line 2125 "./parser/Parser.cpp"
    break;

  case 65:
#line 390 "./parser/Parser.y"
                                                                          {
                                    Perform((yyval.tmp_id), (yyvsp[-2].tmp_id), POW_CMD);
                                    root = (yyval.tmp_id);
                                }
#line 2134 "./parser/Parser.cpp"
    break;

  case 66:
#line 399 "./parser/Parser.y"
                                                                                           {
                                    (yyval.tmp_id) = MakeNode(LESS_CMD);
                                    (yyval.tmp_id)->SetLeft((yyvsp[-4].tmp_id));
                                    (yyval.tmp_id)->SetRight((yyvsp[-2].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2145 "./parser/Parser.cpp"
    break;

  case 67:
#line 405 "./parser/Parser.y"
                                                                                                {
                                    (yyval.tmp_id) = MakeNode(GREATER_CMD);
                                    (yyval.tmp_id)->SetLeft((yyvsp[-4].tmp_id));
                                    (yyval.tmp_id)->SetRight((yyvsp[-2].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2156 "./parser/Parser.cpp"
    break;

  case 68:
#line 411 "./parser/Parser.y"
                                                                                                  {
                                    (yyval.tmp_id) = MakeNode(LESS_EQ_CMD);
                                    (yyval.tmp_id)->SetLeft((yyvsp[-4].tmp_id));
                                    (yyval.tmp_id)->SetRight((yyvsp[-2].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2167 "./parser/Parser.cpp"
    break;

  case 69:
#line 417 "./parser/Parser.y"
                                                                                                      {
                                    (yyval.tmp_id) = MakeNode(GREATER_EQ_CMD);
                                    (yyval.tmp_id)->SetLeft((yyvsp[-4].tmp_id));
                                    (yyval.tmp_id)->SetRight((yyvsp[-2].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2178 "./parser/Parser.cpp"
    break;

  case 70:
#line 423 "./parser/Parser.y"
                                                                                             {
                                    (yyval.tmp_id) = MakeNode(EQ_CMD);
                                    (yyval.tmp_id)->SetLeft((yyvsp[-4].tmp_id));
                                    (yyval.tmp_id)->SetRight((yyvsp[-2].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2189 "./parser/Parser.cpp"
    break;

  case 71:
#line 429 "./parser/Parser.y"
                                                                                                  {
                                    (yyval.tmp_id) = MakeNode(NOT_CMD);

                                    auto equal = MakeNode(EQ_CMD);
                                    equal->SetLeft((yyvsp[-4].tmp_id));
                                    equal->SetRight((yyvsp[-2].tmp_id));

                                    (yyval.tmp_id)->SetLeft(equal);

                                    root = (yyval.tmp_id);
                                }
#line 2205 "./parser/Parser.cpp"
    break;

  case 72:
#line 444 "./parser/Parser.y"
                                                                                         {
                                    (yyval.tmp_id) = MakeNode(AND_CMD);
                                    (yyval.tmp_id)->SetLeft((yyvsp[-4].tmp_id));
                                    (yyval.tmp_id)->SetRight((yyvsp[-2].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2216 "./parser/Parser.cpp"
    break;

  case 73:
#line 450 "./parser/Parser.y"
                                                                 {
                                    (yyval.tmp_id) = MakeNode(NOT_CMD);
                                    (yyval.tmp_id)->SetLeft((yyvsp[-2].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2226 "./parser/Parser.cpp"
    break;

  case 74:
#line 455 "./parser/Parser.y"
                                                                                           {
                                    (yyval.tmp_id) = MakeNode(OR_CMD);
                                    (yyval.tmp_id)->SetLeft((yyvsp[-4].tmp_id));
                                    (yyval.tmp_id)->SetRight((yyvsp[-2].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2237 "./parser/Parser.cpp"
    break;

  case 75:
#line 464 "./parser/Parser.y"
                                     {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                    root = (yyval.tmp_id);
                                }
#line 2246 "./parser/Parser.cpp"
    break;

  case 76:
#line 468 "./parser/Parser.y"
                                            {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                    root = (yyval.tmp_id);
                                }
#line 2255 "./parser/Parser.cpp"
    break;

  case 77:
#line 472 "./parser/Parser.y"
                                                                                          {
                                    (yyval.tmp_id) = MakeNode(CAST_TYPE_CMD);
                                    (yyval.tmp_id)->SetLeft((yyvsp[-4].tmp_id));
                                    (yyval.tmp_id)->SetRight((yyvsp[-2].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2266 "./parser/Parser.cpp"
    break;

  case 78:
#line 478 "./parser/Parser.y"
                                               {
                                   (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                   root = (yyval.tmp_id);
                                }
#line 2275 "./parser/Parser.cpp"
    break;

  case 79:
#line 482 "./parser/Parser.y"
                                           {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                    root = (yyval.tmp_id);
                                }
#line 2284 "./parser/Parser.cpp"
    break;

  case 80:
#line 486 "./parser/Parser.y"
                                                                                         {
                                     (yyval.tmp_id) = MakeNode(PUT_IN_CONTAINER_CMD);
                                     (yyval.tmp_id)->SetLeft((yyvsp[-7].tmp_id));
                                     (yyval.tmp_id)->SetRight((yyvsp[-2].tmp_id));
                                     root = (yyval.tmp_id);
                                }
#line 2295 "./parser/Parser.cpp"
    break;

  case 81:
#line 492 "./parser/Parser.y"
                                                                                                        {
                                    (yyval.tmp_id) = MakeNode(PUT_IN_MAP_CMD);
                                    (yyval.tmp_id)->SetLeft((yyvsp[-9].tmp_id));
                                    (yyval.tmp_id)->SetMiddle((yyvsp[-4].tmp_id));
                                    (yyval.tmp_id)->SetRight((yyvsp[-2].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2307 "./parser/Parser.cpp"
    break;

  case 82:
#line 499 "./parser/Parser.y"
                                                                             {
                                    (yyval.tmp_id) = MakeNode(GET_FROM_CONTAINER_CMD);
                                    (yyval.tmp_id)->SetLeft((yyvsp[-5].tmp_id));
                                    (yyval.tmp_id)->SetRight((yyvsp[-2].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2318 "./parser/Parser.cpp"
    break;

  case 83:
#line 505 "./parser/Parser.y"
                                                                                                          {
                                    (yyval.tmp_id) = MakeNode(SET_IN_CONTAINER_CMD);
                                    (yyval.tmp_id)->SetLeft((yyvsp[-9].tmp_id));
                                    (yyval.tmp_id)->SetMiddle((yyvsp[-4].tmp_id));
                                    (yyval.tmp_id)->SetRight((yyvsp[-2].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2330 "./parser/Parser.cpp"
    break;

  case 84:
#line 512 "./parser/Parser.y"
                                                            {
                                    (yyval.tmp_id) = MakeNode(GET_CONTAINER_SIZE_CMD);
                                    (yyval.tmp_id)->SetLeft((yyvsp[-4].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2340 "./parser/Parser.cpp"
    break;

  case 94:
#line 528 "./parser/Parser.y"
                                       { 
                                    i.EatAst(root);
                                    return 0 ;
                                }
#line 2349 "./parser/Parser.cpp"
    break;

  case 96:
#line 533 "./parser/Parser.y"
                                        { return 0; }
#line 2355 "./parser/Parser.cpp"
    break;


#line 2359 "./parser/Parser.cpp"

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
#line 536 "./parser/Parser.y"



void PrintLineNo() {
    cout << "line num: " << lineno << "\n";
    lineno++;
}

void yyerror(const char* err) {
    cout << err << '\n';
    //cout << yytext << '\n';
}

#include <vector>
using namespace std;

template<class R, class ... cparams,  class ... params>
void Test(R(*f)(cparams...), params ... p) {
    vector<string> cor_p = {typeid(cparams).name()...};
    vector<string> passed_p = {typeid(p).name()...};

    bool input = false;
    if (passed_p.size() == cor_p.size()) {
        input = true;
        for(size_t i = 0; i < passed_p.size(); i++) {
            if (passed_p[i] != cor_p[i]) {
                input = false;
                break;
            }
        }
    }

    if (!input) {
        cout << "Error: couldn't run func\n";
    }
    else {
        //(*f)(p...);
    }
}

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
