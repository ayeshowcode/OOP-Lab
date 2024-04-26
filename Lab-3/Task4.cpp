#include <iostream>
#include <string>
using namespace std;

class Report
{
    string adno;
    string name;
    float marks[5];
    float average;
    void Avg()
    {
        for (int i = 0; i < 5; i++)
        {
            average += marks[i];
        }
        average /= 5;
    }

public:
    void Readinfo()
    {
        while (1)
        {
            cout << "Enter the addmission no (first character should be alphabet and then 3 digits): ";
            getline(cin, adno);
            if (adno.length() == 4 && ((adno.at(0) >= 'A' && adno.at(0) <= 'Z') || (adno.at(0) >= 'a' || adno.at(0) <= 'z')))
            {
                cout << "Valid addmission No!" << endl;
                break;
            }
            else
            {
                cout << "invalid addmission number try again " << endl;
                continue;
            }
        }

        cout << "Enter your name: ";
        getline(cin, name);
        cout << "Enter Your marks (out of 100) " << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << "Course " << i + 1 << ": ";
            cin >> marks[i];
            if (marks[i] > 100)
            {
                cout << "invalid marks" << endl;
                i--;
                continue;
            }
        }
        Avg();
    }
    void DisplayInfo()
    {
        cout << "Admission No: " << adno << endl;
        cout << "Name : " << name << endl;
        cout << "Marks :" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << "Course " << i + 1 << ": " << marks[i] << endl;
        }
        cout << endl;
        cout << "Average: " << average;
    }
};
int main()
{
    Report R;
    R.Readinfo();
    cout << "---------------------------------" << endl;
    R.DisplayInfo();
}