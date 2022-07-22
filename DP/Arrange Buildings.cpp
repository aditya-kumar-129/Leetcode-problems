// Question link :- https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/arrange-buildings-official/ojquestion
// Youtube video :- https://www.youtube.com/watch?v=0nF-BMYy7tc

#include <bits/stdc++.h>
using namespace std;

// Optimised Approach
int main() {
  long long int n;
  cin >> n;

  long long int dpBuilding = 1;
  long long int dpSpace = 1;

  for (long long int i = 2;i <= n;i++) {
    long long int temp = dpBuilding + dpSpace;
    dpBuilding = dpSpace;
    dpSpace = temp;
  }
  cout << (dpBuilding + dpSpace) * (dpBuilding + dpSpace);
}