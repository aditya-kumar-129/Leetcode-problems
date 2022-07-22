// Question link :- https://leetcode.com/problems/maximum-subarray/
// Kadanes Algorithm

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int max_so_far = INT_MIN, curr_sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      curr_sum = curr_sum + nums[i];
      if (max_so_far < curr_sum)
        max_so_far = curr_sum;
      if (curr_sum < 0)
        curr_sum = 0;
    }
    return max_so_far;
  }
};