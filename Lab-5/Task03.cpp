#include<iostream>
#include<string>
using namespace std;

class Employee
{
    int empcode;
    string empname;

public:
    Employee(){};
    Employee(int code)
    {
        empname="unknown";
        empcode = code;
    }
    Employee(int code, string name)
    {
        empcode = code;
        empname = name;
    }
    void setEmpCode(int code)
    {
        empcode = code;
    }
    int getEmpCode()
    {
        return empcode;
    }
    void setEmpName(string name)
    {
        empname = name;
    }
    string getEmpName()
    {
        return empname;
    }
    void displayEmpDetails()
    {
        cout << "Code: " << empcode ;
        cout << "    EmpName: " << empname << endl;
    }
};
int main()
{
    Employee e[6] = {
        Employee(1, "ash"),
        Employee(2, "shinz"),
        Employee(3),
        Employee(4, "ayesh"),
        Employee(5, "goku"),
        Employee(6)};
    for (int i = 0; i< 6; i++){
        if (e[i].getEmpName()=="unknown"){
            string newname;
            cout << "Employee with code: " << e[i].getEmpCode() << " ";
            cout << "Enter your name: ";
            getline(cin, newname);
            e[i].setEmpName(newname);
        }
    }
    for (int i = 0; i < 6; i++)
    {
        e[i].displayEmpDetails();
    }
}