// Question link :- https://leetcode.com/problems/valid-parenthesis-string/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool checkValidString(string s)
  {
    stack <int> openBracket;
    stack <int> star;
    for (int i = 0;i < s.size();i++)
    {
      if (s[i] == '(')
        openBracket.push(i);
      else if (s[i] == '*')
        star.push(i);
      else
      {
        if (!openBracket.empty())
          openBracket.pop();
        else if (!star.empty())
          star.pop();
        else
          return false;
      }
    }
    while (!openBracket.empty())
    {
      if (star.empty())
        return false;
      if (star.top() > openBracket.top())
      {
        openBracket.pop();
        star.pop();
      }
      else
        return false;
    }
    return true;
  }
};
