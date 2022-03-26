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

// Space complexity O(n)
class Solution {
public:
  vector<int> ans;
  void inorderTraversal(TreeNode* root) {
    if (root != NULL)
    {
      inorderTraversal(root->left);
      ans.push_back(root->val);
      inorderTraversal(root->right);
    }
  }
  int kthSmallest(TreeNode* root, int k) 
  {
    inorderTraversal(root);
    return ans[k-1];
  }
};

// Worst case space complexity :- O(n) else less than O(n)

class Solution {
public:
  vector<int> ans;
  void inorderTraversal(TreeNode* root, int& k) {
    if (root != NULL)
    {
      inorderTraversal(root->left, k);
      if (ans.size() == k)return;
      ans.push_back(root->val);
      inorderTraversal(root->right, k);
    }
  }
  int kthSmallest(TreeNode* root, int k)
  {
    inorderTraversal(root, k);
    return ans[k - 1];
  }
};