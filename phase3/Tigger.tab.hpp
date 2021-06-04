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

#ifndef YY_RR_PHASE3_TIGGER_TAB_HPP_INCLUDED
# define YY_RR_PHASE3_TIGGER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef RRDEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define RRDEBUG 1
#  else
#   define RRDEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define RRDEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined RRDEBUG */
#if RRDEBUG
extern int rrdebug;
#endif

/* Token type.  */
#ifndef RRTOKENTYPE
# define RRTOKENTYPE
  enum rrtokentype
  {
    T_CALL = 258,
    T_IF = 259,
    T_GOTO = 260,
    T_RET = 261,
    T_END = 262,
    T_AND = 263,
    T_OR = 264,
    T_EQ = 265,
    T_NEQ = 266,
    T_LEQ = 267,
    T_GEQ = 268,
    T_IMM = 269,
    T_ID = 270,
    T_LOAD = 271,
    T_LOADADDR = 272,
    T_STORE = 273,
    T_MALLOC = 274
  };
#endif

/* Value type.  */
#if ! defined RRSTYPE && ! defined RRSTYPE_IS_DECLARED
typedef char * RRSTYPE;
# define RRSTYPE_IS_TRIVIAL 1
# define RRSTYPE_IS_DECLARED 1
#endif


extern RRSTYPE rrlval;

int rrparse (void);

#endif /* !YY_RR_PHASE3_TIGGER_TAB_HPP_INCLUDED  */
