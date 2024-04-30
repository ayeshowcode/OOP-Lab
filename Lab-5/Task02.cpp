#include <iostream>
using namespace std;
class Number
{
    int num;
    int result;

public:
    Number(int num)
    {
        this->num = num;
    }
    int isWhole()
    {
        if (num >= 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int isPositive()
    {
        if (num > 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void Factorial()
    {
        int temnum = num;
        result = 1;
        while (temnum > 0)
        {
            result *= temnum;
            temnum--;
        }
    }
    void display()
    {
        cout << "Factorial of " << num;
        cout << " is: " << result;
    }
};
int main()
{
    Number n(5);
    if (n.isWhole() && n.isPositive())
        n.Factorial();
    else cout << "The Number is not whole/positive number";
    n.display();
}