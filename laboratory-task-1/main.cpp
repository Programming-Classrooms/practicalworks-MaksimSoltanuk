/*
  Вычислить приближённое значение функции, используя представление ее в виде ряда 
  Тейлора. Вычисления заканчивать, когда очередное слагаемое окажется по модулю 
  меньше заданного числа e, где 0 < e < 10-k,
    k – натуральное число, k > 1. Сравнить 
  полученный результат со значением, вычисленным с помощью стандартных функций. 
  Значение x и e ввести по запросу.

  Вариант 14.
*/


#define _USE_MATH_DEFINES
#include<iostream>
#include<cmath>
#include<iomanip>


long double calculatArctangent(int32_t, int32_t, int32_t);

int main() {
  try {
    int32_t x{}, eps{}, num{ 1 };

    std::cout << "Enter x = ";
    std::cin >> x;
    if (x < 1) 
    {
      throw std::exception("x must be a natural number\n"); 
    }

    std::cout << "Enter eps = ";
    std::cin >> eps;
    if (eps < 1)
    {
      throw std::exception("eps must be a natural number\n");
    }

    std::cout << "arctg(x)= " << atan(x) << '    ' << "\ncalculated by hand = " << std::setprecision(15) << calculatArctangent(eps, x, num) << '\n';
  }
  catch (const std::exception& is) {
    std::cout << is.what();
  }
  return 0;
}

long double calculatArctangent(int32_t eps, int32_t x, int32_t num)
{
  long double firstElement = 0.0, s = M_PI / 2;
  long double epsilon = 1.0;

  for (size_t i = 0; i < eps; ++i)
  {
    epsilon /= 10;
  }

  firstElement = -1.0 / x;
  while (fabs(firstElement) >= epsilon) {
    s += firstElement;
    firstElement = -firstElement * (2 * num - 1) / ((2 * num + 1) * x * x);
    ++num;
  }
  return s;
}
