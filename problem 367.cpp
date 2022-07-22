// Question link :- https://leetcode.com/problems/valid-perfect-square/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isPerfectSquare(int num) {
    int x = mySqrt(num);
    if (x * x == num)
      return true;
    else
      return false;
  }
  int mySqrt(int x) {
    if (x == 0 || x == 1)
      return x;
    long long mid, start = 0, end = x / 2, ans;
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