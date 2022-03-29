// Question link :- https://leetcode.com/problems/basic-calculator-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int calculate(string s)
  {
    stack <int> st;
    int n = s.size();
    char sign = '+';
    for (int i = 0;i < n;i++)
    {
      char ch = s[i];
      if (isdigit(ch))
      {
        int val = 0;
        while (i < n && isdigit(s[i]))
        {
          val = val * 10 + (s[i] - '0');
          i++;
        }
        i--;
        if (sign == '+')
          st.push(val);
        else if (sign == '-')
          st.push(-val);
        else if (sign == '*')
        {
          int num1 = st.top();
          st.pop();
          int result = num1 * val;
          st.push(result);
        }
        else if (sign == '/')
        {
          int num1 = st.top();
          st.pop();
          int result = num1 / val;
          st.push(result);
        }
      }
      else if (ch != ' ')
        sign = ch;
    }
    int sum = 0;
    while (!st.empty())
    {
      int num = st.top();
      sum += num;
      st.pop();
    }
    return sum;
  }
};