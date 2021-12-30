#include "vector.hpp"
#include <iostream>
#include <vector>

int main()
{
    /*
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

    vec.assign(5,8);
    vec.reserve(100);
    vec.push_back(8000000);
    vec.push_back(200000);

    v.assign(5,8);
    v.reserve(100);
    v.push_back(8000000);
    v.push_back(200000);

    v.pop_back();
    vec.pop_back();

    v.push_back(80);
    vec.push_back(80);
    for (size_t i = 0; i < 100; i++)
    {
        std::cout << "my " << v[i] << "   |  " << vec[i] << std::endl;
    }

    std::cout << "fsjkhasjkfhjkafs" << std::endl;
    std::cout << v.size() << " | " << v.capacity() << std::endl;
    std::cout << vec.size() << " | " << vec.capacity() << std::endl;

*/
    /*
        std::vector<int> myvector;
        myvector.push_back(100);
        myvector.push_back(200);
        myvector.push_back(300);

        std::cout << "myvector contains:";
        for (unsigned i = 0; i < myvector.size(); i++)
            std::cout << ' ' << myvector[i];
        std::cout << '\n';

        myvector.clear();
        myvector.push_back(1101);
        myvector.push_back(2202);

        std::cout << "myvector contains:";
        for (unsigned i = 0; i < myvector.size(); i++)
            std::cout << ' ' << myvector[i];
        std::cout << '\n';

            ft::vector<int> myvector1;
        myvector1.push_back(100);
        myvector1.push_back(200);
        myvector1.push_back(300);

        std::cout << "myvector1 contains:";
        for (unsigned i = 0; i < myvector1.size(); i++)
            std::cout << ' ' << myvector1[i];
        std::cout << '\n';

        myvector1.clear();
        myvector1.push_back(1101);
        myvector1.push_back(2202);

        std::cout << "myvector1 contains:";
        for (unsigned i = 0; i < myvector1.size(); i++)
            std::cout << ' ' << myvector1[i];
        std::cout << '\n';
    */
    /*
        std::vector<int> foo(3, 100); // three ints with a value of 100
        std::vector<int> bar(5, 200); // five ints with a value of 200

        foo.swap(bar);

        std::cout << "foo contains:";
        for (unsigned i = 0; i < foo.size(); i++)
            std::cout << ' ' << foo[i];
        std::cout << '\n';

        std::cout << "bar contains:";
        for (unsigned i = 0; i < bar.size(); i++)
            std::cout << ' ' << bar[i];
        std::cout << '\n';

        ft::vector<int> foo1(3, 100); // three ints with a value of 100
        ft::vector<int> bar1(5, 200); // five ints with a value of 200

        foo1.swap(bar1);

        std::cout << "foo1 contains:";
        for (unsigned i = 0; i < foo1.size(); i++)
            std::cout << ' ' << foo1[i];
        std::cout << '\n';

        std::cout << "bar1 contains:";
        for (unsigned i = 0; i < bar1.size(); i++)
            std::cout << ' ' << bar1[i];
        std::cout << '\n';
        */
/*
    ft::vector<int> myvector;
    int *p;
    unsigned int i;
    

    // allocate an array with space for 5 elements using vector's allocator:
    p = myvector.get_allocator().allocate(5);

    // construct values in-place on the array:
    for (i = 0; i < 5; i++)
        myvector.get_allocator().construct(&p[i], i);

    std::cout << "The allocated array contains:";
    for (i = 0; i < 5; i++)
        std::cout << ' ' << p[i];
    std::cout << '\n';

    // destroy and deallocate:
    for (i = 0; i < 5; i++)
        myvector.get_allocator().destroy(&p[i]);
    myvector.get_allocator().deallocate(p, 5);
*/

    int tab[5] = {1,2,3,4,5}; 
    std::iterator_traits<int*>::pointer traits;
    traits = tab;
    std::iterator_traits<int *>::value_type traitsr;

    std::iterator_traits<int *>::reference &ref(tab[2]);
    std::iterator_traits<int *>::difference_type diff;
    traits++;
    std::cout << *traits << " | " << sizeof(traitsr) << " | " << ref << " | " << std::endl;
    return 0;
}
