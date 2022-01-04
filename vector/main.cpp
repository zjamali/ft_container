#include "vector.hpp"
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> myvector;

    // set some values (from 1 to 10)
    for (int i = 1; i <= 10; i++)
        myvector.push_back(i);
    std::cout << "capacity " << myvector.capacity() << std::endl;

    std::vector<int>::iterator it = myvector.begin();
    // erase the 6th element
    //it = myvector.erase(it + 5);
    //std::cout << " it " << *it << std::endl; 
    // erase the first 3 elements:
    myvector.erase(myvector.begin(), myvector.begin() + 3);

    std::cout << "myvector contains:";
    for (unsigned i = 0; i < myvector.size(); ++i)
        std::cout << ' ' << myvector[i];
    std::cout << '\n';

    {
        ft::vector<int> myvector;

        // set some values (from 1 to 10)
        for (int i = 1; i <= 10; i++)
            myvector.push_back(i);
        std::cout << "capacity " << myvector.capacity() << std::endl;

        ft::vector<int>::iterator it = myvector.begin();
        // erase the 6th element
        //it = myvector.erase(it + 5);
        //std::cout << " it " << *it << std::endl; 
        // erase the first 3 elements:
        myvector.erase(myvector.begin(), myvector.begin() + 3);

        std::cout << "myvector contains:";
        for (unsigned i = 0; i < myvector.size(); ++i)
            std::cout << ' ' << myvector[i];
        std::cout << '\n';
    }
    return 0;
}
