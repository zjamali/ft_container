#include "vector.hpp"
#include <iostream>
#include <vector>

int main()
{
    ft::vector<int> v(50);
    std::vector<int> vec(50);
    std::cout << v.size() << std::endl;
    std::cout << vec.size() << std::endl;
    std::srand(time(NULL));
    for (size_t i = 0; i < 20; i++)
    {
        int n = rand() % 50;
        vec[i] = n;
        v[i] = n;
    }

    ft::vector<int> copy;
    copy = v;
    std::cout << "my max " << copy.max_size() << "    |    " << vec.max_size() << std::endl;
    for (size_t i = 0; i < 20; i++)
    {
        std::cout << " my " << copy[i] << " | " << vec[i] << std::endl;
    }
    std::cout << "front " << v.front() << " | " << vec.front() << std::endl;
    std::cout << "back " << v.back() << " | " << vec.back() << std::endl;

    v.assign(5,8);
    vec.assign(5,8);
    vec.reserve(100);
    vec.push_back(8000000);
    vec.push_back(200000);
    v.reserve(100);
    v.push_back(8000000);
    v.push_back(200000);
    v.pop_back();
    vec.pop_back();
    // v.resize(80000);
    // vec.resize(80000);
    for (size_t i = 0; i < 100; i++)
    {
        std::cout << "my " << v[i] << "   |  " << vec[i] << std::endl;
    }

    std::cout << "fsjkhasjkfhjkafs" << std::endl;
    std::cout << v.size() << " | " << v.capacity() << std::endl;
    std::cout << vec.size() << " | " << vec.capacity() << std::endl;

    return 0;
}
