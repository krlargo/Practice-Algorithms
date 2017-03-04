// Source -> Encrypted
// 1010 -> 1211 (1 + 0) (1 + 0 + 1) (0 + 1 + 0) (1 + 0)
//
// 1010
// |/
// 1... (1+0)

// 1010
// \|/
// .2.. (1+0+1)

// 1010
//  \|/
// ..1. (0+1+0)

// 1010
//   \|
// ...1 (1+0)

// Result: 1211

// Write function to go from encrypted to source
// Source numbers are always 1 or 0

#include <iostream>

using namespace std;
/*
	0000 -> 0000
	0001 -> 0011
	0010 -> 0111
	0011 -> 0122
	0100 -> 1110
	0101 -> 1121
	0110 -> 1221
	0111 -> 1232
	1000 -> 1100
	1001 -> 1111
	1010 -> 1211
	1011 -> 1222
	1100 -> 2210
	1101 -> 2221
	1110 -> 2321
	1111 -> 2332
*/

bool decrypt(int encrypt[], int source[],  int i, int size) {
	if(i >= size) //finished
		return true;

	//if 0 => 000
	if(encrypt[i] == 0) {
		//if first digit
		if(i-1 < 0) {
			source[i++] = 0;
			if(decrypt(encrypt,source,i,size))
				return true;
			else {
				source[i-1] = 1;
				return decrypt(encrypt,source,i,size);
			}
		}

		//other digits
		else {
			//prev digit must be 0
			if(source[i-1] != 0)
				return false;
			
			//try 0
			source[i++] = 0;
			if(decrypt(encrypt,source,i,size))
				return true;
			else {
				//try 1
				source[i-1] = 1;
				return decrypt(encrypt,source,i,size);
			}
		}
	}

	//if 1 => 001,010,100
	if(encrypt[i] == 1) {
		//if first digit
		if(i-1 < 0) {
			source[i++] = 0;
			if(decrypt(encrypt,source,i,size))
				return true;
			else {
				source[i-1] = 1;
				return decrypt(encrypt,source,i,size);
			}
		}

		//other digits
		else {
			//if prev digit 1 => 100
			if(source[i-1] == 1) {
				source[i++] = 0;
				if(decrypt(encrypt,source,i,size))
					return true;
				else {
					source[i-1] = 1;
					return decrypt(encrypt,source,i,size);
				}
			}

			//else; prev digit 0 => 010,001
			if(source[i-1] == 0) {
				source[i-1] = 1
			}
		}
	}

	//if 2 => 011,101,110 
	else if(encrypt[i] == 2) {
		//check if prev input is 0
	}

	//if 3 => 111
	else if(encrypt[i] == 3) {
		//check if prev input is 1
	}
	return true;
}

int main(int argv, char** argc) {
  //int source[] = {1,0,1,0};
	int source[4];
	int encrypt[] = {1,0,0,1};

	decrypt(encrypt, source, 0, 4);

	for(int i = 0; i < 4; i++) {
		cout << source[i] << " ";
	}
	cout << endl;
}

