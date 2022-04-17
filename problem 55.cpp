// Question link :- https://leetcode.com/problems/jump-game/
// Youtube link :- https://www.youtube.com/watch?v=muDPTDrpS28

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool canJump(vector<int>& nums) {
    int reachable = 0;
    for (int i = 0;i < nums.size();i++)
    {
      if (reachable < i)
        return false;
      reachable = max(reachable, i + nums[i]);
    }
    return true;
  }
};