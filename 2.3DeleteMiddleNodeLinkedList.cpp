#include <iostream>

using namespace std;

class Node {
public:
	int data;
	Node* next = NULL;

	Node(int d) {
		data = d;
	}

	void appendNode(int d) {
		Node* last = new Node(d);
		Node* current = this;

		while(current->next != NULL) {
			current = current->next; //increment
		}

		current->next = last;
	}
};

void deleteMiddleNode(Node* node) {
	Node* deletedNode = node;
	node->data = 	node->next->data;
	node->next = node->next->next;
	delete(deletedNode);
}

void createLinkedList(Node* head, int count) {
	for(int i = 1; i < count; i++) {
		head->appendNode(i);
	}
}

void printLinkedList(Node* head) {
	Node* current = head;

	while(current != NULL) {
		cout << current->data << " ";
		current = current->next;
	}

	cout << endl;
}

int main(int argv, char** argc) {
	Node* head = new Node(0);	
	createLinkedList(head, 10);
	printLinkedList(head);
	Node* nodeToDelete = head->next->next->next;
	deleteMiddleNode(nodeToDelete);
	printLinkedList(head);
}
