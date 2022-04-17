// Question link :- https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
// Youtube Link :- https://www.youtube.com/watch?v=7ASUzYC2B3Y
// GFG Arcticle :- https://www.geeksforgeeks.org/minimum-number-increment-operations-make-array-elements-equal/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minMoves(vector<int>& nums) 
  {
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    int smallestElement = *min_element(nums.begin(), nums.end());
    int minOperation = totalSum - (nums.size() * smallestElement);
    return minOperation;
  }
};