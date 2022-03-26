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
  bool flag = false;
  bool hasPathSum(TreeNode* root, int targetSum)
  {
    if (!root)
      return false;
    DFS(root, 0, targetSum);
    if(flag)
      return true;
    else
      return false;
  }
  void DFS(TreeNode* root, int num, int targetSum)
  {
    if (!root)
      return;
    num += root->val;
    if (!root->left && !root->right)
    {
      if (num == targetSum)
      {
        flag = true;
        return;
      }
    }
    DFS(root->left, num, targetSum);
    DFS(root->right, num, targetSum);
  }
};