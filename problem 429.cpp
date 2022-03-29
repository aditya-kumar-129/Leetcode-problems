// Question link :- https://leetcode.com/problems/n-ary-tree-level-order-traversal/

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
  vector<vector<int>> levelOrder(Node* root)
  {
    vector<vector<int>> ans;
    if (!root)
      return ans;
    queue <Node*> mq, cq;
    mq.push(root);
    vector<int> temp;
    while (!mq.empty())
    {
      auto tempNode = mq.front();
      temp.push_back(tempNode->val);
      mq.pop();
      for (auto it : tempNode->children)
        cq.push(it);
      if (mq.empty())
      {
        mq = cq;
        queue <Node*> temp1;
        swap(temp1, cq);
        ans.push_back(temp);
        temp.clear();
      }
    }
    return ans;
  }
};