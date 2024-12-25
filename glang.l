%option noyywrap
%{
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include "glang.h"
#include "glang.tab.h"
void yyerror(const char *s);

%}


%%
"int"           { return INT; }
"float"         { return FLOAT; }
"double"        { return DOUBLE; }
"scanf"          { return SCAN; }
"printf"         { return PRINT; }
"return"        { return RETURN; }
"if"            { return IF; }
"else"          { return ELSE; }
"while"         { return WHILE; }
"//".*          { return SLINE_COMMENT;}  
"/*"            { return OPEN_MLINE_COMMENT; }
"*/"            { return CLOSE_MLINE_COMMENT; }
[a-zA-Z_][a-zA-Z0-9_]*   { yylval.sval = strdup(yytext); return VAR; }
[0-9]+\.[0-9]+           { 
                              char *endptr;
                            if(yytext==NULL || *yytext=='\0')
                              return DOUBLE_VAL;
                            errno = 0;
                            double val= strtod(yytext,&endptr);
                            if (((val >= DBL_MAX || val <= -DBL_MAX))) {
                               yyerror("Error: float is not in range");
                               }
                            yylval.dVal = strtod(yytext,NULL);
                            return DOUBLE_VAL; 
                         }
[0-9]+\.[0-9]+[fF]       { 
                            char *endptr;
                            if(yytext==NULL || *yytext=='\0')
                              return FLOAT_VAL;
                            errno = 0;
                              float val = strtof(yytext, &endptr);
                               if (((val >= FLT_MAX || val <= FLT_MIN))) {
                               yyerror("Error: float is not in range");
                               }
                            yylval.fVal = strtof(yytext,NULL);
                           return FLOAT_VAL; 
                         }
[0-9]+                   {
                             char * endptr;
                             long val = strtol(yytext,&endptr,10);
                               if (*endptr != '\0') {
                                      yyerror("Error: integer is not in range!");
                                      // Not a valid integer (extra characters found)

                                }
                                // Check for overflow or underflow
                              if (val >= INT_MAX || val <= INT_MIN) {
                                 yyerror("Error integer is not in range!");
                                  // Overflow or underflow
                              }

                             yylval.iVal = atoi(yytext);
                             return INT_VAL; 
                         }
"=="            { return EQUAL; }
"!="            { return NOTEQUAL; }
"<="            { return LESSEQUAL; }
">="            { return GREATEREQUAL;}
"<"             { return LESS; }
">"             { return GREATER; }
"("             { return LPAREN; }
")"             { return RPAREN; }
"{"             { return LBRACE; }
"}"             { return RBRACE; }
","             { return COMMA; }
";"             { return SEMICOLON; }
"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return MULTIPLY; }
"/"             { return DIVIDE; }
"="             { return ASSIGN; }
"%"             { return MODULO; }
[ \t\n]+         ; /* Ignore whitespace */
.               ;
%%