#ifndef PERSON_HPP
#define PERSON_HPP
#include <cstring>
#include <cstdint>
#include <iostream>

class Person
{
protected:
    char *name;

public:
    // конструкторы и деструктор
    Person();
    Person(char *);
    Person(const Person &);
    virtual ~Person();
    // геттер и сеттер
    char *getName() const;
    void setName(char *);
};

#endif