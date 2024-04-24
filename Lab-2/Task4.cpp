#include <iostream>
#include<ctype.h>

using namespace std;
int Check(string str1, string str2)
{
    int flag=0;
    if (str1.length() == str2.length())
    {
        for (int i = 0; i < str1.length(); i++)
        {
            if (tolower(str1.at(i)) == tolower(str2.at(i)))
            {
              flag = 1;
            }
        }
    }
    return flag;
}
int main()
{
    string str1;
    cout << "Enter the string : ";
    cin >> str1;

    string str2;
    cout << "Enter the string : ";
    cin >> str2;

    if(Check(str1, str2)){
        cout << "True";
    }
    else {
        cout << "False";
    }
}