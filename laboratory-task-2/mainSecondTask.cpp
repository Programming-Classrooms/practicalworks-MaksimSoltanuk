/*
    Написать программу, которая для заданного натурального числа:
    добавляет в запись числа слева и справа центральную цифру,
    если число содержит нечётное количество цифр и не изменяет
    число в противном случае;
*/


#include <iostream> 
#include <cmath>


void searchNumberInTheMiddle(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);

int main()
{
    uint32_t numberOfDigits = 0, number = 0, requiredFigure = 0, result = 0;
    uint32_t  copy1 = 0, copy2 = 0, copy3 = 0;

    std::cout << "Enter number = ";
    std::cin >> number;
    if (number < 1)
    {
            std::cerr << "The wrong number" << '\n';
    }
    else 
    {
        searchNumberInTheMiddle(copy1, copy2, copy3, number, numberOfDigits, requiredFigure, result);
    }
    return 0;
}

void searchNumberInTheMiddle(
    uint32_t copy1,
    uint32_t copy2,
    uint32_t copy3,
    uint32_t number,
    uint32_t numberOfDigits,
    uint32_t requiredFigure,
    uint32_t result
)
{
    copy2 = copy1 = number;
    copy2 *= 10;
    while (copy1)
    {
        copy1 /= 10;
        ++numberOfDigits;
    }
    if (numberOfDigits % 2 == 0)
    {
        std::cout << "The number has no central digit\n";
    }
    else
    {
        while (numberOfDigits / 2 >= copy3)
        {
            copy2 /= 10;
            requiredFigure = copy2;
            requiredFigure %= 10;
            ++copy3;
        }
        result = ((requiredFigure * pow(10, numberOfDigits) + number) * 10 + requiredFigure);
        std::cout << result;
    }
}
