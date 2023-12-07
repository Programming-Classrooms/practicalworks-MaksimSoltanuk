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

int main() 
{
  char str[300];
  char delims[10] = " .,;:|";
  char* separateOnLexeme;  

  std::cout << "Enter the desired string: ";
  std::cin.getline(str, 300); 
  std::cout << "Sorted string: ";

  std::regex regularForWords("[A-Za-z]+"); 
  std::regex regularForNumeric("\\d+"); 
  std::regex regularForLexeme("([\\w\\W]*)"); 
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
    if (std::regex_match(separateOnLexeme, regularForWords)) { 
      wordVect.push_back(separateOnLexeme); 
    }
    else if (std::regex_match(separateOnLexeme, regularForNumeric)) { 
      numVect.push_back(separateOnLexeme); 
    }
    else if (std::regex_match(separateOnLexeme, regularForLexeme)) { 
      lexVect.push_back(separateOnLexeme);
    }
  }
}

void sortInTheRightOrder(std::vector<char*>& wordVect, std::vector<char*>& numVect, std::vector<char*>& lexVect)
{
  auto wordVectIter = wordVect.begin();
  auto numVectIter = numVect.begin(); 
  bool outFlag = true,
     numEndFlag = false, 
     wordEndFlag = false;

  while (!numEndFlag || !wordEndFlag)
  { 
    numEndFlag = (numVectIter == numVect.end()); 
    wordEndFlag = (wordVectIter == wordVect.end()); 
    if (outFlag && !numEndFlag) {  
      std::cout << *(numVectIter++) << " ";
      outFlag = wordEndFlag ^ !outFlag;
    }
    else if (!wordEndFlag) { 
      std::cout << *(wordVectIter++) << " ";
      outFlag = numEndFlag ^ !outFlag; 
    }
  }
  auto lexVectIter = lexVect.begin();
  while (lexVectIter != lexVect.end())
  {
    std::cout << *(lexVectIter++) << " ";
  }
}
