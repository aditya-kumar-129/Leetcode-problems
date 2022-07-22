// Question link :- https://leetcode.com/problems/climbing-stairs/
// Youtube Video :- https://www.youtube.com/watch?v=94dfRrDANRY

#include<bits/stdc++.h>
using namespace std;

// Tabulation Method
class Solution {
public:
  int recurse(int n) {
    int dp[n + 1];
    dp[0] = 1;
    for (int i = 1;i < n + 1;i++)
    {
      if (i == 1)
        dp[i] = dp[i - 1];
      else
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
  }
  int climbStairs(int n) {
    return recurse(n);
  }
};

// Memoization Method
class Solution {
public:
  int recurse(int n, int qb[])
  {
    if (n < 0)
      return 0;
    if (n == 0)
      return 1;
    if (qb[n])
      return qb[n];
    int value = recurse(n - 1, qb) + recurse(n - 2, qb);
    qb[n] = value;
    return value;
  }
  int climbStairs(int n) {
    int qb[n + 1];
    for (int i = 0;i < n + 1;i++)
      qb[i] = 0;
    return recurse(n, qb);
  }
};