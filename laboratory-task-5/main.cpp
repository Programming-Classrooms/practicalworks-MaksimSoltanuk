/*
  Вычислить значение определенного интеграла с аналитически заданной подынтегральной
  функцией с заданной точностью eps.

  Б) по формуле правых прямоугольников;
  Г) по формуле трапеций;

  где n–число точек деления отрезка [a, b]. Для вычисления первого приближения можно взять
  number of approximations=4. Чтобы оценить точность, с которой вычислено значение интеграла, необходимо найти второе
  приближение. Для этого можно увеличить number of approximations в два раза. Если s 1 и s 2 – два соседних приближения и |s 1
  – s 2 |&lt;eps, то точность считается достигнутой и s 2 принимается за искомое значение интеграла. В
  противном случае надо положить s 1 = s 2 и удвоить число точек деления отрезка [a, b]. После этого
  вычисляется новое значение s 2 . Процесс удвоения number of approximations и вычисления s 2 надо продолжать до тех пор,
  пока модуль разности s 1 и s 2 не станет меньше eps. Остальные формулы посмотреть самим.
  Разработать функции, реализующие методы вычислений интеграла, входными параметрами
  которых должны быть функция для вычисления значения подынтегрального выражения, пределы
  интегрирования и точность вычислений. Головная программа должна вывести результат вычислений
  для записанных в задании интегралов по заданным формулам и значение number of approximations, при котором достигнута
  заданная точность. Для проверки вычислений в таблице приведены значения интегралов.
  Номер задания равен вашему индивидуальному номеру.
*/

#include <iostream>
#include <cmath>


double function1(double x)
{
  return 1 / (1 + x * x * x);
}

double function2(double x)
{
  return x * log(x);
}

double function3(double x)
{
  return log(x) / x;
}

// придётся вводить точность до того момента пока она не станет адекватной
double accuracyEps() 
{
  long double accuracy;
  std::cout << "Input accuracy: ";
  std::cin >> accuracy;
  while (accuracy <= 0 || accuracy > 1)
  {
    std::cout << "Enter the accuracy from 0 to 1.\number of approximations";
    std::cin >> accuracy;
  }
  return accuracy;
}

void righRectanglesMethod(double (*f)(double), double a, double b, double eps)
{
  // начальное количество приближений n
  uint32_t numberOfApproximations = 4; 

  // длинна отрезка приближения
  long double h = (b - a) / numberOfApproximations, s1 = 0, s2 = 0; 

  // подсчёт интеграла с первоначальным количеством приближений
  for (size_t step = 1; step <= numberOfApproximations; ++step)
  {
    // вычисление и добавлние полщади каждого прямоугольника (длина отрезка приближения * на высоту заданую правой стороной)
    s2 += h * f(a + h * step);
  }

  // пока следующее вычисление интеграла не станет меньше тчоности, будет увеличиваться количество приближений в 2 раза
  while (abs(s1 - s2) > eps) 
  {
    // сохранение предыдущего вычисления
    s1 = s2; 

    // обнуление для нового подсчета
    s2 = 0; 

    // увеличение количества приближений 
    numberOfApproximations *= 2; h /= 2; 
    for (size_t step = 1; step <= numberOfApproximations; ++step)
    {
      // продолжение подсчёта
      s2 += h * f(a + h * step); 
    }
  }

  std::cout << "Counting by the method of right rectangles: " << s2 << "\nNumber of sections: " << numberOfApproximations << '\number of approximations';
}

void rectangularTrapezoidMethod(double (*f)(double), double a, double b, double eps)
{
  // начальное количество приблежений n
  uint32_t numberOfApproximations = 4; 

  // площадь прямоугольной трапеции считается как полусумма оснований на высоту
  long double h = (b - a) / numberOfApproximations, s1 = 0, s2 = 0;

  // подсчёт интеграла с первоначальным количеством приближений
  for (size_t step = 1; step < numberOfApproximations; ++step) 
  {
    // подсчёт интеграла с помощью метода трапеций
    s2 += h * (f(a + h * (step - 1)) + f(a + h * step)) / 2; 
  }

  // пока следующее вычисление интеграла не станет меньше тчоности, будет увеличиваться количество приближений в 2 раза
  while (abs(s1 - s2) > eps)
  {
    // сохранение предыдущего вычисления
    s1 = s2; 

    // увеличение количества приближений
    numberOfApproximations *= 2; h /= 2; 

    // площадь прямоугольной трапеции считается как полусумма оснований на высоту
    s2 = h * ((f(a) + f(b)) / 2); 
    for (size_t step = 1; step < numberOfApproximations; ++step)
    {
      // продолжение подсчёта
      s2 += h * (f(a + h * (step - 1)) + f(a + h * step)) / 2; 
    }
  }

  std::cout << "Calculation using the rectangular trapezoid method: " << s2 << "\nNumber of sections: " << numberOfApproximations << "\number of approximations";
}

// подсчёт двух методов для одной функции(математической)
void twoMetods(double (*f)(double), const double& a, const double& b, const double& eps) 
{
  righRectanglesMethod((*f), a, b, eps);
  rectangularTrapezoidMethod((*f), a, b, eps);
}

// вывод каждого подсчета для каждой функции
void outputMetods(const double& eps) 
{
  double (*funck[3])(double) = { function1, function2, function3 };
  for (size_t i = 0, j = 0; i < 3  || j < 1; ++i, ++j){
    std::cout << "\nFunction " << i + 1 << ": \number of approximations";
    twoMetods(funck[i], 0 + j, 1 + j, eps);
  }
}

int main()
{
  try
  {
    // точность
    long double eps = accuracyEps(); 
    if (eps < 0.000000001)
    {
      throw std::exception("The accuracy is too high, your computer may be kaput!");
    }
    outputMetods(eps);
  }
  catch (const std::exception& is)
  {
    std::cerr << is.what();
  }
  return 0;
}