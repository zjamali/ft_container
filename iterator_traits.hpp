#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP
#include <cstddef>

namespace ft {
    template <class Category, class T, class Distance = ptrdiff_t,
              class Pointer = T *, class Reference = T &>
    class iterator
    {
    public:
        typedef T value_type;
        typedef Distance difference_type;
        typedef Pointer pointer;
        typedef Reference reference;
        typedef Category iterator_category;
    };

    template <class iterator>
    class iterator_traits
    {
    public:
        typedef typename iterator::difference_type difference_type;
        typedef typename iterator::value_type value_type;
        typedef typename iterator::pointer pointer;
        typedef typename iterator::reference reference;
        typedef typename iterator::iterator_category iterator_category;
    };
    template <class T>
    class iterator_traits<T *>
    {
    public:
        typedef ptrdiff_t difference_type;
        typedef T value_type;
        typedef T *pointer;
        typedef T &reference;
       // typedef typename T::iterator_category iterator_category;
    };
    template <class T>
    class iterator_traits<const T *>
    {
    public:
        typedef ptrdiff_t difference_type;
        typedef T value_type;
        typedef const T *pointer;
        typedef const T &reference;
        //typedef T::iterator_category iterator_category;
    };
}


#endif
