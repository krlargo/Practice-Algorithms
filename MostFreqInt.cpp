//"Find the most frequent integer in an array"

#include<iostream>
#include<unordered_map>
#include<utility> //pair

using namespace std;

int* getUserInput(int &length) {
	//read in length
	cout << "Array length: ";
	cin >> length;

	//create array
	int* arr = new int[length];

	//read in elements
	cout << "List " << length << " elements:" << endl;
	int index = 0;
	while(index < length) {
		cin >> arr[index++];
	}

	return arr;
}

void printArray(int* arr, int length) {
	for(int i = 0; i < length; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(int argc, char** argv) {
	unordered_map<int, int> hashtable;
	int length;
	int mode, modeCount = 0;

	//prompt user input	
  int* arr = getUserInput(length);
	printArray(arr, length); 	

	//for each element in array
	for(int i = 0; i < length; i++) {
    //if element isn't in hashtable, then add it
		if(hashtable.find(arr[i]) == hashtable.end()) {
			hashtable.insert(pair<int,int>(arr[i],1));
    } else {
			//otherwise increment its count
			unordered_map<int, int>::iterator it = hashtable.find(arr[i]);
			it->second += 1;

			if(it->second > modeCount) {
        mode = it->first;
				modeCount = it->second;
      }
	  }
  }

	cout << "Mode: " << mode << endl;
  cout << "Number of recurrences: " << modeCount << endl;	
}
