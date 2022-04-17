// Question link :- https://leetcode.com/problems/largest-multiple-of-three/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  string largestMultipleOfThree(vector<int>& digits)
  {
    int n = digits.size();
    int sum = 0;
    for (int i = 0;i < n;i++)
      sum += digits[i];
    sort(digits.begin(), digits.end());

    // If sum is divisible by 3
    if (sum % 3 == 0)
    {
      if (digits[n - 1] == 0)
        return "0";
      string ans = "";
      for (int i = n - 1;i >= 0;i--)
        ans += to_string(digits[i]);
      return ans;
    }
    // If on dividing the sum it gives 1 as the remainder then :- 
    else if (sum % 3 == 1)
    {
      bool one_Number_With_Remainder_One_Found = false;
      for (int i = 0;i < n;i++)
      {
        if (digits[i] % 3 == 1)
        {
          one_Number_With_Remainder_One_Found = true;
          digits[i] = -1;
          break;
        }
      }
      if (digits.size() == 1 && one_Number_With_Remainder_One_Found)
        return "";
      if (!one_Number_With_Remainder_One_Found)
      {
        vector<int> find_Two_Number_With_Remainder_Two;
        for (int i = 0;i < n;i++)
        {
          if (digits[i] % 3 == 2)
          {
            find_Two_Number_With_Remainder_Two.push_back(digits[i]);
            digits[i] = -1;
            if (find_Two_Number_With_Remainder_Two.size() == 2)
              break;
          }
        }
        if (find_Two_Number_With_Remainder_Two.size() != 2)
          return "";
      }
    }
    else
    {
      bool one_Number_With_Remainder_Two_Found = false;
      for (int i = 0;i < n;i++)
      {
        if (digits[i] % 3 == 2)
        {
          one_Number_With_Remainder_Two_Found = true;
          digits[i] = -1;
          break;
        }
      }
      if (digits.size() == 1 && one_Number_With_Remainder_Two_Found)
        return "";
      if (!one_Number_With_Remainder_Two_Found)
      {
        vector<int> find_Two_Number_With_Remainder_One;
        for (int i = 0;i < n;i++)
        {
          if (digits[i] % 3 == 1)
          {
            find_Two_Number_With_Remainder_One.push_back(digits[i]);
            digits[i] = -1;
            if (find_Two_Number_With_Remainder_One.size() == 2)
              break;
          }
        }
        if (find_Two_Number_With_Remainder_One.size() != 2)
          return "";
      }
    }
    string ans = "";
    for (int i = n - 1;i >= 0;i--)
      if (digits[i] != -1)
        ans += to_string(digits[i]);
    int count = 0;
    for (int i = 0;i < ans.size();i++)
      if (ans[i] == '0')
        count++;
    if (count == ans.size() && ans.size() > 0)
      return "0";
    return ans;
  }
};