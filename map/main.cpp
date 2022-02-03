#include <map>
#include <iostream>
#include "tree.hpp"
#include <utility>
#include "map.hpp"
#include <map>

int main()
{
    std::map<char, int> foo, bar;

    foo['x'] = 100;
    foo['y'] = 200;

    bar['a'] = 11;
    bar['b'] = 22;
    bar['c'] = 33;

    foo.swap(bar);

    std::cout << "foo contains:\n";
    for (std::map<char, int>::iterator it = foo.begin(); it != foo.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    std::cout << "bar contains:\n";
    for (std::map<char, int>::iterator it = bar.begin(); it != bar.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
    std::cout << "\n\n\n";
    {
        ft::map<char, int> foo, bar;

        foo.insert(ft::make_pair('x', 100));
        foo.insert(ft::make_pair('y', 200));

        bar.insert(ft::make_pair('a', 11));
        bar.insert(ft::make_pair('b', 22));
        bar.insert(ft::make_pair('c', 33));

        foo.swap(bar);

        std::cout << "foo contains:\n";
        for (ft::map<char, int>::iterator it = foo.begin(); it != foo.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';

        std::cout << "bar contains:\n";
        for (ft::map<char, int>::iterator it = bar.begin(); it != bar.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    return 0;
}