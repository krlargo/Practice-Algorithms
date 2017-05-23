#include <iostream>

using namespace std;

void printArray(int arr[], int n) {
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void merge(int* arr, int low, int mid, int high) {
	int i = low, j = mid+1, k = 0;
	int tempArr[high-low+1];

	while(i <= mid && j <= high)
		tempArr[k++] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
	while(i <= mid)
		tempArr[k++] = arr[i++];
	while(j <= high)
		tempArr[k++] = arr[j++];

	for(i = low, j = 0; j < k; i++,j++)
		arr[i] = tempArr[j];
}

void mergesort(int* arr, int low, int high) {
	if(low >= high)
		return;

	int mid = (low+high)/2;
	mergesort(arr,low,mid);
	mergesort(arr,mid+1,high);
	merge(arr,low,mid,high);
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
	mergesort(arr,0,n-1);
	printArray(arr,n);
}
