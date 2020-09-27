CC=gcc
CFLAGS= -c -Wall
SOURCES=main.c functions.c display.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=prog

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@
clean: 
	rm -rf $(OBJECTS) $(EXECUTABLE)
.PHONY: all clean 
