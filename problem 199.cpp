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
  int maxLevel =0;
  void rightSide(TreeNode* root,int level)
  {
    if(!root)
      return ;
    if(maxLevel<level)
    {
      ans.push_back(root->val);
      maxLevel = level;
    }
    rightSide(root->right,level+1);
    rightSide(root->left,level+1);
  }
  vector<int> rightSideView(TreeNode* root) 
  {
    rightSide(root,1);
    return ans;
  }
};

// Brute force approach
// Space Complexity :- O(n)
class Solution {
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
  vector<int> rightSideView(TreeNode* root) 
  {
    vector<vector<int>> levelOrderTraversal = levelOrder(root);
    vector <int> ans;
    for(auto it : levelOrderTraversal)
    {
      vector <int > temp = it;
      ans.push_back(temp[temp.size()-1]);
    }
    return ans;
  }
};