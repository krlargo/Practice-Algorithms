#include <iostream>

using namespace std;

void printArray(int arr[], int n) {
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int removeDivisibleBy7(int* arr, int size) {
	int index = 0, newSize = size;
	bool shouldSwap = false;
	for(int i = 0; i < size; i++) {
		if(arr[i] % 7 == 0) {
			if(!shouldSwap) {
				index = i;
				shouldSwap = true;
			}
			newSize--;
		} else if(shouldSwap) {
			swap(arr[i],arr[index]);
			index++;
		}
	}

	return newSize;
}

int main(int argv, char** argc) {
	int n;
	cout << "How many elements in array?" << endl;
	cin >> n;

	int arr[n];
	
	cout << "Enter " << n << " elements:" << endl;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	printArray(arr,n);

	int newSize = removeDivisibleBy7(arr,n);
	printArray(arr,newSize);	
}
