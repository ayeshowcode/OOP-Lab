#include <iostream>
using namespace std;
int mod(int m, int n)
{
    if (m < n)
        return m;
    else
        return mod(m - n, n);
}
int main()
{
    int m, n;
    cout << "Enter the dividened: ";
    cin >> m;
    cout << "Enter the divisor: ";
    cin >> n;
    cout << mod(m, n);
}