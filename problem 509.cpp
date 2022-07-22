// Question link :- https://leetcode.com/problems/fibonacci-number/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int fib(int n) {
    vector<int> ans(n + 2);
    ans[0] = 0;
    ans[1] = 1;
    if (n == 0)
      return 0;
    for (int i = 2;i <= n;i++)
      ans[i] = ans[i - 1] + ans[i - 2];
    return ans[n];
  }
};