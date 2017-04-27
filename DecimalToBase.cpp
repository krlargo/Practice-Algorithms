#include <iostream>
#include "math.h"

using namespace std;

int decimalToBase(int decimal, int base) {
	int res = 0;
	int place = 0;
	
	while(decimal) {
		res += (decimal%base)*pow(10,place++);
		decimal /= base;
	}

	return res;
}

int main(int argv, char** argc) {
	int decimal, base;

	cout << "Enter decimal: ";
	cin >> decimal;

	cout << "Enter base: ";
	cin >> base;

	cout << "Decimal " << decimal << " as base-" << base << ": " << decimalToBase(decimal,base) << endl;
}
