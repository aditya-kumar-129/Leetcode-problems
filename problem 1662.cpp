// Question link :- https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    string str1;
    for (int i = 0;i < word1.size();i++)
      str1 += word1[i];
    string str2;
    for (int i = 0;i < word2.size();i++)
      str2 += word2[i];
    if (str1.compare(str2) == 0)
      return true;
    return false;
  }
};