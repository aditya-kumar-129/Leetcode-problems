// Question link :- https://leetcode.com/problems/max-chunks-to-make-sorted/
// Youtube link :-  https://www.youtube.com/watch?v=XZueXHOhO5E


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxChunksToSorted(vector<int>& arr) 
  {
    int max_reach = -1;
    int count= 0;
    for(int i =0;i<arr.size();i++)
    {
      max_reach = max(arr[i],max_reach);
      if(max_reach == i)
        count++;
    }
    return count;
  }
};