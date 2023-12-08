/*
    Написать программу, которая для заданного натурального числа N
    находит, не превышающие это число: все числа Армстронга
*/


#include <iostream>    
#include <cmath>


void searchAmstrongNumber(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, double, uint32_t);

int main()
{
    uint32_t figure{}, sum{}, num{};
    double degree = 10;
    uint32_t copy1{}, copy2{}, singleNumber{};
    std::cout << "Enter number = ";
    std::cin >> num;
    if (num<1)
    {
        std::cout << "Number must be a naturale digit\n";
    }
    searchAmstrongNumber(num, copy1, copy2, singleNumber, figure, degree, sum);
    return 0;
}

void searchAmstrongNumber(uint32_t num, uint32_t copy1, uint32_t copy2, uint32_t singleNumber, uint32_t figure, double degree, uint32_t sum)
{
    for (size_t i = 1; i < num; i++)
    {
        copy1 = copy2 = i;
        while (copy1)
        {
            copy1 /= 10;
            figure++;
        }
        singleNumber = pow(degree, figure - 1);
        while (copy2)
        {
            sum += pow((double)(copy2 / singleNumber), figure);
            copy2 %= singleNumber;
            singleNumber /= 10;
        }

        if (sum == i)
            std::cout << i << "   It is Armstrong number " << '\n';
        figure = 0;
        sum = 0;
    }
} 
