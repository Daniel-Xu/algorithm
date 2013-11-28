all: app

CC = g++
CFLAGS = -g -Wall 

SRC = $(tg)
OBJ = $(addsuffix .o, $(basename $(SRC)))
DEPS =$(addsuffix .h, $(basename $(filter-out main.c, $(SRC)))) 

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $< 

app: $(OBJ)
	$(CC) -o $@ $(CFLAGS) $(OBJ)


.PHONY: clean
clean:
	rm -rf *o
	rm app
	rm -rf app.*


