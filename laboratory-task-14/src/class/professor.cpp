#include "../class/professor.hpp"

Professor::Professor() : Person(), kafedraName("PVO") {}

Professor::Professor(char *name, char *kafName) : Person(name), kafedraName(kafName) {}

Professor::Professor(const Professor &pr) : Person(pr.name), kafedraName(pr.kafedraName) {}

Professor::~Professor()
{
    if (kafedraName != nullptr)
    {
        delete[] kafedraName;
        kafedraName = nullptr;
    }
}

char *Professor::getKafedraName() const
{
    return kafedraName;
}

void Professor::setKafedraName(char *newName)
{
    this->kafedraName = newName;
}

std::ostream &operator<<(std::ostream &out, const Professor &pr)
{
    out << pr.name << '\n'
        << pr.kafedraName << '\n';
    return out;
}
