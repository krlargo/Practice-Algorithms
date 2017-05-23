#include <iostream>
#include <vector>

using namespace std;

int recursive(int arr[], vector<int>& v, int left, int right, bool myTurn) {
	if(left == right)
		return 0;

	int leftSide = recursive(arr,v,left+1,right,!myTurn)+arr[left];
	int rightSide = recursive(arr,v,left,right-1,!myTurn)+arr[right];
		
	if(myTurn)
		return (leftSide > rightSide) ? leftSide : rightSide;
	else
		return (leftSide < rightSide) ? leftSide : rightSide;
}

int main(int argv, char** argc) {
	cout << "Size of the array: " << endl;
	int n; cin >> n;
	int arr[n];
	cout << "Enter " << n << " elements: " << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	vector<int> v;
	cout << "Max Sum is: " << recursive(arr,v,0,n-1,true) << endl;

	cout << "{";
	for(int i = 0; i < v.size(); i++) {
		cout << v[i] << ((i != v.size()-1) ? "," : "");
	}
	cout << "}" << endl;
}
