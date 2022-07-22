// Question link :- https://www.codingninjas.com/codestudio/problems/left-view-of-a-binary-tree_920519

#include<bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
  T data;
  BinaryTreeNode<T>* left;
  BinaryTreeNode<T>* right;

  BinaryTreeNode(T data)
  {
    this->data = data;
    left = NULL;
    right = NULL;
  }
};

vector<int> ans;
void rightSide(BinaryTreeNode<int>* root, int level)
{
  if (!root)
    return;
  if (ans.size() == level)
    ans.push_back(root->data);
  rightSide(root->left, level + 1);
  rightSide(root->right, level + 1);
}
void printLeftView(BinaryTreeNode<int>* root)
{
  rightSide(root, 0);
  for(auto it :ans)
    cout<<it<<" ";
}