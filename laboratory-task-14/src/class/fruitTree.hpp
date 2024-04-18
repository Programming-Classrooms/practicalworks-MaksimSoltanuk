#ifndef FRUITTREE_HPP
#define FRUITTREE_HPP
#include <string>
#include <cstdint>
#include <iostream>
#include "../src/class/tree.hpp"

class FruitTree : public Tree
{
private:
    size_t fruitMass;
    size_t shelfLife;

public:
    FruitTree(std::string, size_t, Type, size_t, size_t);
    ~FruitTree();
    virtual void print() override;
};

#endif