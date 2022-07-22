// Question link :- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
// Youtube link :- https://www.youtube.com/watch?v=pTQB9wbIpfU

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices, int fee) {
    int oldBuyStateProfit = -prices[0];
    int oldSoldStateProfit = 0;

    for (int i = 1;i < prices.size();i++) {
      int newBuyStateProfit = 0;
      int newSoldStateProfit = 0;

      if (oldSoldStateProfit - prices[i] > oldBuyStateProfit)
        newBuyStateProfit = oldSoldStateProfit - prices[i];
      else
        newBuyStateProfit = oldBuyStateProfit;

      if (prices[i] + oldBuyStateProfit - fee > oldSoldStateProfit)
        newSoldStateProfit = prices[i] + oldBuyStateProfit - fee;
      else
        newSoldStateProfit = oldSoldStateProfit;

      oldBuyStateProfit = newBuyStateProfit;
      oldSoldStateProfit = newSoldStateProfit;
    }
    return oldSoldStateProfit;
  }
};