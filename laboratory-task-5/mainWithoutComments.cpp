/*
  Вычислить значение определенного интеграла с аналитически заданной подынтегральной
  функцией с заданной точностью eps.

  Б) по формуле правых прямоугольников;
  Г) по формуле трапеций;

  где n–число точек деления отрезка [a, b]. Для вычисления первого приближения можно взять
  n=4. Чтобы оценить точность, с которой вычислено значение интеграла, необходимо найти второе
  приближение. Для этого можно увеличить n в два раза. Если s 1 и s 2 – два соседних приближения и |s 1
  – s 2 |&lt;eps, то точность считается достигнутой и s 2 принимается за искомое значение интеграла. В
  противном случае надо положить s 1 = s 2 и удвоить число точек деления отрезка [a, b]. После этого
  вычисляется новое значение s 2 . Процесс удвоения n и вычисления s 2 надо продолжать до тех пор,
  пока модуль разности s 1 и s 2 не станет меньше eps. Остальные формулы посмотреть самим.
  Разработать функции, реализующие методы вычислений интеграла, входными параметрами
  которых должны быть функция для вычисления значения подынтегрального выражения, пределы
  интегрирования и точность вычислений. Головная программа должна вывести результат вычислений
  для записанных в задании интегралов по заданным формулам и значение n, при котором достигнута
  заданная точность. Для проверки вычислений в таблице приведены значения интегралов.
  Номер задания равен вашему индивидуальному номеру.
*/

#include <iostream>
#include <cmath>


double FirstFunction(double); 
double SecondFunction(double); 
double ThirdFunction(double); 
double accuracyEps(); 
void righRectanglesMethod(double (*f)(double), double, double, double); 
void rectangularTrapezoidMethod(double (*f)(double), double, double, double); 
void twoMetods(double (*f)(double), const double&, const double&, const double&); 

int main()
{
  try
  {
    long double eps = accuracyEps(); 
    if (eps < 0.000000001)
    {
      throw std::exception("The accuracy is too high, your computer may be kaput!");
    }

    std::cout << "\nFirst function:\n";
    twoMetods(FirstFunction, 0, 1, eps); 
    std::cout << "\nSecond function:\n";
    twoMetods(SecondFunction, 1, 2, eps); 
    std::cout << "\nThird function:\n";
    twoMetods(ThirdFunction, 1, 2, eps); 

  }
  catch (const std::exception& is)
  {
    std::cout << is.what();
  }
  return 0;
}

double FirstFunction(double x)
{
  return 1 / (1 + x * x * x);
}

double SecondFunction(double x)
{
  return x * log(x);
}

double ThirdFunction(double x)
{
  return log(x) / x;
}

double accuracyEps() 
{
  long double accuracy;
  std::cout << "Input accuracy: ";
  std::cin >> accuracy;
  while (accuracy <= 0 || accuracy > 1)
  {
    std::cout << "Enter the accuracy from 0 to 1.\n";
    std::cin >> accuracy;
  }
  return accuracy;
}

void righRectanglesMethod(double (*f)(double), double a, double b, double eps)
{
  uint32_t n = 4; 
  long double h = (b - a) / n, s1 = 0, s2 = 0; 

  for (size_t step = 1; step <= n; ++step) 
  {
    s2 += h * f(a + h * step);  
  }
  while (abs(s1 - s2) > eps) 
  {
    s1 = s2; 
    s2 = 0; 
    n *= 2; h /= 2; 
    for (size_t step = 1; step <= n; ++step)
    {
      s2 += h * f(a + h * step); 
    }
  }

  std::cout << "Counting by the method of right rectangles: " << s2 << "\nNumber of sections: " << n << '\n';
}

void rectangularTrapezoidMethod(double (*f)(double), double a, double b, double eps)
{
  uint32_t n = 4; 
  long double h = (b - a) / n, s1 = 0, s2 = 0;

  for (size_t step = 1; step < n; ++step)
  { 
    s2 += h * (f(a + h * (step - 1)) + f(a + h * step)) / 2; 
  }

  while (abs(s1 - s2) > eps) 
  {
    s1 = s2; 
    n *= 2; h /= 2; 
    s2 = h * ((f(a) + f(b)) / 2); 
    for (size_t step = 1; step < n; ++step)
    {
      s2 += h * (f(a + h * (step - 1)) + f(a + h * step)) / 2; 
    }
  }

  std::cout << "Calculation using the rectangular trapezoid method: " << s2 << "\nNumber of sections: " << n << "\n";
}

void twoMetods(double (*f)(double), const double& a, const double& b, const double& eps) 
{
  righRectanglesMethod((*f), a, b, eps);
  rectangularTrapezoidMethod((*f), a, b, eps);
}