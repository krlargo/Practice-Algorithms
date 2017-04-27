#include <iostream>

using namespace std;

void printArray(int arr[], int n) {
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void insertionSort(int arr[], int n) {
	for(int i = 0; i < n; i++) {
		for(int j = i; j > 0; j--) {
			if(arr[j] < arr[j-1])
				swap(arr[j], arr[j-1]);
		}
	}
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

	insertionSort(arr,n);
	printArray(arr,n);
}
