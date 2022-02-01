#include <map>
#include <iostream>
#include "tree.hpp"
#include <utility>
#include "map.hpp"
#include <map>

int main()
{

    // empty map container
    std::map<int, int> gquiz1;
    // insert elements in random order
    gquiz1.insert(std::pair<int, int>(1, 40));
    gquiz1.insert(std::pair<int, int>(2, 30));
    gquiz1.insert(std::pair<int, int>(3, 60));
    gquiz1.insert(std::pair<int, int>(4, 20));
    gquiz1.insert(std::pair<int, int>(5, 50));
    gquiz1.insert(std::pair<int, int>(6, 50));
    gquiz1.insert(std::pair<int, int>(7, 10));
    // printing map gquiz1
    std::map<int, int>::iterator itr;
    std::cout << "\nThe map gquiz1 is : \n";
    std::cout << "\tKEY\tELEMENT\n";

    for (itr = gquiz1.end(); itr != gquiz1.begin(); --itr)
    {
        std::cout << '\t' << itr->first << '\t' << itr->second
                  << '\n';
    }

    std::cout << std::endl;

    {
        // empty map container
        ft::map<int, int> o;

        // insert elements in random order
        std::cout << "==========insert \n";
        o.insert(ft::pair<int, int>(1, 40));
        o.insert(ft::pair<int, int>(2, 30));
        o.insert(ft::pair<int, int>(3, 60));
        o.insert(ft::pair<int, int>(4, 20));
        o.insert(ft::pair<int, int>(5, 50));
        o.insert(ft::pair<int, int>(6, 50));
        o.insert(ft::pair<int, int>(7, 10));
        // o.print();

        ft::map<int, int>::iterator itr;
        std::cout << "\nThe map gquiz1 is : \n";
        std::cout << "\tKEY\tELEMENT\n";

        for (itr = o.end(); itr != o.begin(); --itr)
        {
            std::cout << '\t' << itr->first << '\t' << itr->second
                      << '\n';
        }
    }
}