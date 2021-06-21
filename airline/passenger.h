#include <string>
using namespace std;

class passenger;
class list;

class list 
{
    public:
        void init();//inital list in main function.
        void POP(passenger *);//delete specific passenger.
        void Push(passenger *);//add passenger in list.
        void Display_list();//show all the passenger.
        bool exist(short rd);
    private:
        passenger *first;
        passenger *rear;
        short psg_num;

};

class passenger
{
    private:

        int DOB;
        long passport_num;
        short type;
        short seat_num;

    public:
        string first_name;
        string last_name;
        short record;

        passenger *next;
        passenger *preverous;

        void set_first(string);
        void set_last(string);
        void set_DOB(int);
        void set_passport_num(long);
        void set_type(short);
        void set_seat(short);
        void set_record(short);
        void display_name();
        void display_data();
};