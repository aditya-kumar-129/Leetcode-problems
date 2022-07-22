// Question link :- https://leetcode.com/problems/pascals-triangle/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    if (numRows == 1) return { {1} };
    if (numRows == 2) return { {1},{1,1} };

    vector<vector<int>> ans;
    ans.push_back({ 1 });
    ans.push_back({ 1,1 });

    vector<int> prev;
    prev.push_back(1);
    prev.push_back(1);

    for (int i = 3;i <= numRows;i++) {
      vector<int> v;
      v.push_back(1);
      for (int j = 0;j < prev.size() - 1;j++)
        v.push_back(prev[j] + prev[j + 1]);
      v.push_back(1);
      ans.push_back(v);
      prev = v;
    }
    return ans;
  }
};