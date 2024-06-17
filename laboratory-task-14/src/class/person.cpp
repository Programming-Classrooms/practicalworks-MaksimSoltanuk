#include "../class/person.hpp"

Person::Person() : name("Sergey") {}

Person::Person(char *str) : name(str) {}

Person::Person(const Person &p) : name(p.name) {}

Person::~Person()
{
    if (name != nullptr)
    {
        delete[] name;
        name = nullptr;
    }
}

char *Person::getName() const
{
    char* res = new char[strlen(name) + 1];
    strcpy(res, name);
    return res;
}

void Person::setName(char *newName)
{
    this->name = newName;
}
