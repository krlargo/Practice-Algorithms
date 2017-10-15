#include <iostream>

using namespace std;

void printArray(int arr[], int n) {
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void merge(int* a, int low, int mid, int high) {
	int i = low, j = mid+1, k = 0;
	int b[high-low+1];

	while(i <= mid && j <= high)
		b[k++] = (a[i] < a[j]) ? a[i++] : a[j++];
	while(i <= mid)
		b[k++] = a[i++];
	while(j <= high)
		b[k++] = a[j++];

	for(i = 0, j = low; i < k; i++, j++)
		a[j] = b[i];
}

void mergesort(int* a, int low, int high) {
	if(low >= high)
		return;

	int mid = (high + low)/2;
	mergesort(a,low,mid);
	mergesort(a,mid+1,high);
	merge(a,low,mid,high);
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
