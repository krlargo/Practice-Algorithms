#include <iostream>
#include <vector>
#include <vector>
#include <vector>

using namespace std;

bool isWordSquare(vector<string> words) {

	for(int i = 0; i < words.size(); i++) {
		for(int j = 0; j < words[i].length(); j++) {
			if(words[i][j] != words[j][i])
				return false;
		}
	}
	return true;
}

int main(int argv, char** argc) {
	vector<string> words1;
	words1.push_back("BALL");
	words1.push_back("AREA");
	words1.push_back("LEAD");
	words1.push_back("LADY");

	if(isWordSquare(words1))
		cout << "Words1 is a wordsquare" << endl;
	else
		cout << "Words1 isn't a wordsquare" << endl;

	vector<string> words2;
	words2.push_back("THE");
	words2.push_back("HET");
	words2.push_back("EHE");

	if(isWordSquare(words2))
		cout << "Words2 is a wordsquare" << endl;
	else
		cout << "Words2 isn't a wordsquare" << endl;	
}
