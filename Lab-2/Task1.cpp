#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    int temp = num;
    int count = 0;

    int storedigit[100];
    for (int i = 0; i < 100; i++)
    {
        storedigit[i] = temp % 10;
        temp = temp / 10;
        count++;
        if (temp == 0)
        {
            break;
        }
    }
    int sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += pow(storedigit[i], count);
    }
    if (num == sum)
    {
        cout << "The sum is:  " << sum << endl;
        cout << "Hence, it is a Armstrong number";
    }
    else
    {
        cout << "The sum is:  " << sum << endl;
        cout << "Hence, it is not an Armstrong number";
    }
}