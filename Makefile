all: compile run

compile:
	g++ *.cpp -Isrc/include -Iinclude -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system

run:
	./main
