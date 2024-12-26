#ifndef GLANG_H
#define GLANG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <limits.h>
#include <float.h>
#define MAX_VARS 100

void yyerror(const char *s);

typedef enum
{
    typeCon, // type of constant
    typeId,  // type of name
    typeOper // type of operation
} nodeEnum;

typedef enum
{
    INT_TYPE,
    FLOAT_TYPE,
    DOUBLE_TYPE,
    OTHER_TYPE
} DataType;

/* Constants */
typedef struct
{
    DataType type; // Type of the constant
    union
    {
        int iVal;
        float fVal;
        double dVal;
    };
} conNodeType;

/* Identifiers */
typedef struct
{
    DataType type;
    char name[32]; // Variable name
} idNodeType;

typedef struct
{
    char *name;
    DataType type;   // Type of the variable
    void *value;     // Value of the variable
    int scope_level; // maintain the var scope
} Variable;

extern int current_scope; // for new global vars
void enterScope();
void exitScope();

extern Variable sym[MAX_VARS]; // MAX_VARS is the maximum number of variables allowed
extern int symCount;           // Number of variables store

/* Operators */
typedef struct
{
    int oper; // Operator
    int nops; // Number of operands
    struct nodeTypeTag *op[2];
} oprNodeType;

/* General node */
typedef struct nodeTypeTag
{
    nodeEnum type;
    int scope_level;
    union
    {
        conNodeType con; // Constant
        idNodeType id;   // Identifier
        oprNodeType opr; // Operator
    };
} nodeType;

/* prototipurile functiilor */
nodeType *nodOper(int oper, int nops, ...);
Variable *performArithmetic(char oper, Variable *left, Variable *right);
/* nod operator in arbore
 */
nodeType *nodId(const char *name, DataType type);
/* nod frunza identificator
 */
nodeType *nodCon(void *value, DataType typeVar);
/* nod frunza constanta
 */
void freeNode(nodeType *p);
/* eliberare memorie
 */
Variable *interpret(nodeType *p);
/* functia de interpretare*/

Variable *getVariableValue(const char *name, int scope);
void setVariableValue(const char *name, DataType type, Variable *value);
Variable *determineCondition(const char *typeOp, Variable *left, Variable *right);
Variable *negateValue(Variable *val);
void freeVars();
void clearInputBuffer();

typedef struct
{
    char name[32];
    DataType returnType;
    DataType paramTypes[10]; // Parameter types
    char paramNames[10][32]; // Parameter names
    int paramCount;
    nodeType *body;
} Function;

typedef struct
{
    Function functions[100]; // Array to store functions
    int count;
} FunctionTable;

extern FunctionTable functionTable;
Function *findFunction(const char *name);
void addFunction(const char *name, DataType returnType, nodeType *body);
Variable *callFunction(const char *name, Variable **args, int argCount);

#endif
