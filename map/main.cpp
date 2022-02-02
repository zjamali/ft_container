#include <map>
#include <iostream>
#include "tree.hpp"
#include <utility>
#include "map.hpp"
#include <map>

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

    // first insert function version (single parameter):
    mymap.insert(std::pair<char, int>('a', 100));
    mymap.insert(std::pair<char, int>('z', 200));

    std::pair<std::map<char, int>::iterator, bool> ret;
    ret = mymap.insert(std::pair<char, int>('z', 500));
    if (ret.second == false)
    {
        std::cout << "element 'z' already existed";
        std::cout << " with a value of " << ret.first->second << '\n';
    }

    // second insert function version (with hint position):
    std::map<char, int>::iterator it = mymap.begin();
    mymap.insert(it, std::pair<char, int>('b', 300)); // max efficiency inserting
    mymap.insert(it, std::pair<char, int>('c', 400)); // no max efficiency inserting

    // third insert function version (range insertion):
    std::map<char, int> anothermap;
    anothermap.insert(mymap.begin(), mymap.find('c'));

    // showing contents:
    std::cout << "mymap contains:\n";
    for (it = mymap.begin(); it != mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    std::cout << "anothermap contains:\n";
    for (it = anothermap.begin(); it != anothermap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    std::cout << "\n\n";
    {
        ft::map<char, int> mymap;

        // first insert function version (single parameter):
        mymap.insert(ft::pair<char, int>('a', 100));
        mymap.insert(ft::pair<char, int>('z', 200));

        ft::pair<ft::map<char, int>::iterator, bool> ret;
        ret = mymap.insert(ft::pair<char, int>('z', 500));
        if (ret.second == false)
        {
            std::cout << "element 'z' already existed";
            std::cout << " with a value of " << ret.first->second << '\n';
        }

        // second insert function version (with hint position):
        ft::map<char, int>::iterator it = mymap.begin();
        mymap.insert(it, ft::pair<char, int>('b', 300)); // max efficiency inserting
        mymap.insert(it, ft::pair<char, int>('c', 400)); // no max efficiency inserting

        // third insert function version (range insertion):
        ft::map<char, int> anothermap;
        anothermap.insert(mymap.begin(), mymap.find('c'));

        // showing contents:
        std::cout << "mymap contains:\n";
        for (it = mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';

        std::cout << "anothermap contains:\n";
        for (it = anothermap.begin(); it != anothermap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
}