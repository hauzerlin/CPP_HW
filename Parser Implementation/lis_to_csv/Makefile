OBJECTS = lis_to_csv.o

VPATH = ./src: ./header: ./obj

ALL: Praser 

Praser:$(OBJECTS)
	g++ -std=c++11 -o Praser_to_scv $(OBJECTS)

lis_to_scv.o: lis_to_scv.cpp
	g++ -std=c++11 -o lis_to_scv.o lis_to_scv.cpp

clean:
	@rm $(OBJECTS)
