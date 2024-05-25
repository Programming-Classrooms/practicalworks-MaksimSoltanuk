#include "Train.hpp"

Train::Train() : number(0), destination(""), type(""), departureTime(""), travelTime(0) {}

Train::Train(size_t num, std::string destination, std::string type, std::string departureTime, size_t travelTime) : number(num), destination(destination), type(type), departureTime(departureTime), travelTime(travelTime)
{
    if (static_cast<int>((departureTime[0] + departureTime[1])) > 24 || static_cast<int>((departureTime[0] + departureTime[1])) < 0 || static_cast<int>((departureTime[3] + departureTime[4])) > 59 || static_cast<int>((departureTime[3] + departureTime[4])) < 0)
    {
        throw std::invalid_argument("Неправильный формат времни");
    }
}

Train::~Train() {}
