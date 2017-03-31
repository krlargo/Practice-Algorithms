#include <iostream>
#include <vector>

using namespace std;

void printMatrix(int matrix[][5], int numRow, int numCol) {
	for(int i = 0; i < numRow; i++) {
		for(int j = 0; j < numCol; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void alterRowsAndCols(int matrix[][5], int numRow, int numCol) {
	vector<int> altRows;
	vector<int> altCols;

	for(int i = 0; i < numRow; i++) {
		for(int j = 0; j < numCol; j++) {
			if(matrix[i][j] == 0) {
 				altRows.push_back(i);
				altCols.push_back(j);	
			}
		}
	}

	for(int i = 0; i < numRow; i++) {
		for(int j = 0; j < altCols.size(); j++) {
			matrix[i][altCols[j]] = 0;	
		}
	}

	for(int j = 0; j < numCol; j++) {
		for(int i = 0; i < altRows.size(); i++) {
			matrix[altRows[i]][j] = 0;
		}
	}

	cout << endl << "Replaced Rows & Columns: " << endl;
	printMatrix(matrix,numRow,numCol);
}

int main(int argv, char** argc) {
	int matrix[4][5] = {{0,1,1,1,1},{2,2,2,2,2},{3,3,3,0,3},{4,4,4,4,4}};
	cout << "Original Matrix: " << endl;
	printMatrix(matrix,4,5);
	alterRowsAndCols(matrix,4,5);
}
