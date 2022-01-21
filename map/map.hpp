#ifndef MAP_HPP
#define MAP_HPP
#include <memory>
#include <algorithm>
#include <iostream>
#include <utility>
#include <functional>
#include <cstddef>
#include "tree.hpp"

namespace ft
{
    template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
    class map
    {
    public:
        typedef Key key_type;
        typedef T mapped_type;
        typedef pair<const key_type, mapped_type> value_type;
        typedef Compare key_compare;
        typedef Alloc allocator_type;
        typedef value_type &reference;
        typedef const value_type &const_reference;
        typedef value_type *pointer;
        typedef const value_type *const_pointer;
        typedef std::ptrdiff_t difference_type;
        typedef size_t size_type;

        
    };
}

#endif