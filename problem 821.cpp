// Question link :- https://leetcode.com/problems/shortest-distance-to-a-character/

// Youtube video :- https://www.youtube.com/watch?v=YMKpDBmDJQE

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> shortestToChar(string s, char c) {
    vector <int> ans;
    int prev = INT_MAX;
    for (int i = 0;i < s.size();i++)
    {
      if (s[i] == c)
        prev = i;
      if (prev == INT_MAX)
        ans.push_back(INT_MAX);
      else
        ans.push_back(i - prev);
    }
    prev = INT_MAX;
    for (int i = s.size() - 1;i >= 0;i--)
    {
      if (s[i] == c)
        prev = i;
      if (prev != INT_MAX)
        ans[i] = min(ans[i], prev - i);
    }
    return ans;
  }
};