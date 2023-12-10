/*
    Написать программу, которая для заданного натурального числа N
    находит, не превышающие это число: все числа Армстронга.
    Числа Амстронга - числа, которые при сложение каждой чифры числа в степениб соответсвующей количеству цифр в числе, дают само число.
*/


#include <iostream>    
#include <cmath>


int32_t countAmstrongNumber(uint32_t, uint32_t, uint32_t, double, int32_t, uint32_t);
void remakeArray(uint32_t&, uint32_t, uint32_t, uint32_t, double, int32_t);
uint32_t outputArray(uint32_t, uint32_t, uint32_t, double, int32_t, uint32_t*&);

int main()
{
    uint32_t figure = 0, oneDigit = 0, num = 0, size = 10;
    double degree = 10;
    int32_t count = 0;
    std::cout << "Enter number = ";
    std::cin >> num;
    uint32_t sizeForArray = countAmstrongNumber(num, oneDigit, figure, degree, count, size);
    uint32_t* arrayForOutput = new uint32_t[sizeForArray];
    if (num < 1)
    {
        std::cout << "Number must be a naturale digit\n";
    }
    outputArray(num, oneDigit, figure, degree, count, arrayForOutput);
    for (size_t i = 0; i < sizeForArray; ++i)
    {
        std::cout << arrayForOutput[i] << "  It's Amstrong number\n";
    }
    delete[] arrayForOutput;
    return 0;
}

int32_t countAmstrongNumber(uint32_t num, uint32_t oneDigit, uint32_t figure, double degree, int32_t count, uint32_t size)
{
    uint32_t copy1 = 0, copy2 = 0, sum = 0;
    count = 0;
    for (size_t i = 1; i < num; ++i)
    {
        copy1 = i;
        copy2 = i;
        while (copy1)
        {
            copy1 /= 10;
            ++figure;
        }
        oneDigit = pow(degree, figure - 1);
        while (copy2)
        {
            sum += pow((double)(copy2 / oneDigit), figure);
            copy2 %= oneDigit;
            oneDigit /= 10;
        }
        if (sum == i)
        {
            if (count == size)
            {
                remakeArray(size, num, oneDigit, figure, degree, count);
            }
            count++;
        }
        figure = 0;
        sum = 0;
    }
    return count;
}

void remakeArray(uint32_t& size, uint32_t num, uint32_t oneDigit, uint32_t figure, double degree, int32_t count)
{
    size += sqrt(size);
    countAmstrongNumber(num, oneDigit, figure, degree, count, size);
}

uint32_t outputArray(uint32_t num, uint32_t oneDigit, uint32_t figure, double degree, int32_t count, uint32_t*& arrayForOutput)
{
    uint32_t copy1 = 0, copy2 = 0, sum = 0;
    count = 0;
    for (size_t i = 1; i < num; ++i)
    {
        copy1 = i;
        copy2 = i;
        while (copy1)
        {
            copy1 /= 10;
            ++figure;
        }
        oneDigit = pow(degree, figure - 1);
        while (copy2)
        {
            sum += pow((double)(copy2 / oneDigit), figure);
            copy2 %= oneDigit;
            oneDigit /= 10;
        }
        if (sum == i)
        {
                arrayForOutput[count++] = i;
        }
        figure = 0;
        sum = 0;
    }
    return *arrayForOutput;
}

