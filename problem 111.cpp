// Question link :- https://leetcode.com/problems/minimum-depth-of-binary-tree/

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
  int minDepth(TreeNode* root)
  {
    if (!root)
      return 0;
    int ldepth = minDepth(root->left);
    int rdepth = minDepth(root->right);
    if(ldepth==0 || rdepth == 0)
      return 1+max(ldepth,rdepth);
    return 1 + min(ldepth, rdepth);
  }
};