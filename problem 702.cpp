// Question link :- https://leetcode.com/problems/insert-into-a-binary-search-tree/

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

// Recursive Approach
class Solution {
public:
  TreeNode* insertIntoBST(TreeNode* root, int value) {
    if (root == nullptr)
      return new TreeNode(value);

    else if (value < root->val)
      root->left = insertIntoBST(root->left, value);
    else
      root->right = insertIntoBST(root->right, value);
    return root;
  }
};

// Iterative Approach
class Solution {
public:
  TreeNode* insertIntoBST(TreeNode* root, int value) {
    if(!root)
      return new TreeNode(value);
    TreeNode *cur = root;
    while(true)
    {
      if(cur->val<=value)
      {
        if(cur->right)
          cur= cur->left;
        else
        {
          cur->right = new TreeNode (value);
          break;
        }
      }
      else
      {
        if(cur->left)
          cur = cur->left;
        else
        {
          cur->left = new TreeNode(value);
          break;
        }
      }
    }
    return root;
  }
};