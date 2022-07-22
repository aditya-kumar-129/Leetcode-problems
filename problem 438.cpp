// // Question link :- https://leetcode.com/problems/find-all-anagrams-in-a-string/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> findAnagrams(string str, string target)
  {
    vector<int> ans;
    map<char, int> targetWordFrequency;
    map<char, int> substringWordFrequency;

    if (target.size() > str.size())
      return ans;

    for (int i = 0; i < target.size();i++)
      substringWordFrequency[str[i]]++;

    for (auto it : target)
      targetWordFrequency[it]++;

    if (substringWordFrequency == targetWordFrequency)
      ans.push_back(0);

    for (int i = 1;i < str.size() - target.size() + 1;i++)
    {
      substringWordFrequency[str[i - 1]]--;
      if (substringWordFrequency[str[i - 1]] == 0)
        substringWordFrequency.erase(str[i - 1]);

      substringWordFrequency[str[i + target.size() - 1]]++;

      if (substringWordFrequency == targetWordFrequency)
        ans.push_back(i);
    }
    return ans;
  }
};