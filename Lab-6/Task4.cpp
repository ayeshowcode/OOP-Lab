/*

Consider a School Management System. You are required to create two classes, Student and Course. Each student can enroll in multiple courses. The Course class should have the following properties: course code (string), course name (string), and course credit hours (integer).

The Student class should have the following properties: student ID (string), student name (string), and a list of enrolled courses (an array of Course objects).

The Student class should have the following member functions:--------------
A constructor that initializes the student ID and name.
A function named "enroll" that takes a Course object as input and adds it to the list of enrolled
courses for the student.
A function named "drop" that takes a Course object as input and removes it from the list of enrolled
courses for the student.
A function named "getTotalCreditHours" that returns the total number of credit hours for all
courses the student is currently enrolled in.
A function named "printEnrolledCourses" that prints out the course code, name, and credit hours
for all courses the student is currently enrolled in.

*/
#include <iostream>
using namespace std;
class Course
{
    string code;
    string coursename;
    int crdthrs;

public:
    Course() : code(""), coursename(""), crdthrs(0) {}

    Course(string code, string coursename, int crdthrs)
    {
        this->code = code;
        this->coursename = coursename;
        this->crdthrs = crdthrs;
    }
    string getcode()
    {
        return code;
    }
    string getcoursename()
    {
        return coursename;
    }
    int getCreditHours()
    {
        return crdthrs;
    }
    void invalidate()
    {
        code = "";
        coursename = "";
        crdthrs = 0;
    }
};
class Student
{
    int studentid;
    string name;
    Course *courses;

public:
    Student(int studentid, string name)
    {
        this->studentid = studentid;
        this->name = name;
        courses = new Course[5];
    }
    void enroll(Course &c, int i)
    {
        courses[i] = c;
    }
    void drop(string coursecode)
    {
        for (int i = 0; i < 5; i++)
        {
            if (courses[i].getcode() == coursecode)
            {
                courses[i].invalidate();
            }
        }
    }
    int getTotalCredithrs()
    {
        int hours = 0;
        for (int i = 0; i < 5; i++)
        {
            if (courses[i].getcode() != "")
            {
                hours += courses[i].getCreditHours();
            }
        }
        return hours;
    }
    void printdetails()
    {
        cout << "ID: " << studentid << "  "
             << "Name: " << name << endl;
        for (int i = 0; i < 5; i++)
        {
            if (courses[i].getcode() != "")
            {
                cout << i + 1 << " " << courses[i].getcode() << "  " << courses[i].getCreditHours() << "  " << courses[i].getcoursename();
            }
        }
    }
};
int main()
{
    Course c1("CS1001", "Pf", 3);
    Course c2("CS1004", "oop", 3);
    Course c3("CS1008", "ds", 3);
    Student s(1, "ayesh");
    s.enroll(c1, 0);
    s.enroll(c2, 1);
    s.enroll(c3, 2);
    s.drop("CS1004");
    s.printdetails();
    cout << "Total Credit hours: " << s.getTotalCredithrs();
}