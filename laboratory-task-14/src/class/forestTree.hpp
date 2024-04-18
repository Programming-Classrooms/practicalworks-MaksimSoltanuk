#ifndef FORESTTREE_HPP
#define FORESTTREE_HPP
#include <string>
#include <cstdint>
#include <iostream>
#include "../src/class/tree.hpp"

class ForestTree : public Tree
{
private:
    size_t amountWood;

public:
    ForestTree(std::string, size_t, Type, size_t);
    ~ForestTree();
    virtual void print() override;
};

#endif