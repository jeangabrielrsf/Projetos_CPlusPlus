CC=g++
CFLAGS=-Wall -std=c11

OBJECTS=liga.o time.o main.o

PROGRAM=executeApp

all: $(PROGRAM)

$(PROGRAM) : $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ 


.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -vf $(PROGRAM) *.o