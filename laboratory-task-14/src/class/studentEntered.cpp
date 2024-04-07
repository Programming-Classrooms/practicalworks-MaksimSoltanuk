#include "../class/studentEntered.hpp"

uint16_t StudentEntered::count = 0;

StudentEntered::StudentEntered(std::string n, uint16_t c, uint8_t g, uint16_t r) : name(n), course(c), group(g), recordNumber(r), id(++count) {}

StudentEntered::StudentEntered(const StudentEntered &s) : StudentEntered(s.name, s.course, s.group, s.recordNumber) {}

StudentEntered::~StudentEntered() {}

void StudentEntered::setName(std::string s)
{
    this->name = s;
}

void StudentEntered::setCourse(uint16_t c)
{
    this->course = c;
}

void StudentEntered::setGroup(uint8_t g)
{
    this->group = g;
}

std::string StudentEntered::getName() const
{
    return name;
}

uint16_t StudentEntered::getCourse() const
{
    return course;
}

uint16_t StudentEntered::getGroup() const
{
    return group;
}

uint16_t StudentEntered::getRecordNumber() const
{
    return recordNumber;
}

uint16_t StudentEntered::getId() const
{
    return id;
}

std::ostream &operator<<(std::ostream &out, const StudentEntered &s)
{
    out << s.name << '\n'
        << "course: " << s.course << '\n'
        << "group: " << s.group << '\n'
        << "record number: " << s.recordNumber << '\n'
        << "Id: " << s.id << '\n';
    return out;
}
