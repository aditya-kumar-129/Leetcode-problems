// Question link :- https://leetcode.com/problems/check-if-the-sentence-is-pangram/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
  bool checkIfPangram(string sentence) {
    map<int, int> mp;
    for (int i = 0; i < sentence.size(); i++)
      mp[sentence[i]-'a']++;
    bool  flag = true;
    if(mp.size()<26)
      flag = false;
    return flag;
  }
};