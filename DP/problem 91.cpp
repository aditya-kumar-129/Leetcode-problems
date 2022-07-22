// Question link :- https://leetcode.com/problems/decode-ways/
// Youtube video :- https://www.youtube.com/watch?v=o1i7JYWbwOE

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numDecodings(string digits) {
    int n = digits.size();
    vector<int> dp(n + 1, 0);
    if (digits[0] == '0')
      return 0;
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
      // checking the last digit if it non-zero or not 
      // If it non zero then it would countribute dp[i-1] to dp[i] else it would contribute 0
      // digits[i-1] represent the digit that has just been inseted in the string for the current iteration       
      if (digits[i - 1] > '0')
        dp[i] = dp[i - 1];
      // checking the last two digit if it is less than 26 or not
      // If it is less than 26 then it would countribute dp[i-1] + dp[i-2] to dp[i] else it would contribute 0
      // digits[i-1] represent the last digit including the digit that has just been inseted in the string for the current iteration
      if (digits[i - 2] == '1' || (digits[i - 2] == '2' && digits[i - 1] < '7'))
        dp[i] += dp[i - 2];
    }
    return dp[n];
  }
};