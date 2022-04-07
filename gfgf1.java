
// #include <bits/stdc++.h>
// using namespace std;

// /* A binary tree node has data, pointer to left child
// and a pointer to right child */
// struct Node {
//   int data;
//   struct Node* left, * right;
// };

// //Utility function to create a new tree node
// Node* newNode(int data)
// {
//   Node* temp = new Node;
//   temp->data = data;
//   temp->left = temp->right = nullptr;
//   return temp;
// }

// class boundaryTraversal
// {
// public:
//   int maxLevel = 0;
//   void leftView(Node* root, int level, vector<int>& ans)
//   {
//     if (!root)
//       return;
//     if (maxLevel < level)
//     {
//       ans.push_back(root->data);
//       maxLevel = level;
//     }
//     leftView(root->left, level + 1, ans);
//     // Below recursive call is commented because of the reason mentioned in step 1 
//     // leftView(root->right, level + 1, ans);
//   }
//   void rightView(Node* root, int level, vector<int>& ans)
//   {
//     if (!root)
//       return;
//     if (maxLevel < level)
//     {
//       ans.push_back(root->data);
//       maxLevel = level;
//     }
//     rightView(root->right, level + 1, ans);
//     // Below recursive call is commented because of the reason mentioned in step 3
//     // rightView(root->left, level + 1, ans);
//   }
// };

// int main()
// {
//   Node* root = newNode(12);
//   root->left = newNode(15);
//   root->right = newNode(65);
//   root->left->left = newNode(9);
//   root->left->right = newNode(10);
//   root->right->left = newNode(46);
//   root->right->right = newNode(57);
  
//   boundaryTraversal obj;
//   // setting the value of maxLevel as zero so that at each level only one is taken in the view
//   obj.maxLevel = 0;
//   // vector in which we will store the boundary of the binary tree
//   vector<int> ans;
//   // calling the leftView
//   // If you have notices that we are passing the root->left because we are considering the root value in the rightView call
//   obj.leftView(root->left, 1, ans);
//   // We need to reverse the the solution because of the reason stated in step 2
//   reverse(ans.begin(), ans.end());
//   // Again setting the value of maxLevel as zero so that at each level only one is taken in the
//   obj.maxLevel = 0;
//   // calling the rightView
//   // In this call we are considering the root value
//   obj.rightView(root, 1, ans);
//   // Printing the solution
//   for (auto it : ans)
//     cout << it << " ";
// }

// import java.util.*;
// class Node {
//   int key;
//   Node left, right;
//   public Node(int item)
//   {
//       key = item;
//       left = right = null;
//   }
// }

// class boundaryTraversal
// {
//   int maxLevel = 0;
//   void leftView(Node root, int level, List <Integer> ans)
//   {
//     if (root == null)
//       return;
//     if (maxLevel < level)
//     {
//       ans.add(root.key);
//       maxLevel = level;
//     }
//     leftView(root.left, level + 1, ans);
//     // Below recursive call is commented because of the reason mentioned in step 1 
//     // leftView(root->right, level + 1, ans);
//   }
//   void rightView(Node root, int level, List <Integer> ans)
//   {
//     if (root == null)
//       return;
//     if (maxLevel < level)
//     {
//       ans.add(root.key);
//       maxLevel = level;
//     }
//     rightView(root.right, level + 1, ans);
//     // Below recursive call is commented because of the reason mentioned in step 3
//     // rightView(root->left, level + 1, ans);
//   }
// };

// class solution
// {
//   public static void main(String args[])
//   {
//     Node root = new Node(12);
//     root.left = new Node(15);
//     root.right = new Node(65);
//     root.left.left = new Node(9);
//     root.left.right = new Node(10);
//     root.right.left = new Node(46);
//     root.right.right = new Node(57);
//     boundaryTraversal obj = new boundaryTraversal();
//     obj.maxLevel =0;
//     List<Integer> ans = new ArrayList<>();
//     obj.leftView(root.left, 1, ans);

//     Collections.reverse(ans);
//     obj.maxLevel =0;
//     obj.rightView(root, 1, ans);

//     for(Integer item : ans)
//       System.out.print(item+ " ");
//   }
// }