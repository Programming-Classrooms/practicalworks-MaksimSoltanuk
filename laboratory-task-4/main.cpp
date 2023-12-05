/*
При решении следующих задач использовать динамический массив. При
необходимости заполнения массива предусмотреть два способа: ввод с клавиатуры и
заполнение с помощью датчика случайных чисел. В последнем случае перед заполнением
массива ввести границы интервала, которому должны принадлежать элементы массива.
Вывести результаты расчетов. Если по каким-либо причинам решение задачи
невозможно, вывести соответствующее сообщение.

Заполнить квадратную матрицу последовательными натуральными числами,
расположенными по спирали, начиная с центра и продвигаясь по часовой стрелке.
Первый ход – вверх. Например:
25 10 11 12 13
24  9  2  3 14
23  8  1  4 15
22  7  6  5 16
21 20 19 18 17
Подсчитать сумму элементов правого нижнего треугольника.
*/


#include <iostream>
#include <iomanip>


void moveMatrix(uint32_t**, uint32_t);
void outputMatrix(uint32_t**, uint32_t);
uint32_t countRightTriangle(uint32_t** matrix, uint32_t size, int32_t j, uint32_t&);
void mtrxMemoryFree(uint32_t** matrix, uint32_t size);


void main()
{
    try
    {
        uint32_t sum = 0, size = 0;
        int32_t j = 0;
        std::cout << "Size of matrix? ";
        std::cin >> size;

        if (size % 2 == 0)
        {
            throw std::exception("The number must be odd number!");
        }

        uint32_t** matrix = new uint32_t* [size];
        for (int i = 0; i < size; i++) {
            matrix[i] = new uint32_t[size];
        }

        moveMatrix(matrix, size);
        std::cout << "\nMatrix output:\n";
        outputMatrix(matrix, size);
        countRightTriangle(matrix, size, j, sum);
        std::cout << "\nThe sum of the lower right triangle is " << sum << "\n";
        mtrxMemoryFree(matrix, size);

        throw std::string();
    }
    catch (const std::exception&is)
    { 
        std::cout << is.what();
    }
    catch (const std::string& isa)
    {
        void deleteMatrix(int**, int);
    }     
}

void moveMatrix(uint32_t** matrix, uint32_t size) {
    uint32_t number = 1, step = 0;
    uint32_t startRow = size / 2;
    uint32_t startCol = size / 2;
    matrix[startRow][startCol] = number;
    for (uint32_t step = 1; step < size; step += 2) {

        for (uint32_t i = 0; i < step; ++i) {
            matrix[--startRow][startCol] = ++number;
        }

        for (uint32_t i = 0; i < step; ++i) {
            matrix[startRow][++startCol] = ++number;
        }

        for (uint32_t i = 0; i < step + 1; ++i) {
            matrix[++startRow][startCol] = ++number;
        }

        for (uint32_t i = 0; i < step + 1; ++i) {
            matrix[startRow][--startCol] = ++number;
        }
    }
    for (uint32_t i = startRow; i > 0; i--) {
        matrix[--startRow][startCol] = ++number;
    }
}

void outputMatrix(uint32_t** matrix, uint32_t size) {
    for (uint32_t i = 0; i < size; i++)
    {
        for (uint32_t j = 0; j < size - 1; j++)
        {
            std::cout << matrix[i][j] << std::setw(5);
        }
        std::cout << matrix[i][size - 1] << "\n";
    }
}

uint32_t countRightTriangle(uint32_t** matrix, uint32_t size, int32_t j, uint32_t& sum) {
    int32_t position = 0;
    for (int32_t i = size - 1; i >= 0; i--)
    {
        j = position;
        for (int32_t j = position; j < size; j++)
            sum += matrix[i][j];
        ++position;
    }
    return sum;
}

void mtrxMemoryFree(uint32_t** matrix, uint32_t size) {
    for (uint32_t i = 0; i < size; i++) {

        delete[] matrix[i];
    }
    delete[] matrix;
}

