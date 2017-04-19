#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;

	Node(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

void insert(Node* node, int data) {
	if(data < node->data) { // Insert left
		if(node->left)
			insert(node->left, data);
		else // If left is NULL, create left
			node->left = new Node(data);
	} else if(data >= node->data) { // Insert right
		if(node->right)
			insert(node->right, data);
		else // If right is NULL, 
			node->right = new Node(data);
	}
}

void postOrder(Node* node, int indent) {
	if(node) {
		for(int i = 0; i < indent; i++)
			cout << ' ';
		cout << node->data << endl;
		if(node->left) postOrder(node->left, indent+2);
		if(node->right) postOrder(node->right, indent+2);
	}
}

int main(int argv, char** argc) {
	Node* root = new Node(0);
	int input;

	while(cin >> input) {
		insert(root, input);
		postOrder(root, 0);
	}
}
