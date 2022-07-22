// Question link :- https://leetcode.com/problems/subarray-sum-equals-k/
// Youtube link :-  https://www.youtube.com/watch?v=20v8zSo2v18

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int subarraySum(vector<int>& nums, int target) {
    int count = 0, currSum = 0;
    map<int, int> mp;
    mp[0]=1;
    for (int i = 0;i < nums.size();i++)
    {
      currSum += nums[i];
      if (mp.find(currSum - target) != mp.end())
        count += mp[currSum - target];
      mp[currSum]++;
    }
    return count;
  }
};