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
#include "../src/ChmrInterpreter.hpp"
#include "Utils/IntrBridge.hpp"

using namespace std;

int lineno = 0;
ChmrInterpreter i;
string scope_type;

void PrintLineNo();
void yyerror(const char* err);
extern int yylex();
extern FILE *yyin;
extern void yyrestart(FILE* input);
extern char* yytext;

#line 93 "./parser/Parser.cpp"

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
    DO = 292,
    END = 293,
    IF = 294,
    ELSE = 295,
    INT_VAL = 296,
    DOUBLE_VAL = 297,
    STRING_VAL = 298,
    CHAR_VAL = 299,
    BOOL_VAL = 300,
    ELSE_IF = 301,
    FLOAT_VAL = 302,
    MULTI_WS = 303,
    SINGLE_WS = 304,
    ID = 305,
    UNKNOWN = 306
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
#define YYFINAL  68
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   679

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  300

#define YYUNDEFTOK  2
#define YYMAXUTOK   306


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
      61,    62,     2,     2,     2,     2,    63,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    53,     2,
      55,    54,    56,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    57,     2,    58,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    59,    52,    60,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    59,    59,    67,    71,    71,    71,    71,    73,    75,
      82,    92,   105,   115,   115,   117,   118,   119,   120,   123,
     123,   125,   133,   141,   149,   161,   169,   177,   186,   187,
     188,   189,   190,   191,   195,   200,   206,   206,   208,   208,
     210,   215,   221,   227,   232,   237,   242,   247,   252,   260,
     266,   272,   281,   293,   294,   294,   295,   295,   297,   298,
     309,   314,   321,   328,   335,   342,   349,   356,   363,   370,
     382,   389,   396,   403,   410,   417,   428,   435,   442,   452,
     455,   458,   465,   468,   471,   478,   485,   492,   501,   502,
     503,   504,   505,   506,   507,   508,   511,   512,   514,   514
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
  "DIV", "POW", "ADD_LIST", "ADD_MAP", "SET", "GET", "POINTS_TO", "DO",
  "END", "IF", "ELSE", "INT_VAL", "DOUBLE_VAL", "STRING_VAL", "CHAR_VAL",
  "BOOL_VAL", "ELSE_IF", "FLOAT_VAL", "MULTI_WS", "SINGLE_WS", "ID",
  "UNKNOWN", "'|'", "':'", "'='", "'<'", "'>'", "'['", "']'", "'{'", "'}'",
  "'('", "')'", "'.'", "$accept", "do", "end", "scope", "newScope",
  "ifMod", "elseif", "elseMod", "elifMod", "elifChain", "if", "newline",
  "term", "types", "unionTypes", "any_ws", "opt_ws", "assign", "exprList",
  "opt_newline", "opt_ws_or_nl", "ws_or_nl", "statement", "math_expr",
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
     305,   306,   124,    58,    61,    60,    62,    91,    93,   123,
     125,    40,    41,    46
};
# endif

#define YYPACT_NINF (-194)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-40)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     618,  -194,    -6,   -43,  -194,  -194,  -194,  -194,    -6,  -194,
    -194,  -194,  -194,  -194,  -194,  -194,  -194,    63,   272,    10,
     -10,  -194,    34,  -194,  -194,  -194,  -194,  -194,   -12,  -194,
    -194,  -194,    37,  -194,     7,  -194,   -14,    -6,    31,    -6,
      31,   146,    28,    -6,    -6,    -6,    -6,    -6,    -6,    -6,
      -6,    -6,    -6,    -6,    -6,    -6,    -6,    -6,   127,   500,
    -194,  -194,     1,  -194,  -194,  -194,  -194,  -194,  -194,  -194,
      -6,    42,    22,    -6,    14,    40,    48,    56,    73,    -6,
      -6,    31,    31,    31,    31,    31,    31,    31,    31,    31,
      31,    31,    31,    31,    31,   552,   585,  -194,  -194,    -6,
      -6,    34,     1,    46,    -6,  -194,  -194,  -194,  -194,  -194,
    -194,  -194,  -194,    72,    74,    -6,    15,    -6,  -194,    -6,
      31,    -6,    31,    -6,    -6,    -6,    -6,    -6,    -6,    -6,
      -6,    -6,    -6,    -6,    -6,    -6,    -6,    -6,    31,    34,
    -194,  -194,    -6,    34,    -6,  -194,    31,   113,  -194,    92,
     264,   264,   104,   134,    43,    52,   107,    -6,    31,   130,
     215,   113,  -194,   264,    31,    31,    31,    31,    31,    31,
      31,    31,   100,    61,   125,    61,   129,    61,   137,    61,
     138,    31,    -6,   -10,    34,  -194,    31,  -194,    -6,  -194,
     154,    -6,    -6,   156,    -6,    -6,    -6,    -6,  -194,   191,
      31,    -6,   190,    -6,    -6,    -6,    -6,    -6,    -6,    -6,
      -6,    -6,  -194,    -6,  -194,    99,  -194,   135,  -194,    -6,
    -194,    -6,  -194,  -194,   -10,  -194,    31,    -6,   182,    31,
      -6,   264,    31,   264,    31,    -6,   168,    31,   165,   199,
     161,   162,   164,   167,   169,   170,   172,   173,   174,    -9,
    -194,  -194,   175,   192,  -194,  -194,   176,    -6,  -194,   209,
    -194,  -194,  -194,  -194,    31,  -194,    -6,  -194,    -6,  -194,
    -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,  -194,
    -194,    -6,   264,    -6,   201,  -194,    96,   171,    31,  -194,
     216,  -194,    -6,  -194,  -194,   219,    -6,   218,   222,  -194
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    97,    39,     0,    19,    20,    95,     2,     0,    21,
      22,    24,    25,    26,    23,    36,    37,    27,     0,     0,
       0,    92,     0,    94,    93,    79,    96,    58,     0,    80,
      82,    83,     0,    98,     0,    38,     0,    39,     0,    39,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       3,     8,     0,    15,    91,    90,    89,    88,     1,    99,
      39,     0,    27,     0,     0,     0,     0,     0,     0,    39,
      39,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    11,    10,     0,
       0,     0,     0,     0,    39,    60,     9,    28,    29,    30,
      31,    32,    33,     0,     0,    39,    39,    39,    86,    39,
       0,    39,     0,    39,     0,     0,     0,     0,     0,     0,
       0,     0,    39,    39,    39,    39,    39,     0,     0,     0,
      13,    17,     0,     0,    39,    49,    38,    54,    55,     0,
       0,     0,     0,     0,     0,     0,    39,     0,     0,    43,
      56,     0,    57,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    39,     0,    39,     0,    39,     0,    39,
       0,     0,     0,     0,     0,    14,     0,    51,    39,    59,
       0,    39,    39,     0,    39,    39,    39,    39,    84,     0,
       0,     0,     0,    39,    39,    39,    39,    39,    39,    39,
      39,    39,    77,    39,    62,    39,    64,    39,    66,    39,
      68,    39,    12,    16,     0,    50,    53,    39,     0,     0,
      39,     0,     0,     0,     0,    39,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      63,    65,     0,     0,    18,    52,     0,    39,    41,     0,
      34,    40,    35,    42,     0,    85,    39,    48,    39,    81,
      70,    71,    72,    73,    74,    75,    76,    78,    61,    67,
      69,    39,     0,    39,     0,    53,     0,     0,     0,    87,
       0,    47,    39,    44,    45,     0,    39,     0,     0,    46
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -194,  -194,  -100,   -21,   253,  -194,  -194,   193,   195,  -194,
    -194,     8,  -194,  -147,  -194,   354,    -2,  -194,   -74,   183,
    -193,  -194,  -194,  -194,  -194,  -194,   158,   -29,   123
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    19,    61,    20,    21,    22,    99,   100,   101,   102,
      23,    24,    25,   116,   117,    35,   103,    27,   104,   148,
     149,   163,    28,    29,    30,    31,    32,    33,    34
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      36,    62,   141,   190,   191,    69,   123,    68,     1,    37,
     240,     4,     5,    64,   235,    42,   203,   107,   108,   109,
     110,   111,   112,   113,   114,     2,   252,    58,    60,     3,
       4,     5,     6,     4,     5,    71,    65,    74,    70,    60,
      67,    97,    15,    16,     7,   156,     8,    98,     9,    10,
      11,    12,    13,   278,    14,    15,    16,    17,    15,    16,
       4,     5,    66,    15,    16,   115,    69,    69,    18,   144,
     153,     7,     9,    10,    11,    12,    13,   122,    14,    40,
     140,    72,    79,   223,   260,    41,   262,     9,    10,    11,
      12,    13,    18,    14,   105,   194,    72,   195,   118,   213,
     119,   215,   147,   217,   196,   219,   197,    18,   120,    15,
      16,    15,    16,   152,   154,   155,    39,   -39,   183,   158,
      40,   161,   185,   -38,   254,   121,    41,   150,     1,   151,
     172,   174,   176,   178,   180,   287,   188,     9,    10,    11,
      12,    13,   186,    14,   189,     2,    72,    15,    16,     3,
       4,     5,     6,   290,   199,    15,    16,    18,   192,   198,
     193,   250,   212,   224,     7,    -6,     8,    -6,     9,    10,
      11,    12,    13,    -6,    14,    15,    16,    17,    76,    77,
      78,    95,    96,    15,    16,   202,   226,   214,    18,   228,
     229,   216,   231,   232,   233,   234,    73,   251,    75,   218,
     220,   239,   241,   242,   243,   244,   245,   246,   247,   248,
     227,   249,   230,   199,   235,   199,   238,   147,   257,   253,
     265,   267,   268,   269,   270,   256,   271,   292,   259,   272,
     281,   273,   274,   264,   275,   276,   277,   279,   -38,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   289,   280,   282,     9,    10,    11,    12,
      13,   145,    14,   283,   284,    72,   285,   107,   108,   109,
     110,   111,   112,   296,   294,    63,    18,   298,   157,   286,
     159,   288,   299,    43,    44,    45,    46,    47,    48,    49,
     295,    50,    51,    52,   297,   142,   182,   143,     0,    53,
      54,    55,    56,    57,   187,     0,   162,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   201,     0,   187,     0,
       0,     0,   204,   205,   206,   207,   208,   209,   210,   211,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   221,
       0,     0,     0,     0,   225,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26,     0,     0,     0,   236,     0,
       0,     0,    38,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    59,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   255,     0,     0,   258,    26,     0,
     261,     0,   263,     0,     0,   266,     0,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    26,    26,     0,     0,     0,     0,     0,     0,
       0,     0,   255,     0,     0,     0,     0,   106,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   291,     0,   293,     0,     0,    26,
      26,     0,     0,   138,   139,     0,     0,     0,   146,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   160,   164,   165,
     166,   167,   168,   169,   170,   171,     0,   173,   175,   177,
     179,   181,     0,     0,     0,     0,   184,     0,     0,     0,
       0,     1,     0,     0,     0,     0,     0,     0,     0,     0,
     146,   200,     0,     0,     0,     0,     0,     0,     2,     0,
       0,     0,     3,     4,     5,     6,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   222,     7,    -7,     8,
      -7,     9,    10,    11,    12,    13,    -7,    14,    15,    16,
      17,     0,     0,     1,     0,   237,     0,     0,     0,     0,
       0,    18,     0,     0,     0,     0,     0,   146,     0,   146,
       2,   146,     0,   146,     3,     4,     5,     6,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     0,     0,     7,
      -4,     8,    -4,     9,    10,    11,    12,    13,    -4,    14,
      15,    16,    17,     2,     0,     0,     0,     3,     4,     5,
       6,     0,     0,    18,     0,     0,     0,     0,     0,     1,
       0,     0,     7,    -5,     8,    -5,     9,    10,    11,    12,
      13,    -5,    14,    15,    16,    17,     2,     0,     0,     0,
       3,     4,     5,     6,     0,     0,    18,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     0,     8,     0,     9,
      10,    11,    12,    13,     0,    14,    15,    16,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18
};

static const yytype_int16 yycheck[] =
{
       2,    22,   102,   150,   151,    34,    80,     0,     1,    52,
     203,    23,    24,    25,    23,    17,   163,     3,     4,     5,
       6,     7,     8,     9,    10,    18,   219,    19,    38,    22,
      23,    24,    25,    23,    24,    37,    28,    39,    52,    38,
      32,    40,    48,    49,    37,   119,    39,    46,    41,    42,
      43,    44,    45,    62,    47,    48,    49,    50,    48,    49,
      23,    24,    25,    48,    49,    51,    95,    96,    61,    23,
      55,    37,    41,    42,    43,    44,    45,    79,    47,    57,
     101,    50,    54,   183,   231,    63,   233,    41,    42,    43,
      44,    45,    61,    47,    52,    52,    50,    54,    58,   173,
      52,   175,   104,   177,    52,   179,    54,    61,    52,    48,
      49,    48,    49,   115,   116,   117,    53,    54,   139,   121,
      57,   123,   143,    62,   224,    52,    63,    55,     1,    55,
     132,   133,   134,   135,   136,   282,    23,    41,    42,    43,
      44,    45,   144,    47,    52,    18,    50,    48,    49,    22,
      23,    24,    25,    57,   156,    48,    49,    61,    54,    52,
      26,    62,    62,   184,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    32,    33,
      34,    58,    59,    48,    49,    55,   188,    62,    61,   191,
     192,    62,   194,   195,   196,   197,    38,    62,    40,    62,
      62,   203,   204,   205,   206,   207,   208,   209,   210,   211,
      56,   213,    56,   215,    23,   217,    26,   219,    36,   221,
      52,    56,    23,    62,    62,   227,    62,    56,   230,    62,
      54,    62,    62,   235,    62,    62,    62,    62,    23,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    52,    62,   257,    41,    42,    43,    44,
      45,   103,    47,    54,   266,    50,   268,     3,     4,     5,
       6,     7,     8,    54,    58,    22,    61,    59,   120,   281,
     122,   283,    60,    11,    12,    13,    14,    15,    16,    17,
     292,    19,    20,    21,   296,   102,   138,   102,    -1,    27,
      28,    29,    30,    31,   146,    -1,   123,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   158,    -1,   160,    -1,
      -1,    -1,   164,   165,   166,   167,   168,   169,   170,   171,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,
      -1,    -1,    -1,    -1,   186,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     0,    -1,    -1,    -1,   200,    -1,
      -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   226,    -1,    -1,   229,    34,    -1,
     232,    -1,   234,    -1,    -1,   237,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   264,    -1,    -1,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   286,    -1,   288,    -1,    -1,    95,
      96,    -1,    -1,    99,   100,    -1,    -1,    -1,   104,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,   124,   125,
     126,   127,   128,   129,   130,   131,    -1,   133,   134,   135,
     136,   137,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,
      -1,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     156,   157,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,
      -1,    -1,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   182,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    -1,    -1,     1,    -1,   201,    -1,    -1,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,   213,    -1,   215,
      18,   217,    -1,   219,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    18,    -1,    -1,    -1,    22,    23,    24,
      25,    -1,    -1,    61,    -1,    -1,    -1,    -1,    -1,     1,
      -1,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    18,    -1,    -1,    -1,
      22,    23,    24,    25,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    -1,    39,    -1,    41,
      42,    43,    44,    45,    -1,    47,    48,    49,    50,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    18,    22,    23,    24,    25,    37,    39,    41,
      42,    43,    44,    45,    47,    48,    49,    50,    61,    65,
      67,    68,    69,    74,    75,    76,    79,    81,    86,    87,
      88,    89,    90,    91,    92,    79,    80,    52,    79,    53,
      57,    63,    80,    11,    12,    13,    14,    15,    16,    17,
      19,    20,    21,    27,    28,    29,    30,    31,    75,    79,
      38,    66,    67,    68,    25,    75,    25,    75,     0,    91,
      52,    80,    50,    90,    80,    90,    32,    33,    34,    54,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    92,    92,    40,    46,    70,
      71,    72,    73,    80,    82,    52,    79,     3,     4,     5,
       6,     7,     8,     9,    10,    51,    77,    78,    58,    52,
      52,    52,    80,    82,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    79,    79,
      67,    66,    71,    72,    23,    90,    79,    80,    83,    84,
      55,    55,    80,    55,    80,    80,    82,    90,    80,    90,
      79,    80,    83,    85,    79,    79,    79,    79,    79,    79,
      79,    79,    80,    79,    80,    79,    80,    79,    80,    79,
      80,    79,    90,    67,    79,    67,    80,    90,    23,    52,
      77,    77,    54,    26,    52,    54,    52,    54,    52,    80,
      79,    90,    55,    77,    90,    90,    90,    90,    90,    90,
      90,    90,    62,    82,    62,    82,    62,    82,    62,    82,
      62,    90,    79,    66,    67,    90,    80,    56,    80,    80,
      56,    80,    80,    80,    80,    23,    90,    79,    26,    80,
      84,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      62,    62,    84,    80,    66,    90,    80,    36,    90,    80,
      77,    90,    77,    90,    80,    52,    90,    56,    23,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    54,    80,    54,    80,    80,    80,    77,    80,    52,
      57,    90,    56,    90,    58,    80,    54,    80,    59,    60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    64,    65,    66,    67,    67,    67,    67,    68,    69,
      70,    71,    72,    73,    73,    74,    74,    74,    74,    75,
      75,    76,    76,    76,    76,    76,    76,    76,    77,    77,
      77,    77,    77,    77,    78,    78,    79,    79,    80,    80,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    82,
      82,    82,    82,    83,    84,    84,    85,    85,    86,    86,
      86,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      88,    88,    88,    88,    88,    88,    89,    89,    89,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    92,    92
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     3,     3,     2,     2,     2,     4,
       1,     1,     4,     2,     3,     2,     6,     4,     7,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     5,     1,     1,     1,     0,
       8,     8,     8,     5,    11,    12,    16,    11,     8,     2,
       4,     3,     5,     3,     1,     1,     1,     1,     1,     6,
       4,     8,     6,     7,     6,     7,     6,     8,     6,     8,
       8,     8,     8,     8,     8,     8,     8,     6,     8,     1,
       1,     8,     1,     1,     6,     8,     4,    10,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     2
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
                                    if (scope_type.empty()) {
                                        scope_type = GEN_SCOPE;
                                    }
                                    CreateScope(scope_type, i);
                                    scope_type = "";
                                }
#line 1629 "./parser/Parser.cpp"
    break;

  case 3:
#line 67 "./parser/Parser.y"
                                    {
                                    DestroyScope(i);
                                }
#line 1637 "./parser/Parser.cpp"
    break;

  case 9:
#line 75 "./parser/Parser.y"
                                                      {
                                    scope_type = IF_SCOPE;
                                    if (SetNextScopeRunState((yyvsp[-1].tmp_id), i) == 1) {
                                        return 1;
                                    }
                                }
#line 1648 "./parser/Parser.cpp"
    break;

  case 10:
#line 82 "./parser/Parser.y"
                                        { 
                                            scope_type = ELIF_SCOPE;

                                            // will only be true when the previous if statement couldn't run
                                            (yyval.bol_val) = i.NonRunnableScope();
                                            if (!i.ParentNonRunnableScope()) {
                                                i.OverrideRunnable();
                                            }
                                        }
#line 1662 "./parser/Parser.cpp"
    break;

  case 11:
#line 92 "./parser/Parser.y"
                                     {
                                    scope_type = ELSE_SCOPE;

                                    // will only be true when the previous if statement couldn't run
                                    bool next_run_stat = i.NonRunnableScope();
                                    if (!i.ParentNonRunnableScope()) {
                                        i.OverrideRunnable();
                                    }
                                    StrWrapper expr;
                                    expr = CreateTempVar(next_run_stat, i);
                                    SetNextScopeRunState(expr, i);
                                }
#line 1679 "./parser/Parser.cpp"
    break;

  case 12:
#line 105 "./parser/Parser.y"
                                                          {
                                    StrWrapper part_1;
                                    StrWrapper res;
                                    bool runnable = (yyvsp[-3].bol_val);

                                    part_1 = CreateTempVar(runnable, i);
                                    res = And(part_1, (yyvsp[-1].tmp_id), i);
                                    SetNextScopeRunState(res, i);
                                }
#line 1693 "./parser/Parser.cpp"
    break;

  case 21:
#line 125 "./parser/Parser.y"
                                                { 
                                                    string tmp_name = CreateTempVar((yyvsp[0].int_val), i);
                                                    if (tmp_name.empty()) {
                                                        cout << "Error: couldn't create temp var\n";
                                                        return 1;
                                                    }
                                                    (yyval.tmp_id) = tmp_name;
                                                }
#line 1706 "./parser/Parser.cpp"
    break;

  case 22:
#line 133 "./parser/Parser.y"
                                                { 
                                                    string tmp_name = CreateTempVar((yyvsp[0].dou_val), i);
                                                    if (tmp_name.empty()) {
                                                        cout << "Error: couldn't create temp var\n";
                                                        return 1;
                                                    }
                                                    (yyval.tmp_id) = tmp_name;
                                                }
#line 1719 "./parser/Parser.cpp"
    break;

  case 23:
#line 141 "./parser/Parser.y"
                                                { 
                                                    string tmp_name = CreateTempVar((yyvsp[0].flo_val), i);
                                                    if (tmp_name.empty()) {
                                                        cout << "Error: couldn't create temp var\n";
                                                        return 1;
                                                    }
                                                    (yyval.tmp_id) = tmp_name;
                                                }
#line 1732 "./parser/Parser.cpp"
    break;

  case 24:
#line 149 "./parser/Parser.y"
                                                { 
                                                    // deliberately declared data type here
                                                    // because $1 is a StrWrapper, not a string. 
                                                    // so implicit conversion will cause bugs that don't
                                                    // allow for compilation
                                                     string tmp_name = CreateTempVar<string>((yyvsp[0].str_val), i);
                                                     if (tmp_name.empty()) {
                                                         cout << "Error: couldn't create temp var\n";
                                                         return 1;
                                                     }
                                                     (yyval.tmp_id) = tmp_name;
                                                }
#line 1749 "./parser/Parser.cpp"
    break;

  case 25:
#line 161 "./parser/Parser.y"
                                                { 
                                                    string tmp_name = CreateTempVar((yyvsp[0].char_val), i);
                                                    if (tmp_name.empty()) {
                                                        cout << "Error: couldn't create temp var\n";
                                                        return 1;
                                                    }
                                                    (yyval.tmp_id) = tmp_name;
                                                }
#line 1762 "./parser/Parser.cpp"
    break;

  case 26:
#line 169 "./parser/Parser.y"
                                                { 
                                                    string tmp_name = CreateTempVar((yyvsp[0].bol_val), i);
                                                    if (tmp_name.empty()) {
                                                        cout << "Error: couldn't create temp var\n";
                                                        return 1;
                                                    }
                                                    (yyval.tmp_id) = tmp_name;
                                                }
#line 1775 "./parser/Parser.cpp"
    break;

  case 27:
#line 177 "./parser/Parser.y"
                                                { 
                                                    string tmp = CloneToTemp((yyvsp[0].id), i);
                                                    if (tmp.empty()) {
                                                        return 1;
                                                    }
                                                    (yyval.tmp_id) = tmp;
                                                }
#line 1787 "./parser/Parser.cpp"
    break;

  case 28:
#line 186 "./parser/Parser.y"
                                                { (yyval.types) = (yyvsp[0].types); }
#line 1793 "./parser/Parser.cpp"
    break;

  case 29:
#line 187 "./parser/Parser.y"
                                                { (yyval.types) = (yyvsp[0].types); }
#line 1799 "./parser/Parser.cpp"
    break;

  case 30:
#line 188 "./parser/Parser.y"
                                                { (yyval.types) = (yyvsp[0].types); }
#line 1805 "./parser/Parser.cpp"
    break;

  case 31:
#line 189 "./parser/Parser.y"
                                                { (yyval.types) = (yyvsp[0].types); }
#line 1811 "./parser/Parser.cpp"
    break;

  case 32:
#line 190 "./parser/Parser.y"
                                                { (yyval.types) = (yyvsp[0].types); }
#line 1817 "./parser/Parser.cpp"
    break;

  case 33:
#line 191 "./parser/Parser.y"
                                                { (yyval.types) = (yyvsp[0].types); }
#line 1823 "./parser/Parser.cpp"
    break;

  case 34:
#line 195 "./parser/Parser.y"
                                                             {
                                    (yyvsp[-4].types).AddPending((yyvsp[-4].types));
                                    (yyvsp[-4].types).AddPending((yyvsp[0].types));
                                    (yyval.tmp_id) = (yyvsp[-4].types);
                                }
#line 1833 "./parser/Parser.cpp"
    break;

  case 35:
#line 200 "./parser/Parser.y"
                                                                     {
                                    (yyvsp[-4].tmp_id).AddPending((yyvsp[0].types));
                                    (yyval.tmp_id) = (yyvsp[-4].tmp_id);
                                }
#line 1842 "./parser/Parser.cpp"
    break;

  case 40:
#line 210 "./parser/Parser.y"
                                                                           {
                                    if (Assign((yyvsp[-7].id), (yyvsp[0].tmp_id), (yyvsp[-4].types), i).empty()) {
                                        return 1;
                                    }
                                }
#line 1852 "./parser/Parser.cpp"
    break;

  case 41:
#line 215 "./parser/Parser.y"
                                                                               {
                                    bool made_union = !MakeUnknown((yyvsp[-7].id), (yyvsp[0].tmp_id), i).empty();
                                    if(!made_union) {
                                        return 1;
                                    }
                                }
#line 1863 "./parser/Parser.cpp"
    break;

  case 42:
#line 221 "./parser/Parser.y"
                                                                                  {
                                    auto union_name = MakeUnion((yyvsp[-7].id), (yyvsp[-4].tmp_id), (yyvsp[0].tmp_id), i);
                                    if (union_name.empty()) {
                                        return 1;
                                    }
                                }
#line 1874 "./parser/Parser.cpp"
    break;

  case 43:
#line 227 "./parser/Parser.y"
                                                            {
                                    if(Reassign((yyvsp[-4].id), (yyvsp[0].tmp_id), i).empty()) {
                                        return 1;
                                    }
                                }
#line 1884 "./parser/Parser.cpp"
    break;

  case 44:
#line 232 "./parser/Parser.y"
                                                                                         {
                                    if (RefBind((yyvsp[-10].id), (yyvsp[0].tmp_id), (yyvsp[-7].types), i).empty()) {
                                        return 1;
                                    }
                                }
#line 1894 "./parser/Parser.cpp"
    break;

  case 45:
#line 237 "./parser/Parser.y"
                                                                                             {
                                    if(MakeList((yyvsp[-11].id), (yyvsp[-6].types), i).empty()) {
                                        return 1;
                                    }
                                }
#line 1904 "./parser/Parser.cpp"
    break;

  case 46:
#line 242 "./parser/Parser.y"
                                                                                                                                    {
                                    if (MakeMap((yyvsp[-15].id), (yyvsp[-10].types), (yyvsp[-6].types), i).empty()) {
                                        return 1;
                                    }
                                }
#line 1914 "./parser/Parser.cpp"
    break;

  case 47:
#line 247 "./parser/Parser.y"
                                                                                          {
                                    if(ReassignContainer((yyvsp[-10].id), (yyvsp[-5].types), (yyvsp[0].tmp_id), i).empty()) {
                                        return 1;
                                    }
                                }
#line 1924 "./parser/Parser.cpp"
    break;

  case 48:
#line 252 "./parser/Parser.y"
                                                                        {
                                    if (RefBind((yyvsp[-7].id), (yyvsp[-3].tmp_id), i).empty()) {
                                        return 1;
                                    }
                                }
#line 1934 "./parser/Parser.cpp"
    break;

  case 49:
#line 260 "./parser/Parser.y"
                                           {
                                    if(!(yyvsp[0].tmp_id).GetFinalResult().empty()) { 
                                        (yyvsp[0].tmp_id).AddPending((yyvsp[0].tmp_id)); 
                                    }
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id); 
                                }
#line 1945 "./parser/Parser.cpp"
    break;

  case 50:
#line 266 "./parser/Parser.y"
                                                             {
                                    if(!(yyvsp[0].tmp_id).GetFinalResult().empty()) {
                                        (yyvsp[0].tmp_id).AddPending((yyvsp[0].tmp_id));
                                    }
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 1956 "./parser/Parser.cpp"
    break;

  case 51:
#line 272 "./parser/Parser.y"
                                                             {  
                                    if(!(yyvsp[-2].tmp_id).GetFinalResult().empty()) { 
                                        (yyvsp[-2].tmp_id).AddPending((yyvsp[0].tmp_id)); 
                                    }
                                    for(unsigned int i = 0; i < (yyvsp[0].tmp_id).PendingDataSize(); i++) {
                                        (yyvsp[-2].tmp_id).AddPending((yyvsp[0].tmp_id)[i]);
                                    }
                                    (yyval.tmp_id) = (yyvsp[-2].tmp_id);
                                }
#line 1970 "./parser/Parser.cpp"
    break;

  case 52:
#line 281 "./parser/Parser.y"
                                                                            {
                                    auto list = (yyvsp[-4].tmp_id);
                                    if(!list.GetFinalResult().empty()) { 
                                        list.AddPending((yyvsp[0].tmp_id)); 
                                    }
                                    for(unsigned int i = 0; i < (yyvsp[0].tmp_id).PendingDataSize(); i++) {
                                        list.AddPending((yyvsp[0].tmp_id)[i]);
                                    }
                                    (yyval.tmp_id) = list;
                                }
#line 1985 "./parser/Parser.cpp"
    break;

  case 59:
#line 298 "./parser/Parser.y"
                                                                             { 
                                    int err = Print((yyvsp[-2].tmp_id), ' ', i);
                                    
                                    if (err == 1) {
                                        cout << "Error: print error\n";
                                        return 1;
                                    }
                                    else if ((yyvsp[-2].tmp_id).PendingDataSize() > 0 && err == SUCCEED) {
                                        cout << '\n';
                                    }
                                }
#line 2001 "./parser/Parser.cpp"
    break;

  case 60:
#line 309 "./parser/Parser.y"
                                                     { return 0; }
#line 2007 "./parser/Parser.cpp"
    break;

  case 61:
#line 314 "./parser/Parser.y"
                                                                                           {
                                    string tmp = Add((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id), i);
                                    if(tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 2019 "./parser/Parser.cpp"
    break;

  case 62:
#line 321 "./parser/Parser.y"
                                                                 {
                                    string tmp = Add((yyvsp[-2].tmp_id), i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 2031 "./parser/Parser.cpp"
    break;

  case 63:
#line 328 "./parser/Parser.y"
                                                                          {
                                    string tmp = Subtract((yyvsp[-3].tmp_id), (yyvsp[-1].tmp_id), i);
                                    if(tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 2043 "./parser/Parser.cpp"
    break;

  case 64:
#line 335 "./parser/Parser.y"
                                                                 {
                                    string tmp = Subtract((yyvsp[-2].tmp_id), i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 2055 "./parser/Parser.cpp"
    break;

  case 65:
#line 342 "./parser/Parser.y"
                                                                          {
                                    string tmp = Multiply((yyvsp[-3].tmp_id), (yyvsp[-1].tmp_id), i);
                                    if(tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 2067 "./parser/Parser.cpp"
    break;

  case 66:
#line 349 "./parser/Parser.y"
                                                                 {
                                    string tmp = Multiply((yyvsp[-2].tmp_id), i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 2079 "./parser/Parser.cpp"
    break;

  case 67:
#line 356 "./parser/Parser.y"
                                                                                       {
                                    string tmp = Divide((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id), i);
                                    if(tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 2091 "./parser/Parser.cpp"
    break;

  case 68:
#line 363 "./parser/Parser.y"
                                                                 {
                                    string tmp = Divide((yyvsp[-2].tmp_id), i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 2103 "./parser/Parser.cpp"
    break;

  case 69:
#line 370 "./parser/Parser.y"
                                                                                           {
                                    auto res = Pow((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id), i);
                                    if (res.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = res;
                                }
#line 2115 "./parser/Parser.cpp"
    break;

  case 70:
#line 382 "./parser/Parser.y"
                                                                            {
                                    string tmp = Less((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id), i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 2127 "./parser/Parser.cpp"
    break;

  case 71:
#line 389 "./parser/Parser.y"
                                                                                 {
                                    string tmp = Greater((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id), i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 2139 "./parser/Parser.cpp"
    break;

  case 72:
#line 396 "./parser/Parser.y"
                                                                                   {
                                    string tmp = LessEqual((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id), i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 2151 "./parser/Parser.cpp"
    break;

  case 73:
#line 403 "./parser/Parser.y"
                                                                                       {
                                    string tmp = GreaterEqual((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id), i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 2163 "./parser/Parser.cpp"
    break;

  case 74:
#line 410 "./parser/Parser.y"
                                                                              {
                                    string tmp = Equal((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id), i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 2175 "./parser/Parser.cpp"
    break;

  case 75:
#line 417 "./parser/Parser.y"
                                                                                   {
                                    string tmp = NotEqual((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id), i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 2187 "./parser/Parser.cpp"
    break;

  case 76:
#line 428 "./parser/Parser.y"
                                                                          {
                                    string tmp = And((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id), i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 2199 "./parser/Parser.cpp"
    break;

  case 77:
#line 435 "./parser/Parser.y"
                                                                 {
                                    string tmp = Not((yyvsp[-2].tmp_id), i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 2211 "./parser/Parser.cpp"
    break;

  case 78:
#line 442 "./parser/Parser.y"
                                                                            {
                                    string tmp = Or((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id), i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 2223 "./parser/Parser.cpp"
    break;

  case 79:
#line 452 "./parser/Parser.y"
                                     {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2231 "./parser/Parser.cpp"
    break;

  case 80:
#line 455 "./parser/Parser.y"
                                            {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2239 "./parser/Parser.cpp"
    break;

  case 81:
#line 458 "./parser/Parser.y"
                                                                                           {
                                    string tmp = Cast((yyval.tmp_id), (yyvsp[-4].tmp_id), (yyvsp[-2].types), i);
                                    if (tmp.empty()) {
                                        cout << "Error: couldn't cast\n";
                                        return 1;
                                    }
                                }
#line 2251 "./parser/Parser.cpp"
    break;

  case 82:
#line 465 "./parser/Parser.y"
                                               {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2259 "./parser/Parser.cpp"
    break;

  case 83:
#line 468 "./parser/Parser.y"
                                           {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2267 "./parser/Parser.cpp"
    break;

  case 84:
#line 471 "./parser/Parser.y"
                                                                               {
                                    string list_id = PutInContainer((yyvsp[-5].id), (yyvsp[-1].tmp_id), i);
                                    if (list_id.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = list_id;
                                }
#line 2279 "./parser/Parser.cpp"
    break;

  case 85:
#line 478 "./parser/Parser.y"
                                                                                          {
                                    string id = PutInMap((yyvsp[-7].id), (yyvsp[-3].tmp_id), (yyvsp[-1].tmp_id), i);
                                    if (id.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = id;
                                }
#line 2291 "./parser/Parser.cpp"
    break;

  case 86:
#line 485 "./parser/Parser.y"
                                                               {
                                    string list_id = GetFromContainer((yyvsp[-3].id), (yyvsp[-1].tmp_id), i);
                                    if (list_id.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = list_id;
                                }
#line 2303 "./parser/Parser.cpp"
    break;

  case 87:
#line 492 "./parser/Parser.y"
                                                                                                          {
                                    string list_id = SetInContainer((yyvsp[-9].id), (yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id), i);
                                    if (list_id.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = list_id;
                                }
#line 2315 "./parser/Parser.cpp"
    break;

  case 95:
#line 508 "./parser/Parser.y"
                                       { 
                                    return 0 ;
                                }
#line 2323 "./parser/Parser.cpp"
    break;

  case 97:
#line 512 "./parser/Parser.y"
                                        { GarbageCollect(i); return 1; }
#line 2329 "./parser/Parser.cpp"
    break;

  case 98:
#line 514 "./parser/Parser.y"
                                     { GarbageCollect(i); }
#line 2335 "./parser/Parser.cpp"
    break;

  case 99:
#line 514 "./parser/Parser.y"
                                                                        { GarbageCollect(i); }
#line 2341 "./parser/Parser.cpp"
    break;


#line 2345 "./parser/Parser.cpp"

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
#line 515 "./parser/Parser.y"



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
