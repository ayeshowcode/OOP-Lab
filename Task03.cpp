#include <iostream>
using namespace std;
int main()
{
    int arr[10] = {1, 1, 11, 3, 5, 6, 7, 8, 9, 10};
    int flag = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (arr[i] == arr[j])
            {
                flag = 1;
            }
        }
    }
    if (flag){
        cout << "Duplicate has been found!";
    }
    else{
    cout << "Duplicates Not Found";
    }
}