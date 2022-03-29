// Question link :- https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/

#include<bits/stdc++.h>
using namespace std;

// Passes all the test cases
class Solution {
public:
  static bool cmp(string& a, string& b)
  {
    if (a.size() == b.size())
      return a < b;
    return a.size() < b.size();
  }
  string kthLargestNumber(vector<string>& nums, int k)
  {
    sort(nums.begin(), nums.end(), cmp);
    reverse(nums.begin(), nums.end());
    return nums[k - 1];
  }
};


// class Solution 
// {
// public:
//   string kthLargestNumber(vector<string>& nums, int k) {
//     vector <long long int> temp;
//     for (int i = 0;i < nums.size();i++)
//     {
//       string str = nums[i];
//       int num = stoll(str);
//       temp.push_back(num);
//     }
//     sort(temp.begin(), temp.end());
//     reverse(temp.begin(), temp.end());
//     int kthValue = temp[k - 1];
//     string ans = to_string(kthValue);
//     return ans;
//   }
// };

// test case not satisfied in the above method are:- 
// ["623986800","3","887298","695","794","6888794705","269409","59930972","723091307","726368","8028385786","378585"]
// 11

