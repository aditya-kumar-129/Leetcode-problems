// Question link :- https://leetcode.com/problems/missing-number/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int missingNumber(vector<int>& nums) {
    int size = nums.size();
    int missingNumber;
    sort(nums.begin(),nums.end());
    for(int i=0;i<size;i++)
    {
      if(nums[i]!=i)
      {
        missingNumber = i;
        break;
      }
    }
    return missingNumber;
  }
};