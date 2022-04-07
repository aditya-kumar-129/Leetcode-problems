#include <bits/stdc++.h>
using namespace std;

struct Node {
  char val;
  vector<Node*> children;
};

// Utility function to create a new tree node
Node* newNode(int key)
{
  Node* temp = new Node;
  temp->val = key;
  return temp;
}

class LevelOrderTraversal {
public:
  void levelOrder(Node* root)
  {
    vector<vector<int> > ans;
    if (!root)
      cout << "N-Ary tree does not any nodes";
    // create two queues main_queue and child_queue
    queue<Node*> main_queue, child_queue;
    // push the root value in the main_queue
    main_queue.push(root);
    // create a temp vector to store the all the node
    // values present at a particular level
    vector<int> temp;
    // Run a while loop until the main_queue is empty
    while (!main_queue.empty()) {
      // get the front of the main_queue
      auto tempNode = main_queue.front();
      // push the value of the front of the main queue
      // in the temp vector
      temp.push_back(tempNode->val);
      // push all the child of the popped node in the
      // child queue
      for (auto it : tempNode->children)
        child_queue.push(it);
      // pop the front of the main queue
      main_queue.pop();
      // if main_queue becomes empty and child_queue
      // is not empty then swap the content of the two
      // queues
      if (main_queue.empty()) {
        main_queue = child_queue;
        queue<Node*> temp1;
        swap(temp1, child_queue);
        // push the temporary vector in the ans
        // vector
        ans.push_back(temp);
        // clear the temporary vector
        temp.clear();
      }
    }
    for (auto it : ans) {
      for (auto v : it)
        cout << v << " ";
      cout << endl;
    }
  }
};

int main()
{
  Node* root = newNode(1);
  root->children.push_back(newNode(3));
  root->children.push_back(newNode(2));
  root->children.push_back(newNode(4));
  root->children[0]->children.push_back(newNode(5));
  root->children[0]->children.push_back(newNode(6));
  LevelOrderTraversal obj;
  obj.levelOrder(root);
  return 0;
}

// This code is contributed by aditya kumar (adityakumar129)

// Java implementation of the above problem
// https://www.studytonight.com/advanced-data-structures/nary-tree


// https://www.geeksforgeeks.org/flatten-a-binary-tree-into-linked-list/
// reference striver video
// approach :- 
// class Solution {
// public:
//   TreeNode* prev = nullptr;
//   void flatten(TreeNode* root)
//   {
//     if (!root)
//       return;
//     flatten(root->right);
//     flatten(root->left);
//     root->right = prev;
//     root->left = nullptr;
//     prev = root;
//   }
// };