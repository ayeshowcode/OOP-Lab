#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int *arr;
    arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    cout << "Sum: " << sum << endl;
    float Average = sum / n;
    cout << "Average: " << Average << endl;

    int max = arr[0];
    for (int i = 0; i < n; i++)
    {

        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    cout << "MAX : " << max << endl;

    int min = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    cout << "MIN : " << min << endl;
    delete[] arr;
    return 0;
}