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
	int size = input.length(); //start at full length

	while(size > first) {

		cout << input.substr(last-size+1, size) << endl;
		cout << reverse.substr(first, size) << endl << endl;

		//if rhs input substr = lhs reverse substr
		if(input.substr(last-size+1, size) == reverse.substr(first, size)) {
			cout << "largest substr is " << reverse.substr(first, size) << endl;
			break;
    }
		size--;   
  }

  return input;
}

int main(int argv, char** argc) {
	string input, palindrome;
	getUserInput(input);
	palindrome = findShortestPalindrome(input);
}
