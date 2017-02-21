//"Find the most frequent integer in an array"

#include <iostream>
#include <unordered_map>
#include <utility> //pair
#include <vector>

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
	vector<int> modeVector;
	int length;
	int modeCount = 0;

	//prompt user input	
  int* arr = getUserInput(length);

	//for each element in array
	for(int i = 0; i < length; i++) {
    //if element isn't in hashtable, then add it
		if(hashtable.find(arr[i]) == hashtable.end()) {
			hashtable.insert(pair<int,int>(arr[i],1));
    } else {
			//otherwise increment its count
			unordered_map<int, int>::iterator it = hashtable.find(arr[i]);
			it->second += 1;

			//if greater count, assign new mode
			if(it->second > modeCount) {
        //mode = it->first;

				//empty mode vector
				modeVector.clear();
				modeVector.push_back(it->first);

				modeCount = it->second;
      }
			//if equal count, append tie
			else if(it->second == modeCount) {
				modeVector.push_back(it->first);
			}
	  }
  }

	//print out results
	if(modeVector.size() == 0) {
		cout << "No mode; all elements have same frequency." << endl;
		return 0;
	} else if(modeVector.size() == 1) {
		cout << "Mode: " << *modeVector.begin() << endl;
	} else {
		cout << "Modes: ";
		vector<int>::iterator i;
		for(i = modeVector.begin(); i != modeVector.end(); ++i) {
      cout << *i << " ";
    }
		cout << endl;
  }
  cout << "Number of recurrences: " << modeCount << endl;	
}
