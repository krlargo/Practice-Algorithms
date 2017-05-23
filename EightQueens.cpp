#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<int> arr, int newCol) {
	for(int row = 0; row < arr.size(); row++) {
		// horizontal
		if(arr[row] == newCol) return false;

		// diagonal up
		int newRow = arr.size();
		if(abs(row - newRow) == abs(newCol - arr[row]))
			return false;
	}
	return true;
}

void recursive8Queens(vector<int>& arr) {
	if(arr.size() == 8)
		return;
	
	for(int i = 0; i < 8; i++) {
		if(!isValid(arr,i))
			continue;
		arr.push_back(i);
		recursive8Queens(arr);
		if(arr.size() == 8)
			return;
		arr.pop_back();
	}
}

int main(int argv, char** argc) {
	vector<int> arr;

	recursive8Queens(arr);

	for(int i = 0; i < arr.size(); i++) {
		for(int j = 0; j < arr[i]; j++) cout << "  ";
		cout << arr[i] << endl;
	}
}
