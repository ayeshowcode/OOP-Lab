#include <iostream>
using namespace std;
int main()
{
    int arr[5];
    cout << "Enter the 5 numbers: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += arr[i];
    }
    cout << "Sum: " << sum << endl;
    cout << "Average: " << sum / 5 << endl;

    int max = arr[0];
    for (int i = 0; i < 5; i++)
    {

        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    cout << "MAX : " << max << endl;

    int min = arr[0];
    for (int i = 0; i < 5; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    cout << "MIN : " << min << endl;
    return 0;
}