# for the unit tests
CC=g++
CFLAGS= -W -Wall -Weffc++ -ansi -std=c++11
LDFLAGS=
EXEC= unary.exe
EXEC2= binary.exe
SRC= ./../src/
INCL= -I./../include/$(wildcard *.h)
OBJ= operator.o binaryOperator.o unaryOperator.o constant.o variable.o affect.o expressionFactory.o expression.o 
OBJ_TESTS= unaryOperatorTests.o binaryOperatorTests.o


all: $(EXEC) $(EXEC2) clean

$(EXEC): $(OBJ) unaryOperatorTests.o
	@echo "création de l'exécutable ->" $@
	@$(CC) $(LDFLAGS) $^ -o $@

$(EXEC2): $(OBJ) binaryOperatorTests.o
	@echo "création de l'exécutable ->" $@
	@$(CC) $(LDFLAGS) $^ -o $@

%.o: $(SRC)%.cpp
	@echo "création de l'objet" $@
	@$(CC) $(CFLAGS) $(INCL) -c $< -o $@ 

unaryOperatorTests.o: unaryOperatorTests.cpp ../include/expressionFactory.hpp ../include/expression.hpp
	@echo "création de l'objet" $@
	@$(CC) -o unaryOperatorTests.o -c unaryOperatorTests.cpp $(CFLAGS)

binaryOperatorTests.o: binaryOperatorTests.cpp ../include/expressionFactory.hpp ../include/expression.hpp
	@echo "création de l'objet" $@
	@$(CC) -o binaryOperatorTests.o -c binaryOperatorTests.cpp $(CFLAGS)

clean: 	
	@rm -rf *.o

mrproper: clean 
	@rm -rf $(EXEC) $(EXEC2)
