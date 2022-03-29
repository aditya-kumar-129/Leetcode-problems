// Question link :- https://leetcode.com/problems/binary-tree-level-order-traversal/

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

class Solution 
{
public:
  vector<vector<int>> levelOrder(TreeNode* root)
  {
    vector<vector<int>> ans;
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
        ans.push_back(temp);
        mq = cq;
        queue<TreeNode* > change;
        swap(cq, change);
        temp.clear();
      }
    }
    return ans;
  }
};