#include "passenger.h"

//check if the array is full.
bool first_full(bool[]);
bool economy_full(bool[]);
bool record_full(bool[]);
int ask_change(int);

//assign a place for passenger.
void assign_first(passenger*,bool[]);
void assign_economy(passenger*,bool[]);
void assign_record(passenger*,bool[]);

passenger *locate_rd(list, passenger*, short);

//void check_list(bool [], bool []);
short first_left(bool[]);
short economy_left(bool[]);
short seats_left(bool[]);
short record_left(bool[]);