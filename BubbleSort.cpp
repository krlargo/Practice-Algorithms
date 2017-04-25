#include <iostream>

using namespace std;

void printArray(int arr[], int n) {
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void bubblesort(int arr[], int n) {
	bool swapped = true;
	int j = 0;

	while(swapped) {
		swapped = false;

		j++;
		for(int i = 0; i < n - j; i++) {
			if(arr[i] > arr[i+1]) {
				swap(arr[i], arr[i+1]);
				swapped = true;
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

	bubblesort(arr,n);
	printArray(arr,n);
}
