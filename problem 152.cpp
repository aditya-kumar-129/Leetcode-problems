// Question link :- https://leetcode.com/problems/maximum-product-subarray/
// Youtube link for method1 :-  https://youtu.be/tHNsZHXnYd4

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxProduct(vector<int>& nums) {
    int ma = nums[0], mi = nums[0], ans = nums[0];
    for (int i = 1;i < nums.size();i++)
    {
      if (nums[i] < 0)
        swap(ma, mi);
      ma = max(nums[i], ma * nums[i]);
      mi = min(nums[i], mi * nums[i]);
      ans = max(ans, ma);
    }
    return ans;
  }
}; 

// Method 2 :-
class Solution {
public:
  int maxProduct(vector<int>& arr) {
    int max_ending_here = arr[0];
    int min_ending_here = arr[0];
    int max_so_far = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
      int temp = max({ arr[i], arr[i] * max_ending_here, arr[i] * min_ending_here });
      min_ending_here = min({ arr[i], arr[i] * max_ending_here, arr[i] * min_ending_here });
      max_ending_here = temp;
      max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
  }
};