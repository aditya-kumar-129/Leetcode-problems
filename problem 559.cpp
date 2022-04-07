// Question link :- https://leetcode.com/problems/maximum-depth-of-n-ary-tree/

#include<bits/stdc++.h>
using namespace std;

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
  int maxDepth(Node* root) {
    if (!root)
      return 0;
    int maxdepth = 0;
    for (auto it : root->children)
      maxdepth = max(maxdepth, maxDepth(it));
    return maxdepth + 1;
  }
};