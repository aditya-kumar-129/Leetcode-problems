// Question link :- https://leetcode.com/problems/binary-number-with-alternating-bits/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool hasAlternatingBits(int n) {
    int prev = n & 1;
    n = (n >> 1);
    cout << n;
    while (n)
    {
      int curr = n & 1;
      if (curr == prev)
        return false;
      prev = curr;
      n = (n >> 1);
    }
    return true;
  }
};