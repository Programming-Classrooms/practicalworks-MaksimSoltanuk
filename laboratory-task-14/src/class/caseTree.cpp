#include "caseTree.hpp"

CaseTree::CaseTree(size_t size) : caseForTree(std::vector<Tree *>(size, nullptr)) {}

CaseTree::~CaseTree() 
{
    for (auto & tree : caseForTree) 
    {
        delete tree;
    }
}

void CaseTree::print()
{
    size_t size = caseForTree.size();

    for (size_t i = 0; i < size; ++i)
    {
        if (caseForTree[i] != nullptr)
        {
            caseForTree[i]->print();
            std::cout << '\n';
        }
    }
}

void CaseTree::countTypes()
{
    size_t countLeaf = 0, countPine = 0;
    size_t countFruit = 0, countForest = 0;

    for (size_t i = 0; i < caseForTree.size(); ++i)
    {
        if (caseForTree[i]->getType() == Type::pine)
        {
            ++countPine;
        }
        if (caseForTree[i]->getType() == Type::leaf)
        {
            ++countLeaf;
        }
        if (dynamic_cast<FruitTree *>(caseForTree[i]))
        {
            ++countFruit;
        }
        if (dynamic_cast<ForestTree *>(caseForTree[i]))
        {
            ++countForest;
        }
    }

    std::cout << countForest << " forest trees" << '\n'
              << countFruit << " fruit trees" << '\n'
              << countPine << "  pine trees" << '\n'
              << countLeaf << " leaf trees" << '\n';
}

void CaseTree::sortUpForName()
{
    size_t size = caseForTree.size();

    for (size_t i = 1; i < size; ++i)
    {
        for (size_t j = i; j > 0 && caseForTree[j - 1]->getName() > caseForTree[j]->getName(); --j)
        {
            auto temp = caseForTree[j - 1];
            caseForTree[j - 1] = caseForTree[j];
            caseForTree[j] = temp;
        }
    }

    for (size_t i = 0; i < size; ++i)
    {
        caseForTree[i]->print();
    }
}


Tree* CaseTree::operator[](size_t i)
{
    return this->caseForTree[i];
}
