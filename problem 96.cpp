// Question link :- https://leetcode.com/problems/unique-binary-search-trees/

#include<bits/stdc++.h>
using namespace std;

// Uses the concept of Catlan Number

class Solution {
public:
  int dp[20];
  int numTrees(int n)
  {
    if (n <= 1)
      return 1;
    if (dp[n])
      return dp[n];
    for (int i = 1; i <= n; i++)
      dp[n] += numTrees(i - 1) * numTrees(n - i);
    return dp[n];
  }
};