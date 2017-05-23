#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool recursiveKT(vector<pair<int,int> >& res, int checked[][8]);

vector<pair<int,int> > knightsTour() {
	vector<pair<int,int> > res;
	int checked[8][8];
	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++)
			checked[i][j] = 0;
	res.push_back(pair<int,int>(0,0));
	recursiveKT(res,checked);
	return res;
}

pair<int,int> nextLocation(pair<int,int> pos, int& index) {
	switch(index) {
		case 0:
			if(pos.first+2 < 8 && pos.second+1 < 8)
				return pair<int,int>(pos.first+2,pos.second+1);
		case 1:
			index = 1;
			if(pos.first+2 < 8 && pos.second-1 >= 0)
				return pair<int,int>(pos.first+2,pos.second-1);
		case 2:
			index = 2;
			if(pos.first+1 < 8 && pos.second+2 < 8)
				return pair<int,int>(pos.first+1,pos.second+2);
		case 3:
			index = 3;
			if(pos.first+1 < 8 && pos.second-2 >= 0)
				return pair<int,int>(pos.first+1,pos.second-2);
		case 4:
			index = 4;
			if(pos.first-1 >= 0 && pos.second+2 < 8)
				return pair<int,int>(pos.first-1,pos.second+2);
		case 5:
			index = 5;
			if(pos.first-1 >= 0 && pos.second-2 >= 0)
				return pair<int,int>(pos.first-1,pos.second-2);
		case 6:
			index = 6;
			if(pos.first-2 >= 0 && pos.second+1 < 8)
				return pair<int,int>(pos.first-2,pos.second+1);
		case 7:
			index = 7;
			if(pos.first-2 >= 0 && pos.second-1 >= 0)
				return pair<int,int>(pos.first-2,pos.second-1);
		default:
			return pair<int,int>(-1,-1);
	}
}

bool recursiveKT(vector<pair<int,int> >& res, int checked[][8]) {
	if(res.size() == 64)
		return true;
	pair<int,int> pos = res.back();
	for(int i = 0; i < 8; i++) {
		pair<int,int> next = nextLocation(pos,i);
		if(pair<int,int>(-1,-1) == next)
			continue;
		res.push_back(next);
		checked[next.first][next.second] = 1; //mark
		if(recursiveKT(res,checked))
			return true;
		res.pop_back();
		checked[next.first][next.second] = 0;
	}
	return false;
}

int main(int argv, char** argc) {
	vector<pair<int,int> > answer = knightsTour();

	cout << "{" << endl;
	for(int i = 0; i < 64; i++) {
		cout << "{" << answer[i].first << "," << answer[i].second << "}" << endl;	
	}
	cout << "}" << endl;
}
