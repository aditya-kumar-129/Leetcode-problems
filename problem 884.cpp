// Question link :- https://leetcode.com/problems/uncommon-words-from-two-sentences/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<string> uncommonFromSentences(string s1, string s2) {
    map<string, int> mp;
    string word = "";
    vector <string> ans;
    // storing the words in map
    // Added the extra space at the end so that the last wprd will also be stored in the array 
    s1 += " ";
    for (int i = 0;i < s1.size();i++)
    {
      if (s1[i] != ' ')
        word += s1[i];
      else
      {
        mp[word]++;
        word = "";
      }
    }
    // Added the extra space at the end so that the last wprd will also be stored in the array 
    s2+=" ";
    word = "";
    for (int i = 0;i < s2.size();i++)
    {
      if (s2[i] != ' ')
        word += s2[i];
      else
      {
        mp[word]++;
        word = "";
      }
    }
    for (auto it : mp)
      if (it.second == 1)
        ans.push_back(it.first);
    return ans;
  }
};