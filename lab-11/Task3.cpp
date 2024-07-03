#include <iostream>
#include <string>

using namespace std;

class Course
{
public:
    string courseName;
    string courseCode;
    string courseCreditHours;
    bool Assigned;

    Course(string name, string code, string creditHours)
        : courseName(name), courseCode(code), courseCreditHours(creditHours), Assigned(false) {}

    bool isAssigned() const
    {
        return Assigned;
    }

    void setAssigned(bool status)
    {
        Assigned = status;
    }
};

class Employee
{
public:
    string EmployeeName;
    string EmployeeDesignation;
    string EmployeeDept;
    int EmployeeSalary;

    Employee(string name, string designation, string dept, int sal)
        : EmployeeName(name), EmployeeDesignation(designation), EmployeeDept(dept), EmployeeSalary(sal) {}

    void printSalary() const
    {
        cout << "Salary: " << EmployeeSalary << endl;
    }

    Employee operator++(int)
    {
        Employee temp = *this;
        EmployeeSalary += static_cast<int>(EmployeeSalary * 0.10); // Increase salary by 10%
        return temp;
    }

    int operator+(const Employee &other) const
    {
        return this->EmployeeSalary + other.EmployeeSalary;
    }
};

class Faculty : public Employee
{
    int workingHours;
    Course *courseList[5];
    int assignedCourseCount;
    int totalCreditHours;

public:
    Faculty(string name, string designation, string dept, int sal, int hours)
        : Employee(name, designation, dept, sal), workingHours(hours), assignedCourseCount(0), totalCreditHours(0) {}

    void AssignCourse(Course &newCourse)
    {
        if (assignedCourseCount < 5)
        {
            char deptInitial = EmployeeDept[0];
            if (newCourse.courseCode[0] == deptInitial && !newCourse.isAssigned())
            {
                courseList[assignedCourseCount++] = &newCourse;
                totalCreditHours += stoi(newCourse.courseCreditHours);
                newCourse.setAssigned(true);

                if (totalCreditHours > 12)
                {
                    cout << "Warning: Total assigned credit hours exceed 12." << endl;
                }
            }
            else
            {
                cout << "Course cannot be assigned due to department mismatch or course already assigned." << endl;
            }
        }
        else
        {
            cout << "Faculty member already has the maximum number of assigned courses." << endl;
        }
    }

    Faculty operator++(int)
    {
        Faculty temp = *this;
        EmployeeSalary += static_cast<int>(EmployeeSalary * 0.20); 

        if (EmployeeDesignation == "Instructor")
        {
            EmployeeDesignation = "Assistant Professor";
        }
        else if (EmployeeDesignation == "Lecturer")
        {
            EmployeeDesignation = "Professor";
        }
        return temp;
    }
};

class Staff : public Employee
{
public:
    string areaOfExpertise;

    Staff(string name, string designation, string dept, int sal, string expertise)
        : Employee(name, designation, dept, sal), areaOfExpertise(expertise) {}

    bool Verify(const string &dept) const
    {
        return EmployeeDept == dept;
    }

    bool Verify(int lowRange, int highRange) const
    {
        return EmployeeSalary >= lowRange && EmployeeSalary <= highRange;
    }
};

int main()
{
    Course c1("Introduction to Computing", "CS101", "3");
    Course c2("Object-Oriented Programming", "CS102", "4");

    Faculty faculty1("John Doe", "Professor", "CS", 50000, 38);
    faculty1.AssignCourse(c1);
    faculty1.AssignCourse(c2);

    faculty1.printSalary();

    Staff staff1("Jane Smith", "Technician", "CS", 30000, "Network Maintenance");

    bool deptCheck = staff1.Verify("CS");
    cout << "Staff department match: " << (deptCheck ? "Yes" : "No") << endl;

    bool salaryCheck = staff1.Verify(25000, 35000);
    cout << "Staff salary within range: " << (salaryCheck ? "Yes" : "No") << endl;

    Employee ob1("Ali", "Lecturer", "Electrical Engineering", 150000);
    Employee result = ob1++;
    cout << "Increased Salary (10%): " << result.EmployeeSalary << endl;

    Faculty ob2("Jawed", "Instructor", "Computer Science", 100000, 0);
    ob2++; 

    cout << "Updated Faculty Salary and Designation: " << ob2.EmployeeSalary << ", " << ob2.EmployeeDesignation << endl;

    return 0;
}