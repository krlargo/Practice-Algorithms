#include <iostream>
#include <vector>

using namespace std;

void recurse(string str, string newStr, int index, vector<string>& res) {
	if(index == str.length()) {
		res.push_back(newStr);
		return;
	}
	if(str[index] == '0' || str[index] == '1')
		recurse(str,newStr+str[index],index+1,res);
	else if(str[index] == '?') {
		recurse(str,newStr+'0',index+1,res);
		recurse(str,newStr+'1',index+1,res);
	}
}

vector<string> allStrCombos(string str) {
	vector<string> res;
	recurse(str,"",0,res);	
	return res;
}

int main(int argv, char** argc) {
	cout << "Enter input string:" << endl;
	string input;
	cin >> input;

	vector<string> strVec = allStrCombos(input);
	for(int i = 0; i < strVec.size(); i++)
		cout << strVec[i] << endl;	
}
