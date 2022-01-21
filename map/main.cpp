#include <map>
#include <iostream>
#include "tree.hpp"
#include <utility>
#include <map>

int main()
{
    ft::tree<int, int /*,std::greater<int> */> j;
    std::map<int,int> hh;
    for (size_t i = 0; i < 2000000; i++)
    {
        std::cout << ":::::: add : " << i << "\n";
    }
/*
    for (size_t i = 0; i < 10; i++)
    {
       // std::cout << ":::::: add : " << i << "\n";
        j.add(i);
    }
    */
/*
    std::cout << "/:::::::::::::::::::::\n";
    j.print();
    std::cout << "\n:::::::::::::::::::::\n";
    j.deleleNode(13);
    */
    // j.print();
    // std::cout << ":::::::::::::::::::::\n";
    // j.deleleNode(5);
    // j.print();
    // std::cout << ":::::::::::::::::::::\n";
    // j.deleleNode(4);
    // j.deleleNode(1);
    //std::cout << "\n\n";
    //j.print();
    //std::cout << "\n\n";
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
/*
    std::cout << " find " <<j.search(0)->data << "\n";
    std::cout << "\n\n";
    j.print();
    std::cout << "\n\n";
    */
}
