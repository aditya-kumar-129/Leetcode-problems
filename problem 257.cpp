// Question link :- https://leetcode.com/problems/binary-tree-paths/

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
  vector<string> ans;
  vector<string> binaryTreePaths(TreeNode* root)
  {
    if (!root)
      return ans;
    dfs(root, "");
    return ans;
  }
  void dfs(TreeNode* root, string temp)
  {
    if (!root)
      return;
    if (temp.length() == 0)
      temp += to_string(root->val);
    else
    {
      temp += "->";
      temp += to_string(root->val);
    }
    if (!root->left && !root->right)
    {
      ans.push_back(temp);
      return;
    }
    dfs(root->left, temp);
    dfs(root->right, temp);
  }
};