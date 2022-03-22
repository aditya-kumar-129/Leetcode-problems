#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  void rotate(vector<vector<int>>& arr)
  {
    // Below code for transpose is only for sqaure matrix
    for (int i = 0;i < arr.size();i++)
      for (int j = 0;j < i;j++)
        swap(arr[i][j], arr[j][i]);

    for (int r = 0;r < arr.size();r++)
    {
      int left = 0;
      int right = arr.size() - 1;
      while (left < right)
      {
        swap(arr[r][left], arr[r][right]);
        left++;
        right--;
      }
    }
  }
};