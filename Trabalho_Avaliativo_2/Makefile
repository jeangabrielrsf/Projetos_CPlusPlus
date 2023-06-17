CXX=g++
CXXFLAGS=-Wall -std=c++11

OBJECTS=aresta.o vertice.o main.o grafo.o

PROGRAM=executeGrafo

all: $(PROGRAM)

$(PROGRAM) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@ 


.c++.o:
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -vf $(PROGRAM) *.o