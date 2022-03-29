// Question link :- https://leetcode.com/problems/remove-duplicates-from-sorted-array/ 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int>& nums)
  {
    int index = 1;
    for (int i = 1;i < nums.size();i++)
    {
      if (nums[i] != nums[i - 1])
      {
        nums[index] = nums[i];
        index++;
      }
    }
    return index;
  }
};