#include <iostream>

using namespace std;

struct Node {
	Node* next;
	int value;

	Node(int value) {
    this->value = value;
  }
};

Node* initializeLinkedList(Node* head) {
	Node* node1 = new Node(1);
	Node* node2 = new Node(2);
	Node* node3 = new Node(3);
	Node* node4 = new Node(4);
	Node* node5 = new Node(5);

	head->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;

	return node5;
}

void reverseLinkedList(Node* node, Node* prev) {
	if(node->next != NULL) {
		reverseLinkedList(node->next, node);
  }

	//tail iterates this code first, head iterates last
	node->next = prev;
}

void printLinkedList(Node* node) {
	cout << node->value << " ";
	if(node->next != NULL) {
		printLinkedList(node->next);
  }
}

int main(int argv, char** argc) {
	Node* head = new Node(0);
	Node* tail = initializeLinkedList(head);

	printLinkedList(head);
	cout << endl;

	reverseLinkedList(head, NULL);
	printLinkedList(tail);
	cout << endl;
}
