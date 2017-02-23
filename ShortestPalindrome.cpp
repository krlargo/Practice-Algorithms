#include <iostream>
#include <string>

using namespace std;

void getUserInput(string& input) {
	cout << "Enter string: ";
	cin >> input;
}

string reverseString(string input) {
	string reverse = "";
	for(int i = input.length(); i >= 0; --i) {
   	reverse += input[i];
  }
	return reverse;
}

string findShortestPalindrome(string input) {
	string reverse = reverseString(input);
	cout << "reversed: " << reverse << endl;
	return reverse;
}

int main(int argv, char** argc) {
	string input, palindrome;
	getUserInput(input);
	palindrome = findShortestPalindrome(input);
}
