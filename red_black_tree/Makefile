all: app

CC = gcc
CFLAGS = -Wall -g

SRC = red_black_tree.c main.c
OBJ = $(addsuffix .o, $(basename $(SRC)))
DEPS =$(addsuffix .h, $(basename $(filter-out main.c, $(SRC)))) 

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $< 

app: $(OBJ)
	$(CC) -o $@ $(CFLAGS) $(OBJ)


.PHONY: clean
clean:
	rm -rf *o 
	rm app


