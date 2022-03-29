// Question link :- https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  int first(vector<int>& a, int low, int high, int k) 
  {
    int index = -1;
    while (high >= low)
    {
      int mid = (low + high) / 2;
      if (a[mid] == k)
      {
        index = mid;
        high = mid - 1;       // TO check the leftmost position of the target if it exist in the left of the mid
      }
      else if (a[mid] > k)
        high = mid - 1;
      else if (a[mid] < k)
        low = mid + 1;
    }
    return index;
  }
  int last(vector<int>& a, int low, int high, int k)
  {
    int index = -1;
    while (high >= low)
    {
      int mid = (low + high) / 2;
      if (a[mid] == k)
      {
        index = mid;
        low = mid + 1;    // TO check the rightmost position of the target if it exist in the left of the mid
      }
      else if (a[mid] > k)
        high = mid - 1;
      else if (a[mid] < k)
        low = mid + 1;
    }
    return index;
  }
  vector<int> searchRange(vector<int>& a, int k) {
    int n = a.size() - 1;
    int first_index = first(a, 0, n, k);
    int last_index = last(a, 0, n, k);
    vector<int> v;
    v.push_back(first_index);
    v.push_back(last_index);
    return v;
  }
};