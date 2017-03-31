#include <iostream>

using namespace std;

void getUserInput(string& str1, string& str2) {
	cout << "Enter first string: ";
	cin >> str1;
	cout << "Enter second string: ";
	cin >> str2;
}

bool isSubstring(string str1, string str2) {
	return str1.find(str2) != string::npos;
}

bool checkIfStringsAreRotations(string str1, string str2) {
	str1 += str1;
	
	return isSubstring(str1,str2);
}

int main(int argv, char** argc) {
	string str1, str2;

	getUserInput(str1, str2);
	
	if(checkIfStringsAreRotations(str1,str2))
		cout << str1 << " is a rotation of " << str2 << endl;
	else 
		cout << str1 << " is NOT a rotation of " << str2 << endl;		
}
