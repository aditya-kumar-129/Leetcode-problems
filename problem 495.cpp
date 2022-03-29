// https://leetcode.com/problems/teemo-attacking/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findPoisonedDuration(vector<int>& timeSeries, int duration)
  {
    if (timeSeries.size() == 0)
      return 0;

    int count = 0;
    for (int i = 1;i < timeSeries.size();i++)
    {
      if (timeSeries[i] - timeSeries[i - 1] > duration)
        count += duration;
      else
        count += timeSeries[i] - timeSeries[i - 1];
    }
    count += duration;
    return count;
  }
};