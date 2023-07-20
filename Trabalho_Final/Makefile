CXX=g++
CXXFLAGS=-Wall -std=c++11

OBJECTS=main.o

PROGRAM=executeGerenciador

all: $(PROGRAM)

$(PROGRAM) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@ 


.c++.o:
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -vf $(PROGRAM) *.o