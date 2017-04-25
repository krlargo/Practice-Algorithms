#include <iostream>

using namespace std;

int findStartIndex(int arr[], int low, int high) {
	if(high == low)
		return low;

	if(high - low == 1) {
return (arr[low] > arr[low+1]) ? low+1 : low; 
}

	int med = (high-low)/2;

	if(low > med)
		return findStartIndex(arr,low,med);
	else if(med > high)
		return findStartIndex(arr,med,high);
	else
		return 0;
}

int binarySearch(int value, int arr[], int offset, int low, int high) {
	int med = ((high - low + offset) / 2) % (high - low + 1);

	if(value < arr[med])
		return binarySearch(value,arr,offset,low,med-1);
	else if(value > arr[med])
		return binarySearch(value,arr,offset,med+1,high);
	else
		return med;
}

int findElmRotatedSortedArr(int arr[], int elm) {
  // Find start index
  int offset = findStartIndex(arr,0,5);
  return binarySearch(elm,arr,offset,0,5);
}

int main(int argv, char** argc) {
	int arr[6] = {4,5,6,1,2,3};
	
	cout << "index: " << findElmRotatedSortedArr(arr, 5) << endl;	
}
