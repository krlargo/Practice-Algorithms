#include <iostream>
#include <vector>
#include "math.h"

using namespace std;

vector<char> getUserInput() {
	int count;
	vector<char> set;

	cout << "Number of elements in array:" << endl;
	cin >> count;

	cout << "Enter " << count << " elements:" << endl;

	while(count > 0) {
		char element;
		cin >> element;

		set.push_back(element);
		count--;
	}

	return set;
}

vector<vector<char> > getPowerSet(vector<char> set) {
	int powerSetSize = pow(2,set.size());

	vector<vector<char> > powerSet;

	//iterate through each combination of 0's and 1's
	for(int i = 0; i < powerSetSize; i++) {
		vector<char> subset;

		//iterate through each bit
		for(int j = 0; j < set.size(); j++) {
			//if bits match, push to subset
			if(i & (1 << j)) {
				subset.push_back(set[j]);
			}
		}

			powerSet.push_back(subset);
	}

	return powerSet;
}

void printPowerSet(vector<vector<char> > powerSet) {

	for(int i = 0; i < powerSet.size(); i++) {
		for(int j = 0; j < powerSet[i].size(); j++) {
			cout << powerSet[i][j] << " ";	
		}
		cout << endl;
	}
}

int main(int argv, char** argc) {

	vector<char> set = getUserInput();
	vector<vector<char> > powerSet = getPowerSet(set);
	printPowerSet(powerSet);

	return 0;
}
