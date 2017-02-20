#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char** argv) {

	stringstream ss;	
	string inputLine, token;
	char delim = ' ';

		inputLine = "The dog ate the cat";
		ss.str(inputLine);

		while(getline(ss, token, delim)) {
			cout << token;
		}

	return 0;
}
