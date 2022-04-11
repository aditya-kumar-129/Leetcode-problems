// Question link :- https://leetcode.com/problems/reverse-linked-list-ii/

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
  ListNode* reverse(struct ListNode* head)
  {
    ListNode* prev = nullptr, * curr = head, * next = nullptr;
    while (curr)
    {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (left == right)
      return head;
    ListNode* reverseStart = nullptr, * reverseEnd = nullptr;
    ListNode* reversePrevious = nullptr, * reverseEndNext = nullptr;

    // Find values of above pointers.
    int i = 1;
    ListNode* curr = head;
    while (curr && i <= right)
    {
      if (i < left)
        reversePrevious = curr;
      if (i == left)
        reverseStart = curr;
      if (i == right)
      {
        reverseEnd = curr;
        reverseEndNext = curr->next;
      }
      curr = curr->next;
      i++;
    }
    reverseEnd->next = nullptr;

    // Reverse linked list starting with reverseStart.
    reverseEnd = reverse(reverseStart);
    // If starting position was not head
    if (reversePrevious)
      reversePrevious->next = reverseEnd;
    // If starting position was head
    else
      head = reverseEnd;
    reverseStart->next = reverseEndNext;
    return head;
  }
};