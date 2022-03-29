// Question link :- https://leetcode.com/problems/n-ary-tree-preorder-traversal/ 

#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
  int val;
  vector<Node*> children;
  Node() {}
  Node(int _val) {
    val = _val;
  }
  Node(int _val, vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
public:
  vector<int> ans;
  void preorderUtil(Node *root)
  {
    ans.push_back(root->val);
    for (auto it : root->children)
      preorderUtil(it);
  }

  vector<int> preorder(Node* root) 
  {
    if(!root)
      return ans;
    preorderUtil(root);
    return ans;
  }
};



// class Solution {
// public:
//   void preorderUtil(Node* root, vector <int>& ans)
//   {
//     ans.push_back(root->val);
//     for (auto it : root->children)
//       preorderUtil(it, ans);
//   }

//   vector<int> preorder(Node* root)
//   {
//     vector<int> ans;
//     if (!root)
//       return ans;
//     preorderUtil(root, ans);
//     return ans;
//   }
// };