CFLAGS = -g -Wall -Wextra -DDEBUG

nonbloat:
	beef generator.py.cpp.c.bf > generator.py.cpp.c
	gcc $(CFLAGS) generator.py.cpp.c -o ggg
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
