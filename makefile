SOURCE = src/main.c
OUTPUT = main
FLAGS = -Wall
LIBRARY = -lc
BUILDS = build
VERSION = c99
COMPILER = clang
ARGUMENT = test.xbc
cnr:
	$(COMPILER) $(SOURCE) $(FLAGS) -std=$(VERSION) $(LIBRARY) -o $(BUILDS)/$(OUTPUT)
	./$(BUILDS)/$(OUTPUT) $(ARGUMENT)
all:
	$(COMPILER) $(SOURCE) $(FLAGS) -std=$(VERSION) $(LIBRARY) -o $(BUILDS)/$(OUTPUT)