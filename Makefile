all: interpreter

NAME := glang

interpreter:
	flex ${NAME}.l
	bison -d -v -Wcounterexamples ${NAME}.y
	gcc -g -o ${NAME} ${NAME}.tab.c lex.yy.c ${NAME}.c -lm