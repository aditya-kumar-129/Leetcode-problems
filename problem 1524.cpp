// Question link :- https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numOfSubarrays(vector<int>& arr) {
    int MOD = 1000000007;
    if (arr.size() == 0)
      return 0;
    int evenCount = 0, oddCount = 0;
    int sum = 0;
    int countSubArray = 0;
    for (auto it : arr)
    {
      sum += it;
      if (sum % 2 == 0)
      {
        countSubArray += oddCount;
        evenCount++;
      }
      else
      {
        countSubArray += 1 + evenCount;
        oddCount++;
      }
      countSubArray = countSubArray % MOD;
    }
    return countSubArray;
  }
};