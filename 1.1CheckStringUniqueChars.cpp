//Implement an algorithm to determine if a string has all unique characters What if you cannot use additional data structures?

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string getUserInput() {
	string str;
	cout << "Input string: ";
	cin >> str;
	return str;
}

//runs in O(n) time, using hashtable
bool checkForUniqueChars(string str) {
	unordered_map<char, bool> readChars;

	for(int i = 0; i < str.length(); i++) {
		if(readChars.find(str[i]) != readChars.end()) //if char already read, then false
			return false;
		else
			readChars.insert(pair<char, bool>(str[i], true));
	}

	//all elements traversed, no duplicates
	return true;
}

//runs in O(n^2) time, no data structures
bool checkForUniqueCharsNoDataStructs(string str) {
	for(int i = 0; i < str.length(); i++) {
		for(int j = i+1; j < str.length(); j++) {
			if(str[i] == str[j])
				return false;
		}
	}
	return true;
}

int main(int argv, char** argc) {
	string str = getUserInput();

//	if(checkForUniqueChars(str))
	if(checkForUniqueCharsNoDataStructs(str))
		cout << str << " has unique characters." << endl;
	else
		cout << str << " doesn't have unique characters." << endl;
}
