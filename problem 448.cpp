// Question link :- https://leetcode.com/problems/find-all-duplicates-in-an-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
      // For every given element Find its index
      int temp = abs(nums[i]) - 1;
      // Update the element at the found index
      nums[temp] = nums[temp] > 0 ? -nums[temp] : nums[temp];
    }
    for (int i = 0; i < nums.size(); i++)
      if (nums[i] > 0)
        ans.push_back(i + 1);
    return ans;
  }
};