CFLAGS = -g -Wall -Wextra -DDEBUG -std=c++14
CC = g++

all:
	$(CC) $(CFLAGS) generator.py.cpp -o generator_generator

clean:
	rm generator_generator
