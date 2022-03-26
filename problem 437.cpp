// Have a look on the below video:- ONLY FIRST PART OF THE VIDEO
// https://youtu.be/yyZA4v0x16w
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
  int total = 0;
public:
  int pathSum(TreeNode* root, int targetSum)
  {
    if (!root)
      return 0;
    DFS(root, targetSum, 0);
    pathSum(root->left, targetSum);
    pathSum(root->right, targetSum);
    return total;
  }
  void DFS(TreeNode* root, int targetSum, int currentsum)
  {
    if (!root)
      return;
    currentsum += root->val;
    if (currentsum == targetSum)
      total++;
    DFS(root->left, targetSum, currentsum);
    DFS(root->right, targetSum, currentsum);
  }
};