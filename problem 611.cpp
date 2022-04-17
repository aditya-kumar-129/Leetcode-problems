// Question link :- https://leetcode.com/problems/valid-triangle-number/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int triangleNumber(vector<int>& nums)
  {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int count = 0;
    for (int i = n - 1; i >= 1; i--)
    {
      int left = 0, right = i - 1;
      while (left < right)
      {
        if (nums[left] + nums[right] > nums[i])
        {
          count += right - left;
          right--;
        }
        else
          left++;
      }
    }
    return count;
  }
};


// Time complexity :- O(N^2)
class Solution {
public:
  int triangleNumber(vector<int>& nums)
  {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n - 2; ++i)
    {
      for (int j = i + 1; j < n; ++j)
      {
        int k = j + 1;
        while (k < n && nums[i] + nums[j] > nums[k])
          ++k;
        if (k > j)
          count += k - j - 1;
      }
    }
    return count;
  }
};


// Brute force approach
class Solution {
public:
  int triangleNumber(vector<int>& nums)
  {
    int n = nums.size();
    int count = 0;
    for (int i = 0;i < n - 2;i++)
    {
      for (int j = i + 1;j < n - 1;j++)
      {
        for (int k = j + 1;k < n;k++)
        {
          if (((nums[i] + nums[j]) > nums[k]) && ((nums[j] + nums[k]) > nums[i]) && ((nums[i] + nums[k]) > nums[j]))
            count++;
        }
      }
    }
    return count;
  }
};