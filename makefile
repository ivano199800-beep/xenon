SOURCE = src/main.c
OUTPUT = main
FLAGS = -Wall
LIBRARY = 
BUILDS = build
VERSION = c99
COMPILER = clang
ARGUMENT = test.xbc

all:
	$(COMPILER) $(SOURCE) $(FLAGS) -std=$(VERSION) $(LIBRARY) -o $(BUILDS)/$(OUTPUT)
run:
	./$(BUILDS)/${OUTPUT} $(ARGUMENT)
cnr:
	$(COMPILER) $(SOURCE) $(FLAGS) -std=$(VERSION) $(LIBRARY) -o $(BUILDS)/$(OUTPUT)
	./$(BUILDS)/$(OUTPUT) $(ARGUMENT)
rm:
	rm $(BUILD)/$(OUTPUT)
edit:
	vim $(BUILD)/$(OUTPUT)