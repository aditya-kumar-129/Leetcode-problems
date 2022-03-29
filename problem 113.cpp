// Question link :- https://leetcode.com/problems/path-sum-ii/

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
  vector<vector<int>> ans;
  vector<vector<int>> pathSum(TreeNode* root, int targetSum)
  {
    if (!root)
      return ans;
    vector <int> temp;
    DFS(root, temp, 0, targetSum);
    return ans;
  }
  void DFS(TreeNode* root, vector <int> temp, int num, int targetSum)
  {
    if (!root)
      return;
    num += root->val;
    temp.push_back(root->val);
    if (!root->left && !root->right && num == targetSum)
    {
        ans.push_back(temp);
        return;
    }
    DFS(root->left, temp, num, targetSum);
    DFS(root->right, temp, num, targetSum);
  }
};