#include "func.hpp"

void secondPartOfTheTask()
{
	std::vector<int> numbers;
	int fin;

	// Ввод чисел
	std::cout << "введите числа, -1 - конец ввода: ";
	while (std::cin >> fin && fin != -1)
	{
		numbers.push_back(fin);
	}

	// Сумма чисел
	int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
	std::cout << "Сумма чисел: " << sum << '\n';

	// Общее количество чисел
	std::cout << "Общее количество чисел: " << numbers.size() << '\n';

	// Количество чисел, равных заданному
	int target;
	std::cout << "Введите число для подсчета: ";
	std::cin >> target;
	int count = std::count(numbers.begin(), numbers.end(), target);
	std::cout << "Количество чисел, равных " << target << ": " << count << '\n';

	// Количество чисел, больше, чем n
	int n;
	std::cout << "Введите число n: ";
	std::cin >> n;
	count = std::count_if(numbers.begin(), numbers.end(), [=](int num)
						  { return num > n; });
	std::cout << "Количество чисел, больше, чем " << n << ": " << count << '\n';

	// Заменить все нули средним арифметическим, взять целую часть
	int average = static_cast<int>(sum / numbers.size());
	std::replace(numbers.begin(), numbers.end(), 0, average);

	// Добавить к каждому элементу вектора сумму всех чисел из заданного интервала
	int start, end;
	std::cout << "Введите начало и конец интервала: ";
	std::cin >> start >> end;
	if (start > end)
	{
		std::swap(start, end);
	}
	if (start >= 0 && end < numbers.size())
	{
		int interval_sum = std::accumulate(numbers.begin() + start, numbers.begin() + end + 1, 0);
		std::transform(numbers.begin(), numbers.end(), numbers.begin(), [=](int num)
					   { return num + interval_sum; });
	}

	// Заменить все числа, модуль которых есть четное число, на разность максимального и минимального элемента
	int min_num = *std::min_element(numbers.begin(), numbers.end());
	int max_num = *std::max_element(numbers.begin(), numbers.end());
	std::transform(numbers.begin(), numbers.end(), numbers.begin(), [=](int num)
				   { return abs(num) % 2 == 0 ? max_num - min_num : num; });

	// Удалить из последовательности все равные по модулю числа, кроме первого из них
	std::sort(numbers.begin(), numbers.end(), [](int a, int b)
			  { return abs(a) < abs(b); });
	numbers.erase(std::unique(numbers.begin(), numbers.end(), [](int a, int b)
							  { return abs(a) == abs(b); }),
				  numbers.end());
}

void thirdPartOfTheTask()
{
	std::vector<std::string> words;
	char letter;

	// Чтение списка слов из текстового файла
	fillingTheVectorForThirdTask(words);

	// Сортировка списка
	std::sort(words.begin(), words.end());

	// Печать отсортированного списка
	for (const auto &w : words)
	{
		std::cout << w << '\n';
	}

	// Печать элементов списка, начинающихся на заданную букву
	std::cout << "Введите букву: ";
	bool thePresenceOfAWordStartingWithTheSameLetter = true;
	std::cin >> letter;
	for (const auto &w : words)
	{
		if (w[0] == letter)
		{
			std::cout << w << '\n';
			thePresenceOfAWordStartingWithTheSameLetter = false;
		}
	}
	if (thePresenceOfAWordStartingWithTheSameLetter)
	{
		std::cout << "Нету слов начинающихся на эту букву\n";
	}

	// Удаление элементов списка на заданную букву
	std::cout << "Введите букву для удаления слов: ";
	thePresenceOfAWordStartingWithTheSameLetter = true;
	std::cin >> letter;
	size_t count = 0;
	for (auto &w : words)
	{
		if (w[0] == letter)
		{
			words.erase(words.begin() + count);
			thePresenceOfAWordStartingWithTheSameLetter = false;
		}
		++count;
	}
	if (thePresenceOfAWordStartingWithTheSameLetter)
	{
		std::cout << "Нету слов начинающихся на эту букву\n";
	}

	// Печать списка после удаления элементов
	for (const auto &w : words)
	{
		std::cout << w << '\n';
	}
}

void fillingTheVectorForThirdTask(std::vector<std::string> &vec)
{
	// Чтение списка слов из текстового файла
	std::string path = "src/files/dataForthirdTask.txt";
	std::ifstream fin(path);
	checkFile(fin, path);
	std::string str;
	std::regex regexForWord("[\\w']+");
	while (getline(fin, str))
	{
		auto wordBegin = std::sregex_iterator(str.begin(), str.end(), regexForWord);
		auto wordEnd = std::sregex_iterator();
		for (std::sregex_iterator i = wordBegin; i != wordEnd; ++i)
		{
			std::smatch match = *i;
			std::string matchStr = match.str();
			vec.push_back(matchStr);
		}
	}

	fin.close();
}

void checkPath(const std::string &path)
{
	std::filesystem::path pathToCheck(path);
	if (!std::filesystem::exists(pathToCheck))
	{
		throw std::invalid_argument("Файловый объект по пути " + path + " не существует!");
	}

	if (!std::filesystem::is_regular_file(pathToCheck))
	{
		throw std::invalid_argument("Файловый объект по пути " + path + " не является обычным файлом!");
	}

	if (!pathToCheck.has_extension() || pathToCheck.extension() != ".txt")
	{
		throw std::invalid_argument("Файловый объект по пути " + path + " имеет недопустимое расширение! Ожидается .txt");
	}
}

void checkFile(std::ifstream &fin, const std::string &path)
{
	checkPath(path);
	if (!fin)
	{
		throw std::ios_base::failure("Не удалось открыть файл. Путь: " + path);
	}
	if (fin.peek() == EOF)
	{
		throw std::runtime_error("Файл пуст. Путь: " + path);
	}
}

void fourthPartOfTheTask()
{
	srand(time(0));
	int n, m, low, high;
	std::cout << "Введите размеры матрицы (n и m): ";
	std::cin >> n >> m;
	if (1 > n || 1 > m)
	{
		throw std::invalid_argument("Размерность матрицы не может быть отрицательной");
	}

	std::cout << "Введите границы интервала (low и high): ";
	std::cin >> low >> high;

	std::vector<std::vector<int>> matrix(n, std::vector<int>(m));

	// Заполнение матрицы случайными значениями
	for (auto &row : matrix)
	{
		for (auto &el : row)
		{
			el = low + rand() % (high - low + 1);
		}
	}

	// Поиск максимального элемента и его позиции
	int maxVal = matrix[0][0], maxRow = 0, maxCol = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (matrix[i][j] > maxVal)
			{
				maxVal = matrix[i][j];
				maxRow = i;
				maxCol = j;
			}
		}
	}

	// Удаление строки и столбца с максимальным элементом
	deleteRowAndColumn(matrix, maxRow, maxCol);

	// Упорядочиенные строки матрицы
	sortRows(matrix);
}

void deleteRowAndColumn(std::vector<std::vector<int>> &matrix, int row, int col)
{
	matrix.erase(matrix.begin() + row);
	for (auto &r : matrix)
	{
		r.erase(r.begin() + col);
	}
}

void sortRows(std::vector<std::vector<int>> &matrix)
{
	bool swapped;
	do
	{
		swapped = false;
		for (size_t i = 0; i < matrix.size() - 1; ++i)
		{
			int sum1 = 0, sum2 = 0;
			for (const auto &el : matrix[i])
				sum1 += el;
			for (const auto &el : matrix[i + 1])
				sum2 += el;
			if (sum1 > sum2)
			{
				swap(matrix[i], matrix[i + 1]);
				swapped = true;
			}
		}
	} while (swapped);
}

void fifthPartOfTheTask()
{
	std::string path = "src/files/Students.txt";
	std::ifstream fin(path);
	checkFile(fin, path);
	std::vector<Student> students;

	// Чтение данных из файла
	Student temp;
	while (fin >> temp.name >> temp.course >> temp.group)
	{
		students.push_back(temp);
	}
	fin.close();

	// Сортировка по фамилии и запись в файл "Fio.txt"
	std::sort(students.begin(), students.end(), compareByName);
	std::ofstream fout("src/files/Fio.txt");
	for (const auto &student : students)
	{
		fout << student.name << " " << student.course << " " << student.group << "\n";
	}
	fout.close();

	// Сортировка по курсу, группе и фамилии и запись в файл "Groups.txt"
	std::sort(students.begin(), students.end(), compareByCourseGroupAndName);
	fout.open("src/files/Groups.txt");
	for (const auto &student : students)
	{
		fout << student.name << " " << student.course << " " << student.group << "\n";
	}
	fout.close();
}

bool compareByName(const Student &first, const Student &second)
{
	return first.name < second.name;
}

bool compareByCourseGroupAndName(const Student &first, const Student &second)
{
	if (first.course != second.course)
		return first.course < second.course;
	if (first.group != second.group)
		return first.group < second.group;
	return first.name < second.name;
}

void sixthPartOfTheTask()
{
	// Чтение данных из файла
	std::ifstream fin("src/files/Train.txt");
	checkFile(fin, "src/files/Train.txt");
	std::vector<Train> trains;
	Train temp;
	while (fin >> temp.number >> temp.destination >> temp.type >> temp.departureTime >> temp.travelTime)
	{
		trains.push_back(temp);
	}
	fin.close();

	// Сортировка по времени отправления
	std::sort(trains.begin(), trains.end(), [](const Train &a, const Train &b)
			  { return a.departureTime < b.departureTime; });

	// Вывод информации обо всех поездах из заданного диапазона времени
	std::string startTime, endTime;
	std::cout << "Введите диапазон времени по формату ЧЧ:ММ\n";
	std::cout << "От: ";
	std::cin >> startTime;
	std::regex time("^([01]?[0-9]|2[0-3]):[0-5][0-9]$");
	if (!std::regex_match(startTime, time))
	{
		throw std::invalid_argument("Неправильный формат");
	}
	std::cout << "До: ";
	std::cin >> endTime;
	if (!std::regex_match(startTime, time))
	{
		throw std::invalid_argument("Неправильный формат");
	}
	if (startTime > endTime)
	{
		std::swap(startTime, endTime);
	}
	for (const auto &train : trains)
	{
		if (train.departureTime >= startTime && train.departureTime <= endTime)
		{
			std::cout << train.number << " " << train.destination << " " << train.type << " " << train.departureTime << " " << train.travelTime << "\n";
		}
	}

	// Вывод информации о всех поездах, направляющихся в заданный пункт назначения
	std::string destination;
	std::cout << "Пункт назначения: ";
	std::cin >> destination;
	bool availability = true;
	for (const auto &train : trains)
	{
		if (train.destination == destination)
		{
			availability = false;
			std::cout << train.number << " " << train.destination << " " << train.type << " " << train.departureTime << " " << train.travelTime << "\n";
		}
	}
	if (availability)
	{
		std::cout << "Поезда с таким местом назначения отсутсвуют\n";
	}

	// Вывод на экран всех скорых поездов, направляющихся в заданный пункт назначения
	std::cout << "Пункт назначения скорого поезда: ";
	std::cin >> destination;
	availability = true;
	for (const auto &train : trains)
	{
		if (train.destination == destination && train.type == "fast")
		{
			availability = false;
			std::cout << train.number << " " << train.destination << " " << train.type << " " << train.departureTime << " " << train.travelTime << "\n";
		}
	}
	if (availability)
	{
		std::cout << "Cкорые поезда с таким местом назначения отсутсвуют\n";
	}

	// Нахождение самого быстрого поезда, следующего в заданный пункт назначения
	Train *fastest = nullptr;
	for (auto &train : trains)
	{
		if (train.destination == destination && (!fastest || train.travelTime < fastest->travelTime))
		{
			fastest = &train;
		}
	}
	if (fastest)
	{
		std::cout << "Самый быстрый поезд: " << fastest->number << " " << fastest->destination << " " << fastest->type << " " << fastest->departureTime << " " << fastest->travelTime << "\n";
	}
}
