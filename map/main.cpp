#include <map>
#include <iostream>
#include "tree.hpp"
#include <utility>
#include "map.hpp"
#include <map>

bool fncomp(char lhs, char rhs) { return lhs < rhs; }

struct classcomp
{
    bool operator()(const char &lhs, const char &rhs) const
    {
        return lhs < rhs;
    }
};

int main()
{
    /*
        // empty map container
        std::map<int, int> gquiz1;
        // insert elements in random order
        std::map<int,int>::iterator ittr = gquiz1.begin();
        std::cout << "begin d zeb: " << ittr->first << "\n";
        gquiz1.insert(gquiz1.begin(),std::pair<int, int>(1, 40));
        gquiz1.insert(gquiz1.begin(),std::pair<int, int>(2, 30));
        gquiz1.insert(gquiz1.begin(),std::pair<int, int>(3, 60));
        gquiz1.insert(gquiz1.begin(),std::pair<int, int>(4, 20));
        gquiz1.insert(gquiz1.begin(),std::pair<int, int>(5, 50));
        gquiz1.insert(gquiz1.begin(),std::pair<int, int>(6, 50));
        gquiz1.insert(gquiz1.begin(),std::pair<int, int>(7, 10));
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
            o.insert(o.begin(), ft::pair<int, int>(1, 40));
            o.insert(o.begin(), ft::pair<int, int>(2, 30));
            o.insert(o.begin(), ft::pair<int, int>(3, 60));
            o.insert(o.begin(), ft::pair<int, int>(4, 20));
            o.insert(o.begin(), ft::pair<int, int>(5, 50));
            o.insert(o.begin(), ft::pair<int, int>(6, 50));
            o.insert(o.begin(), ft::pair<int, int>(7, 10));
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
        */
    int i;
    std::map<int, int> mymap;

    if (mymap.max_size() > 1000)
    {
        for (i = 0; i < 1000; i++)
            mymap[i] = 0;
        std::cout << "The map contains 1000 elements.\n";
    }
    else
        std::cout << "The map could not hold 1000 elements.\n";
    {
        int i;
        ft::map<int, int> mymap;

        if (mymap.max_size() > 1000)
        {
            for (i = 0; i < 1000; i++)
                mymap.insert(ft::make_pair(i,0));
            std::cout << "The map contains 1000 elements.\n";
        }
        else
            std::cout << "The map could not hold 1000 elements.\n";
    }
    return 0;
}