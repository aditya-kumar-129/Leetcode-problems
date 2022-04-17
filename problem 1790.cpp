// Question link :- https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool areAlmostEqual(string s1, string s2) {
    int startIndex = -1 , endIndex = -1;
    int n = s1.size();
    for(int i=0;i<n;i++)
    {
      if(s1[i]!=s2[i])
      {
        startIndex = i;
        break;
      }
    }
    for (int i = n-1;i >= 0;i--)
    {
      if (s1[i] != s2[i])
      {
        endIndex = i;
        break;
      }
    } 
    if(startIndex != -1 && endIndex != -1)
      swap(s2[startIndex],s2[endIndex]);

    for (int i = 0;i < n;i++)
      if (s1[i] != s2[i])
        return false;
    return true;
  }
};