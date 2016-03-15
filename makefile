CC= /usr/bin/g++
LEX = flex
YACC = bison

CFLAGS= -W -Wall -Weffc++ -ansi -std=c++11
CXXFLAGS= -W -Wall -Wno-deprecated-register -ansi -g -O0 -std=c++11
LDFLAGS=

EXEC= project.exe

SRC= ./src/
PARSER= parser/
INCL= -I./include/$(wildcard *.h)

OBJ= operator.o binaryOperator.o unaryOperator.o constant.o variable.o affectation.o expressionFactory.o operatorFactory.o expression.o main.o debugger.o
PARSER_OBJ= parser.o scanner.o driver.o


all: $(EXEC) clean

$(EXEC): $(OBJ) $(PARSER_OBJ)
	@echo "création de l'exécutable ->" $@
	@$(CC) $(LDFLAGS) $^ -o $@

parser.cc: $(PARSER)parser.yy
	@echo "création de l'objet" $@
	@$(YACC) -o parser.cc --defines=parser.h parser.yy

scanner.cc: $(PARSER)lexer.l
	@echo "création de l'objet" $@
	@$(LEX) -o scanner.cc lexer.l

parser.o: $(PARSER)parser.cc
	@echo "création de l'objet" $@
	@$(CC) $(CXXFLAGS) -c -o $@ $<

scanner.o: $(PARSER)scanner.cc
	@echo "création de l'objet" $@
	@$(CC) $(CXXFLAGS) -c -o $@ $<

driver.o: $(PARSER)driver.cpp
	@echo "création de l'objet" $@
	@$(CC) $(CXXFLAGS) -c -o $@ $<

%.o: $(SRC)%.cpp
	@echo "création de l'objet" $@
	@$(CC) $(CFLAGS) $(INCL) -c $< -o $@ 

clean: 	
	@rm -rf *.o
	@rm -rf $(EXEC).dSYM

mrproper: clean 
	@rm -rf $(EXEC)
	@rm -f *.cc *.hh parser.h
