// Question link :- https://leetcode.com/problems/product-of-array-except-self/

#include<bits/stdc++.h>
using namespace std;

// A more simpler method
class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> ans;
    int n = nums.size();
    if (n == 1) {
      ans.push_back(0);
      return ans;
    }
    vector<int> left(n);
    vector<int> right(n);
    vector<int> product(n);
    left[0]=1;
    right[n - 1] = 1;

    for (int i = 1;i < n;i++)
      left[i] = nums[i - 1] * left[i - 1];

    for (int i = n - 2;i>=0;i--)
      right[i] = nums[i + 1] * right[i + 1];

    for (int i = 0; i < n; i++)
      product[i] = left[i] * right[i];
    return product;
  }
};

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    long prod = 1;
    long flag = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
      if (nums[i] == 0)
        flag++;
      else
        prod *= nums[i];
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
      // if there is more than one 0 in the array then it doesn't matter what whether we have zero at the current index or not because the other zeroes present will make the overall product zero
      if (flag > 1)
        ans[i] = 0;
      // if there is only no 0 in the array then we can use the product of the array except the current index
      else if (flag == 0)
        ans[i] = (prod / nums[i]);
      // if there is only one 0 in the array and the current element is not zero then all the other indexes values will become zero
      else if (flag == 1 && nums[i] != 0)
        ans[i] = 0;
      // if there is only one 0 in the array and the current element is not zero then the value at the current index is equal to the product of the array except the current index
      else
        ans[i] = prod;
    }
    return ans;
  }
};