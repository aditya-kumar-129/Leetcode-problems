// Question link :- https://leetcode.com/problems/find-all-duplicates-in-an-array/

// WARNING :- This method works only when the numbers present in the array is in the range[0,n-1]
// WARNING :- You can't use array as a hashing by negating in thi case necuase that method is suitable when the elements are in the range [0,n] and the number of elements present in the array is n+2 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> findDuplicates(vector<int>& nums) {
    vector<int> ans;
    int n = nums.size();
    for (int i = 0;i < n;i++)
      nums[i]--;

    for (int i = 0;i < n;i++)
      nums[nums[i] % n] += n;
    for (int i = 0;i < n;i++)
    {
      if (nums[i] >= n * 2)
        ans.push_back(i + 1);
    }
    return ans;
  }
};