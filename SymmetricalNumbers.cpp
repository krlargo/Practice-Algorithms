#include <iostream>
#include <vector>

using namespace std;

vector<int> getSymmetricNumbers(vector<int> arr) {
	bool symDigits[10] = {true, true, false, true, false, false, false, false, true, false};
	vector<int> answer;

	for(int i = 0; i < arr.size(); i++) {
		int num = arr[i];
		bool isSym = true;

		while(num > 0) {
			int digit = num%10;
			num /= 10; // shifts

			if(!symDigits[digit]) {
				isSym = false;
				break;
			}
		}

		if(isSym)
			answer.push_back(arr[i]);
	}

	return answer;
}

void printIntVector(vector<int> arr) {
	for(int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main(int argv, char** argc) {
	vector<int> arr1;
	arr1.push_back(0);
	arr1.push_back(1);
	arr1.push_back(2);
	arr1.push_back(3);
	arr1.push_back(4);
	arr1.push_back(5);
	arr1.push_back(6);
	arr1.push_back(7);
	arr1.push_back(8);
	arr1.push_back(9);

	vector<int> arr2;
	arr2.push_back(13);
	arr2.push_back(23);
	arr2.push_back(47);
	arr2.push_back(80);
	arr2.push_back(1380);

	printIntVector(arr1);
	printIntVector(getSymmetricNumbers(arr1));
	printIntVector(arr2);
	printIntVector(getSymmetricNumbers(arr2));

	return 0;	
}
