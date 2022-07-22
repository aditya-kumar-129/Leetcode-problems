// Question link :- https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/goldmine-official/ojquestion
// Youtube video :- https://www.youtube.com/watch?v=hs0lilfJ7C0

#include <bits/stdc++.h>
using namespace std;

int collectGold(int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp) {
  // We are filling the table in column wise direction. Hence the loop is in the reverse order as compared to the normal methods!!!
  for (int j = m - 1;j >= 0;j--) {
    for (int i = n - 1;i >= 0;i--) {
      // Last column
      if (j == m - 1)
        dp[i][j] = grid[i][j];
      // first row
      else if (i == 0)
        dp[i][j] = max(dp[i][j + 1], dp[i + 1][j + 1]) + grid[i][j];
      // Last row
      else if (i == n - 1)
        dp[i][j] = max(dp[i][j + 1], dp[i - 1][j + 1]) + grid[i][j];
      // remaining cell
      else
        dp[i][j] = max({ dp[i][j + 1], dp[i - 1][j + 1], dp[i + 1][j + 1] }) + grid[i][j];
    }
  }
  // finding maximum value in the first column
  int ans = INT_MIN;
  for (int i = 0;i < n;i++)
    ans = max(ans, dp[i][0]);
  return ans;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> arr(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> arr[i][j];
  vector<vector<int>> dp(n, vector<int>(m, 0));
  cout << collectGold(n, m, arr, dp);
}