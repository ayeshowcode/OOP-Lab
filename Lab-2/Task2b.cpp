#include <iostream>
using namespace std;
void NewSeries(int n, int *arr)
{
    for (int i = 1; i < n; i++)
    {
        arr[i] += arr[i - 1];
    }
}
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
    cout << endl;
    cout << "-----------------------"<< endl;
    cout << "Original Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    NewSeries(n, arr);
    cout << "-----------------------"<< endl;
    cout << "Modified Array: ";
    for (int i = 1; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
