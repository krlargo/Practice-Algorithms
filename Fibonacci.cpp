//Write Fibonacci sequence iteratively and recursively

#include <iostream>

using namespace std;

void iterativeFibonacci(int n) {
	int a = 0, b = 1, c;
	n -= 2; //a and b are already calculated
	int i = 0;

	cout << a << " " << b << " ";

	while(i < n) {
    c = a + b;
		cout << c << " ";
		a = b;
		b = c;
		i++;
  }

	cout << endl;
}

void recursiveFibonacci(int a, int b, int n) {

}

int main(int argv, char** argc) {
	int term;
	
	cout << "Show sequence up to which term?" << endl;
	cin >> term;

	iterativeFibonacci(term);
	//recursiveFibonacci();
}
