// Question link :- https://leetcode.com/problems/n-repeated-element-in-size-2n-array/

#include<bits/stdc++.h>
using namespace std;

// Using hashmap and the property that is specified in the question. i.e, nums contains n + 1 unique elements.
class Solution {
public:
  int repeatedNTimes(vector<int>& nums) 
  {
    map<int, int> mp;
    int val;
    for (int i = 0;i < nums.size();i++)
    {
      mp[nums[i]]++;
      if (mp[nums[i]] > 1)
      {
        val = nums[i];
        break;
      }
    }
    return val;
  }
};

// using hashhmap
class Solution {
public:
  int repeatedNTimes(vector<int>& nums) 
  {
    map<int, int> mp;
    for (int i = 0;i < nums.size();i++)
      mp[nums[i]]++;
    int n = nums.size()/2;
    int val;
    for (auto it : mp)
    {
      if (it.second == n)
      {
        val = it.first;
        break;
      }
    }
    return val;
  }
};

// Optimised solution that i don't get
// https://www.enjoyalgorithms.com/blog/n-repeated-element-in-2n-size-array

// class Solution {
//   public int repeatedNTimes(int[] A) {
//     for (int k = 1; k <= 3; ++k)
//       for (int i = 0; i < A.length - k; ++i)
//         if (A[i] == A[i + k])
//           return A[i];
//     throw null;
//   }
// }