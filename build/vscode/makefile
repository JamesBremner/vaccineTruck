#source file search paths
VPATH = ../../src 

# compiler include search paths
INCS = \
	-I../../src \
	-I../../../boost/boost1_72

DEPS = cPathFinder.h

# folder for .o files
ODIR=./obj

# sources
_OBJ = truck.o cPathFinder.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	g++   -std=c++17 -c -o $@ $< $(INCS)

truck: $(OBJ) 
	g++ -o ../../bin/truck.exe $^ 


.PHONY: clean

clean:
	del /q obj