// Question link :- https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

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
  vector<int> ans;
  void inorderTraversal(TreeNode* root)
  {
    if (!root)
    {
      inorderTraversal(root->left);
      ans.push_back(root->val);
      inorderTraversal(root->right);
    }
  }
  bool findTarget(TreeNode* root, int k)
  {
    inorderTraversal(root);
    bool flag = false;
    int i = 0, j = ans.size() - 1;
    while (i < j)
    {
      if (ans[i] + ans[j] == k)
      {
        flag = true;
        return flag;
      }
      else if (ans[i] + ans[j] > k)
        j--;
      else
        i++;
    }
    return flag;
  }
};

// Worst case Space complexity O(n)
class Solution 
{
public:
  map<int, int> m;
  bool findTarget(TreeNode* root, int k) 
  {
    if (!root)
      return false;
    if (m.find(k - root->val) != m.end())
      return true;
    m[root->val]++;
    return findTarget(root->left, k) || findTarget(root->right, k);
  }
};