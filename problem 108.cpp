// Question link :- https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  TreeNode* help(vector<int>& v, int start, int end) {
    if (start > end) 
      return nullptr;
    int mid = (start + end) / 2;
    TreeNode* node = new TreeNode(v[mid]);
    node->left = help(v, start, mid - 1);
    node->right = help(v, mid + 1, end);
    return node;
  }
  TreeNode* sortedArrayToBST(vector<int>& nums) 
  {
    int start = 0, end = nums.size() - 1;
    return help(nums, start, end);
  }
};