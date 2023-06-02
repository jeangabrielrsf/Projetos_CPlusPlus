CXX=g++
CXXFLAGS=-Wall -std=c++98

OBJECTS=liga.o time.o main.o

PROGRAM=executeApp

all: $(PROGRAM)

$(PROGRAM) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@ 


.c++.o:
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -vf $(PROGRAM) *.o