#include <iostream>
using namespace std;
class Employee
{
protected:
    int salary;
    int hoursWorked;
    string name;

public:
    Employee(string name, int hoursWorked) : name(name), hoursWorked(hoursWorked)
    {
        salary = 40000 + hoursWorked * 1500;
    }
    int getSalary()
    {
        return salary;
    }
    string getName()
    {
        return name;
    }
};
class Lawyers : public Employee
{

public:
    Lawyers(string name, int hoursWorked) : Employee(name, hoursWorked) {}
    int getSalary()
    {
        return Employee::getSalary();
    }
    void Sue()
    {
        cout << Employee::getName() << " can Sue" << endl;
    }
};
class Marketers : public Employee
{

public:
    Marketers(string name, int hoursWorked) : Employee(name, hoursWorked) {}
    void Advertise()
    {
        cout << Employee::getName() << " can advertise" << endl;
    }
    int extraPayMArketers()
    {
        return 10000;
    }
    int getSalary()
    {
        return Employee::getSalary() + extraPayMArketers();
    }
};
class Secrataries : public Employee
{
protected:
    int vacationDaysTaken;
    int vacationPay;

public:
    Secrataries(string name, int hoursWorked, int vacationDaysTaken) : Employee(name, hoursWorked), vacationDaysTaken(vacationDaysTaken) {}
    int getSalary()
    {
        return Employee::getSalary();
    }
    void Dictation()
    {
        cout << Employee::getName() << " knows how to take dictation" << endl;
    }
    int leaves_encashment()
    {
        int remainingDays = 10 - vacationDaysTaken;
        return remainingDays * (vacationPay / 10);
    }
};
class LegalSecratary : public Employee
{
public:
    LegalSecratary(string name, int hoursWorked) : Employee(name, hoursWorked) {}
    int extraPaysecretaries()
    {
        return 5000;
    }
    int getSalary()
    {
        return Employee::getSalary() + extraPaysecretaries();
    }
    void LegalDocuments()
    {
        cout << Employee::getName() << " knows how to prepare Legal Documents" << endl;
    }
};
int main()
{
    Lawyers L("lash", 3);
    Marketers M("alksn", 4);
    Secrataries S("niga", 5, 4);
    LegalSecratary LS("ash", 2);

    L.Sue();
    cout << "Salary: " << L.getSalary() << endl;

    M.Advertise();
    cout << "Salary: " << M.getSalary()<< endl;
    

    S.Dictation();
    cout << "Salary: " << S.getSalary() << "   ";
   cout << "Enchasment Leaves: " << S.leaves_encashment() << endl;

   LS.LegalDocuments();
   cout << "Salary: " << LS.getSalary();



    return 0;
}