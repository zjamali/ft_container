#ifndef MAP_HPP
#define MAP_HPP
#include <memory>
#include <algorithm>
#include <iostream>
#include <utility>
#include <functional>
#include <cstddef>
#include "tree.hpp"
#include "iterator.hpp"
#include "utills.hpp"

namespace ft
{
    template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
    class map
    {
    public:
        typedef Key key_type;
        typedef T mapped_type;
        typedef ft::pair<const key_type, mapped_type> value_type;
        typedef Compare key_compare;
        typedef Alloc allocator_type;
        typedef value_type &reference;
        typedef const value_type &const_reference;
        typedef value_type *pointer;
        typedef const value_type *const_pointer;
        typedef std::ptrdiff_t difference_type;
        typedef size_t size_type;

    public:
        // template <class _Key, class _T, class _Compare, class _Alloc>
        class value_compare
        { // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
            friend class map;

        protected:
            Compare comp;
            value_compare(Compare c) : comp(c) {} // constructed with map's comparison object
        public:
            typedef bool result_type;
            typedef value_type first_argument_type;
            typedef value_type second_argument_type;
            bool operator()(const value_type &x, const value_type &y) const
            {
                return comp(x.first, y.first);
            }
        };

    public:
        typedef typename ft::tree<value_type, value_compare, allocator_type> tree;
        typedef typename ft::Node<value_type> node;
        typedef node *node_ptr;
        typedef tree_iterator<pointer, node_ptr> iterator;
        // typedef tree_iterator<const_pointer , node_ptr> const_iterator;
        // typedef typename ft::reverse_iterator<iterator> reverse_iterator;
        // typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
        // typedef typename iterator_traits<iterator>::difference_type difference_type;

    private:
        tree _tree;
        allocator_type _alloc;
        key_compare _compare;

    public:
        explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
            : _tree(value_compare(comp), alloc), _alloc(alloc), _compare(comp)
        {
        }
        /// range
        // template <class InputIterator>
        // map(InputIterator first, InputIterator last,
        //     const key_compare &comp = key_compare(),
        //     const allocator_type &alloc = allocator_type());
        // // copy
        map(const map &x) : _tree(value_compare(x.comp), x._alloc), _alloc(x._alloc), _compare(x._compare)
        {
            *this = x;
        }

        map &operator=(const map &obj)
        {
            if (this != &obj)
            {
                this->_alloc = obj._alloc;
                this->_compare = obj._compare;
                // copy tree ----->
            }
            return (*this);
        }

        ~map() {}

    public:
        ft::pair<iterator, bool> insert(const value_type &val)
        {
            node_ptr node = _tree.search(val);
            if (node != nullptr)
                return (ft::pair<iterator,bool>(iterator(node), false)) ;
            std::cout << "jdgshjkdhsgj\n";
            node_ptr inserted_node = _tree.add(val);
            return (ft::pair<iterator, bool>(iterator(inserted_node),true));
        }
        void print()
        {
            if (this->_tree.base() != NULL)
                _tree.print();
        }

    public:
        iterator begin()
        {
            return (iterator(this->_tree.treeMinimum(this->_tree.base())));
        }
        iterator end()
        {
            return (iterator(this->_tree.end()));
        }
    };
}

#endif