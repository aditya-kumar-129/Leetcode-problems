// Question link :- https://leetcode.com/problems/set-matrix-zeroes/

#include<bits/stdc++.h>
using namespace std;

// Better Approach :- 
// Spcae complexity :- O(n+m)
class Solution {
public:
  void setZeroes(vector<vector<int>>& matrix) {
    set<int> row, col;
    for (int i = 0;i < matrix.size();i++)
      for (int j = 0;j < matrix[0].size();j++)
        if (matrix[i][j] == 0)
          row.insert(i), col.insert(j);

    for (int i = 0;i < matrix.size();i++)
      for (int j = 0;j < matrix[0].size();j++)
        if (row.find(i) != row.end() || col.find(j) != col.end())
          matrix[i][j] = 0;
  }
}; 

class Solution {
public:
  void setZeroes(vector<vector<int>>& matrix) {
    int rows = matrix.size(), cols = matrix[0].size();
    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
      {
        if (matrix[i][j] == 0)
        {
          int ind = i - 1;
          while (ind >= 0)
          {
            if (matrix[ind][j] != 0)
              matrix[ind][j] = -1;
            ind--;
          }
          ind = i + 1;
          while (ind < rows)
          {
            if (matrix[ind][j] != 0)
              matrix[ind][j] = -1;
            ind++;
          }
          ind = j - 1;
          while (ind >= 0)
          {
            if (matrix[i][ind] != 0)
              matrix[i][ind] = -1;
            ind--;
          }
          ind = j + 1;
          while (ind < cols)
          {
            if (matrix[i][ind] != 0)
              matrix[i][ind] = -1;
            ind++;
          }
        }
      }
    }
    for (int i = 0; i < rows; i++)
      for (int j = 0; j < cols; j++)
        if (matrix[i][j] <= 0)
          matrix[i][j] = 0;
  }
};

// Time Complexity : O((N* M)* (N + M)).O(N* M) for traversing through each element and (N + M)for traversing to rowand column of elements having value 0.
// Space Complexity : O(1)