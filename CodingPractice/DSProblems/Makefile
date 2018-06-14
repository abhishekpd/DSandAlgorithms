CC=g++
CFLAGS=-Wall -g -w
INCLUDE:= -Iheader/
SOURCE:= $(wildcard src/*.cpp)

EXE=DSandAlgorithm

all: $(EXE)

$(EXE):
	$(CC) $(CFLAGS) $(INCLUDE) $(SOURCE) -o $(EXE) 


clean:
	rm $(EXE)	
