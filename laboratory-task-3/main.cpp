/*
    Использовать статический массив(+отдельно сделать для динамического
    массива).Максимальную размерность массива задать именованной константой.
    Реальное количество элементов массива ввести с клавиатуры с контролем на выход
    за границы массива.Массивы должны состоять не менее, чем из одного элемента.
    Предусмотреть два способа заполнения массива : с клавиатуры и с помощью
    датчика случайных чисел.В последнем случае перед заполнением массива ввести
    границы интервала, которому должны принадлежать элементы массива.
    Вывести результаты расчетов.Если по каким - либо причинам решение задачи
    невозможно, вывести соответствующее сообщение.
    Дополнительных массивов для преобразования данных использовать нельзя.

    В массиве, состоящем из п вещественных элементов:
    - в упорядоченном массиве удалить наименьшее количество элементов для получения
    строго возрастающего массива;
    - вычислить произведение элементов массива, расположенных между последним
    максимальным и последним минимальным элементами.
    Упорядочить элементы массива с четными номерами по возрастанию.
*/


#include <iostream>
#include <ctime>


void random(double, double, uint32_t, double*);
void printArray(uint32_t, double*);
void printMaxGrowing(double*, uint32_t);
uint32_t idexMax(uint32_t, double*);
uint32_t idexMin(uint32_t, double*);
double productBetween(double*, uint32_t);
void my_sort(uint32_t, double*);


int main()
{
    uint32_t size = 0, first = 0, last = 0, Filling_method;
    double* arr = new double[size];
    double minElement = arr[0], maxElement = arr[0], maxIndex{}, minIndex{}, product = 1.0;
    
    try
    {          
        std::cout << "Fill the array RANDOMLY(1) or BY HANDS(2) ?" << '\n';
        std::cin >> Filling_method;

        switch (Filling_method)
        {
        default:
            std::cout << "You need to enter 1 or 2"; break;

        case 1:

            std::cout << "Enter the number of array elements = ";
            std::cin >> size;

            if (size < 1)
            {
                throw std::exception("The number of elements must be a natural number!");
            }

            random(first, last, size, arr);
            printArray(size, arr);        

            break;
        case 2:

            std::cout << "Enter the number of array elements = ";
            std::cin >> size;

            if (size < 1)
            {
                throw std::exception("The number of elements must be a natural number!");
            }

            std::cout << "Enter Array Elements :" << '\n';
            for (int i = 0; i < size; i++)
            {
                std::cin >> arr[i];
            }

            break;
        }

        std::cout << "Strictly increasing sequence :" << '\n';
        printMaxGrowing(arr, size);

        std::cout << "product between smallest and largest :" << '\n';
        try {
            std::cout << productBetween(arr, size) << '\n';
        }

        catch (const std::exception& isa)
        {
            std::cout << isa.what();
        }

        std::cout << "Ordered even-numbered array elements in ascending order :" << '\n';
        my_sort(size, arr);
        printArray(size, arr);

    }
    catch (const std::exception& is)
    {
        std::cout << is.what();
    }
    return 0;
}

void random(double first, double last, uint32_t size, double* arr)
{
    std::cout << "Lower limit of randomness = ";
    std::cin >> first;
    std::cout << "The upper limit of randomness = ";
    std::cin >> last;
    if (first >= last)
    {
        std::swap(first, last);
    }
    srand(time(NULL));

    for (size_t i = 0; i < size; ++i)
    {
        arr[i] = first + rand() * (last - first) / RAND_MAX;
    }
    std::cout << '\n';
}

void printArray(uint32_t size, double* arr)
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
}

//1 часть
//макимальная возрастающая последовательнось
void printMaxGrowing(double* arr, uint32_t size)
{
    size_t curr_len = 1, max_len = 1, start_ind = 0;for (size_t i = 1; i < size; ++i) {
        if (arr[i - 1] < arr[i]) {
            ++curr_len;
            start_ind = i - curr_len;
        }
        else {
            if (curr_len > max_len) {
                max_len = curr_len;
            }
            curr_len = 1;
        }
    }

    if (curr_len > max_len) {
        max_len = curr_len;
    }

    for (size_t i = start_ind + 1; i <= start_ind + max_len; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}

//2 часть
//произведение между послденим (max)
uint32_t idexMax(uint32_t size, double* arr)
{
    uint32_t index_max = size - 1;
    double max = arr[size - 1];
    for (uint32_t i = size - 1; i > 0; --i)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            index_max = i;
        }
    }
    return index_max;
}

uint32_t idexMin(uint32_t size, double* arr)
{
    uint32_t index_min = size - 1;
    double min = arr[size - 1];
    for (size_t i = 0; i < size; ++i)
    {
        if (arr[i] <= min)
        {
            min = arr[i];
            index_min = i;
        }
    }
    return index_min;
}

double productBetween(double* arr, uint32_t size)
{
    uint32_t index_max = idexMax(size, arr);
    uint32_t index_min = idexMin(size, arr);
    double product = 1.0;

    if (index_max < index_min) {
        std::swap(index_max, index_min);
    }
    if (index_max == index_min + 1) {
        throw std::exception("No elements between\n");
    }
    if (index_max == index_min) {
        throw std::exception("Position Max = Min \n");
    }

    for (uint32_t i = index_min + 1; i < index_max; i++) {
        product *= arr[i];
    }
    return  product;
}

//3часть
//сортировка
void my_sort(uint32_t size, double* arr)
{
    for (size_t i = 1; i < size; i += 2)
    {
        for (size_t j = i + 2; j < size; j += 2)
        {
            if (arr[i] > arr[j])
            {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}