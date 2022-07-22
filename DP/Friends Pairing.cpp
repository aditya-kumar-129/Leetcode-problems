// Question link :- https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/friends-pairing-official/ojquestion
// Youtube video :- https://www.youtube.com/watch?v=SHDu0Ufjyk8

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int dp[n + 1];
  for (int i = 0; i <= n; i++) {
    if (i <= 2)
      dp[i] = i;
    else
      dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
  }
  cout << dp[n];
}