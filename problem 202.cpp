// Question link :- https://leetcode.com/problems/happy-number/

#include<bits/stdc++.h>
using namespace std;

// Optimised Solution 
// Time Complexity: O(n*log(n))
// Space Complexity :- O(1)

class Solution {
public:
  int numSquareSum(int n) {
    int totalSum = 0;
    while (n > 0) {
      int d = n % 10;
      n = n / 10;
      totalSum += d * d;
    }
    return totalSum;
  }

  // Basically we are using slow and fast pointer method to check if their is any loop exist OR NOT
  bool isHappy(int n) {
    int slow, fast;
    slow = fast = n;
    do
    {
      slow = numSquareSum(slow);
      fast = numSquareSum(numSquareSum(fast));
    } while (slow != fast);
    return (slow == 1);
  }
};

// Brute Force Approach
// Time Complexity: O(n*log(n))
// Space Complexity :- O(n)
// Watch the below video to get to know why we have used set here 
// or just take the example of 29 and do DRY RUN
// youtube video :- https://youtu.be/Egw03gI-Tf0
class Solution {
public:
  int getNext(int n) {
    int totalSum = 0;
    while (n > 0) {
      int d = n % 10;
      n = n / 10;
      totalSum += d * d;
    }
    return totalSum;
  }

  bool isHappy(int n) {
    set<int> seen;
    while (n != 1 && seen.find(n) == seen.end()) {
      seen.insert(n);
      n = getNext(n);
    }
    return n == 1;
  }
};