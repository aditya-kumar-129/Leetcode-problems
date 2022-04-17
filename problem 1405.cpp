// Question link :- https://leetcode.com/problems/longest-happy-string/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  string longestDiverseString(int x, int y, int z) {
    string result = "";
    vector<char> charMap = { 'a', 'b', 'c' };
    priority_queue<vector<int>> maxHeap;
    // Push given count of 'a', 'b' and 'c' if they are non zero.
    if (x > 0)
      maxHeap.push({ x, 0 });
    if (y > 0)
      maxHeap.push({ y, 1 });
    if (z > 0)
      maxHeap.push({ z, 2 });

    while (maxHeap.size() >= 2)
    {
      vector<int> first = maxHeap.top();
      maxHeap.pop();
      vector<int> second = maxHeap.top();
      maxHeap.pop();
      // Add the character with maximum current count two times if possible.
      for (int i = 0; i < 2; i++)
      {
        if (first[0] != 0)
        {
          result.push_back(charMap[first[1]]);
          first[0]--;
        }
      }
      // If count of second popped element becomes more than count of first, then add this character two times.
      if (second[0] > first[0] && second[0] > 2)
      {
        result.push_back(charMap[second[1]]);
        result.push_back(charMap[second[1]]);
        second[0] -= 2;
      }
      // Else add second character one time only. 
      else
      {
        result.push_back(charMap[second[1]]);
        second[0] -= 1;
      }
      // If count of first and second element do not become zero then push them back into the heap.
      if (first[0] > 0)
        maxHeap.push(first);
      if (second[0] > 0)
        maxHeap.push(second);
    }
    // If heap still contain one element then we can add this character at most 2 times.
    if (maxHeap.size() != 0)
    {
      vector<int> first = maxHeap.top();
      for (int i = 0; i < 2; i++)
      {
        if (first[0] != 0)
        {
          result.push_back(charMap[first[1]]);
          first[0]--;
        }
      }
    }
    return result;
  }
};