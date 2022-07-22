// Question link :- https://leetcode.com/problems/coin-change/'

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    // Since we have to find the minimum no of coins to acheive the target amount that's why we have filled our initial vector with a number that can't be acheived 
    // We haven't used INT_MAX because it may throw RUNTIME EXCEPTION in case of int overflow for some test case
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int i = 1;i < dp.size();i++)
      for (int j = 0;j < coins.size();j++)
        if (i - coins[j] >= 0)
          dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
          
    // In case their is no option with which we can acheive our target amount we have to return -1  
    if (dp[amount] == amount + 1)
      return -1;
    return dp[amount];
  }
};