CC = gcc
SRCOBJ = functions.c
OBJECT = functions.o
SRCMAIN = main.c
EXECUTABLE = main

$(EXECUTABLE): $(OBJECT)
	$(CC) $(SRCMAIN) $(OBJECT) -o $@ 

$(OBJECT): $(SRCOBJ)
	$(CC) -c $(SRCOBJ) -o $@

clean:
	rm -f $(OBJECT) $(EXECUTABLE)

