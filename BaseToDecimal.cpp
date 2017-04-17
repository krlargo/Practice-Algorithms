#include <iostream>
#include "math.h"

using namespace std;

int baseToDecimal(int nary, int base) {
	int decimal = 0;
	int index = 0;

	while(nary != 0) {
		int lsb = nary % 10;

		decimal += pow(base, index) * lsb;
		
		index++;
		nary /= 10; // Shift right one bit
	}

	return decimal;
}

int main(int argv, char** argc) {
	int base, nary;

	cout << "Enter base: ";
	cin >> base;

	cout << "Enter n-nary number: ";
	cin >> nary;

	cout << nary << " as a decimal is: " << baseToDecimal(nary, base) << endl;
}
