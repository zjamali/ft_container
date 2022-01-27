#include <iostream>
#define COUNT 15
template <typename node_ptr>
void printUtils(node_ptr root, int space, int depth, int &size)
{
	if (root == 0)
		return;

	space += COUNT;

	printUtils(static_cast<node_ptr>(root->right), space, depth + 1, size);

	std::cout << std::endl;
	for (int i = COUNT; i < space; i++) std::cout << " ";
	std::cout << "bf: " << root->bf << std::endl;
	for (int i = COUNT; i < space; i++) std::cout << " ";
	std::cout << "value: " << root->data.first << std::endl;
	for (int i = COUNT; i < space; i++) std::cout << " ";
	std::cout << "node: " << root << std::endl;
	for (int i = COUNT; i < space; i++) std::cout << " ";
	std::cout << "right: " << root->right << std::endl;
	for (int i = COUNT; i < space; i++) std::cout << " ";
	std::cout << "left: " << root->left << std::endl;
	for (int i = COUNT; i < space; i++) std::cout << " ";
	std::cout << "parent: " << root->parent << std::endl;
	for (int i = COUNT; i < space; i++) std::cout << " ";
	std::cout << "depth: " << depth << std::endl;
	//for (int i = COUNT; i < space; i++) std::cout << " ";
	//std::cout << "value: " << root->data << std::endl;
	size++;
	printUtils(static_cast<node_ptr>(root->left), space, depth + 1, size);
}

template <typename node_ptr>
void print2D(node_ptr *root)
{
	int size;

	size = 0;
	printUtils(root, 0, 0, size);
	std::cout << "*********************************************** size: "
	          << size << std::endl;
}