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


void functionForSeparateStringIntoLexemes(uint32_t, uint32_t, std::string, std::string, std::string,
  std::string&, std::regex, std::regex, std::regex, std::vector<std::string>&, std::vector<std::string>&);

void sortingInTheRightOrder(std::vector<std::string>&, std::vector<std::string>&, std::string&);

int main() {

  std::string str; // вводимая строка
  std::string delims = " .,;:|"; // символы-разделители
    
  std::string word; // слова
  std::string numeric; // числа
  std::string lexeme; // лексемы
  std::string separateOnLexeme; // разделенная строка на лексемы 

  uint32_t startPos = 0; // начальная позиция
  uint32_t delimPos = 0; // позиция символа-разделителя

  std::cout << "Enter the desired string: ";
  std::getline(std::cin, str); // ввод стороки с клавиатуры
  std::cout << "Sorted string: ";

  std::regex regularForWords("[A-Za-z]+"); //регулрное выражение для провекрии на слова \w
  std::regex regularForNumeric("\\d+"); // регулрное выражение для провекрии на числа
  std::regex regularForLexeme("([\\w\\W]*)"); // регулрное выражение для провекрии на лексемы

  std::vector<std::string> wordVect, numVect; //вектора для хранения последовательности слов, чисел

  functionForSeparateStringIntoLexemes(startPos, delimPos, str, delims, separateOnLexeme, lexeme, regularForWords, regularForNumeric,
    regularForLexeme, wordVect, numVect);

  sortingInTheRightOrder(wordVect, numVect, lexeme);
  
  return 0;
}


void functionForSeparateStringIntoLexemes(
  uint32_t startPos,
  uint32_t delimPos, 
  std::string str,
  std::string delims,
  std::string separateOnLexeme,
  std::string& lexeme,
  std::regex regularForWords,
  std::regex regularForNumeric,
  std::regex regularForLexeme,
  std::vector<std::string>& wordVect,
  std::vector<std::string>& numVect
)
{

  while ((startPos = str.find_first_not_of(delims, startPos)) != -1) { // делим до момента пока не закончиться строка
    delimPos = str.find_first_of(delims, startPos); // позиция раделителя
    separateOnLexeme = str.substr(startPos, delimPos - startPos); // разделение на лексему

    if (std::regex_match(separateOnLexeme, regularForWords)) { // проверка всех символов текущей части от заданной строки на соответсвие регулярному выражению(для слов)
        wordVect.push_back(separateOnLexeme); // если чило, то записываем в веткор хранящий числа
    }

    else if (std::regex_match(separateOnLexeme, regularForNumeric)) { // проверка всех символов текущей части от заданной строки на соответсвие регулярному выражению(для чисел)
        numVect.push_back(separateOnLexeme); // если число, то записываем в вектор хранящий числа
    }

    else if (std::regex_match(separateOnLexeme, regularForLexeme)) { // проверка всех символов текущей части от заданной строки на соответсвие регулярному выражению(для лексем)
        lexeme += separateOnLexeme; // если не удовлетворило правилам, то тогда записывается в строку хранящую лексемы
        lexeme += ' ';
    }
    startPos = delimPos; // переприсваем начальную позицию на конец, чтоб дальше делить строку на лексемы уже оттуда  
  }
}

void sortingInTheRightOrder(std::vector<std::string>& wordVect, std::vector<std::string>& numVect, std::string& lexeme) {auto wordVectIter = wordVect.begin(); // первый элемент вектора слов
  auto numVectIter = numVect.begin(); // первый элемент вектора чисел
  bool outFlag = true, // индекатор смены чередования
     numEndFlag = false, // является ли текущий элемент последним
     wordEndFlag = false; // является ли текущий элемент последним
  while (!numEndFlag || !wordEndFlag) { // пока два векора не закончатся
    numEndFlag = (numVectIter == numVect.end()); // для провекри на конец вектора чисел
    wordEndFlag = (wordVectIter == wordVect.end()); // для проверки на конец вектора слов
    
    if (outFlag && !numEndFlag) {  // вхождение прозойдет если outFlag(индекатор смены чередования) == true и вектор чиесл не закончился
      std::cout << *(numVectIter++) << " "; // вывод эелементов векторов чисел
      outFlag = wordEndFlag ^ !outFlag; // происходит переключение outFlag в случае если один из векторов не закончился (необходимо для чередования вывода чисел и слов)
    }
    else if (!wordEndFlag) { // вхождение прооизойдет в случае если вектор слов ещё не закончился
      std::cout << *(wordVectIter++) << " "; // вывод элементов вектора слов
      outFlag = numEndFlag ^ !outFlag; // переключение 
    }
  }
  std::cout << lexeme; // вывод лексем, которые не удовлетворяют числам или словам
}