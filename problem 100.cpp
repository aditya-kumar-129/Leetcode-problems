// Question link :- https://leetcode.com/problems/same-tree/

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
  bool flag = true;
  bool isSameTree(TreeNode* p, TreeNode* q)
  {
    if (!p && !q)   // In case if the root values are null
      return true;
    if (p && q)
      return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    return false;
  }
};