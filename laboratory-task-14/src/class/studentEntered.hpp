#ifndef STUDENTENTERED_HPP
#define STUDENTENTERED_HPP
#include <iostream>
#include <string>
#include <cstdint>

class StudentEntered
{
protected:
    std::string name;
    uint16_t course;
    uint8_t group;
    const uint16_t recordNumber;
    const uint16_t id;
    static uint16_t count;

public:
    // конструкторы и деструктор
    StudentEntered() = delete;
    StudentEntered(std::string, uint16_t, uint8_t, uint16_t);
    StudentEntered(const StudentEntered &);
    ~StudentEntered();
    // сеттеры
    void setName(std::string);
    void setCourse(uint16_t);
    void setGroup(uint8_t);
    // геттеры
    std::string getName() const;
    uint16_t getCourse() const;
    uint16_t getGroup() const;
    uint16_t getRecordNumber() const;
    uint16_t getId() const;
    // вывод
    friend std::ostream &operator<<(std::ostream &, const StudentEntered &);
    // подсчёт среднего
    virtual double midle(){};
};

#endif