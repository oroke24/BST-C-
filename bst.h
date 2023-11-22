//By: Jamie O'Roke
//This is header file bst.h 
//This file contains the Bst class, which is a binary search tree
//
#include<vector>
using std::vector;

struct BtreeNode{
	double x;
	BtreeNode * leftChild;
	BtreeNode * rightChild;

	BtreeNode(double x): x(x), leftChild(nullptr), rightChild(nullptr){}
};
class Bst{
	public:
		Bst();
		~Bst();
		void insert(double x);// shouldn't use recursion
		bool searchTree(double x);// should use recursion (call a private recursive func)
		bool searchTree(double x, BtreeNode * node);
		void inOrder(vector<double>& v); //copy values (inorder) to the passed in vector
		void inOrder(vector<double>& v, BtreeNode * node);
		int size(); // return number of nodes in tree
		int size(BtreeNode * node);
		void destroyRecursive(BtreeNode * node);

	private:
		BtreeNode * root;
};

