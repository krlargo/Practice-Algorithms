#include <iostream>
#include <vector>
#include "math.h"

using namespace std;

vector<int> getUserInput() {
	int size;
	cout << "Number of elements in array: ";
	cin >> size;

	vector<int> arr;
	cout << "Enter " << size << " elements." << endl;
	for(int i = 0; i < size; i++) {
		int input;
		cin >> input;
		arr.push_back(input);
	}

	return arr;
}

void printPowerset(vector<int> arr) {
	int powersetSize = pow(2, arr.size());
	cout << "{";

	for(int i = 0; i < powersetSize; i++) {
		cout << "{ ";

		// Increment through bits
		for(int j = 0; j < arr.size(); j++) {
			if(i & (1 << j))
				cout << arr[j] << " ";
		}
		cout << "}" << endl;
	}
	cout << "}";
}

int main(int argv, char** argc) {
	vector<int> arr = getUserInput();
	printPowerset(arr);
}

