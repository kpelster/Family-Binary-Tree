/*
 * FamilyNode.hpp
 *
 *  Created on: Aug 8, 2020
 *      Author: karapelster
 */

#ifndef FNODE_HPP_
#define FNODE_HPP_
#include <iostream>
#include <string>
using namespace std;


class FNode{

private:
	friend class FT;
	friend class main;
	FNode *left;
	FNode *right;
	FNode *parent;
	int age;
	string child1;
	string child2;
	string name;
	int height;

public:
	friend class FTMain;
	FNode(string n, string c1, string c2, int a);
	FNode();
	~FNode();
	void printNode();
	int getAge();
	void printInfo();
};


#endif /* FNODE_HPP_ */
