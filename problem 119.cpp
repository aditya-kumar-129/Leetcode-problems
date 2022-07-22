// Question link :- https://leetcode.com/problems/pascals-triangle-ii/

#include<bits/stdc++.h>
using namespace std;

// Optimised Solution 
// Space Complexities is less as compared to the previous method 
// This is iterative approach and we can also solve it using recursion
class Solution {
public:
  vector<int> getRow(int rowIndex) {
    int numRows = rowIndex +1;
    vector<int> ans;
    ans.push_back(1);
    if (numRows == 1)
      return ans;
    ans.push_back(1);
    if (numRows == 2)
      return ans;
    vector<int> prev = ans;
    for (int i = 3;i <= numRows;i++)
    {
      vector<int> curr;
      curr.push_back(1);
      for (int j = 0;j < prev.size() - 1;j++)
      {
        int sum = prev[j] + prev[j + 1];
        curr.push_back(sum);
        sum = 0;
      }
      curr.push_back(1);
      ans.clear();
      ans = curr;
      prev.clear();
      prev = curr;
      curr.clear();
    }
    return ans;
  }
};

// Brute Force Approach
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> getRow(int rowIndex) {
    int numRows = rowIndex + 1;
    vector<vector<int>> ans;
    ans.push_back({ 1 });
    if (numRows == 1)
      return ans[ans.size() - 1];
    ans.push_back({ 1,1 });
    if (numRows == 2)
      return ans[ans.size() - 1];
    vector<int> prev = ans[ans.size() - 1];
    for (int i = 3;i <= numRows;i++)
    {
      vector<int> curr;
      curr.push_back(1);
      for (int i = 0;i < prev.size() - 1;i++)
      {
        int sum = prev[i] + prev[i + 1];
        curr.push_back(sum);
        sum = 0;
      }
      curr.push_back(1);
      ans.push_back(curr);
      prev = curr;
      curr.clear();
    }
    return ans[ans.size() - 1];
  }
};