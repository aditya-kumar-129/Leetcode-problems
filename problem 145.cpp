// Question link :- https://leetcode.com/problems/binary-tree-postorder-traversal/

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

// RECURSIVE SOLUTION
class Solution {
public:
  vector<int> ans;
  vector<int> postorderTraversal(TreeNode* root) {
    if (root != nullptr)
    {
      postorderTraversal(root->left);
      postorderTraversal(root->right);
      ans.push_back(root->val);
    }
    return ans;
  }
};

// ITERATIVE SOLUTION
// BRUTE FORCE APPROACH 
// We are using TWO STACK in order to solve the problem
class Solution {
public:
  vector<int> ans;
  vector<int> postorderTraversal(TreeNode* root) {
    if (!root)
      return ans;
    stack<TreeNode*> st1, st2;
    st1.push(root);
    while (!st1.empty())
    {
      auto topElement = st1.top();
      st1.pop();
      st2.push(topElement);
      if (topElement->left)
        st1.push(topElement->left);
      if (topElement->right)
        st1.push(topElement->right);
    }
    while (!st2.empty())
    {
      ans.push_back(st2.top()->val);
      st2.pop();
    }
    return ans;
  }
};

class Solution {
public:
  vector<int> postOrder;
  vector<int> postorderTraversal(TreeNode* cur) {
    vector < int > postOrder;
    if (!cur) return postOrder;

    stack < TreeNode* > st;
    while (cur || !st.empty()) {

      if (cur) {
        st.push(cur);
        cur = cur->left;
      }
      else {
        TreeNode* temp = st.top()->right;
        if (!temp) {
          temp = st.top();
          st.pop();
          postOrder.push_back(temp->val);
          while (!st.empty() && temp == st.top()->right) {
            temp = st.top();
            st.pop();
            postOrder.push_back(temp->val);
          }
        }
        else cur = temp;
      }
    }
    return postOrder;
  }
};

// Application of PostOrder Traversal
// Postorder traversal is used to delete the tree.
// For implementation of the above question Refer this article :-
// https://www.geeksforgeeks.org/write-a-c-program-to-delete-a-tree/

// Postorder traversal is also useful to get the postfix expression of an expression tree.