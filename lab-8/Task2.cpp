#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>
using namespace std;
class Person
{
protected:
    string name;
    string gender;
    string contactNo;
    public:
    Person()
    {
        cout << "Name: ";
        getline(cin, name);
        cout << "Gender: ";
        getline(cin, gender);
        cout << "Contact Number: ";
        getline(cin, contactNo);
    }
};
class SecurePassword : protected Person
{
    int minLen, NumSpecialCh, NumDigits;
    char *pass;
    char *specialchar;

public:
    SecurePassword()
    {
        cout << "Min Length: ";
        cin >> minLen;
        pass = new char[minLen];

        cout << "Num digits: ";
        cin >> NumDigits;

        cout << "Special characters: ";
        cin >> NumSpecialCh;
        specialchar = new char[NumSpecialCh];
    }
    void generate()
    {

        char listSpecialChar[8] = {'(', ')', '#', '@', '!', '%', '^', '&'};
        if (NumSpecialCh > 8)
        {
            cout << "Sorry there are only 8 characters!" << endl;
            return;
        }
        int num;
        for (int i = 0; i < name.size(); i++)
        { 
            pass[i] = name.at(i);
        }
        for (int i = name.size(); i < name.size() + NumDigits; i++)
        {
            num = rand() % contactNo.size();
            pass[i] = contactNo.at(num);
        }
        for (int i = name.size() + NumDigits; i < name.size() + NumDigits + NumSpecialCh; i++)
        {
            num = rand()%8;
              pass[i]=listSpecialChar[num];
        }
    }
    void display(){
        for (int i = 0; i< minLen; i++)
        {
            cout << pass[i];
        }
    }
};
int main()
{
    srand(time(NULL));
    SecurePassword ash;
    ash.generate();
    ash.display();
}