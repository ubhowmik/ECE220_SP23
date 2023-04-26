#include <vector>
using namespace std; 

struct node{
	int data;
	node *left;
	node *right;
};

class bst{
	public:
		bst();
		~bst();
		void insert(int data);
		node *search(int data);
		void inorder();
		int countnodes();
		int getHeight();

	private:
		void delete_tree(node *root);
		void insert(int data, node *root);
		node *search(int data, node *root);
		void inorder(node *root, vector<int> &v);
		int countnodes(node *root);
		int getHeight(node *root);
		node *root;
};

