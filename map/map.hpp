#ifndef MAP_HPP
#define MAP_HPP
#include <memory>
#include <algorithm>
#include <iostream>
#include <utility>
#include <functional>
#include <cstddef>
#include "tree.hpp"
#include "./map_iterator.hpp"
#include "../utils.hpp"

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
        class value_compare
        {
            friend class map;

        protected:
            Compare comp;
            value_compare(Compare c) : comp(c) {}

        public:
            typedef bool result_type;
            typedef value_type first_argument_type;
            typedef value_type second_argument_type;
            bool operator()(const value_type &x, const value_type &y) const
            {
                return comp(x.first, y.first);
            }
        };

    private:
        typedef typename ft::tree<value_type, value_compare, allocator_type> tree;
        typedef typename ft::Node<value_type> node;
        typedef node *node_ptr;
    
    public:
        typedef tree_iterator<pointer, node_ptr> iterator;
        typedef tree_iterator<const_pointer, node_ptr> const_iterator;
        typedef typename ft::reverse_iterator<iterator> reverse_iterator;
        typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;

    private:
        //ft::tree<value_type, value_compare, allocator_type> _tree;
        tree _tree;
        allocator_type _alloc;
        key_compare _compare;

    public:
        explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
            : _tree(value_compare(comp), alloc), _alloc(alloc), _compare(comp)
        {
        }
        /// range
        template <class InputIterator>
        map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
            : _tree(value_compare(comp), alloc), _alloc(alloc), _compare(comp)
        {
            this->insert(first, last);
        }
        ////// copy
        map(const map &x) : _tree(value_compare(x._compare), x._alloc), _alloc(x._alloc), _compare(x._compare)
        {
            *this = x;
        }

        map &operator=(const map &obj)
        {
            // this need to fix
            if (this != &obj)
            {
                insert(obj.begin(), obj.end());
            }
            return (*this);
        }

        ~map()
        {
            this->clear();
        }

    public:
        //// Iterators
        iterator begin()
        {
            return (iterator(this->_tree.treeMinimum(_tree.base())));
        }
        const_iterator begin() const
        {
            return (const_iterator(_tree.treeMinimum(_tree.base())));
        }
        iterator end()
        {
            return (iterator(this->_tree.end()));
        }
        const_iterator end() const
        {
            return (const_iterator(this->_tree.end()));
        }
        reverse_iterator rbegin()
        {
            return (reverse_iterator(this->end()));
        }
        const_reverse_iterator rbegin() const
        {
            return (const_reverse_iterator(this->end()));
        }
        reverse_iterator rend()
        {
            return (reverse_iterator(this->begin()));
        }
        const_reverse_iterator rend() const
        {
            return (const_reverse_iterator(this->begin()));
        }

    public: // Element access:
        mapped_type &operator[](const key_type &k)
        {
            return (insert(ft::make_pair(k, mapped_type())).first->second);
        }

    public: // Capacity:
        bool empty() const
        {
            return (this->_tree.size() == 0);
        }
        size_type size() const
        {
            return (this->_tree.size());
        }
        size_type max_size() const
        {
            return (std::min(std::numeric_limits<difference_type>::max(),
                             (difference_type)this->_alloc.max_size()));
        }

    public: /// Modifiers
        ft::pair<iterator, bool> insert(const value_type &val)
        {
            node_ptr node = _tree.search(val);
            if (node != nullptr)
                return (ft::pair<iterator, bool>(iterator(node), false));

            node_ptr inserted_node = _tree.add(val);
            return (ft::pair<iterator, bool>(iterator(inserted_node), true));
        }

        iterator insert(iterator position, const value_type &val)
        {
            node_ptr node = _tree.search(val);
            if (node != nullptr)
                return (iterator(node));
            (void)position;
            node_ptr n = this->_tree.add(val);
            return (iterator(n));
        }

        template <class InputIterator>
        void insert(InputIterator first, InputIterator last)
        {
            while (first != last)
            {
                _tree.add(*first);
                first++;
            }
        }

        void erase(iterator position)
        {
            this->_tree.deleleNode(ft::make_pair(position->first, position->second));
        }
        size_type erase(const key_type &k)
        {
            node_ptr node = this->_tree.search(ft::make_pair(k, mapped_type()));
            if (node)
            {
                this->_tree.deleleNode(ft::make_pair(k, mapped_type()));
                return (1);
            }
            return (0);
        }
        void erase(iterator first, iterator last)
        {
            iterator position;
            while (first != last)
            {
                position = first;
                first++;
                this->erase(position);
            }
        }

        void swap(map &x)
        {
            this->_tree.swap(x._tree);
        }

        void clear()
        {
            this->_tree.clear();
        }

    public: // Observers:
        key_compare key_comp() const
        {
            return (_compare);
        }
        value_compare value_comp() const
        {
            return value_compare(_compare);
        }

    public: /// Operations:
        iterator find(const key_type &k)
        {
            node_ptr node = this->_tree.search(ft::make_pair(k, mapped_type()));
            if (node == NULL)
                return (this->end());
            return (iterator(node));
        }
        const_iterator find(const key_type &k) const
        {
            node_ptr node = this->_tree.search(ft::make_pair(k, mapped_type()));
            if (node == NULL)
                return (this->end());
            return (const_iterator(node));
        }

        size_type count(const key_type &k) const
        {
            return (this->find(k) != this->end() ? 1 : 0);
        }

        iterator lower_bound(const key_type &k)
        {
            return (iterator(this->_tree.lower_bound(ft::make_pair(k, mapped_type()))));
        }
        const_iterator lower_bound(const key_type &k) const
        {
            return (const_iterator(this->_tree.lower_bound(ft::make_pair(k, mapped_type()))));
        }
    
        iterator upper_bound(const key_type &k)
        {
            return (iterator(this->_tree.upper_bound(ft::make_pair(k, mapped_type()))));
        }
        const_iterator upper_bound(const key_type &k) const
        {
            return (const_iterator(this->_tree.upper_bound(ft::make_pair(k, mapped_type()))));
        }

        pair<const_iterator, const_iterator> equal_range(const key_type &k) const
        {
            return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
        }
        pair<iterator, iterator> equal_range(const key_type &k)
        {
            return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
        }
        
        allocator_type get_allocator() const
        {
            return(this->_tree.get_alloc());
        }
    public: //////////////////////////////////////////////////
        void print()
        {
            if (this->_tree.base() != NULL)
                _tree.print();
        }
    };

}

#endif