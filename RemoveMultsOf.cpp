#include <iostream>

using namespace std;

int removeMultsOf(int arr[], int n) {
	bool shouldSwap = false;
	int openIndex = -1;

	for(int i = 0; i < 10; i++) {
		if(arr[i] % n == 0) {
			if(!shouldSwap) {
				openIndex = i;
				shouldSwap = true;
			} else {
				continue;
			}
		}
		else if(shouldSwap) {
			swap(arr[openIndex],arr[i]);
			openIndex++;
		}
	}
	
	return openIndex;
}

int main(int argv, char** argc) {
	int arr[10] = {0,1,7,2,14,3,21,4,28,5};
	int n = 7;
	
	for(int i = 0; i < 10; i++)
		cout << arr[i] << " ";

	cout << endl << endl;

	int newSize = removeMultsOf(arr,n);

	for(int i = 0; i < newSize; i++)
		cout << arr[i] << " ";
}
