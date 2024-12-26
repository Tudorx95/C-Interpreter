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

#ifndef YY_YY_GLANG_TAB_H_INCLUDED
# define YY_YY_GLANG_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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
    VAR = 258,                     /* VAR  */
    INT_VAL = 259,                 /* INT_VAL  */
    FLOAT_VAL = 260,               /* FLOAT_VAL  */
    DOUBLE_VAL = 261,              /* DOUBLE_VAL  */
    INT = 262,                     /* INT  */
    FLOAT = 263,                   /* FLOAT  */
    DOUBLE = 264,                  /* DOUBLE  */
    IF = 265,                      /* IF  */
    WHILE = 266,                   /* WHILE  */
    PRINT = 267,                   /* PRINT  */
    SCAN = 268,                    /* SCAN  */
    RETURN = 269,                  /* RETURN  */
    SLINE_COMMENT = 270,           /* SLINE_COMMENT  */
    OPEN_MLINE_COMMENT = 271,      /* OPEN_MLINE_COMMENT  */
    CLOSE_MLINE_COMMENT = 272,     /* CLOSE_MLINE_COMMENT  */
    LPAREN = 273,                  /* LPAREN  */
    RPAREN = 274,                  /* RPAREN  */
    LBRACE = 275,                  /* LBRACE  */
    RBRACE = 276,                  /* RBRACE  */
    COMMA = 277,                   /* COMMA  */
    SEMICOLON = 278,               /* SEMICOLON  */
    ASSIGN = 279,                  /* ASSIGN  */
    MODULO = 280,                  /* MODULO  */
    IFX = 281,                     /* IFX  */
    ELSE = 282,                    /* ELSE  */
    PLUS = 283,                    /* PLUS  */
    MINUS = 284,                   /* MINUS  */
    MULTIPLY = 285,                /* MULTIPLY  */
    DIVIDE = 286,                  /* DIVIDE  */
    EQUAL = 287,                   /* EQUAL  */
    NOTEQUAL = 288,                /* NOTEQUAL  */
    LESSEQUAL = 289,               /* LESSEQUAL  */
    GREATEREQUAL = 290,            /* GREATEREQUAL  */
    LESS = 291,                    /* LESS  */
    GREATER = 292,                 /* GREATER  */
    UMINUS = 293,                  /* UMINUS  */
    FUNCTION = 294                 /* FUNCTION  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "glang.y"

    int iVal;
    float fVal;
    double dVal;
    char *sval;
    nodeType *node;

#line 111 "glang.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_GLANG_TAB_H_INCLUDED  */
