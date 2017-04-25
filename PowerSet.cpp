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

vector<vector<int> > getPowerset(vector<int> arr) {
	int powerSetSize = pow(2,arr.size());
	vector<vector<int> > powerSet;

	for(int i = 0; i < powerSetSize; i++) {
		vector<int> subset;
		for(int j = 0; j < arr.size(); j++) {
			if(i & 1 << j)
				subset.push_back(arr[j]);		
		}
		powerSet.push_back(subset);
	}

	return powerSet;
}

void printPowerset(vector<vector<int> > powerset) {
	cout << "{ " << endl;
	for(int i = 0; i < powerset.size(); i++) {
		vector<int> subset = powerset[i];
		
		cout << "{ ";
		for(int j = 0; j < subset.size(); j++) {
			cout << subset[j] << " ";
		}
		cout << "}" << endl;
	}
	cout << "}" << endl;
}

int main(int argv, char** argc) {
	vector<int> arr = getUserInput();
	vector<vector<int> > powerset = getPowerset(arr);
	printPowerset(powerset);
}
