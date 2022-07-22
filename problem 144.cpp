// Question link :- https://leetcode.com/problems/binary-tree-preorder-traversal/

#include<bits/stdc++.h>
using namespace std;
// PRE ORDER TRAVERSAL OF A BINARY TREE
// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// RECURSIVE SOLUTION
class Solution {
public:
  vector<int> ans;
  vector<int> preorderTraversal(TreeNode* root) {
    if (root != nullptr)
    {
      ans.push_back(root->val);
      preorderTraversal(root->left);
      preorderTraversal(root->right);
    }
    return ans;
  }
};

// ITERATIVE SOLUTION
class Solution {
public:
  vector<int> ans;
  vector<int> preorderTraversal(TreeNode* root) {
    if (!root) 
      return ans;
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty())
    {
      auto temp = st.top();
      st.pop();
      ans.push_back(temp->val);
      if (temp->right)
        st.push(temp->right);
      if (temp->left)
        st.push(temp->left);
    }
    return ans;
  }
};

// Application of Preorder Traversal
// Preorder traversal is used to create a copy of the tree.
// Preorder traversal is also used to get prefix expression on an expression tree.

// For Iterrative Solution refer the below Article :- 
// https://www.geeksforgeeks.org/iterative-preorder-traversal/