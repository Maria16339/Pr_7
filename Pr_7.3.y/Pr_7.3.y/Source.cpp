#include <iostream>
int multRow(int arr[], int size);
void inputMatrix(int** arr, int row, int column);
void showMatrix(int** arr, int row, int column);

const int row = 4;
const int column = 3;

int main()
{
    int** matrix = new int* [row];
    for (int i = 0; i < row; i++)
        matrix[i] = new int[column];

    inputMatrix(matrix, row, column);
    showMatrix(matrix, row, column);

    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
        {
            if (matrix[i][j] < 0)
                break;
            else if (j + 1 == column)
            {
                int result = multRow(matrix[i], column);
                std::cout << "Row ¹" << i + 1 << ". Value = " << result << std::endl;
            }
        }

    return 0;
}

int multRow(int arr[], int size)
{
    int result = arr[0];
    for (int i = 1; i < size; i++)
        result *= arr[i];
    return result;
}

void inputMatrix(int** arr, int row, int column)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
        {
            std::cout << "Enter the element ¹[" << i << "][" << j << "]: ";
            std::cin >> arr[i][j];
            std::cout << std::endl;
        }
}

void showMatrix(int** arr, int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
