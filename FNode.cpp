/*
 * FamilyNode.cpp
 *
 *  Created on: Aug 8, 2020
 *      Author: karapelster
 */


#include <iostream>
#include <string>
#include "FNode.hpp"
using namespace std;

FNode::FNode(string n, string c1, string c2, int a){
	left = NULL;
	right = NULL;
	parent = NULL;
	height = 1;
	name = n;
	child1 = c1;
	child2 = c2;
	age = a;
}

FNode::FNode(){
	left = NULL;
	right = NULL;
	parent = NULL;
	height = 1;
	name = "";
	child1 = "";
	child2 = "";
	age = 0;
}

void FNode::printNode(){
	cout <<"name: "<< name<<", age: "<<age<<endl;
	if(child1!=""){
	cout <<"child 1: "<< child1<<endl;}
	if(child2!=""){
	cout <<"child 2: "<< child2<<endl;}
	cout <<"height: "<<height<<endl;
	cout<<endl;
}

int FNode::getAge(){
	return age;
}


void FNode::printInfo(){
	cout<<name<< " is "<< age<<" years old and is at height "<< height<< " in the Family Tree."<<endl;
	if(parent!=NULL){
		cout<<"They are a child of "<<parent->name<<"."<<endl;
	}
	if(child1==""&&child2==""){
		cout<<"They have no children."<<endl;
	}
	else if(child2==""){
		cout<<"They have one child, "<<child1<<"."<<endl;
	}
	else{
		cout<<"They have two children, "<<child1<<" and "<<child2<<"."<<endl;
	}
}

FNode::~FNode(){
}




