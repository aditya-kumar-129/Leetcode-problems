// Question link :- https://leetcode.com/problems/combination-sum-ii/

#include<bits/stdc++.h>
using namespace std;

// OPTIMISED APPROACH
class Solution {
public:
  void findCombination(vector<vector<int>>& ans, int ind, int target, vector<int>& temp, const vector<int>& arr)
  {
    if (target == 0)
    {
      ans.push_back(temp);
      return;
    }
    for (int i = ind;i < arr.size();i++)
    {
      if (arr[i] > target)
        break;
      if (i > ind && arr[i] == arr[i - 1])
        continue;
      temp.push_back(arr[i]);
      findCombination(ans, i + 1, target - arr[i], temp, arr);
      temp.pop_back();
    }
  }
  vector<vector<int>> combinationSum2(vector<int>& arr, int target)
  {
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> temp;
    findCombination(ans, 0, target, temp, arr);
    return ans;
  }
};


// Brute force Approach
class Solution {
public:
  void findNumbers(int index, int target, vector<int>& arr, vector<vector<int> >& ans, vector<int>& r)
  {
    if (index == arr.size())
    {
      if (target == 0)
        ans.push_back(r);
      return;
    }

    // if the arr element is picked 
    if (arr[index] <= target)
    {
      r.push_back(arr[index]);
      findNumbers(index + 1, target - arr[index], arr, ans, r);
      r.pop_back();
    }
    // if the arr element is not picked 
    findNumbers(index + 1, target, arr, ans, r);
  }
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
  {
    sort(candidates.begin(), candidates.end());
    vector<int> r;
    vector<vector<int> > ans;
    set<vector<int>> s;
    findNumbers(0, target, candidates, ans, r);
    for (auto it : ans)
      s.insert(it);
    ans.clear();
    for (auto it : s)
      ans.push_back(it);
    return ans;
  }
};