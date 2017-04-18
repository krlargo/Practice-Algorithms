#include <iostream>
#include <string>

using namespace std;

void swap(char& a, char& b) {
	char c = a;
	a = b;
	b = c;
}

void reverseStringInPlace(string str) {
	int first = 0; // Start pos
	int last = str.length() - 1; // Last pos

	while(first < last) {
		swap(str[first],str[last]);
		first++;
		last--;
	}
	
	cout << str << endl;
}

int main(int argv, char** argc) {
	cout << "Enter string to be reversed:";
	string str;
	cin >> str;

	reverseStringInPlace(str);
}
