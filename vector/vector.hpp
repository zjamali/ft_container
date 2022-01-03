#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include "iterator.hpp"

namespace ft {

    template <class T, class Alloc = std::allocator<T> >
    class vector
    {
    public:
        typedef T value_type;
        typedef Alloc allocator_type;
        typedef T &reference;
        typedef T &const_reference;
        typedef T *pointer;
        typedef T *const_pointer;
        typedef int difference_type;
        typedef size_t size_type;

        //typedef ft::iterator<T> iterator;
        //typedef ft::const_iterator<T> const_iterator;
        typedef ft::reverse_iterator<T> reverse_iterator;
        //typedef ft::reverse_iterator<const T> const_reverse_iterator;
        

    private:
        allocator_type _alloc;
        size_type _capacity;
        size_type _size;
        T *_rawData;

    public:
        explicit vector(const allocator_type &alloc = allocator_type())
            : _alloc(alloc), _capacity(0), _size(0), _rawData(NULL)
        {
            /*
            this->_alloc = alloc;
            this->_capacity = 0;
            this->_size = 0;
            this->_rawData = NULL;
            */
        }
        explicit vector(size_type n, const value_type &val = value_type(),
                        const allocator_type &alloc = allocator_type())
            : _alloc(alloc), _capacity(n), _size(n)
        {
            // allocate memory
            this->_rawData = _alloc.allocate(this->_capacity);
            // initialize _rawData
            for (size_type i = 0; i < this->_size; i++)
            {
                _alloc.construct(&_rawData[i], val);
            }
        }
        /*
        template <class InputIterator>
        vector(InputIterator first, InputIterator last,
               const allocator_type &alloc = allocator_type())
        {
        }
        // COPY constructor
*/
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
            return (this->_alloc.max_size());
        }

        void resize(size_type n, value_type val = value_type())
        {
            if (this->_size > n)
            {
                T *ptr = this->_alloc.allocate(this->_capacity);
                for (size_type i = 0; i < this->_size; i++)
                {
                    this->_alloc.construct(&ptr[i], this->_rawData[i]);
                }
                this->_alloc.deallocate(this->_rawData, this->_capacity);
                this->_rawData = ptr;
            }
            else
            {
                T *ptr = this->_alloc.allocate(n);
                for (size_type i = 0; i < this->_size; i++)
                {
                    this->_alloc.construct(&ptr[i], this->_rawData[i]);
                }
                for (size_type i = this->_size; i < n; i++)
                {
                    this->_alloc.construct(&ptr[i], val);
                }
                this->_alloc.deallocate(this->_rawData, this->_capacity);
                this->_rawData = ptr;
                this->_capacity = n;
                this->_size = n;
            }
        }

        void reserve(size_type n)
        {
            if (this->_capacity < n)
            {
                T *ptr = this->_alloc.allocate(n);
                for (size_type i = 0; i < this->_size; i++)
                {
                    this->_alloc.construct(&ptr[i], this->_rawData[i]);
                }
                this->_alloc.deallocate(this->_rawData, this->_capacity);
                this->_rawData = ptr;
                this->_capacity = n;
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

    public:
        /*********  MODIFIERS MEMBERS FUNCTIONS  ********/
        // template<class InputIterator>
        // void assign(InputIterator first, InputIterator last);

        void assign(size_type n, const value_type &val)
        {
            if (this->_capacity < n)
            {
                T *ptr = this->_alloc.allocate(n);
                for (size_type i = 0; i < this->_size; i++)
                {
                    this->_alloc.construct(&ptr[i], val);
                }
                this->_alloc.deallocate(this->_rawData, this->_capacity);
                this->_rawData = ptr;
                this->_capacity = n;
                this->_size = n;
            }
            else
            {
                for (size_type i = 0; i < n; i++)
                {
                    this->_alloc.construct(&_rawData[i], val);
                }
                this->_capacity = n;
                this->_size = n;
            }
        }

        void push_back(const value_type &val)
        {

            if (this->_size == this->_capacity)
            {

                T *ptr = this->_alloc.allocate(this->_capacity * 2);
                for (size_type i = 0; i < this->_size; i++)
                {
                    this->_alloc.construct(&ptr[i], this->_rawData[i]);
                }
                this->_alloc.deallocate(this->_rawData, this->_capacity);
                this->_rawData = ptr;
                this->_capacity = this->_capacity * 2;
            }
            this->_rawData[this->_size] = val;
            this->_size++;
        }

        void pop_back()
        {
            this->_alloc.destroy(&_rawData[_size - 1]);
            this->_size--;
        }

        // iterator insert(iterator position, const value_type &val);

        // void insert(iterator position, size_type n, const value_type &val);
        // template <class InputIterator>
        // void insert(iterator position, InputIterator first, InputIterator last);

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
            T *_rawData = x._rawData;
            size_type _size = x._size;
            size_type _capacity = x._capacity;

            x._rawData = this->_rawData;
            x._size = this->_size;
            x._capacity = this->_capacity;

            this->_rawData = _rawData;
            this->_size = _size;
            this->_capacity = _capacity;
        }

        allocator_type get_allocator() const
        {
            return (this->_alloc);
        }
    };
}
#endif