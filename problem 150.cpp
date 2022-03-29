// Question link :- https://leetcode.com/problems/evaluate-reverse-polish-notation/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int evalRPN(vector<string>& tokens) 
  {
    stack <int> st;
    int n = tokens.size();
    for(int i=0;i<n;i++)
    {
      if(tokens[i]=="+")
      {
        int num2 = st.top();
        st.pop();
        int num1 = st.top();
        st.pop();
        int result  = num1 + num2;
        st.push(result);
      }
      else if (tokens[i] == "-")
      {
        int num2 = st.top();
        st.pop();
        int num1 = st.top();
        st.pop();
        int result = num1 - num2;
        st.push(result);
      }
      else if (tokens[i] == "*")
      {
        int num2 = st.top();
        st.pop();
        int num1 = st.top();
        st.pop();
        int result = num1 * num2;
        st.push(result);
      }
      else if (tokens[i] == "/")
      {
        int num2 = st.top();
        st.pop();
        int num1 = st.top();
        st.pop();
        int result = num1 / num2;
        st.push(result);
      }
      else
      {
        string str = tokens[i];
        int val = stoi(str);
        st.push(val);
      }
    }
    return st.top();
  }
};