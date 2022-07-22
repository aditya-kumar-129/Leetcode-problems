// Question link :- https://leetcode.com/problems/longest-palindromic-substring/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  string longestPalindrome(string str) {
    int n = str.size();
    bool dp[n][n];
    memset(dp, 0, sizeof(dp));
    int maxLength = 1;

    // All the one charcter strings are palindromes 
    for (int i = 0; i < n; ++i)
      dp[i][i] = true;

    // Start Variable is used for printing thr resultant maximum length substring
    int start = 0;
    // All the strings of length 2 are palindromes
    for (int i = 0; i < n - 1; ++i) {
      if (str[i] == str[i + 1]) {
        dp[i][i + 1] = true;
        start = i;
        // updating the maximum length of the substring
        maxLength = 2;
      }
    }

    // Check for all the strings of length greater than 2 if they are palindromes
    for (int k = 3; k <= n; k++) {
      for (int i = 0; i < n - k + 1; i++) {
        int j = i + k - 1;
        if (dp[i + 1][j - 1] && str[i] == str[j]) {
          dp[i][j] = true;
          if (k > maxLength) {
            start = i;
            maxLength = k;
          }
        }
      }
    }
    return str.substr(start, maxLength);
  }
};