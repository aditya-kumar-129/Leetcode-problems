// Question link :- https://leetcode.com/problems/remove-linked-list-elements/

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
  ListNode* removeElements(ListNode* head, int val)
  {
    if (!head)
      return head;
    while (head && head->val == val)
      head = head->next;
    ListNode* curr = head, * prev = nullptr;
    while (curr)
    {
      if (curr->val == val)
        prev->next = curr->next;
      else
        prev = curr;
      curr = curr->next;
    }
    return head;
  }
};