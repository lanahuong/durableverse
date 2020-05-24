CC = gcc -Wall -Wextra -std=c99
BIN = bin/
OBJ = obj/
SRC = src/
INC = headers/
TEST = test/
TESTLIST = $(TEST)structureTest.c $(TEST)testRun.c

EXEC = $(BIN)durableverse

all : $(EXEC)

test : $(TEST)testRun.c $(OBJ)structure.o
	$(CC) -o $(BIN)tests $^ -lcunit

$(EXEC) : $(OBJ)structure.o $(OBJ)card.o $(OBJ)board.o $(OBJ)interface.o $(SRC)main.c
	$(CC) -o $@ $^

$(OBJ)%.o : $(SRC)%.c $(INC)%.h
	$(CC) -c -o $@ $<

doc :
	doxygen Doxyfile

clean : cleandoc
	rm -fr $(OBJ)*.o $(BIN)*

cleandoc :
	rm -fr html latex
