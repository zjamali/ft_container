#include <map>
#include <iostream>
#include "tree.hpp"
#include <utility>
#include "map.hpp"
#include <map>

int main()
{
    std::map<char, int> mymap;
    char c;

    mymap['a'] = 101;
    mymap['c'] = 202;
    mymap['f'] = 303;

    for (c = 'a'; c < 'h'; c++)
    {
        std::cout << c;
        if (mymap.count(c) > 0)
            std::cout << " is an element of mymap.\n";
        else
            std::cout << " is not an element of mymap.\n";
    }

    std::cout << "\n\n\n\n";
    {
        ft::map<char, int> mymap;
        char c;

        mymap.insert(ft::make_pair('a', 101));
        mymap.insert(ft::make_pair('c', 202));
        mymap.insert(ft::make_pair('f', 303));

        for (c = 'a'; c < 'h'; c++)
        {
            std::cout << c;
            if (mymap.count(c) > 0)
                std::cout << " is an element of mymap.\n";
            else
                std::cout << " is not an element of mymap.\n";
        }
    }
    return 0;
}