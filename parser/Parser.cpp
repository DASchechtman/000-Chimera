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

void PrintLineNo();
void yyerror(const char* err);
extern int yylex();
extern FILE *yyin;
extern void yyrestart(FILE* input);
extern char* yytext;

#line 92 "./parser/Parser.cpp"

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
    FLOAT_VAL = 301,
    MULTI_WS = 302,
    SINGLE_WS = 303,
    ID = 304,
    UNKNOWN = 305
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
#define YYFINAL  65
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   518

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  278

#define YYUNDEFTOK  2
#define YYMAXUTOK   305


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
      60,    61,     2,     2,     2,     2,    62,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    52,     2,
      54,    53,    55,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    56,     2,    57,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,    51,    59,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    57,    57,    61,    65,    65,    67,    71,    78,    80,
      80,    82,    90,    98,   106,   118,   126,   134,   143,   144,
     145,   146,   147,   148,   152,   157,   163,   163,   165,   165,
     167,   172,   178,   184,   189,   194,   199,   204,   209,   217,
     223,   229,   238,   250,   251,   251,   252,   252,   254,   255,
     266,   271,   278,   285,   292,   299,   306,   313,   320,   327,
     339,   346,   353,   360,   367,   374,   385,   392,   399,   409,
     412,   415,   422,   425,   428,   435,   442,   449,   458,   459,
     460,   461,   462,   463,   464,   465,   468,   469,   471,   471
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
  "BOOL_VAL", "FLOAT_VAL", "MULTI_WS", "SINGLE_WS", "ID", "UNKNOWN", "'|'",
  "':'", "'='", "'<'", "'>'", "'['", "']'", "'{'", "'}'", "'('", "')'",
  "'.'", "$accept", "do", "end", "firstScopeStmt", "newScope", "ifMod",
  "if", "newline", "term", "types", "unionTypes", "any_ws", "opt_ws",
  "assign", "exprList", "opt_newline", "opt_ws_or_nl", "ws_or_nl",
  "statement", "math_expr", "compare_expr", "boolExpr", "expr", "prog",
  "line", YY_NULLPTR
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
     305,   124,    58,    61,    60,    62,    91,    93,   123,   125,
      40,    41,    46
};
# endif

#define YYPACT_NINF (-177)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-30)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     379,  -177,    -8,   -38,  -177,  -177,  -177,  -177,    -8,  -177,
    -177,  -177,  -177,  -177,  -177,  -177,  -177,   268,   250,   -16,
    -177,     0,  -177,  -177,  -177,  -177,  -177,    83,  -177,  -177,
    -177,    91,  -177,     4,  -177,    -9,    -8,   258,    -8,   258,
      85,    10,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,  -177,   379,  -177,
    -177,  -177,  -177,  -177,  -177,  -177,  -177,    -8,    30,   -18,
      -8,    51,    26,    35,    39,    42,    -8,    -8,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   109,    53,    -8,  -177,  -177,  -177,  -177,  -177,
    -177,  -177,  -177,    46,    58,    -8,   -36,    -8,  -177,    -8,
     258,    -8,   258,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,  -177,  -177,
      -8,  -177,   258,   103,  -177,    78,    65,    65,    77,   110,
     -43,   -30,    31,    -8,   258,    81,   121,   103,  -177,    65,
     258,   258,   258,   258,   258,   258,   258,   258,    76,   -31,
      80,   -31,    82,   -31,    84,   -31,    88,   258,   258,  -177,
      -8,  -177,    87,    -8,    -8,   104,    -8,    -8,    -8,    -8,
    -177,   115,   258,    -8,   113,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,  -177,    -8,  -177,   -28,  -177,    19,
    -177,    -8,  -177,    -8,  -177,   258,    -8,   124,   258,    -8,
      65,   258,    65,   258,    -8,   122,   258,   106,   156,   131,
     133,   135,   137,   139,   142,   144,   145,   147,     1,  -177,
    -177,   148,   149,  -177,   129,    -8,  -177,   158,  -177,  -177,
    -177,  -177,   258,  -177,    -8,  -177,    -8,  -177,  -177,  -177,
    -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,    -8,
      65,    -8,   151,  -177,   194,   159,   258,  -177,   160,  -177,
      -8,  -177,  -177,   162,    -8,   155,   157,  -177
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    87,    29,     0,     9,    10,    85,     2,     0,    11,
      12,    14,    15,    16,    13,    26,    27,    17,     0,     0,
      82,     0,    84,    83,    69,    86,    48,     0,    70,    72,
      73,     0,    88,     0,    28,     0,    29,     0,    29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     4,     0,     5,
       8,    81,    80,    79,    78,     1,    89,    29,     0,    17,
       0,     0,     0,     0,     0,     0,    29,    29,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    29,    50,     7,    18,    19,    20,
      21,    22,    23,     0,     0,    29,    29,    29,    76,    29,
       0,    29,     0,    29,     0,     0,     0,     0,     0,     0,
       0,     0,    29,    29,    29,    29,    29,     0,     3,     6,
      29,    39,    28,    44,    45,     0,     0,     0,     0,     0,
       0,     0,    29,     0,     0,    33,    46,     0,    47,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    29,
       0,    29,     0,    29,     0,    29,     0,     0,     0,    41,
      29,    49,     0,    29,    29,     0,    29,    29,    29,    29,
      74,     0,     0,     0,     0,    29,    29,    29,    29,    29,
      29,    29,    29,    29,    67,    29,    52,    29,    54,    29,
      56,    29,    58,    29,    40,    43,    29,     0,     0,    29,
       0,     0,     0,     0,    29,     0,     0,     0,    44,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
      55,     0,     0,    42,     0,    29,    31,     0,    24,    30,
      25,    32,     0,    75,    29,    38,    29,    71,    60,    61,
      62,    63,    64,    65,    66,    68,    51,    57,    59,    29,
       0,    29,     0,    43,     0,     0,     0,    77,     0,    37,
      29,    34,    35,     0,    29,     0,     0,    36
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -177,  -177,  -177,  -177,   197,  -177,  -177,    57,  -177,  -135,
    -177,   317,    -2,  -177,   -74,   128,  -176,  -177,  -177,  -177,
    -177,  -177,   141,   -27,   187
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    19,   129,    58,    20,    21,    22,    23,    24,   106,
     107,    34,    93,    26,    94,   134,   135,   149,    27,    28,
      29,    30,    31,    32,    33
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      35,   172,   173,   113,    65,     1,    66,    57,   176,   219,
     177,    15,    16,    36,   185,    41,    15,    16,   139,    15,
      16,   178,     2,   179,   214,   231,     3,     4,     5,     6,
     -28,    15,    16,   229,    68,   142,    71,     7,    39,    15,
      16,     7,    67,     8,    40,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    97,    98,    99,   100,   101,   102,
     103,   104,   256,    76,    18,    66,    15,    16,    97,    98,
      99,   100,   101,   102,   112,   238,   130,   240,    15,    16,
     230,    95,   180,   108,    62,   195,   109,   197,    64,   199,
     110,   201,   133,   111,     9,    10,    11,    12,    13,    14,
     136,   105,    69,   138,   140,   141,     4,     5,    61,   144,
       1,   147,   137,    18,     4,     5,    63,    73,    74,    75,
     158,   160,   162,   164,   166,   265,   170,     2,   168,   171,
     174,     3,     4,     5,     6,   184,   175,   194,   214,   217,
     181,   196,   206,   198,   -28,   200,     7,   128,     8,   202,
       9,    10,    11,    12,    13,    14,    15,    16,    17,   209,
     235,   245,     9,    10,    11,    12,    13,    14,   205,    18,
      69,   207,   208,   243,   210,   211,   212,   213,    70,   246,
      72,    18,   259,   218,   220,   221,   222,   223,   224,   225,
     226,   227,   247,   228,   248,   181,   249,   181,   250,   133,
     251,   232,   267,   252,   234,   253,   254,   237,   255,   257,
     258,   261,   242,   276,   270,   274,   277,   272,    60,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   260,   131,     9,    10,    11,    12,    13,
      14,   148,   262,    69,   263,    92,     0,     0,     0,     0,
     268,   143,     0,   145,    18,     0,     0,   264,     0,   266,
       0,    42,    43,    44,    45,    46,    47,    48,   273,    49,
      50,    51,   275,   169,     0,     0,     0,    52,    53,    54,
      55,    56,     0,     0,     0,   183,     0,   169,     0,     0,
       0,   186,   187,   188,   189,   190,   191,   192,   193,     9,
      10,    11,    12,    13,    14,     0,     0,    69,   203,   204,
       0,     0,     0,     0,     0,    15,    16,    25,    18,     0,
      38,   -29,     0,   215,    39,    37,     0,     0,     0,     0,
      40,     0,     0,     0,     0,     0,    59,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   233,     0,     0,   236,
      25,     0,   239,     0,   241,     0,     0,   244,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,     0,    25,     0,     0,     0,     0,
       1,     0,     0,   233,     0,     0,     0,    96,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     2,     0,     0,
       0,     3,     4,     5,     6,   269,     0,   271,     0,    25,
       0,   132,     0,     0,     0,     0,     7,     0,     8,     0,
       9,    10,    11,    12,    13,    14,    15,    16,    17,     0,
     146,   150,   151,   152,   153,   154,   155,   156,   157,    18,
     159,   161,   163,   165,   167,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   132,
     182,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     216,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   132,     0,   132,     0,   132,     0,   132
};

static const yytype_int16 yycheck[] =
{
       2,   136,   137,    77,     0,     1,    33,    23,    51,   185,
      53,    47,    48,    51,   149,    17,    47,    48,    54,    47,
      48,    51,    18,    53,    23,   201,    22,    23,    24,    25,
      61,    47,    48,    61,    36,   109,    38,    37,    56,    47,
      48,    37,    51,    39,    62,    41,    42,    43,    44,    45,
      46,    47,    48,    49,     3,     4,     5,     6,     7,     8,
       9,    10,    61,    53,    60,    92,    47,    48,     3,     4,
       5,     6,     7,     8,    76,   210,    23,   212,    47,    48,
      61,    51,    51,    57,    27,   159,    51,   161,    31,   163,
      51,   165,    94,    51,    41,    42,    43,    44,    45,    46,
      54,    50,    49,   105,   106,   107,    23,    24,    25,   111,
       1,   113,    54,    60,    23,    24,    25,    32,    33,    34,
     122,   123,   124,   125,   126,   260,    23,    18,   130,    51,
      53,    22,    23,    24,    25,    54,    26,    61,    23,    26,
     142,    61,    55,    61,    23,    61,    37,    38,    39,    61,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    55,
      36,    55,    41,    42,    43,    44,    45,    46,   170,    60,
      49,   173,   174,    51,   176,   177,   178,   179,    37,    23,
      39,    60,    53,   185,   186,   187,   188,   189,   190,   191,
     192,   193,    61,   195,    61,   197,    61,   199,    61,   201,
      61,   203,    51,    61,   206,    61,    61,   209,    61,    61,
      61,    53,   214,    58,    55,    53,    59,    57,    21,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,   235,    93,    41,    42,    43,    44,    45,
      46,   113,   244,    49,   246,    58,    -1,    -1,    -1,    -1,
      56,   110,    -1,   112,    60,    -1,    -1,   259,    -1,   261,
      -1,    11,    12,    13,    14,    15,    16,    17,   270,    19,
      20,    21,   274,   132,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    -1,    -1,    -1,   144,    -1,   146,    -1,    -1,
      -1,   150,   151,   152,   153,   154,   155,   156,   157,    41,
      42,    43,    44,    45,    46,    -1,    -1,    49,   167,   168,
      -1,    -1,    -1,    -1,    -1,    47,    48,     0,    60,    -1,
      52,    53,    -1,   182,    56,     8,    -1,    -1,    -1,    -1,
      62,    -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   205,    -1,    -1,   208,
      33,    -1,   211,    -1,   213,    -1,    -1,   216,    -1,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    58,    -1,    -1,    -1,    -1,
       1,    -1,    -1,   242,    -1,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    -1,    -1,
      -1,    22,    23,    24,    25,   264,    -1,   266,    -1,    92,
      -1,    94,    -1,    -1,    -1,    -1,    37,    -1,    39,    -1,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    -1,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    60,
     123,   124,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,
     143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     183,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   195,    -1,   197,    -1,   199,    -1,   201
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    18,    22,    23,    24,    25,    37,    39,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    60,    64,
      67,    68,    69,    70,    71,    74,    76,    81,    82,    83,
      84,    85,    86,    87,    74,    75,    51,    74,    52,    56,
      62,    75,    11,    12,    13,    14,    15,    16,    17,    19,
      20,    21,    27,    28,    29,    30,    31,    23,    66,    74,
      67,    25,    70,    25,    70,     0,    86,    51,    75,    49,
      85,    75,    85,    32,    33,    34,    53,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    87,    75,    77,    51,    74,     3,     4,     5,
       6,     7,     8,     9,    10,    50,    72,    73,    57,    51,
      51,    51,    75,    77,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    38,    65,
      23,    85,    74,    75,    78,    79,    54,    54,    75,    54,
      75,    75,    77,    85,    75,    85,    74,    75,    78,    80,
      74,    74,    74,    74,    74,    74,    74,    74,    75,    74,
      75,    74,    75,    74,    75,    74,    75,    74,    75,    85,
      23,    51,    72,    72,    53,    26,    51,    53,    51,    53,
      51,    75,    74,    85,    54,    72,    85,    85,    85,    85,
      85,    85,    85,    85,    61,    77,    61,    77,    61,    77,
      61,    77,    61,    85,    85,    75,    55,    75,    75,    55,
      75,    75,    75,    75,    23,    85,    74,    26,    75,    79,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    61,
      61,    79,    75,    85,    75,    36,    85,    75,    72,    85,
      72,    85,    75,    51,    85,    55,    23,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    53,
      75,    53,    75,    75,    75,    72,    75,    51,    56,    85,
      55,    85,    57,    75,    53,    75,    58,    59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    63,    64,    65,    66,    66,    67,    68,    69,    70,
      70,    71,    71,    71,    71,    71,    71,    71,    72,    72,
      72,    72,    72,    72,    73,    73,    74,    74,    75,    75,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    77,
      77,    77,    77,    78,    79,    79,    80,    80,    81,    81,
      81,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      83,    83,    83,    83,    83,    83,    84,    84,    84,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    87,    87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     4,     4,     2,     1,
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
#line 57 "./parser/Parser.y"
                                   {
                                    CreateScope(i);
                                }
#line 1582 "./parser/Parser.cpp"
    break;

  case 3:
#line 61 "./parser/Parser.y"
                                    {
                                    DestroyScope(i);
                                }
#line 1590 "./parser/Parser.cpp"
    break;

  case 7:
#line 71 "./parser/Parser.y"
                                                      {
                                    if (SetNextScopeRunState((yyvsp[-1].tmp_id), i) == 1) {
                                        return 1;
                                    }
                                }
#line 1600 "./parser/Parser.cpp"
    break;

  case 11:
#line 82 "./parser/Parser.y"
                                                { 
                                                    string tmp_name = CreateTempVar((yyvsp[0].int_val), i);
                                                    if (tmp_name.empty()) {
                                                        cout << "Error: couldn't create temp var\n";
                                                        return 1;
                                                    }
                                                    (yyval.tmp_id) = tmp_name;
                                                }
#line 1613 "./parser/Parser.cpp"
    break;

  case 12:
#line 90 "./parser/Parser.y"
                                                { 
                                                    string tmp_name = CreateTempVar((yyvsp[0].dou_val), i);
                                                    if (tmp_name.empty()) {
                                                        cout << "Error: couldn't create temp var\n";
                                                        return 1;
                                                    }
                                                    (yyval.tmp_id) = tmp_name;
                                                }
#line 1626 "./parser/Parser.cpp"
    break;

  case 13:
#line 98 "./parser/Parser.y"
                                                { 
                                                    string tmp_name = CreateTempVar((yyvsp[0].flo_val), i);
                                                    if (tmp_name.empty()) {
                                                        cout << "Error: couldn't create temp var\n";
                                                        return 1;
                                                    }
                                                    (yyval.tmp_id) = tmp_name;
                                                }
#line 1639 "./parser/Parser.cpp"
    break;

  case 14:
#line 106 "./parser/Parser.y"
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
#line 1656 "./parser/Parser.cpp"
    break;

  case 15:
#line 118 "./parser/Parser.y"
                                                { 
                                                    string tmp_name = CreateTempVar((yyvsp[0].char_val), i);
                                                    if (tmp_name.empty()) {
                                                        cout << "Error: couldn't create temp var\n";
                                                        return 1;
                                                    }
                                                    (yyval.tmp_id) = tmp_name;
                                                }
#line 1669 "./parser/Parser.cpp"
    break;

  case 16:
#line 126 "./parser/Parser.y"
                                                { 
                                                    string tmp_name = CreateTempVar((yyvsp[0].bol_val), i);
                                                    if (tmp_name.empty()) {
                                                        cout << "Error: couldn't create temp var\n";
                                                        return 1;
                                                    }
                                                    (yyval.tmp_id) = tmp_name;
                                                }
#line 1682 "./parser/Parser.cpp"
    break;

  case 17:
#line 134 "./parser/Parser.y"
                                                { 
                                                    string tmp = CloneToTemp((yyvsp[0].id), i);
                                                    if (tmp.empty()) {
                                                        return 1;
                                                    }
                                                    (yyval.tmp_id) = tmp;
                                                }
#line 1694 "./parser/Parser.cpp"
    break;

  case 18:
#line 143 "./parser/Parser.y"
                                                { (yyval.types) = (yyvsp[0].types); }
#line 1700 "./parser/Parser.cpp"
    break;

  case 19:
#line 144 "./parser/Parser.y"
                                                { (yyval.types) = (yyvsp[0].types); }
#line 1706 "./parser/Parser.cpp"
    break;

  case 20:
#line 145 "./parser/Parser.y"
                                                { (yyval.types) = (yyvsp[0].types); }
#line 1712 "./parser/Parser.cpp"
    break;

  case 21:
#line 146 "./parser/Parser.y"
                                                { (yyval.types) = (yyvsp[0].types); }
#line 1718 "./parser/Parser.cpp"
    break;

  case 22:
#line 147 "./parser/Parser.y"
                                                { (yyval.types) = (yyvsp[0].types); }
#line 1724 "./parser/Parser.cpp"
    break;

  case 23:
#line 148 "./parser/Parser.y"
                                                { (yyval.types) = (yyvsp[0].types); }
#line 1730 "./parser/Parser.cpp"
    break;

  case 24:
#line 152 "./parser/Parser.y"
                                                             {
                                    (yyvsp[-4].types).AddPending((yyvsp[-4].types));
                                    (yyvsp[-4].types).AddPending((yyvsp[0].types));
                                    (yyval.tmp_id) = (yyvsp[-4].types);
                                }
#line 1740 "./parser/Parser.cpp"
    break;

  case 25:
#line 157 "./parser/Parser.y"
                                                                     {
                                    (yyvsp[-4].tmp_id).AddPending((yyvsp[0].types));
                                    (yyval.tmp_id) = (yyvsp[-4].tmp_id);
                                }
#line 1749 "./parser/Parser.cpp"
    break;

  case 30:
#line 167 "./parser/Parser.y"
                                                                           {
                                    if (Assign((yyvsp[-7].id), (yyvsp[0].tmp_id), (yyvsp[-4].types), i).empty()) {
                                        return 1;
                                    }
                                }
#line 1759 "./parser/Parser.cpp"
    break;

  case 31:
#line 172 "./parser/Parser.y"
                                                                               {
                                    bool made_union = !MakeUnknown((yyvsp[-7].id), (yyvsp[0].tmp_id), i).empty();
                                    if(!made_union) {
                                        return 1;
                                    }
                                }
#line 1770 "./parser/Parser.cpp"
    break;

  case 32:
#line 178 "./parser/Parser.y"
                                                                                  {
                                    auto union_name = MakeUnion((yyvsp[-7].id), (yyvsp[-4].tmp_id), (yyvsp[0].tmp_id), i);
                                    if (union_name.empty()) {
                                        return 1;
                                    }
                                }
#line 1781 "./parser/Parser.cpp"
    break;

  case 33:
#line 184 "./parser/Parser.y"
                                                            {
                                    if(Reassign((yyvsp[-4].id), (yyvsp[0].tmp_id), i).empty()) {
                                        return 1;
                                    }
                                }
#line 1791 "./parser/Parser.cpp"
    break;

  case 34:
#line 189 "./parser/Parser.y"
                                                                                         {
                                    if (RefBind((yyvsp[-10].id), (yyvsp[0].tmp_id), (yyvsp[-7].types), i).empty()) {
                                        return 1;
                                    }
                                }
#line 1801 "./parser/Parser.cpp"
    break;

  case 35:
#line 194 "./parser/Parser.y"
                                                                                             {
                                    if(MakeList((yyvsp[-11].id), (yyvsp[-6].types), i).empty()) {
                                        return 1;
                                    }
                                }
#line 1811 "./parser/Parser.cpp"
    break;

  case 36:
#line 199 "./parser/Parser.y"
                                                                                                                                    {
                                    if (MakeMap((yyvsp[-15].id), (yyvsp[-10].types), (yyvsp[-6].types), i).empty()) {
                                        return 1;
                                    }
                                }
#line 1821 "./parser/Parser.cpp"
    break;

  case 37:
#line 204 "./parser/Parser.y"
                                                                                          {
                                    if(ReassignContainer((yyvsp[-10].id), (yyvsp[-5].types), (yyvsp[0].tmp_id), i).empty()) {
                                        return 1;
                                    }
                                }
#line 1831 "./parser/Parser.cpp"
    break;

  case 38:
#line 209 "./parser/Parser.y"
                                                                        {
                                    if (RefBind((yyvsp[-7].id), (yyvsp[-3].tmp_id), i).empty()) {
                                        return 1;
                                    }
                                }
#line 1841 "./parser/Parser.cpp"
    break;

  case 39:
#line 217 "./parser/Parser.y"
                                           {
                                    if(!(yyvsp[0].tmp_id).GetFinalResult().empty()) { 
                                        (yyvsp[0].tmp_id).AddPending((yyvsp[0].tmp_id)); 
                                    }
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id); 
                                }
#line 1852 "./parser/Parser.cpp"
    break;

  case 40:
#line 223 "./parser/Parser.y"
                                                             {
                                    if(!(yyvsp[0].tmp_id).GetFinalResult().empty()) {
                                        (yyvsp[0].tmp_id).AddPending((yyvsp[0].tmp_id));
                                    }
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 1863 "./parser/Parser.cpp"
    break;

  case 41:
#line 229 "./parser/Parser.y"
                                                             {  
                                    if(!(yyvsp[-2].tmp_id).GetFinalResult().empty()) { 
                                        (yyvsp[-2].tmp_id).AddPending((yyvsp[0].tmp_id)); 
                                    }
                                    for(unsigned int i = 0; i < (yyvsp[0].tmp_id).PendingDataSize(); i++) {
                                        (yyvsp[-2].tmp_id).AddPending((yyvsp[0].tmp_id)[i]);
                                    }
                                    (yyval.tmp_id) = (yyvsp[-2].tmp_id);
                                }
#line 1877 "./parser/Parser.cpp"
    break;

  case 42:
#line 238 "./parser/Parser.y"
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
#line 1892 "./parser/Parser.cpp"
    break;

  case 49:
#line 255 "./parser/Parser.y"
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
#line 1908 "./parser/Parser.cpp"
    break;

  case 50:
#line 266 "./parser/Parser.y"
                                                     { return 0; }
#line 1914 "./parser/Parser.cpp"
    break;

  case 51:
#line 271 "./parser/Parser.y"
                                                                                           {
                                    string tmp = Add((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id), i);
                                    if(tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 1926 "./parser/Parser.cpp"
    break;

  case 52:
#line 278 "./parser/Parser.y"
                                                                 {
                                    string tmp = Add((yyvsp[-2].tmp_id), i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 1938 "./parser/Parser.cpp"
    break;

  case 53:
#line 285 "./parser/Parser.y"
                                                                          {
                                    string tmp = Subtract((yyvsp[-3].tmp_id), (yyvsp[-1].tmp_id), i);
                                    if(tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 1950 "./parser/Parser.cpp"
    break;

  case 54:
#line 292 "./parser/Parser.y"
                                                                 {
                                    string tmp = Subtract((yyvsp[-2].tmp_id), i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 1962 "./parser/Parser.cpp"
    break;

  case 55:
#line 299 "./parser/Parser.y"
                                                                          {
                                    string tmp = Multiply((yyvsp[-3].tmp_id), (yyvsp[-1].tmp_id), i);
                                    if(tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 1974 "./parser/Parser.cpp"
    break;

  case 56:
#line 306 "./parser/Parser.y"
                                                                 {
                                    string tmp = Multiply((yyvsp[-2].tmp_id), i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 1986 "./parser/Parser.cpp"
    break;

  case 57:
#line 313 "./parser/Parser.y"
                                                                                       {
                                    string tmp = Divide((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id), i);
                                    if(tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 1998 "./parser/Parser.cpp"
    break;

  case 58:
#line 320 "./parser/Parser.y"
                                                                 {
                                    string tmp = Divide((yyvsp[-2].tmp_id), i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 2010 "./parser/Parser.cpp"
    break;

  case 59:
#line 327 "./parser/Parser.y"
                                                                                           {
                                    auto res = Pow((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id), i);
                                    if (res.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = res;
                                }
#line 2022 "./parser/Parser.cpp"
    break;

  case 60:
#line 339 "./parser/Parser.y"
                                                                            {
                                    string tmp = Less((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id), i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 2034 "./parser/Parser.cpp"
    break;

  case 61:
#line 346 "./parser/Parser.y"
                                                                                 {
                                    string tmp = Greater((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id), i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 2046 "./parser/Parser.cpp"
    break;

  case 62:
#line 353 "./parser/Parser.y"
                                                                                   {
                                    string tmp = LessEqual((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id), i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 2058 "./parser/Parser.cpp"
    break;

  case 63:
#line 360 "./parser/Parser.y"
                                                                                       {
                                    string tmp = GreaterEqual((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id), i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 2070 "./parser/Parser.cpp"
    break;

  case 64:
#line 367 "./parser/Parser.y"
                                                                              {
                                    string tmp = Equal((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id), i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 2082 "./parser/Parser.cpp"
    break;

  case 65:
#line 374 "./parser/Parser.y"
                                                                                   {
                                    string tmp = NotEqual((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id), i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 2094 "./parser/Parser.cpp"
    break;

  case 66:
#line 385 "./parser/Parser.y"
                                                                          {
                                    string tmp = And((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id), i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 2106 "./parser/Parser.cpp"
    break;

  case 67:
#line 392 "./parser/Parser.y"
                                                                 {
                                    string tmp = Not((yyvsp[-2].tmp_id), i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 2118 "./parser/Parser.cpp"
    break;

  case 68:
#line 399 "./parser/Parser.y"
                                                                            {
                                    string tmp = Or((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id), i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 2130 "./parser/Parser.cpp"
    break;

  case 69:
#line 409 "./parser/Parser.y"
                                     {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2138 "./parser/Parser.cpp"
    break;

  case 70:
#line 412 "./parser/Parser.y"
                                            {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2146 "./parser/Parser.cpp"
    break;

  case 71:
#line 415 "./parser/Parser.y"
                                                                                           {
                                    string tmp = Cast((yyval.tmp_id), (yyvsp[-4].tmp_id), (yyvsp[-2].types), i);
                                    if (tmp.empty()) {
                                        cout << "Error: couldn't cast\n";
                                        return 1;
                                    }
                                }
#line 2158 "./parser/Parser.cpp"
    break;

  case 72:
#line 422 "./parser/Parser.y"
                                               {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2166 "./parser/Parser.cpp"
    break;

  case 73:
#line 425 "./parser/Parser.y"
                                           {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2174 "./parser/Parser.cpp"
    break;

  case 74:
#line 428 "./parser/Parser.y"
                                                                               {
                                    string list_id = PutInContainer((yyvsp[-5].id), (yyvsp[-1].tmp_id), i);
                                    if (list_id.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = list_id;
                                }
#line 2186 "./parser/Parser.cpp"
    break;

  case 75:
#line 435 "./parser/Parser.y"
                                                                                          {
                                    string id = PutInMap((yyvsp[-7].id), (yyvsp[-3].tmp_id), (yyvsp[-1].tmp_id), i);
                                    if (id.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = id;
                                }
#line 2198 "./parser/Parser.cpp"
    break;

  case 76:
#line 442 "./parser/Parser.y"
                                                               {
                                    string list_id = GetFromContainer((yyvsp[-3].id), (yyvsp[-1].tmp_id), i);
                                    if (list_id.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = list_id;
                                }
#line 2210 "./parser/Parser.cpp"
    break;

  case 77:
#line 449 "./parser/Parser.y"
                                                                                                          {
                                    string list_id = SetInContainer((yyvsp[-9].id), (yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id), i);
                                    if (list_id.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = list_id;
                                }
#line 2222 "./parser/Parser.cpp"
    break;

  case 85:
#line 465 "./parser/Parser.y"
                                       { 
                                    return 0 ;
                                }
#line 2230 "./parser/Parser.cpp"
    break;

  case 87:
#line 469 "./parser/Parser.y"
                                        { GarbageCollect(i); return 1; }
#line 2236 "./parser/Parser.cpp"
    break;

  case 88:
#line 471 "./parser/Parser.y"
                                     { GarbageCollect(i); }
#line 2242 "./parser/Parser.cpp"
    break;

  case 89:
#line 471 "./parser/Parser.y"
                                                                        { GarbageCollect(i); }
#line 2248 "./parser/Parser.cpp"
    break;


#line 2252 "./parser/Parser.cpp"

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
#line 472 "./parser/Parser.y"



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
