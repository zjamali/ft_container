#include <map>
#include <iostream>
#include "tree.hpp"
#include <utility>
#include "map.hpp"
#include <map>

int main()
{
    std::map<char, int> mymap;

    std::map<char, int>::key_compare mycomp = mymap.key_comp();

    mymap['a'] = 100;
    mymap['b'] = 200;
    mymap['c'] = 300;

    std::cout << "mymap contains:\n";

    char highest = mymap.rbegin()->first; // key value of last element

    std::map<char, int>::iterator it = mymap.begin();
    do
    {
        std::cout << it->first << " => " << it->second << '\n';
    } while (mycomp((*it++).first, highest));

    std::cout << "\n\n\n\n";
    {
        ft::map<char, int> mymap;

        ft::map<char, int>::key_compare mycomp = mymap.key_comp();

        mymap.insert(ft::make_pair('a', 100));
        mymap.insert(ft::make_pair('b', 200));
        mymap.insert(ft::make_pair('c', 300));

        std::cout << "mymap contains:\n";

        char highest = mymap.rbegin()->first; // key value of last element

        ft::map<char, int>::iterator it = mymap.begin();
        do
        {
            std::cout << it->first << " => " << it->second << '\n';
        } while (mycomp((*it++).first, highest));
    }
    return 0;
}