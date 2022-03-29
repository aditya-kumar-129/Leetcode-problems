// Question link :- https://leetcode.com/problems/unique-morse-code-words/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  int uniqueMorseRepresentations(vector<string>& words) {
    string arr[26] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
    map<string, int> m;
    for (int i = 0;i < words.size();i++)
    {
      string temp;
      string word = words[i];
      for (int j = 0;j < word.length();j++)
      {
        string morse = arr[word[j] - 'a'];
        temp += morse;
      }
      m[temp]++;
    }
    return m.size();
  }
};