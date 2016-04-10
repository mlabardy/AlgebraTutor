# for the unit tests
CC= /usr/bin/g++
CFLAGS= -W -Wall -Weffc++ -ansi -std=c++11
LDFLAGS=
EXEC= tests.exe
SRC= ./../src/
INCL= -I./../include/$(wildcard *.h)
OBJ= for.o ifElse.o block.o conditional.o operator.o binaryOperator.o unaryOperator.o constant.o variable.o affectation.o expressionFactory.o comparatorFactory.o operatorFactory.o expression.o debugger.o
OBJ_TESTS= unitTests.o


all: $(EXEC) clean

$(EXEC): $(OBJ) unitTests.o
	@echo "création de l'exécutable ->" $@
	@$(CC) $(LDFLAGS) $^ -o $@

%.o: $(SRC)%.cpp
	@echo "création de l'objet" $@
	@$(CC) $(CFLAGS) $(INCL) -c $< -o $@ 

unitTests.o: unitTests.cpp
	@echo "création de l'objet" $@
	@$(CC) -o unitTests.o -c unitTests.cpp $(CFLAGS)

clean: 	
	@rm -rf *.o
	@rm -rf $(EXEC).dSYM

mrproper: clean 
	@rm -rf $(EXEC)
