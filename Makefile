# Specify include directories
INCLUDE_DIRS := -Isrc/include -Iinclude

# Specify library directories and flags
LIB_DIRS := -Lsrc/lib
LIBS := -lsfml-graphics -lsfml-window -lsfml-system

# Specify compiler and flags
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17

all: compile run

# Compile target
compile: #$(wildcard *.cpp)
	g++ $(wildcard *.cpp) $(INCLUDE_DIRS) $(LIB_DIRS) $(LIBS) -o bin/main

# Run target
run:
	./bin/main

# Clean target
clean:
	rm -f bin/main

.PHONY: all compile run clean
