%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <setjmp.h>
#include "glang.h"

extern FILE *yyin;
extern int yylex();
extern void yyrestart(FILE *input_file);

void yyerror(const char *s);
volatile sig_atomic_t canJump = 0;

/* Set to 1 once "env" buffer has been
   initialized by [sig]setjmp() */
  static jmp_buf env;


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
%token LPAREN RPAREN LBRACE RBRACE COMMA SEMICOLON
%token ASSIGN MODULO

%nonassoc IFX   /* resolve the ambiguity of if-then-else */
%nonassoc ELSE
%left PLUS MINUS
%left MULTIPLY DIVIDE
%left EQUAL NOTEQUAL LESSEQUAL GREATEREQUAL LESS GREATER

%nonassoc UMINUS
%nonassoc LPAREN 
%nonassoc ASSIGN
%nonassoc SEMICOLON
%type <node> stmt expr stmt_list if_statement while_statement
%type <node> declaration assignment print_statement scan_statement block_stmt

%token FUNCTION
%type <node> function_declaration function_call parameter_list expr_list block_stmt_func
%type <iVal> type

%start program

%%
program: function
        { freeVars(); }
        ;

function: function stmt
        { interpret($2); freeNode($2);  }
        | /* NULL */
        ;

function_call:
    VAR LPAREN expr_list RPAREN
    {
        $$ = nodOper(FUNCTION, 2, nodId($1, OTHER_TYPE), $3);
    }
    ;

expr_list:
    expr
    {
        $$ = $1;
    }
    | expr_list COMMA expr
    {
        $$ = nodOper(COMMA, 2, $1, $3);
    }
    ;
type:
    INT     { $$ = INT_TYPE; }
    | FLOAT { $$ = FLOAT_TYPE; }
    | DOUBLE { $$ = DOUBLE_TYPE; }
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
    { $$ = $1; }
    ;
block_stmt:
    LBRACE 
    { 
        enterScope();
    }
                        // Why do I need to add a rule here?
                        // Because the execution will continue to analyze
                        // stmt_list before to call enterScope().
    stmt_list RBRACE    // and here it continues
    {
       exitScope(); 
        $$ = $3;
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
    { $$ = nodOper(ASSIGN, 2, nodId($1,OTHER_TYPE), $3); }
    ;
declaration: INT VAR ASSIGN expr SEMICOLON %prec ASSIGN
    { 
        $$ = nodOper(ASSIGN, 2, nodId($2,INT_TYPE), $4);
    }
    | FLOAT VAR ASSIGN expr SEMICOLON %prec ASSIGN
    {      
            $$ = nodOper(ASSIGN, 2, nodId($2,FLOAT_TYPE), $4);
    }
    | DOUBLE VAR ASSIGN expr SEMICOLON %prec ASSIGN
    {
         $$ = nodOper(ASSIGN, 2, nodId($2,DOUBLE_TYPE), $4);
    }
    | INT VAR SEMICOLON %prec SEMICOLON
    {
        void*val=malloc(sizeof(int));
        *(int*)val=0;
        $$ = nodOper(ASSIGN, 2, nodId($2,INT_TYPE),nodCon(&val,INT_TYPE)); 
    }
    | FLOAT VAR SEMICOLON %prec SEMICOLON
    {
       void*val=malloc(sizeof(float));
        *(float*)val=0;
        $$ = nodOper(ASSIGN, 2, nodId($2,FLOAT_TYPE),nodCon(&val,FLOAT_TYPE)); 
    }
    | DOUBLE VAR SEMICOLON %prec SEMICOLON
    {
       void*val=malloc(sizeof(double));
        *(double*)val=0;
        $$ = nodOper(ASSIGN, 2, nodId($2,DOUBLE_TYPE),nodCon(&val, DOUBLE_TYPE)); 
    }
    | function_declaration
    ;
function_declaration: INT VAR LPAREN parameter_list RPAREN block_stmt_func
    {
        addFunction($2, INT_TYPE, $6);
        $$ = NULL;  // Function declarations don't produce a value
    }
    | FLOAT VAR LPAREN parameter_list RPAREN block_stmt_func
    {
        addFunction($2, FLOAT_TYPE, $6);
        $$ = NULL; 
    }
    | DOUBLE VAR LPAREN parameter_list RPAREN block_stmt_func
    {
        addFunction($2, DOUBLE_TYPE, $6);
        $$ = NULL;
    }
    | INT VAR LPAREN RPAREN block_stmt_func
    {
        addFunction($2, INT_TYPE, $5);
        $$ = NULL;
    }
    | FLOAT VAR LPAREN RPAREN block_stmt_func
    {
        addFunction($2, FLOAT_TYPE, $5);
        $$ = NULL;
    }
    | DOUBLE VAR LPAREN RPAREN block_stmt_func
    {
        addFunction($2, DOUBLE_TYPE, $5);
        $$ = NULL;
    }
    ;
block_stmt_func: LBRACE RETURN expr SEMICOLON RBRACE 
    { $$ = $3; }
    ;
parameter_list:
    type VAR
    {
        // Store parameter information in current function
        Function* func = &functionTable.functions[functionTable.count];
        func->paramTypes[func->paramCount] = $1;
        strncpy(func->paramNames[func->paramCount], $2, sizeof(func->paramNames[0]) - 1);
        func->paramCount++;
        $$ = nodId($2, $1);
    }
    | parameter_list COMMA type VAR
    {
        Function* func = &functionTable.functions[functionTable.count];
        func->paramTypes[func->paramCount] = $3;
        strncpy(func->paramNames[func->paramCount], $4, sizeof(func->paramNames[0]) - 1);
        func->paramCount++;
        $$ = nodOper(COMMA, 2, $1, nodId($4, $3));
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

expr: function_call { $$ = $1; }
    | INT_VAL
    {   
        $$ = nodCon(&$1,INT_TYPE); 
    }
    | FLOAT_VAL
    { 
        $$ = nodCon(&$1,FLOAT_TYPE); 
    }
    | DOUBLE_VAL
    { 
        $$ = nodCon(&$1,DOUBLE_TYPE); 
    }
    | VAR
    { $$ = nodId($1,OTHER_TYPE); }
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
    | LPAREN INT RPAREN expr %prec UMINUS
    {
        $$ = $4;
    }
    | LPAREN FLOAT RPAREN expr %prec UMINUS
    {
        $$ = $4;
    }
    | LPAREN DOUBLE RPAREN expr %prec UMINUS
    {
        $$ = $4;
    }
    | LPAREN expr RPAREN
    { $$ = $2; }
    ;
%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

// Function to reset lexer and parser states
void reset_parser_state() {
    // Reset input streams
    yyrestart(stdin);
    yyin = stdin;
    
    // Clear any existing error flags
    clearerr(stdin);
}

void signal_handler(int signo)
{
    printf("Signal %d caught!\n", signo);
    longjmp(env, 1);
    
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

    // Set up the initial jump point
    if (sigsetjmp(env, 1) != 0) 
    {
        // We've jumped back here after a signal
        printf("\nReturned to main loop after signal. Press Enter:\n");
        reset_parser_state();
        clearInputBuffer();
        fflush(stdout);
        fflush(stdin);
    }

    while(1)
    {
        // Activate the jump mechanism
        canJump = 1;

        printf("Enter to start (or analyze a program: run <script_name> or <exit> to shutdown the program): ");
        fgets(input, sizeof(input), stdin);

         // Deactivate the jump mechanism during processing
        canJump = 0;

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
