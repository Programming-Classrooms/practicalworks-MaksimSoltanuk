/*
При написании программ использовать нуль–терминированные строки
и работать только с типом char* .Длина каждой строки не превосходит 300
символов.Словом, входящим в состав строки, назовём непрерывную
последовательность символов, ограниченную символами–разделителями,
началом и концом строки.Символы, относящиеся к разделителям, определяет
пользователь, если иное не сказано в условии задачи.Если решить задачу
невозможно, программа должна выдать соответствующее сообщение.

Строка состоит из слов, разделенных ровно одним пробелом, пробелов
перед первым и после последнего слова нет.Получить новую строку, в
начале которой на нечетном месте должно стоять слово только из цифр, а на
четном – другое слово.В конце новой строки поместить те слова, которые не
могут быть записаны согласно приведенному правилу.Дополнительно
можно использовать не более одной вспомогательной строки.
*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
#include <regex>


void functionForSeparateStringIntoLexemes(char*, char*, char*&, std::regex, std::regex, std::regex, std::vector<char*>&, std::vector<char*>&, std::vector<char*>&);
void sortInTheRightOrder(std::vector<char*>&, std::vector<char*>&, std::vector<char*>&);

int main() {

  // вводимая строка
  char str[300];

  // символы-разделители
  char delims[10] = " .,;:|"; 

  // разделенная строка на лексемы
  char* separateOnLexeme;  

  std::cout << "Enter the desired string: ";

  // ввод стороки с клавиатуры
  std::cin.getline(str, 300); 
  std::cout << "Sorted string: ";

  //регулрное выражение для провекрии на слова
  std::regex regularForWords("[A-Za-z]+"); 

  // регулрное выражение для провекрии на числа
  std::regex regularForNumeric("\\d+"); 

  // регулрное выражение для провекрии на лексемы
  std::regex regularForLexeme("([\\w\\W]*)"); 

  //вектора для хранения последовательности слов, чисел
  std::vector<char*> wordVect, numVect, lexVect; 

  functionForSeparateStringIntoLexemes(str, delims, separateOnLexeme, regularForWords, regularForNumeric,
    regularForLexeme, wordVect, numVect, lexVect);

  sortInTheRightOrder(wordVect, numVect, lexVect);

  delete[]separateOnLexeme;
  
  return 0;
}


void functionForSeparateStringIntoLexemes(
  char* str,
  char* delims,
  char*& separateOnLexeme,
  std::regex regularForWords,
  std::regex regularForNumeric,
  std::regex regularForLexeme,
  std::vector<char*>& wordVect,
  std::vector<char*>& numVect,
  std::vector<char*>& lexVect
)
{
  for(char* separateOnLexeme = strtok(str, delims); separateOnLexeme != NULL; separateOnLexeme = strtok(NULL, delims))
  {
    // проверка всех символов текущей части от заданной строки на соответсвие регулярному выражению(для слов)
    if (std::regex_match(separateOnLexeme, regularForWords)) { 

      // если чило, то записываем в веткор хранящий числа
      wordVect.push_back(separateOnLexeme); 
    }

    // проверка всех символов текущей части от заданной строки на соответсвие регулярному выражению(для чисел)
    else if (std::regex_match(separateOnLexeme, regularForNumeric)) { 

      // если число, то записываем в вектор хранящий числа
      numVect.push_back(separateOnLexeme); 
    }

    // проверка всех символов текущей части от заданной строки на соответсвие регулярному выражению(для лексем)
    else if (std::regex_match(separateOnLexeme, regularForLexeme)) { 

      // если не удовлетворило правилам, то тогда записывается в векотор хранящий лексемы
      lexVect.push_back(separateOnLexeme);
    }
  }
}

void sortInTheRightOrder(std::vector<char*>& wordVect, std::vector<char*>& numVect, std::vector<char*>& lexVect) {

  // первый элемент вектора слов
  auto wordVectIter = wordVect.begin();

  // первый элемент вектора чисел
  auto numVectIter = numVect.begin(); 

  // индекатор смены чередования
  bool outFlag = true,

    // является ли текущий элемент последним
     numEndFlag = false, 

    // является ли текущий элемент последним
     wordEndFlag = false;

  // пока два векора не закончатся
  while (!numEndFlag || !wordEndFlag) {// для провекри на конец вектора чисел
    numEndFlag = (numVectIter == numVect.end()); 

    // для проверки на конец вектора слов
    wordEndFlag = (wordVectIter == wordVect.end()); 
    
    // вхождение прозойдет если outFlag(индекатор смены чередования) == true и вектор чиесл не закончился
    if (outFlag && !numEndFlag) {  
      std::cout << *(numVectIter++) << " ";

      // происходит переключение outFlag в случае если один из векторов не закончился (необходимо для чередования вывода чисел и слов)
      outFlag = wordEndFlag ^ !outFlag;
    }

    // вхождение прооизойдет в случае если вектор слов ещё не закончился
    else if (!wordEndFlag) { 
      std::cout << *(wordVectIter++) << " "; 

      // переключение 
      outFlag = numEndFlag ^ !outFlag; 
    }
  }

  // вывод лексем, которые не удовлетворяют числам или словам
  auto lexVectIter = lexVect.begin();
  while (lexVectIter != lexVect.end())
  {
    std::cout << *(lexVectIter++) << " ";
  }
}
