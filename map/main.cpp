#include <map>
#include <iostream>
#include "tree.hpp"
#include <utility>
#include "map.hpp"
#include <map>

int main()
{
    std::map<char, int> mymap;

    mymap['x'] = 100;
    mymap['y'] = 200;
    mymap['z'] = 300;

    std::cout << "mymap contains:\n";
    for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    mymap.clear();
    mymap['a'] = 1101;
    mymap['b'] = 2202;

    std::cout << "mymap contains:\n";
    for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
    std::cout << "\n\n\n";
    {
        ft::map<char, int> mymap;

        mymap.insert(ft::make_pair('x', 100));
        mymap.insert(ft::make_pair('y', 200));
        mymap.insert(ft::make_pair('z', 300));

        std::cout << "mymap contains:\n";
        for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
        mymap.print();
        std::cout << "begin clear\n";
        mymap.clear();
        std::cout << "after clear\n";

        mymap.print();
        std::cout << "after print\n";
        mymap.insert(ft::make_pair('a', 1101));
        mymap.insert(ft::make_pair('b', 2202));

        mymap.print();
        std::cout << "mymap contains:\n";
        for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    return 0;
}