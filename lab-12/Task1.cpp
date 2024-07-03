#include <iostream>
#include <string>
using namespace std;
class User
{
protected:
    string user_id;
    string username;
    string password;

public:
    User(const string &uid, const string &uname, const string &pwd)
        : user_id(uid), username(uname), password(pwd) {}

    virtual void login() = 0;
    virtual void logout() = 0;
};

class Course
{
public:
    string course_code;
    string description;
    string section;
    Course(const string &code = "", const string &desc = "", const string &sec = "")
        : course_code(code), description(desc), section(sec) {}
};

class Student : public User
{
    static const int MAX_COURSES = 10;
    Course courses[MAX_COURSES];
    int course_count;

public:
    Student(const string &uid, const string &uname, const string &pwd)
        : User(uid, uname, pwd), course_count(0) {}

    void login() override
    {
        cout << "Student " << username << " logged in.\n";
    }

    void logout() override
    {
        cout << "Student " << username << " logged out.\n";
    }

    void add_course(const Course &course)
    {
        if (course_count < MAX_COURSES)
        {
            courses[course_count++] = course;
            cout << "Course " << course.course_code << " added to " << username << "'s profile.\n";
        }
        else
        {
            cout << "Maximum course limit reached.\n";
        }
    }

    string get_username() const
    {
        return username;
    }

    const Course *get_courses() const
    {
        return courses;
    }

    int get_course_count() const
    {
        return course_count;
    }
};

class Advisor : public User
{
public:
    Advisor(const string &uid, const string &uname, const string &pwd)
        : User(uid, uname, pwd) {}

    void login() override
    {
        cout << "Advisor " << username << " logged in.\n";
    }

    void logout() override
    {
        cout << "Advisor " << username << " logged out.\n";
    }

    void approve_course(Student &student, const Course &course)
    {
        student.add_course(course);
        cout << "Course " << course.course_code << " approved for " << student.get_username() << ".\n";
    }
};

class Registrar : public User
{
public:
    Registrar(const string &uid, const string &uname, const string &pwd)
        : User(uid, uname, pwd) {}

    void login() override
    {
        cout << "Registrar " << username << " logged in.\n";
    }

    void logout() override
    {
        cout << "Registrar " << username << " logged out.\n";
    }

    void generate_bill_report(const Student &student)
    {
        cout << "Billing Report for " << student.get_username() << ":\n";
        for (int i = 0; i < student.get_course_count(); ++i)
        {
            cout << " - " << student.get_courses()[i].course_code << "\n";
        }
    }
};

int main()
{
    Student john("001", "ayesh", "onthn");
    Advisor jane("002", "notayesh", "nhtna");
    Registrar admin("003", "ayesha", "pas");

    Course cs101("CS1002", "Intro to Computer Science", "A");
    Course ma101("MT1001", "Calculus I", "B");

    john.login();
    jane.login();
    jane.approve_course(john, cs101);
    jane.approve_course(john, ma101);
    admin.login();
    admin.generate_bill_report(john);

    john.logout();
    jane.logout();
    admin.logout();

    return 0;
}