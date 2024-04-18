/*
    Задание 1

    Разработать иерархию классов.
    У базового класса Person одно поле – строка типа char*, содержащая фамилию, имя, отчество (возможно с пробелами).
    У производного класса Student дополнительно к полям базового класса два числовых поля - курс и группа.
    У производного класса Professor дополнительно к полям базового класса поле - строка типа char*, содержащая название кафедры (возможно с пробелами).
    Реализовать для вышеперечисленных классов конструкторы, деструкторы, методы типа set и get, метод вывода на экран информации об объектах каждого типа.
    В головной программе создать меню со следующими пунктами:
        1. Ввести студента
        2. Ввести преподавателя
        3. Вывести список студентов
        4. Вывести список преподавателей
        5. Закончить работу
    Все создаваемые объекты хранить в одном массиве.
*/

/*
    Задание 2

    Разработать следующие классы:
    1. Базовый класс Student с полями:
        ◦ уникальный неизменяемый идентификатор, создаваемый автоматически - константное поле,
        ◦ имя (string),
        ◦ курс,
        ◦ группа, 
        ◦ номер зачетки (неизменяемое после создания объекта поле)- константное поле;
    2. Производный от базового класса класс «студент после первой сессии».
        Добавить поле – массив из 4 оценок;
    3. Производный от класса «студент после первой сессии» класс «студент после второй сессии».
        Добавить поле – массив из 5 оценок.
        Реализовать конструкторы с параметрами и конструктор копирования.
        Запретить вызов конструктора без параметров.
        Обеспечить уникальность идентификатора. Реализовать методы:
            ◦ set- и get-методы для полей класса Student (где это допустимо);
            ◦ для производных классов определить методы для доступа к оценке (чтение и изменение);
        Во всех 3 классах перегрузить оператор вывода в поток (<<) для вывода сведений о студенте и об оценках.
        Решение оформить как многофайловый проект с использованием стража многократного включения.
        Определить метод подсчета среднего балла (полиморфный):
            – у класса «студент после первой сессии» - после 1 сессии;
            – у класса «студент после второй сессии» - за год.
        Определить средний балл в указанной группе после первой сессии, после двух сессий.
*/

#include "../class/person.hpp"
#include "../class/student.hpp"
#include "../class/professor.hpp"
#include "../class/studentEntered.hpp"
#include "../class/studentFirstSession.hpp"
#include "../class/studentSecondSession.hpp"
#include "../class/tree.hpp"
#include "../class/forestTree.hpp"
#include "../class/fruitTree.hpp"
#include "../class/caseTree.hpp"
#include "fstream"

uint16_t getSize();
void menu(Person **, const uint16_t &);
void menuForSecondLab(StudentEntered **, StudentFirstSession);
bool checkFile(std::ifstream &);

int main()
{
    /*   // демонстрация первого задания
      uint16_t size = getSize();
      Person **arr = new Person *[size];
      Student A("jenya", 5, 8);
      std::cout << A;
      Professor B("fedor", "mexmat");
      std::cout << B;

      // демнострация второго задания
      StudentEntered C("kostya", 1, 2, 8);
      std::cout << C;
      StudentFirstSession D("andrey", 1, 2, 8, 9, 8, 6, 10);
      std::cout << D;
      StudentSecondSession E(D, 9, 8, 7, 9, 10);
      std::cout << C;
      StudentSecondSession F(D, E);
      std::cout << F;
      std::cout << D.midle() << ' ' << F.midle() << '\n';
      StudentEntered *arr2[5];

      try
      {
          // меню для первого задания
          menu(arr, size);

          // меню для второго задания
          menuForSecondLab(arr2, D);
      }
      catch (const std::logic_error &err)
      {
          std::cerr << err.what() << '\n';
      }

      delete[] arr; */
   /*  CaseTree arrTree(3);
    FruitTree *first = new FruitTree("elka", 8, Type::pine, 9, 2);

    for (size_t i = 0; i < 3; ++i)
    {
        arrTree[i] = dynamic_cast<FruitTree *>(first);
    } */

    return 0;
}

uint16_t getSize()
{
    uint16_t normalSize;
    std::cout << "how many people you want to add?\n";
    std::cin >> normalSize;
    while (normalSize < 0)
    {
        std::cout << "input natural number\n";
        std::cin >> normalSize;
    }
    return normalSize;
}

void menu(Person **arr, const uint16_t &size)
{
    uint16_t choice;
    uint16_t count = 0, sCount = 0, prCount = 0;
    while (choice != 5)
    {
        std::cout << "what you want?\n\n1.input student\n2.input professor\n3.output student's list\n4.output professor's list\n5.the end\n";
        std::cin >> choice;
        while (choice < 0 && choice > 5)
        {
            std::cout << "input from 1 to 5\n";
            std::cin >> choice;
        }
        switch (choice)
        {
        case 1:
            char name[100];
            uint32_t course;
            uint32_t group;
            std::cout << "input name\n";
            std::cin.ignore();
            std::cin.getline(name, 100);
            std::cout << "input course\n";
            std::cin >> course;
            std::cout << "input group\n";
            std::cin >> group;
            arr[count] = new Student(name, course, group);
            ++count;
            ++sCount;
            if (count == size)
            {
                std::cout << "you input all people\n";
                return;
            }
            break;
        case 2:
            char nameSecond[100];
            char kafedraName[100];
            std::cout << "input name\n";
            std::cin.ignore();
            std::cin.getline(nameSecond, 100);
            std::cout << "input name of kafedra\n";
            std::cin.ignore();
            std::cin.getline(kafedraName, 100);
            arr[count] = new Professor(nameSecond, kafedraName);
            ++count;
            ++prCount;
            if (count == size)
            {
                std::cout << "you input all people\n";
                return;
            }
            break;
        case 3:
            if (sCount == 0)
            {
                std::cout << "student list is empty\n";
            }
            else
            {
                for (size_t i = 0; i < count; ++i)
                {
                    if (dynamic_cast<Student *>(arr[i]))
                    {
                        std::cout << dynamic_cast<Student *>(arr[i])->getName() << '\n'
                                  << "course: " << dynamic_cast<Student *>(arr[i])->getCourse() << '\n'
                                  << "group: " << dynamic_cast<Student *>(arr[i])->getGroup() << '\n';
                    }
                }
            }
            break;
        case 4:
            if (prCount == 0)
            {
                std::cout << "professor list is empty\n";
            }
            else
            {
                for (size_t i = 0; i < count; ++i)
                {
                    if (dynamic_cast<Professor *>(arr[i]))
                    {
                        std::cout << dynamic_cast<Professor *>(arr[i])->getName() << '\n'
                                  << "kafedra name: " << dynamic_cast<Professor *>(arr[i])->getKafedraName() << '\n';
                    }
                }
            }
            break;
        case 5:
            return;
            break;
        default:
            break;
        }
    }
}

void menuForSecondLab(StudentEntered **arr, StudentFirstSession B)
{
    std::string name = "";
    uint16_t m1, m2, m3, m4, m5;
    uint16_t course;
    uint16_t group, groupYouWant;
    uint16_t recordNumber;
    double res = 0.0;
    uint16_t choice;
    uint16_t count = 0, countColF = 0, countColS = 0;
    while (count != 3)
    {
        std::cout << "what you want?\n\n1.input student after first session\n2.input student after second session\n3.output midle mark of group after first session\n4.output midle mark of group after second session\n5.stop\n";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            std::cout << "input name\n";
            std::cin.ignore();
            std::getline(std::cin, name);
            std::cout << "input course\n";
            std::cin >> course;
            std::cout << "input group\n";
            std::cin >> group;
            std::cout << "input record number\n";
            std::cin >> recordNumber;
            std::cout << "input 4 marks\n";
            std::cin >> m1 >> m2 >> m3 >> m4;
            arr[count] = new StudentFirstSession(name, course, group, recordNumber, m1, m2, m3, m4);
            ++count;
            break;
        case 2:
            std::cout << "input 5 marks\n";
            std::cin >> m1 >> m2 >> m3 >> m4 >> m5;
            arr[count] = new StudentSecondSession(B, m1, m2, m3, m4, m5);
            ++count;
            break;
        case 3:
            std::cout << "what group you want?\n";
            std::cin >> groupYouWant;
            for (size_t i = 0; i < 2; ++i)
            {
                if (dynamic_cast<StudentFirstSession *>(arr[i]) && arr[i]->getGroup() == groupYouWant)
                {
                    res += dynamic_cast<StudentFirstSession *>(arr[i])->midle();
                    ++countColF;
                }
            }
            if (res == 0.0)
            {
                std::cout << "haven't this group";
            }
            else
            {
                res = res / countColF;
                std::cout << "midle mark in this group: " << res << '\n';
            }
            res = 0.0;
            countColF = 0;
            break;
        case 4:
            std::cout << "what group you want?\n";
            std::cin >> groupYouWant;
            for (size_t i = 0; i < 2; ++i)
            {
                if (dynamic_cast<StudentSecondSession *>(arr[i]) && arr[i]->getGroup() == groupYouWant)
                {
                    res += dynamic_cast<StudentSecondSession *>(arr[i])->midle();
                    ++countColS;
                }
            }
            if (res == 0.0)
            {
                std::cout << "haven't this group";
            }
            else
            {
                res = res / countColS;
                std::cout << "midle mark in this group: " << res << '\n';
            }
            res = 0.0;
            countColS = 0;
            break;
        case 5:
            count = 2;
            break;
        default:
            std::cout << ("NO");
            break;
        }
    }
}

bool checkFile(std::ifstream &file)
{
    if (!file.good())
    {
        throw std::logic_error("not okey");
    }
    if (!file)
    {
        throw std::logic_error("don't exist");
    }
    if (file.peek() == EOF)
    {
        throw std::logic_error("empty");
    }
    return true;
}