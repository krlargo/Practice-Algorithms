#include <iostream>
#include "math.h"

using namespace std;

int decimalToBinary(int decimal) {
	int binary = 0;

	while(decimal > 0) {
		// Find largest base 2 number that is less than decimal
		int i = 0;

		while(pow(2,i++) <= decimal);
		i -= 2; // Move back one
			
		decimal -= pow(2,i);
		binary += pow(10,i); // Add bit
	}

	return binary;
}

int main(int argv, char** argc) {
	cout << "Enter decimal number: ";
	int decimal;
	cin >> decimal;

	cout << decimalToBinary(decimal) << endl;
}
