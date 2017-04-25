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

int main(int argv, char** argc) {
	int array[10] = {1,3,5,7,9,8,6,4,2,0};
	Node* head = createLinkedList(array, 10);
	printLinkedList(head);	
}
