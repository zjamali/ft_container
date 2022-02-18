#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

namespace ft
{
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
            //--(*this->iter);
            --iter;
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
            this = this + n;
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
            this = this - n;
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
}
#endif