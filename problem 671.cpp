// Question link :- https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/

// Heve a look on the below video:- 
// https://www.youtube.com/watch?v=zex8_82T46U

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
  int findSecondMinimumValue(TreeNode* root)
  {
    if(!root)
      return -1;
    if(!root->left && !root->right)
      return -1;
    auto left = root->left->val;
    auto right = root->right->val;

    if(root->val == root->left->val)
      left = findSecondMinimumValue(root->left);
    if (root->val == root->right->val)
      right = findSecondMinimumValue(root->right);

    if(left != -1 && right != -1)
      return min(left,right);
    else if (left != -1)
      return left;
    else
      return right;
  }
};

// Brute force approach

class Solution {
public:
  vector<int> ans;
  void inorderTraversal(TreeNode* root) {
    if (root != nullptr)
    {
      inorderTraversal(root->left);
      ans.push_back(root->val);
      inorderTraversal(root->right);
    }
  }
  int findSecondMinimumValue(TreeNode* root)
  {
    inorderTraversal(root);
    sort(ans.begin(), ans.end());
    for (int i = 0;i < ans.size() - 1;i++)
      if (ans[i] != ans[i + 1])
        return ans[i + 1];
    return -1;
  }
};

class Solution {
public:
  vector<int> ans;
  void inorderTraversal(TreeNode* root) {
    if (root != nullptr)
    {
      inorderTraversal(root->left);
      ans.push_back(root->val);
      inorderTraversal(root->right);
    }
  }
  int findSecondMinimumValue(TreeNode* root)
  {
    inorderTraversal(root);
    map<int, int> mp;
    for (int i = 0;i < ans.size();i++)
      mp[ans[i]]++;
    int count = 0;
    for (auto it : mp)
    {
      if (count == 1)
        return it.first;
      count++;
    }
    if (mp.size() < 2)
      return -1;
    return -1;
  }
};