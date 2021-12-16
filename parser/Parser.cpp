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

void PrintLineNo();
void yyerror(const char* err);
extern int yylex();
extern FILE *yyin;
extern void yyrestart(FILE* input);
extern char* yytext;

#line 95 "./parser/Parser.cpp"

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
    INT_VAL = 298,
    DOUBLE_VAL = 299,
    STRING_VAL = 300,
    CHAR_VAL = 301,
    BOOL_VAL = 302,
    ELSE_IF = 303,
    FLOAT_VAL = 304,
    MULTI_WS = 305,
    SINGLE_WS = 306,
    ID = 307,
    UNKNOWN = 308
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
#define YYFINAL  75
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   622

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  282

#define YYUNDEFTOK  2
#define YYMAXUTOK   308


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
      63,    64,     2,     2,     2,     2,    65,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    55,     2,
      57,    56,    58,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    59,     2,    60,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    61,    54,    62,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    59,    59,    63,    72,    81,    88,    97,    98,    99,
     100,   100,   102,   103,   104,   105,   106,   108,   108,   110,
     114,   118,   122,   126,   130,   134,   140,   141,   142,   143,
     144,   145,   148,   153,   160,   160,   162,   162,   164,   169,
     176,   182,   193,   199,   206,   212,   219,   227,   236,   239,
     242,   246,   252,   253,   253,   257,   258,   267,   272,   276,
     280,   284,   288,   297,   303,   309,   315,   321,   327,   342,
     348,   353,   362,   366,   370,   376,   380,   384,   390,   397,
     403,   410,   417,   418,   419,   420,   421,   422,   423,   424,
     428,   429,   431,   431
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
  "END", "IF", "ELSE", "WHILE", "SIZE", "INT_VAL", "DOUBLE_VAL",
  "STRING_VAL", "CHAR_VAL", "BOOL_VAL", "ELSE_IF", "FLOAT_VAL", "MULTI_WS",
  "SINGLE_WS", "ID", "UNKNOWN", "'|'", "':'", "'='", "'<'", "'>'", "'['",
  "']'", "'{'", "'}'", "'('", "')'", "'.'", "$accept", "end", "ifHead",
  "elseIfHead", "elseHead", "whileHead", "ifBody", "elseIfBody",
  "elseBody", "elseIfChain", "whileStatement", "ifStatement", "newline",
  "term", "types", "unionTypes", "any_ws", "opt_ws", "id", "assign",
  "exprList", "opt_newline", "opt_ws_or_nl", "statement", "math_expr",
  "compare_expr", "boolExpr", "expr", "prog", "line", YY_NULLPTR
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
     305,   306,   307,   308,   124,    58,    61,    60,    62,    91,
      93,   123,   125,    40,    41,    46
};
# endif

#define YYPACT_NINF (-157)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-38)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     546,  -157,   -41,   -35,  -157,  -157,  -157,   -41,   -41,  -157,
    -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,   591,   546,
     546,   -16,  -157,  -157,  -157,  -157,  -157,   191,  -157,    20,
    -157,  -157,  -157,    93,  -157,   354,  -157,   -26,   -41,   172,
     172,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,
     -41,   -41,   -41,   -41,   -41,   -41,   389,   476,  -157,   -41,
     -41,  -157,   546,   546,  -157,    -5,   -16,   -41,   -41,    38,
     -27,  -157,  -157,  -157,  -157,  -157,  -157,   -41,    -7,   -57,
     -41,   -41,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   286,   -41,   172,   -41,   -41,   -41,   -41,  -157,
      17,   172,   424,   511,  -157,  -157,  -157,    -5,   131,   172,
       1,     6,    10,    15,   -41,   -41,  -157,    44,    56,   -41,
     -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,
    -157,   172,    76,   172,    36,  -157,    42,    46,    47,    55,
    -157,   -41,  -157,  -157,  -157,  -157,  -157,  -157,  -157,    45,
      51,   -41,    -9,   -41,   -41,   -41,   -41,   -41,    67,   172,
      68,  -157,  -157,   139,   172,   172,   172,   172,   172,   172,
     172,   172,    59,  -157,  -157,  -157,  -157,  -157,  -157,  -157,
    -157,    87,   139,   139,    69,   102,     7,    22,    70,   172,
     172,   172,  -157,    72,  -157,   -41,   -41,   -41,   -41,   -41,
     -41,   -41,   -41,   -41,  -157,  -157,    74,   -41,   -41,    90,
     -41,   -41,   -41,   -41,  -157,   -41,   -41,   -41,   130,  -157,
      94,    96,    97,    98,    99,   113,   115,   116,   118,   -41,
     121,   172,   -41,   139,   172,   139,   172,   132,   172,   172,
     125,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,
     137,   -41,  -157,   146,  -157,  -157,  -157,  -157,  -157,   -41,
     -41,  -157,   -41,   139,   -41,   133,   149,   129,   127,   172,
    -157,  -157,   144,  -157,   -41,  -157,  -157,   151,   -41,   153,
     150,  -157
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    91,    37,     0,    17,    18,    89,     0,     0,    19,
      20,    22,    23,    24,    21,    34,    35,    38,     0,     0,
       0,     0,    88,    87,    86,    72,    90,    25,    55,     0,
      73,    75,    76,     0,    92,     0,    36,     0,    37,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    37,    37,    37,    37,    37,     0,     0,     2,     0,
       0,    13,     0,     0,    10,     0,     0,    37,    37,     0,
       0,    85,    84,    83,    82,     1,    93,    37,     0,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    37,     0,    37,    37,    37,    37,    12,
       0,     0,     0,     0,    16,    14,    11,     0,     0,     0,
       0,     0,     0,     0,    37,    37,    57,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    37,    37,
      48,    36,    53,    54,     0,    49,     0,     0,     0,     0,
       5,     0,    15,    26,    27,    28,    29,    30,    31,     0,
       0,    37,    37,    37,    37,    37,    37,    37,     0,     0,
       0,     3,     6,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,    50,    51,    58,    59,    60,    61,
      62,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    81,    42,    56,    37,    37,    37,    37,    37,
      37,    37,    37,    37,    70,     4,     0,    37,    37,     0,
      37,    37,    37,    37,    79,    37,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    37,
       0,     0,    37,     0,     0,     0,     0,     0,     0,     0,
       0,    74,    63,    64,    65,    66,    67,    68,    69,    71,
       0,    37,    40,     0,    32,    39,    33,    41,    77,    37,
      37,    47,    37,     0,    37,     0,     0,     0,     0,     0,
      78,    80,     0,    46,    37,    43,    44,     0,    37,     0,
       0,    45
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -157,   -45,  -157,  -157,  -157,  -157,  -157,   154,   156,  -157,
    -157,  -157,     5,  -157,  -156,  -157,   244,    -2,    11,  -157,
      43,   -92,   -80,  -157,  -157,  -157,  -157,     0,     2,    -6
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    61,    19,    62,    63,    20,    21,    64,    65,    66,
      22,    23,    24,    25,   152,   153,    36,   132,    79,    28,
      93,    94,   134,    29,    30,    31,    32,    33,    34,    35
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      37,   133,    68,   133,   133,   133,   133,   195,    69,    15,
      16,    27,    99,    56,    57,   136,   137,   138,   139,    38,
     104,   105,    58,   133,    59,    70,   206,   207,    77,   114,
      27,    27,    60,    58,    72,   160,    78,    76,    74,    80,
      81,    15,    16,     4,     5,    71,    27,   116,   185,    92,
      92,    92,    92,    92,   140,   155,   102,   103,    76,    76,
     156,   210,   142,   211,   157,   108,   109,    27,    27,   158,
     110,   111,   112,    27,    27,    92,   212,   254,   213,   256,
     113,   161,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   130,   162,   135,    95,    96,    97,    98,   129,
     176,   141,   182,   219,    76,    76,   177,   268,   183,   154,
     178,   179,   159,    27,    27,   220,     4,     5,    73,   180,
     115,   192,   194,   204,   205,   208,   172,   173,   209,   218,
     214,   174,   229,   175,   143,   144,   145,   146,   147,   148,
     149,   150,   143,   144,   145,   146,   147,   148,   232,   184,
     186,   187,   188,   189,   190,   191,   240,   251,   241,   193,
     242,   243,   244,   245,   196,   197,   198,   199,   200,   201,
     202,   203,     9,    10,    11,    12,    13,   246,    14,   247,
     248,    17,   249,   261,   151,   274,   258,   270,   272,   215,
     216,   217,    18,   262,   221,   222,   223,   224,   225,   226,
     227,   228,   264,   271,   276,   230,   231,   278,   233,   234,
     235,   236,   281,   237,   280,     9,    10,    11,    12,    13,
     106,    14,   107,     0,    17,     0,     0,   250,     0,     0,
     253,   252,     0,     0,   255,    18,   257,     0,   259,   260,
       0,    15,    16,     0,    26,     0,    67,   -37,     0,   263,
      68,    39,    40,     0,     0,     0,    69,   265,   266,     0,
     267,     0,   269,    26,    26,     0,     0,   273,     0,   275,
       0,     0,   277,     0,     0,     0,   279,     0,     0,    26,
       0,     0,     0,     0,     0,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,     0,     0,     0,     0,     0,
      26,    26,     0,   100,   101,     0,    26,    26,     0,   129,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   117,   118,     0,     0,     0,     9,
      10,    11,    12,    13,     0,    14,     0,   131,    17,   131,
     131,   131,   131,     0,     0,     0,    26,    26,     0,    18,
       0,     0,     0,     0,    75,     1,     0,     0,     0,   131,
       0,     0,     0,   163,   164,   165,   166,   167,   168,   169,
     170,   171,     2,     0,     0,     0,     3,     4,     5,     6,
       0,     0,     0,     0,     0,   181,     0,     0,     0,     0,
       1,     0,     0,     7,     0,     8,     0,     9,    10,    11,
      12,    13,     0,    14,    15,    16,    17,     2,     0,     0,
       0,     3,     4,     5,     6,     0,     0,    18,     0,     0,
       0,     0,     0,     0,     0,     1,     0,    -7,     7,    -7,
       8,     0,     9,    10,    11,    12,    13,    -7,    14,    15,
      16,    17,     2,     0,     0,     0,     3,     4,     5,     6,
       0,     0,    18,     0,     0,     0,     0,     0,     0,     0,
     238,   239,    -8,     7,    -8,     8,     0,     9,    10,    11,
      12,    13,    -8,    14,    15,    16,    17,     1,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    18,     0,     0,
       0,     0,     0,     0,     2,     0,     0,     0,     3,     4,
       5,     6,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,    58,     7,     0,     8,     0,     9,
      10,    11,    12,    13,     0,    14,    15,    16,    17,     2,
       0,     0,     0,     3,     4,     5,     6,     0,     0,    18,
       0,     0,     0,     0,     0,     0,     0,     1,     0,    -9,
       7,     0,     8,     0,     9,    10,    11,    12,    13,     0,
      14,    15,    16,    17,     2,     0,     0,     0,     3,     4,
       5,     6,     0,     0,    18,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     0,     8,     0,     9,
      10,    11,    12,    13,     0,    14,    15,    16,    17,     0,
       0,     0,    41,    42,    43,    44,    45,    46,    47,    18,
      48,    49,    50,     0,     0,     0,     0,     0,    51,    52,
      53,    54,    55
};

static const yytype_int16 yycheck[] =
{
       2,    93,    59,    95,    96,    97,    98,   163,    65,    50,
      51,     0,    57,    19,    20,    95,    96,    97,    98,    54,
      65,    66,    38,   115,    40,    27,   182,   183,    54,    56,
      19,    20,    48,    38,    29,   115,    38,    35,    33,    39,
      40,    50,    51,    23,    24,    25,    35,    54,    57,    51,
      52,    53,    54,    55,    37,    54,    62,    63,    56,    57,
      54,    54,   107,    56,    54,    67,    68,    56,    57,    54,
      32,    33,    34,    62,    63,    77,    54,   233,    56,   235,
      42,    37,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    37,    94,    52,    53,    54,    55,    23,
      64,   101,    57,   195,   102,   103,    64,   263,    57,   109,
      64,    64,   114,   102,   103,   195,    23,    24,    25,    64,
      77,    54,    54,    64,    37,    56,   128,   129,    26,    57,
      60,   131,    58,   133,     3,     4,     5,     6,     7,     8,
       9,    10,     3,     4,     5,     6,     7,     8,    58,   151,
     152,   153,   154,   155,   156,   157,    26,    36,    64,   159,
      64,    64,    64,    64,   164,   165,   166,   167,   168,   169,
     170,   171,    43,    44,    45,    46,    47,    64,    49,    64,
      64,    52,    64,    58,    53,    58,    54,    54,    59,   189,
     190,   191,    63,    56,   196,   197,   198,   199,   200,   201,
     202,   203,    56,    54,    60,   207,   208,    56,   210,   211,
     212,   213,    62,   215,    61,    43,    44,    45,    46,    47,
      66,    49,    66,    -1,    52,    -1,    -1,   229,    -1,    -1,
     232,   231,    -1,    -1,   234,    63,   236,    -1,   238,   239,
      -1,    50,    51,    -1,     0,    -1,    55,    56,    -1,   251,
      59,     7,     8,    -1,    -1,    -1,    65,   259,   260,    -1,
     262,    -1,   264,    19,    20,    -1,    -1,   267,    -1,   269,
      -1,    -1,   274,    -1,    -1,    -1,   278,    -1,    -1,    35,
      -1,    -1,    -1,    -1,    -1,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,
      56,    57,    -1,    59,    60,    -1,    62,    63,    -1,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    80,    81,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    -1,    49,    -1,    93,    52,    95,
      96,    97,    98,    -1,    -1,    -1,   102,   103,    -1,    63,
      -1,    -1,    -1,    -1,     0,     1,    -1,    -1,    -1,   115,
      -1,    -1,    -1,   119,   120,   121,   122,   123,   124,   125,
     126,   127,    18,    -1,    -1,    -1,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,   141,    -1,    -1,    -1,    -1,
       1,    -1,    -1,    39,    -1,    41,    -1,    43,    44,    45,
      46,    47,    -1,    49,    50,    51,    52,    18,    -1,    -1,
      -1,    22,    23,    24,    25,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    -1,    38,    39,    40,
      41,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    18,    -1,    -1,    -1,    22,    23,    24,    25,
      -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     216,   217,    38,    39,    40,    41,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,     1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    -1,    -1,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     1,    -1,    38,    39,    -1,    41,    -1,    43,
      44,    45,    46,    47,    -1,    49,    50,    51,    52,    18,
      -1,    -1,    -1,    22,    23,    24,    25,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,    38,
      39,    -1,    41,    -1,    43,    44,    45,    46,    47,    -1,
      49,    50,    51,    52,    18,    -1,    -1,    -1,    22,    23,
      24,    25,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    41,    -1,    43,
      44,    45,    46,    47,    -1,    49,    50,    51,    52,    -1,
      -1,    -1,    11,    12,    13,    14,    15,    16,    17,    63,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    18,    22,    23,    24,    25,    39,    41,    43,
      44,    45,    46,    47,    49,    50,    51,    52,    63,    68,
      71,    72,    76,    77,    78,    79,    82,    84,    85,    89,
      90,    91,    92,    93,    94,    95,    82,    83,    54,    82,
      82,    11,    12,    13,    14,    15,    16,    17,    19,    20,
      21,    27,    28,    29,    30,    31,    95,    95,    38,    40,
      48,    67,    69,    70,    73,    74,    75,    55,    59,    65,
      83,    25,    78,    25,    78,     0,    94,    54,    83,    84,
      93,    93,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    83,    86,    87,    86,    86,    86,    86,    67,
      82,    82,    95,    95,    67,    67,    73,    74,    83,    83,
      32,    33,    34,    42,    56,    86,    54,    82,    82,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    23,
      93,    82,    83,    87,    88,    93,    88,    88,    88,    88,
      37,    93,    67,     3,     4,     5,     6,     7,     8,     9,
      10,    53,    80,    81,    93,    54,    54,    54,    54,    83,
      88,    37,    37,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    83,    83,    93,    93,    64,    64,    64,    64,
      64,    82,    57,    57,    83,    57,    83,    83,    83,    83,
      83,    83,    54,    93,    54,    80,    93,    93,    93,    93,
      93,    93,    93,    93,    64,    37,    80,    80,    56,    26,
      54,    56,    54,    56,    60,    93,    93,    93,    57,    87,
      88,    83,    83,    83,    83,    83,    83,    83,    83,    58,
      83,    83,    58,    83,    83,    83,    83,    83,    82,    82,
      26,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      83,    36,    93,    83,    80,    93,    80,    93,    54,    93,
      93,    58,    56,    83,    56,    83,    83,    83,    80,    83,
      54,    54,    59,    93,    58,    93,    60,    83,    56,    83,
      61,    62
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    75,    76,    77,    77,    77,    77,    78,    78,    79,
      79,    79,    79,    79,    79,    79,    80,    80,    80,    80,
      80,    80,    81,    81,    82,    82,    83,    83,    84,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    86,    86,
      86,    86,    87,    88,    88,    89,    89,    89,    90,    90,
      90,    90,    90,    91,    91,    91,    91,    91,    91,    92,
      92,    92,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    95,    95
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     5,     5,     3,     5,     2,     2,     2,
       1,     2,     3,     2,     3,     4,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     5,     1,     1,     1,     0,     1,     8,
       8,     8,     5,    11,    12,    16,    11,     8,     2,     2,
       3,     3,     3,     1,     1,     1,     6,     4,     5,     5,
       5,     5,     5,     8,     8,     8,     8,     8,     8,     8,
       6,     8,     1,     1,     8,     1,     1,     8,    10,     6,
      10,     5,     2,     2,     2,     2,     1,     1,     1,     1,
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
#line 59 "./parser/Parser.y"
                                    {
                                    i.EatAst(MakeNode(END_BLOCK_CMD));
                                }
#line 1617 "./parser/Parser.cpp"
    break;

  case 3:
#line 63 "./parser/Parser.y"
                                                            {
                                    auto control_block = MakeNode(CTRL_BLOCK_CMD);
                                    auto if_block = MakeNode(IF_BLOCK_CMD);
                                    if_block->SetLeft((yyvsp[-2].tmp_id));
                                    control_block->SetLeft(if_block);
                                    root = nullptr;
                                    i.EatAst(control_block);
                                }
#line 1630 "./parser/Parser.cpp"
    break;

  case 4:
#line 72 "./parser/Parser.y"
                                                                 {
                                    auto control_block = MakeNode(CTRL_BLOCK_CMD);
                                    auto if_block = MakeNode(ELIF_BLOCK_CMD);
                                    if_block->SetLeft((yyvsp[-2].tmp_id));
                                    control_block->SetLeft(if_block);
                                    root = nullptr;
                                    i.EatAst(control_block);
                                }
#line 1643 "./parser/Parser.cpp"
    break;

  case 5:
#line 81 "./parser/Parser.y"
                                                 {
                                    auto control_block = MakeNode(CTRL_BLOCK_CMD);
                                    auto if_block = MakeNode(ELSE_BLOCK_CMD);
                                    control_block->SetLeft(if_block);
                                    i.EatAst(control_block);
                                }
#line 1654 "./parser/Parser.cpp"
    break;

  case 6:
#line 88 "./parser/Parser.y"
                                                               {
                                    auto control_block = MakeNode(CTRL_BLOCK_CMD);
                                    auto while_block = MakeNode(WHILE_BLOCK_CMD);
                                    while_block->SetLeft((yyvsp[-2].tmp_id));
                                    control_block->SetLeft(while_block);
                                    root = nullptr;
                                    i.EatAst(control_block);
                                }
#line 1667 "./parser/Parser.cpp"
    break;

  case 17:
#line 108 "./parser/Parser.y"
                                        {i.EatAst(root); root = nullptr;}
#line 1673 "./parser/Parser.cpp"
    break;

  case 19:
#line 110 "./parser/Parser.y"
                                                { 
                                       (yyval.tmp_id) = MakeNode(RAW_DATA_CMD, (yyvsp[0].int_val), INT_NODE_TYPE);
                                       root = (yyval.tmp_id);             
                                }
#line 1682 "./parser/Parser.cpp"
    break;

  case 20:
#line 114 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeNode(RAW_DATA_CMD, (yyvsp[0].dou_val), DOUBLE_NODE_TYPE);
                                        root = (yyval.tmp_id);          
                                }
#line 1691 "./parser/Parser.cpp"
    break;

  case 21:
#line 118 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeNode(RAW_DATA_CMD, (yyvsp[0].flo_val), FLOAT_NODE_TYPE);
                                        root = (yyval.tmp_id);            
                                }
#line 1700 "./parser/Parser.cpp"
    break;

  case 22:
#line 122 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeNode(RAW_DATA_CMD, (string)(yyvsp[0].str_val), STRING_NODE_TYPE);
                                        root = (yyval.tmp_id);                    
                                }
#line 1709 "./parser/Parser.cpp"
    break;

  case 23:
#line 126 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeNode(RAW_DATA_CMD, (yyvsp[0].char_val), CHAR_NODE_TYPE);
                                        root = (yyval.tmp_id);
                                }
#line 1718 "./parser/Parser.cpp"
    break;

  case 24:
#line 130 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = MakeNode(RAW_DATA_CMD, (yyvsp[0].bol_val), BOOL_NODE_TYPE);
                                        root = (yyval.tmp_id);
                                }
#line 1727 "./parser/Parser.cpp"
    break;

  case 25:
#line 134 "./parser/Parser.y"
                                                { 
                                        (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                        root = (yyval.tmp_id);         
                                }
#line 1736 "./parser/Parser.cpp"
    break;

  case 26:
#line 140 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeNode(RAW_DATA_CMD, (string)(yyvsp[0].types), VAR_TYPE_NODE_TYPE); root = (yyval.tmp_id); }
#line 1742 "./parser/Parser.cpp"
    break;

  case 27:
#line 141 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeNode(RAW_DATA_CMD, (string)(yyvsp[0].types), VAR_TYPE_NODE_TYPE); root = (yyval.tmp_id); }
#line 1748 "./parser/Parser.cpp"
    break;

  case 28:
#line 142 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeNode(RAW_DATA_CMD, (string)(yyvsp[0].types), VAR_TYPE_NODE_TYPE); root = (yyval.tmp_id); }
#line 1754 "./parser/Parser.cpp"
    break;

  case 29:
#line 143 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeNode(RAW_DATA_CMD, (string)(yyvsp[0].types), VAR_TYPE_NODE_TYPE); root = (yyval.tmp_id); }
#line 1760 "./parser/Parser.cpp"
    break;

  case 30:
#line 144 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeNode(RAW_DATA_CMD, (string)(yyvsp[0].types), VAR_TYPE_NODE_TYPE); root = (yyval.tmp_id); }
#line 1766 "./parser/Parser.cpp"
    break;

  case 31:
#line 145 "./parser/Parser.y"
                                                { (yyval.tmp_id) = MakeNode(RAW_DATA_CMD, (string)(yyvsp[0].types), VAR_TYPE_NODE_TYPE); root = (yyval.tmp_id); }
#line 1772 "./parser/Parser.cpp"
    break;

  case 32:
#line 148 "./parser/Parser.y"
                                                                            {
                                   (yyval.tmp_id) = (yyvsp[-4].tmp_id);
                                   (yyval.tmp_id)->PutInAdditional((yyvsp[0].tmp_id));
                                   root = (yyval.tmp_id);
                                }
#line 1782 "./parser/Parser.cpp"
    break;

  case 33:
#line 153 "./parser/Parser.y"
                                                                           {
                                    (yyval.tmp_id) = (yyvsp[-4].tmp_id);
                                    (yyval.tmp_id)->PutInAdditional((yyvsp[0].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 1792 "./parser/Parser.cpp"
    break;

  case 38:
#line 164 "./parser/Parser.y"
                                   {
                                    (yyval.tmp_id) = MakeNode(RAW_DATA_CMD, (yyvsp[0].id), ID_NODE_TYPE);
                                    root = (yyval.tmp_id); 
                                }
#line 1801 "./parser/Parser.cpp"
    break;

  case 39:
#line 169 "./parser/Parser.y"
                                                                           {
                                    (yyval.tmp_id) = MakeNode(BIND_CMD);                                    
                                    (yyval.tmp_id)->SetLeft((yyvsp[-7].tmp_id));
                                    (yyval.tmp_id)->SetMiddle((yyvsp[-4].tmp_id));
                                    (yyval.tmp_id)->SetRight((yyvsp[0].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 1813 "./parser/Parser.cpp"
    break;

  case 40:
#line 176 "./parser/Parser.y"
                                                                               {
                                    (yyval.tmp_id) = MakeNode(MAKE_UNION_CMD);
                                    (yyval.tmp_id)->SetLeft((yyvsp[-7].tmp_id));
                                    (yyval.tmp_id)->SetRight((yyvsp[0].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 1824 "./parser/Parser.cpp"
    break;

  case 41:
#line 182 "./parser/Parser.y"
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
#line 1840 "./parser/Parser.cpp"
    break;

  case 42:
#line 193 "./parser/Parser.y"
                                                            {
                                   (yyval.tmp_id) = MakeNode(REBIND_CMD);
                                   (yyval.tmp_id)->SetLeft((yyvsp[-4].tmp_id));
                                   (yyval.tmp_id)->SetRight((yyvsp[0].tmp_id));
                                   root = (yyval.tmp_id);
                                }
#line 1851 "./parser/Parser.cpp"
    break;

  case 43:
#line 199 "./parser/Parser.y"
                                                                                         {
                                    (yyval.tmp_id) = MakeNode(REFBIND_CMD);
                                    (yyval.tmp_id)->SetLeft((yyvsp[-10].tmp_id));
                                    (yyval.tmp_id)->SetMiddle((yyvsp[-7].tmp_id));
                                    (yyval.tmp_id)->SetRight((yyvsp[0].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 1863 "./parser/Parser.cpp"
    break;

  case 44:
#line 206 "./parser/Parser.y"
                                                                                             {
                                    (yyval.tmp_id) = MakeNode(MAKE_LIST_CMD);
                                    (yyval.tmp_id)->SetLeft((yyvsp[-11].tmp_id));
                                    (yyval.tmp_id)->SetRight((yyvsp[-6].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 1874 "./parser/Parser.cpp"
    break;

  case 45:
#line 212 "./parser/Parser.y"
                                                                                                                                    {
                                    (yyval.tmp_id) = MakeNode(MAKE_MAP_CMD);
                                    (yyval.tmp_id)->SetLeft((yyvsp[-15].tmp_id));
                                    (yyval.tmp_id)->SetMiddle((yyvsp[-10].tmp_id));
                                    (yyval.tmp_id)->SetRight((yyvsp[-6].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 1886 "./parser/Parser.cpp"
    break;

  case 46:
#line 219 "./parser/Parser.y"
                                                                                          {
                                    (yyval.tmp_id) = MakeNode(MAKE_LIST_CMD);
                                    (yyval.tmp_id)->SetLeft((yyvsp[-10].tmp_id));
                                    (yyval.tmp_id)->SetMiddle((yyvsp[0].tmp_id));
                                    (yyval.tmp_id)->SetRight((yyvsp[-5].tmp_id));
                                    root = (yyval.tmp_id);

                                }
#line 1899 "./parser/Parser.cpp"
    break;

  case 47:
#line 227 "./parser/Parser.y"
                                                                        {
                                    (yyval.tmp_id) = MakeNode(REFBIND_CMD);
                                    (yyval.tmp_id)->SetLeft((yyvsp[-7].tmp_id));
                                    (yyval.tmp_id)->SetRight((yyvsp[-3].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 1910 "./parser/Parser.cpp"
    break;

  case 48:
#line 236 "./parser/Parser.y"
                                           {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 1918 "./parser/Parser.cpp"
    break;

  case 49:
#line 239 "./parser/Parser.y"
                                                   {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 1926 "./parser/Parser.cpp"
    break;

  case 50:
#line 242 "./parser/Parser.y"
                                                             {  
                                    (yyvsp[-2].tmp_id)->PutInAdditional((yyvsp[0].tmp_id));
                                    (yyval.tmp_id) = (yyvsp[-2].tmp_id);
                                }
#line 1935 "./parser/Parser.cpp"
    break;

  case 51:
#line 246 "./parser/Parser.y"
                                                                  {
                                    (yyvsp[-2].tmp_id)->PutInAdditional((yyvsp[0].tmp_id));
                                    (yyval.tmp_id) = (yyvsp[-2].tmp_id);
                                }
#line 1944 "./parser/Parser.cpp"
    break;

  case 56:
#line 258 "./parser/Parser.y"
                                                                            { 
                                    (yyval.tmp_id) = MakeNode(PRINT_CMD);
                                    (yyval.tmp_id)->SetLeft((yyvsp[-2].tmp_id));
                                    for(size_t index = 0; index < (yyvsp[-2].tmp_id)->Extras(); index++) {
                                        (yyval.tmp_id)->SetLeft((yyvsp[-2].tmp_id)->GetAdditional(index));
                                        (yyvsp[-2].tmp_id)->NullAdditional(index);
                                    }
                                    root = (yyval.tmp_id);
                                }
#line 1958 "./parser/Parser.cpp"
    break;

  case 57:
#line 267 "./parser/Parser.y"
                                                     { return 0; }
#line 1964 "./parser/Parser.cpp"
    break;

  case 58:
#line 272 "./parser/Parser.y"
                                                                       {
                                    Perform((yyval.tmp_id), (yyvsp[-2].tmp_id), ADDITION_CMD);
                                    root = (yyval.tmp_id);
                                }
#line 1973 "./parser/Parser.cpp"
    break;

  case 59:
#line 276 "./parser/Parser.y"
                                                                         {
                                    Perform((yyval.tmp_id), (yyvsp[-2].tmp_id), SUBTRACTION_CMD);
                                    root = (yyval.tmp_id);
                                }
#line 1982 "./parser/Parser.cpp"
    break;

  case 60:
#line 280 "./parser/Parser.y"
                                                                          {
                                    Perform((yyval.tmp_id), (yyvsp[-2].tmp_id), MULTIPLY_CMD);
                                    root = (yyval.tmp_id);
                                }
#line 1991 "./parser/Parser.cpp"
    break;

  case 61:
#line 284 "./parser/Parser.y"
                                                                          {
                                    Perform((yyval.tmp_id), (yyvsp[-2].tmp_id), DIVIDE_CMD);
                                    root = (yyval.tmp_id);
                                }
#line 2000 "./parser/Parser.cpp"
    break;

  case 62:
#line 288 "./parser/Parser.y"
                                                                          {
                                    Perform((yyval.tmp_id), (yyvsp[-2].tmp_id), POW_CMD);
                                    root = (yyval.tmp_id);
                                }
#line 2009 "./parser/Parser.cpp"
    break;

  case 63:
#line 297 "./parser/Parser.y"
                                                                                           {
                                    (yyval.tmp_id) = MakeNode(LESS_CMD);
                                    (yyval.tmp_id)->SetLeft((yyvsp[-4].tmp_id));
                                    (yyval.tmp_id)->SetRight((yyvsp[-2].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2020 "./parser/Parser.cpp"
    break;

  case 64:
#line 303 "./parser/Parser.y"
                                                                                                {
                                    (yyval.tmp_id) = MakeNode(GREATER_CMD);
                                    (yyval.tmp_id)->SetLeft((yyvsp[-4].tmp_id));
                                    (yyval.tmp_id)->SetRight((yyvsp[-2].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2031 "./parser/Parser.cpp"
    break;

  case 65:
#line 309 "./parser/Parser.y"
                                                                                                  {
                                    (yyval.tmp_id) = MakeNode(LESS_EQ_CMD);
                                    (yyval.tmp_id)->SetLeft((yyvsp[-4].tmp_id));
                                    (yyval.tmp_id)->SetRight((yyvsp[-2].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2042 "./parser/Parser.cpp"
    break;

  case 66:
#line 315 "./parser/Parser.y"
                                                                                                      {
                                    (yyval.tmp_id) = MakeNode(GREATER_EQ_CMD);
                                    (yyval.tmp_id)->SetLeft((yyvsp[-4].tmp_id));
                                    (yyval.tmp_id)->SetRight((yyvsp[-2].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2053 "./parser/Parser.cpp"
    break;

  case 67:
#line 321 "./parser/Parser.y"
                                                                                             {
                                    (yyval.tmp_id) = MakeNode(EQ_CMD);
                                    (yyval.tmp_id)->SetLeft((yyvsp[-4].tmp_id));
                                    (yyval.tmp_id)->SetRight((yyvsp[-2].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2064 "./parser/Parser.cpp"
    break;

  case 68:
#line 327 "./parser/Parser.y"
                                                                                                  {
                                    (yyval.tmp_id) = MakeNode(NOT_CMD);

                                    auto equal = MakeNode(EQ_CMD);
                                    equal->SetLeft((yyvsp[-4].tmp_id));
                                    equal->SetRight((yyvsp[-2].tmp_id));

                                    (yyval.tmp_id)->SetLeft(equal);

                                    root = (yyval.tmp_id);
                                }
#line 2080 "./parser/Parser.cpp"
    break;

  case 69:
#line 342 "./parser/Parser.y"
                                                                                         {
                                    (yyval.tmp_id) = MakeNode(AND_CMD);
                                    (yyval.tmp_id)->SetLeft((yyvsp[-4].tmp_id));
                                    (yyval.tmp_id)->SetRight((yyvsp[-2].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2091 "./parser/Parser.cpp"
    break;

  case 70:
#line 348 "./parser/Parser.y"
                                                                 {
                                    (yyval.tmp_id) = MakeNode(NOT_CMD);
                                    (yyval.tmp_id)->SetLeft((yyvsp[-2].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2101 "./parser/Parser.cpp"
    break;

  case 71:
#line 353 "./parser/Parser.y"
                                                                                           {
                                    (yyval.tmp_id) = MakeNode(OR_CMD);
                                    (yyval.tmp_id)->SetLeft((yyvsp[-4].tmp_id));
                                    (yyval.tmp_id)->SetRight((yyvsp[-2].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2112 "./parser/Parser.cpp"
    break;

  case 72:
#line 362 "./parser/Parser.y"
                                     {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                    root = (yyval.tmp_id);
                                }
#line 2121 "./parser/Parser.cpp"
    break;

  case 73:
#line 366 "./parser/Parser.y"
                                            {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                    root = (yyval.tmp_id);
                                }
#line 2130 "./parser/Parser.cpp"
    break;

  case 74:
#line 370 "./parser/Parser.y"
                                                                                          {
                                    (yyval.tmp_id) = MakeNode(CAST_TYPE_CMD);
                                    (yyval.tmp_id)->SetLeft((yyvsp[-4].tmp_id));
                                    (yyval.tmp_id)->SetRight((yyvsp[-2].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2141 "./parser/Parser.cpp"
    break;

  case 75:
#line 376 "./parser/Parser.y"
                                               {
                                   (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                   root = (yyval.tmp_id);
                                }
#line 2150 "./parser/Parser.cpp"
    break;

  case 76:
#line 380 "./parser/Parser.y"
                                           {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                    root = (yyval.tmp_id);
                                }
#line 2159 "./parser/Parser.cpp"
    break;

  case 77:
#line 384 "./parser/Parser.y"
                                                                                         {
                                     (yyval.tmp_id) = MakeNode(PUT_IN_CONTAINER_CMD);
                                     (yyval.tmp_id)->SetLeft((yyvsp[-7].tmp_id));
                                     (yyval.tmp_id)->SetRight((yyvsp[-2].tmp_id));
                                     root = (yyval.tmp_id);
                                }
#line 2170 "./parser/Parser.cpp"
    break;

  case 78:
#line 390 "./parser/Parser.y"
                                                                                                        {
                                    (yyval.tmp_id) = MakeNode(PUT_IN_MAP_CMD);
                                    (yyval.tmp_id)->SetLeft((yyvsp[-9].tmp_id));
                                    (yyval.tmp_id)->SetMiddle((yyvsp[-4].tmp_id));
                                    (yyval.tmp_id)->SetRight((yyvsp[-2].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2182 "./parser/Parser.cpp"
    break;

  case 79:
#line 397 "./parser/Parser.y"
                                                                             {
                                    (yyval.tmp_id) = MakeNode(GET_FROM_CONTAINER_CMD);
                                    (yyval.tmp_id)->SetLeft((yyvsp[-5].tmp_id));
                                    (yyval.tmp_id)->SetRight((yyvsp[-2].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2193 "./parser/Parser.cpp"
    break;

  case 80:
#line 403 "./parser/Parser.y"
                                                                                                          {
                                    (yyval.tmp_id) = MakeNode(SET_IN_CONTAINER_CMD);
                                    (yyval.tmp_id)->SetLeft((yyvsp[-9].tmp_id));
                                    (yyval.tmp_id)->SetMiddle((yyvsp[-4].tmp_id));
                                    (yyval.tmp_id)->SetRight((yyvsp[-2].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2205 "./parser/Parser.cpp"
    break;

  case 81:
#line 410 "./parser/Parser.y"
                                                            {
                                    (yyval.tmp_id) = MakeNode(GET_CONTAINER_SIZE_CMD);
                                    (yyval.tmp_id)->SetLeft((yyvsp[-4].tmp_id));
                                    root = (yyval.tmp_id);
                                }
#line 2215 "./parser/Parser.cpp"
    break;

  case 89:
#line 424 "./parser/Parser.y"
                                       { 
                                    i.EatAst(root);
                                    return 0 ;
                                }
#line 2224 "./parser/Parser.cpp"
    break;

  case 91:
#line 429 "./parser/Parser.y"
                                        {  }
#line 2230 "./parser/Parser.cpp"
    break;


#line 2234 "./parser/Parser.cpp"

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
#line 432 "./parser/Parser.y"



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
