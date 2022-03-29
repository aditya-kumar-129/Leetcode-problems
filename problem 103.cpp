// Question link :- https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
  vector<int> temp;
  queue <TreeNode*> mq, cq;
  int level = 1;
  vector<vector<int>> zigzagLevelOrder(TreeNode* root)
  {
    if(!root)
      return ans;
    mq.push(root);
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
        if (level % 2 == 1)
          ans.push_back(temp);
        else
        {
          reverse(temp.begin(), temp.end());
          ans.push_back(temp);
        }
        level++;
        mq = cq;
        queue <TreeNode*> change;
        swap(change, cq);
        temp.clear();
      }
    }
    return ans;
  }
};