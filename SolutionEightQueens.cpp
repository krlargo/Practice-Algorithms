#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<int> arr, int i) {
	for(int j = 0; j < arr.size(); j++) {
		if(arr[j] == i)
			return false;
		
		int dist = abs(i - arr[j]);
		if(arr[j]+dist == i && j+dist == arr.size())
			return false;
		if(arr[j]-dist == i && j+dist == arr.size())
			return false;
	} 

	return true;
}

bool recursive8Queens(vector<int>& arr) {
	if(arr.size() == 8)
		return true;

	for(int i = 0; i < 8; i++) {
		if(!isValid(arr,i))
			continue;
		else
			arr.push_back(i);		

		if(recursive8Queens(arr))
			return true;
		
		arr.pop_back();
	}

	return false;
}

int main(int argv, char** argc) {
	vector<int> arr;

	recursive8Queens(arr);

	for(int i = 0; i < arr.size(); i++) {
		for(int j = 0; j < arr[i]; j++) cout << "  ";
		cout << arr[i] << endl;
	}
}
