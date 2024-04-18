#include "../src/class/forestTree.hpp"
#include "forestTree.hpp"

ForestTree::ForestTree(std::string name, size_t years, Type type, size_t amountWood) : Tree(name, years, type), amountWood(amountWood) {}

ForestTree::~ForestTree() {}

void ForestTree::print()
{
    Tree::print();
    std::cout<<this->amountWood<<'\n';
}
