#include "assignment5.h"
// public members
binTree::binTree(){
	this->root=nullptr;
}
void binTree::insert(int value){
	this->insert(this->root, value);
}
int binTree::height() const{
	return this->height(this->root);
}
unsigned binTree::size() const{
	return this->size(this->root);		
}
void binTree::inorder(void (*func)(int)){
	this->inorder(this->root, func);
}
void binTree::preorder(void (*func)(int)){
	this->preorder(this->root, func);
}
void binTree::postorder(void (*func)(int)){
	this->postorder(this->root, func);
}

// Private versions
void binTree::insert(Node*& node, int value){
	if(node==nullptr){
		node=new Node(value);
		return;
	}
	if(height(node->right) < height(node->left))
		insert(node->right, value);
	else insert(node->left, value);	
}
int binTree::height(Node* node) const{
	if(node==nullptr) return -1;
	int leftHeight=height(node->left);
	int rightHeight=height(node->right);
	return (leftHeight > rightHeight ? leftHeight : rightHeight)+1;
}
unsigned binTree::size(Node* node) const{
	if(node==nullptr) return 0;
	return size(node->left)+size(node->right)+1;
}
void binTree::inorder(Node* node, void(*func)(int)){
	if(node){
		inorder(node->left, func);
		func(node->value);
		inorder(node->right, func);
	}
}
void binTree::preorder(Node* node, void(*func)(int)){
	if(node){
		func(node->value);
		preorder(node->left, func);
		preorder(node->right, func);
	}
}
void binTree::postorder(Node* node, void(*func)(int)){
	if(node){
		postorder(node->left, func);
		postorder(node->right, func);
		func(node->value);
	}
}
