// Question link :- https://leetcode.com/problems/binary-tree-right-side-view/

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

// Optimised solution
class Solution {
public:
  vector<int> ans;
  void rightSide(TreeNode* root, int level)
  {
    if (!root)
      return;
    if (ans.size() == level)
      ans.push_back(root->val);
    rightSide(root->right, level + 1);
    rightSide(root->left, level + 1);
  }
  vector<int> rightSideView(TreeNode* root)
  {
    rightSide(root, 0);
    return ans;
  }
};

// Brute force approach
// Space Complexity :- O(n)
class Solution {
public:
  vector<int> rightSideView(TreeNode* root)
  {
    vector<int> ans;
    if (!root)
      return ans;
    queue<TreeNode*> mq;
    mq.push(root);
    while (!mq.empty())
    {
      int size = mq.size();
      while (size--)
      {
        auto tempNode = mq.front();
        mq.pop();

        if (size == 0)
          ans.push_back(tempNode->val);

        if (tempNode->left)
          mq.push(tempNode->left);
        if (tempNode->right)
          mq.push(tempNode->right);
      }
    }
    return ans;
  }
};