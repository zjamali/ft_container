#ifndef TREE_HPP
#define TREE_HPP
#include <memory>
#include <iostream>
#include <algorithm>
#include <utility>
#include "print.hpp"

#define RIGHT 1
#define LEFT -1

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
            if (node->bf < -1 || node->bf > 1)
            {
                rebalance(node);
                return;
            }
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

        void leftRotation(node_ptr root)
        {
            node_ptr newRoot = root->right; // new_root
            root->right = newRoot->left;    // root get left of new root
            if (newRoot->left)              // assign parent of of left to root
                newRoot->left->parent = root;

            newRoot->parent = root->parent; //

            if (root->parent == NULL) // make new_root as tree root
                this->_root = newRoot;
            else if (root->parent->left == root)
                root->parent->left = newRoot;
            else
                root->parent->right = newRoot;

            newRoot->left = root;
            root->parent = newRoot;

            root->bf = root->bf + 1 - std::min(0, newRoot->bf);
            newRoot->bf = newRoot->bf + 1 + std::max(root->bf, 0);
        }

        void rightRotation(node_ptr root)
        {
            node_ptr newRoot = root->left; // new_root

            root->left = newRoot->right;
            if (newRoot->right)
                newRoot->right->parent = root;
            newRoot->parent = root->parent;

            if (root->parent == NULL)
                this->_root = newRoot;
            else if (root->parent->right == root)
                root->parent->right = newRoot;
            else
                root->parent->left = newRoot;

            newRoot->right = root;
            root->parent = newRoot;

            root->bf = root->bf - 1 - std::max(0, newRoot->bf);
            newRoot->bf = newRoot->bf - 1 + std::min(root->bf, 0);
        }

        void rebalance(node_ptr node)
        {
            if (node->bf < 0)
            {
                if (node->right && node->right->bf > 0)
                {
                    rightRotation(node->right);
                    leftRotation(node);
                }
                else
                    leftRotation(node);
            }
            else if (node->bf > 0)
            {
                if (node->left && node->left->bf < 0)
                {
                    leftRotation(node->left);
                    
                    rightRotation(node);
                }
                else
                    rightRotation(node);
            }
        }

        node_ptr treeMinimum(node_ptr treeRoot)
        {
            while (treeRoot->left != NULL)
            {
                treeRoot = treeRoot->left;
            }
            return (treeRoot);
        }
        node_ptr treeMaximun(node_ptr treeRoot)
        {
            while (treeRoot->right != NULL)
            {
                treeRoot = treeRoot->right;
            }
            return (treeRoot);
        }

        node_ptr find(node_ptr treeRoot, int value)
        {
            node_ptr node = nullptr;
            while (treeRoot != nullptr)
            {
                node = treeRoot;
                if (treeRoot->data == value)
                    break;
                if (this->_comp(value, treeRoot->data))
                    treeRoot = treeRoot->left;
                else
                    treeRoot = treeRoot->right;
            }
            if (node->data == value)
                return (node);
            return (nullptr);
        }

        void updateBalanceFactorAfterDelete(node_ptr node, int rightLeft)
        {
            if (!node)
                return;
            if (node != nullptr)
            {
                if (rightLeft == -1)
                    node->bf -= 1;
                else
                    node->bf += 1;
            }
            if (node->bf < -1 || node->bf > 1)
            {
                rebalance(node);
                return;
            }
            if (node->bf == 0)
            {
                if (node->parent != nullptr)
                {
                    if (node->parent->right == node)
                        updateBalanceFactorAfterDelete(node->parent, RIGHT);
                    else
                        updateBalanceFactorAfterDelete(node->parent, LEFT);
                }
            }
        }
        void deleleNode(int value)
        {
            node_ptr node = find(this->_root, value);

            if (!node) // node not found
                return;
            if (!node->left && !node->right) // first case node isa leaf node
                deleteNodeFirstCase(node);
            else if (node->left == NULL || node->right == NULL) // second case node has only one child
                deleteNodeSecondCase(node);
            else /// third case
                deleteNodethirdCase(node);
        }
        void deleteNodeFirstCase(node_ptr node)
        {
            node_ptr parent = node->parent;
            if (!parent)
                return;
            if (parent->left == node)
            {
                this->_alloc.deallocate(node, 1);
                parent->left = NULL;
                updateBalanceFactorAfterDelete(parent, LEFT);
            }
            else
            {
                parent->right = NULL;
                this->_alloc.deallocate(node, 1);
                updateBalanceFactorAfterDelete(parent, RIGHT);
            }
        }
        void deleteNodeSecondCase(node_ptr node)
        {
            node_ptr newRoot = nullptr;
            node_ptr parent = node->parent;

            // get new root is child of node
            if (node->left)
                newRoot = node->left;
            else
                newRoot = node->right;

            if (!parent) // node is root
                this->_root = newRoot;
            else
            {
                newRoot->parent = parent;
                if (parent->right == node)
                {
                    parent->right = newRoot;
                    updateBalanceFactorAfterDelete(parent, RIGHT);
                }
                else
                {
                    parent->left = newRoot;
                    updateBalanceFactorAfterDelete(parent, LEFT);
                }
            }
            this->_alloc.deallocate(node, 1);
        }
        void deleteNodethirdCase(node_ptr node)
        {
            node_ptr nodePredecessor = treePredecessor(node);
            // node->data = nodePredecessor->data;
            int nodePredecessorData = nodePredecessor->data;
            this->deleleNode(nodePredecessorData);
            node->data = nodePredecessorData;
        }
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
            if (root->right)
                return treeMaximun(root->left);
            node_ptr parent = root->parent;
            while (parent && parent->right == root)
            {
                root = parent;
                parent = parent->parent;
            }
            return (parent);
        }
        
        node_ptr search(int value)
        {
            return (this->find(this->_root,value));
        }

        void print()
        {
            std::cout<< "\n"; 
            print(this->_root);
            std::cout<< "\n"; 
            print2D(this->_root);
            std::cout<< "\n"; 
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