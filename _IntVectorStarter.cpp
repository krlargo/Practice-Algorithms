#include <iostream>
#include <vector>
#include "math.h"

using namespace std;

void printVector(vector<int> arr) {
	for(int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
}

void printVectorVector(vector<vector<int> > arr) {
	cout << "{ ";
	for(int i = 0; i < arr.size(); i++) {
		cout << "{ ";
		printVector(arr[i]);
		cout << "}" << ((i < arr.size()-1) ? "\n" : "");
	}
	cout << " }" << endl;
}

int main(int argv, char** argc) {
	int n;
	cout << "How many elements in array?" << endl;
	cin >> n;
	
	int input;
	vector<int> arr;

	cout << "Enter " << n << " elements:" << endl;
	for(int i = 0; i < n; i++) {
		cin >> input;
		arr.push_back(input);
	}

	printVector(arr);
	cout << endl;

	// Call method here
}
