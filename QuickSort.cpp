#include <iostream>

using namespace std;

void printArray(int arr[], int n) {
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void quicksort(int arr[], int left, int right) {
	if(left >= right)
		return;

	int i = left, j = right;
	int pivot = arr[(left+right)/2];

	while(i <= j) {
		while(arr[i] < pivot) i++;
		while(arr[j] > pivot) j--;

		if(i <= j) {
			swap(arr[i],arr[j]);
			i++;
			j++;
		}
	}

	quicksort(arr,left,j);
	quicksort(arr,i,right);
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

	quicksort(arr,0,n);
	printArray(arr,n);
}
