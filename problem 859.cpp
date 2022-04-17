// Question link :- https://leetcode.com/problems/buddy-strings/
// Youtube Link :- https://www.youtube.com/watch?v=OlX_CZZfcI4

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool buddyStrings(string A, string B) {
    if (A.length() != B.length())
      return false;
    if (A == B)
    {
      set<char> s;
      for (int i = 0;i < A.size();i++)
      {
        if (s.find(A[i]) != s.end())
          return true;
        s.insert(A[i]);
      }
      return false;
    }

    vector<int> diff;
    for (int i = 0; i < A.length(); ++i)
      if (A[i] != B[i])
        diff.push_back(i);

    return diff.size() == 2 && A[diff[0]] == B[diff[1]] && A[diff[1]] == B[diff[0]];
  }
};
