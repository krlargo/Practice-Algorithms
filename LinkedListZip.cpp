#include <iostream>

using namespace std;

struct Node {
	Node* next;
	int value;

	Node(int value) {
		this->next = NULL;
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

#include <deque>
void printLinkedListZip(Node* n) {
	deque<Node*> nodeDeque;

	while(n) {
		nodeDeque.push_back(n);
		n = n->next;
	}
	bool front = true;
	while(!nodeDeque.empty()) {
		cout << ((front) ? nodeDeque.front()->value : nodeDeque.back()->value) << endl;
		(front) ? nodeDeque.pop_front() : nodeDeque.pop_back();
		front = (front) ? false : true;
	}

}

int main(int argv, char** argc) {
	int array[10] = {1,3,5,7,9,8,6,4,2,0};
	Node* head = createLinkedList(array, 10);
	printLinkedList(head);	
	printLinkedListZip(head);
}
