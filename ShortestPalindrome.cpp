#include <iostream>
#include <string>

using namespace std;

void getUserInput(string& input) {
	cout << "Enter string: ";
	cin >> input;
}

string reverseString(string input) {
	string reverse = "";
	for(int i = input.length()-1; i >= 0; i--) {
   	reverse += input[i];
  }
	return reverse;
}

//find largest substring on RHS of input
// and LHS of reverse
string findShortestPalindrome(string input) {
	string reverse = reverseString(input);

	int first = 0;
	int last = input.length()-1;
	int substrSize = input.length(); //start at full length

	while(substrSize > first) {

		cout << input.substr(last-substrSize+1, substrSize) << endl;
		cout << reverse.substr(first, substrSize) << endl << endl;

		//if rhs input substr = lhs reverse substr
		if(input.substr(last-substrSize+1, substrSize) == reverse.substr(first, substrSize)) {
			break;
    }
		substrSize--;   
  }

	input += reverse.substr(substrSize,last-substrSize+1);

  return input;
}

int main(int argv, char** argc) {
	string input, palindrome;

	getUserInput(input);
	palindrome = findShortestPalindrome(input);

	cout << "Shortest Palindrome: " << palindrome << endl;
}
