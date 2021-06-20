OBJECTS = airline.o Reservation_system.o

airline:$(OBJECTS)
	g++ -o airline $(OBJECTS)

airline.o:  airline.cpp airline.h
	g++ -c airline.cpp 

Reservation_system.o: Reservation_system.cpp airline.h
	g++ -c Reservation_system.cpp 
