CC=g++
CFLAGS= -W -Wall -Weffc++ -ansi -pedantic -std=c++11 -pthread
LDFLAGS=
EXEC= server
SRC= ./src/
INCL= -I./include/$(wildcard *.h)
OBJ= Exercice.o Client.o


all: $(EXEC) clean

$(EXEC): $(OBJ)
	@echo "création de l'exécutable " $@
	@$(CC) $(LDFLAGS) $^ -o $@

%.o: $(SRC)%.cpp
	@echo "création de l'objet " $@
	@$(CC) $(CFLAGS) $(INCL) -c $< -o $@ 

clean: 	
	@rm -rf *.o

mrproper: clean 
	@rm -rf $(EXEC)
