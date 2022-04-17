// Question link :- https://leetcode.com/problems/remove-k-digits/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  string removeKdigits(string num, int k)
  {
    int n = num.size();
    stack <char> st;
    for (auto it : num)
    {
      while (!st.empty() && k > 0 && st.top() > it)
      {
        st.pop();
        k--;
      }
      // When the stack is empty and the current number is 0 then we will simply skip the zero and DON'T Push the element 
      if (!st.empty() || it != '0')
        st.push(it);
    }

    // Now the value of k is still non zero then in that case pop the stack k times
    // ex :- 12345
    while (!st.empty() && k)
    {
      st.pop();
      k--;
    }
    if (st.empty())
      return "0";

    // store the remaining number in ans variable
    string ans = "";
    while (!st.empty())
    {
      ans += st.top();
      st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};