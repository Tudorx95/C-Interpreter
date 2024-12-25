%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "glang.h"

extern FILE *yyin;
extern int yylex();
extern void yyrestart(FILE *input_file);

void yyerror(const char *s);

%}

%union {
    int iVal;
    float fVal;
    double dVal;
    char *sval;
    nodeType *node;
}
%define parse.error verbose

%token <sval> VAR
%token <iVal> INT_VAL
%token <fVal> FLOAT_VAL
%token <dVal> DOUBLE_VAL
%token INT FLOAT DOUBLE IF WHILE PRINT SCAN RETURN
%token SLINE_COMMENT OPEN_MLINE_COMMENT CLOSE_MLINE_COMMENT
%token LPAREN RPAREN LBRACE RBRACE COMMA SEMICOLON
%token ASSIGN MODULO

%nonassoc IFX   /* resolve the ambiguity of if-then-else */
%nonassoc ELSE
%left PLUS MINUS
%left MULTIPLY DIVIDE
%left EQUAL NOTEQUAL LESSEQUAL GREATEREQUAL LESS GREATER

%nonassoc UMINUS
%type <node> stmt expr stmt_list if_statement while_statement
%type <node> declaration assignment print_statement scan_statement block_stmt

%start program

%%
program: function
        { freeVars(); }
        ;

function: function stmt
        { interpret($2); freeNode($2);  }
        | /* NULL */
        ;

stmt: SEMICOLON 
    { $$ = nodOper(SEMICOLON, 2, NULL, NULL); }
    | expr SEMICOLON
    { $$ = $1; }
    | print_statement
    { $$ = $1; }
    | scan_statement
    { $$ = $1; }
    | declaration
    { $$ = $1; }
    | assignment
    { $$ = $1; }
    | while_statement
    { $$ = $1; }
    | if_statement
    { $$ = $1; }
    | block_stmt
    ;
block_stmt:
    LBRACE 
    { 
    //    enterScope(); $<node>$= NULL; 
    }   // here this is $2.
                        // Why do I need to add a rule here?
                        // Because the execution will continue to analyze
                        // stmt_list before to call enterScope().
    stmt_list RBRACE    // and here it continues
    {
        $$ = $3;
     //   exitScope(); 
    }
    ;

stmt_list: stmt
        { $$ = $1; }
        | stmt_list stmt
        { $$ = nodOper(SEMICOLON, 2, $1, $2); }
        ;
scan_statement: SCAN expr SEMICOLON 
        { $$ = nodOper(SCAN, 1, $2); }
;
print_statement: PRINT expr SEMICOLON
    { $$ = nodOper(PRINT, 1, $2); }
    ;

assignment: VAR ASSIGN expr SEMICOLON
    { $$ = nodOper(ASSIGN, 2, nodId($1), $3); }
    ;
declaration: INT VAR ASSIGN expr SEMICOLON 
    { 
        $$ = nodOper(ASSIGN, 2, nodId($2), $4);
    }
    | FLOAT VAR ASSIGN expr SEMICOLON 
    {      
            $$ = nodOper(ASSIGN, 2, nodId($2), $4);
    }
    | DOUBLE VAR ASSIGN expr SEMICOLON
    {
         $$ = nodOper(ASSIGN, 2, nodId($2), $4);
    }
    | INT VAR SEMICOLON 
    {
        Variable*p=malloc(sizeof(Variable));
        p->type=INT_TYPE;
        p->scope_level= current_scope;
        printf("a scope: %d\n",current_scope);
        p->value=malloc(sizeof(int));
        *(int*)p->value=0;
         $$ = nodOper(ASSIGN, 2, nodId($2),p); 
    }
    | FLOAT VAR SEMICOLON 
    {
        Variable*p=malloc(sizeof(Variable));
        p->type=FLOAT_TYPE;
        p->scope_level= current_scope;
        p->value=malloc(sizeof(float));
        *(float*)p->value=0.0f;
         $$ = nodOper(ASSIGN, 2, nodId($2),p); 
    }
    | DOUBLE VAR SEMICOLON 
    {
        Variable*p=malloc(sizeof(Variable));
        p->type=DOUBLE_TYPE;
        p->scope_level= current_scope;
        p->value=malloc(sizeof(double));
        *(double*)p->value=0;
        $$ = nodOper(ASSIGN, 2, nodId($2),p); 
    }
    ; 


while_statement: WHILE LPAREN expr RPAREN stmt
    { $$ = nodOper(WHILE, 2, $3, $5); }
    ;

if_statement: IF LPAREN expr RPAREN stmt %prec IFX
    { $$ = nodOper(IF, 2, $3, $5); }
    | IF LPAREN expr RPAREN stmt ELSE stmt
    { $$ = nodOper(IF, 3, $3, $5, $7); }
    ;

expr: INT_VAL
    { $$ = nodCon(&$1,INT_TYPE); }
    | FLOAT_VAL
    { $$ = nodCon(&$1,FLOAT_TYPE); }
    | DOUBLE_VAL
    { $$ = nodCon(&$1,DOUBLE_TYPE); }
    | VAR
    { $$ = nodId($1); }
    | MINUS expr %prec UMINUS
    { $$ = nodOper(UMINUS, 1, $2); }
    | expr PLUS expr
    { $$ = nodOper(PLUS, 2, $1, $3); }
    | expr MINUS expr
    { $$ = nodOper(MINUS, 2, $1, $3); }
    | expr MULTIPLY expr
    { $$ = nodOper(MULTIPLY, 2, $1, $3); }
    | expr DIVIDE expr
    {
        if ($3->con.iVal == 0) 
        {
            yyerror("Division by zero.");
            $3->con.iVal=1;
        }
        $$ = nodOper(DIVIDE, 2, $1, $3); 
    }
    | expr LESS expr
    { $$ = nodOper(LESS, 2, $1, $3); }
    | expr GREATER expr
    { $$ = nodOper(GREATER, 2, $1, $3); }
    | expr GREATEREQUAL expr
    { $$ = nodOper(GREATEREQUAL, 2, $1, $3); }
    | expr LESSEQUAL expr
    { $$ = nodOper(LESSEQUAL, 2, $1, $3); }
    | expr NOTEQUAL expr
    { $$ = nodOper(NOTEQUAL, 2, $1, $3); }
    | expr EQUAL expr
    { $$ = nodOper(EQUAL, 2, $1, $3); }
    | LPAREN expr RPAREN
    { $$ = $2; }
    ;
%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

void signal_handler(int signo)
{
    printf("Signal %d caught!\n", signo);
    exit(0);
}

void setEndSignal()
{
  struct sigaction sa;
  memset(&sa, 0, sizeof(sa));
  sa.sa_handler = signal_handler;
  sa.sa_flags = 0;
  sigemptyset(&sa.sa_mask);
  sigaction(SIGINT, &sa, NULL);
  sigaction(SIGTERM,&sa, NULL);
  sigaction(SIGSEGV, &sa, NULL);
}


int main(int argc, char *argv[]) {

    setEndSignal();
    char input[100];
    printf("Welcome to the C PARSER\n\n");
    for(int i=0; i<30; i++,printf("="));
    printf("\n");
    while(1)
    {
        printf("Enter to start (or analyze a program: run <script_name> or <exit> to shutdown the program): ");
        fgets(input, sizeof(input), stdin);
        if(strcmp(input, "exit\n") == 0)
            break;
        printf("Start analyzing the context!\n");
        if(strstr(input, "run"))
        {
            char *p=strtok(input," ");
            p=strtok(NULL," \n");
            printf("FILENAME: %s\n",p);
            yyin=fopen(p, "r");
            yyparse();
            fclose(yyin);
            // reset lexer internal state
            yyrestart(stdin);
            yyin=stdin;
            clearInputBuffer();
        }
        else
        {
            yyin=stdin;
            yyparse();
            clearInputBuffer();
        }
        fflush(stdin);
    }
    return 0;
}
