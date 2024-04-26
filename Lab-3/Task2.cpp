#include <iostream>
#include <string>
using namespace std;
class Batsmen
{
    int Bcode;
    string name;
    int innings;
    int notout;
    int runs;
    double batavg;
    void calcavg()
    {
        batavg = runs / (innings - notout);
    }

public:
    void readdata()
    {
        int count = 0;
        while (count != 4)
        {
            cout << "Enter the valid BCode (4 digits): ";
            cin >> Bcode;
            int tem = Bcode;
            int rem;
            while (tem != 0)
            {
                rem = Bcode % 10;
                tem /= 10;
                count++;
            }
        }

        cin.ignore();
        cout << "Enter the name: ";
        getline(cin, name);
        cout << "Enter the no of innings: ";
        cin >> innings;
        cout << "Enter the no of times not out: ";
        cin >> notout;
        cout << "Enter the runs: ";
        cin >> runs;
        calcavg();
    }
    void displaydata()
    {
        cout << endl;
        cout << "Bcode: " << Bcode << endl;
        cout << "Name: " << name << endl;
        cout << "Innings: " << innings << endl;
        cout << "Not Out: " << notout << endl;
        cout << "runs: " << runs << endl;
        cout << "bat avg: " << batavg << endl;
    }
};
int main()
{
    Batsmen b;
    b.readdata();
    b.displaydata();
}