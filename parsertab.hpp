/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSERTAB_HPP_INCLUDED
# define YY_YY_PARSERTAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    BEGIN_T = 258,                 /* BEGIN_T  */
    END_T = 259,                   /* END_T  */
    NUMBER = 260,                  /* NUMBER  */
    INTEGER = 261,                 /* INTEGER  */
    REAL = 262,                    /* REAL  */
    ID = 263,                      /* ID  */
    PROGRAM = 264,                 /* PROGRAM  */
    VAR = 265,                     /* VAR  */
    ASSIGNOP = 266,                /* ASSIGNOP  */
    ADDOP = 267,                   /* ADDOP  */
    MULOP = 268,                   /* MULOP  */
    RELOP = 269,                   /* RELOP  */
    INPUT_OUTPUT = 270,            /* INPUT_OUTPUT  */
    READOP = 271,                  /* READOP  */
    WRITEOP = 272,                 /* WRITEOP  */
    ARRAY = 273,                   /* ARRAY  */
    OF = 274,                      /* OF  */
    IF = 275,                      /* IF  */
    WHILE = 276,                   /* WHILE  */
    DO = 277,                      /* DO  */
    ELSE = 278,                    /* ELSE  */
    THEN = 279,                    /* THEN  */
    OR = 280,                      /* OR  */
    NOT = 281,                     /* NOT  */
    FUNCTION = 282,                /* FUNCTION  */
    PROCEDURE = 283,               /* PROCEDURE  */
    EQ = 284,                      /* EQ  */
    NEQ = 285,                     /* NEQ  */
    LT = 286,                      /* LT  */
    LEQ = 287,                     /* LEQ  */
    GEQ = 288,                     /* GEQ  */
    GT = 289                       /* GT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSERTAB_HPP_INCLUDED  */
