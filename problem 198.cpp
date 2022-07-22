// Question link :- https://leetcode.com/problems/maximum-product-subarray/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int rob(vector<int>& nums) {
    int odd_sum=0,even_sum=0;
    for(int i=0;i<nums.size();i++)
    {
      if(i&1)
        odd_sum+=nums[i];
      else
        even_sum+=nums[i];
    }
    return max(odd_sum,even_sum);
  }
};