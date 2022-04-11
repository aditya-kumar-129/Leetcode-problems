// Question link :- https://leetcode.com/problems/deepest-leaves-sum/

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
// Spcae Complexity :- O(1)
class Solution {
public:
  int maxLevelSum =0;
  int levelOrder(TreeNode* root)
  {
    if (!root)
      return 0;
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
        int sum = 0;
        for (int i = 0;i < temp.size();i++)
          sum += temp[i];
        maxLevelSum = sum;
        mq = cq;
        queue<TreeNode* > change;
        swap(cq, change);
        temp.clear();
      }
    }
    return maxLevelSum;
  }
  int deepestLeavesSum(TreeNode* root) {
    levelOrder(root);
    return maxLevelSum;
  }
};


// Brute force Approach
// Spcae Complexity :- O(h) wheight h is the height of a binary tree
class Solution {
public:
  vector<int> ans;
  vector<int> levelOrder(TreeNode* root)
  {
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
        int sum =0;
        for(int i=0;i<temp.size();i++)
          sum+=temp[i];
        ans.push_back(sum);
        mq = cq;
        queue<TreeNode* > change;
        swap(cq, change);
        temp.clear();
      }
    }
    return ans;
  }
  int deepestLeavesSum(TreeNode* root) {
    levelOrder(root);
    return ans[ans.size()-1];
  }
};