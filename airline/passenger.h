#include <string>
using namespace std;

/*class list
{
    public:
    passenger *first;
    passenger *rear;
    short psg_num;

};*/

class passenger
{
    private:
        string first_name;
        string last_name;
        int DOB;
        long passport_num;
        short type;
        short seat_num;
        short record;

    public:
        //passenger(string,string);
        //passenger *next;
        //passenger *preverous;
        //void add_passenger(list &l);
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