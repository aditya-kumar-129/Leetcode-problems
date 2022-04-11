// Question link :- https://leetcode.com/problems/merge-two-sorted-lists/

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

// Iterative Approach
class Solution {
public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1)
      return list2;
    if (!list2)
      return list1;
    // We want List1 to contain the minimum of the two value that are present in the head of the two list
    // If this is not the case then in that case swap the two list
    if (list1->val > list2->val)
      swap(list1, list2);
    ListNode* res = list1;
    while (list1 && list2)
    {
      ListNode* temp1 = nullptr;
      while (list1 && list1->val <= list2->val)
      {
        temp1 = list1;
        list1 = list1->next;
      }
      temp1->next = list2;
      swap(list1, list2);
    }
    return res;
  }
};


// Recursive Approach
class Solution {
public:
  ListNode* mergeTwoLists(ListNode* head1, ListNode* head2)
  {
    if (!head1)
      return head2;
    if (!head2)
      return head1;
    if (head1->val < head2->val)
    {
      head1->next = mergeTwoLists(head1->next, head2);
      return head1;
    }
    else
    {
      head2->next = mergeTwoLists(head1, head2->next);
      return head2;
    }
  }
};