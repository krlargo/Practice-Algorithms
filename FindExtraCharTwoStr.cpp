#include <iostream>

using namespace std;

char findExtraChar(string str1, string str2) {
	string goodStr = (str1.length() < str2.length()) ? str1 : str2;
	string badStr = (str1.length() < str2.length()) ? str2 : str1;
	
	int i = 0;
	for(i = 0; i < goodStr.length(); i++) {
		if(goodStr[i] != badStr[i])
			return badStr[i];
	}
	
	return badStr[i];
}

int main(int argv, char** argc) {
	cout << findExtraChar("abc", "aabc") << endl;
	cout << findExtraChar("abbc", "abc") << endl;
	cout << findExtraChar("abbcbcc", "abbcbc") << endl;
}
