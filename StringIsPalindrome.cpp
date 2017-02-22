/*
 * Check if string is a palindrome but off by one insert/delete
 */

#include <iostream>
#include <string>

using namespace std;

void getUserInput(string &input) {
	cout << "Enter string: ";
	cin >> input;
}

bool checkIfPalindrome(string input, int i, int j) {
	if(i >= j) {
    return true; //we're done, indices past each other
  }

	if(input[i] != input[j]) {
		return false;
  } else {
		return checkIfPalindrome(input, i+1, j-1);
  }
}

bool checkIfAlmostPalindrome(string input, int i, int j) {
	if(i >= j) {
		cout << input << " is a palindrome." << endl;
		return true; //we're done, indices past each other
	}

  if(input[i] != input[j]) {
		if(checkIfPalindrome(input, i, j-1) ||
       checkIfPalindrome(input, i+1, j)) {
			cout << input << " is almost a palindrome (off by one character)." << endl;
			return true;
    } else {
			cout << input << " is not a palindrome." << endl;
			return false;
		}
  } else {
		return checkIfAlmostPalindrome(input, i+1, j-1);
	}
}

int main(int argv, char** argc) {
	string input;

	getUserInput(input);
	checkIfAlmostPalindrome(input,0,input.length()-1);
}
