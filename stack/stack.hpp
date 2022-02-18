#ifndef STACK_HPP
#define STACK_HPP
#include "../vector/vector.hpp"

namespace ft
{
    template <class T, class Container = ft::vector<T> >
    class stack
    {
    public:
        typedef Container container_type;
        typedef typename container_type::value_type value_type;
        typedef typename container_type::size_type size_type;

    protected:
        container_type c;

    public:
        explicit stack(const container_type &ctnr = container_type())
        {
            c = ctnr;
        }
        // COPY constructor
        stack(const stack &x)
        {
            *this = x;
        }
        /// ASSIGN operator
        stack &operator=(const stack &x)
        {
            if (this != &x)
            {
                this->c = x.c;
            }
            return (*this);
        }
        ~stack(){};

    public:
        container_type base() const
        {
            return (this->c);
        }
        bool empty() const
        {
            return (this->c.empty());
        }

        size_type size() const
        {
            return (this->c.size());
        }

        value_type &top()
        {
            return (this->c[this->c.size() - 1]);
        }
        const value_type &top() const
        {
            return (this->c.at(this->c.size() - 1));
        }

        void push(const value_type &val)
        {
            this->c.push_back(val);
        }

        void pop()
        {
            this->c.pop_back();
        }
        template <class _T, class _Container>
        friend bool operator==(const stack<_T, _Container> &lhs, const stack<_T, _Container> &rhs);
        
        template <class _T, class _Container>
        friend bool operator!=(const stack<_T, _Container> &lhs, const stack<_T, _Container> &rhs);
        
        template <class _T, class _Container>
        friend bool operator<(const stack<_T, _Container> &lhs, const stack<_T, _Container> &rhs);
        
        template <class _T, class _Container>
        friend bool operator<=(const stack<_T, _Container> &lhs, const stack<_T, _Container> &rhs);
        
        template <class _T, class _Container>
        friend bool operator>(const stack<_T, _Container> &lhs, const stack<_T, _Container> &rhs);
        
        template <class _T, class _Container>
        friend bool operator>=(const stack<_T, _Container> &lhs, const stack<_T, _Container> &rhs);
    };

    template <class _T, class _Container>
     bool operator==(const stack<_T, _Container> &lhs, const stack<_T, _Container> &rhs)
    {
        return (lhs.c == rhs.c);
    }
    template <class _T, class _Container>
     bool operator!=(const stack<_T, _Container> &lhs, const stack<_T, _Container> &rhs)
    {
        return (lhs.c != rhs.c);
    }
    template <class _T, class _Container>
     bool operator<(const stack<_T, _Container> &lhs, const stack<_T, _Container> &rhs)
    {
        return (lhs.c < rhs.c);
    }
    template <class _T, class _Container>
     bool operator<=(const stack<_T, _Container> &lhs, const stack<_T, _Container> &rhs)
    {
        return (lhs.c <= rhs.c);
    }
    template <class _T, class _Container>
     bool operator>(const stack<_T, _Container> &lhs, const stack<_T, _Container> &rhs)
    {
        return (lhs.c > rhs.c);
    }
    template <class _T, class _Container>
     bool operator>=(const stack<_T, _Container> &lhs, const stack<_T, _Container> &rhs)
    {
        return (lhs.c >= rhs.c);
    }
}
#endif