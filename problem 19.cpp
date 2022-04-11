// Question link :- https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
  ListNode* removeNthFromEnd(ListNode* head, int n)
  {
    if (!head->next)
      return nullptr;
    ListNode* temp1 = head;
    // Finding the length of the linked list
    int length = 0;
    while (temp1)
    {
      length++;
      temp1 = temp1->next;
    }
    int index = length - n;
    // If the head node is to be deleted
    if (index == 0)
    {
      head = head->next;
      return head;
    }
    // If it is some other node preset in the list
    ListNode* prev = nullptr, * temp2 = head;
    while (index--)
    {
      prev = temp2;
      temp2 = temp2->next;
    }
    prev->next = temp2->next;
    return head;
  }
};