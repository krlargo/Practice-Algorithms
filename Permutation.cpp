#include <iostream>

using namespace std;

void printArray(int arr[], int n) {
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void permutation(int arr[], int i, int n) {
	if(i >= n) {
		printArray(arr,n);
		return;
	}

	for(int j = i; j < n; j++) {
		swap(arr[i], arr[j]);
		permutation(arr, i+1, n);
		swap(arr[i], arr[j]);
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

	permutation(arr,0,n);
}
