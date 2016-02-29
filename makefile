# for the project
CC=g++
CFLAGS= -W -Wall -Weffc++ -ansi -std=c++11
LDFLAGS=
EXEC= project.exe
SRC= ./src/
INCL= -I./include/$(wildcard *.h)
OBJ=  operator.o binaryOperator.o unaryOperator.o constant.o variable.o affectation.o expressionFactory.o operatorFactory.o expression.o main.o debugger.o 


all: $(EXEC) clean

$(EXEC): $(OBJ)
	@echo "création de l'exécutable ->" $@
	@$(CC) $(LDFLAGS) $^ -o $@

%.o: $(SRC)%.cpp
	@echo "création de l'objet" $@
	@$(CC) $(CFLAGS) $(INCL) -c $< -o $@ 

clean: 	
	@rm -rf *.o
	@rm -rf $(EXEC).dSYM

mrproper: clean 
	@rm -rf $(EXEC)
