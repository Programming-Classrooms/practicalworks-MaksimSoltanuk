#include "../class/studentSecondSession.hpp"

StudentSecondSession::StudentSecondSession(const StudentFirstSession &s, uint16_t m1, uint16_t m2, uint16_t m3, uint16_t m4, uint16_t m5) : StudentFirstSession(s)
{
    marksSecond[0] = m1;
    marksSecond[1] = m2;
    marksSecond[2] = m3;
    marksSecond[3] = m4;
    marksSecond[4] = m5;
}
StudentSecondSession::StudentSecondSession(const StudentFirstSession &rhs, const StudentSecondSession &s) : StudentFirstSession(rhs)
{
    for (size_t i = 0; i < 5; ++i)
    {
        marksSecond[i] = s.marksSecond[i];
    }
}

StudentSecondSession::~StudentSecondSession() {}

void StudentSecondSession::setMarks(uint16_t m1, uint16_t m2, uint16_t m3, uint16_t m4, uint16_t m5)
{
    marksSecond[0] = m1;
    marksSecond[1] = m2;
    marksSecond[2] = m3;
    marksSecond[3] = m4;
    marksSecond[4] = m5;
}

void StudentSecondSession::getMarks() const
{
    for (size_t i = 0; i < 5; ++i)
    {
        std::cout << marksSecond[i] << '\n';
    }
}

double StudentSecondSession::midle()
{
    double res = 0;
    for (size_t i = 0; i < 4; ++i)
    {
        res += marksFirst[i];
    }
    for (size_t i = 0; i < 5; ++i)
    {
        res += marksSecond[i];
    }
    return static_cast<double>(res) / 9;
}

std::ostream &operator<<(std::ostream &out, const StudentSecondSession &s)
{
    out << s.name << '\n'
        << "course: " << s.course << '\n'
        << "group: " << s.group << '\n'
        << "record number: " << s.recordNumber << '\n'
        << "Id: " << s.id << '\n';
    for (size_t i = 0; i < 4; ++i)
    {
        out << s.marksFirst[i] << ' ';
    }
    for (size_t i = 0; i < 5; ++i)
    {
        out << s.marksSecond[i] << ' ';
    }
    out << '\n';
    return out;
}
