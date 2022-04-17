// https://www.geeksforgeeks.org/level-order-traversal-of-n-ary-tree/
// Java implementation of the above problem
// https://www.studytonight.com/advanced-data-structures/nary-tree


// https://www.geeksforgeeks.org/flatten-a-binary-tree-into-linked-list/
// ALSO IN C LANGUAGE OF THE GIVEN ARTICLE
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

// https://www.geeksforgeeks.org/given-an-array-a-and-a-number-x-check-for-pair-in-a-with-sum-as-x/
// IMPLEMENTATION IN C 

// https://www.geeksforgeeks.org/maximum-number-partitions-can-sorted-individually-make-sorted/
// IMPLEMENTATION IN C 

// https://www.geeksforgeeks.org/check-if-a-string-has-all-characters-with-same-frequency-with-one-variation-allowed/
// IMPLEMENTATION IN C 

// https://www.geeksforgeeks.org/find-the-missing-number/
// IMPLEMENTATION IN C 

// https://www.geeksforgeeks.org/reverse-sublist-linked-list/
// IMPLEMENTATION IN C 

// https://www.geeksforgeeks.org/linked-list-set-3-deleting-node/
// IMPLEMENTATION IN C

// https://www.geeksforgeeks.org/delete-middle-of-linked-list/
// IMPLEMENTATION IN C

// https://www.geeksforgeeks.org/activity-selection-problem-greedy-algo-1/
// output of first method is somewhat not coreect
// Also c implementation to be done

// https://www.geeksforgeeks.org/job-sequencing-problem/
// IMPLEMENTATION IN C

// https://www.geeksforgeeks.org/maximize-array-sun-after-k-negation-operations/
// IMPLEMENTATION IN C

// https://www.geeksforgeeks.org/minimum-number-of-jumps-to-reach-end-of-a-given-array/
// IMPLEMENTATION IN C

// https://www.geeksforgeeks.org/given-an-array-of-numbers-arrange-the-numbers-to-form-the-biggest-number/
// All the methods are giving the wrong output for the input  0 0 0 0

// https://www.geeksforgeeks.org/minimum-incrementdecrement-to-make-array-non-increasing/
// Using Set Data Structure
// CPP code to count the change required to
// convert the array into non-increasing array
// #include <bits/stdc++.h>
// using namespace std;

// int DecreasingArray(int a[], int n)
// {
//   int sum = 0, dif = 0;
//   set<int> s;
//   for (int i = 0; i < n; i++) {
//     if (!s.empty() && *s.begin() < a[i]) {
//       dif = a[i] - *s.begin();
//       sum += dif;
//       s.erase(s.begin());
//       s.insert(a[i]);
//     }
//     s.insert(a[i]);
//   }
//   return sum;
// }

// // Driver Code
// int main()
// {
//   int a[] = { 3, 1, 5, 1 };
//   int n = sizeof(a) / sizeof(a[0]);
//   cout << DecreasingArray(a, n);
//   return 0;
// }


// https://www.geeksforgeeks.org/convert-to-strictly-increasing-integer-array-with-minimum-changes/
// Using Priority queue and set data structure

// This code is contributed by Aditya Kumar (adityakumar129)
// Node * root = (Node *)malloc(sizeof(Node));

// #include<stdio.h>
// #include<stdlib.h>
// #include <stdbool.h>

// This code is contributed by Sania Kumari Gupta
// Added the code in c language for the first method


// To check
// https://www.geeksforgeeks.org/delete-middle-of-linked-list/
// https://www.geeksforgeeks.org/merge-two-binary-trees-node-sum/
// https://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1/
// https://www.geeksforgeeks.org/union-find-algorithm-set-2-union-by-rank/
// https://www.geeksforgeeks.org/distinct-permutations-string-set-2/