#include "../src/class/tree.hpp"
#include "tree.hpp"

Tree::Tree(std::string name, size_t years, Type type) : name(name), years(years), type(type) {}

Tree::~Tree() {}

void Tree::print()
{
    std::cout << this->name << '\n'
              << this->years << '\n'
              << (this->type == Type::pine ? "pine" : "leaf") << '\n';
}

std::string Tree::getName() const
{
    return this->name;
}

size_t Tree::getYears() const
{
    return this->years;
}

Type Tree::getType() const
{
    return this->type;
}
