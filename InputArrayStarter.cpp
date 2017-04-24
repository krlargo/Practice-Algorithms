#include <iostream>

using namespace std;

void printArray(char arr[], int n) {
	for(int i = 0; i < n; i++) 
		cout << arr[i] << " ";
	cout << endl;
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

	// Call method to work on array here
}

