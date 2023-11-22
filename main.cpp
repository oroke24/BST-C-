//By: Jamie O'Roke
//
#include<iostream>
#include"bst.h"
using std::cout, std::endl;

int main(){
	vector <double> myV;
	Bst tree;
	tree.insert(1);
	tree.insert(2);
	tree.insert(3);
	tree.insert(4);
	tree.insert(5);
	tree.insert(6);
	tree.insert(7);
	tree.insert(8);
	tree.insert(9);
	tree.insert(10);
	cout << "size of tree should be 10: size is " << tree.size() << endl;

	tree.inOrder(myV);
	cout << "copying tree to vector... \nprinting vector: ";
	for(size_t i = 0; i < myV.size(); i++){
		cout << myV.at(i) << ' ';
	}
	//--------------------------------------------------------------
	//
	double x = 5;
	bool check = false;
	
	//Searching through Tree for variable x above 
	cout << endl << "Searching for " << x << " in tree...\n"; 
	if(tree.searchTree(x)) cout << x << " Found in tree." << endl;
	else cout << x << " Not Found in tree." << endl;
	
	//Searching through Vector for the same variable x
	cout << endl << "Searching for " << x << " in vector...\n"; 
	for(size_t i = 0; i < myV.size(); i++){if(myV.at(i) == x) check = true;}
	if(check) cout << x << " Found in vector." << endl;
	else cout << x << " Not Found in vector." << endl;

	return 0;
}
