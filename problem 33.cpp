// Question link :- https://leetcode.com/problems/search-in-rotated-sorted-array/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int search1(vector <int> A, int l, int h, int key)
  {
    if (l > h)
      return -1;
    int mid = (l + h) / 2;
    if (A[mid] == key)
      return mid;
    //If left part is sorted
    if (A[l] <= A[mid])
    {
      if (key >= A[l] && key <= A[mid])
        return search1(A, l, mid - 1, key);
      return search1(A, mid + 1, h, key);
    }
    //if right part is sorted
    else
    {
      if (key >= A[mid] && key <= A[h])
        return search1(A, mid + 1, h, key);
      return search1(A, l, mid - 1, key);
    }
  }
  int search(vector<int>& nums, int target) {
    return search1(nums, 0, nums.size() - 1, target);
  }
};