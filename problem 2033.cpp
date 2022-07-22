// Question link :- https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minOperations(vector<vector<int>>& grid, int x)
  {
    int mod = grid[0][0] % x;
    for (int i = 0;i < grid.size();i++)
      for (int j = 0;j < grid[0].size();j++)
        if (grid[i][j] % x != mod)
          return -1;


    vector <int> arr;
    for (auto it : grid)
      for (auto et : it)
        arr.push_back(et);


    sort(arr.begin(), arr.end());
    int median = 0;
    int n = arr.size();
    if (arr.size() % 2 == 0)
      median = (arr[n / 2] + arr[n / 2 - 1]) / 2;
    else
      median = arr[n / 2];
    int totalSteps = 0;
    for (auto it : arr)
      totalSteps += abs(it - median);
    return totalSteps / x;
  }
};
