/*
  Словом, входящим в состав строки, назовём непрерывную
  последовательность символов, ограниченную символами–разделителями,
  началом и концом строки.Символы, относящиеся к разделителям, определяет
  пользователь, если иное не сказано в условии задачи.Если решить задачу
  невозможно, программа должна выдать соответствующее сообщение.

  Строка состоит из слов. Получить новую строку, в начале которой на
  нечетном месте должно стоять слово только из цифр, а на четном – другое
  слово. В конце новой строки поместить те слова, которые не могут быть
  записаны согласно приведенному правилу.
*/


#include <iostream>
#include <vector>
#include <string>
#include <regex>


void functionForSeparateStringIntoLexemes(std::string&, std::regex, std::regex, std::vector<std::string>&, std::vector<std::string>&);
void sortingInTheRightOrder(std::vector<std::string>&, std::vector<std::string>&, std::string&);

int main() {

  std::string str; // вводимая строка
  std::string lexeme;//лексемы

  std::cout << "Enter the desired string: ";
  std::getline(std::cin, str);//ввод стороки с клавиатуры
  std::cout << "Sorted string: ";
 
  std::regex regularForNumeric("\\d+"); // регулрное выражение для провекрии на числа
  std::regex sepRegex("\\W+"); // регулрное выражение для провекрии на разделители

  std::vector<std::string> wordVect, numVect; //вектора для хранения последовательности слов и неподходящих под условие лексем, чисел
  
  functionForSeparateStringIntoLexemes(str, sepRegex, regularForNumeric, wordVect, numVect);
  sortingInTheRightOrder(wordVect, numVect, lexeme);
  
  return 0;
}


void functionForSeparateStringIntoLexemes(
  std::string& str,
  std::regex sepRegex,
  std::regex regularForNumeric,
  std::vector<std::string>& wordVect,
  std::vector<std::string>& numVect
) 
{
  std::sregex_token_iterator iter(str.begin(), str.end(), sepRegex, -1); // iter выпоняет роль "контейнера" для хранения лексем разделенных регулярным выражением
  for (; iter != std::sregex_token_iterator(); ++iter) { // пока iter не укажет на номер за послденим "контейнером" будет двигаться по всем дальше
    std::string lexeme = std::string(*iter);
    if (std::regex_match(lexeme, regularForNumeric)) { // проврека регулярным выражением на число
      numVect.push_back(lexeme); // в случае если число - записывается в вектор чисел
    }
    else {
      wordVect.push_back(lexeme); // в случае если не число - записывается в вектор слов(лексем)
    }
  }
}

void sortingInTheRightOrder(std::vector<std::string>& wordVect, std::vector<std::string>& numVect, std::string& lexeme) {
  
  auto wordVectIter = wordVect.begin(); // первый элемент вектора слов
  auto numVectIter = numVect.begin(); // первый элемент вектора чисел
  bool outFlag = true, // индекатор смены чередования
    numEndFlag = false, // является ли текущий элемент последним
    wordEndFlag = false; // является ли текущий элемент последним
  while (!numEndFlag || !wordEndFlag) { // пока два векора не закончатся
    numEndFlag = (numVectIter == numVect.end()); // для провекри на конец вектора чисел
    wordEndFlag = (wordVectIter == wordVect.end()); // первый элемент вектора чисел

    if (outFlag && !numEndFlag) { // вхождение прозойдет если outFlag(индекатор смены чередования) == true и вектор чиесл не закончился
      std::cout << *(numVectIter++) << " "; // вывод эелементов вектора чисел
      outFlag = wordEndFlag ^ !outFlag; // происходит переключение outFlag в случае если один из векторов не закончился (необходимо для чередования вывода чисел и слов)
    }
    else if (!wordEndFlag) { // вхождение прооизойдет в случае если вектор слов ещё не закончился
      std::cout << *(wordVectIter++) << " "; // вывод элементов вектора слов и после лексем не удовлетворяющих условию
      outFlag = numEndFlag ^ !outFlag; // переключение
    }
  }
}
