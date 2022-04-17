// Question link :- https://leetcode.com/problems/monotone-increasing-digits/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int monotoneIncreasingDigits(int n) 
  {
    string s = to_string(n);
    int size = s.size();
    int i=1;
    // Move until a cliff is found
    while(i<size && s[i]>=s[i-1])
      i++;

    // Once you get a cliff decrease the previous value untill you get rid of it
    while(i>0 && i<size && s[i-1] > s[i])
    {
      s[i-1]--;
      i--;
    }

    for(int j=i+1;j<size;j++)
      s[j] = '9';
      
    return stoi(s);
  }
};