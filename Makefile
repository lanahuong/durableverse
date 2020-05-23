CC = gcc -Wall -Wextra -std=c99 -g
BIN = bin/
OBJ = obj/
SRC = src/
INC = headers/

EXEC = $(BIN)durableverse

all : $(EXEC)

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
