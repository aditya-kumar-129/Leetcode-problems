// Question link :- https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
// Youtube video :- https://www.youtube.com/watch?v=jgps7MXtKRQ

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int knapSack(int size, int bagCapacity, int profits[], int weight[])
  {
    vector<int> dp(bagCapacity + 1, 0);
    dp[0] = 0;
    for (int i = 1;i <= bagCapacity;i++) {
      int maximum_profit = 0;
      for (int j = 0;j < size;j++) {
        if (i - weight[j] >= 0) {
          int temperoryProfit = profits[j] + dp[i - weight[j]];
          maximum_profit = max(temperoryProfit, maximum_profit);
        }
      }
      dp[i] = maximum_profit;
    }
    return dp[bagCapacity];
  }
};