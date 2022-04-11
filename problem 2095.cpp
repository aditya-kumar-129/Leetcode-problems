// Question link :- https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

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
  ListNode* deleteMiddle(ListNode* head) {
    ListNode* slow = head, * fast = head, * temp = nullptr;
    if (!head->next)
      return nullptr;
    while (fast && fast->next)
    {
      temp = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    temp->next = slow->next;
    return head;
  }
};