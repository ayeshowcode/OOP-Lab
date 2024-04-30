#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class ElectricityBill
{
    int ConsumerNo;
    string ConsumerName;
    double PreviousMonthReading;
    double CurrentMonthReading;
    double billamount;
    string typeofEB;
    double totalUnits;

public:
    ElectricityBill()
    {
        cout << "welcome to Bill Generator" << endl;
    }
    void getInput()
    {
        cout << "Enter the consumer NO: ";
        cin >> ConsumerNo;
        cin.ignore();
        cout << "Enter your name: ";
        getline(cin, ConsumerName);
        cout << "Enter previous Month reading: ";
        cin >> PreviousMonthReading;
        cout << "Enter Current Month Reading: ";
        cin >> CurrentMonthReading;
        cin.ignore();
        cout << "Enter the type of EB(domestic or commercial): ";
        getline(cin, typeofEB);
    }
    int Calculate()
    {
        if (typeofEB == "domestic")
        {
            totalUnits = fabs(PreviousMonthReading - CurrentMonthReading);
            if (totalUnits > 500)
            {
                billamount += totalUnits * 6;
            }
            else if (totalUnits > 200)
            {
                billamount += totalUnits * 4;
            }
            else if (totalUnits > 100)
            {
                billamount += totalUnits * 2.5;
            }
            else if (totalUnits > 0)
            {
                billamount += totalUnits * 1;
            }
            return 1;
        }
        else if (typeofEB == "commercial")
        {
            totalUnits = fabs(PreviousMonthReading - CurrentMonthReading);
            if (totalUnits > 500)
            {
                billamount += totalUnits * 7;
            }
            else if (totalUnits > 200)
            {
                billamount += totalUnits * 4.5;
            }
            else if (totalUnits > 100)
            {
                billamount += totalUnits * 6;
            }
            else if (totalUnits > 0)
            {
                billamount += totalUnits * 2;
            }
            return 1;
        }
        else
        {
            cout << "invalid info";
            return 0;
        }
    }
    void display()
    {
        cout << "consumer No: " << ConsumerNo << endl;
        cout << "consumer Name: " << ConsumerName << endl;
        cout << "previous Month Reading: " << PreviousMonthReading << endl;
        cout << "Current Month Reading: " << CurrentMonthReading << endl;
        cout << "Bill amount: " << billamount << endl;
        cout << "Type: " << typeofEB << endl;
    }
};
int main()
{
    ElectricityBill e;
    int choice;
    while (1)
    {
        cout << "Enter 0 to calculate the bill and 1 to continue adding amount: ";
        cin >> choice;
        if (choice == 0)
        {
            break;
        }
        else if (choice == 1)
        {
            if (e.Calculate())
                e.getInput();
            e.display();
        }
        else
        {
            cout << "please Enter 0 or 1" << endl;
        }
    }
}