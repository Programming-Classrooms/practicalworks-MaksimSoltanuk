#include <algorithm>
#include <iterator>
#include <fstream>
#include <iostream>
#include "../class/library.hpp"

void checkFile(std::ofstream &fout)
{
	if (!fout.is_open())
	{
		throw std::runtime_error("File is not open\n");
	}
	if (fout.fail())
	{
		throw std::runtime_error("File operation failed\n");
	}
	if (!fout.good())
	{
		throw std::runtime_error("File state is not good\n");
	}
}

void fishTheyCaught(std::ofstream &fout, std::set<std::string> fisher1, std::set<std::string> fisher2, std::set<std::string> fisher3)
{
	fout << "---------------------------------------------------------------------------------------------\n";
	fout << "first fiser have:\n";

	for (auto item : fisher1)
	{
		fout << item << "\t";
	}

	fout << '\n';
	fout << '\n';
	fout << "second fiser have:\n";

	for (auto item : fisher2)
	{
		fout << item << "\t";
	}

	fout << '\n';
	fout << '\n';
	fout << "third fiser have:\n";

	for (auto item : fisher3)
	{
		fout << item << "\t";
	}

	fout << '\n';
	fout << '\n';
}

std::set<std::string> unionFishes(std::set<std::string> fisher1, std::set<std::string> fisher2, std::set<std::string> fisher3)
{
	std::set<std::string> unionFish;
	std::set<std::string> temp;

	std::set_union(fisher1.begin(), fisher1.end(), fisher2.begin(), fisher2.end(), std::inserter(temp, temp.begin()));
	std::set_union(temp.begin(), temp.end(), fisher3.begin(), fisher3.end(), std::inserter(unionFish, unionFish.begin()));

	return unionFish;
}

void haveOneOrMore(std::ofstream &fout, std::set<std::string> fisher1, std::set<std::string> fisher2, std::set<std::string> fisher3)
{
	fout << "---------------------------------------------------------------------------------------------\n";

	for (auto item : unionFishes(fisher1, fisher2, fisher3))
	{
		fout << item << "\t";
	}

	fout << '\n';
	fout << '\n';
}

void whatAlsoHaveLake(std::ofstream &fout, std::set<std::string> fisher1, std::set<std::string> fisher2, std::set<std::string> fisher3, std::set<std::string> lake)
{
	std::set<std::string> notCatch;
	std::set<std::string> temp = unionFishes(fisher1, fisher2, fisher3);
	std::set_difference(lake.begin(), lake.end(), temp.begin(), temp.end(), std::inserter(notCatch, notCatch.begin()));

	fout << "---------------------------------------------------------------------------------------------\n";

	for (auto item : notCatch)
	{
		fout << item << "\t";
	}

	fout << '\n';
	fout << '\n';
}

int main()
{
	try
	{
		// вторая часть задачи
		Book A(7, "mdvfdm knsovk sjnkn", "ndonvnvo nnlnl lknlk", 2002);
		Library l(7, "mdvfdm knsovk sjnkn", "vmevm", 2000);
		l.addBook(7, "mdvfdm knsovk sjnkn", "knvsokdnvoskn", 1211);
		l.addBook(A);
		l.deleteBook(7, "mdvfdm knsovk sjnkn", "vmevm", 2000);
		// l.deleteBook(A);
		// l.FindByBookName("vmevm");
		l.FindAllAuthorBook("mdvfdm knsovk sjnkn");
		l.addAuthor(A, "skdmvkls");
		l.deleteAuthor(A);

		//// третья часть задачи
		std::ifstream fin("info.txt");
		std::map<std::string, size_t> table;
		std::string word;
		while (fin >> word)
		{
			std::transform(word.begin(), word.end(), word.begin(), ::tolower);
			table[word]++;
		}
		fin.close();
		for (const auto &item : table)
		{
			std::cout << item.first << " " << item.second << '\n';
		}

		// четвертая часть лабы
		std::ofstream fout("info.txt");
		checkFile(fout);

		std::set<std::string> lake;
		lake.insert("okyn'");
		lake.insert("voblya");
		lake.insert("plotva");
		lake.insert("karp");
		lake.insert("shyka");
		lake.insert("karas'");
		lake.insert("kit");
		lake.insert("kasatka");
		lake.insert("del'fin");
		lake.insert("megaladon");

		std::set<std::string> firstFishes;
		firstFishes.insert("okyn,");
		firstFishes.insert("karp");
		firstFishes.insert("shyka");
		firstFishes.insert("treska");

		std::set<std::string> secondFishes;
		secondFishes.insert("okyn,");
		secondFishes.insert("voblya");
		secondFishes.insert("karas'");
		secondFishes.insert("okyn,");

		std::set<std::string> thirdFishes;
		thirdFishes.insert("okyn,");
		thirdFishes.insert("okyn,");
		thirdFishes.insert("karp");
		thirdFishes.insert("plotva");

		auto fisher1 = firstFishes;
		auto fisher2 = secondFishes;
		auto fisher3 = thirdFishes;

		fishTheyCaught(fout, fisher1, fisher2, fisher3);
		haveOneOrMore(fout, fisher1, fisher2, fisher3);
		whatAlsoHaveLake(fout, fisher1, fisher2, fisher3, lake);

		fout.close();
	}
	catch (const std::exception &err)
	{
		std::cerr << err.what() << '\n';
	}
	return 0;
}
