// Question link :- https://leetcode.com/problems/minimum-absolute-difference-in-bst/

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
  vector<int> temp;
  vector<int> inorderTraversal(TreeNode* root) {
    if (root != nullptr)
    {
      inorderTraversal(root->left);
      temp.push_back(root->val);
      inorderTraversal(root->right);
    }
    return temp;
  }
  int getMinimumDifference(TreeNode* root) {
    inorderTraversal(root);
    vector <int> ans;
    for(int i=0;i<temp.size()-1;i++)
      ans.push_back(abs(temp[i]-temp[i+1]));
    sort(ans.begin(),ans.end());
    return ans[0];
  }
};