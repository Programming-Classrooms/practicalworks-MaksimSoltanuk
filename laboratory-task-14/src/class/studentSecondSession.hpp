#ifndef STUDENTSECONDSESSION_HPP
#define STUDENTSECONDSESSION_HPP
#include "../class/studentFirstSession.hpp"

class StudentSecondSession : public StudentFirstSession
{
protected:
    uint16_t marksSecond[5];

public:
    // конструкторы и деструктор
    StudentSecondSession() = delete;
    StudentSecondSession(const StudentFirstSession &, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t);
    StudentSecondSession(const StudentFirstSession &, const StudentSecondSession &);
    ~StudentSecondSession();
    // сеттер
    void setMarks(uint16_t, uint16_t, uint16_t, uint16_t, uint16_t);
    // геттер
    void getMarks() const;
    // вывод
    friend std::ostream &operator<<(std::ostream &, const StudentSecondSession &);
    // средний балл за год
    double midle() override;
};

#endif