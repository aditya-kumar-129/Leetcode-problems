#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> numberOfLines(vector<int>& v, string s) {
    int line = 0;
    int max = 100;
    int count = 0;
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
    if (max != 0)
      line++;
    if (count == 100)
      line++;
    ans.push_back(line);
    ans.push_back(100 - max);
    return ans;
  }
};