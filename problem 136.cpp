// Question link :- https://leetcode.com/problems/single-number/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int oddNumber = 0;
    for (int i = 0;i <nums.size();  i++)
      oddNumber = oddNumber^ nums[i];
    return oddNumber;
  }
};