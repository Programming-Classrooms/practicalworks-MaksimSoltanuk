#include <iostream>
#include "../class/busRoute.hpp"
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

void checkFile(std::ifstream &fin)
{
    if (!fin.is_open())
    {
        throw std::invalid_argument("file not open");
    }
    if (!fin.good())
    {
        throw std::invalid_argument("file not good");
    }
}

std::vector<BusRoute> putDataInVector(std::vector<BusRoute> &vec)
{
    BusRoute obj;
    std::ifstream fin("src/files/busFile.txt");
    checkFile(fin);
    std::string str;
    size_t count = 1;
    while (fin >> str)
    {
        if (count % 4 == 1)
        {
            obj.numOfRoute = std::stoi(str);
        }
        if (count % 4 == 2)
        {
            obj.driverName = str;
        }
        if (count % 4 == 3)
        {
            obj.numOfBus = std::stoi(str);
        }
        if (count % 4 == 0)
        {
            obj.markOfBus = str;
            vec.push_back(obj);
        }
        ++count;
    }
    return vec;
}

void outputVector(const std::vector<BusRoute> &vec)
{
    for (const auto &item : vec)
    {
        std::cout << item << '\n';
    }
}

void sortByNumOfBus(std::vector<BusRoute> &vec)
{
    std::sort(vec.begin(),vec.end(), [&](BusRoute a, BusRoute b){ return a.numOfBus < b.numOfBus; });
    outputVector(vec);
}

void sortByNumORoute(std::vector<BusRoute> &vec)
{
    std::sort(vec.begin(),vec.end(), [&](BusRoute a, BusRoute b){ return a.numOfRoute < b.numOfRoute; });
    outputVector(vec);
}

int main()
{
    try
    {
        std::vector<BusRoute> vec;
        putDataInVector(vec);
        sortByNumOfBus(vec);
        sortByNumORoute(vec);
    }
    catch (const std::invalid_argument &err)
    {
        std::cerr << err.what() << '\n';
    }
    return 0;
}
