/* Given two strings, check if one is a rotated version
   of the other.
*/

#include <iostream>
#include <string>

using namespace std;

void getUserInputs(string &str1, string &str2) {
	cout << "Enter first string: ";
	cin >> str1;
	cout << "Enter second string: ";
	cin >> str2;
}

int main(int argv, char** argc) {
	string str1, str2;

	getUserInputs(str1, str2);

	cout << "str1: " << str1 << ", str2: " << str2 << endl;
}
