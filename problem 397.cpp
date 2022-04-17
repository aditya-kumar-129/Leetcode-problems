// Question link :- https://leetcode.com/problems/integer-replacement/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int dfs(int n)
  {
    if (n == 1)
      return 0;
    if (n % 2 == 0)
      return 1 + dfs(n / 2);
    else
    {
      if (n == INT_MAX)
        return 32;
      else
        return 1 + min(dfs(n - 1), dfs(n + 1));
    }
  }
  int integerReplacement(int n) {
    return dfs(n);
  }
};

class Solution {
public:
  int dfs(long n)
  {
    if (n == 1)
      return 0;
    if (n % 2 == 0)
      return 1 + dfs(n / 2);
    else
      return 1 + min(dfs(n - 1), dfs(n + 1));
  }
  int integerReplacement(int n) {
    return dfs(long(n));
  }
};