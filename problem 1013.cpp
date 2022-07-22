// Question link :- https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool canThreePartsEqualSum(vector<int>& nums) {
    int totalSum = 0;
    for (auto it : nums)
      totalSum += it;
    if (totalSum % 3 != 0)
      return false;
    int subarraySum = totalSum / 3;
    int noOfPartition = 0;
    int currSum = 0;
    for (int i = 0;i < nums.size();i++)
    {
      currSum += nums[i];
      if (currSum == subarraySum)
      {
        noOfPartition++;
        currSum = 0;
      }
      if (noOfPartition == 3)
        return true;
    }
    return false;
  }
};