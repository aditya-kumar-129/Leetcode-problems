// Question link :- https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
  int utilityFunction(TreeNode* node, int& maximumSumValue) {
    if (!node)
      return 0;

    int leftSubtreeSum = max(0, utilityFunction(node->left, maximumSumValue));
    int rightSubtreeSum = max(0, utilityFunction(node->right, maximumSumValue));
    maximumSumValue = max(maximumSumValue, leftSubtreeSum + rightSubtreeSum + node->val);
    return node->val + max(leftSubtreeSum, rightSubtreeSum);
  }

  int maxPathSum(TreeNode* root) {
    int maximumSumValue = INT_MIN;
    utilityFunction(root, maximumSumValue);
    return maximumSumValue;
  }
};