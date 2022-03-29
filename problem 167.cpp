// Question link :- https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target)
  {
    vector<int> ans;
    int i = 0, j = numbers.size() - 1;
    while (i < j)
    {
      if (numbers[i] + numbers[j] == target)
      {
        ans.push_back(i + 1);
        ans.push_back(j + 1);
      }
      else if (numbers[i] + numbers[j] > target)
        j--;
      else
        i++;
    }
    return ans;
  }
};