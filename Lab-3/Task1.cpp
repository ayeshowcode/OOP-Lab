#include <iostream>
using namespace std;
class Matrix
{
private:
    int rows;
    int cols;
    int elements[2][2];

public:
    void setElement(int i, int j, int value)
    {
        elements[i][j] = value;
    }
    void Add(Matrix M2)
    {
        Matrix add;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                add.elements[i][j] = elements[i][j] + M2.elements[i][j];
            }
        }
        cout << "THE ADDITION OF TWO MATRIX IS: " << endl;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cout << elements[i][j] << " ";
            }
            cout << endl;
        }
    }
    void Multiply(Matrix M2)
    {
        Matrix Mult;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                Mult.elements[i][j] = 0;
                for (int k = 0; k < 2; k++)
                {
                    Mult.elements[i][j] += elements[i][k] * M2.elements[k][j];
                }
            }
        }
        cout << "THE MULTIPLICATION OF TWO MATRIX IS:" << endl;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cout << Mult.elements[i][j] << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    Matrix M1, M2;
    M1.setElement(0, 0, 1);
    M1.setElement(0, 1, 2);
    M1.setElement(1, 0, 3);
    M1.setElement(1, 1, 4);

    M2.setElement(0, 0, 5);
    M2.setElement(0, 1, 6);
    M2.setElement(1, 0, 7);
    M2.setElement(1, 1, 8);

    M1.Add(M2);
    M1.Multiply(M2);
    return 0;
}