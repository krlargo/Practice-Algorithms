#include <iostream>
#include <vector>

using namespace std;

void recursivePowerset(vector<vector<int> > set) {
	return;
}
//{} {0} {1} {2} {0,1} {0,2} {1,2} {0,1,2}
vector<int> findPowerset(vector<int> set) {
	vector<vector<int> > powerset;
	vector<int> emptyset;

	powerset.push_back(emptyset);

	vector<int>::iterator it;
	vector<int>::iterator it2;
	
	for(it = set.begin(); it != set.end(); ++it) {	
		vector<int> subset;

		for(it2 = it; it2 != set.end(); ++it2) {
			subset.push_back(*it);
		}
	}
}

void printVector(vector<vector<int> > powerset) {

	vector<vector<int> >::iterator vIt;	//vector iterator
  vector<int>::iterator it;	//integer iterator

	cout << "{";

	for(vIt = powerset.begin(); vIt != powerset.end(); ++vIt) {
		vector<int> currentSet = *vIt;

		if(vIt != powerset.begin())		
			cout << ",";

		cout << "{";
		for(it = currentSet.begin(); it != currentSet.end(); ++it) {
			if(it != currentSet.begin())
				cout << ",";
			cout << *it;
		}
		cout << "}";
	}
	cout << "}" << endl;
}

int main(int argc, char** argv) {
	//hardcoded input
	vector<int> set = {0,1,2};

	recursivePowerset(set, 3);

/*	vector<vector<int> > test;
	vector<int> t1;
	vector<int> t2;
	vector<int> t3;

	t1.push_back(1);
	t1.push_back(2);
	t1.push_back(3);

	t2.push_back(4);
	t2.push_back(5);
	t2.push_back(6);

	t3.push_back(7);
	t3.push_back(8);
	t3.push_back(9);	

	test.push_back(t1);
	test.push_back(t2);
	test.push_back(t3);

	printVector(test);
*/
	return 0;
}
