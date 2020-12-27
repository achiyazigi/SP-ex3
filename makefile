CC = gcc
FLAGS = -Wall
.PHONY: clean all

all:isort txtfind

isort:isort.c
	$(CC) $(FLAGS) $^ -o $@ 

txtfind:txtfind.c
	$(CC) $(FLAGS) $^ -o $@ 
	
clean:
	rm *.o txtfind isort
