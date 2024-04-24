// According to lab 
//(NEXT)
#include <iostream>
using namespace std;

void NewSeries(int n, int *arr){
    for (int i = 0; i< n-1; i++){
        arr[i]+=arr[i+1];
    }
}
int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int *arr;
    arr = new int[n];

    for (int i = 0; i< n; i++){
        cin >> arr[i];
    }
    NewSeries(n, arr);
    
    for (int i = 0; i< n-1; i++){
        cout << arr[i] << " ";
    }
}
