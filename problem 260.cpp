// Question link :- https://leetcode.com/problems/single-number-iii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> singleNumber(vector<int>& nums) {
    long long int xor_of_nums = 0;
    for(int i=0;i<nums.size();i++)
      xor_of_nums^=nums[i];
    long long int get_the_rightmost_set_bit = xor_of_nums & ~(xor_of_nums -1) ;
    long long int x =0,y=0;
    for(int i=0;i<nums.size();i++)
    {
      if (nums[i] & get_the_rightmost_set_bit)
        x^=nums[i];
      else
        y^=nums[i];
    }
    vector <int> ans;
    ans.push_back(x);
    ans.push_back(y);
    return ans;
  }
};