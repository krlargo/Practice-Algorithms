#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Node {
	Node* next;
	int value;

	Node(int value) {
		this->value = value;
	}
};

void addNode(Node*& tail, int value) {
	tail->next = new Node(value);
	tail = tail->next;
}

void removeDuplicateNodes(Node* head) {
	Node* current = head;
	Node* prev;

	unordered_map<int, bool> hashtable;

	//traverse entire linked list
	while(current) {
		if(hashtable.find(current->value) != hashtable.end()) //if in hashtable
			prev->next = current->next;
		else
			hashtable.insert(pair<int,bool>(current->value,true));

		prev = current;
		current = current->next;
	}	
}

void printLinkedList(Node* head) {
	Node* current = head;
	
	while(current) {
		cout << current->value << " ";
		current = current->next;
	}
	
	cout << endl;
}

int main(int argv, char** argc) {
	Node* head = new Node(0);
	Node* tail = head;
	
	addNode(tail, 1);
	addNode(tail, 2);
	addNode(tail, 3);
  addNode(tail, 3);
  addNode(tail, 4);
  addNode(tail, 5);
  addNode(tail, 1);
  addNode(tail, 6);
  addNode(tail, 7);
  addNode(tail, 8);
  addNode(tail, 9);

	printLinkedList(head);

	removeDuplicateNodes(head);

	printLinkedList(head);	
}
