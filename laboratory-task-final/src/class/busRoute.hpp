#ifndef BUSROUTE_HPP
#define BUSROUTE_HPP

#include <iostream>
#include <string>
#include <fstream>

struct BusRoute
{
    size_t numOfRoute;
    std::string driverName;
    size_t numOfBus;
    std::string markOfBus;

    friend std::ostream& operator<<(std::ostream&, const BusRoute&);
};

#endif