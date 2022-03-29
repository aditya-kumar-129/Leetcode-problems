// Question link :- https://leetcode.com/problems/next-greater-element-ii/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1);
    stack <int> s;
    for (int i = 0;i < 2 * n;i++)
    {
      while (!s.empty() && nums[s.top()] < nums[i % n])
      {
        ans[s.top()] = nums[i % n];
        s.pop();
      }
      if (i < n)
        s.push(i);
    }
    return ans;
  }
};