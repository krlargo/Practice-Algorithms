#include <iostream>

using namespace std;

string compress(string str) {
	char prevChar = str[0];
	int count = 1;
	string newStr = "";

	for(int i = 1; i < str.length(); i++) {
		if(str[i] == prevChar) {
			count++;
			continue;
		} else { //new char encountered
			newStr += prevChar;
			newStr += count + '0';

			//reset
			prevChar = str[i];
			count = 1;
		}
	}

	newStr += prevChar;
	newStr += count + '0';

	return (str.length() < newStr.length()) ? str : newStr;
}

int main(int argv, char** argc) {
	string input;

	while(true) {
		cout << "Enter string: ";
		cin >> input;
		cout << compress(input) << endl;
	}	
}
