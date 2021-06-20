OBJECTS = passenger.o Reservation_system.o screen.o

airline:$(OBJECTS)
	g++ -o airline $(OBJECTS)

passenger.o:  passenger.cpp passenger.h
	g++ -c passenger.cpp 

Reservation_system.o: Reservation_system.cpp passenger.h
	g++ -c Reservation_system.cpp 

screen.o: screen.cpp screen.h
	g++ -c screen.cpp