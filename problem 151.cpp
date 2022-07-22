// Question link :- https://leetcode.com/problems/reverse-words-in-a-string/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  string reverseWords(string s) {
    if (s[s.size() - 1] != ' ')
      s += ' ';
    vector<string> word;
    string temp;
    for (int i = 0;i < s.size();i++)
    {
      if (s[i] != ' ')
        temp += s[i];
      else
      {
        if (temp.size() > 0)
          word.push_back(temp);
        temp = "";
      }
    }
    reverse(word.begin(), word.end());
    string ans;
    for (auto it : word)
    {
      ans += it;
      ans += ' ';
    }
    ans.erase(ans.size() - 1);
    return ans;
  }
};