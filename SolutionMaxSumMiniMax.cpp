#include <iostream>
#include <vector>

using namespace std;

int getMaxSum(vector<int> pots, int l, int r, bool myTurn) {
  if(l == r) return (myTurn ? pots[l] : 0);

  if(myTurn) 
    return max(pots[l]+getMaxSum(pots,l+1,r,!myTurn), pots[r]+getMaxSum(pots,l,r-1,!myTurn));
  else
    return min(getMaxSum(pots,l+1,r,!myTurn), getMaxSum(pots,l,r-1,!myTurn));
}

int main() {
  bool myTurn = true;

  vector<int> pots;
  pots.push_back(1);
  pots.push_back(3);
  pots.push_back(5);

  cout << "Your max sum if you " << (myTurn ? "" : "don't ") << "go first is: " << getMaxSum(pots, 0, pots.size()-1, myTurn) << endl;
}
