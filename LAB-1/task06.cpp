#include <iostream>
using namespace std;

int main()
{
    int bookCount;
    cout << "Enter the number of books: ";
    cin >> bookCount;
    cin.ignore();

    const int maxTitleLength = 50;
    char **bookTitles = new char *[bookCount];

    for (int i = 0; i < bookCount; i++)
    {
        bookTitles[i] = new char[maxTitleLength];
    }

    for (int i = 0; i < bookCount; i++)
    {
        cout << "Book " << (i + 1) << " title: ";
        cin.getline(bookTitles[i], maxTitleLength);
    }

    cout << "\nBook titles:\n";
    for (int i = 0; i < bookCount; i++)
    {
        cout << i + 1 << ": " << bookTitles[i] << std::endl;
    }

    for (int i = 0; i < bookCount; i++)
    {
        delete[] bookTitles[i];
    }

    delete[] bookTitles;

    return 0;
}
