OBJECTS = Reservation_system.o airline.o
HEAD_PATH = -I ./header

VPATH = ./src: ./header

ALL: airline clean

airline:$(OBJECTS) ./obj/check.o ./obj/passenger.o
	g++ -o airline $(OBJECTS) ./obj/check.o ./obj/passenger.o

Reservation_system.o: Reservation_system.cpp passenger.h airline.h
	@g++ $(HEAD_PATH) -c ./src/Reservation_system.cpp

airline.o: airline.cpp airline.h
	@g++ $(HEAD_PATH) -c ./src/airline.cpp

#passenger.o:  passenger.cpp passenger.h
#	@g++ $(HEAD_PATH) -o ./obj/passenger.o -c ./src/passenger.cpp

#check.o: check.cpp check.h
#	@g++ $(HEAD_PATH) -o ./obj/check.o -c ./src/check.cpp

.PHONY: airline clean

exe:
	@airline.exe

clean:
	@del $(OBJECTS)

