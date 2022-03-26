#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
  {
    intervals.push_back(newInterval);
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());
    vector<int> intermediate_pair;
    int second_term;
    for (auto it : intervals)
    {
      if (intermediate_pair.size() == 0)
      {
        intermediate_pair.push_back(it[0]);
        second_term = it[1];
      }
      else if (second_term >= it[0])
      {
        if (second_term > it[1])
          second_term = second_term;
        else
          second_term = it[1];
      }
      else
      {
        intermediate_pair.push_back(second_term);
        ans.push_back(intermediate_pair);
        intermediate_pair.clear();
        intermediate_pair.push_back(it[0]);
        second_term = it[1];
      }
    }
    intermediate_pair.push_back(second_term);
    ans.push_back(intermediate_pair);
    return ans;
  }
};