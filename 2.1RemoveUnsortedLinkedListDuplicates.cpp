#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
public:
	Node* next = NULL;
	int data;

	Node(int d) {
		data = d;
	}

	void appendNode(int d) {
		Node* next = new Node(d);
		Node* current = this;

		while(current->next != NULL) {
			current = current->next;
		}

		current->next = next;
	}
};

void printLinkedList(Node* head) {
	Node* current = head;

	while(current != NULL) {
		cout << current->data << " ";
		current = current->next; //increment
	}
	
	cout << endl;
}

void removeDuplicates(Node* head) {
	unordered_map<int,bool> hashtable;
	Node* current = head;
	Node* prev = NULL;

	while(current != NULL) {
		//if key isn't in hashtable, then add it
		if(hashtable.find(current->data) == hashtable.end()) {
			hashtable.insert(pair<int, bool>(current->data, true));
			prev = current;
		} else { //this will never be head since head can't be duplicate
			prev->next = current->next; //delete node
		}

		current = current->next;
	}
}

int main(int argv, char** argc) {
	//create node
	Node* head = new Node(0);
	head->appendNode(1);
	head->appendNode(2);
	head->appendNode(2);
	head->appendNode(3);
	head->appendNode(3);
	head->appendNode(3);
	head->appendNode(4);
	
	printLinkedList(head);
	removeDuplicates(head);
	printLinkedList(head);
}
