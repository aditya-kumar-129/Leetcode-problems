// Question link :- https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/tiling1-official/ojquestion
// Youtube video :- https://www.youtube.com/watch?v=dVT9JeUMMDE

#include <bits/stdc++.h>
using namespace std;

int countWays(int n)
{
  if (n == 0)
    return 1;
  if (n <= 2)
    return n;
  int dp[n + 1];
  dp[1] = 1;
  dp[2] = 2;
  for (int i = 3;i <= n;i++)
    dp[i] = dp[i - 1] + dp[i - 2];
  return dp[n];
}

int main()
{
  int n;
  cin >> n;
  cout << countWays(n);
  return 0;
}