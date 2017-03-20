#include <iostream>
#include <string>

using namespace std;

void getUserInput(string &str1, string &str2) {
	cout << "Enter first string: ";
	cin >> str1;
	cout << "Enter second string: ";
	cin >> str2;
}

bool checkIfPermutations(string str1, string str2) {
	if(str1.length() != str2.length())
		return false;

	int charCount[256] = {0};

	for(int i = 0; i < str1.length(); i++) {
		int index = str1[i] - 'a';
		charCount[index]++;
	}

	for(int i = 0; i < str2.length(); i++) {
		int index = str2[i] - 'a';
		if(--charCount[index] < 0)
			return false;
	}
	
	return true;
}

int main(int argv, char** argc) {
	string str1, str2;

	getUserInput(str1, str2);

	if(checkIfPermutations(str1, str2))
		cout << str1 << " is a permutation of " << str2 << endl;
	else
		cout << str1 << " is not a permutation of " << str2 << endl;
}
