/*
    Разработать шаблон функции для обработки массивов с элементами простого арифметического типа и массивов, элементы которых – строки типа char* .
    Продемонстрировать использование этого шаблона для конкретных динамических массивов типа int, double, char* .
    Для получения входных данных иметь три варианта :
    непосредственный ввод и запись в текстовый файл;
    генерирование с помощью датчика случайных чисел и запись в текстовый файл;
    ввод из текстового файла, а вывод - в консоль.
    Разработать шаблон функции, позволяющей в упорядоченный массив включить новый элемент так, чтобы не нарушилась упорядоченность.
*/


#include<iostream>
#include<regex>
#include<string>
#include<iomanip>
#include<fstream>
#include<ctime>


template<typename T>
void tasksForArray(T*, const uint32_t);
template<typename T>
void directInput(T*, const uint32_t);
template<typename T>
void arraySort(T*, const uint32_t);
template<typename T>
void arrayOutput(T*, const uint32_t);
template <typename T>
void newArrayOutput(T*, const uint32_t);
template<typename T>
void insertIntoOrderedArray(T*, const uint32_t, T);
template <typename T>
void writeToFile(T*, const uint32_t);
void arrayRand(int32_t*, const uint32_t);
void arrayRand(double*, const uint32_t);
void arrayRand(char*, const uint32_t);
template <typename T>
void readFromFileAndPrint(T*, const uint32_t);
void clearArray(int32_t*&, double*&, char*&);

int main()
{
    srand(time(NULL));
    try
    {
        // Блок кода, отвечающий за адекватность размера массива 
        std::string size;
        std::regex doubleCheck("^(0|([1-9][0-9]*))((\\.[0-9]+)+)$");
        std::regex stringCheck("\\D+");
        std::cout << "Enter the size of the array:\n";
        std::cin >> size;
        try
        {
            if (std::regex_match(size, stringCheck)) {
                throw std::string("Size may be only number!\n");
            }
            if (std::regex_match(size, doubleCheck)) {
                throw std::string("Size may be only integer number!\n");
            }
            if (std::stoi(size) <= 0) {
                throw std::string("Size may be only naturale number!\n");
            }
            std::cout << '\n';
        }
        catch (const std::string& sizeForArray)
        {
            std::cerr << "Exception: " << sizeForArray;
            throw std::exception();
        }
        const uint32_t realSize = std::stoi(size);

        // Создание массивов трёх видов
        int32_t* arrayInt = new int32_t[realSize + 1];
        double* arrayDouble = new double[realSize + 1];
        char* arrayChar = new char[realSize + 1];
        try
        {
            // Выбор типа массива
            uint32_t choiceForArray;
            std::cout << "Choose which array you want:\n";
            std::cout << "1. With integer\n";
            std::cout << "2. With fractions\n";
            std::cout << "3. With symbols\n";
            std::cout << "What did you choose: ";
            std::cin >> choiceForArray;
            std::cout << '\n';
            switch (choiceForArray)
            {
            case 1:
                tasksForArray(arrayInt, realSize);
                break;
            case 2:
                tasksForArray(arrayDouble, realSize);
                break;
            case 3:
                tasksForArray(arrayChar, realSize);
                break;
            default:
                throw std::string("You have choice only between 1, 2 and 3!\n");
            }
            throw std::string();
        }
        catch (const std::string& is)
        {
            std::cerr << is;
            clearArray(arrayInt, arrayDouble, arrayChar);
        }
    }
    catch (const std::exception&)
    {
        std::cout << '\n';
    }
    return 0;
}

// Задачи предоставляемые пользователю на выбор
template <typename T>
void tasksForArray
(
  T* array,
  const uint32_t realSize
) 
{
    uint32_t choiceForTask;
    std::cout << "Choose an option:\n";
    std::cout << "1. Direct input and write to file\n";
    std::cout << "2. Generate and write to file\n";
    std::cout << "3. Read from file and print\n";
    std::cout << "What did you choose: ";
    std::cin >> choiceForTask;
    std::cout << "\n";
    switch (choiceForTask)
    {
    case 1:
        directInput(array, realSize);
        arrayOutput(array, realSize);
        T newElementForDirectInput;
        std::cout << "What you want to add? ";
        std::cin >> newElementForDirectInput;
        insertIntoOrderedArray(array, realSize, newElementForDirectInput);
        writeToFile(array, realSize);
        break;
    case 2:
        arrayRand(array, realSize);
        arrayOutput(array, realSize); 
        T newElementForRandArray;
        std::cout << "What you want to add? ";
        std::cin >> newElementForRandArray;
        insertIntoOrderedArray(array, realSize, newElementForRandArray);
        writeToFile(array, realSize);
        break;
    case 3:
        readFromFileAndPrint(array, realSize);
        arrayOutput(array, realSize);
        T newElementForFileArray;
        std::cout << "What you want to add? ";
        std::cin >> newElementForFileArray;
        insertIntoOrderedArray(array, realSize, newElementForFileArray);
        break;
    default:
        throw std::string("You have choice only between 1, 2 and 3!\n");
    }
}

// Ввод массива в консоль
template <typename T>
void directInput
(
  T* array,
  const uint32_t realSize
)
{
    std::cout << "Enter " << realSize << " integers: \n";
    for (int i = 0; i < realSize; ++i)
    {
        std::cin >> array[i];
    }
}

// Сортировка массива 
template <typename T>
void arraySort
(
  T* array,
  const uint32_t realSize
) 
{
    for (size_t i = 1; i < realSize; i++)
    {
        for (size_t j = 0; j < realSize - 1; j++)
        {
            if (array[j] > array[i]) {
                std::swap(array[i], array[j]);
            }
        }
    }
}

// Вывод массива
template <typename T>
void arrayOutput
(
  T* array,
  const uint32_t realSize
)
{
  arraySort(array, realSize);
  for (int i = 0; i < realSize; ++i)
  {
      std::cout << std::setw(5) << array[i] << ' ';
  }
  std::cout << '\n';
}

// Вывод массива с добавленным элементов
template <typename T>
void newArrayOutput
(
  T* array,
  const uint32_t realSize
)
{
    for (int i = 0; i < realSize + 1; ++i)
    {
        std::cout << std::setw(5) << array[i] << ' ';
    }
    std::cout << '\n';
}

// Добавление в массив еще одного элемента
template <typename T>
void insertIntoOrderedArray
(
  T* array,
  const uint32_t realSize,
  T newElement
)
{
  array[realSize] = newElement;
  for (size_t i = realSize; i > 0; --i)
  {
      if (array[i - 1] > array[i]) {
          std::swap(array[i - 1], array[i]);
      }
  }
  newArrayOutput(array, realSize);
}

// Запись в файл "File.txt", кторый находится в одной папке с проектом
template <typename T>
void writeToFile
(
T* array,
const uint32_t realSize
)
{
   std::ofstream fout("file.txt");
   if (fout.is_open()) {
       for (size_t i = 0; i < realSize + 1; ++i) 
       {
           fout << array[i] << " ";
       }
       fout.close();
       std::cout << "Data written to file.txt\n";
   }
   else {
       throw std::string("Unable to open file!\n");
   }
}

// Рандом для инта
void arrayRand
(
  int32_t* array,
  const uint32_t realSize
)
{
   for (size_t i = 0; i < realSize; ++i)
   {
       array[i] = rand() % 100;
   }
   arraySort(array, realSize);
}
 
// Рандом для дабла
void arrayRand
(
  double* array,
  const uint32_t realSize
)
{
   for (size_t i = 0; i < realSize; ++i)
   {
       array[i] = 10 + (static_cast<double>(rand()) * 90 / RAND_MAX);
   }
   arraySort(array, realSize);
}

// Рандом для чара
void arrayRand
(
  char* array,
  const uint32_t realSize
)
{
   for (size_t i = 0; i < realSize; ++i) 
   {
       array[i] = static_cast<char>(rand() % 100);
   }
   arraySort(array, realSize);
}

// Чтение из файла "file.txt" который находится в одной папке с проектом
template <typename T>
void readFromFileAndPrint
(
  T* array,
  const uint32_t realSize
)
{
    std::ifstream fin("file.txt");
    uint32_t countSymbol = 0;
    fin.seekg(0, std::ios_base::end);
    countSymbol = fin.tellg();
    fin.close();
    std::ifstream finArrayOutput("file.txt");
    if (countSymbol >= realSize) {
        if (finArrayOutput.is_open()) {
            for (int i = 0; i < realSize && i < countSymbol; ++i)
            {
                finArrayOutput >> array[i];
            }
            finArrayOutput.close();
        }
        else {
            throw std::string("Unable to open file!\n");
        }
    }
    else {
        throw std::string("There is too little data in the file!\n");
    }
}

// Очитска памяти 
void clearArray
(
  int32_t*& arrayInt,
  double*& arrayDouble,
  char*& arrayChar
)
{
    delete[] arrayInt;
    delete[] arrayChar;
    delete[] arrayDouble;
}
