// Question link :- https://leetcode.com/problems/palindrome-number/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0)
      return false;
    string num = to_string(x);
    int left = 0, right = num.size() - 1;
    while (left <= right)
    {
      if (num[left] != num[right])
        return false;
      left++;
      right--;
    }
    return true;
  }
};