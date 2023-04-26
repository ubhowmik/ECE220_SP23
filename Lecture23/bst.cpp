#include <iostream>
#include <vector>
#include "bst.hpp"
using namespace std;

bst::bst(){
	root = NULL;
}

bst::~bst(){
	cout<<"delete a binary search tree "<<endl;
	delete_tree(root);
}

void bst::insert(int data){
	if(root == NULL){
		root = new node;
		root->data = data;
		root->left = root->right = NULL;
		return;
	}
	else 
		insert(data, root);
}

node * bst::search(int data){
	if (root == NULL || root->data == data)
		return root;
	else
		return search(data, root);
}

void bst::inorder(){
	if (root == NULL)
		cout<<"empty tree"<<endl;
	else{
		cout<<"inorder traversal of this binary search tree"<<endl;
		vector<int> v;
		inorder(root, v);

//Traversing vector using iterator

		for(vector<int>::iterator it=v.begin(); it!=v.end(); it++){
	        	cout<<"node:"<<*it<<endl;
		}


/*
//Traversing vector without using iterator

       for(int it=0; it<size(v); it++){
			cout<<"node:"<<v[it]<<endl;
	}
	*/
   }
}

int bst::countnodes(){
	/* if (root == NULL)
		return 0;
	else */
		return countnodes(root);
}

void bst::delete_tree(node *root){
	if(root != NULL){
		delete_tree(root->left);
		delete_tree(root->right);
		cout<<"node deleted: "<<root->data<<endl;
		delete root;
	}
}

void bst::insert(int data, node *root){
	if(data == root->data)
		return; //data already exists in BST
	else if(data < root->data){
		if(root->left == NULL){
			root->left = new node;
			root->left->data = data;
			root->left->left = root->left->right = NULL;
			return;
		}
		else
			return insert(data, root->left);
	}
	else{
		if(root->right == NULL){
			root->right = new node;
			root->right->data = data;
			root->right->left = root->right->right = NULL;
			return;
		}
		else
			return insert(data, root->right);
	}
}

node * bst::search(int data, node *root){
	if(root == NULL)
		return NULL;
	if(data == root->data)
		return root;
	else if(data < root->data)
		return search(data, root->left);
	else
		return search(data, root->right);
}

void bst::inorder(node *root, vector<int> &v){
	if(root != NULL){
		inorder(root->left, v);
		v.push_back(root->data);
		inorder(root->right, v);
	}	
}

int bst::countnodes(node *root){
	if(root == NULL)
		return 0;
	else
		return 1+countnodes(root->left)+countnodes(root->right);
}

int bst::getHeight(){
	if (root == NULL)
		return 0;
	else
		return getHeight(root);
}


int bst::getHeight(node *root){
	int lh,rh;

// base case: Reached to NULL
	if(root == NULL)
	return -1;

// recursive case: Calculate the height of the left-subtree and 
//   the right-subtree, and take the bigger one.

   else{
	lh = getHeight(root->left);
	rh = getHeight(root->right);
   if(lh>rh)
	return lh+1;
   else
	return rh+1;
}

}