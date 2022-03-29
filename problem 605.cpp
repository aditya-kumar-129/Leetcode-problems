// Question link :- https://leetcode.com/problems/can-place-flowers/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n)
  {
    int count = 0;
    for (int i = 0;i < flowerbed.size();i++)
    {
      if (flowerbed[i] == 0)
      {
        int prev = (i == 0 || flowerbed[i - 1] == 0) ? 0 : 1;
        int next = (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0) ? 0 : 1;

        if (prev == 0 && next == 0)
        {
          flowerbed[i] = 1;
          count++;
        }
      }
    }
    if (count >= n)
      return true;
    else
      return false;
  }
};