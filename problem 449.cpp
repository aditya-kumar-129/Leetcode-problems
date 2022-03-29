// Question link :- https://leetcode.com/problems/serialize-and-deserialize-bst/

#include<bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:

  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    string s = "";
    if(!root)
      return s;
    queue <TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
      auto tempNode = q.front();
      q.pop();
      if(!tempNode)
        s.append("#,");
      else
      {
        s.append(to_string(tempNode->val)+',');
        q.push(tempNode->left);
        q.push(tempNode->right);
      }
    }
    return s;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) 
  {
    if(!data.size())
      return nullptr;
    stringstream s(data);
    string str;
    getline(s,str,',');
    TreeNode *root = new TreeNode(stoi(str));
    queue <TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
      TreeNode *node = q.front();
      q.pop();
      getline(s,str,',');
      if(str == "#")
        node->left = nullptr;
      else
      {
        TreeNode * leftNode = new TreeNode(stoi(str));
        node->left = leftNode;
        q.push(leftNode);
      }

      getline(s,str,',');
      if(str == "#")
        node->right = nullptr;
      else
      {
        TreeNode * rightNode = new TreeNode(stoi(str));
        node->right = rightNode;
        q.push(rightNode);
      }
    }
    return root;
  }
};