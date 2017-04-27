#include <iostream>

using namespace std;

void printArray(int arr[], int n) {
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void bubbleSort(int *arr, int n) {
	bool swapped = true;

	while(swapped) {
		swapped = false;

		for(int j = 0; j < n; j++) {
		for(int i = 0; i < n-1; i++) {
			if(arr[i] > arr[i+1]) {
				swap(arr[i],arr[i+1]);
				swapped = true;
			}
		}
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

	bubbleSort(arr,n);
	printArray(arr,n);
}
