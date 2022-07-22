// Question link :- https://leetcode.com/problems/sqrtx/

#include<bits/stdc++.h>
using namespace std;

// Logic is good
class Solution {
public:
  int mySqrt(int x) {
    long long mid, start = 0, end = x, ans;
    while (start <= end)
    {
      mid = start + ((end - start) / 2);
      if (mid * mid == x)
        return mid;
      else if (mid * mid < x)
        start = mid + 1, ans = mid;
      else
        end = mid - 1;
    }
    return ans;
  }
};