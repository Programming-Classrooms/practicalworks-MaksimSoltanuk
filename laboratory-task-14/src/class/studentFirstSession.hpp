#ifndef STUDENTFIRSTSESSION_HPP
#define STUDENTFIRSTSESSION_HPP
#include "../class/studentEntered.hpp"

class StudentFirstSession : public StudentEntered
{
protected:
    uint16_t marksFirst[4];

public:
    // конструкторы и деструктор
    StudentFirstSession() = delete;
    StudentFirstSession(std::string, uint16_t, uint8_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t);
    StudentFirstSession(const StudentFirstSession &);
    ~StudentFirstSession();
    // сеттер
    void setMarks(uint16_t, uint16_t, uint16_t, uint16_t);
    // геттер
    void getMarks() const;
    // вывод
    friend std::ostream &operator<<(std::ostream &, const StudentFirstSession &);
    // средний балл за 1 сессию
    double midle() override;
};

#endif