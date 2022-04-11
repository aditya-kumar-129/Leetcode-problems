// Question link :- https://leetcode.com/problems/delete-node-in-a-linked-list/

#include<bits/stdc++.h>
using namespace std;
//  Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  void deleteNode(ListNode* node) 
  {
    // It is used to set the next pointer of Last Node to NULL
    ListNode* prev;
    if (node == nullptr)
      return;
    else 
    {
      while (node->next) 
      {
        node->val = node->next->val;
        prev = node;
        node = node->next;
      }
      prev->next = nullptr;
    }
  }
};