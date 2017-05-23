#include <iostream>

using namespace std;

/*
   t
 l 1

	if(t != 1) p++;
	if(t == 1) nothing;
	if(l != 1) p++;
	if(l == 1) nothing

	if((j == 0 || j = matrix[i].size()-1) && m[i] == 1) { //last col
		p++ for rightside
	}

	if((i == 0 || matrix.size()-1) && m[i] == 1) { //last row
		p++ for bottom
	}
*/

#include <pair>

enum dir {
	up,down,left,right
};

int findPerimeter(int** m, int numRows, int numCols) {
	int p = 0;
	bool started = false;
	pair<int,int> start;
	dir lastDirection = right;

	int i = 0, j = 0;

	for(i = 0; i < numRows; i++) {
		for(j = 0; j < numCols; j++) {
			if(m[i][j] == 1) {
				started = true;
				start = pair<int,int>(i,j);
				p += 2;
				break;
			}
		}
		if(started) break;
	}

	while(started) {
		switch(lastDirection) {
			case up: // check left
				break;
			case right: // check up
				if(i == 0) { // if at top
					p++;
					if(j == 0)
						p++; //upper left corner
					else if(j == numCols-1) {// if at right
						lastDirection = down;
						p++; //upper right corner	
					}
				}
				break;
			case down: // check right
				break;	
			case left: // check down
				break;
		}
	}

	return p;	
}

int main(int argv, char** argc) {
	int matrix[4][4];
	matrix[0] = {0,1,1,0};
	matrix[1] = {1,1,0,0};
	matrix[2] = {0,1,1,0};
	matrix[3] = {0,0,0,0};

	cout << "Perimeter: " << findPerimeter(matrix,4,4) << endl;
}
