// Question link :- https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<long long> sumOfThree(long long num)
  {
    long long int sum = 0;
    long long num1 = num;
    vector<long long> ans;
    // This is necessary in order to know thqt whether the sum is divisible by 3 or not         
    while (num != 0)
    {
      long long int quo = num % 10;
      sum += quo;
      num /= 10;
    }
    if (sum % 3 == 0)
    {
      num1 /= 3;
      ans.push_back(num1 - 1);
      ans.push_back(num1);
      ans.push_back(num1 + 1);
    }
    return ans;
  }
};