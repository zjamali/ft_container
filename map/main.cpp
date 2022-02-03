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
    std::map<char, int> mymap;
    std::map<char, int>::iterator it;

    // insert some values:
    mymap['a'] = 10;
    mymap['b'] = 20;
    mymap['c'] = 30;
    mymap['d'] = 40;
    mymap['e'] = 50;
    mymap['f'] = 60;

    std::cout << "before erase \n";
    for (it = mymap.begin(); it != mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    it = mymap.find('b');
    std::cout << " erase b using position iterator \n";
    mymap.erase(it); // erasing by iterator
    for (it = mymap.begin(); it != mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    std::cout << " erase c using key  \n";
    mymap.erase('c'); // erasing by key
    for (it = mymap.begin(); it != mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    it = mymap.find('e');
    std::cout << " erase e to the end using rande erase  \n";
    mymap.erase(it, mymap.end()); // erasing by range
    for (it = mymap.begin(); it != mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    // show content:
    std::cout << "after earse\n";
    for (it = mymap.begin(); it != mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    std::cout << "\n\n\n\n";
    {

        ft::map<char, int> mymap;
        ft::map<char, int>::iterator it;

        // insert some values:
        mymap.insert(ft::make_pair('a', 10));
        mymap.insert(ft::make_pair('b', 20));
        mymap.insert(ft::make_pair('c', 30));
        mymap.insert(ft::make_pair('d', 40));
        mymap.insert(ft::make_pair('e', 50));
        mymap.insert(ft::make_pair('f', 60));

        std::cout << "before erase \n";
        for (it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';

        it = mymap.find('b');
        std::cout << " erase b using position iterator \n";
        mymap.erase(it); // erasing by iterator
        for (it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';

        std::cout << " erase c using key  \n";
        mymap.erase('c'); // erasing by key
        for (it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';

        std::cout << "//////////////////////////////\n";
        mymap.print();
        std::cout << "/////////////////////////////////\n";
        it = mymap.find('e');
        std::cout << " erase e to the end using rande erase  \n";
        mymap.erase(it, mymap.end()); // erasing by range
        for (it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';

        // show content:
        std::cout << "after earse\n";
        for (it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    return 0;
}