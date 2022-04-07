// Question link :- https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    map<int, int > mp;
    for (int i = 0;i < inorder.size();i++)
      mp[inorder[i]] = i;

    TreeNode* root = buildTree(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
    return root;
  }
  TreeNode* buildTree(vector<int> postorder, int postorderStart, int postorderEnd, vector<int> inorder, int inorderStart, int inorderEnd, map<int, int>& mp)
  {
    if (postorderStart > postorderEnd || inorderStart > inorderEnd)
      return nullptr;
    TreeNode* root = new TreeNode(postorder[postorderEnd]);
    int inRoot = mp[root->val];
    int numsLeft = inRoot - inorderStart;
    root->left = buildTree(postorder, postorderStart , postorderStart + numsLeft -1, inorder, inorderStart, inRoot - 1, mp);

    root->right = buildTree(postorder, postorderStart + numsLeft , postorderEnd -1, inorder, inRoot + 1, inorderEnd, mp);

    return root;
  }
};