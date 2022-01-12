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

    private:
        container_type _container;

    public:
        explicit stack(const container_type &ctnr = container_type())
        {
            _container = ctnr;
            // std::cout << "shghafs\n";
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
                this->_container = x._container;
            }
            return (*this);
        }

        ~stack(){};

    public:
        container_type base() const
        {
            return (this->_container);
        }
        bool empty() const
        {
            return (this->_container.empty());
        }

        size_type size() const
        {
            return (this->_container.size());
        }

        value_type &top()
        {
            return (this->_container[this->_container.size() - 1]);
        }
        const value_type &top() const
        {
            return (this->_container.at(this->_container.size() - 1));
        }

        void push(const value_type &val)
        {
            this->_container.push_back(val);
        }

        void pop()
        {
            this->_container.pop_back();
        }
        template <class _T, class _Container>
        friend bool operator==(const stack<_T, _Container> &lhs, const stack<_T, Container> &rhs);
        template <class _T, class _Container>
        friend bool operator!=(const stack<_T, _Container> &lhs, const stack<_T, Container> &rhs);
        template <class _T, class _Container>
        friend bool operator<(const stack<_T, _Container> &lhs, const stack<_T, Container> &rhs);
        template <class _T, class _Container>
        friend bool operator<=(const stack<_T, _Container> &lhs, const stack<_T, Container> &rhs);
        template <class _T, class _Container>
        friend bool operator>(const stack<_T, _Container> &lhs, const stack<_T, Container> &rhs);
        template <class _T, class _Container>
        friend bool operator>=(const stack<_T, _Container> &lhs, const stack<_T, Container> &rhs);
    };
    template <class _T, class _Container>
    bool operator==(const stack<_T, _Container> &lhs, const stack<_T, _Container> &rhs)
    {
        return (lhs._container == rhs._container);
    }
    template <class _T, class _Container>
    bool operator!=(const stack<_T, _Container> &lhs, const stack<_T, _Container> &rhs)
    {
        return (lhs._container != rhs._container);
    }
    template <class _T, class _Container>
    bool operator<(const stack<_T, _Container> &lhs, const stack<_T, _Container> &rhs)
    {
        return (lhs._container < rhs._container);
    }
    template <class _T, class _Container>
    bool operator<=(const stack<_T, _Container> &lhs, const stack<_T, _Container> &rhs)
    {
        return (lhs._container <= rhs._container);
    }
    template <class _T, class _Container>
    bool operator>(const stack<_T, _Container> &lhs, const stack<_T, _Container> &rhs)
    {
        return (lhs._container > rhs._container);
    }
    template <class _T, class _Container>
    bool operator>=(const stack<_T, _Container> &lhs, const stack<_T, _Container> &rhs)
    {
        return (lhs._container >= rhs._container);
    }
}
#endif