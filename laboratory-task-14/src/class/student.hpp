#ifndef STUDENT_HPP
#define STUDENT_HPP
#include "../class/person.hpp"

class Student : public Person
{
private:
    uint32_t course;
    uint32_t group;

public:
    // конструкторы и деструктор
    Student();
    Student(char *, uint32_t, uint32_t);
    Student(const Student &);
    ~Student();
    // геттеры, сеттеры
    uint32_t getCourse() const;
    uint32_t getGroup() const;
    void setCourse(uint32_t);
    void setGroup(uint32_t);
    // вывод
    friend std::ostream &operator<<(std::ostream &, const Student &);
};

#endif