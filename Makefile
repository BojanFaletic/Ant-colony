CC=clang++
CXXFLAGS=-lsfml-graphics -lsfml-window -lsfml-system


.PHONY: clean run

run:
	@make clean
	@make sfml-app
	./sfml-app

sfml-app: obj/main.o
	$(CC) $^ -o sfml-app $(CXXFLAGS)

obj/main.o: main.cpp
	$(CC) -c $< -o $@

clean:
	rm -f sfml-app
	rm -f obj/*.o
