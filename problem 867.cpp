#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> transpose(vector<vector<int>>& matrix)
  {
    // Below code transposes both square as well as rectangular matrix         
    int n = matrix.size();   // ROW
    int m = matrix[0].size();   // COLUMN
    // Below initialisation is IMPORTANT otherwise IT GIVES ERROR
    vector<vector<int>> ans(m, vector<int>(n, 0));
    for (int i = 0;i < n;i++)
      for (int j = 0;j < m;j++)
        ans[j][i] = matrix[i][j];
    return ans;
  }
};