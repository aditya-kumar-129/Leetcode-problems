// Question link :- https://leetcode.com/problems/find-largest-value-in-each-tree-row/

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

// Optimised Solution
class Solution {
public:
  void helper(vector<int>& res, TreeNode* root, int level)
  {
    if (!root)
      return;
    if (level == res.size())
      res.push_back(root->val);
    else
      res[level] = max(res[level], root->val);
    helper(res, root->left, level + 1);
    helper(res, root->right, level + 1);
  }
  vector<int> largestValues(TreeNode* root) {
    vector<int> res;
    helper(res, root, 0);
    return res;
  }
};

// Brute Force Approach
class Solution {
public:
  vector<int> largestValues(TreeNode* root) {
    vector<int> ans;
    if (!root)
      return ans;
    queue<TreeNode*> mq, cq;
    mq.push(root);
    vector<int> temp;
    while (!mq.empty())
    {
      auto tempNode = mq.front();
      temp.push_back(tempNode->val);
      mq.pop();
      if (tempNode->left)
        cq.push(tempNode->left);
      if (tempNode->right)
        cq.push(tempNode->right);
      if (mq.empty())
      {
        sort(temp.begin(), temp.end());
        ans.push_back(temp[temp.size() - 1]);
        mq = cq;
        queue<TreeNode* > change;
        swap(cq, change);
        temp.clear();
      }
    }
    return ans;
  }
};