#include <iostream>
using namespace std;
#define MAX_DAYS 31 // assume pls
#define MONTHS 12
class Calender
{
private:
    string Tasks[MONTHS][MAX_DAYS];

public:
    void AddTask(string task, int month, int date)
    {
        if (date > MAX_DAYS || month > MONTHS || date < 1 || month < 1)
        {
            cout << "invalid input " << endl;
            return;
        }
        Tasks[month - 1][date - 1] = task;
    }
    void RemoveTask(int month, int date)
    {
        if (date > MAX_DAYS || month > MONTHS || date < 1 || month < 1)
        {
            cout << "invalid input " << endl;
            return;
        }
        Tasks[month - 1][date - 1] = "";
    }
    void showTasks()
    {
        for (int i = 0; i < MONTHS; i++)
        {
            cout << "Tasks for the month: " << i + 1 << endl;
            for (int j = 0; j < MAX_DAYS; j++)
            {
                if (Tasks[i][j] != "")
                    cout << "Date: " << j + 1 << " " << Tasks[i][j]  << "    ";
            }
            cout << endl << endl;
        }
    }
};
int main()
{
    Calender c;
    c.AddTask("Cricket Match", 5, 6);
    c.AddTask("Bussiness Meeting", 9, 1);
    c.AddTask("Run", 12, 31);
    c.AddTask("Trip to America", 9, 11);
    c.AddTask("go to gym" , 1, 1);
    c.AddTask("sleep" , 1, 2);

    c.RemoveTask(9,1);
    c.RemoveTask(12,31);

    c.showTasks();
    return 0;
}