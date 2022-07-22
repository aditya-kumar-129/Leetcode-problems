// Question link :- https://leetcode.com/problems/boundary-of-binary-tree/
// CodeStudio Link :- https://www.codingninjas.com/codestudio/problems/boundary-traversal_790725
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
  bool isLeaf(TreeNode* root) {
    return !root->left && !root->right;
  }
  void addLeftBoundary(TreeNode* root, vector < int >& res) {
    TreeNode* cur = root->left;
    while (cur) {
      if (!isLeaf(cur)) res.push_back(cur->val);
      if (cur->left) cur = cur->left;
      else cur = cur->right;
    }
  }
  void addRightBoundary(TreeNode* root, vector < int >& res) {
    TreeNode* cur = root->right;
    vector < int > tmp;
    while (cur) {
      if (!isLeaf(cur)) tmp.push_back(cur->val);
      if (cur->right) cur = cur->right;
      else cur = cur->left;
    }
    for (int i = tmp.size() - 1; i >= 0; --i)
      res.push_back(tmp[i]);
  }
  void addLeaves(TreeNode* root, vector < int >& res) {
    if (isLeaf(root)) {
      res.push_back(root->val);
      return;
    }
    if (root->left) addLeaves(root->left, res);
    if (root->right) addLeaves(root->right, res);
  }
  vector<int> boundaryOfBinaryTree(TreeNode* root) {
    vector < int > res;
    if (!root) return res;
    if (!isLeaf(root)) res.push_back(root->val);
    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);
    return res;
  }
};