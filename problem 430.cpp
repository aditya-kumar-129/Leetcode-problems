// Question link :- https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

#include<bits/stdc++.h>
using namespace std;


// Definition for a Node.
class Node {
public:
  int val;
  Node* prev, * next, * child;
};

class Solution {
public:
  Node* flatten(Node* head) {
    if (!head)
      return head;
    static Node* last = head;
    Node* nextPointer = head->next;
    if (head->child)
      last->next = flatten(head->child);
    if (nextPointer)
      last->next = flatten(nextPointer);
    return head;
  }
};
