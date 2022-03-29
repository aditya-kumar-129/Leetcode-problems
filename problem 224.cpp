// Question link :- https://leetcode.com/problems/basic-calculator/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int calculate(string s)
  {
    int sum = 0;
    int sign = 1;
    stack <int> st;
    for (int i = 0;i < s.size();i++)
    {
      char ch = s[i];
      if (isdigit(ch))
      {
        int val = 0;
        while (i < s.size() && isdigit(s[i]))
        {
          val = val * 10 + (s[i] - '0');
          i++;
        }
        i--; // it should be done as the for loop also increments the the value of i
        val *= sign;
        sign = 1;
        sum += val;
      }
      else if (ch == '(')
      {
        st.push(sum);
        st.push(sign);
        sum = 0;
        sign = 1;
      }
      else if (ch == ')')
      {
        int sign = st.top();
        sum *= sign;
        st.pop();
        int temp = st.top();
        sum += temp;
        st.pop();
      }
      else if (ch == '-')
        sign *= -1;
    }
    return sum;
  }
};