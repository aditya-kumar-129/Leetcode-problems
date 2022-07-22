// Question link :- https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findMin(vector<int>& arr) {
    int low = 0;
    int high = arr.size() - 1;

    while (low < high)
    {
      int mid = low + (high - low) / 2;
      if (arr[mid] == arr[high])
        high--;
      // second half is unsorted so minimum element is on the second half
      else if (arr[mid] > arr[high])
        low = mid + 1;
      // first half is unsorted so minimum element is on the first half
      else
        high = mid;
    }
    return arr[high];
  }
};