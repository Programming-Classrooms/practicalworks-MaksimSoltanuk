#include "../src/class/fruitTree.hpp"
#include "fruitTree.hpp"

FruitTree::FruitTree(std::string name, size_t years, Type type, size_t fruitMass, size_t shelfLife) : Tree(name, years, type), fruitMass(fruitMass), shelfLife(shelfLife) {}

FruitTree::~FruitTree() {}

void FruitTree::print()
{
    Tree::print();
    std::cout << this->fruitMass << '\n'
              << this->shelfLife << '\n';
}
