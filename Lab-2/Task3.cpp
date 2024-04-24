#include <iostream>
using namespace std;
void printReverse(char *arr)
{
    for (int i = 0; i < 5 / 2; i++)
    {
        char temp;
        temp = arr[i];
        arr[i] = arr[5 - i - 1];
        arr[5 - i - 1] = temp;
    }
}
int main()
{
    char arr[5] = {'c', 's', 'a', '1', '2'};
    printReverse(arr);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
}