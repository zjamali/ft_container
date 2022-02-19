#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP
#include <cstddef>
#include "../iterator_traits.hpp"
// #include "../reverse_iterator.hpp"
namespace ft
{
    template <class T, class node_ptr>
    class tree_iterator : public iterator<std::bidirectional_iterator_tag, T>
    {
    public:
        typedef typename iterator_traits<T>::value_type value_type;
        typedef typename iterator_traits<T>::difference_type difference_type;
        typedef typename iterator_traits<T>::pointer pointer;
        typedef typename iterator_traits<T>::reference reference;
        typedef std::bidirectional_iterator_tag iterator_category;

    private:
        node_ptr current_node;

    public:
        tree_iterator() : current_node(nullptr)
        {
        }
        explicit tree_iterator(node_ptr ptr) : current_node(ptr)
        {
        }
        template <class T1, class node_ptr1>
        tree_iterator(const tree_iterator<T1, node_ptr1> &it) : current_node(it.base()) {}

        node_ptr base() const
        {
            return (current_node);
        }

        reference operator*() const
        {
            return (this->current_node->data);
        }
        pointer operator->() const
        {
            return (&(this->operator*()));
        }
        tree_iterator &operator++()
        {
            this->current_node = this->treeSuccessor(this->current_node);
            return (*this);
        }
        tree_iterator operator++(int)
        {
            tree_iterator temp = *this;
            ++(*this);
            return temp;
        }
        tree_iterator &operator--()
        {
            this->current_node = this->treePredecessor(this->current_node);
            return (*this);
        }
        tree_iterator operator--(int)
        {
            tree_iterator temp = *this;
            --(*this);
            return temp;
        }

    private:
        node_ptr treeSuccessor(node_ptr root)
        {
            if (root->right)
                return treeMinimum(root->right);
            node_ptr parent = root->parent;
            while (parent && parent->right == root)
            {
                root = parent;
                parent = parent->parent;
            }
            return (parent);
        }
        node_ptr treePredecessor(node_ptr root)
        {
            if (root->left)
                return treeMaximun(root->left);
            node_ptr parent = root->parent;
            while (parent && parent->left == root)
            {
                root = parent;
                parent = parent->parent;
            }
            return (parent);
        }
        node_ptr treeMaximun(node_ptr treeRoot)
        {
            while (treeRoot->right != NULL)
            {
                treeRoot = treeRoot->right;
            }
            return (treeRoot);
        }
        node_ptr treeMinimum(node_ptr treeRoot)
        {
            while (treeRoot->left != NULL)
            {
                treeRoot = treeRoot->left;
            }
            return (treeRoot);
        }

    public:
        template <class T1, class T2>
        friend bool operator==(const tree_iterator<T1, T2> &x, const tree_iterator<T1, T2> &y);
        template <class T1, class T2>
        friend bool operator!=(const tree_iterator<T1, T2> &x, const tree_iterator<T1, T2> &y);
    };
    template <class T, class node_ptr>
    bool operator==(const tree_iterator<T, node_ptr> &x, const tree_iterator<T, node_ptr> &y)
    {
        return (x.base() == y.base());
    }
    template <class T, class node_ptr>
    bool operator!=(const tree_iterator<T, node_ptr> &x, const tree_iterator<T, node_ptr> &y)
    {
        return (x.current_node != y.current_node);
    }
};

#endif