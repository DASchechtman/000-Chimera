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
    CAST = 264,
    LESS = 265,
    GREATER = 266,
    LESS_EQUAL = 267,
    GREATER_EQUAL = 268,
    EQUAL = 269,
    NOT_EQUAL = 270,
    PRINT = 271,
    AND = 272,
    OR = 273,
    NOT = 274,
    EXIT = 275,
    NEWLINE = 276,
    SEMICOLON = 277,
    EOPU = 278,
    REF = 279,
    ADD = 280,
    SUB = 281,
    MUL = 282,
    DIV = 283,
    POW = 284,
    INT_VAL = 285,
    DOUBLE_VAL = 286,
    STRING_VAL = 287,
    CHAR_VAL = 288,
    BOOL_VAL = 289,
    FLOAT_VAL = 290,
    MULTI_WS = 291,
    SINGLE_WS = 292,
    ID = 293,
    UNKNOWN = 294
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  52
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   361

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  214

#define YYUNDEFTOK  2
#define YYMAXUTOK   294


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
      45,    46,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    41,     2,
      43,    42,    44,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    40,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    56,    56,    56,    58,    66,    74,    82,    94,   102,
     110,   119,   120,   121,   122,   123,   124,   128,   133,   139,
     139,   141,   141,   143,   148,   154,   160,   165,   173,   179,
     185,   194,   206,   207,   207,   208,   208,   210,   211,   222,
     227,   234,   241,   248,   255,   262,   269,   276,   283,   305,
     312,   319,   326,   333,   340,   351,   358,   365,   375,   378,
     381,   388,   391,   396,   397,   398,   399,   400,   401,   404,
     405,   407,   407
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "DOUBLE", "BOOL", "CHAR",
  "STRING", "CAST", "LESS", "GREATER", "LESS_EQUAL", "GREATER_EQUAL",
  "EQUAL", "NOT_EQUAL", "PRINT", "AND", "OR", "NOT", "EXIT", "NEWLINE",
  "SEMICOLON", "EOPU", "REF", "ADD", "SUB", "MUL", "DIV", "POW", "INT_VAL",
  "DOUBLE_VAL", "STRING_VAL", "CHAR_VAL", "BOOL_VAL", "FLOAT_VAL",
  "MULTI_WS", "SINGLE_WS", "ID", "UNKNOWN", "'|'", "':'", "'='", "'<'",
  "'>'", "'('", "')'", "$accept", "newline", "term", "types", "unionTypes",
  "any_ws", "opt_ws", "assign", "exprList", "opt_newline", "opt_ws_or_nl",
  "ws_or_nl", "statement", "math_expr", "compare_expr", "boolExpr", "expr",
  "prog", "line", YY_NULLPTR
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
     124,    58,    61,    60,    62,    40,    41
};
# endif

#define YYPACT_NINF (-141)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-23)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      29,  -141,    73,   -26,  -141,  -141,  -141,  -141,  -141,  -141,
    -141,  -141,  -141,  -141,  -141,    51,   276,  -141,  -141,  -141,
    -141,    80,  -141,  -141,  -141,    85,  -141,     3,  -141,   -20,
      73,    73,   -10,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,  -141,  -141,
    -141,  -141,  -141,  -141,    73,     7,     4,    73,    73,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   153,    73,  -141,  -141,  -141,  -141,  -141,
    -141,  -141,    73,   -21,    73,   278,    73,  -141,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,  -141,   278,    23,  -141,    13,    15,    34,
      28,    43,  -141,   210,    23,  -141,   123,   278,   278,   278,
     278,   278,   278,   278,   278,    33,   -19,    45,   -19,    58,
     -19,    86,   -19,    87,   278,   278,  -141,    73,  -141,    73,
      90,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,  -141,    73,  -141,    40,  -141,    53,
    -141,    73,  -141,    73,  -141,   278,   278,    73,   123,   278,
     123,   278,   115,    92,   108,   110,   112,   114,   116,   117,
     134,   135,   -15,  -141,   161,  -141,   143,   144,  -141,  -141,
     150,  -141,  -141,  -141,  -141,    73,  -141,  -141,  -141,  -141,
    -141,  -141,  -141,  -141,  -141,    73,  -141,  -141,  -141,    73,
    -141,   278,   278,  -141
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    70,    22,     0,     2,     3,    68,     4,     5,     7,
       8,     9,     6,    19,    20,    10,     0,    67,    58,    69,
      37,     0,    59,    61,    62,     0,    71,     0,    21,     0,
      22,    22,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    66,    65,
      64,    63,     1,    72,    22,     0,     0,    22,    22,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    22,    39,    11,    12,    13,    14,
      15,    16,    22,    22,    22,     0,    22,    10,     0,     0,
       0,     0,     0,     0,     0,     0,    22,    22,    22,    22,
      22,     0,    22,    28,    21,    33,    34,     0,     0,     0,
       0,     0,    26,    35,     0,    36,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    22,     0,    22,     0,
      22,     0,    22,     0,     0,     0,    30,    22,    38,    22,
       0,    22,    22,    22,    22,    22,    22,    22,    22,    22,
      22,    22,    22,    22,    56,    22,    41,    22,    43,    22,
      45,    22,    47,    22,    29,    32,     0,    22,     0,     0,
       0,     0,    33,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    42,     0,    44,     0,     0,    31,    24,
       0,    17,    23,    18,    25,    22,    60,    49,    50,    51,
      52,    53,    54,    55,    57,    22,    40,    46,    48,    22,
      32,     0,     0,    27
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -141,    21,  -141,  -114,  -141,    78,    -2,  -141,   -57,   109,
    -140,  -141,  -141,  -141,  -141,  -141,   149,   167,  -141
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    17,    18,    83,    84,    28,    73,    20,    74,   106,
     107,   116,    21,    22,    23,    24,    25,    26,    27
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      29,    86,   145,    52,     1,   173,   205,    76,    77,    78,
      79,    80,    81,    32,    30,    13,    14,    13,    14,     2,
      54,   186,   109,     3,     4,     5,     6,   -21,    55,    56,
       1,   206,    57,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    49,    82,   137,     2,    51,    75,    16,     3,
       4,     5,     6,   138,   191,    85,   193,   139,   140,     7,
       8,     9,    10,    11,    12,    13,    14,    15,   141,   155,
     142,   157,   105,   159,    16,   161,    13,    14,    19,   154,
     108,   110,   111,   143,   114,   144,   183,    13,    14,    13,
      14,   156,    31,   -22,   125,   127,   129,   131,   133,   185,
     135,     4,     5,    48,   158,    19,     4,     5,    50,    13,
      14,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    76,    77,    78,    79,
      80,    81,   160,   162,   167,   165,   195,   166,   196,   168,
     169,   170,   171,   172,   174,   175,   176,   177,   178,   179,
     180,   181,   104,   182,   197,   184,   198,   184,   199,   105,
     200,   187,   201,   202,   113,   190,   117,   118,   119,   120,
     121,   122,   123,   124,   102,   126,   128,   130,   132,   134,
     203,   204,   205,     7,     8,     9,    10,    11,    12,   207,
     208,    87,   209,   210,    53,   115,     0,     0,    16,     0,
       0,     0,     0,   211,     0,     0,     0,   212,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   103,     0,     0,     0,     0,     0,     0,     0,
       0,   -21,     0,   104,   112,   104,     0,   104,     0,   104,
       7,     8,     9,    10,    11,    12,     0,     0,    87,     0,
       0,     0,     0,   136,     0,    16,     0,     0,     0,     0,
       0,     0,   136,     0,     0,     0,   146,   147,   148,   149,
     150,   151,   152,   153,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   163,   164,    33,    34,    35,    36,    37,
      38,    39,     0,    40,    41,    42,     0,     0,     0,     0,
       0,    43,    44,    45,    46,    47,     0,     0,     7,     8,
       9,    10,    11,    12,   188,   189,    87,     0,   192,     0,
     194,     0,     0,    16,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     188,   213
};

static const yytype_int16 yycheck[] =
{
       2,    58,   116,     0,     1,   145,    21,     3,     4,     5,
       6,     7,     8,    15,    40,    36,    37,    36,    37,    16,
      40,   161,    43,    20,    21,    22,    23,    46,    30,    31,
       1,    46,    42,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    21,    39,    21,    16,    25,    40,    45,    20,
      21,    22,    23,    40,   168,    57,   170,    42,    24,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    40,   126,
      42,   128,    74,   130,    45,   132,    36,    37,     0,    46,
      82,    83,    84,    40,    86,    42,    46,    36,    37,    36,
      37,    46,    41,    42,    96,    97,    98,    99,   100,    46,
     102,    21,    22,    23,    46,    27,    21,    22,    23,    36,
      37,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     3,     4,     5,     6,
       7,     8,    46,    46,    44,   137,    21,   139,    46,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,    74,   155,    46,   157,    46,   159,    46,   161,
      46,   163,    46,    46,    86,   167,    88,    89,    90,    91,
      92,    93,    94,    95,    21,    97,    98,    99,   100,   101,
      46,    46,    21,    30,    31,    32,    33,    34,    35,    46,
      46,    38,    42,   195,    27,    86,    -1,    -1,    45,    -1,
      -1,    -1,    -1,   205,    -1,    -1,    -1,   209,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    21,    -1,   155,    85,   157,    -1,   159,    -1,   161,
      30,    31,    32,    33,    34,    35,    -1,    -1,    38,    -1,
      -1,    -1,    -1,   104,    -1,    45,    -1,    -1,    -1,    -1,
      -1,    -1,   113,    -1,    -1,    -1,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   134,   135,     9,    10,    11,    12,    13,
      14,    15,    -1,    17,    18,    19,    -1,    -1,    -1,    -1,
      -1,    25,    26,    27,    28,    29,    -1,    -1,    30,    31,
      32,    33,    34,    35,   165,   166,    38,    -1,   169,    -1,
     171,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     211,   212
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    16,    20,    21,    22,    23,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    45,    48,    49,    52,
      54,    59,    60,    61,    62,    63,    64,    65,    52,    53,
      40,    41,    53,     9,    10,    11,    12,    13,    14,    15,
      17,    18,    19,    25,    26,    27,    28,    29,    23,    48,
      23,    48,     0,    64,    40,    53,    53,    42,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    53,    55,    40,     3,     4,     5,     6,
       7,     8,    39,    50,    51,    53,    55,    38,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    21,    63,    52,    53,    56,    57,    53,    43,
      53,    53,    63,    52,    53,    56,    58,    52,    52,    52,
      52,    52,    52,    52,    52,    53,    52,    53,    52,    53,
      52,    53,    52,    53,    52,    53,    63,    21,    40,    42,
      24,    40,    42,    40,    42,    50,    63,    63,    63,    63,
      63,    63,    63,    63,    46,    55,    46,    55,    46,    55,
      46,    55,    46,    63,    63,    53,    53,    44,    53,    53,
      53,    53,    53,    57,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    46,    53,    46,    57,    53,    63,    63,
      53,    50,    63,    50,    63,    21,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    21,    46,    46,    46,    42,
      53,    53,    53,    63
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    48,    49,    49,    49,    49,    49,    49,
      49,    50,    50,    50,    50,    50,    50,    51,    51,    52,
      52,    53,    53,    54,    54,    54,    54,    54,    55,    55,
      55,    55,    56,    57,    57,    58,    58,    59,    59,    59,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    61,
      61,    61,    61,    61,    61,    62,    62,    62,    63,    63,
      63,    63,    63,    64,    64,    64,    64,    64,    64,    64,
      64,    65,    65
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     5,     1,
       1,     1,     0,     8,     8,     8,     5,    11,     2,     4,
       3,     5,     3,     1,     1,     1,     1,     1,     6,     4,
       8,     6,     7,     6,     7,     6,     8,     6,     8,     8,
       8,     8,     8,     8,     8,     8,     6,     8,     1,     1,
       8,     1,     1,     2,     2,     2,     2,     1,     1,     1,
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
  case 4:
#line 58 "./parser/Parser.y"
                                                { 
                                                    string tmp_name = CreateTempVar((yyvsp[0].int_val), i);
                                                    if (tmp_name.empty()) {
                                                        cout << "Error: couldn't create temp var\n";
                                                        return 1;
                                                    }
                                                    (yyval.tmp_id) = tmp_name;
                                                }
#line 1517 "./parser/Parser.cpp"
    break;

  case 5:
#line 66 "./parser/Parser.y"
                                                { 
                                                    string tmp_name = CreateTempVar((yyvsp[0].dou_val), i);
                                                    if (tmp_name.empty()) {
                                                        cout << "Error: couldn't create temp var\n";
                                                        return 1;
                                                    }
                                                    (yyval.tmp_id) = tmp_name;
                                                }
#line 1530 "./parser/Parser.cpp"
    break;

  case 6:
#line 74 "./parser/Parser.y"
                                                { 
                                                    string tmp_name = CreateTempVar((yyvsp[0].flo_val), i);
                                                    if (tmp_name.empty()) {
                                                        cout << "Error: couldn't create temp var\n";
                                                        return 1;
                                                    }
                                                    (yyval.tmp_id) = tmp_name;
                                                }
#line 1543 "./parser/Parser.cpp"
    break;

  case 7:
#line 82 "./parser/Parser.y"
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
#line 1560 "./parser/Parser.cpp"
    break;

  case 8:
#line 94 "./parser/Parser.y"
                                                { 
                                                    string tmp_name = CreateTempVar((yyvsp[0].char_val), i);
                                                    if (tmp_name.empty()) {
                                                        cout << "Error: couldn't create temp var\n";
                                                        return 1;
                                                    }
                                                    (yyval.tmp_id) = tmp_name;
                                                }
#line 1573 "./parser/Parser.cpp"
    break;

  case 9:
#line 102 "./parser/Parser.y"
                                                { 
                                                    string tmp_name = CreateTempVar((yyvsp[0].bol_val), i);
                                                    if (tmp_name.empty()) {
                                                        cout << "Error: couldn't create temp var\n";
                                                        return 1;
                                                    }
                                                    (yyval.tmp_id) = tmp_name;
                                                }
#line 1586 "./parser/Parser.cpp"
    break;

  case 10:
#line 110 "./parser/Parser.y"
                                                { 
                                                    string tmp = CloneToTemp((yyvsp[0].id), i);
                                                    if (tmp.empty()) {
                                                        return 1;
                                                    }
                                                    (yyval.tmp_id) = tmp;
                                                }
#line 1598 "./parser/Parser.cpp"
    break;

  case 11:
#line 119 "./parser/Parser.y"
                                                { (yyval.types) = (yyvsp[0].types); }
#line 1604 "./parser/Parser.cpp"
    break;

  case 12:
#line 120 "./parser/Parser.y"
                                                { (yyval.types) = (yyvsp[0].types); }
#line 1610 "./parser/Parser.cpp"
    break;

  case 13:
#line 121 "./parser/Parser.y"
                                                { (yyval.types) = (yyvsp[0].types); }
#line 1616 "./parser/Parser.cpp"
    break;

  case 14:
#line 122 "./parser/Parser.y"
                                                { (yyval.types) = (yyvsp[0].types); }
#line 1622 "./parser/Parser.cpp"
    break;

  case 15:
#line 123 "./parser/Parser.y"
                                                { (yyval.types) = (yyvsp[0].types); }
#line 1628 "./parser/Parser.cpp"
    break;

  case 16:
#line 124 "./parser/Parser.y"
                                                { (yyval.types) = (yyvsp[0].types); }
#line 1634 "./parser/Parser.cpp"
    break;

  case 17:
#line 128 "./parser/Parser.y"
                                                             {
                                    (yyvsp[-4].types).AddPending((yyvsp[-4].types));
                                    (yyvsp[-4].types).AddPending((yyvsp[0].types));
                                    (yyval.tmp_id) = (yyvsp[-4].types);
                                }
#line 1644 "./parser/Parser.cpp"
    break;

  case 18:
#line 133 "./parser/Parser.y"
                                                                     {
                                    (yyvsp[-4].tmp_id).AddPending((yyvsp[0].types));
                                    (yyval.tmp_id) = (yyvsp[-4].tmp_id);
                                }
#line 1653 "./parser/Parser.cpp"
    break;

  case 23:
#line 143 "./parser/Parser.y"
                                                                           {
                                    if (Assign((yyvsp[-7].id), (yyvsp[0].tmp_id), (yyvsp[-4].types), i).empty()) {
                                        return 1;
                                    }
                                }
#line 1663 "./parser/Parser.cpp"
    break;

  case 24:
#line 148 "./parser/Parser.y"
                                                                               {
                                    bool made_union = !MakeUnknown((yyvsp[-7].id), (yyvsp[0].tmp_id), i).empty();
                                    if(!made_union) {
                                        return 1;
                                    }
                                }
#line 1674 "./parser/Parser.cpp"
    break;

  case 25:
#line 154 "./parser/Parser.y"
                                                                                  {
                                    auto union_name = MakeUnion((yyvsp[-7].id), (yyvsp[-4].tmp_id), (yyvsp[0].tmp_id), i);
                                    if (union_name.empty()) {
                                        return 1;
                                    }
                                }
#line 1685 "./parser/Parser.cpp"
    break;

  case 26:
#line 160 "./parser/Parser.y"
                                                            {
                                    if(Reassign((yyvsp[-4].id), (yyvsp[0].tmp_id), i).empty()) {
                                        return 1;
                                    }
                                }
#line 1695 "./parser/Parser.cpp"
    break;

  case 27:
#line 165 "./parser/Parser.y"
                                                                                         {
                                    if (i.RefBind((yyvsp[-10].id), (yyvsp[0].tmp_id), (yyvsp[-7].types)).empty()) {
                                        return 1;
                                    }
                                }
#line 1705 "./parser/Parser.cpp"
    break;

  case 28:
#line 173 "./parser/Parser.y"
                                           {
                                    if(!(yyvsp[0].tmp_id).GetFinalResult().empty()) { 
                                        (yyvsp[0].tmp_id).AddPending((yyvsp[0].tmp_id)); 
                                    }
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id); 
                                }
#line 1716 "./parser/Parser.cpp"
    break;

  case 29:
#line 179 "./parser/Parser.y"
                                                             {
                                    if(!(yyvsp[0].tmp_id).GetFinalResult().empty()) {
                                        (yyvsp[0].tmp_id).AddPending((yyvsp[0].tmp_id));
                                    }
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 1727 "./parser/Parser.cpp"
    break;

  case 30:
#line 185 "./parser/Parser.y"
                                                             {  
                                    if(!(yyvsp[-2].tmp_id).GetFinalResult().empty()) { 
                                        (yyvsp[-2].tmp_id).AddPending((yyvsp[0].tmp_id)); 
                                    }
                                    for(unsigned int i = 0; i < (yyvsp[0].tmp_id).PendingDataSize(); i++) {
                                        (yyvsp[-2].tmp_id).AddPending((yyvsp[0].tmp_id)[i]);
                                    }
                                    (yyval.tmp_id) = (yyvsp[-2].tmp_id);
                                }
#line 1741 "./parser/Parser.cpp"
    break;

  case 31:
#line 194 "./parser/Parser.y"
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
#line 1756 "./parser/Parser.cpp"
    break;

  case 38:
#line 211 "./parser/Parser.y"
                                                                             { 
                                    int err = Print((yyvsp[-2].tmp_id), ' ', i);
                                    
                                    if (err == 1) {
                                        cout << "Error: print error\n";
                                        return 1;
                                    }
                                    else if ((yyvsp[-2].tmp_id).PendingDataSize() > 0) {
                                        cout << '\n';
                                    }
                                }
#line 1772 "./parser/Parser.cpp"
    break;

  case 39:
#line 222 "./parser/Parser.y"
                                                     { return 0; }
#line 1778 "./parser/Parser.cpp"
    break;

  case 40:
#line 227 "./parser/Parser.y"
                                                                                           {
                                    string tmp = Add((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id), i);
                                    if(tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 1790 "./parser/Parser.cpp"
    break;

  case 41:
#line 234 "./parser/Parser.y"
                                                                 {
                                    string tmp = Add((yyvsp[-2].tmp_id), i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 1802 "./parser/Parser.cpp"
    break;

  case 42:
#line 241 "./parser/Parser.y"
                                                                          {
                                    string tmp = Subtract((yyvsp[-3].tmp_id), (yyvsp[-1].tmp_id), i);
                                    if(tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 1814 "./parser/Parser.cpp"
    break;

  case 43:
#line 248 "./parser/Parser.y"
                                                                 {
                                    string tmp = Subtract((yyvsp[-2].tmp_id), i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 1826 "./parser/Parser.cpp"
    break;

  case 44:
#line 255 "./parser/Parser.y"
                                                                          {
                                    string tmp = Multiply((yyvsp[-3].tmp_id), (yyvsp[-1].tmp_id), i);
                                    if(tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 1838 "./parser/Parser.cpp"
    break;

  case 45:
#line 262 "./parser/Parser.y"
                                                                 {
                                    string tmp = Multiply((yyvsp[-2].tmp_id), i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 1850 "./parser/Parser.cpp"
    break;

  case 46:
#line 269 "./parser/Parser.y"
                                                                                       {
                                    string tmp = Divide((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id), i);
                                    if(tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 1862 "./parser/Parser.cpp"
    break;

  case 47:
#line 276 "./parser/Parser.y"
                                                                 {
                                    string tmp = Divide((yyvsp[-2].tmp_id), i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 1874 "./parser/Parser.cpp"
    break;

  case 48:
#line 283 "./parser/Parser.y"
                                                                             {
                                    string var_1 = (yyvsp[-4].tmp_id);
                                    string var_2 = (yyvsp[-2].tmp_id);

                                    if (var_1.empty()) {
                                        var_1 = (yyvsp[-4].tmp_id)[0];
                                    }
                                    if (var_2.empty()) {
                                        var_2 = (yyvsp[-2].tmp_id)[0];
                                    }
                                    
                                    if (i.Pow(var_1, var_2) == 1) {
                                        return 1;
                                    }
                                    (yyvsp[-4].tmp_id).ClearPending();
                                    (yyval.tmp_id) = var_1;
                                }
#line 1896 "./parser/Parser.cpp"
    break;

  case 49:
#line 305 "./parser/Parser.y"
                                                                            {
                                    string tmp = Less((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id), i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 1908 "./parser/Parser.cpp"
    break;

  case 50:
#line 312 "./parser/Parser.y"
                                                                                 {
                                    string tmp = Greater((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id), i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 1920 "./parser/Parser.cpp"
    break;

  case 51:
#line 319 "./parser/Parser.y"
                                                                                   {
                                    string tmp = LessEqual((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id), i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 1932 "./parser/Parser.cpp"
    break;

  case 52:
#line 326 "./parser/Parser.y"
                                                                                       {
                                    string tmp = GreaterEqual((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id), i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 1944 "./parser/Parser.cpp"
    break;

  case 53:
#line 333 "./parser/Parser.y"
                                                                              {
                                    string tmp = Equal((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id), i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 1956 "./parser/Parser.cpp"
    break;

  case 54:
#line 340 "./parser/Parser.y"
                                                                                   {
                                    string tmp = NotEqual((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id), i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 1968 "./parser/Parser.cpp"
    break;

  case 55:
#line 351 "./parser/Parser.y"
                                                                          {
                                    string tmp = And((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id), i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 1980 "./parser/Parser.cpp"
    break;

  case 56:
#line 358 "./parser/Parser.y"
                                                                 {
                                    string tmp = Not((yyvsp[-2].tmp_id), i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 1992 "./parser/Parser.cpp"
    break;

  case 57:
#line 365 "./parser/Parser.y"
                                                                            {
                                    string tmp = Or((yyvsp[-4].tmp_id), (yyvsp[-2].tmp_id), i);
                                    if (tmp.empty()) {
                                        return 1;
                                    }
                                    (yyval.tmp_id) = tmp;
                                }
#line 2004 "./parser/Parser.cpp"
    break;

  case 58:
#line 375 "./parser/Parser.y"
                                     {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2012 "./parser/Parser.cpp"
    break;

  case 59:
#line 378 "./parser/Parser.y"
                                            {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2020 "./parser/Parser.cpp"
    break;

  case 60:
#line 381 "./parser/Parser.y"
                                                                                           {
                                    string tmp = Cast((yyval.tmp_id), (yyvsp[-4].tmp_id), (yyvsp[-2].types), i);
                                    if (tmp.empty()) {
                                        cout << "Error: couldn't cast\n";
                                        return 1;
                                    }
                                }
#line 2032 "./parser/Parser.cpp"
    break;

  case 61:
#line 388 "./parser/Parser.y"
                                               {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2040 "./parser/Parser.cpp"
    break;

  case 62:
#line 391 "./parser/Parser.y"
                                           {
                                    (yyval.tmp_id) = (yyvsp[0].tmp_id);
                                }
#line 2048 "./parser/Parser.cpp"
    break;

  case 68:
#line 401 "./parser/Parser.y"
                                       { 
                                    return 0 ;
                                }
#line 2056 "./parser/Parser.cpp"
    break;

  case 70:
#line 405 "./parser/Parser.y"
                                        { i.GarbageCollect(); return 1; }
#line 2062 "./parser/Parser.cpp"
    break;

  case 71:
#line 407 "./parser/Parser.y"
                                     {i.GarbageCollect();}
#line 2068 "./parser/Parser.cpp"
    break;

  case 72:
#line 407 "./parser/Parser.y"
                                                                       {i.GarbageCollect();}
#line 2074 "./parser/Parser.cpp"
    break;


#line 2078 "./parser/Parser.cpp"

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
#line 408 "./parser/Parser.y"



void PrintLineNo() {
    cout << "line num: " << lineno << "\n";
    lineno++;
}

void yyerror(const char* err) {
    cout << err << '\n';
    cout << yytext << '\n';
}

int main(int argc, char *argv[]) {
    bool in_file_mode = false;
    FILE *file = nullptr;
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        
        if (file) {
            yyin = file;
            in_file_mode = true;
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
