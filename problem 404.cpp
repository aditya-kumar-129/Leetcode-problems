// Question link :- https://leetcode.com/problems/sum-of-left-leaves/

#include<bits/stdc++.h>
using namespace std;

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
  void helper(TreeNode* root, int& sum, bool flag)
  {
    if (!root)
      return;
    if (!root->left && !root->right && flag == true)
      sum += root->val;
    helper(root->left, sum, true);
    helper(root->right, sum, false);
  }
  int sumOfLeftLeaves(TreeNode* root) {
    int sum = 0;
    helper(root->left, sum, true);
    helper(root->right, sum, false);
    return sum;
  }
};