// Question link :- https://leetcode.com/problems/remove-duplicates-from-sorted-list/

#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head)
  {
    if (!head || !head->next)
      return head;
    ListNode* curr = head->next, * prev = head;
    while (curr)
    {
      if (prev->val == curr->val)
        prev->next = curr->next;
      else
        prev = prev->next;
      curr = curr->next;
    }
    return head;
  }
};