#include "BinaryTree.h"
#include <iostream>
using namespace std;

//simplest implementation of an iterative binary tree
//note: This is the starting point for other similar binary tree projects

int main() {
	//begin by inserting random data into a tree
	BinaryTree mainTree;
	cout << "Inserting data into the tree..." << endl;
	mainTree.insert(45);
	mainTree.insert(22);
	mainTree.insert(3);
	mainTree.insert(56);
	mainTree.insert(22);
	mainTree.insert(32);
	mainTree.insert(8);

	//demonstrate inorder, preorder, and postorder traversal
	cout << "Insertion complete, printing binary tree in order" << endl;
	mainTree.print_inorder();
	cout << " " << endl;
	cout << "Insertion complete, printing binary tree pre order" << endl;
	mainTree.print_preorder();
	cout << " " << endl;
	cout << "Insertion complete, printing binary tree post order" << endl;
	mainTree.print_postorder();
	cout << " " << endl;

	//empty the tree out
	cout << "clearing the tree out" << endl;
	mainTree.clear();

	cout << "End of program" << endl;
	return 0;
}
