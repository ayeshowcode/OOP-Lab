#include <iostream>
#include <string>

using namespace std;
class Book
{
private:
    int BookNo;
    string BookTitle;
    float price;
    float TotalCost(int N)
    {
        float totalcost = N * price;
        return totalcost;
    }

public:
    void Input()
    {
        cout << "Enter the Book No: ";
        cin >> BookNo;
        cin.ignore();
        cout << "Enter the Book Title: ";
        getline(cin, BookTitle);
        cout << "Enter the price: ";
        cin >> price;
    }
    void Purchase()
    {
        int N;
        cout << "Enter the no of copies: ";
        cin >> N;
        cout << "Total Price: " << TotalCost(N) << endl;
    }
};
int main()
{
    Book b;
    b.Input();
    b.Purchase();
}