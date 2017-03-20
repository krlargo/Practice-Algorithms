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
		Node* current = this;

		while(current->next != NULL) {
			current = current->next; //increment
		}

		current->next = new Node(d);
	}
};

void createLinkedList(Node* head, int size) {
	Node* current = head;

	for(int i = 1; i < size; i++) {
		current->next = new Node(i);
		current = current->next;
	}
}

int findKthToLastElement(Node* current, int& k, int& answer) {
	if(current != NULL) {
		findKthToLastElement(current->next, k, answer);	
		
		cout << "k: " << k << "; " << current->data << endl;

		if(k == 0) //only update answer at kth element
			answer = current->data;
		k--;
	}
	return answer;
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

	int k = 3;
	int answer = 0;

	cout << findKthToLastElement(head, k, answer) << endl;				
}
