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
    mp.insert(std::make_pair(2, 30));
    mp.insert(std::make_pair(1, 10));
    mp.insert(std::make_pair(5, 50));
    mp.insert(std::make_pair(4, 40));
    for (std::map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
    {
        std::cout << (*it).first << " " << (*it).second << std::endl;
    }

    // when 2 is present
    std::map<int, int>::iterator it = mp.lower_bound(2);
    std::cout << "The lower bound of key 2 is ";
    std::cout << (*it).first << " " << (*it).second << std::endl;

    // when 3 is not present
    // points to next greater after 3
    it = mp.lower_bound(3);
    std::cout << "The lower bound of key 3 is ";
    std::cout << (*it).first << " " << (*it).second;

    // when 6 exceeds
    it = mp.lower_bound(6);
    std::cout << "\nThe lower bound of key 6 is ";
    std::cout << (*it).first << " " << (*it).second;

    std::cout << "\n\n\n\n";
    {

        // initialize container
        ft::map<int, int> mp;

        // insert elements in random order
        mp.insert(ft::make_pair(2, 30));
        mp.insert(ft::make_pair(1, 10));
        mp.insert(ft::make_pair(5, 50));
        mp.insert(ft::make_pair(4, 40));
        for (ft::map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
        {
            std::cout << (*it).first << " " << (*it).second << std::endl;
        }

        // when 2 is present
        ft::map<int, int>::iterator it = mp.lower_bound(2);
        std::cout << "The lower bound of key 2 is ";
        std::cout << (*it).first << " " << (*it).second << std::endl;

        // when 3 is not present
        // points to next greater after 3
        it = mp.lower_bound(3);
        std::cout << "The lower bound of key 3 is ";
        std::cout << (*it).first << " " << (*it).second;

        // when 6 exceeds
        it = mp.lower_bound(6);
        std::cout << "\nThe lower bound of key 6 is ";
        std::cout << (*it).first << " " << (*it).second;
    }
    return 0;
}