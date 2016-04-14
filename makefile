CC= /usr/bin/g++
LEX = flex
YACC = bison

CFLAGS= -W -Wall -Weffc++ -ansi -std=c++11
CXXFLAGS= -W -Wall -Wno-deprecated-register -ansi -g -O0 -std=c++11
LDFLAGS=

EXEC= project.exe

SRC= ./src/
PARSER= ./parser/
INCL= -I./include/$(wildcard *.h)
INCL_PARSER= -I./parser/$(wildcard *.h)
OBJECTS= ./objects/

OBJ= main.o product.o for.o ifElse.o block.o conditional.o operator.o binaryOperator.o unaryOperator.o constant.o variable.o affectation.o expressionFactory.o comparatorFactory.o operatorFactory.o expression.o debugger.o
PARSER_OBJ= $(OBJECTS)parser.o $(OBJECTS)scanner.o $(OBJECTS)driver.o


all: $(EXEC) clean

$(EXEC): $(PARSER_OBJ) $(OBJ)
	@echo "création de l'exécutable ->" $@
	@$(CC) $(LDFLAGS) $^ -o $@

$(PARSER)parser.cc: $(PARSER)parser.yy
	@echo "création du fichier" $@
	@$(YACC) -o $@ --defines=$(PARSER)parser.h $<

$(PARSER)scanner.cc: $(PARSER)lexer.l
	@echo "création du fichier" $@
	@$(LEX) -o $(PARSER)scanner.cc $(PARSER)lexer.l

$(OBJECTS)parser.o: $(PARSER)parser.cc
	@echo "création de l'objet" $@
	@$(CC) $(CXXFLAGS) -c -o $@ $<

$(OBJECTS)scanner.o: $(PARSER)scanner.cc
	@echo "création de l'objet" $@
	@$(CC) $(CXXFLAGS) -c -o $@ $<

$(OBJECTS)driver.o: $(PARSER)driver.cpp
	@echo "création de l'objet" $@
	@$(CC) $(CXXFLAGS) $(INCL) $(INCL_PARSER) -c -o $@ $<

%.o: $(SRC)%.cpp
	@echo "création de l'objet" $@
	@$(CC) $(CFLAGS) $(INCL) $(INCL_PARSER) -c $< -o $@ 

clean: 
	@rm -rf *.o
	@rm -rf $(EXEC).dSYM

mrproper: clean 
	@rm -rf $(EXEC)
	@rm -f $(PARSER)*.cc $(PARSER)*.hh
	@rm -rf $(OBJECTS)*.o
