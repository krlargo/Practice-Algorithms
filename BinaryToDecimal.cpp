#include <iostream>
#include "math.h"

using namespace std;

int binaryToDecimal(int binary) {
	int decimal = 0;
	int pos = 0; // LSB
	while(binary > 0) {
		// LSB is 1
		if(binary % 10 == 1) {
			decimal += pow(pos,2);
//			binary -= 1;
		}
		binary /= 10; // Shift right
		pos++;
	}
	return decimal;
}

int main(int argv, char** argc) {
	cout << "Enter binary number: ";
	int binary;
	cin >> binary;

	cout << binaryToDecimal(binary) << endl;
}
