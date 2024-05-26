#ifndef TRAIN_HPP
#define TRAIN_HPP

#include <string>
#include <iostream>
#include <vector>

class Train
{
public:
    size_t number;
    std::string destination;
    std::string type;
    std::string departureTime;
    size_t travelTime;

    // Конструтор по умолчанию
    Train();
    // Конструтор с параметрами
    Train(size_t, std::string, std::string, std::string, size_t);
    // деструктор
    ~Train();
};

#endif
