#include <iostream>
using namespace std;
class Packages
{
protected:
    string Sname, Saddress, Scity, Sstate, Szipcode;
    string Rname, Raddress, Rcity, Rstate, Rzipcode;
    double weight, costperounce;
    double cost;

public:
    Packages() {}
    Packages(string Sname, string Saddress, string Scity, string Sstate, string Szipcode, string Rname, string Raddress, string Rcity, string Rstate, string Rzipcode, double weight, double costperounce) : Sname(Sname), Saddress(Saddress), Scity(Scity), Sstate(Sstate), Szipcode(Szipcode), Rname(Rname), Raddress(Raddress), Rcity(Rcity), Rstate(Rstate), Rzipcode(Rzipcode), weight(weight), costperounce(costperounce) {}
    void authentication()
    {
        if (weight <= 0 || costperounce <= 0)
        {
            cout << "Invalid input" << endl;
            return;
        }
        else
            cost = weight * costperounce;
    }
};
class TwoDayPackage : public Packages
{
private:
    double flatfee;

public:
    TwoDayPackage(string Sname, string Saddress, string Scity, string Sstate, string Szipcode, string Rname, string Raddress, string Rcity, string Rstate, string Rzipcode, double weight, double costperounce) : Packages(Sname, Saddress, Scity, Sstate, Szipcode, Rname, Raddress, Rcity, Rstate, Rzipcode, weight, costperounce) {}

    void setFlatFee(double flatfee)
    {
        this->flatfee = flatfee;
    }
    double calculateCost()
    {
        return flatfee + cost;
    }
};
class OverNightPackage : public Packages
{
    double addCost;

public:
    OverNightPackage(string Sname, string Saddress, string Scity, string Sstate, string Szipcode, string Rname, string Raddress, string Rcity, string Rstate, string Rzipcode, double weight, double costperounce) : Packages(Sname, Saddress, Scity, Sstate, Szipcode, Rname, Raddress, Rcity, Rstate, Rzipcode, weight, costperounce) {}
    void setAddCost(double addCost)
    {
        this->addCost = addCost;
    }
    double calculateCost()
    {
        return addCost + cost;
    }
};
int main()
{

    TwoDayPackage P1("ash", "bakerStreet", "London", "bhainscolony", "a14", "afds", "agags", "afds", "afds", "a13", 50.0, 2.0);
    P1.authentication();
    P1.setFlatFee(250.0);
    cout << "Charges for Two Day package delivery: " << P1.calculateCost() << endl;

    OverNightPackage P2("ayesh", "afds", "adgs", "hu", "b14", "iuo", "iuo", "qwe", "uhbafd", "b13", 50.0, 2.0);
    P1.authentication();
    P2.setAddCost(100.0);
    cout << "Charges for overnight delivery: " << P2.calculateCost();
}