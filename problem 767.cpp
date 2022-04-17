// Question link :- https://leetcode.com/problems/reorganize-string/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  string reorganizeString(string s)
  {
    map<char, int> mp;
    for (auto it : s)
      mp[it]++;

    // finding the character that occured maximum number of times
    int max_freq = -1;
    char max_char;
    for (auto it : mp)
    {
      if (it.second > max_freq)
      {
        max_freq = it.second;
        max_char = it.first;
      }
    }

    int size = s.size();
    if (max_freq > (size + 1) / 2)
      return "";
    // https://www.geeksforgeeks.org/create-a-string-of-specific-length-in-cpp/
    string res(size, ' ');

    // storing the maximum occured character at even positions 
    int index = 0;
    while (max_freq)
    {
      res[index] = max_char;
      index += 2;
      max_freq--;
    }
    // max_freq gets zero in the above while loop
    mp[max_char] = 0;
    // Storing the leftover charcters at remaining positions; first to even positions if not occupied otherwise at odd position
    for (auto it : mp)
    {
      while (mp[it.first])
      {
        index = (index >= size) ? 1 : index;
        res[index] = it.first;
        index += 2;
        mp[it.first]--;
      }
    }
    return res;
  }
};