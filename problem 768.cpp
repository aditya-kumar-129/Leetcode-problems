// Question link :- https://leetcode.com/problems/max-chunks-to-make-sorted-ii/
// Youtube link :-  https://www.youtube.com/watch?v=GxTo3agdnjs


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxChunksToSorted(vector<int>& arr)
  {
    vector <int> rightMin(arr.size() + 1);
    rightMin[rightMin.size()-1] = INT_MAX;
    for(int i=rightMin.size()-2;i>=0;i--)
      rightMin[i] = min(rightMin[i+1],arr[i]);

    int count =0;
    int leftMax = INT_MIN;

    for(int i=0;i<arr.size();i++)
    {
      leftMax = max(leftMax,arr[i]);
      if(leftMax<=rightMin[i+1])
        count++;
    }
    return count;
  }
};