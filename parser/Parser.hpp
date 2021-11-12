/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
    CAST = 265,
    LESS = 266,
    GREATER = 267,
    LESS_EQUAL = 268,
    GREATER_EQUAL = 269,
    EQUAL = 270,
    NOT_EQUAL = 271,
    PRINT = 272,
    AND = 273,
    OR = 274,
    NOT = 275,
    EXIT = 276,
    NEWLINE = 277,
    SEMICOLON = 278,
    EOPU = 279,
    REF = 280,
    ADD = 281,
    SUB = 282,
    MUL = 283,
    DIV = 284,
    POW = 285,
    PUT = 286,
    SET = 287,
    GET = 288,
    INT_VAL = 289,
    DOUBLE_VAL = 290,
    STRING_VAL = 291,
    CHAR_VAL = 292,
    BOOL_VAL = 293,
    FLOAT_VAL = 294,
    MULTI_WS = 295,
    SINGLE_WS = 296,
    ID = 297,
    UNKNOWN = 298
  };
#endif

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_PARSER_HPP_INCLUDED  */
