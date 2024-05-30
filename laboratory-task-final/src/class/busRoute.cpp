#include "busRoute.hpp"

std::ostream &operator<<(std::ostream &out, const BusRoute &obj)
{
    out << "num of route: " << obj.numOfRoute << '\n';
    out << "driver name: " << obj.driverName << '\n';
    out << "num of bus: " << obj.numOfBus << '\n';
    out << "mark of bus: " << obj.numOfRoute << '\n';
    out << '\n';
    return out;
}
