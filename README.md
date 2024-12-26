# C-Interpreter

An example of C interpreter language using FLEX and BISON.

## Table of Contents

- [What is an interpretor?](#project_overview)
- [Interpretors vs Compilers](#interpretors-compilers)
- [C-Interpreter Functionalities](#server_app)
- [Terminal Experience](#gui_app)
- [Usage](#run_app)
- [Bibliography](#bibliography)
- [Contributors](#contributors)

## What is an interpretor?

An interpretor is a computer software program used to simulate specific programming languages without converting it in actual machine code.
The commands are parsed to the interpreter that analyze them line by line. The source code is translated into object code which is then executed
by the integrated interpreter virtual machine.

## Interpretors vs Compilers

A compiler is a computer software program used for translating a specific programming language into a program written in machine code.
This new program is also named object file that contains object code. This code is then executed by the computer itself by linking it wih
additional system libraries if needed.
There are several advantages and disadvantages regarding this two terminologiers:

- Compiler advantages: Compilers can create the final executable and the run-time process is much faster than in the case of Interpretors
  Also, another advantage would be the memory consumption. The final executable can be executed at any time and has a fixed size on disk.

- Compiler disadvantages: Needs a linker to integrate the system libraries into the final executable.

- Interpretor advantages: In some cases, the interpretors are more reliable than a simple executable. They can detect errors regarding the
  syntactic and semantic analisis and diminuate the programmer debugging time (the code is analyzed as a programming language not as a machine code).

- Interpretor disadvantages: In case of interpretors, they are memory consuming because the memory space for the actual interpretor program is larger.
  The process of analyzing the code is increased due to the number of run-time grammar instructions.

## C-Interpreter Functionalities

There are several functionalities of this C-Interpretor program. Some of them are:

- variables support data-types: int, float, double
  E.g. int a = 5; or double b=3.15; or float c = 2.5f; or int x; (here when a variable is declared without a number, a residual value will take place)
- Arithmetic operations. Supported operators are: + (PLUS), - (MINUS), \* (MULTIPLY), / (DIVISON).
  E.g. a + b; b \* c; a / 2; (here the commutative and associative rules are handled correctly, alongside the paranthesis)
- Control instructions. Supported control instructions are: if and while
  E.g.
  if (a > 3) {
  a = a + 1;
  } else {
  a = a - 1;
  }
  while (a < 10) {
  a = a + 1;
  }
- Input and Output operations. Supported instructions: scanf and printf, but used different than C.
  E.g. scanf(x); printf(x); (here the value x must be defined first)
- Error detection. Supported error detections are: division by zero, data-types representation limits, variables beyond the scope (see below)
  E.g. c/0; int x=213432524254234; (here beyond an integer value)
- Block Scope. All declaration of variables are detected in their scope
  E.g.
  int x=10;
  {
  int b=7;
  printf(x);
  }
  printf(b); (here an exception occurs because var b is used outside its scope)
- Simple Functions. Supported simple function implementation along with function calls.
  E.g.
  int suma(int x, int y) {
  return x + y;
  }
  int rezultat = suma(5, 3);
- Type Conversion. Supported type conversion for int, float and double types.
  E.g. double e = (double)a; float f = (float)e; float d = (float)suma(10,2);
- Comments. Supported comments: line comments (//) and multi-line comments (/\*\*/)
  E.g. printf(/\* This is a comment
  \*/x)

## Terminal Experience

Regarding the User Experience (UE), the program execution is limited to a simple terminal where the user can interact with.
The interface:

Welcome to the C PARSER

==============================
Enter to start (or analyze a program: run <script_name> or <exit> to shutdown the program):

This is the program interface and the user may press enter and run its appropriate commands or use the command "run <program_name>" and
analyze its appropriate C program.

After the command "run <program_name>" the user must press enter to return to the menu.
After the pressing enter, the user can return to the menu by pressing CTRL-C command (SIGINT signal that is handled) and then press enter.
The program can be stopped ###only### with "exit" command.

## Usage

First clone the repo by using git clone <GIT_PROJECT_URL_NAME>.
Then navigate inside the project folder (cd C-Interpreter).
From that just run make -B interpreter to start the compilation process of the Interpreter.
And then run the interpreter using: ./glang

## Contributors
