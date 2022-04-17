// Question link :- https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
// Why to use Median ?? 
// Refer the youtube link :-
// https://youtu.be/FGgL5QxZLno 
// Another Approach (having some base value and using two pointer algorithm) having same Time complexity 
// Refer Below Youtube Video
// https://youtu.be/Wo168YDPwzk  

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minMoves2(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int start =0 , end = n-1;
    int countSteps = 0;
    while(start<end)
    {
      countSteps += (nums[end] - nums[start]);
      start++;
      end--;
    }
    return countSteps;
  }
};

class Solution {
public:
  int minMoves2(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int median;
    if (n % 2 == 0)
      median = (nums[n / 2] + nums[n / 2 - 1]) / 2;
    else
      median = nums[n / 2];
    int totalMoves = 0;
    for (auto it : nums)
      totalMoves += abs(median - it);
    return totalMoves;
  }
};