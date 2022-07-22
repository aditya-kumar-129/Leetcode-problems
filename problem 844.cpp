// Question link :- https://leetcode.com/problems/backspace-string-compare/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool backspaceCompare(string str1, string str2) {
    stack<char> st1, st2;
    for (int i = 0;i < str1.size();i++)
    {
      if (str1[i] == '#' && !st1.empty())
        st1.pop();
      else if (str1[i] == '#' && st1.empty())
        continue;
      else
        st1.push(str1[i]);
    }
    for (int i = 0;i < str2.size();i++)
    {
      if (str2[i] == '#' && !st2.empty())
        st2.pop();
      else if (str2[i] == '#' && st2.empty())
        continue;
      else
        st2.push(str2[i]);
    }
    string resultantString1, resultantString2;
    while (!st1.empty())
    {
      resultantString1 += st1.top();
      st1.pop();
    }
    while (!st2.empty())
    {
      resultantString2 += st2.top();
      st2.pop();
    }
    reverse(resultantString1.begin(), resultantString1.end());
    reverse(resultantString2.begin(), resultantString2.end());
    if (resultantString1 == resultantString2)
      return true;
    else
      return false;
  }
};