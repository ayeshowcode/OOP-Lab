
#include <iostream>
using namespace std;
class office
{
    string location;
    int seatingcapacity;
    string furniture[3];

public:
    office(string str) : location(str) {}
    office(int n) : seatingcapacity(n) {}
    office() : furniture{"", "", ""} {}
    string getlocation()
    {
        return location;
    }
    int getcapacity()
    {
        return seatingcapacity;
    }
    string *getfurniture()
    {
        return furniture;
    }
};
int main()
{
    string *str;
    int n, i = 0;
    office obj_1(" ");
    office obj_2(0);
    office obj_3;
    cout << "location is " << obj_1.getlocation() << endl;
    cout << "seating capacity is " << obj_2.getcapacity() << endl;
    cout << "furniture=" << endl;
    while (i < 3)
    {
        cout << obj_3.getfurniture()[i] << endl;
        ++i;
    }
}