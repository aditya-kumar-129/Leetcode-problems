// Question link :- https://leetcode.com/problems/move-zeroes/

#include<bits/stdc++.h>
using namespace std;

// Optimised Approach 
// Time Complexity :- O(n)
// IDK j=how the below method is working
class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    int count = 0;
    for (int i = 0;i < nums.size();i++)
      if (nums[i] != 0)
        nums[count++] = nums[i];
    while (count < nums.size())
      nums[count++] = 0;
  }
};


// Brute Force Approach 
// Time Complexity :- O(n^2)
class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0;i < n - 1;i++)
    {
      if (nums[i] == 0)
      {
        int index = -1;
        for (int j = i + 1;j < n;j++)
        {
          if (nums[j] != 0)
          {
            index = j;
            break;
          }
        }
        if (index == -1)
          continue;
        else
          swap(nums[i], nums[index]);
      }
    }
  }
};