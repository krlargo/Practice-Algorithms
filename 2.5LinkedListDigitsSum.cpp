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

Node* sumLinkedLists(Node* n1, Node* n2) {
	Node* n3 = NULL;
	Node* answer;
	int carryOver = 0;
	int v1 = 0, v2 = 0, value = 0;

	while(n1 || n2) {
		v1 = (n1) ? n1->value : 0;
		v2 = (n2) ? n2->value : 0;

		int value = (v1 + v2 + carryOver) % 10;

		if(v1 + v2 >= 10)
			carryOver = 1;
		else
			carryOver = 0;

		if(!n3) {
			n3 = new Node(value);
			answer = n3;
		} else {

			n3->next = new Node(value);
			n3 = n3->next;
		}

		//increment
		if(n1) n1 = n1->next;
		if(n2) n2 = n2->next;
	}

	return answer;
}

int main(int argv, char** argc) {
	int num1[3] = {8,9,1}; //198
	int num2[3] = {4,3,2}; //234
	Node* head1 = createLinkedList(num1, 3);
	Node* head2 = createLinkedList(num2, 3);

	Node* answer = sumLinkedLists(head1, head2);
	
	printLinkedList(answer);	
}
