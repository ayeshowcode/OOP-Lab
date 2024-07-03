#include <iostream>
#include <string>
using namespace std;
class Passenger
{
    string mobile_no;
    string pickup;
    string dropoff;
    int Kms;
    string area;

public:
    Passenger(){};
    Passenger(int kms, string area)
    {
        mobile_no = "91410351";
        pickup = "helsa";
        dropoff = "alsa";
        this->Kms = kms;
        this->area = area;
    }
    string getArea()
    {
        return area;
    }
    int getKms()
    {
        return Kms;
    }
};
class driver
{
    int id;
    string name;
    Passenger *p;
    static int earnings;
    static int countalpha;
    static int countbeta;
    static int countgamma;
    static int remainingfuel;

public:
    driver(Passenger *pas)
    {
        id = 1;
        name = "ayesh";
        p = new Passenger[2];
        for (int i = 0; i < 2; i++)
        {
            p[i] = pas[i];
        }
    }
    void checkArea()
    {
        for (int i = 0; i < 2; i++)
        {
            if (p[i].getArea() == "alpha")
            {
                earnings += p[i].getKms() * 150;
                countalpha++;
                remainingfuel -= 2 * p[i].getKms();
            }
            else if (p[i].getArea() == "beta")
            {
                earnings += p[i].getKms() * 150;
                countbeta++;
                remainingfuel -= 2 * p[i].getKms();
            }
            else if (p[i].getArea() == "gamma")
            {
                earnings += p[i].getKms() * 150;
                countgamma++;
                remainingfuel -= 2 * p[i].getKms();
            }
        }
    }
    void Reward()
    {
        cout << "Driver got " << countalpha << " alpha type, "
             << countbeta << " beta type, " << countgamma << " gamma type passengers" << endl;
        cout << "Total Earnings: " << earnings;

        if (countalpha > countbeta && countalpha > countgamma)
        {
            earnings += 500;
            cout << "Driver got a reward!! " << endl
                 << "Total Earnings: " << earnings;
        }
    }
    int static getRemainingfuel()
    {
        return remainingfuel;
    }
};
int driver ::earnings = 0;
int driver ::countalpha = 0;
int driver ::countbeta = 0;
int driver ::countgamma = 0;
int driver ::remainingfuel = 5000;

int main()
{
    int kms;
    string area;
    Passenger *p;
    p = new Passenger[2];
    for (int i = 0; i < 2; i++)
    {
        cout << "Enter the no of kms you want to travel: " << endl;
        cin >> kms;
        cin.ignore();
        cout << "Enter the area: ";
        getline(cin, area);
        p[i] = Passenger(kms, area);
    }
    driver d(p);
    d.checkArea();
    d.Reward();
    cout << "Remaining Fuel: " << driver::getRemainingfuel();
}
