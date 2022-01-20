#include <map>
#include <iostream>
#include "tree.hpp"
#include <utility>

int main()
{
    ft::tree<int, int /*,std::greater<int> */> j;
    /*
    for (size_t i = 5; i < 10; i++)
    {
        std::cout << ":::::: add : " << i << "\n";
        j.add(i);
    }
    */
    for (size_t i = 0; i < 6; i++)
    {
        std::cout << ":::::: add : " << i << "\n";
        j.add(i);
    }
    //std::cout << ":::::::::::::::::::::\n";
    //j.deleleNode(0);
    //j.print();
    //std::cout << ":::::::::::::::::::::\n";
    //j.deleleNode(5);
    //j.print();
    //std::cout << ":::::::::::::::::::::\n";
    j.deleleNode(4);
    //j.deleleNode(1);
    //j.deleleNode(3);
    // j.add(10);
    // std::cout << "\n\n";
    // j.print();
    // std::cout << "\n\n";
    // j.deleleNode(10);
    // std::cout << "\n\n";
    /*
    j.add(5);
    j.add(8);
    j.add(5646);
    j.add(66);
    j.add(6654);
    j.add(9);
    j.add(10);
    j.add(1);
    j.add(6614);

    j.add(656);
*/
    j.print();
}
