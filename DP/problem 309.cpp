// Question link :- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
// Youtube link :- https://www.youtube.com/watch?v=GY0O57llkKQ

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int oldBuyStateProfit = -prices[0];
    int oldSoldStateProfit = 0;
    int oldCoolStateProfit = 0;

    for (int i = 1;i < prices.size();i++) {
      int newBuyStateProfit = 0;
      int newSoldStateProfit = 0;
      int newCoolStateProfit = 0;

      if (oldCoolStateProfit - prices[i] > oldBuyStateProfit)
        newBuyStateProfit = oldCoolStateProfit - prices[i];
      else
        newBuyStateProfit = oldBuyStateProfit;

      if (prices[i] + oldBuyStateProfit > oldSoldStateProfit)
        newSoldStateProfit = prices[i] + oldBuyStateProfit;
      else
        newSoldStateProfit = oldSoldStateProfit;

      if(oldSoldStateProfit>oldCoolStateProfit)
        newCoolStateProfit = oldSoldStateProfit;
      else
        newCoolStateProfit = oldCoolStateProfit;

      oldBuyStateProfit = newBuyStateProfit;
      oldSoldStateProfit = newSoldStateProfit;
      oldCoolStateProfit = newCoolStateProfit;
    }
    return oldSoldStateProfit;
  }
};