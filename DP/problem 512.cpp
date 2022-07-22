// Question link :- https://leetcode.com/problems/coin-change-2/
// Youtube video :- https://www.youtube.com/watch?v=l_nR5X9VmaI


// Coin Change Combination 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int change(int amount, vector<int>& coins) {
    int dp[amount + 1];
    for (int i = 0;i < amount + 1;i++)
      dp[i] = 0;
    dp[0] = 1;
    for (int i = 0;i < coins.size();i++)
      for (int j = coins[i];j < amount + 1;j++)
        dp[j] += dp[j - coins[i]];
    return dp[amount];
  }
};