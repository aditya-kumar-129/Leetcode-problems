// Question link :- https://leetcode.com/problems/find-mode-in-binary-search-tree/

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
  map <int, int> mp;
  void inorderTraversal(TreeNode* root) {
    if (root != nullptr)
    {
      inorderTraversal(root->left);
      mp[root->val]++;
      inorderTraversal(root->right);
    }
  }
  vector<int> findMode(TreeNode* root)
  {
    vector<int> ans;
    inorderTraversal(root);
    int max_frequency = -1;
    for(auto it :mp)
      max_frequency = max(max_frequency,it.second);
    for(auto it :mp)
      if(it.second == max_frequency)
        ans.push_back(it.first);
    return ans;
  }
};