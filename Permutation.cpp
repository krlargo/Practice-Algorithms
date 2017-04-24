#include <iostream>

using namespace std;

void printArray(char arr[], int n) {
	for(int i = 0; i < n; i++) 
		cout << arr[i] << " ";
	cout << endl;
}

void permute(char arr[], int i, int n) {
	if(i == n-1) // Last element
		printArray(arr, n);

	for(int j = i; j < n; j++) {
		swap(arr[i],arr[j]);
		permute(arr,i+1,n);
		swap(arr[i],arr[j]); // Swap back
	}
}

int main(int argv, char** argc) {
  cout << "How many elements in array?" << endl;
  int n;
  cin >> n;
  char arr[n];

  cout << "Enter " << n << " elements: " << endl;
  
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

	permute(arr,0,n);
}

