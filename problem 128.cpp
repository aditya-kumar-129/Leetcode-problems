// Question link :- https://leetcode.com/problems/longest-consecutive-sequence/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int>& nums)
  {
    if (nums.size() == 0)
      return 0;
    int ans = 0, count = 0, n = nums.size();
    sort(nums.begin(), nums.end());
    // we have to consider only unique elements
    vector<int> v;
    v.push_back(nums[0]);
    for (int i = 1; i < n; i++)
      if (nums[i] != nums[i - 1])
        v.push_back(nums[i]);
    for (int i = 0; i < v.size(); i++)
    {
      if (i > 0 && v[i] == v[i - 1] + 1)
        count++;
      else
        count = 1;
      ans = max(ans, count);
    }
    return ans;
  }
};