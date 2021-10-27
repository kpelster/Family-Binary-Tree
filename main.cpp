/*
 * main.cpp
 *
 *  Created on: Aug 8, 2020
 *      Author: karapelster
 */
//#include "FTMain.hpp"
#include "FT.hpp"
#include "FNode.hpp"
#include <iostream>
#include <iostream>
using namespace std;

void insertionSort(FNode *array, int size);

int main(){

	//these are all of the family members. The list is out of order
	//FNode **famList = NULL;
	FNode *famList[20];
	//famList = new FNode*[20];
	famList[0] = new FNode("Riley", "Skyler", "Harley", 82);
	famList[1] = new FNode("Syd", "", "", 12);
	famList[2] = new FNode("Avery", "Ty", "Sara", 40);
	famList[3] = new FNode("Skyler", "Alex", "Jordan",60);
	famList[4] = new FNode("Alex", "Syd", "", 35);
	famList[5] = new FNode("Morgan", "Riley", "Hayden", 104);
	famList[6] = new FNode("Hunter", "Lauren", "", 41);
	famList[7] = new FNode("Lauren", "", "", 20);
	famList[8] = new FNode("Harley", "Hunter", "", 62);
	famList[9] = new FNode("Jordan", "", "", 40);
	famList[10] = new FNode("Parker", "Jess", "Kyle", 35);
	famList[11] = new FNode("Sara", "", "", 16);
	famList[12] = new FNode("Hayden", "Dakota", "Finley", 84);
	famList[13] = new FNode("James", "", "", 33);
	famList[14] = new FNode("Jess", "", "", 15);
	famList[15] = new FNode("Kyle", "", "", 13);
	famList[16] = new FNode("Finley", "Avery", "", 64);
	famList[17] = new FNode("Ty", "", "", 16);
	famList[18] = new FNode("Dakota", "James", "Parker", 63);


	insertionSort(*famList, 19); //sort list by age


	FT *tree = new FT();
	for(int i=18;i>-1;i--){
		tree->insert(famList[i]); //insert members into tree
	}

	tree->printTree();


	string n;
	cout<<"Enter the name of a family member in the tree. \nIf done, type 'E' or 'e' to end the program. "<<endl;
	cin>>n;
	while(n!="E" && n!="e"){

	tree->find(n); //find family member in tree
	cout<<endl;
	cout<<"Enter the name of a family member in the tree. \nIf done, type 'E' or 'e' to end the program. "<<endl; //ask for more input
	cin>>n;
	}

	cout<<"Program Ended."<<endl;

	tree->clearTree();

	return  0;


}


void insertionSort(FNode *array, int size){
	int j;
	FNode current;
	for(int i=0;i<size;i++){ //for each item in array
		current = array[i]; //assign node
		j = i-1; //look at previous item
		while(j>=0 && array[j].getAge()>current.getAge()){ //while the current node age is less than the previous
			array[j+1]=array[j];  //move jth item forward
			j=j-1;
		}
		array[j+1] = current; //move current node to front

	}

}
