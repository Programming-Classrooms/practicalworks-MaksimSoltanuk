#include "src/class/list/list.hpp"
#include "src/class/fraction/fraction.hpp"
#include "src/class/matrix/matrix.hpp"

int main()
{
	try
	{
		// первое задание
		Fraction A;							   // по умолчанию
		Fraction B(24, -2);					   // с параметрами
		Fraction C(B);						   // копирования
		Fraction D = (B + B - B * B / B) ^ -2; // арифметические операторы

		Fraction Z(std::move(D)); // перемещение

		std::cin >> D; // ввод
		int a = -3;
		D = D ^ a;
		std::cout << D; // вывод
		// операторы сравнения
		Fraction E(1, 5);
		if (B == C)
		{
			std::cout << "= \n";
		}
		if (B != E)
		{
			std::cout << "!=\n";
		}
		if (E > B)
		{
			std::cout << ">\n";
		}
		if (B < E)
		{
			std::cout << "<\n";
		}
		if (B <= E)
		{
			std::cout << "<=\n";
		}
		if (B >= C)
		{
			std::cout << ">=\n";
		}
		// декремент и инкеремент
		E++;
		std::cout << ++E;
		++E;
		std::cout << --E;
		E--;
		std::cout << E;
		--E;
		std::cout << E;
		// унарный минус
		E = -E;
		std::cout << E;
		E = -E;
		std::cout << E;
		// обратная дробь
		E = !E;
		std::cout << E;
		E = !E;
		std::cout << E;
		// вещественная форма
		Fraction F;
		std::cin >> F;
		std::cout << F.doubleForm(F);
		// операторы составного присваивания
		F += E;
		std::cout << F;
		F += 1;
		std::cout << F;
		F -= E;
		std::cout << F;
		F -= 1;
		std::cout << F;
		F *= E;
		std::cout << F;
		F *= 1;
		std::cout << F;
		F /= E;
		std::cout << F;
		F /= 1;
		std::cout << F;

		// второе задание

		Matrix M1(2, 2); // с параметрами
		Matrix M2(M1);	 // копирования
		M1 = 5.3;		 // присваивание константы
		std::cout << M1; // вывод

		std::cin >> M1; // ввод
		std::cin >> M2;
		std::cout << M2;
		Matrix M3 = M1 * M3; // умножение матриц
		std::cout << C << '\n';

		M1 = 5.2;
		M3 += M1; // +=
		std::cout << M3 << '\n';

		Matrix M4(M1);
		if (M1 == M4)
		{
			std::cout << "equal";
		}
		if (!(M1 != M4))
		{
			std::cout << "equal";
		}

		// третье задание
		List<int> l;
		// ввод списка
		l.pushBack(5);
		l.pushFront(4);
		l.pushBack(8);
		l.pushBack(-3);
		l.pushBack(4);
		l.pushBack(6);
		// удаление по значению
		l.deleteByValue(8);
		// удаление сзади
		l.popBack();
		// удаление спереди
		l.popFront();

		List<int> l2 = l;

		for (size_t i = 0; i < l.getCountElements(); ++i)
		{
			std::cout << l[i] << ' ';
		}
		std::cout << '\n';
		// вывод
		l2.outputList();
		// callback
		l2.checkList([](int data)
					 { std::cout << data << " "; });
	}
	catch (const std::logic_error &err)
	{
		std::cerr << err.what();
	}
	return 0;
}
