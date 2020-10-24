/*Note: you must create the BST.cpp file.  I'm only including a few 
Otherwise, as specified in the directions, you must write the BST.cpp.
including the method definitions to accompany the method declarations 
in BST.hpp
*/

#include "BST.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

BST::BST() {
	root = NULL;
}
BST::BST(string s) {
	root = new TNode(s);
}

void BST::printTreeIO() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing In Order:" <<endl;
		printTreeIO(root);
	}
}


void BST::printTreePre() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing PreOrder:" <<endl;
		printTreePre(root);
	}
}


void BST::printTreePost() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing PostOrder:" <<endl;
		printTreePost(root);
	}
}


void BST::clearTree() {
	if (root == NULL) {
		cout << "Tree already empty" << endl;
	}
	else {
		cout << endl << "Clearing Tree:" << endl;
		clearTree(root);
		root = NULL;
	}
}
void BST::clearTree(TNode *tmp) {
	if (tmp == NULL) {
		return;
	}
	else {
		clearTree(tmp->left);
		clearTree(tmp->right);
		tmp->printNode();
		delete(tmp);
	}
}

bool BST::insert(string s){

	if(root == NULL){
		TNode *newNode = new TNode(s);
		root = newNode;
		setHeight(newNode);
		return true;
	}

	else{
		TNode *n = root;

		while(n != NULL){

			if(s < n->data->phrase){
				if(n->left == NULL){
					TNode *newNode = new TNode(s);
					newNode->parent = n;
					n->left = newNode;
					setHeight(newNode);
					return true;
				}
				else{
					n = n->left;
				}
			}
			else if(s > n->data->phrase){
				if(n->right == NULL){
					TNode *newNode = new TNode(s);
					newNode->parent = n;
					n->right = newNode;
					setHeight(newNode);
					return true;
				}
				else{
					n = n->right;
				}
			}
		}
	}

	return false;
}

TNode* BST::find(string s){

	if(root == NULL){
		return NULL;
	}

	else{
		TNode *n = root;

		while(n != NULL){
			if(s == n->data->phrase){
				return n;
			}
			else if(s > n->data->phrase){
				n = n->right;
			}
			else if(s < n->data->phrase){
				n = n->left;
			}
		}
	}

	return NULL;
}

void BST::printTreeIO(TNode *n){
	// In-order Traversal: left, parent, right

	if(n == NULL){
		return;
	}
	else{
		printTreeIO(n->left);
		n->printNode();
		printTreeIO(n->right);
	}
}

void BST::printTreePre(TNode *n){
	// Pre-order Traversal: parent, left, right

	if(n == NULL){
		return;
	}
	else{
		n->printNode();
		printTreePre(n->left);
		printTreePre(n->right);
	}
}

void BST::printTreePost(TNode *n){
	//Post-order Traversal: left, right, parent

	if(n == NULL){
		return;
	}
	else{
		printTreePost(n->left);
		printTreePost(n->right);
		n->printNode();
	}
}


