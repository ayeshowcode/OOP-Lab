#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
    int const students = 3;
    int const subjects = 6;

    int arr[students][subjects];
    for (int i = 0; i < students; i++)
    {
        cout << "Student : " << i + 1 << endl;
        for (int j = 0; j < subjects; j++)
        {
            cout << "Enter the marks of subject: " << j + 1 << "  ";
            cin >> arr[i][j];
              if (arr[i][j] > 100 || arr[i][j] < 0){
                cout << "please enter the marks between 0 and 100" << endl;
                j--;
                continue;
              }
        }
    }
    double obtmarks = 0;
    char Grade;
    for (int i = 0; i < students; i++)
    {
        obtmarks = 0;
        for (int j = 0; j < subjects; j++)
        {
            obtmarks += arr[i][j];
        }
        double percentage = obtmarks / 600 * 100;
        cout << "student: " << i + 1 << "" << percentage << "%" << endl;
        if (percentage >= 90 && percentage <= 100)
        {
            Grade = 'A';
        }
        else if (percentage >= 80 && percentage < 90)
        {
            Grade = 'B';
        }
        else if (percentage >= 70 && percentage < 80)
        {
            Grade = 'C';
        }
        else if (percentage >= 60 && percentage < 70)
        {
            Grade = 'D';
        }
        else if (percentage < 60 && percentage >= 0)
        {
            Grade = 'F';
        }
        cout << "Grade: " << Grade << endl;
    }
}