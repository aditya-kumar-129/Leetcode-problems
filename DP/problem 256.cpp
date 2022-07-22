// Question link :- https://leetcode.ca/all/256.html
// Youtube video :- https://www.youtube.com/watch?v=kh48JLieeW8

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<vector<int> > costs(n, vector<int>(3, 0));
  for (int i = 0;i < costs.size();i++)
    for (int j = 0;j < costs[0].size();j++)
      cin >> costs[i][j];

  vector<vector<int> > dp(n, vector<int>(3, 0));
  dp[0][0] = costs[0][0];
  dp[0][1] = costs[0][1];
  dp[0][2] = costs[0][2];

  for (int i = 1; i < costs.size(); i++) {
    dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0];
    dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1];
    dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i][2];
  }
  cout << min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
  return 0;
}