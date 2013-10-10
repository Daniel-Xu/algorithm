all: c_insertion_sort

CC = gcc
CFLAGS = -Wall -g

SRC = insertion_sort.c main.c
OBJ = $(addsuffix .o, $(basename $(SRC)))
DEPS =$(addsuffix .h. $(basename $(filter-out main.c $(SRC)))) 

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< 

c_insertion_sort: $(OBJ)
	$(CC) -o $@ $(CFLAGS) $(OBJ)


.PHONY: clean
clean:
	rm -rf *o hello

