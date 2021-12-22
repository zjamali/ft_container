#include "vector.hpp"
#include <iostream>
#include <vector>


int main()
{
   ft::vector<int> v(50, 8);
    std::vector<int> vec(50,8);
   std::cout << v.size() << std::endl;
    std::cout << vec.size() << std::endl;

    //for (size_t i = 0; i < 50; i++)
    //{
    //    std::cout << v[i] << std::endl;
    //}
    v[5] = 40;
    v.at(80);
    std::cout << v[5]<< std::endl;
    return 0;
}
