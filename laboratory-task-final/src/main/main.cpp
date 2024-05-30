#include <iostream>
#include "../class/busRoute.hpp"
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>

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
    std::sort(vec.begin(), vec.end(), [&](BusRoute a, BusRoute b)
              { return a.numOfBus < b.numOfBus; });
    outputVector(vec);
}

void sortByNumORoute(std::vector<BusRoute> &vec)
{
    std::sort(vec.begin(), vec.end(), [&](BusRoute a, BusRoute b)
              { return a.numOfRoute < b.numOfRoute; });
    outputVector(vec);
}

void moveFormVectorToMap(std::vector<BusRoute> &vec, std::multimap<size_t, BusRoute> &mapOfBus)
{
    for (auto &item : vec)
    {
        mapOfBus.insert(std::make_pair(item.numOfRoute, item));
    }
}

void allBusOfThisRoute(std::multimap<size_t, BusRoute> &mapOfBus)
{
    std::cout << "Какой номер маршрута хотите найти?\n";
    size_t num = 0;
    size_t count = 0;
    std::cin >> num;

    for (auto &item : mapOfBus)
    {
        if (item.first == num)
        {
            std::cout << item.second << '\n';
            ++count;
        }
    }
    if (!count)
    {
        std::cout << "Нет автобусов по этому маршруту\n\n";
    }
}

void allDriversOnThisMarkOfBus(std::multimap<size_t, BusRoute> &mapOfBus)
{
    std::cout << "Какая марка интересует?\n";
    std::string nameMarkOfBus;
    size_t count = 0;
    std::cin >> nameMarkOfBus;

    for (auto &item : mapOfBus)
    {
        if (item.second.markOfBus == nameMarkOfBus)
        {
            std::cout << item.second.driverName << '\n';
            ++count;
        }
    }
    if (!count)
    {
        std::cout << "Нет такой марки\n\n";
    }
}

void deleteByNumOfRoute(std::multimap<size_t, BusRoute> mapOfBus)
{
    std::cout << "Какой маршрут удалить?\n";
    size_t num;
    size_t count = 0;
    std::cin >> num;

    for (auto &item : mapOfBus)
    {
        if (item.first == num)
        {
            mapOfBus.erase(num);
            ++count;
            break;
        }
    }
    if (!count)
    {
        std::cout << "Нет такого маршрута\n\n";
    }
}

void findWithMoreMarks(std::multimap<size_t, BusRoute> mapOfBus, std::vector<BusRoute> vec)
{
    std::vector<size_t> countForThisRoute;
    size_t count = 0;
    std::set<std::string> set;
    std::map<size_t, std::set<std::string>> routeAndCount;

    for (const auto &item : mapOfBus)
    {
        routeAndCount[item.first].insert(item.second.markOfBus);
    }

    for (const auto &item : routeAndCount)
    {
        countForThisRoute.push_back(item.second.size());
    }

    for (const auto &item : countForThisRoute)
    {
        std::cout << item << " ";
    }

    std::cout << "Номер маршрута, который содержит наиболее большое количество марок:";
}

int main()
{
    try
    {
        // первая задача
        std::vector<BusRoute> vec;
        putDataInVector(vec);
        sortByNumOfBus(vec);
        sortByNumORoute(vec);

        // вторая задача
        std::multimap<size_t, BusRoute> mapOfBus;
        moveFormVectorToMap(vec, mapOfBus);
        allBusOfThisRoute(mapOfBus);
        allDriversOnThisMarkOfBus(mapOfBus);
        deleteByNumOfRoute(mapOfBus);

        // третья задача
        findWithMoreMarks(mapOfBus, vec);
    }
    catch (const std::invalid_argument &err)
    {
        std::cerr << err.what() << '\n';
    }
    return 0;
}
