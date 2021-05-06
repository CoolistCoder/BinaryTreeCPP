#include "BinaryTree.h"

node* BinaryTree::newnode(int value){
	node* temp = new node();
	temp->left = NULL;
	temp->right = NULL;
	temp->data = value;
	return temp;
}

void BinaryTree::insert(int value){
	node* temp = this->root;	//the temp node keeps track of the current position
	node* prev;					//the previous node keeps track of temp's parent node
	if (!root){					//if the root is empty
		root = newnode(value);	//populate the root with data
		return;
	}
	while (temp){					//if the temp node is not null
		prev = temp;				//capture the node in previous
		if (value < temp->data){	//go left if the value < current node data
			temp = temp->left;
		}
		else if (value > temp->data){ //go right if the value > current node data
			temp = temp->right;
		}
		else{ //we do not want duplicates whatsoever
			std::cout << "No duplicates allowed" << std::endl;
			return;
		}
	}

	//retreat into the previous node in order to insert the data properly
	if (value < prev->data){			//insert the data left if the value is < the data at the current position
		prev->left = newnode(value);
	}
	else {								//insert the data left if the value is < the data at the current position
		prev->right = newnode(value);
	}
}

void BinaryTree::print_inorder(){
	std::stack<node*> nodestack;			//this is where previous nodes will be stored temporarily
	node* temp = this->root;				//traversal node
	while(temp || !nodestack.empty()){		//while the temporary node is not empty and the stack has something in it..
		while (temp){						//first, store the current branch and travel left
			nodestack.push(temp);			//repeat until we can't go left further
			temp=temp->left;
		}
		temp=nodestack.top();				//once we're at the end, pop the top to return to the last node
		nodestack.pop();
		std::cout << temp->data << std::endl; //print out the data at the position
		temp=temp->right;					//travel right
	}
}

void BinaryTree::print_preorder(){
	if (!this->root){					//check if the root's empty
		return;							//return if there's nothing in the root
	}
	std::stack<node*> nodestack;		//create a stack to return to the previous node/s
	node* temp = this->root;			//temporary node for iteration
	nodestack.push(temp);				//push the node to the stack
	while(!nodestack.empty()){
		temp = nodestack.top();			//begin with what's on the top of the stack
		std::cout << temp->data << std::endl;	//print the top of the stack
		nodestack.pop();				//remove the top of the stack

		if(temp->right){				//save the right branch to iterate to it
			nodestack.push(temp->right);//this will be the new top
		}
		if (temp->left){				//save the left branch to iterate to it
			nodestack.push(temp->left); //this will be the new top
		}
	}
}

void BinaryTree::print_postorder(){
	if (!this->root){					//check if the root's empty
		return;							//return if there's nothing in the root
	}

	std::stack<node*> nodestack;			//this stack will be used to capture the previous node
	std::stack<node*> postorder_stack;		//this stack will be used to store everything in postorder format
	node* temp = this->root;				//begin by saving the root to the nodestack
	nodestack.push(temp);

	while(!nodestack.empty()){			//go to the next loop if the nodestack is emptied out
		temp = nodestack.top();			//restore the current node the iterator is at
		nodestack.pop();				//remove the node from the nodestack
		postorder_stack.push(temp);		//push what we have into the formatted stack
		if (temp->left){				//save the left node to the stack for iteration
			nodestack.push(temp->left);
		}
		if (temp->right){				//save the right node to the stack for iteration
			nodestack.push(temp->right);
		}
	}

	//with our formatted stack, we can simply go through and print each node within the stack
	while(!postorder_stack.empty()){
		std::cout << postorder_stack.top()->data << std::endl;
		postorder_stack.pop();	//remove nodes from the top as we go
	}
}

void BinaryTree::clear(){
	if (!this->root){					//check if the root's empty
		return;							//return if there's nothing in the root
	}

	std::stack<node*> nodestack;	//use the stack to store the previous node
	node* temp = this->root;		//temp is the iterator
	nodestack.push(temp);			//push the root to the nodestack
	while(!nodestack.empty()){		//repeat until the stack is empty
		temp = nodestack.top();		//get the last node saved
		nodestack.pop();			//remove the last node from the stack
		if (temp->left){			//go left down the tree
			nodestack.push(temp->left);
		}
		if(temp->right){			//go right down the tree
			nodestack.push(temp->right);
		}
		delete temp;				//remove the current node from memory
	}
	this->root = NULL;				//nullify the root, as it is deleted
}

BinaryTree::BinaryTree() {
	//nullify the root and its branches
	this->root = NULL;
}

BinaryTree::~BinaryTree() {

}

