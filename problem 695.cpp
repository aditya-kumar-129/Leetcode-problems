// Question link :- https://leetcode.com/problems/max-area-of-island/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int result = 0;
  int dfs(vector<vector<int>>& grid, int row, int col) {
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0)
      return 0;
    // not keeping visited marking...
    grid[row][col] = 0;
    return 1 + dfs(grid, row + 1, col) + dfs(grid, row - 1, col) + dfs(grid, row, col + 1) + dfs(grid, row, col - 1);
  }
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    if (grid.size() == 0 || grid[0].size() == 0)
      return result;

    for (int i = 0; i < grid.size(); i++)
      for (int j = 0; j < grid[0].size(); j++)
        if (grid[i][j] == 1)
          result = max(result, dfs(grid, i, j));

    return result;
  }
};