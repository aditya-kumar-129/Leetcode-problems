#include<bits/stdc++.h>
using namespace std;
// POST ORDER TRAVERSAL OF A BINARY TREE
// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// INT_MIN:
// Minimum value for an object of type int
// Value of INT_MIN is - 32767 (-215 + 1) or less

// INT_MAX :
// Maximum value for an object of type int
// Value of INT_MAX is 32767 (215 - 1) or greater

// LONG_MIN:
// Minimum value for an object of type long int
// Value of LONG_MIN is - 2147483647 (-231 + 1) or less *

// LONG_MAX :
// Maximum value for an object of type long int
// Value of LONG_MAX is 2147483647 (231 - 1) or greater *

class Solution {
public:
  int check(TreeNode* node, long min, long max)
  {
    if (node == NULL)
      return 1;
    if (node->val <= min || node->val >= max)
      return 0;
    return
      check(node->left, min, node->val) && check(node->right, node->val, max);
  }
  bool isValidBST(TreeNode* root)
  {
    return check(root, LONG_MIN, LONG_MAX);
  }
};

// Below method is not correct as it just compares its just neighbouring left node and right node
// bool isValidBST(TreeNode* root)
// {
//   bool flag = true;
//   if (root)
//   {
//     if (root->left != NULL && root->right != NULL && root->left->val > root->val && root->right->val < root->val)
//     {
//       flag = false;
//       return flag;
//     }
//     isValidBST(root->left);
//     isValidBST(root->right);
//   }
//   return flag;
// }