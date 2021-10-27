/*
 * FamilyTree.cpp
 *
 *  Created on: Aug 8, 2020
 *      Author: karapelster
 */

#include <iostream>
#include <string>
#include "FNode.hpp"
#include "FT.hpp"
using namespace std;

FNode *tmp1;
FNode *tmp2;
int count1;
int count2 = 0;

FT::FT(){
	root = NULL;
	size = 0;
}

FT::FT(string n, string c1, string c2, int a){
	root = new FNode(n, c1, c2, a);
	size = 1;
}


void FT::insertTraverse(FNode *tmp, string name){ //preorder traversal that traverses RIGHT then LEFT since older children are on right
	//cout<<"tmp1 name: "<<tmp1->name<<endl;
	if(tmp!=NULL){
		if(tmp->child1!=name && tmp->child2!=name){ //if either of the children of the current node match the name of the new one return this current node
			insertTraverse(tmp->right, name); //traverse to right since right is elder child/ default add if null
			insertTraverse(tmp->left, name); //traverse to left
		}
		else{
			tmp1 = tmp; //set global variable

		}
	}
}

bool FT::insert(FNode *node){
	cout<<endl;
	string name = node->name;
	int age = node->age;

	if(root==NULL){ //if the tree is empty, initialize root
		root = node;
		size+=1;
		return true;
	}

	tmp1 = root;

	insertTraverse(tmp1, name);

	if(tmp1->right==NULL){ //if the right node is empty, then we place it there
		tmp1->right = node;
		node->parent = tmp1;
		setHeight(node); //set height
		size+=1;
		return true;
	}
	else if(tmp1->right->age<age){ //if the right node is not empty but the age is less than what we are adding, something went wrong
		cout<<"Ages are not ordered"<<endl;
		return false;
	}
	else{ //otherwise if the right node is full and the age is greater than what we are adding, then insert left
		tmp1->left = node;
		node->parent = tmp1;
		setHeight(node); //set height
		size+=1;
		return true;
	}
}

void FT::findTraverse(FNode *tmp, string n){
	if(count1==size){
		if(count2==0){
			cout<<"No Member Found"<<endl;}
		count2++;
		return;
	}
	if (tmp!=NULL){
		if(tmp->name!=n){ //if either of the children of the current node match the name of the new one return this current node
			count1 = count1 +1;
			findTraverse(tmp->right, n); //traverse to right since right is elder child/ default add if null
			findTraverse(tmp->left, n); //traverse to left
		}
		else{
			tmp->printInfo(); //print info to user
		}
	}
}


void FT::find(string n){
	count1=0;
	if(root==NULL){ //if root is null, tree is empty so return null
		cout<<"Family Tree is empty."<<endl;
	}
	else{
		findTraverse(root, n);
	}
}

void FT::setHeight(FNode *n){
	/*adjust heights for nodes when a new one is added*/

	n->height = 1; //set newest node height to 1
	n = n->parent; //move to parent

	while(n!=NULL){
		if(n->left==NULL&&n->right!=NULL){ //if left is null, set parent to right+1
			n->height = n->right->height +1;
		}
		else if(n->right==NULL&&n->left!=NULL){ //if right is null, set parent to left+1
			n->height = n->left->height +1;
		}
		else if(n->left!=NULL&&n->right!=NULL){ //if neither null, set to max+1
			n->height = 1+max(n->right->height, n->left->height);
		}
		n=n->parent; //move to next parent
	}
}

void FT::clearTree(){
	if(root==NULL){
		cout<<"Tree is already empty"<<endl;
	}
	else{
		cout << endl << "Clearing Tree..." << endl;
		clearTree(root);
		root = NULL;
		cout<<"Finished Clearing."<<endl;
	}
}


void FT::clearTree(FNode *tmp){
	if (tmp == NULL) {
		return;
	}
	else {
		clearTree(tmp->right);
		clearTree(tmp->left);
		delete(tmp);
	}
}

void FT::printTree(){
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing Tree..." <<endl;
		cout<<"Number of members: "<<size<<endl;
		cout<<endl;
		printTree(*root);
	}

}
void FT::printTree(FNode &n){
	/*print root node first, then traverse right, then left.*/
	if((&n)!=NULL){
		n.printNode();
		printTree(*n.right);

		printTree(*n.left);

	}
}


