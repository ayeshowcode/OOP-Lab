#include <iostream>
using namespace std;

void Ascending(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int *findPairs(int *pairsInteger, int size, int key, int &pairCount)
{
    Ascending(pairsInteger, size);

    int *result = new int[size];
    pairCount = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (pairsInteger[i] + pairsInteger[j] == key)
            {
                result[pairCount++] = pairsInteger[i];
                result[pairCount++] = pairsInteger[j];
                break;
            }
        }
    }
    return result;
}
int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int *pairsInteger = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> pairsInteger[i];
    }
    int key;
    cout << "Enter the number to find pairs in the array with an equal sum: ";
    cin >> key;
    int pairCount = 0;

    int *pairs = findPairs(pairsInteger, n, key, pairCount);
    cout << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "The sum of the pairs whose sum equals to " << key << " in the array [ ";
    for (int i = 0; i < n; i++)
    {
        cout << pairsInteger[i] << " ";
    }
    cout << "] is: " << endl;

    for (int i = 0; i < pairCount; i += 2)
    {
        cout << "[" << pairs[i] << "," << pairs[i + 1] << "]  ";
    }
    delete[] pairs;
}