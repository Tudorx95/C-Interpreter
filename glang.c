#include "glang.h"
#include "glang.tab.h"
#include <stddef.h>

Variable sym[MAX_VARS];
int symCount = 0;

// scope management
int current_scope = 0;

void enterScope()
{
  printf("ENTERS SCOPE\n");
  current_scope++;
}

void exitScope()
{
  printf("EXITS SCOPE\n");
  // Șterge toate variabilele din scope-ul curent
  // for (int i = symCount - 1; i >= 0; i--)
  // {
  //   if (sym[i].scope_level == current_scope)
  //   {
  //     free(sym[i].value);
  //     free(sym[i].name);

  //     // Mutăm ultima variabilă în locul celei șterse
  //     if (i < symCount - 1)
  //     {
  //       sym[i] = sym[symCount - 1];
  //     }
  //     symCount--;
  //   }
  // }
  current_scope--;
}

Variable *getVariableValue(const char *name, int scope)
{
  Variable *result = malloc(sizeof(Variable));
  result->type = 0;
  result->value = NULL;
  result->scope_level = 0;
  // for (int scope = current_scope; scope >= 0; scope--)
  for (int i = 0; i < symCount; ++i)
  {
    // printf("Type: %d\n", sym[i].type);
    if (sym[i].name && strcmp(sym[i].name, name) == 0 && sym[i].scope_level <= scope) // && sym[i].scope_level <= scope)
    {
      result->type = sym[i].type;
      result->scope_level = sym[i].scope_level;
      // result->value = malloc(sizeof(sym[i].value));
      // memcpy(result->value, sym[i].value, sizeof(sym[i].value));
      switch (sym[i].type)
      {
      case INT_TYPE:
        result->value = malloc(sizeof(int));
        *(int *)result->value = *(int *)sym[i].value;
        printf("Getting variable %s with value %d\n", name, *(int *)sym[i].value);
        break;
      case FLOAT_TYPE:
        result->value = malloc(sizeof(float));
        *(float *)result->value = *(float *)sym[i].value;
        break;
      case DOUBLE_TYPE:
        result->value = malloc(sizeof(double));
        *(double *)result->value = *(double *)sym[i].value;
        break;
      }
      return result;
    }
  }
  printf("Error: Variable '%s' not defined.\n", name);
  free(result);
  return NULL;
}

void setVariableValue(const char *name, Variable *var)
{
  if (!var)
    return;
  printf("Setting variable %s with value %d\n", name, *(int *)var->value);
  for (int i = 0; i < symCount; ++i)
  {
    // if variable exists verify if it has the same scope
    printf("SYMNAME: %s, SYM_SCOPE: %d, VAR_SCOPE: %d\n", sym[i].name, sym[i].scope_level, var->scope_level);
    if (strcmp(sym[i].name, name) == 0 && sym[i].scope_level <= var->scope_level)
    {
      printf("Variable EXISTS\n");
      sym[i].type = var->type;
      // sym[i].scope_level = var->scope_level;

      if (sym[i].value)
        free(sym[i].value);

      switch (var->type)
      {
      case INT_TYPE:
        sym[i].value = malloc(sizeof(int));
        *(int *)sym[i].value = *(int *)var->value;
        break;
      case FLOAT_TYPE:
        sym[i].value = malloc(sizeof(float));
        *(float *)sym[i].value = *(float *)var->value;
        break;
      case DOUBLE_TYPE:
        sym[i].value = malloc(sizeof(double));
        *(double *)sym[i].value = *(double *)var->value;
        break;
      }
      return;
    }
  }
  // else Add new variable
  if (symCount >= MAX_VARS)
  {
    printf("Error: Maximum number of variables exceeded.\n");
    exit(EXIT_FAILURE);
  }
  printf("Variable NOT EXISTS! SymCount: %d VarName: %s Curr_scope: %d\n", symCount, name, current_scope);
  sym[symCount].name = strdup(name);
  sym[symCount].type = var->type;
  sym[symCount].scope_level = var->scope_level;
  printf("Var current Scope: %d\n", current_scope);
  switch (var->type)
  {
  case INT_TYPE:
    sym[symCount].value = malloc(sizeof(int));
    *(int *)sym[symCount].value = *(int *)var->value;
    break;
  case FLOAT_TYPE:
    sym[symCount].value = malloc(sizeof(float));
    *(float *)sym[symCount].value = *(float *)var->value;
    break;
  case DOUBLE_TYPE:
    sym[symCount].value = malloc(sizeof(double));
    *(double *)sym[symCount].value = *(double *)var->value;
    break;
  }

  ++symCount;
}

#define SIZEOF_NODETYPE ((char *)&p->con - (char *)p)
nodeType *nodCon(void *value, DataType typeVar)
{
  nodeType *p;
  size_t nodeSize;
  /* alocare memorie pentru noul nod */
  nodeSize = SIZEOF_NODETYPE + sizeof(conNodeType);
  if ((p = malloc(nodeSize)) == NULL)
    yyerror("out of memory");
  /* copiere valoare constanta */
  p->type = typeCon;
  p->con.type = typeVar;
  p->scope_level = current_scope;
  printf("DEBUG nodCon: Current_scope: %d\n", current_scope);
  if (typeVar == INT_TYPE)
  {
    p->con.iVal = *(int *)value;
    printf("\nINT val inserted!\n");
  }
  else if (typeVar == DOUBLE_TYPE)
  {
    p->con.dVal = *(double *)value;
    printf("\nDOUBLE val inserted!\n");
  }
  else if (typeVar == FLOAT_TYPE)
  {
    p->con.fVal = *(float *)value;
    printf("\nFLOAT val inserted!\n");
  }
  return p;
}

nodeType *nodId(const char *name)
{
  nodeType *p;
  size_t nodeSize;

  /* Allocate memory for the new node */
  nodeSize = SIZEOF_NODETYPE + sizeof(idNodeType) + strlen(name) + 1;
  if ((p = malloc(nodeSize)) == NULL)
    yyerror("out of memory");

  /* Copy variable name */
  p->type = typeId;
  p->scope_level = current_scope;
  printf("DEBUG nodID: Current_scope: %d\n", current_scope);
  /* Store name in allocated memory after the node */
  strcpy(p->id.name, name);

  return p;
}

nodeType *nodOper(int oper, int nops, ...)
{
  va_list ap;
  nodeType *p;
  size_t nodeSize;
  int i;
  /* alocare memorie pentru noul nod */
  nodeSize = SIZEOF_NODETYPE + sizeof(oprNodeType) +
             (nops - 1) * sizeof(nodeType *);
  if ((p = malloc(nodeSize)) == NULL)
    yyerror("out of memory");
  /* copiere informatii functie de nops */
  p->type = typeOper;
  p->opr.oper = oper;
  p->opr.nops = nops;
  p->scope_level = current_scope;
  va_start(ap, nops);
  for (i = 0; i < nops; i++)
    p->opr.op[i] = va_arg(ap, nodeType *);
  va_end(ap);
  return p;
}

void freeNode(nodeType *p)
{
  int i;
  if (!p)
    return;
  if (p->type == typeOper)
  {
    for (i = 0; i < p->opr.nops; i++)
      freeNode(p->opr.op[i]);
  }
  free(p);
}
void freeVars()
{
  for (int i = 0; i < symCount; i++)
  {
    if (sym[i].value)
      free(sym[i].value);
    if (sym[i].name)
      free(sym[i].name);
  }
  symCount = 0;
}

Variable *performArithmetic(char oper, Variable *left, Variable *right)
{
  Variable *result = malloc(sizeof(Variable));
  if (!result)
  {
    yyerror("Memory allocation failed.");
    exit(EXIT_FAILURE);
  }
  // setting the max scope
  result->scope_level = (left->scope_level > right->scope_level ? left->scope_level : right->scope_level);

  double leftVal, rightVal, resVal;
  if (left->type == INT_TYPE)
    leftVal = *(int *)left->value;
  else if (left->type == FLOAT_TYPE)
    leftVal = *(float *)left->value;
  else
    leftVal = *(double *)left->value;

  if (right->type == INT_TYPE)
    rightVal = *(int *)right->value;
  else if (right->type == FLOAT_TYPE)
    rightVal = *(float *)right->value;
  else
    rightVal = *(double *)right->value;

  switch (oper)
  {
  case '+':
    resVal = leftVal + rightVal;
    printf("Perform arithmetic value: %d\n", (int)resVal);
    break;
  case '-':
    resVal = leftVal - rightVal;
    break;
  case '*':
    resVal = leftVal * rightVal;
    break;
  case '/':
    resVal = leftVal / rightVal;
    break;
  default:
    yyerror("Invalid operator.");
    free(result);
    return NULL;
  }

  if (left->type == DOUBLE_TYPE || right->type == DOUBLE_TYPE)
  {
    result->type = DOUBLE_TYPE;
    result->value = malloc(sizeof(double));
    *(double *)result->value = resVal;
  }
  else if (left->type == FLOAT_TYPE || right->type == FLOAT_TYPE)
  {
    result->type = FLOAT_TYPE;
    result->value = malloc(sizeof(float));
    *(float *)result->value = (float)resVal;
  }
  else
  {
    result->type = INT_TYPE;
    result->value = malloc(sizeof(int));
    *(int *)result->value = (int)resVal;
  }

  return result;
}

Variable *determineCondition(const char *typeOp, Variable *left, Variable *right)
{
  Variable *result = malloc(sizeof(Variable));
  if (!result)
  {
    yyerror("Memory allocation failed.");
    exit(EXIT_FAILURE);
  }
  double leftVal, rightVal;
  if (left->type == INT_TYPE)
    leftVal = *(int *)left->value;
  else if (left->type == FLOAT_TYPE)
    leftVal = *(float *)left->value;
  else
    leftVal = *(double *)left->value;

  if (right->type == INT_TYPE)
    rightVal = *(int *)right->value;
  else if (right->type == FLOAT_TYPE)
    rightVal = *(float *)right->value;
  else
    rightVal = *(double *)right->value;

  printf("LEFT VAL: %lf\tRIGHT VAL: %lf\n", leftVal, rightVal);
  result->type = INT_TYPE;
  result->value = malloc(sizeof(int));
  if (!strcmp(typeOp, ">"))
  {
    if (leftVal > rightVal)
    {
      *(int *)result->value = 1;
    }
    else
    {
      *(int *)result->value = 0;
    }
  }
  if (!strcmp(typeOp, "<"))
  {
    if (leftVal < rightVal)
    {
      *(int *)result->value = 1;
    }
    else
    {
      *(int *)result->value = 0;
    }
  }
  if (!strcmp(typeOp, "<="))
  {
    if (leftVal <= rightVal)
    {
      *(int *)result->value = 1;
    }
    else
    {
      *(int *)result->value = 0;
    }
  }
  if (!strcmp(typeOp, ">="))
  {
    if (leftVal >= rightVal)
    {
      *(int *)result->value = 1;
    }
    else
    {
      *(int *)result->value = 0;
    }
  }
  if (!strcmp(typeOp, "!="))
  {
    if (leftVal != rightVal)
    {
      *(int *)result->value = 1;
    }
    else
    {
      *(int *)result->value = 0;
    }
  }
  if (!strcmp(typeOp, "=="))
  {
    if (leftVal == rightVal)
    {
      *(int *)result->value = 1;
    }
    else
    {
      *(int *)result->value = 0;
    }
  }
  return result;
}

// used when scanf statements are included in the grammar
void clearInputBuffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

Variable *negateValue(Variable *val)
{
  switch (val->type)
  {
  case INT_TYPE:
    *(int *)val->value = -(*(int *)val->value);
    break;
  case FLOAT_TYPE:

    *(float *)val->value = -(*(float *)val->value);
    break;
  case DOUBLE_TYPE:

    *(double *)val->value = -(*(double *)val->value);
    break;
  default:
  }
  return val;
}

Variable *interpret(nodeType *p)
{
  if (!p)
    return NULL;

  Variable *result = malloc(sizeof(Variable));
  if (!result)
  {
    yyerror("Memory allocation failed.");
    exit(EXIT_FAILURE);
  }

  switch (p->type)
  {
  case typeCon:
  {
    result->type = p->con.type;
    result->scope_level = p->scope_level;
    switch (p->con.type)
    {
    case INT_TYPE:
      result->value = malloc(sizeof(int));
      *(int *)result->value = p->con.iVal;
      break;
    case FLOAT_TYPE:
      result->value = malloc(sizeof(float));
      *(float *)result->value = p->con.fVal;
      break;
    case DOUBLE_TYPE:
      result->value = malloc(sizeof(double));
      *(double *)result->value = p->con.dVal;
      break;
    default:
      result->value = NULL;
    }
    return result;
  }

  case typeId:
    return getVariableValue(p->id.name, p->scope_level);

  case typeOper:
  {
    switch (p->opr.oper)
    {
    case WHILE:
      // here is an expression that returns an int value
      while (*(int *)interpret(p->opr.op[0])->value)
        interpret(p->opr.op[1]);
      return NULL;

    case IF:
    {
      Variable *condition = interpret(p->opr.op[0]);
      if (!condition || !condition->value || *(int *)condition->value == 0)
      {
        if (p->opr.nops > 2)
        {
          return interpret(p->opr.op[2]); // ELSE branch
        }
        return NULL; // No ELSE branch
      }
      return interpret(p->opr.op[1]); // IF true branch
    }

    case PRINT:
    {
      Variable *val = interpret(p->opr.op[0]);
      if (!val || !val->value)
      {
        printf("Error: Variable not found or has null value.\n");
        return NULL;
      }
      printf("Current scope:var scope %d:%d\n", current_scope, val->scope_level);
      printf("Printing variable with type %d\n", val->type);
      switch (val->type)
      {
      case INT_TYPE:
        printf("INT %d\n", *(int *)val->value);
        break;
      case FLOAT_TYPE:
        printf("FLOAT %f\n", *(float *)val->value);
        break;
      case DOUBLE_TYPE:
        printf("DOUBLE %lf\n", *(double *)val->value);
        break;
      default:
        printf("Error: Unknown type %d\n", val->type);
      }
      return NULL;
    }

    case SCAN:
    {
      Variable *val = interpret(p->opr.op[0]); // Get the variable
      if (!val || !val->value)
      {
        printf("Error: Variable not found or has null value.\n");
        return NULL;
      }

      // Depending on the type of the variable, scan the correct value
      switch (val->type)
      {
      case INT_TYPE:
      {
        int input;
        if (scanf("%d", &input) != 1)
        {
          printf("Error: Invalid input for integer variable.\n");
          return NULL;
        }
        *(int *)(val->value) = input; // Store the input value in the variable's allocated memory
        break;
      }
      case FLOAT_TYPE:
      {
        float input;
        if (scanf("%f", &input) != 1)
        {
          printf("Error: Invalid input for float variable.\n");
          return NULL;
        }
        *(float *)(val->value) = input; // Store the input value in the variable's allocated memory
        break;
      }
      case DOUBLE_TYPE:
      {
        double input;
        if (scanf("%lf", &input) != 1)
        {
          printf("Error: Invalid input for double variable.\n");
          return NULL;
        }
        *(double *)(val->value) = input; // Store the input value in the variable's allocated memory
        break;
      }
      default:
        printf("Error: Unsupported variable type for scan.\n");
        return NULL;
      }
      clearInputBuffer();
      return val;
    }

    case SEMICOLON:
      interpret(p->opr.op[0]);
      return interpret(p->opr.op[1]);

    case ASSIGN:
      setVariableValue(p->opr.op[0]->id.name, interpret(p->opr.op[1])); // Assign value to variable
      return getVariableValue(p->opr.op[0]->id.name, p->opr.op[0]->scope_level);

    case UMINUS:
      return negateValue(interpret(p->opr.op[0]));
      //-interpret(p->opr.op[0]);
    case PLUS:
      return performArithmetic('+', interpret(p->opr.op[0]), interpret(p->opr.op[1]));
      // interpret(p->opr.op[0]) +
      //        interpret(p->opr.op[1]);
    case MINUS:
      return performArithmetic('-', interpret(p->opr.op[0]), interpret(p->opr.op[1]));
      // interpret(p->opr.op[0]) - interpret(p->opr.op[1]);
    case MULTIPLY:
      return performArithmetic('*', interpret(p->opr.op[0]), interpret(p->opr.op[1]));
      //  interpret(p->opr.op[0]) *
      //        interpret(p->opr.op[1]);
    case DIVIDE:
      return performArithmetic('/', interpret(p->opr.op[0]), interpret(p->opr.op[1]));
      //      interpret(p->opr.op[0]) /
      //  interpret(p->opr.op[1]);
    case LESS:
      return determineCondition("<", interpret(p->opr.op[0]), interpret(p->opr.op[1]));
      //  interpret(p->opr.op[0]) <
      //        interpret(p->opr.op[1]);
    case GREATER:
      return determineCondition(">", interpret(p->opr.op[0]), interpret(p->opr.op[1]));
      // interpret(p->opr.op[0]) >
      //        interpret(p->opr.op[1]);
    case GREATEREQUAL:
      return determineCondition(">=", interpret(p->opr.op[0]), interpret(p->opr.op[1]));
      //  interpret(p->opr.op[0]) >=
      //        interpret(p->opr.op[1]);
    case LESSEQUAL:
      return determineCondition("<=", interpret(p->opr.op[0]), interpret(p->opr.op[1]));
      //  interpret(p->opr.op[0]) <=
      //        interpret(p->opr.op[1]);
    case NOTEQUAL:
      return determineCondition("!=", interpret(p->opr.op[0]), interpret(p->opr.op[1]));
      // interpret(p->opr.op[0]) !=
      //        interpret(p->opr.op[1]);
    case EQUAL:
      return determineCondition("==", interpret(p->opr.op[0]), interpret(p->opr.op[1]));
      // interpret(p->opr.op[0]) ==
      //        interpret(p->opr.op[1]);
    }
  }
  }
  return result;
}
