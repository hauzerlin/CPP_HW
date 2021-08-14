OBJECTS =  main.o tree_func.o file_op.o

VPATH = ./src: ./header

All: MAIN TEST clean

TEST:
	@./main.out floorplan.txt floorplan_out.txt

MAIN: $(OBJECTS)
	@g++ -I ./header -std=c++11 $(OBJECTS) -o main.out 

tree_func.o:tree_func.cpp tree_func.h
	@g++ -I ./header -std=c++11 -o tree_func.o -c $<

file_op.o:file_op.cpp file_op.h
	@g++ -I ./header -std=c++11 -c $<

main.o: main.cpp tree_func.h
	@g++ -I ./header -std=c++11 -c $<

clean:
	@rm $(OBJECTS)
