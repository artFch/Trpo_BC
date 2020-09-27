CC=gcc
CFLAGS= -c -Wall
SOURCES=src/main.c src/functions.c src/display.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=bin/prog

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@
clean: 
	rm -rf $(OBJECTS) $(EXECUTABLE)
.PHONY: all clean 