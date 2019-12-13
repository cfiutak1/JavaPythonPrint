CFLAGS = -g -Wall -Wextra -DDEBUG -std=c++14
CC = g++

all:
	gcc generator.py.cpp.c -std=c99 -o generator_generator_generator
	./generator_generator_generator
	$(CC) $(CFLAGS) generator.py.cpp -o generator_generator

clean:
	rm generator_generator
	rm generator_generator_generator
