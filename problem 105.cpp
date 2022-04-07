// Question link :- https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    map<int ,int > mp;
    for (int i = 0;i < inorder.size();i++)
      mp[inorder[i]] = i;
    
    TreeNode* root = buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
    return root;
  }
  TreeNode * buildTree(vector<int> preorder,int preorderStart,int preorderEnd,vector<int> inorder,int inorderStart,int inorderEnd,map<int,int> &mp)
  {
    if(preorderStart>preorderEnd || inorderStart>inorderEnd)
      return nullptr;
    TreeNode* root = new TreeNode(preorder[preorderStart]);
    int inRoot = mp[root->val];
    int numsLeft = inRoot - inorderStart;
    root->left = buildTree(preorder,preorderStart+1,preorderStart + numsLeft,inorder,inorderStart,inRoot-1,mp);

    root->right = buildTree(preorder, preorderStart + numsLeft +1,preorderEnd,inorder,inRoot+1,inorderEnd,mp);

    return root;
  }
};