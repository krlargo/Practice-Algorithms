#include <iostream>
#include <cmath>

using namespace std;

// arr = [5] // no carryover
// arr = [4,5] //
// arr = [1,9] // is carryover
// arr = [9] // carryover && add digit
// arr = [9,9]

int addOne(int* arr, int size) {
  int result = 0;
  bool addedOne = false;
  
  for(int i = size-1; i >= 0; i--) {
    int power = size-i-1;
    int currentValue = arr[i];

    if(!addedOne) {
      if(currentValue != 9) {
        result += (currentValue + 1)*pow(10,power);
        addedOne = true;
      }
    } else {
      result += currentValue*pow(10,power);
    }
  }

  if(!addedOne) result += pow(10,size);

  return result;
}

int main() {
  while(true) {
  	int size;
  	cout << "What's the size of your array?" << endl;
  	cin >> size;
  	size = min(size,9);

  	int arr[size];

  	cout << "Enter " << size << " digits:" << endl;
  	for(int i = 0; i < size; i++) {
    	int input;
    	cin >> input;
    	
			if(input >= 0 && input <= 9) {
     		arr[i] = input;
    	} else {
      	cout << "Please enter a single-digit integer within range [0,9]" << endl;
      	i--;
   	  }
    }
  cout << "Adding one would equal " << addOne(arr, size) << endl;
  }
}

