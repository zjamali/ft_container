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
    class vec_iterator : public iterator<std::random_access_iterator_tag, T *>
    {
    public:
        typedef T iterator_type;
        typedef typename iterator_traits<T>::value_type value_type;
        typedef typename iterator_traits<T>::difference_type difference_type;
        typedef typename iterator_traits<T>::pointer pointer;
        typedef typename iterator_traits<T>::reference reference;
        typedef typename iterator_traits<T>::iterator_category iterator_category;

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
            *this->ptr = *this->ptr + n;
            return (*this);
        }

        vec_iterator operator-(difference_type n) const
        {
            *this->ptr = *this->ptr - n;
            return (*this);
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
            *this = *this - n;
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
    template <class Iterator>
    bool operator==(const vec_iterator<Iterator> &lhs,
                    const vec_iterator<Iterator> &rhs)
    {
        return (lhs->ptr == rhs->ptr);
    }
    template <class Iterator>
    bool operator!=(const vec_iterator<Iterator> &lhs,
                    const vec_iterator<Iterator> &rhs)
    {
        return (lhs.base() != rhs.base());
    }
    template <class Iterator>
    bool operator<(const vec_iterator<Iterator> &lhs,
                   const vec_iterator<Iterator> &rhs)
    {
        return (lhs.base() < rhs.base());
    }
    template <class Iterator>
    bool operator<=(const vec_iterator<Iterator> &lhs,
                    const vec_iterator<Iterator> &rhs)
    {
        return (lhs.base() <= rhs.base());
    }
    template <class Iterator>
    bool operator>(const vec_iterator<Iterator> &lhs,
                   const vec_iterator<Iterator> &rhs)
    {
        return (lhs.base() > rhs.base());
    }
    template <class Iterator>
    bool operator>=(const vec_iterator<Iterator> &lhs,
                    const vec_iterator<Iterator> &rhs)
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
        iterator_type iter;

    public:
        reverse_iterator() : iter(){};
        explicit reverse_iterator(iterator_type iter) : iter(iter){};
        template <class Iter>
        reverse_iterator(const reverse_iterator<Iter> &rev_it) : iter(rev_it.base()){};
        ~reverse_iterator(){};

    public:
        iterator_type base() const
        {
            return (this->iter);
        }

    public:
        reference operator*() const
        {
            iterator_type copy = this->iter;
            --copy;
            return (*copy);
        }

        reverse_iterator operator+(difference_type n) const
        {
            return reverse_iterator(iter + n);
        }

        reverse_iterator &operator++()
        {
            --(*this->iter);
            return (*this);
        }

        reverse_iterator operator++(int)
        {
            reverse_iterator temp = *this;
            --(this->iter);
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
            ++(this->iter);
            return (*this);
        }

        reverse_iterator operator--(int)
        {
            reverse_iterator temp = *this;
            ++(this->iter);
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