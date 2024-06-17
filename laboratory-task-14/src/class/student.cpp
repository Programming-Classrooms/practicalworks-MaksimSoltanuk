#include "../class/student.hpp"

Student::Student() : Person(), course(1), group(1) {}

Student::Student(char *name, uint32_t c, uint32_t g) : Person(name), course(c), group(g) {}

Student::Student(const Student &s) : Person(s.name), course(s.course), group(s.group) {}

Student::~Student() {}

uint32_t Student::getCourse() const
{
    return course;
}

uint32_t Student::getGroup() const
{
    return group;
}

void Student::setCourse(uint32_t newCourse)
{
    if (newCourse <= 0 || newCourse >= 8)
    {
        throw std::logic_error("course only from 1 to 7");
    }
    this->course = newCourse;
}

void Student::setGroup(uint32_t newGroup)
{
    if (newGroup <= 0)
    {
        throw std::logic_error("group can be only natural number");
    }
    this->group = newGroup;
}

std::ostream &operator<<(std::ostream &out, const Student &s)
{
    out << s.name << '\n'
        << "course: " << s.course << "\n"
        << "group: " << s.group << '\n';
    return out;
}
