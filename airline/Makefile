OBJECTS = ./obj/passenger.o ./obj/Reservation_system.o ./obj/airline.o ./obj/check.o
HEAD_PATH = -I ./header
OBJ_PATH = ./obj/

VPATH = ./src: ./header
vpath %.cpp src
vpath %.o obj

airline:$(OBJECTS)
	g++ -o airline $(OBJECTS)

Reservation_system.o: Reservation_system.cpp passenger.h airline.h
	g++ $(HEAD_PATH) -c ./src/Reservation_system.cpp

airline.o: airline.cpp airline.h
	g++ $(HEAD_PATH) -c ./src/airline.cpp

passenger.o:  passenger.cpp passenger.h
	g++ $(HEAD_PATH) -c ./src/passenger.cpp

check.o: check.cpp check.h
	g++ $(HEAD_PATH) -c ./src/check.cpp

clean:
	del $(OBJECTS)