#include <iostream>

using namespace std;

void printArray(int arr[], int n) {
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void merge(int*,int,int,int);

void mergesort(int* a, int low, int high) {
	int mid = (high+low)/2;
	if(low < high) {
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}

void merge(int* a, int low, int mid, int high) {
	int i = low, j = mid+1, k = low;
	int b[high];

	while(i <= mid && j <= high)
		b[k++] = (a[i] < a[j]) ? a[i++] : a[j++];
	
	while(i <= mid)
		b[k++] = a[i++];

	while(j <= high)
		b[k++] = a[j++];

	for(i = low; i < k; i++)
		a[i] = b[i];
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
