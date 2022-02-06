#include <map>
#include <iostream>
#include "tree.hpp"
#include <utility>
#include "map.hpp"
#include <map>

int main()
{

    // initialize container
    std::map<int, int> mp;

    // insert elements in random order
    mp.insert(std::make_pair(12, 30));
    mp.insert(std::make_pair(11, 10));
    mp.insert(std::make_pair(15, 50));
    mp.insert(std::make_pair(14, 40));

    // when 11 is present
    std::map<int, int>::iterator it = mp.upper_bound(11);
    std::cout << "The upper bound of key 11 is ";
    std::cout << (*it).first << " " << (*it).second << std::endl;

    // when 13 is not present
    it = mp.upper_bound(13);
    std::cout << "The upper bound of key 13 is ";
    std::cout << (*it).first << " " << (*it).second << std::endl;

    // when 17 is exceeds the maximum key, so size
    // of mp is returned as key and value as 0.
    it = mp.upper_bound(17);
    std::cout << "The upper bound of key 17 is ";
    std::cout << (*it).first << " " << (*it).second;

    std::cout << "\n\n\n\n";
    {

        // initialize container
        ft::map<int, int> mp;

        // insert elements in random order
        mp.insert(ft::make_pair(12, 30));
        mp.insert(ft::make_pair(11, 10));
        mp.insert(ft::make_pair(15, 50));
        mp.insert(ft::make_pair(14, 40));

        // when 11 is present
        ft::map<int, int>::iterator it = mp.upper_bound(11);
        std::cout << "The upper bound of key 11 is ";
        std::cout << (*it).first << " " << (*it).second << std::endl;

        // when 13 is not present
        it = mp.upper_bound(13);
        std::cout << "The upper bound of key 13 is ";
        std::cout << (*it).first << " " << (*it).second << std::endl;

        // when 17 is exceeds the maximum key, so size
        // of mp is returned as key and value as 0.
        it = mp.upper_bound(17);
        std::cout << "The upper bound of key 17 is ";
        std::cout << (*it).first << " " << (*it).second;
    }
    return 0;
}