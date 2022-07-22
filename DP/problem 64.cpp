// Question link :- https://leetcode.com/problems/minimum-path-sum/
// Youtube video :- https://www.youtube.com/watch?v=BzTIOsC0xWM

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = n - 1;i >= 0;i--) {
      for (int j = m - 1;j >= 0;j--) {
        // last cell
        if (i == n - 1 && j == m - 1) 
          dp[i][j] = grid[i][j];
        // last row
        else if (i == n - 1) 
          dp[i][j] = dp[i][j + 1] + grid[i][j];
        // last column
        else if (j == m - 1) 
          dp[i][j] = dp[i + 1][j] + grid[i][j];
        // remaining cell
        else 
          dp[i][j] = min(dp[i][j + 1], dp[i + 1][j]) + grid[i][j];
      }
    }
    return dp[0][0];
  }
};