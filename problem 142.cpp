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
    if (!head)
      return nullptr;
    ListNode* slow = head, * fast = head;
    bool flag = false;
    while (fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast)
      {
        flag = true;
        break;
      }
    }
    // In case if there is no loop
    if (!flag)
      return nullptr;
    // When there is a loop
    fast = head;
    while (slow != fast)
    {
      slow = slow->next;
      fast = fast->next;
    }
    return slow;
  }
};