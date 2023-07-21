CXX=g++
CXXFLAGS=-Wall -std=c++11
INCLFLAGS=-I/usr/include/python3.8 -lpython3.8
DEBUGFLAG=-g
VALGRINDFLAG=valgrind --leak-check=yes

OBJECTS=main.o

PROGRAM=executeGerenciador

all: $(PROGRAM)

$(PROGRAM) : $(OBJECTS)
	$(CXX) $(DEBUGFLAG) $(CXXFLAGS) $(OBJECTS) $(INCLFLAGS) -o $@ 


.c++.o:
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -vf $(PROGRAM) *.o