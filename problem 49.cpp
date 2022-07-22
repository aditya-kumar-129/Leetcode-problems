// Question link :- https://leetcode.com/problems/group-anagrams/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    map<string, vector<string>> m;
    for (auto it : strs)
    {
      string temp = it;
      sort(temp.begin(), temp.end());
      m[temp].push_back(it);
    }
    for (auto it : m)
      ans.push_back(it.second);
    return ans;
  }
};