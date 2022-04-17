// Question link :- https://leetcode.com/problems/smallest-value-of-the-rearranged-number/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long smallestNumber(long long num) {
    vector <int> digits;
    if (num == 0)
      return 0;
    else if (num < 0)
    {
      string s = to_string(-num);
      // https://www.geeksforgeeks.org/vector-rbegin-and-rend-function-in-c-stl/
      sort(s.rbegin(), s.rend());
      return -stoll(s);
    }
    else
    {
      string s = to_string(num);
      sort(s.begin(), s.end());
      int i = 0;
      while (s[i] == '0')
        i++;
      swap(s[0], s[i]);
      return stoll(s);
    }
    return 0;
  }
};