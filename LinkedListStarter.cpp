#include <iostream>

using namespace std;

struct Node {
	Node* next;
	int value;

	Node(int value) {
		this->value = value;
	}
};

Node* createLinkedList(int n) {
	Node* head = new Node(0);
	Node* current = head;

	for(int i = 1; i < n; i++) {
		current->next = new Node(i);
		current = current->next;
	}

	return head;
}

void printLinkedList(Node* head) {
	Node* current = head;

	while(current) {
		cout << current->value << " ";
		current = current->next;
	}
}

int main(int argv, char** argc) {
	Node* head = createLinkedList(10);
	printLinkedList(head);	
}
