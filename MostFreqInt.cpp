//"Find the most frequent integer in an array"

#include<iostream>

using namespace std;

int* getUserInput(int &length) {
	//read in length
	cout << "Array length: ";
	cin >> length;

	//create array
	int* arr = new int[length];

	//read in elements
	cout << "List " << length << " elements:" << endl;
	int index = 0;
	while(index < length) {
		cin >> arr[index++];
	}

	return arr;
}

void printArray(int* arr, int length) {
	for(int i = 0; i < length; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(int argc, char** argv) {
	int length;

	//prompt user input	
  int* arr = getUserInput(length);
	printArray(arr, length); 	
}
