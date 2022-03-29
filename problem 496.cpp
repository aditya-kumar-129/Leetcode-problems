// Question link :- https://leetcode.com/problems/next-greater-element-i/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
  {
    stack <int> s;
    vector <int> ans(nums2.size());
    map<int, int> mp;
    for (int i = 0;i < nums2.size();i++)
    {
      if (s.empty())
        s.push(i);
      else
      {
        while (!s.empty() && nums2[s.top()] < nums2[i])
        {
          mp[nums2[s.top()]] = nums2[i];
          s.pop();
        }
        s.push(i);
      }
    }
    while (!s.empty())
    {
      mp[nums2[s.top()]] = -1;
      s.pop();
    }
    vector <int> temp (nums1.size());
    for(int i=0;i<nums1.size();i++)
      temp[i] = mp[nums1[i]];
    return temp;
  }
};