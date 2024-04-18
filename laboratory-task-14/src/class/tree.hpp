#ifndef TREE_HPP
#define TREE_HPP
#include <string>
#include <cstdint>
#include <iostream>

enum class Type
{
    pine,
    leaf
};

class Tree
{
protected:
    std::string name;
    size_t years;
    Type type;

public:
    Tree(std::string, size_t, Type);
    ~Tree();
    virtual void print();

    std::string getName() const;
    size_t getYears() const;
    Type getType() const;
};

#endif