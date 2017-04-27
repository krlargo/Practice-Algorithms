#include <iostream>

using namespace std;

void printArray(int arr[], int n) {
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void selectionSort(int* arr, int n) {
	for(int i = 0; i < n; i++) {
		int minIndex = i;

		for(int j = i; j < n; j++) {
			if(arr[j] < arr[minIndex])
				minIndex = j;
		}
	
		swap(arr[i],arr[minIndex]);
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

	selectionSort(arr,n);
	printArray(arr,n);
}
