// Question link :- https://leetcode.com/problems/binary-tree-preorder-traversal/

#include<bits/stdc++.h>
using namespace std;
// PRE ORDER TRAVERSAL OF A BINARY TREE
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
  vector<int> ans;
  vector<int> preorderTraversal(TreeNode* root) {
    if (root != nullptr)
    {
      ans.push_back(root->val);
      preorderTraversal(root->left);
      preorderTraversal(root->right);
    }
    return ans;
  }
};