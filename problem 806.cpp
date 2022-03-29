// Question link :- https://leetcode.com/problems/number-of-lines-to-write-string/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> numberOfLines(vector<int>& v, string s) {
    int line = 0;     // count the number of lines 
    int max = 100;    // to check how many pixel value are remaining
    int count = 0;    // to check how many pixels have been used
    vector <int> ans;
    for (int i = 0;i < s.length();i++)
    {
      if (max < v[s[i] - 'a'])
      {
        max = 100;
        line++;
        i--;
        continue;
      }
      count += v[s[i] - 'a'];
      max -= v[s[i] - 'a'];
    }
    if (max != 0)       // in case the line is partially filled
      line++;
    if (count == 100)    // in case the line is fully used
      line++;
    ans.push_back(line);
    ans.push_back(100 - max);
    return ans;
  }
};