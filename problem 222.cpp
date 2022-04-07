// Question link :- https://leetcode.com/problems/count-complete-tree-nodes/

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
  int left_height(TreeNode* node)
  {
    int ht = 0;
    while (node) {
      ht++;
      node = node->left;
    }
    return ht;
  }

  int right_height(TreeNode* node)
  {
    int ht = 0;
    while (node) {
      ht++;
      node = node->right;
    }
    return ht;
  }

  int countNodes(TreeNode* root) {
    if (!root)
      return 0;
    int leftHeight = left_height(root);
    int rightHeight = right_height(root);
    if (leftHeight == rightHeight)
      return pow(2, leftHeight) - 1;
    else
      return 1 + countNodes(root->left) + countNodes(root->right);
  }
};