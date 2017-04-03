#include <iostream>

using namespace std;

struct Node {
	Node* next;
	int value;

	Node(int value) {
		this->value = value;
	}
};

void removeKthToLastNode(Node* node, int k, int &answer) {
	if(!node)
		return;	

	removeKthToLastNode(node->next, k, answer);

	if(k == 0)
		answer = node->value;

	k--;	
}

int main(int argv, char** argc) {
	Node* head = new Node(0);
	Node* n1 = new Node(1);	
	Node* n2 = new Node(2);
	Node* n3 = new Node(3);
	Node* n4 = new Node(4);
	Node* n5 = new Node(5);
	Node* n6 = new Node(6);
	Node* n7 = new Node(7);

	head->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;

	int answer = 0;

	//removeKthToLastNode(head,3,answer);

	cout << answer << endl;
}
