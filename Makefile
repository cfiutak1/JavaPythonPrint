CFLAGS = -g -Wall -Wextra -DDEBUG

nonbloat:
	gcc $(CFLAGS) -std=c90 generator.py.cpp.c -o ggg
	./ggg
	g++ $(CFLAGS) generator.py.cpp -o gg
	./gg
	python3 generator.py

bloat:
	g++ $(CFLAGS) generator.py.cpp -o gg
	./gg
	python3 generator.py

clean:
	rm ggg gg
