#include <iostream>
//#include <csignal>
#include "assignment6.h"
#include "assignment5.h"
using std::cout;
using std::endl;
// Public Members
void BST::insert(int item){
	this->insert(root, item);
}
bool BST::search(int item){
	return this->search(root, item);
}
bool BST::remove(int item){
	return this->remove(root, item);
}
int BST::sumOfRange(int lower, const int upper){
	return sumOfRange(root, lower, upper);
}
// Private Members
void BST::insert(Node*& node, int item){
	if(node==NULL)
		node=new Node(item);
	else
		if(node->value > item)
			insert(node->left, item);
		else insert(node->right, item);
}

bool BST::search(Node*& node, int item){
	if(node==NULL) return false;
	if(node->value == item) return true;
	if(node->value > item)
		return search(node->left, item);
	return search(node->right, item);
}

bool BST::remove(Node *&node, int value){
//	cout<<"Trying to delete: "<<value<<endl;
	if(!node) return false;
	if(node->value > value)
		remove(node->left, value);
	else if(node->value < value)
		remove(node->right, value);
	else{
		if((node->right==NULL) & (node->left==NULL)){
			node=NULL;
			delete node;
		}
		else if(node->left == NULL){
			Node* tmp=node;
			node=node->right;
			tmp=NULL;
			delete tmp;
		}
		else if(node->right == NULL){
			Node* tmp=node;
			node=node->left;
			tmp=NULL;
			delete tmp;
		}
		else{
			// Find n's pred, copy pred's data to n, rec call
			Node* pred=node->left;
			Node* next=pred->right;
			while(next){
				pred=next;
				next=next->right;
			}
			node->value=pred->value;
			remove(node->left, pred->value);
		}
	}
	return true;
}

int BST::sumOfRange(Node*& node, const int lower, const int upper){
	if(node==NULL) return 0;
	if((node->value >= lower) & (node->value <= upper))	// If value is within range
		// Add the value and return the sum of valid nodes from left and right trees
		return node->value + sumOfRange(node->right, lower, upper)+ sumOfRange(node->left, lower, upper);
	// else just return the sum of left and right subtree's valid nodes
	return sumOfRange(node->right, lower, upper)+ sumOfRange(node->left, lower, upper);
}
