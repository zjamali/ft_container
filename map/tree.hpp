#ifndef TREE_HPP
#define TREE_HPP
#include <memory>
#include <iostream>
#include <algorithm>
#include <utility>

namespace ft
{
    template <class T>
    struct Node
    {
        T data;
        Node<T> *left;
        Node<T> *right;
        Node<T> *parent;
        int bf;
        Node(const T &data) : data(data), left(nullptr), right(nullptr), parent(nullptr), bf(0){};
    };

    template <class key, class T, class Compare = std::less<key>, class Alloc = std::allocator<Node<T> > >
    class tree
    {
    public:
        typedef Alloc allocator_type;
        typedef Node<T> *node_ptr;
        typedef Compare key_compare;
        typedef size_t size_type;

    private:
        node_ptr _root;
        allocator_type _alloc;
        key_compare _comp;
        size_type _size;

    public:
        tree(const allocator_type &alloc = allocator_type(), const key_compare &compare = key_compare())
            : _root(nullptr), _alloc(alloc), _comp(compare), _size(0){};
        ~tree(){};

        node_ptr createNode(T const &data)
        {
            node_ptr newNode = this->_alloc.allocate(1);
            this->_alloc.construct(newNode, data);
            return (newNode);
        }

        void add(T const &data)
        {
            node_ptr newNode = createNode(data);
            if (this->_root == nullptr)
            {
                this->_root = newNode;
                this->_size++;
                return;
            }
            add(this->_root, newNode);
        }
        void add(node_ptr root, node_ptr newNode)
        {
            node_ptr parent = root;
            while (root != nullptr)
            {
                parent = root;
                if (this->_comp(newNode->data, parent->data)) //  (const T& x, const T& y) const {return x<y;}
                    root = root->left;
                else
                    root = root->right;
            }
            if (this->_comp(newNode->data, parent->data))
            {
                parent->left = newNode;
                newNode->parent = parent;
                this->_size++;
            }
            else
            {
                parent->right = newNode;
                newNode->parent = parent;
                this->_size++;
            }
            updateBalanceFactor(newNode);
        }

        void updateBalanceFactor(node_ptr node)
        {
            if (node->bf < -1 || node->bf > 1 )
                std::cout << "\n node : " << node->data << " must rebalance \n";
            node_ptr parent = node->parent;
            if (parent != nullptr)
            {
                if (parent->left == node)
                    parent->bf += 1;
                else if (parent->right == node)
                    parent->bf -= 1;

                // if parent bf change then the grand parent must be update
                if (parent->bf != 0)
                    updateBalanceFactor(parent);
            }
        }
        void leftRotation(node_ptr node)
        void print()
        {
            print(this->_root);
        }
        void print(node_ptr node)
        {
            if (!node)
                return;

            print(node->left);
            std::cout << " -> " << node->data << " {" << node->bf << "}   ";

            print(node->right);
        }
    };
}

#endif