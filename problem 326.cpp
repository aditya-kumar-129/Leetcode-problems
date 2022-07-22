// Question link :- https://leetcode.com/problems/power-of-three/

// Refer the below article for more understanding :-
// https://www.geeksforgeeks.org/find-whether-given-integer-power-3-not/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isPowerOfThree(int n) {
    return (n > 0 && 1162261467 % n == 0);
  }
};

// Below does not work 
// Reason IDK

class Solution {
public:
  double logn(int n, int r) {
    return log(n) / log(r);
  }
  bool isPowerOfThree(int n) {
    if (n == 0)
      return false;
    return(ceil(logn(n, 3)) == floor(logn(n, 3)));
  }
};