// Question link :- https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minAddToMakeValid(string s) {
    stack<char> st;
    int countClosingBrackets = 0;
    for (int i = 0;i < s.size();i++)
    {
      if (s[i] == '(')
        st.push('(');
      else
      {
        if (st.size() != 0 && st.top() == '(')
          st.pop();
        else if(st.size()==0)
          countClosingBrackets++;
      }
    }
    if (st.size() == 0 && countClosingBrackets == 0)
      return 0;
    else if (st.size() == 0 && countClosingBrackets > 0)
      return countClosingBrackets;
    else if (st.size() > 0 && countClosingBrackets == 0)
      return st.size();
    else
      return st.size() + countClosingBrackets;
  }
};