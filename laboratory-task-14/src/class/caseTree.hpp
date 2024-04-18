#ifndef CASETREE_HPP
#define CASETREE_HPP
#include <string>
#include <cstdint>
#include <iostream>
#include <vector>
#include "../src/class/tree.hpp"
#include "../src/class/fruitTree.hpp"
#include "../src/class/forestTree.hpp"

class CaseTree
{
private:
    std::vector<Tree *> caseForTree;

public:
    CaseTree(size_t);
    ~CaseTree();
    void print();
    void countTypes();
    void sortUpForName();
    Tree* operator[](size_t);
};

#endif