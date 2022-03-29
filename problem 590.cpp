// Question link :- https://leetcode.com/problems/n-ary-tree-postorder-traversal/

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
  void postOrderUtil(Node* root)
  {
    for (auto it : root->children)
      postOrderUtil(it);
    ans.push_back(root->val);
  }

  vector<int> postorder(Node* root)
  {
    if (!root)
      return ans;
    postOrderUtil(root);
    return ans;
  }
};

// 2nd approach to solve the problem
class Solution {
public:
  void postOrderUtil(Node* root, vector <int>& ans)
  {
    for (auto it : root->children)
      postOrderUtil(it, ans);
    ans.push_back(root->val);
  }

  vector<int> postorder(Node* root)
  {
    vector<int> ans;
    if (!root)
      return ans;
    postOrderUtil(root, ans);
    return ans;
  }
};