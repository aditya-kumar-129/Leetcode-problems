// Question link :- https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
    ListNode* dummy = new ListNode(-1);
    dummy->next= head;
    ListNode* prev = dummy;
    ListNode*curr = head;
    while(curr)
    {
      while(curr->next && prev->next->val == curr->next->val)
        curr = curr->next;
      if(prev->next==curr)
        prev = prev->next;
      else
        prev->next = curr->next;
      curr = curr->next;
    }
    head = dummy->next;
    return head;
  }
};