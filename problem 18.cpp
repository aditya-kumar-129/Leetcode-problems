#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target)
  {
    vector<vector<int>> ans;
    if (nums.size() < 4)
      return ans;
    sort(nums.begin(), nums.end());
    for (int i = 0;i < nums.size() - 3;i++)
    {
      for (int j = i + 1;j < nums.size() - 2;j++)
      {
        int left = j + 1, right = nums.size() - 1;
        int target_2 = target - nums[i] - nums[j];
        while (left < right)
        {
          if (nums[left] + nums[right] == target_2)
          {
            vector <int> temp;
            temp.push_back(nums[i]);
            temp.push_back(nums[j]);
            temp.push_back(nums[left]);
            temp.push_back(nums[right]);
            ans.push_back(temp);
            while (left < right && nums[left] == temp[2]) left++;
            while (left < right && nums[right] == temp[3]) right--;
          }
          else if (nums[left] + nums[right] > target_2)
            right--;
          else
            left++;
        }
        while (j + 1 < nums.size() && nums[j] == nums[j + 1]) j++;
      }
      while (i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
    }
    return ans;
  }
};