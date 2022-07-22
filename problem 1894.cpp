// Question link :- https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int chalkReplacer(vector<int>& chalk, int k) {
    int index, i = 0;
    long long sum = 0;
    for (auto it : chalk)
      sum += it;
    if (k > sum)
      k = k % sum;
    while (true)
    {
      if (k < chalk[i % chalk.size()])
      {
        index = i % chalk.size();
        break;
      }
      k -= chalk[i % chalk.size()];
      i++;
    }
    return index;
  }
};