#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <cstddef>

namespace ft
{
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
    template <class Iterator>
    class iterator_traits
    {
    public:
        typedef typename Iterator::difference_type difference_type;
        typedef typename Iterator::value_type value_type;
        typedef typename Iterator::pointer pointer;
        typedef typename Iterator::reference reference;
        typedef typename Iterator::iterator_category iterator_category;
    };
    template <class T>
    class iterator_traits<T *>
    {
    public:
        typedef ptrdiff_t difference_type;
        typedef T value_type;
        typedef T *pointer;
        typedef T &reference;
        typedef std::random_access_iterator_tag iterator_category;
    };
    template <class T>
    class iterator_traits<const T *>
    {
    public:
        typedef ptrdiff_t difference_type;
        typedef T value_type;
        typedef const T *pointer;
        typedef const T &reference;
        typedef std::random_access_iterator_tag iterator_category;
    };
    template <class T>
    class reverse_iterator : public iterator<std::random_access_iterator_tag, T>
    {
    public:
        typedef T iterator_type;
        typedef typename iterator_traits<T>::value_type value_type;
        typedef typename iterator_traits<T>::difference_type difference_type;
        typedef typename iterator_traits<T>::pointer pointer;
        typedef typename iterator_traits<T>::reference reference;
        typedef typename iterator_traits<T>::iterator_category iterator_category;

    private:
        iterator_type ptr;

    public:
        reverse_iterator() : ptr(){};
        explicit reverse_iterator(iterator_type iter) : ptr(iter){};
        template <class Iter>
        reverse_iterator(const reverse_iterator<Iter> &rev_it) : ptr(rev_it.base()){};

        iterator_type base() const
        {
            return (this->ptr);
        }

        reference operator*() const
        {
            iterator_type copy = this->ptr;
            --copy;
            return (*copy);
        }

        reverse_iterator operator+(difference_type n) const
        {
            return reverse_iterator(ptr + n);
        }

        reverse_iterator &operator++()
        {
            ++(*this);
            return (*this);
        }

        reverse_iterator operator++(int)
        {
            reverse_iterator temp = *this;
            ++(*this);
            return temp;
        }

        reverse_iterator &operator+=(difference_type n)
        {
            *this = *this + n;
            return (*this);
        }

        reverse_iterator operator-(difference_type n) const
        {
            *this = *this - n;
            return (*this);
        }

        reverse_iterator &operator--()
        {
            --(*this);
            return (*this);
        }

        reverse_iterator operator--(int)
        {
            reverse_iterator temp = *this;
            --(*this);
            return temp;
        }

        reverse_iterator &operator-=(difference_type n)
        {
            *this = *this - n;
            return (*this);
        }

        pointer operator->() const
        {
            return (&(this->operator*()));
        }

        reference operator[](difference_type n) const
        {
            return (this->base()[-n - 1]);
        }
    };

    template <class Iterator>
    bool operator==(const reverse_iterator<Iterator> &lhs,
                    const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() == rhs.base());
    }
    template <class Iterator>
    bool operator!=(const reverse_iterator<Iterator> &lhs,
                    const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() != rhs.base());
    }
    template <class Iterator>
    bool operator<(const reverse_iterator<Iterator> &lhs,
                   const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() < rhs.base());
    }
    template <class Iterator>
    bool operator<=(const reverse_iterator<Iterator> &lhs,
                    const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() <= rhs.base());
    }
    template <class Iterator>
    bool operator>(const reverse_iterator<Iterator> &lhs,
                   const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() > rhs.base());
    }
    template <class Iterator>
    bool operator>=(const reverse_iterator<Iterator> &lhs,
                    const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() >= rhs.base());
    }

    template <class Iterator>
    reverse_iterator<Iterator> operator+(
        typename reverse_iterator<Iterator>::difference_type n,
        const reverse_iterator<Iterator> &rev_it)
    {
        reverse_iterator<Iterator> tmp = rev_it + n;
        return (tmp);
    }

    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator-(
        const reverse_iterator<Iterator> &lhs,
        const reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() - rhs.base());
    }
};
#endif