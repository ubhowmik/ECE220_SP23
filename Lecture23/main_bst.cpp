#include <iostream>
#include "bst.hpp"
using namespace std;

int main(){
	cout<<"build a binary search tree"<<endl;
	bst tree1;
	tree1.insert(30);
	tree1.insert(20);
	tree1.insert(10);
	tree1.insert(15);
	tree1.insert(50);
    tree1.insert(12);
       
	cout<<"total number of nodes in this tree: "<<tree1.countnodes()<<endl;
	
//searching a node;

int node_data=6;
cout<<"Searching a node with data_val:"<<node_data<<endl;

node *x;
x=tree1.search(node_data);

if (x)
	cout<<"Node Found. The address is: "<<x<<endl;
else
        cout<<"Node does not exist"<<endl;

//Calculating the height of the Tree

cout<<"The height of the tree is:"<<tree1.getHeight()<<endl;

tree1.inorder();

	return 0;
}


