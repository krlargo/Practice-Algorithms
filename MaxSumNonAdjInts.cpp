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

void recurse(vector<int> arr, int& maxSum, int currentSum, int index) {
	if(index >= arr.size()) 
		return;
		
	maxSum = max(maxSum,currentSum);
 
	for(int i = index+2; i < arr.size(); i++) {
		recurse(arr,maxSum,currentSum+arr[i],i);
	}
}
 
int maxNonAdjacentSum(vector<int> arr) {
	int maxSum = 0;
	
	recurse(arr,maxSum,arr[0],0);
	recurse(arr,maxSum,arr[1],1);
 
	return maxSum;
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
	cout << "Max sum is: " << maxNonAdjacentSum(arr) << endl;	
}
