// Question link :- https://leetcode.com/problems/kth-largest-element-in-an-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pq;
    for (int num : nums)
      pq.push(num);
    int front;
    while (k > 0)
    {
      front = pq.top();
      pq.pop();
      k--;
    }
    return front;
  }
};