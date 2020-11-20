
#include <iostream>
#include <clocale>
#include <cmath>
#include <iomanip>
#include <ctime>
using namespace std;
int main()
{
    srand((unsigned)time(NULL));
    setlocale(LC_ALL, "Russian");

    int x, y;
    cout << "¬ведите кол-во строк  в массиве  : ";
    cin >> x;
    cout << "¬ведите кол-во столбцов в массиве: ";
    cin >> y ;
    cout << y << endl;

    int** mat = new int* [x];
    for (int i = 0; i < x; i++)
        mat[i] = new int[y];

    cout << "ѕервоначальный массив: " << endl;
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            mat[i][j] = rand() % 21 - 10;

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
            cout << setw(3) << mat[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < x; i++)
    {
        int k = 1;
        for (int j = 0; j < y; j++)
        {
            if (mat[i][j] < 0)
                mat[i][j] *= 1;
            else
                k *= mat[i][j];
        }
        cout << "произведение на строке " << i + 1 << " равна = " << k << endl;
    }

    // ищем макс. сумму на диагонал€х, начина€ с правого верхнего угла
    int* ar = new int[2 * x - 1]{ 0 };

    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            ar[i + j] += mat[i][x - 1 - j];

    int maxidx = 0;
    for (int i = 1; i < x * 2 - 1; i++)
        if (ar[i] > ar[maxidx])
            maxidx = i;

    cout << "\nдиагональ: " << maxidx + 1;
    cout << "\nмакс. сум: " << ar[maxidx];

    delete[] ar;
    for (int i = 0; i < x; i++)
        delete[]mat[i];
    delete[]mat;

    return 0;
}