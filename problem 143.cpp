// Question link :- https://leetcode.com/problems/reorder-list/

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
  ListNode* reverse(struct ListNode* head)
  {
    ListNode* current = head, * prev = nullptr, *nextNode = nullptr;
    while (current) 
    {
      nextNode = current->next;
      current->next = prev; 
      prev = current;
      current = nextNode;
    }
    return prev;
  }
  void reorderList(ListNode* head) {
    if (!head || !(head->next)) 
      return;
    ListNode* slow = head, * fast = head->next;
    while (fast && fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode* secondLLHead = slow->next;
    secondLLHead = reverse(secondLLHead);

    ListNode*firstLLHead =head;
    slow->next = nullptr;

    while(secondLLHead)
    {
      ListNode* temp1 = firstLLHead->next;
      ListNode * temp2 = secondLLHead->next;
      firstLLHead->next = secondLLHead;
      secondLLHead->next = temp1;
      firstLLHead=temp1;
      secondLLHead=temp2;
    }
  }
};