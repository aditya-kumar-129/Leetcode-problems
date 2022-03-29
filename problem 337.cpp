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
          sum += temp[i];
        ans.push_back(sum);
        mq = cq;
        queue<TreeNode* > change;
        swap(cq, change);
        temp.clear();
      }
    }
    return ans;
  }
  int rob(TreeNode* root)
  {
    int sum_odd =0;
    int sum_even =0;
    for(int i=0;i<ans.size();i++)
    {
      if(i%2==0)
        sum_even+=ans[i];
      else
      sum_odd+=ans[i];
    }
    return max(sum_even,sum_odd);
  }
};