CC = g++
OBJ = search_simple_test.o
HEADER = include 
#CFLAGS = -c -Wall -Wextra -Wunused-variable -Iinclude 

CFLAGS = -c  -Iinclude 
search_simple_test: $(OBJ) 
	$(CC) $(OBJ) -o $@

search_simple_test.o: src/search_simple_test.cc $(HEADER)
	$(CC) $(CFLAGS) $< -o $@

clean: 
	rm -rf *o search_simple_test




