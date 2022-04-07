// Question link :- https://leetcode.com/problems/single-number-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int singleNumber(vector<int>& nums)
  {
    int result = 0;
    int count;
    for (int i = 0;i < 32;i++)
    {
      count = 0;
      for (int j = 0;j < nums.size();j++)
        if (nums[j] & (1 << i))
          count++;
      if (count % 3 != 0)
        result |= (1 << i);
    }
    return result;
  }
};