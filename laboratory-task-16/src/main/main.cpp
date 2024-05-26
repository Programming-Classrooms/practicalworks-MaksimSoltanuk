#include "src/func/func.hpp"

int main()
{
	try
	{
		secondPartOfTheTask();
		thirdPartOfTheTask();
		fourthPartOfTheTask();
		fifthPartOfTheTask();
		sixthPartOfTheTask();
	}
	catch (std::invalid_argument &err)
	{
		std::cerr << err.what() << '\n';
	}
	return 0;
}
