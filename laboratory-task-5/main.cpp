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


double FirstFunction(double); // первая функция(математическая)
double SecondFunction(double); // вторая функция(математическая)
double ThirdFunction(double); // третья функция(математическая)
double accuracyEps(); // желаемая точность вычисления интегралов
void righRectanglesMethod(double (*f)(double), double, double, double); // вычисление по методу правых прямоугольников
void rectangularTrapezoidMethod(double (*f)(double), double, double, double); // вычисление по методу прямоугольных трапеций
void twoMetods(double (*f)(double), const double&, const double&, const double&); // вывод двух вариантов вычисления для каждой математической функции

int main()
{
  try
  {
    long double eps = accuracyEps(); // точность
    if (eps < 0.000000001)
    {
      throw std::exception("The accuracy is too high, your computer may be kaput!");
    }

    std::cout << "\nFirst function:\n";
    twoMetods(FirstFunction, 0, 1, eps); // вывод вычислений для первой математической функции
    std::cout << "\nSecond function:\n";
    twoMetods(SecondFunction, 1, 2, eps); // вывод вычислений для второй математической функции
    std::cout << "\nThird function:\n";
    twoMetods(ThirdFunction, 1, 2, eps); // вывод вычислений для третей математической функции

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

double accuracyEps() // придётся вводить точность до того момента пока она не станет адекватной
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
  uint32_t n = 4; // начальное количество приближений
  long double h = (b - a) / n, s1 = 0, s2 = 0; // длинна отрезка приближения

  for (size_t step = 1; step <= n; ++step) // подсчёт интеграла с первоначальным количеством приближений
  {
    s2 += h * f(a + h * step); // вычисление и добавлние полщади каждого прямоугольника (длина отрезка приближения * на высоту заданую правой стороной)
  }
while (abs(s1 - s2) > eps) // пока следующее вычисление интеграла не станет меньше тчоности, будет увеличиваться количество приближений в 2 раза
  {
    s1 = s2; // сохранение предыдущего вычисления
    s2 = 0; // обнуление для нового подсчета
    n *= 2; h /= 2; // увеличение количества приближений 
    for (size_t step = 1; step <= n; ++step)
    {
      s2 += h * f(a + h * step); // продолжение подсчёта
    }
  }

  std::cout << "Counting by the method of right rectangles: " << s2 << "\nNumber of sections: " << n << '\n';
}

void rectangularTrapezoidMethod(double (*f)(double), double a, double b, double eps)
{
  uint32_t n = 4; // начальное количество приблежений 
  long double h = (b - a) / n, s1 = 0, s2 = 0;// h* ((f(a) + f(b)) / 2); // площадь прямоугольной трапеции считается как полусумма оснований на высоту

  for (size_t step = 1; step < n; ++step) // подсчёт интеграла с первоначальным количеством приближений
  {
    s2 += h * (f(a + h * (step - 1)) + f(a + h * step)) / 2; // подсчёт интеграла с помощью метода трапеций
  }

  while (abs(s1 - s2) > eps) // пока следующее вычисление интеграла не станет меньше тчоности, будет увеличиваться количество приближений в 2 раза
  {
    s1 = s2; // сохранение предыдущего вычисления
    n *= 2; h /= 2; // увеличение количества приближений
    s2 = h * ((f(a) + f(b)) / 2); // площадь прямоугольной трапеции считается как полусумма оснований на высоту
    for (size_t step = 1; step < n; ++step)
    {
      s2 += h * (f(a + h * (step - 1)) + f(a + h * step)) / 2; // продолжение подсчёта
    }
  }

  std::cout << "Calculation using the rectangular trapezoid method: " << s2 << "\nNumber of sections: " << n << "\n";
}

void twoMetods(double (*f)(double), const double& a, const double& b, const double& eps) // вывод подсчёта двух методов для одной функции(математической)
{
  righRectanglesMethod((*f), a, b, eps);
  rectangularTrapezoidMethod((*f), a, b, eps);
}