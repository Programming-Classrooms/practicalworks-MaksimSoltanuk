/*
    Написать программу, которая для заданного натурального числа N
    находит, не превышающие это число: все числа Армстронга.
    Числа Амстронга - числа, которые при сложение каждой чифры числа в степениб соответсвующей количеству цифр в числе, дают само число.
*/


#include <iostream>    
#include <cmath>


int32_t countAmstrongNumber(uint32_t, uint32_t, uint32_t, double, int32_t);
uint32_t otputArray(uint32_t, uint32_t, uint32_t, double, int32_t, uint32_t*&);

int main()
{
    uint32_t figure = 0, singleNumber = 0, num = 0;
    double degree = 10;
    int32_t count = 0;
    uint32_t* arrayForOutput = new uint32_t[countAmstrongNumber(num, singleNumber, figure, degree, count)];
    std::cout << "Enter number = ";
    std::cin >> num;
    if (num < 1)
    {
        std::cout << "Number must be a naturale digit\n";
    }
    otputArray(num, singleNumber, figure, degree, count, arrayForOutput);
    for (size_t i = 0; i < countAmstrongNumber(num, singleNumber, figure, degree, count); ++i)
    {
        std::cout << arrayForOutput[i] << "  It's Amstrong number\n";
    }
    delete[]arrayForOutput;
    return 0;
}

int32_t countAmstrongNumber(uint32_t num, uint32_t singleNumber, uint32_t figure, double degree, int32_t count)
{
    uint32_t copy1 = 0, copy2 = 0;
    uint32_t sum = 0, size = 10;
    remakeArray:
    count = 0;
    uint32_t* arr = new uint32_t[size];
    for (size_t i = 1; i < num; ++i)
    {
        copy1 = copy2 = i;
        while (copy1)
        {
            copy1 /= 10;
            ++figure;
        }
        singleNumber = pow(degree, figure - 1);
        while (copy2)
        {
            sum += pow((double)(copy2 / singleNumber), figure);
            copy2 %= singleNumber;
            singleNumber /= 10;
        }
        if (sum == i)
        {
            if (count == size)
            {
                delete[]arr;
                size += sqrt(size);
                goto remakeArray;
            }
            arr[count++] = i;
        }
        figure = 0;
        sum = 0;
    }
    delete[]arr;
    return size;
}

uint32_t otputArray(uint32_t num, uint32_t singleNumber, uint32_t figure, double degree, int32_t count, uint32_t*& arrayForOutput)
{
    uint32_t copy1 = 0, copy2 = 0;
    uint32_t sum = 0;
    count = -1;
    for (size_t i = 1; i < num; ++i)
    {
        copy1 = copy2 = i;
        while (copy1)
        {
            copy1 /= 10;
            ++figure;
        }
        singleNumber = pow(degree, figure - 1);
        while (copy2)
        {
            sum += pow((double)(copy2 / singleNumber), figure);
            copy2 %= singleNumber;
            singleNumber /= 10;
        }
        if (sum == i)
        {
                arrayForOutput[++count] = i;
        }
        figure = 0;
        sum = 0;
    }
    return *arrayForOutput;
}
