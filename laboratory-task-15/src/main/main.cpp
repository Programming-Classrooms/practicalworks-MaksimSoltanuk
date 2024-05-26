#include "../class/List.hpp"
#include "../class/TDeque.hpp"

int main()
{
    try
    {
        List<char *> list;
        TDeque<char *> tdeque;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
