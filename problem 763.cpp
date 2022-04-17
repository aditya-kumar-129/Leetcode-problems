// Question link :- https://leetcode.com/problems/partition-labels/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> partitionLabels(string s)
  {
    vector<int> ans;
    map <char, int> mp;
    for (int i = 0;i < s.size();i++)
      mp[s[i]] = i;

    int prev = -1;
    int max_reach = -1;
    for (int i = 0;i < s.size();i++)
    {
      max_reach = max(max_reach,mp[s[i]]);
      if(max_reach == i)
      {
        ans.push_back(max_reach - prev);
        prev = max_reach;
      }
    }
    return ans;
  }
};