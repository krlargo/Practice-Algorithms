#include <iostream>

using namespace std;

struct Node {
	Node* next;
	int value;

	Node(int value) {
		this->value = value;
	}
};

Node* createLinkedList(int arr[], int size) {
	Node* head;
	Node* current;

	for(int i = 0; i < size; i++) {
		if(i == 0) {
			head = new Node(arr[i]);
			current = head;
			continue;
		}

		current->next = new Node(arr[i]);
		current = current->next;
	}

	return head;
}

void printLinkedList(Node* head) {
	Node* current = head;
	
	while(current != NULL) {
		cout << current->value << " ";
		current = current->next;
	}

	cout << endl;
}

Node* splitLinkedListAroundX(Node* head, int x) {
	Node* current = head;

	Node* left = NULL;
	Node* right = NULL;
	Node* leftHead = NULL;
	Node* rightHead = NULL;

	while(current) {
		if(current->value < x) {
			if(!left) {
				leftHead = current;
				left = current;
			} else {
				left->next = current;
				left = left->next;
			}
		} else {
			if(!right) {
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
	right->next = NULL;

	return leftHead;	
}

int main(int argv, char** argc) {
	int array[10] = {1,3,5,7,9,8,6,4,2,0};
	Node* head = createLinkedList(array, 10);

	printLinkedList(head);

	int x = 5;
  Node* newHead = splitLinkedListAroundX(head, x);

	printLinkedList(head);	
}
