/*
    Написать программу, которая для заданного натурального числа N
    находит, не превышающие это число: числа близнецы;
*/


#include <iostream> 
#include <cmath>


void twins(uint32_t, uint32_t, uint32_t);

int main()
{
    uint32_t count = 0, prime1 = 0, prime2 = 10;;
    while (count < 1)
    {
        std::cout << "Input count = ";
        std::cin >> count;
    }
    twins(count, prime1, prime2);
    return 0;
}

void twins(uint32_t count, uint32_t prime1, uint32_t prime2)
{
    for (int i = 2; count; ++i)
    {
        bool isPrime = true;
        for (int j = 2; j <= sqrt(i); ++j)
        {
            if (!(i % j))
            {
                isPrime = false;
            }
        }
        if (isPrime)
        {
            if (prime1)
            {
                prime2 = prime1;
            }
            prime1 = i;
            if (prime1 - prime2 == 2)
            {
                std::cout << prime2 << " " << prime1 << '\n';
                --count;
            }
        }
    }
}
