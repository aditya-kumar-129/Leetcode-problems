// Question link :- https://leetcode.com/problems/balanced-binary-tree/
// Youtube Video  :- https://www.youtube.com/watch?v=Yt50Jfbd8Po

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

// Brute force approach
// Time complexity :- O(N)^2
class Solution {
public:
  int heightOfTree(TreeNode* root)
  {
    if (!root)
      return 0;
    int lheight = heightOfTree(root->left);
    int rheight = heightOfTree(root->right);
    return 1 + max(lheight,rheight);
  }

  bool isBalanced(TreeNode* root)
  {
    if (!root)
      return true;
    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);
    if (abs(leftHeight - rightHeight) > 1)
      return false; 
    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    // if any of the left or right subtree return false then the tree is not a complete tree
    if(!left || !right)
      return false;
    return true;
  }
};

// Time complexity : - O(N)
// Optimised solution

class Solution {
public:
  int heightOfTree(TreeNode* root)
  {
    if (!root)
      return 0;
    int leftHeighOfTree = heightOfTree(root->left);
    if(leftHeighOfTree==-1)
      return -1;
    int rightHeighOfTree = heightOfTree(root->right);
    if (rightHeighOfTree == -1)
      return -1;
    if(abs(leftHeighOfTree-rightHeighOfTree)>1)
      return -1;
    return 1 + max(leftHeighOfTree,rightHeighOfTree);
  }
  bool isBalanced(TreeNode* root)
  {
    return heightOfTree(root) !=-1;
  }
};