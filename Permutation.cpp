#include <iostream>

using namespace std;

void printArray(char arr[], int n) {
	for(int i = 0; i < n; i++) 
		cout << arr[i] << " ";
	cout << endl;
}

void permutation(char arr[], int j, int n) {
	if(j == n-1)
		printArray(arr,n);
	else {
		for(int i = j; i < n; i++) {
			swap(arr[i],arr[j]);
			permutation(arr,j+1,n);
			swap(arr[i],arr[j]);
		}
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

	permutation(arr,0,n);
}

