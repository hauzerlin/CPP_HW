OBJECTS = passenger.o Reservation_system.o airline.o check.o

airline:$(OBJECTS)
	g++ -o airline $(OBJECTS)

Reservation_system.o: Reservation_system.cpp passenger.h airline.h
	g++ -c Reservation_system.cpp 

airline.o: airline.cpp airline.h
	g++ -c airline.cpp

passenger.o:  passenger.cpp passenger.h
	g++ -c passenger.cpp 

check.o: check.cpp check.h
	g++ -c check.cpp