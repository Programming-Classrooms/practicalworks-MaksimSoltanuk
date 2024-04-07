#include "../class/studentFirstSession.hpp"

StudentFirstSession::StudentFirstSession(std::string n, uint16_t c, uint8_t g, uint16_t r, uint16_t m1, uint16_t m2, uint16_t m3, uint16_t m4) : StudentEntered(n, c, g, r)
{
    marksFirst[0] = m1;
    marksFirst[1] = m2;
    marksFirst[2] = m3;
    marksFirst[3] = m4;
}
StudentFirstSession::StudentFirstSession(const StudentFirstSession &rhs) : StudentEntered(rhs.name, rhs.course, rhs.group, rhs.recordNumber)
{
    for (size_t i = 0; i < 4; ++i)
    {
        marksFirst[i] = rhs.marksFirst[i];
    }
}

StudentFirstSession::~StudentFirstSession() {}

void StudentFirstSession::setMarks(uint16_t m1, uint16_t m2, uint16_t m3, uint16_t m4)
{
    marksFirst[0] = m1;
    marksFirst[1] = m2;
    marksFirst[2] = m3;
    marksFirst[3] = m4;
}

void StudentFirstSession::getMarks() const
{
    for (size_t i = 0; i < 4; ++i)
    {
        std::cout << marksFirst[i] << '\n';
    }
}

double StudentFirstSession::midle()
{
    double res = 0;
    for (size_t i = 0; i < 4; ++i)
    {
        res += marksFirst[i];
    }
    res = (static_cast<double>(res) / 4);
    return res;
}
std::ostream &operator<<(std::ostream &out, const StudentFirstSession &s)
{
    out << s.name << '\n'
        << "course: " << s.course << '\n'
        << "group: " << s.group << '\n'
        << "record number: " << s.recordNumber << '\n'
        << "Id: " << s.id << '\n';
    for (size_t i = 0; i < 4; ++i)
    {
        out << s.marksFirst[i] << '\n';
    }
    return out;
}
