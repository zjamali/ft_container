#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <iostream>
#include "iterator.hpp"
#include "utils.hpp"
#include <algorithm>

namespace ft
{

    template <class T, class Alloc = std::allocator<T> >
    class vector
    {
    public:
        typedef T value_type;
        typedef Alloc allocator_type;
        typedef T &reference;
        typedef T &const_reference;
        typedef T *pointer;
        typedef const T *const_pointer;
        typedef std::ptrdiff_t difference_type;
        typedef size_t size_type;
        typedef ft::vec_iterator<pointer> iterator;
        typedef ft::vec_iterator<const_pointer> const_iterator;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

    private:
        allocator_type _alloc;
        size_type _capacity;
        size_type _size;
        pointer _rawData;

    public:
        explicit vector(const allocator_type &alloc = allocator_type())
            : _alloc(alloc), _capacity(0), _size(0), _rawData(NULL) {}
        explicit vector(size_type n, const value_type &val = value_type(),
                        const allocator_type &alloc = allocator_type())
            : _alloc(alloc), _capacity(0), _size(0), _rawData(NULL)
        {
            this->assign(n, val);
        }

        template <class InputIterator>
        vector(InputIterator first, InputIterator last,
               const allocator_type &alloc = allocator_type(),
               typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = nullptr)
            : _alloc(alloc), _capacity(0), _size(0), _rawData(NULL)
        {
            this->assign(first, last);
        }

        // COPY constructor
        vector(const vector &x)
        {
            *this = x;
        }
        /// ASSIGN operator
        vector &operator=(const vector &x)
        {
            if (this != &x)
            {
                this->_alloc.deallocate(this->_rawData, this->_capacity);
                this->_capacity = x._capacity;
                this->_size = x._size;
                this->_rawData = _alloc.allocate(this->_capacity);
                for (size_type i = 0; i < this->_capacity; i++)
                {
                    _alloc.construct(&_rawData[i], x._rawData[i]);
                }
            }
            return (*this);
        }
        ~vector()
        {
            for (size_type i = 0; i < this->_size; i++)
            {
                this->_alloc.destroy(&_rawData[i]);
            }
            this->_alloc.deallocate(this->_rawData, this->_capacity);
        };

    public:
        /*********  CAPACITY MEMBERS FUNCTIONS  ********/
        size_type size() const
        {
            return (this->_size);
        }

        size_type capacity() const
        {
            return (this->_capacity);
        }

        bool empty() const
        {
            return (this->_size == 0);
        }
        size_type max_size() const
        {
            return (std::min(std::numeric_limits<difference_type>::max(), (difference_type)this->_alloc.max_size()));
        }

        void resize(size_type n, value_type val = value_type())
        {
            size_type _sz = this->_size;
            if (_sz > n)
            {
                for (size_type i = n - 1; i < _sz; i++)
                    _alloc.destroy(&(this->_rawData[i]));
                this->_size = n;
            }
            else if (_sz < n)
            {
                this->reserve(n);
                this->_size = n;
                for (size_type i = _sz; i < this->_size; i++)
                    _alloc.construct(&(this->_rawData[i]), val);
            }
        }

        void reserve(size_type n)
        {
            if (this->_capacity < n)
            {
                size_type oldCapacity = this->_capacity;
                if (this->_capacity * 2 >= n)
                    this->_capacity *= 2;
                else
                    this->_capacity = n;
                pointer ptr = this->_alloc.allocate(this->_capacity);
                for (size_type i = 0; i < this->_size; i++)
                {
                    this->_alloc.construct(ptr + i, this->_rawData[i]);
                }
                for (size_type i = 0; i < this->_size; i++)
                {
                    _alloc.destroy(&this->_rawData[i]);
                }
                this->_alloc.deallocate(this->_rawData, oldCapacity);
                this->_rawData = ptr;
            }
        }

    public:
        /*********  ELEMENT ACCESS MEMBERS FUNCTIONS  ********/
        reference operator[](size_type n)
        {
            return (this->_rawData[n]);
        }

        const_reference operator[](size_type n) const
        {
            return (this->_rawData[n]);
        }

        reference at(size_type n)
        {
            if (this->_size < n)
                throw std::out_of_range("vector");
            return (this->_rawData[n]);
        }

        const_reference at(size_type n) const
        {
            if (this->size < n)
                throw std::out_of_range("vector");
            return (this->_rawData[n]);
        }

        reference front()
        {
            return (this->_rawData[0]);
        }

        const_reference front() const
        {
            return (this->_rawData[0]);
        }

        reference back()
        {
            return (this->_rawData[_size - 1]);
        }

        const_reference back() const
        {
            return (this->_rawData[_size - 1]);
        }

    private:
        void assign_alloctor(size_type n)
        {
            if (this->_capacity < n)
            {
                size_type oldCapacity = this->_capacity;
                this->_capacity = n;
                pointer ptr = this->_alloc.allocate(this->_capacity);
                for (size_type i = 0; i < this->_size; i++)
                {
                    this->_alloc.construct(ptr + i, this->_rawData[i]);
                }
                for (size_type i = 0; i < this->_size; i++)
                {
                    _alloc.destroy(&this->_rawData[i]);
                }
                this->_alloc.deallocate(this->_rawData, oldCapacity);
                this->_rawData = ptr;
            }
        }

    public:
        /*********  MODIFIERS MEMBERS FUNCTIONS  ********/
        void assign(size_type n, const value_type &val)
        {
            if (n <= 0)
                return;
            this->assign_alloctor(n);
            this->_size = n;
            size_type i = 0;
            while (i < this->_size)
            {
                _alloc.construct(&(this->_rawData[i]), val);
                i++;
            }
        }
        template <class InputIterator>
        void assign(InputIterator first, InputIterator last,
                    typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = nullptr)
        {
            difference_type rangeLen = last - first;
            if (rangeLen <= 0)
                throw std::out_of_range("vector");
            this->assign_alloctor(rangeLen);
            this->_size = rangeLen;
            size_type i = 0;
            while (i < this->_size)
            {
                _alloc.construct(&this->_rawData[i], *first);
                i++;
                first++;
            }
        }

        void push_back(const value_type &val)
        {
            this->reserve(this->_size + 1);
            _alloc.construct(&this->_rawData[_size++], val);
        }

        void pop_back()
        {
            this->_alloc.destroy(&_rawData[_size - 1]);
            this->_size--;
        }

        iterator insert(iterator position, const value_type &val)
        {
            difference_type positionIndex = position - this->begin();
            size_type newSize;

            if ((size_type)positionIndex > this->_size + 1)
                newSize = this->_size + (positionIndex - this->_size + 1);
            else
                newSize = this->_size + 1;
            this->reserve(newSize);
            this->_size = newSize;
            for (difference_type i = this->_size - 1; i > positionIndex; i--)
            {
                this->_rawData[i] = this->_rawData[i - 1];
            }
            this->_rawData[positionIndex] = val;
            return (this->begin() + positionIndex);
        }

        void insert(iterator position, size_type n, const value_type &val)
        {
            difference_type firstPosIndex = position - this->begin();

            difference_type lastPosIndex = firstPosIndex + n - 1;
            this->reserve(this->_size + n);
            for (difference_type i = firstPosIndex; i <= lastPosIndex; i++)
            {
                this->insert(this->begin() + i, val);
            }
        }

        template <class InputIterator>
        void insert(iterator position, InputIterator first, InputIterator last,
                    typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = nullptr)
        {
            difference_type firstPosIndex = position - this->begin();
            difference_type lastPosIndex = firstPosIndex + last - first - 1;
            difference_type ranglen = last - first;
            this->reserve(this->_size + ranglen);

            for (difference_type i = firstPosIndex; i <= lastPosIndex; i++)
            {
                this->insert(this->begin() + i, *first);
                first++;
            }
        }

        void clear()
        {
            for (size_type i = 0; i < this->_size; i++)
            {
                this->_alloc.destroy(&_rawData[i]);
            }
            this->_size = 0;
        }

        void swap(vector &x)
        {
            std::swap(this->_rawData, x._rawData);
            std::swap(this->_size, x._size);
            std::swap(this->_capacity, x._capacity);
            std::swap(this->_alloc, x._alloc);
        }

        iterator erase(iterator position)
        {
            difference_type index = position - this->begin();

            this->_alloc.destroy(&_rawData[index]);
            for (size_type i = index; i < this->_size - 1; i++)
            {
                this->_rawData[i] = this->_rawData[i + 1];
            }
            this->_size--;
            return (this->begin() + index);
        }
        iterator erase(iterator first, iterator last)
        {
            difference_type firstPosIndex = first - this->begin();
            difference_type lastPosIndex = firstPosIndex + last - first - 1;

            for (difference_type i = firstPosIndex; i <= lastPosIndex; i++)
            {
                this->erase(this->begin() + firstPosIndex);
            }
            return (this->begin());
        }

        allocator_type get_allocator() const
        {
            return (this->_alloc);
        }

    public:
        ////Iterators:
        iterator begin()
        {
            return iterator(this->_rawData);
        }

        const_iterator begin() const
        {
            return const_iterator(this->_rawData);
        }

        iterator end()
        {
            return iterator(this->_rawData + this->_size);
        }
        const_iterator end() const
        {
            return const_iterator(this->_rawData + this->_size);
        }

        reverse_iterator rbegin()
        {
            return reverse_iterator(this->end() - 1);
        }

        const_reverse_iterator rbegin() const
        {
            return const_reverse_iterator(this->end() - 1);
        }

        reverse_iterator rend()
        {
            return reverse_iterator(this->begin());
        }

        const_reverse_iterator rend() const
        {
            return const_reverse_iterator(this->begin());
        }
    };
    template <class T, class Alloc>
    bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }

    template <class T, class Alloc>
    bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return !(lhs == rhs);
    }

    template <class T, class Alloc>
    bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }

    template <class T, class Alloc>
    bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return ((lhs < rhs) || lhs == rhs);
    }

    template <class T, class Alloc>
    bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
    }

    template <class T, class Alloc>
    bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return ((lhs > rhs) || lhs == rhs);
    }

    template <class T, class Alloc>
    void swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
    {
        x.swap(y);
    }
}
#endif