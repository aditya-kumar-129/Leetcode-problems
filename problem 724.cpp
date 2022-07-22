// Question link :- https://leetcode.com/problems/find-pivot-index/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int pivotIndex(vector<int>& nums) {
    int sum = 0;
    for(auto it :nums)
      sum+=it;
    int leftSum=0,index=-1;
    for(int i=0;i<nums.size();i++)
    {
      sum-=nums[i];
      leftSum+=nums[i];
      if(leftSum==sum)
      {
        index =i;
        break;
      }
    }
    return index;
  }
};