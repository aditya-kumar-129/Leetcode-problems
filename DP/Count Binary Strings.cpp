// Question link :- https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/count-binary-strings-official/ojquestion
// Youtube video :- https://www.youtube.com/watch?v=nqrXHJWMeBc

#include <bits/stdc++.h>
using namespace std;

// Optimised Approach
int main() {
  int n;
  cin >> n;

  int dp0 = 1;
  int dp1 = 1;

  for (int i = 2;i <= n;i++) {
    int temp = dp0 + dp1;
    dp0 = dp1;
    dp1 = temp;
  }
  cout << dp0 + dp1;
}

// BruteForce Approach
int main() {
  int n;
  cin >> n;

  vector<int> dp0(n + 1, 0);
  vector<int> dp1(n + 1, 0);

  dp0[1] = 1;
  dp1[1] = 1;

  for (int i = 2;i <= n;i++) {
    dp1[i] = dp0[i - 1] + dp1[i - 1];
    dp0[i] = dp1[i - 1];
  }
  cout << dp0[n] + dp1[n];
}