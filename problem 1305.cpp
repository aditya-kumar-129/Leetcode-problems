// Question link :- https://leetcode.com/problems/all-elements-in-two-binary-search-trees/

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


// Optimised solution
// Time Complexity : O(m + n)
// Auxiliary Space : O(height of the first tree + height of the second tree)
class Solution
{
public:
  vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
  {
    vector<int> res;
    stack<TreeNode*> s1, s2;
    while (root1 || root2 || !s1.empty() || !s2.empty())
    {
      while (root1)
        s1.push(root1),root1 = root1->left;
      while (root2)
        s2.push(root2),root2 = root2->left;
      if (s2.empty() || (!s1.empty() && s1.top()->val <= s2.top()->val))
      {
        root1 = s1.top();
        s1.pop();
        res.push_back(root1->val);
        root1 = root1->right;
      }
      else
      {
        root2 = s2.top();
        s2.pop();
        res.push_back(root2->val);
        root2 = root2->right;
      }
    }
    return res;
  }
};

// Brute force approach
// Time Complexity :- O(M+N)log(M+N)
// Space Complexity :- O(M+N)

class Solution {
public:
  vector<int> ans;
  void inorderTraversal(TreeNode* root)
  {
    if (root)
    {
      inorderTraversal(root->left);
      ans.push_back(root->val);
      inorderTraversal(root->right);
    }
  }
  vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
  {
    inorderTraversal(root1);
    inorderTraversal(root2);
    sort(ans.begin(), ans.end());
    return ans;
  }
};