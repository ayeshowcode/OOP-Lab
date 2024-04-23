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
    int newsize;
    cout << "Enter the new size: ";
    cin >> newsize;
    int *newarr;
    newarr = new int[newsize];

    for (int i = 0; i < n; i++)
    {
        newarr[i] = arr[i];
    }
    delete[] arr;
    cout << "Enter the new elements: ";
    for (int i = n; i < newsize; i++)
    {
        cin >> newarr[i];
    }
    for (int i = 0; i < newsize; i++)
    {
        cout << newarr[i] << " ";
    }
    delete[] newarr;
    return 0;
}