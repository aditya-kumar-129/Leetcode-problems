// Question link :- https://leetcode.com/problems/diameter-of-binary-tree/
// Youtube Link:- https://www.youtube.com/watch?v=Rezetez59Nk

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

// Optimised Approach
// Time Complexity:- O(n)

class Solution {
public:
  int height(TreeNode* node, int& diameter) {
    if (!node)
      return 0;

    int lh = height(node->left, diameter);
    int rh = height(node->right, diameter);
    diameter = max(diameter, lh + rh);
    return node->val + max(lh, rh);
  }

  int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    height(root, diameter);
    return diameter;
  }
};

// Brute Force Approach
// Time Complexity:- O(n^2)

class Solution {
public:
  int height(TreeNode* node)
  {
    if (!node)
      return 0;
    int ldepth = height(node->left);
    int rdepth = height(node->right);
    return 1 + max(ldepth, rdepth);
  }

  int diameterOfBinaryTree(TreeNode* tree) {
    if (!tree)
      return 0;
    int lheight = height(tree->left);
    int rheight = height(tree->right);
    // The path does not need to pass through the root that why we are calling the below recursive calls 
    int ldiameter = diameterOfBinaryTree(tree->left);
    int rdiameter = diameterOfBinaryTree(tree->right);

    return max(lheight + rheight, max(ldiameter, rdiameter));
  }
};