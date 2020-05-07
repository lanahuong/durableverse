CC = gcc -Wall -Wextra -std=c99
BIN = bin/
OBJ = obj/
SRC = src/
INC = headers/

EXEC = $(BIN)durableverse

all : $(EXEC)

$(EXEC) : $(OBJ)structure.o $(OBJ)card.o $(OBJ)board.o $(OBJ)interface.o $(OBJ)main.o
	$(CC) -o $@ $^

$(OBJ)main.o : $(SRC)main.c
	$(CC) -c -o $@ $<

$(OBJ)%.o : $(SRC)%.c $(INC)%.h
	$(CC) -c -o $@ $<

doc :
	doxygen Doxyfile

clean : cleandoc
	rm -f $(OBJ)*.o $(BIN)*

cleandoc :
	rm -r html latex