// Question link :- https://leetcode.com/problems/find-the-difference/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  // wrong solution
  char findTheDifference(string s, string t) {
    map<char, int> mp;
    for (int i = 0;i < s.size();i++)
      mp[s[i]]++;
    for (int i = 0;i < t.size();i++)
      mp[t[i]]++;
    char ch;
    for (auto it : mp)
    {
      if (it.second == 1)
        ch = it.first;
    }
    return ch;
  }
};