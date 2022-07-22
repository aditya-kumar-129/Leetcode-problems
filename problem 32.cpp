// Question link :- https://leetcode.com/problems/longest-valid-parentheses/
// Youtube video :-  https://youtu.be/VdQuwtEd10M

#include<bits/stdc++.h>
using namespace std;

// OPTIMISED SOLUTION 
// SPACE COMPLEXITY :- O(1)
class Solution {
public:
  int longestValidParentheses(string str) {
    int ans = 0;
    int openBracket = 0, closeBracket = 0;
    for (int i = 0;i < str.size();i++)
    {
      if (str[i] == '(')
        openBracket++;
      else
        closeBracket++;
      if (openBracket == closeBracket)
        ans = max(ans, 2 * openBracket);
      if (closeBracket > openBracket)
        closeBracket = 0, openBracket = 0;
    }
    openBracket = 0, closeBracket = 0;
    for (int i = str.size()-1;i >=0;i--)
    {
      if (str[i] == '(')
        openBracket++;
      else
        closeBracket++;
      if (openBracket == closeBracket)
        ans = max(ans, 2 * openBracket);
      if (openBracket > closeBracket)
        closeBracket = 0, openBracket = 0;
    }
    return ans;
  }
};


// BRUTE FORCE APPROACH
// SPACE COMPLEXITY :- O(n)
class Solution {
public:
  int longestValidParentheses(string str) {
    int n = str.length();
    stack<int> st;
    st.push(-1);
    int result = 0;
    for (int i = 0; i < n; i++)
    {
      if (str[i] == '(')
        st.push(i);
      else
      {
        if (!st.empty())
          st.pop();
        if (!st.empty())
          result = max(result, i - st.top());
        else
          st.push(i);
      }
    }
    return result;
  }
};