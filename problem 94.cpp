// Question link :- https://leetcode.com/problems/binary-tree-inorder-traversal/

#include<bits/stdc++.h>
using namespace std;

// INORDER TRAVERSAL OF A BINARY TREE
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
  vector<int> inorderTraversal(TreeNode* root) {
    if (root != nullptr)
    {
      inorderTraversal(root->left);
      ans.push_back(root->val);
      inorderTraversal(root->right);
    }
    return ans;
  }
};

// ITERATIVE SOLUTION

class Solution {
public:
  vector<int> inorderTraversal(TreeNode* root) {
    stack<TreeNode*> st;
    TreeNode* node = root;
    vector<int> ans;
    while (true)
    {
      if (node)
      {
        st.push(node);
        node = node->left;
      }
      else
      {
        if (st.empty())
          break;
        node = st.top();
        st.pop();
        ans.push_back(node->val);
        node = node->right;
      }
    }
    return ans;
  }
};