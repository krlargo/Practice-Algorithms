#include <iostream>

using namespace std;

void printArray(int* arr, int size) {
  for(int i = 0; i < size; i++) {
    if(i == 0)
      cout << "{";
    else
      cout << ", ";
    cout << arr[i];
  }
  
  cout << "}" << endl << endl;
}

void insertionSort(int* arr, int size) {
}

int main(int argv, char* argc[]) {

  int size;
  printf("Number of elements in array: ");
  cin >> size;

  if(size <= 0) {
    cout << "Array is empty." << endl << endl;
    return 0;
  }

  int arr[size];

  for(int i = 0; i < size; i++)
    cin >> arr[i];

  printArray(arr, size);

  return 0;
}
