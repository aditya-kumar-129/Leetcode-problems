// Question link :- https://leetcode.com/problems/add-binary/

#include<bits/stdc++.h>
using namespace std;

// Question link :- https://leetcode.com/problems/add-binary/

#include<bits/stdc++.h>
using namespace std;

// Optimised Approach
// Time Complexity :- O(n^2)
class Solution {
public:
  int totalHammingDistance(vector<int>& nums) {
    int ans = 0;
    int n = nums.size();
    for (int i = 0; i < 32; i++) 
    {
      int count = 0;
      for (int j = 0; j < n; j++)
        if ((nums[j] & (1 << i)))
          count++;
      ans += (count * (n - count) * 2);
    }
    return ans / 2;
  }
};

// Brute force Approach
// Time Complexity :- O(n^2)
class Solution {
public:
  int totalHammingDistance(vector<int>& nums) {
    int totalSum = 0;
    for(int i=0;i<nums.size()-1;i++)
    {
      for(int j=i+1;j<nums.size();j++)
      {
        int xorValue = nums[i]^nums[j];
        totalSum += __builtin_popcount(xorValue);
      }
    }
    return totalSum;
  }
};