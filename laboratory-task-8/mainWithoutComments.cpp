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

  std::string str; 
  std::string lexeme;

  std::cout << "Enter the desired string: ";
  std::getline(std::cin, str);
  std::cout << "Sorted string: ";
 
  std::regex regularForNumeric("\\d+");
  std::regex sepRegex("\\W+"); 

  std::vector<std::string> wordVect, numVect; 
  
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
  std::sregex_token_iterator iter(str.begin(), str.end(), sepRegex, -1); 
  for (; iter != std::sregex_token_iterator(); ++iter) { 
    std::string lexeme = std::string(*iter);
    if (std::regex_match(lexeme, regularForNumeric)) { 
      numVect.push_back(lexeme);
    }
    else {
      wordVect.push_back(lexeme); 
    }
  }
}

void sortingInTheRightOrder(std::vector<std::string>& wordVect, std::vector<std::string>& numVect, std::string& lexeme) {
  
  auto wordVectIter = wordVect.begin(); 
  auto numVectIter = numVect.begin(); 
  bool outFlag = true, 
    numEndFlag = false, 
    wordEndFlag = false; 
  while (!numEndFlag || !wordEndFlag) { 
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
}
