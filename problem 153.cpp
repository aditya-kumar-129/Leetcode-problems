// Question link :- https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// This code does not handles the case where the array contains duplicate elements.
// Refer to the code snippet from problem 154.cpp:

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findMin(vector<int>& nums) {
    int low = 0;
    int high = nums.size() - 1;

    // Either array is rotated by its length or it is not rotated.
    if (nums[low] <= nums[high])
      return nums[0];

    while (low <= high)
    {
      int mid = (low + high) / 2;
      if (nums[mid] > nums[mid + 1])
        return nums[mid + 1];
      else if (nums[mid] < nums[mid - 1])
        return nums[mid];
      // minimum element is always on the unsorted side of the mid element
      else if (nums[low] <= nums[mid])
        low = mid + 1;
      else
        high = mid - 1;
    }
    return -1;
  }
};