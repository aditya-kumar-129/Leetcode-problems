// Question link :- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// Youtube link :- https://www.youtube.com/watch?v=wuzTpONbd-0

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& arr) {
    int mpist = 0;
    int leastsf = arr[0];
    int dpLeft[arr.size()];
    for (int i = 1;i < arr.size();i++) {
      if (arr[i] < leastsf)
        leastsf = arr[i];

      mpist = arr[i] - leastsf;
      if (mpist > dpLeft[i - 1])
        dpLeft[i] = mpist;
      else
        dpLeft[i] = dpLeft[i - 1];
    }

    int mpibt = 0;
    int maxat = arr[arr.size() - 1];
    int dpRight[arr.size()];

    for (int i = arr.size() - 2;i >= 0;i--) {
      if (arr[i] > maxat)
        maxat = arr[i];

      mpibt = maxat - arr[i];
      if (mpibt > dpRight[i + 1])
        dpRight[i] = mpibt;
      else
        dpRight[i] = dpRight[i + 1];
    }

    int maxProfit = 0;
    for (int i = 0;i < arr.size();i++)
      if (dpLeft[i] + dpRight[i] > maxProfit)
        maxProfit = dpLeft[i] + dpRight[i];

    return maxProfit;
  }
};

// NOT SUBMITTED