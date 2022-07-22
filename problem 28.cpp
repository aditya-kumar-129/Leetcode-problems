// Question link :- https://leetcode.com/problems/implement-strstr/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int strStr(string s1, string s2) {
    int j = 0;
    for (int i = 0; i < s1.size();)
    {
      if (s1[i] == s2[j] && s2[j + 1] == '\0')
        return i - j;
      else if (s1[i] == s2[j])
      {
        i++;
        j++;
      }
      else if (s1[i] != s2[j])
      {
        i++;
        if (j > 0)
        {
          i = i - j;
          j = 0;
        }
      }
    }
    return -1;
  }
};