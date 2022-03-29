// Question link :- https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

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
  vector<int> levelOrder(TreeNode* root)
  {
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
  int maxLevelSum(TreeNode* root) 
  {
    vector <int> ans = levelOrder(root);
    int max = INT_MIN;
    int index = -1;
    for(int i=0;i<ans.size();i++)
    {
      if(max<ans[i])
      {
        index = i;
        max = ans[i];
      }
    }
    for(auto it:ans)
      cout<<it<<" ";
    return index+1;
  }
};