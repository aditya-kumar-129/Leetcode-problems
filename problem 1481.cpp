// Question link :- https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
    unordered_map<int, int> freqmap;
    // it arranges the number in ascending order
    priority_queue<int, vector<int>, greater<int>> minpq;

    for (auto n : arr)
      freqmap[n]++;

    for (auto it : freqmap)
      minpq.push(it.second);

    while (k > 0)
    {
      k -= minpq.top();
      if (k >= 0)
        minpq.pop();
    }
    return minpq.size();
  }
};