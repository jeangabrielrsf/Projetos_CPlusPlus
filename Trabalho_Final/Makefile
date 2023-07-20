CXX=g++
CXXFLAGS=-Wall -std=c++11
INCLFLAGS=-I/usr/include/python3.8 -lpython3.8

OBJECTS=main.o

PROGRAM=executeGerenciador

all: $(PROGRAM)

$(PROGRAM) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) $(INCLFLAGS) -o $@ 


.c++.o:
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -vf $(PROGRAM) *.o