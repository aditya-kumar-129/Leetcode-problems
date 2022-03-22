#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
    int len1 = a.size(), len2 = b.size();

    if (len1 > len2)
      return findMedianSortedArrays(b, a);

    int low = 0;
    int high = len1;
    int total_length = len1 + len2;

    while (low <= high)
    {
      int mid = (low + high) / 2;
      int aleft = mid;
      int bleft = (total_length + 1) / 2 - aleft;   // because median divides the array into two equal halves

      int alm1 = (aleft == 0) ? INT_MIN : a[aleft - 1];
      int al = (aleft == len1) ? INT_MAX : a[aleft];
      int blm1 = (bleft == 0) ? INT_MIN : b[bleft - 1];
      int bl = (bleft == len2) ? INT_MAX : b[bleft];

      if (alm1 <= bl && blm1 <= al)
      {
        double median;
        if (total_length % 2 == 0)    // When the total length is even  
          median = (max(alm1, blm1) + min(al, bl)) / 2.0;
        else                        // When the total length is odd
          median = max(alm1, blm1);
        return median;
      }

      else if (alm1 > bl)
        high = mid - 1;
      else if (blm1 > al)
        low = mid + 1;
    }
    return 0.0;
  }
};