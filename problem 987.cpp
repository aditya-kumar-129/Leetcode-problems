// Question link :- https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
// Youtube Link:- https://www.youtube.com/watch?v=q_a6lpbKJdw

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
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    // map<verticals,map<level,all the nodes at that level with that verticals>>>
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode*, pair<int, int>>> todo;
    todo.push({ root,{0,0} });
    while (!todo.empty())
    {
      auto p = todo.front();   // pair<TreeNode*, pair<int, int>>
      todo.pop();
      TreeNode* node = p.first;
      int x = p.second.first, y = p.second.second;
      nodes[x][y].insert(node->val);   // This one is IMPORTANT
      if (node->left)
        todo.push({ node->left,{x - 1,y + 1} });
      if (node->right)
        todo.push({ node->right,{x + 1,y + 1} });
    }
    vector<vector<int>> ans;
    for (auto p : nodes)
    {
      vector<int> col;
      for (auto q : p.second)
        col.insert(col.end(), q.second.begin(), q.second.end());
      ans.push_back(col);
    }
    return ans;
  }
};