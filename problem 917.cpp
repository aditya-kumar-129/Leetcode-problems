// Question link :- https://leetcode.com/problems/reverse-only-letters/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  string reverseOnlyLetters(string s)
  {
    vector<string> str;   // Stores all the alphabetical characters
    string temp = "";      // temporarily stores all the alphabetical characters untill some non-alphabetical characters found
    for (int i = 0;i < s.size();i++)
    {
      if ((s[i] < 65 || s[i]>90) && (s[i] < 97 || s[i]>122))
      {
        reverse(temp.begin(), temp.end());
        str.push_back(temp);
        temp = "";
      }
      else
        temp += s[i];
    }
    // To put the last word 
    reverse(temp.begin(), temp.end());
    str.push_back(temp);

    // reverse the whole vector
    reverse(str.begin(), str.end());

    temp = "";
    for (auto it : str)
      temp += it;

    // for printing the final answer
    string ans = "";
    int j = 0;
    for (int i = 0;i < s.size();i++)
    {
      if ((s[i] < 65 || s[i]>90) && (s[i] < 97 || s[i]>122))
        ans += s[i];
      else
      {
        ans += temp[j];
        j++;
      }
    }
    return ans;
  }
};