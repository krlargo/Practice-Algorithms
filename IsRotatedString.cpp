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

	//append str1 to itself; this will guarantee
	//that all possible rotations are substrings
	string concat = str1 + str1;

	//if npos, no match
	if(concat.find(str2, 0) == string::npos || str1.length() != str2.length()) {
		cout << "String 1 isn't a rotation of string 2" << endl;
  } else {
		cout << "String 1 is a rotation of string 2" << endl;
  }
}
