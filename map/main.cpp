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
    std::map<char, int> first;

    first['a'] = 10;
    first['b'] = 30;
    first['c'] = 50;
    first['d'] = 70;

    std::map<char, int> second(first.begin(), first.end());

    std::map<char, int> third(second);

    std::map<char, int, classcomp> fourth; // class as Compare

    bool (*fn_pt)(char, char) = fncomp;
    std::map<char, int, bool (*)(char, char)> fifth(fn_pt); // function pointer as Compare

    std::map<char, int>::iterator itr;
    for (itr = third.begin(); itr != third.end(); ++itr)
    {
        std::cout << '\t' << itr->first << '\t' << itr->second
                  << '\n';
    }
    std::cout << "\n\n\n";

    {
        ft::map<char, int> first;

        //first['a'] = 10;
        //first['b'] = 30;
        //first['c'] = 50;
        //first['d'] = 70;
        first.insert(ft::pair<char, int>('a',10));
        first.insert(ft::pair<char, int>('b',30));
        first.insert(ft::pair<char, int>('c',50));
        first.insert(ft::pair<char, int>('d',70));
        ft::map<char, int> second(first.begin(), first.end());

        ft::map<char, int> third(second);

        ft::map<char, int, classcomp> fourth; // class as Compare

        bool (*fn_pt)(char, char) = fncomp;
        ft::map<char, int, bool (*)(char, char)> fifth(fn_pt); // function pointer as Compare

        ft::map<char, int>::iterator itr;
        for (itr = third.begin(); itr != third.end(); ++itr)
        {
            std::cout << '\t' << itr->first << '\t' << itr->second
                      << '\n';
        }
    }
    return 0;
}