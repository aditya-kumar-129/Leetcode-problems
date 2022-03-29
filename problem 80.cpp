// Question link :- https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

#include<bits/stdc++.h>
using namespace std;

// HAve a  look on this youtube video
// https://www.youtube.com/watch?v=drbtmYjZQHQ

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for (auto it : nums)
    {
      if (i == 0 || i == 1 || nums[i - 2] != it)
      {
        nums[i] = it;
        i++;
      }
    }
    return i;
  }
};