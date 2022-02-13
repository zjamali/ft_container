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

    template <class T, class Compare = std::less<T>, class Alloc = std::allocator<Node<T> > >
    class tree
    {
    public:
        typedef T value_type;
        typedef Compare key_compare;
        typedef size_t size_type;
        typedef Node<value_type> node;
        typedef Node<value_type> *node_ptr;
        typedef typename Alloc::template rebind<node>::other allocator_type;
        typedef ptrdiff_t difference_type;

    private:
        node_ptr _root;
        node_ptr _end;
        allocator_type _alloc;
        key_compare _comp;
        size_type _size;

    public:
        tree(const key_compare &compare = key_compare(), const allocator_type &alloc = allocator_type())
            : _root(nullptr), _alloc(alloc), _comp(compare), _size(0)
        {
            //this->_end = _alloc.allocate(1); // allocate the end node
            this->_end = NULL;
        }
        ~tree(){};

        node_ptr createNode(value_type const &data)
        {
            // node_ptr newNode = node_allocator(_alloc).allocate(1);
            node_ptr newNode = _alloc.allocate(1);
            this->_alloc.construct(newNode, data);
            return (newNode);
        }
        node_ptr base() const
        {
            return (this->_root);
        }
        node_ptr end() const
        {
            return (this->_end);
        }
        node_ptr add(value_type const &data)
        {
            node_ptr newNode = createNode(data);
            if (this->_root == nullptr)
            {
                this->_root = newNode;
                if (this->_end == NULL)
                    this->_end = _alloc.allocate(1);
                this->_end->left = this->_root;
                this->_root->parent = this->_end;
                this->_size++;
                return (this->_root);
            }
            this->_root->parent = NULL;
            node_ptr node = add(this->_root, newNode);
            this->_end->left = this->_root;
            this->_root->parent = this->_end;
            return (node);
        }
        node_ptr add(node_ptr root, node_ptr newNode)
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
            /// if the key already exist then replace the value
            if (parent->data.first == newNode->data.first)
            {
                parent->data.second = newNode->data.second;
                _alloc.deallocate(newNode, 1);
                return (parent);
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
            return (newNode);
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

            newRoot->parent = root->parent; // assign old root parent to new root 

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

        node_ptr treeMinimum(node_ptr treeRoot) const
        {
            if (treeRoot == NULL)
                return (this->_end);
            while (treeRoot->left != NULL)
            {
                treeRoot = treeRoot->left;
            }
            return (treeRoot);
        }
        node_ptr treeMaximun(node_ptr treeRoot) const
        {
            while (treeRoot->right != NULL)
            {
                treeRoot = treeRoot->right;
            }
            return (treeRoot);
        }

        node_ptr find(node_ptr treeRoot, value_type value) const
        {
            node_ptr node = nullptr;
            if (treeRoot == NULL)
                return (NULL);
            while (treeRoot != nullptr)
            {
                node = treeRoot;
                // if (treeRoot->data.second == value.second)
                if (treeRoot->data.first == value.first)
                    break;
                if (this->_comp(value, treeRoot->data))
                    treeRoot = treeRoot->left;
                else
                    treeRoot = treeRoot->right;
            }
            /// if the key alreadey exist
            if (node->data.first == value.first)
                return (node);
            return (nullptr);
        }

        void updateBalanceFactorAfterDelete(node_ptr node, int rightLeft)
        {
            /// make root parent NULL to don't balance end node
            this->_root->parent = NULL;

            if (!node) /// hadchi zayd 
                return;
            if (node != nullptr)
            {
                if (rightLeft == LEFT)
                    node->bf -= 1;
                else if (rightLeft == RIGHT)
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
            this->_root->parent = this->_end;
        }
        void deleleNode(value_type val)
        {
            node_ptr node = find(this->_root, val);

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
            if (!parent)  // neeed to get  fixed leeks<----
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
            this->_size--;
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
            this->_size--;
        }

        void deleteNodethirdCase(node_ptr node)
        {
            node_ptr nodePredecessor = treePredecessor(node);
            value_type nodePredecessorData = nodePredecessor->data;
            this->deleleNode(nodePredecessorData);
            // node->data = nodePredecessorData;

            /*
             * save node parent ,childrens and balance factore before construction
             * construction set above to null
             */
            node_ptr parent = node->parent;
            node_ptr right = node->right;
            node_ptr left = node->left;
            int bf = node->bf;
            this->_alloc.construct(node, nodePredecessorData);
            node->bf = bf;
            node->left = left;
            node->right = right;
            node->parent = parent;
        }

        node_ptr treeSuccessor(node_ptr root) const
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

        node_ptr search(value_type value) const
        {
            return (this->find(this->_root, value));
        }

        allocator_type get_alloc() const
        {
            return (allocator_type());
        }
        size_type size() const
        {
            return (_size);
        }
        size_type max_size() const
        {
            return (std::min(std::numeric_limits<difference_type>::max(), (difference_type)this->_alloc.max_size()));
        }
        void swap(tree &x)
        {
            size_type tmp_size = x._size;
            allocator_type tmp_alloc = x._alloc;
            node_ptr tmp_root = x._root;
            node_ptr tmp_end = x._end;

            x._size = _size;
            _size = tmp_size;

            x._alloc = _alloc;
            _alloc = tmp_alloc;

            x._end = _end;
            _end = tmp_end;

            x._root = _root;
            _root = tmp_root;
        }

        void clear()
        {
            if (this->_root)
            {
                clear(this->_root);
                this->_root = NULL;
            }
            if (this->_end )
                this->_alloc.deallocate(this->_end, 1);
            this->_end = NULL;
            this->_size = 0;
        }
        void clear(node_ptr node)
        {
            if (!node)
                return;
            if (node->left)
                clear(node->left);
            if (node->right)
                clear(node->right);
            this->_alloc.destroy(node);
            this->_alloc.deallocate(node, 1);
            //node = NULL;
        }

        node_ptr lower_bound(value_type val) const
        {
            node_ptr node = this->treeMinimum(this->_root);

            while (!this->_comp(val, node->data))
            {
                if (val.first == node->data.first)
                    break;
                node = this->treeSuccessor(node);
                if (node == NULL)
                {
                    return (this->_end);
                }
            }
            return (node);
        }

        node_ptr upper_bound(value_type val) const
        {
            node_ptr node = this->treeMinimum(this->_root);

            while (!this->_comp(val, node->data))
            {
                node = this->treeSuccessor(node);
                if (node == NULL)
                {
                    return (this->_end);
                }
            }
            return (node);
        }

        

        void print()
        {
            std::cout << "\n";
            print(this->_root);
            std::cout << "\n";
            print2D(this->_root);
            std::cout << "\n";
        }
        void print(node_ptr node)
        {
            if (!node)
                return;

            print(node->left);
            std::cout << " -> " << node->data.second << " {" << node->bf << "}   ";
            print(node->right);
        }
    };
}

#endif
