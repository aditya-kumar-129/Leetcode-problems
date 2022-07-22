// Question link :- https://leetcode.com/problems/power-of-two/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isPowerOfTwo(int n) {
    long x = n;
    return x && (!(x & (x - 1)));
  }
};

// Method 2 :- 
class Solution {
public:
  bool isPowerOfTwo(int n) {
    if (n == 0)
      return false;
    double ans = log2(n);
    cout << ans;
    if (ceil(ans) == floor(ans))
      return true;
    return false;
  }
};