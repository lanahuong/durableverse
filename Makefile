CC = gcc -Wall -Wextra -std=c99
BIN = bin/
OBJ = obj/
SRC = src/
INC = headers/

EXEC = $(BIN)durableverse

all : $(EXEC)

$(EXEC) : $(OBJ)*.o
	$(CC) -o $@ $^

$(OBJ)%.o : $(SRC)%.c $(INC)%.h
	$(CC) -c -o $@ $<

clean :
	rm -f $(OBJ)*.o $(BIN)*