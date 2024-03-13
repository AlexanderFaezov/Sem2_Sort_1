#include <iostream>
using namespace std;
int n;

void CountingSort(int* A)
{
    int min = A[0];
    int max = A[0];
    int p = 0;

    for (int i = 0; i < n; i++)
    {
        if (A[i] < min)
            min = A[i];
        if (A[i] > max)
            max = A[i];
    }
    int* c = new int[n];

    for (int i = 0; i < n; i++)
    {
        c[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        c[A[i] - min]++;
    }for (int i = 0; i < n; i++)
    {
        if (c[i] > 0)
        {
            for (int j = 0; j < c[i]; j++)
            {
                A[p] = i + min;
                p++;
            }
        }
    }
    delete c;
}

int main()
{
    setlocale(LC_ALL, "ru");
    int* A = new int[100];
    cout << "Размер массива: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "элемент: ";
        cin >> A[i];
    }
    CountingSort(A);
    cout << "Упорядоченный массив: ";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}