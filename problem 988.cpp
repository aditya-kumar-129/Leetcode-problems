// Question link :- https://leetcode.com/problems/smallest-string-starting-from-leaf/

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
  vector <string>  ans;
  string smallestFromLeaf(TreeNode* root)
  {
    string temp;
    DFS(root, temp);
    sort(ans.begin(), ans.end());
    return ans[0];
  }
  void DFS(TreeNode* root, string temp)
  {
    if (!root)
      return;
    temp += root->val + 'a';
    if (!root->left && !root->right)
    {
      reverse(temp.begin(), temp.end());
      ans.push_back(temp);
      return;
    }
    DFS(root->left, temp);
    DFS(root->right, temp);
  }
};

// In this case You don't have to sort as well as space complexity will also be O(1)

class Solution {
public:
  void DFS(TreeNode* root, string& ans, string temp)
  {
    if (!root) return;
    temp += 'a' + root->val;
    if (!root->left  && !root->right)
    {
      reverse(temp.begin(), temp.end());
      if (ans == "")
        ans = temp;
      else
        ans = min(ans, temp);
    }
    DFS(root->left, ans, temp);
    DFS(root->right, ans, temp);
  }
  string smallestFromLeaf(TreeNode* root)
  {
    string ans = "";
    DFS(root, ans, "");
    return ans;
  }
};