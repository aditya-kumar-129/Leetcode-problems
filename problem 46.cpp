// Question link :- https://leetcode.com/problems/permutations/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  void helper(int left, int size, vector<int>& nums, vector<vector<int>>& ans)
  {
    if (left == size)
    {
      ans.push_back(nums);
      return;
    }
    for (int i = left;i < size;i++)
    {
      swap(nums[i], nums[left]);
      helper(left + 1, size, nums, ans);
      swap(nums[i], nums[left]);
    }

  }
  vector<vector<int>> permute(vector<int>& nums)
  {
    vector<vector<int>> ans;
    helper(0, nums.size(), nums, ans);
    return ans;
  }
};