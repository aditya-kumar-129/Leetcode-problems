// Question link :- https://leetcode.com/problems/maximum-swap/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maximumSwap(int num) {
    int max_digit = -1;
    int max_digit_indx = -1;
    int l_indx = -1;
    int r_indx = -1;
    string num_in_str = to_string(num);
    for (int i = num_in_str.size() - 1; i >= 0; i--)
    {
      if (num_in_str[i] > max_digit)
      {
        max_digit = num_in_str[i];
        max_digit_indx = i;
        continue;
      }
      if (num_in_str[i] < max_digit)
      {
        l_indx = i;
        r_indx = max_digit_indx;
      }
    }
    if (l_indx == -1)
      return num;
    swap(num_in_str[l_indx], num_in_str[r_indx]);
    return stoi(num_in_str);
  }
};
