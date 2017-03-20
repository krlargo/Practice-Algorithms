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

void splitLinkedList(Node* head, int value) {
	Node* current = head;
	Node* left = NULL;
	Node* rightHead = NULL;
	Node* right = NULL;

	while(current != NULL) {
		if(current->data < value) {
			if(left == NULL) {
				left = current;
			} else {
				left->next = current;
				left = left->next;
			}
		} else {
			if(right == NULL) {
				rightHead = current;
				right = current;
			} else {
				right->next = current;
				right = right->next;
			}
		}
		current = current->next;
	}
	
	left->next = rightHead;
}

void createLinkedList(Node* head, int count) {
	//for(int i = 1; i < count; i++) {
	//	head->appendNode(i);
	//}
	head->appendNode(0);
	head->appendNode(9);
	head->appendNode(1);
  head->appendNode(8);
  head->appendNode(2);
  head->appendNode(7);
  head->appendNode(3);
  head->appendNode(6);
  head->appendNode(4);
  head->appendNode(5);
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
	splitLinkedList(head, 4);
	printLinkedList(head);
}
