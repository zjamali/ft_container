#ifndef VEC_ITERATOR_HPP
#define VEC_ITERATOR_HPP
#include <cstddef>
#include "../iterator_traits.hpp"
#include "../reverse_iterator.hpp"

namespace ft
{
    template <class T>
    class vec_iterator /* : public iterator<std::random_access_iterator_tag, T>*/
    {
    public:
        typedef typename iterator_traits<T>::value_type value_type;
        typedef typename iterator_traits<T>::difference_type difference_type;
        typedef typename iterator_traits<T>::pointer pointer;
        typedef typename iterator_traits<T>::reference reference;
        typedef std::random_access_iterator_tag iterator_category;

    private:
        pointer ptr;

    public:
        vec_iterator() : ptr(NULL){};
        explicit vec_iterator(pointer ptr) : ptr(ptr){};
        template <class Iter>
        vec_iterator(const vec_iterator<Iter> &iter) : ptr(iter.base()){};
        ~vec_iterator(){};

    public:
        pointer base() const
        {
            return (this->ptr);
        }

    public:
        reference operator*() const
        {
            return (*this->ptr);
        }

        vec_iterator operator+(difference_type n) const
        {
            return vec_iterator(ptr + n);
        }

        vec_iterator &operator++()
        {
            this->ptr++;
            return (*this);
        }

        vec_iterator operator++(int)
        {
            vec_iterator temp = *this;
            ++(*this);
            return temp;
        }

        vec_iterator &operator+=(difference_type n)
        {
            this->ptr = this->ptr + n;
            return (*this);
        }

        vec_iterator operator-(difference_type n) const
        {
            return (vec_iterator(this->ptr - n));
        }

        vec_iterator &operator--()
        {
            this->ptr--;
            return (*this);
        }

        vec_iterator operator--(int)
        {
            vec_iterator temp = *this;
            --(*this);
            return temp;
        }

        vec_iterator &operator-=(difference_type n)
        {
            this = this - n;
            return (*this);
        }

        pointer operator->() const
        {
            return (&(this->operator*()));
        }

        reference operator[](difference_type n) const
        {
            return (this->base()[n]);
        }
    };
    template <class Iterator, class iter>
    bool operator==(const vec_iterator<Iterator> &lhs,
                    const vec_iterator<iter> &rhs)
    {
        return (lhs.base() == rhs.base());
    }
    template <class Iterator, class iter>
    bool operator!=(const vec_iterator<Iterator> &lhs,
                    const vec_iterator<iter> &rhs)
    {
        return (lhs.base() != rhs.base());
    }
    template <class Iterator, class iter>
    bool operator<(const vec_iterator<Iterator> &lhs,
                   const vec_iterator<iter> &rhs)
    {
        return (lhs.base() < rhs.base());
    }
    template <class Iterator, class iter>
    bool operator<=(const vec_iterator<Iterator> &lhs,
                    const vec_iterator<iter> &rhs)
    {
        return (lhs.base() <= rhs.base());
    }
    template <class Iterator, class iter>
    bool operator>(const vec_iterator<Iterator> &lhs,
                   const vec_iterator<iter> &rhs)
    {
        return (lhs.base() > rhs.base());
    }
    template <class Iterator, class iter>
    bool operator>=(const vec_iterator<Iterator> &lhs,
                    const vec_iterator<iter> &rhs)
    {
        return (lhs.base() >= rhs.base());
    }

    template <class Iterator>
    vec_iterator<Iterator> operator+(
        typename vec_iterator<Iterator>::difference_type n,
        const vec_iterator<Iterator> &iter)
    {
        vec_iterator<Iterator> tmp = iter + n;
        return (tmp);
    }

    template <class Iterator>
    typename vec_iterator<Iterator>::difference_type operator-(
        const vec_iterator<Iterator> &lhs,
        const vec_iterator<Iterator> &rhs)
    {
        return (lhs.base() - rhs.base());
    }
};
#endif