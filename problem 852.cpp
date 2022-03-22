#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int peakIndexInMountainArray(vector<int>& arr)
  {
    int low = 0;
    int high = arr.size();
    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
        return mid;
      else if (arr[mid] < arr[mid + 1])
        low = mid + 1;
      else
        high = mid - 1;
    }
    return -1;
  }
};