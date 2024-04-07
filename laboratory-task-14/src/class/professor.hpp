#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP
#include "../class/person.hpp"

class Professor : public Person
{
private:
    char *kafedraName;

public:
    // конструкоры и деструктор
    Professor();
    Professor(char *, char *);
    Professor(const Professor &);
    ~Professor();
    // геттер и сеттер
    char *getKafedraName() const;
    void setKafedraName(char *);
    // вывод
    friend std::ostream &operator<<(std::ostream &, const Professor &);
};

#endif