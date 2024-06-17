#ifndef FUNC_HHPP
#define FUNC_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <string>
#include <regex>
#include <filesystem>
#include <locale>

#include "src/class/Train.hpp"

void secondPartOfTheTask();

void thirdPartOfTheTask();
void fillingTheVectorForThirdTask(std::vector<std::string> &);
void checkPath(const std::string &);
void checkFile(std::ifstream &, const std::string &);

void fourthPartOfTheTask();
void deleteRowAndColumn(std::vector<std::vector<int>> &, int, int);
void sortRows(std::vector<std::vector<int>> &);

void fifthPartOfTheTask();
struct Student
{
	std::string name;
	int course;
	int group;
};
bool compareByName(const Student &, const Student &);
bool compareByCourseGroupAndName(const Student &, const Student &);

void sixthPartOfTheTask();

#endif
