# $Id$
# plain simple Makefile to build $(EXEC)

CXX = /usr/bin/g++
LEX = flex
YACC = bison

CXXFLAGS= -W -Wall -Wno-deprecated-register -ansi -g -O0 -std=c++11
LDFLAGS= 

EXEC= example


all: $(EXEC) clean

# Generate scanner and parser

parser.cc: parser.yy
	$(YACC) -o parser.cc --defines=parser.h parser.yy

scanner.cc: lexer.l
	$(LEX) -o scanner.cc lexer.l

# Implicit rule to compile c++ files

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Link executable

$(EXEC): parser.o scanner.o driver.o main.o
	$(CXX) $(LDFLAGS) -o $@ parser.o scanner.o driver.o main.o

clean:
	rm -f *.o

mrproper: clean
	rm -f *.cc *.hh parser.h
