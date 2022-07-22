// Question link :- https://leetcode.com/problems/palindromic-substrings/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countSubstrings(string str) {
    int n = str.size();
    int ans = 0;
    bool P[n][n];
    memset(P, false, sizeof(P));
    for (int i = 0; i < n; i++) {
      P[i][i] = true;
      ans++;
    }
    for (int i = 0;i < n - 1;i++) {
      if (str[i] == str[i + 1]) {
        P[i][i + 1] = true;
        ans++;
      }
    }
    for (int gap = 3; gap <= n; gap++) {
      for (int i = 0; i <= n - gap; i++) {
        int j = gap + i - 1;
        if (str[i] == str[j] && P[i + 1][j - 1]) {
          P[i][j] = true;
          ans++;
        }
      }
    }
    return ans;
  }
};