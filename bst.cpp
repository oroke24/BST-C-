//By: Jamie O'Roke
//Date: 11/14/2023
//
#include"bst.h"
#include<iostream>

using std::cout, std::endl;

Bst::Bst(): root(nullptr){}
Bst::~Bst(){
	destroyRecursive(root);	
}
void Bst::insert(double x)// shouldn't use recursion
{
	if(!this->root) this->root = new BtreeNode(x);
	else{
		BtreeNode * newNode = new BtreeNode(x);
		BtreeNode * root = this->root;
		BtreeNode * parent = nullptr; //trails root becuase roots cant look up, only down
		while(root){
			parent = root;
			if(x <= root->x){
				root = root->leftChild;
			}
			else if(x > root->x){
				root = root->rightChild;
			}
		}
		//Now evaluating the trailing nodes value to determine if newNode
		//should be a left or right child
		if(x <= parent->x) parent->leftChild = newNode;
		else parent->rightChild = newNode;
	}
}
bool Bst::searchTree(double x){return searchTree(x, root);} 	//Kickstarter
bool Bst::searchTree(double x, BtreeNode * node){		//Recursive
	if(!node) return false; //base case
	else{
		if(x == node->x) return true;
		if(x <= node->x) return searchTree(x, node->leftChild);
		else return searchTree(x, node->rightChild);
	}
}
void Bst::inOrder(vector<double>& v) {inOrder(v, root);} 	//Kickstarter
void Bst::inOrder(vector<double>& v, BtreeNode * node){		//Recursive
	if(!node) return; //base case
	inOrder(v, node->leftChild);
	v.push_back(node->x);
	inOrder(v, node->rightChild);
}
int Bst::size(){return size(root);} 	//Kickstarter
int Bst::size(BtreeNode * node){ 	//Recursive
	if(!node) return 0; //base case
	else return (size(node->leftChild) + 1 + size(node->rightChild)); 
}
void Bst::destroyRecursive(BtreeNode * node){
	if(node){
		destroyRecursive(node->leftChild);
		destroyRecursive(node->rightChild);
		delete node;
	}
}
