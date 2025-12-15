SOURCE = src/main.cpp
OUTPUT = main
FLAGS = -Wall
LIBRARY = 
BUILDS = build
VERSION = c++11
COMPILER = clang++
ARGUMENT = test.xbc

all:
	$(COMPILER) $(SOURCE) $(FLAGS) -std=$(VERSION) $(LIBRARY) -o $(BUILDS)/$(OUTPUT)
run:
	./$(BUILDS)/${OUTPUT} $(ARGUMENT)
cnr:
	$(COMPILER) $(SOURCE) $(FLAGS) -std=$(VERSION) $(LIBRARY) -o $(BUILDS)/$(OUTPUT)
	./$(BUILDS)/$(OUTPUT) $(ARGUMENT)