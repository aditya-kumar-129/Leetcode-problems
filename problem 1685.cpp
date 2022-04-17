// Question link :- https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> getSumAbsoluteDifferences(vector<int>& nums)
  {
    int totalSum = 0;
    for (auto it : nums)
      totalSum += it;
    vector<int> ans;
    int leftSum = 0;
    int leftIndex = 0;

    for (int i = 0;i < nums.size();i++)
    {
      int rightSum = totalSum - leftSum - nums[i];
      int rightIndex = nums.size() - leftIndex - 1;
      ans.push_back(((leftIndex * nums[i]) - leftSum) + (rightSum - (rightIndex * nums[i])));
      leftIndex++;
      leftSum += nums[i];
    }
    return ans;
  }
};