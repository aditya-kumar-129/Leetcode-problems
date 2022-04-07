// Question link :- https://leetcode.com/problems/find-the-duplicate-number/

#include<bits/stdc++.h>
using namespace std;

// Youtube video link to solve the problem  :-  https://www.youtube.com/watch?v=32Ll35mhWg0
// Optimised solution
class Solution {
public:
  int findDuplicate(vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];
    do{
      slow = nums[slow];
      fast = nums[nums[fast]];
    }while(slow!=fast);
    fast = nums[0];
    while(slow!=fast)
    {
      slow = nums[slow];
      fast = nums[fast];
    }
    return slow;
  }
};

// Brute force approach
class Solution {
public:
  int findDuplicate(vector<int>& nums) 
  {
    map<int,int> mp;
    for(int i=0;i<nums.size();i++)
      mp[nums[i]]++;
    int duplicate_number;
    for(auto it:mp){
      if(it.second>1)
      {
        duplicate_number = it.first;
        break;
      }
    }
    return duplicate_number;
  }
};