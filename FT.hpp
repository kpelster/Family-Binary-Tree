/*
 * FamilyTree.hpp
 *
 *  Created on: Aug 8, 2020
 *      Author: karapelster
 */

#ifndef FT_HPP_
#define FT_HPP_
#include "FNode.hpp"


class FT {
	FNode *root;
	string name;
	int size;


public:
	FT();
	FT(string n, string c1, string c2, int a);
	//FNode *PreOTraverse(FNode *tmp, string name, bool rightNULL); //pre order traversal
	void insertTraverse(FNode *tmp, string name); //pre order traversal
	void findTraverse(FNode *tmp, string name);
	//bool insert(string n, string c1, string c2, int a);
	bool insert(FNode *node);
	void find(string n);
	void clearTree();
	void clearTree(FNode *tmp);
	void setHeight(FNode *n);
	void printTree();
	void printTree(FNode &n);



};

#endif /* FT_HPP_ */
