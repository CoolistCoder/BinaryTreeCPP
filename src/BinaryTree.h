#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include <cstddef>
#include <stack>   //used to store the previous node
#include <iostream>

//node the binary tree will be composed of
struct node{
	node* left;		//the node to the left
	node* right;	//the node to the right
	int data;		//the data within the node
};

class BinaryTree {
private:

	node* newnode(int value);

public:
	node* root;	//the first node
	void insert(int value);	//recursively insert data into the tree
	void print_inorder(); //print out the data in the tree using recursive inorder traversal
	void print_preorder(); //print out the data in the tree using recursive preorder traversal
	void print_postorder(); //print out the data in the tree using recursive postorder traversal
	void clear(); //clear out the binary tree

	BinaryTree();
	virtual ~BinaryTree();
};

#endif
