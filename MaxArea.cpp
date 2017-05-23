#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int> & height) {
	int currentMax = 0;
	int i = 0, j = height.size()-1;

	while(i < j) {
		int h = min(height[i],height[j]);
		int b = j - i;
		currentMax = max(currentMax,h*b);

		while(h >= height[i] && i < j) i++;
		while(h >= height[j] && i < j) j--;
	}

	return currentMax;
}

int main(int argv, char** argc) {
	vector<int> v;
	v.push_back(4);
	v.push_back(8 );
	v.push_back(4);

	cout << maxArea(v) << endl;
}
