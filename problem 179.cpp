// Question link :- https://leetcode.com/problems/largest-number/
// Youtube link :- https://www.youtube.com/watch?v=qEIGhVtZ-sg

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  static bool comparator(string first, string second)
  {
    string one = first + second;
    string two = second + first;
    if (one > two)
      return true;
    else
      return false;
  }
  string largestNumber(vector<int>& nums)
  {
    vector <string> str;
    for (auto it : nums)
      str.push_back(to_string(it));
    sort(str.begin(), str.end(), comparator);
    string ans = "";
    for (auto it : str)
      ans += it;
    return ans[0] == '0' ? "0" : ans;
  }
};