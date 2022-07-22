// Question link :- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// Youtube link :- https://www.youtube.com/watch?v=HWJ9kIPpzXs

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int sellingDate=0;
    int buyingDate=0;
    int totalProfit=0;
    for(int i=1;i<prices.size();i++){
      if(prices[i]>=prices[i-1])
        sellingDate++;
      else{
        totalProfit+= (prices[sellingDate] - prices[buyingDate]);
        sellingDate = buyingDate =i;
      }
    }
    totalProfit += (prices[sellingDate] - prices[buyingDate]);
    return totalProfit;
  }
};