// Question link :- https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Youtube link :- https://www.youtube.com/watch?v=4YjEHmw1MX0

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int min_ele = 1e9;
    int maxProfit = 0;
    for (int i = 0;i < prices.size();i++)
    {
      min_ele = min(min_ele, prices[i]);
      maxProfit = max(maxProfit, prices[i] - min_ele);
    }
    return maxProfit;
  }
};