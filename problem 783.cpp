// Question link :- https://leetcode.com/problems/minimum-distance-between-bst-nodes/

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
  vector<int> ans;
  vector<int> inorderTraversal(TreeNode* root)
  {
    if (root != nullptr)
    {
      inorderTraversal(root->left);
      ans.push_back(root->val);
      inorderTraversal(root->right);
    }
    return ans;
  }
  int minDiffInBST(TreeNode* root)
  {
    inorderTraversal(root);
    int result = 5000;
    for (int i = 0;i < ans.size() - 1;i++)
      result = min(result, abs(ans[i] - ans[i + 1]));
    return result;
  }
};