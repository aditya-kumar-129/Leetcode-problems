// Question link :- https://leetcode.com/problems/contains-duplicate/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    map<int, int>  m;
    for (auto it : nums)
      m[it]++;
    bool flag = false;
    for (auto it : m)
    {
      if (it.second > 1)
      {
        flag = true;
        break;
      }
    }
    return flag;
  }
};