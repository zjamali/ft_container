#include <map>
#include <iostream>
#include "tree.hpp"
#include <utility>
#include "map.hpp"
#include <map>

int main()
{
    std::map<char, int> mymap;

    mymap['x'] = 1001;
    mymap['y'] = 2002;
    mymap['z'] = 3003;

    std::cout << "mymap contains:\n";

    std::pair<char, int> highest = *mymap.rbegin(); // last element

    std::map<char, int>::iterator it = mymap.begin();
    do
    {
        std::cout << it->first << " => " << it->second << '\n';
    } while (mymap.value_comp()(*it++, highest));

    std::cout << "\n\n\n\n";
    {
        ft::map<char, int> mymap;

        mymap.insert(ft::make_pair('x', 1001));
        mymap.insert(ft::make_pair('y', 2002));
        mymap.insert(ft::make_pair('z', 3003));

        std::cout << "mymap contains:\n";

        ft::pair<char, int> highest = *mymap.rbegin(); // last element

        ft::map<char, int>::iterator it = mymap.begin();
        do
        {
            std::cout << it->first << " => " << it->second << '\n';
        } while (mymap.value_comp()(*it++, highest));
    }
    return 0;
}