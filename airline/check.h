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