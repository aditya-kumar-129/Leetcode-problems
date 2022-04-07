// Question link :- https://leetcode.com/problems/linked-list-cycle-ii/

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
  ListNode* detectCycle(ListNode* head) {
    if(!head  )
      return nullptr;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
      slow = slow->next;
      fast = fast->next->next;
      if(slow==fast)
        break;
    }
    if (!fast || !fast->next)
      return nullptr;
    fast = head;
    while (slow != fast)
    {
      slow = slow->next;
      fast = fast->next;
    }
    return slow;
  }
};
