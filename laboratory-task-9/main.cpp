/*
  Разработать алгоритм и составить программу для решения  следующих задач:
  Задан текстовый файл input.txt. Требуется определить строки этого  файла, содержащие максимальную по длине подстроку, состоящую только из  знаков препинания.
  Перечень символов, подходящих под определение “знаки  препинания”, задает пользователь. Если таких строк несколько, найти первые  10.
  Результат вывести на консоль в форме, удобной для чтения.
*/


#include<iostream>
#include<fstream>
#include<string>
#include<regex>


void readFromFile(std::string&, std::regex, std::regex, size_t&, size_t&, size_t&, size_t&, uint32_t*);
uint32_t countOfDelims(std::string&, std::regex, std::regex);
uint32_t maxSizeOfDelims(size_t&, size_t&, uint32_t*, std::string&, std::regex, std::regex, size_t&, size_t&);
void outputSttrings(size_t&, uint32_t*, std::string&, uint32_t& zero);

int main()
{
  // разделителями выступют буквы и цифры
  std::regex sepRegex("\\w+");

  // разделители (как то что нам нужно)
  std::regex delims("[\\W]+");

  // 6удем хранить строку из файла
  std::string str = "";

  // изначально макисмальный размер подсторки из раделителей равна нулю 
  size_t maxSize = 0;

  // текущий размер подстроки
  size_t size = 0;

  // индекс текущей сторки
  size_t ind = 0;

  // массив в котром хранятся индексы строк 
  uint32_t indexCounter[10];

  // индекс масива в котором хрянятся индексы 
  size_t index = 0;

  // просто значение для обнуления индекса
  uint32_t zero = 0;

  try
  {
    // функция выполняет роль чтения каждой строки из файла с последующим подсчетом длины подсроки разделителей
    readFromFile(str, sepRegex, delims, ind, index, maxSize, size, indexCounter);

    std::cout << "Lines with the longest delimiter sequence:\n";

    // вывод строк с подхоядщим решением 
    outputSttrings(ind, indexCounter, str, zero);
  }
  catch (const std::string& what)
  {
    std::cerr << what;
  }

  return 0;
}

// читает строки из файла(елси он существует и непустой), 
void readFromFile
(
  std::string& str,
  std::regex sepRegex,
  std::regex delims,
  size_t& ind,
  size_t& index,
  size_t& maxSize,
  size_t& size,
  uint32_t* indexCounter
  )
{
  // !!! input.txt необходимо создать в папке с проектом, либо елси хотите чтоб открывался другой, то надо поменять в 80 и  строке !!!
  std::ifstream fin("input.txt");
  if (fin.is_open()) {
    if (fin.peek() == EOF) {
      throw std::string("File is empty.\n");
    }
    else {
      for (ind = 0; getline(fin, str, '\n'); ++ind)
      {
        maxSizeOfDelims(ind, index, indexCounter, str, sepRegex, delims, maxSize, size);
      }
      fin.close();
    }
  }
  else {
    throw std::string("Unable to open file!\n");
  }
}

// функция считает длину подстроки из разделителей
uint32_t countOfDelims
(
  std::string& str,
  std::regex sepRegex,
  std::regex delims
)
{
  std::size_t count = 1;
  std::sregex_iterator start(str.begin(), str.end(), delims);
  std::sregex_iterator end;
  for (; start != end; ++start)
  {
    auto s = start->str();
    if (std::regex_match(s, delims)) {
      count = std::max(count, s.size());
    }
  }
  return count;
}

// функция для случая, когда строк удовлетворяющих условию несколько, то они будут записываться в массив для хранения индексов сторк(максимум первых 10 строк, тково условие задачи)
uint32_t maxSizeOfDelims
(
  size_t& ind,
  size_t& index,
  uint32_t* indexCounter,
  std::string& str,
  std::regex sepRegex,
  std::regex delims,
  size_t& maxSize,
  size_t& size
)
{
  size_t count = countOfDelims(str, sepRegex, delims);

  if (size < std::max(maxSize, count)) {
    index = 0;
    indexCounter[index] = ind;
    maxSize = std::max(maxSize, count);
  }
  if (size == count && index != 9) {
    indexCounter[++index] = ind;
  }
  size = maxSize;

  return *indexCounter;
}

// вывод нужных строк
void outputSttrings
(
  size_t& ind,
  uint32_t* indexCounter,
  std::string& str,
  uint32_t& zero
)
{
  std::ifstream finNew("input.txt");
  for (ind = 0; getline(finNew, str, '\n'); ++ind)
  {
    if (ind == indexCounter[zero]) {
      std::cout << str << '\n';
      ++zero;
    }
  }
  finNew.close();
}
