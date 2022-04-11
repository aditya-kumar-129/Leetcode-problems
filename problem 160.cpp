// Question link :- https://leetcode.com/problems/intersection-of-two-linked-lists/

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
  int getCount(ListNode* head)
  {
    ListNode* current = head;
    int count = 0;
    while (current != nullptr) {
      count++;
      current = current->next;
    }
    return count;
  }
  ListNode* getIntesectionNode(ListNode* head1, ListNode* head2)
  {
    int c1 = getCount(head1);
    int c2 = getCount(head2);
    int d = abs(c1-c2);
    // If first is greater
    if (c1 > c2) 
      return _getIntesectionNode(d, head1, head2);
    else 
      return _getIntesectionNode(d, head2, head1);
  }

  // function to get the intersection point of two linked lists head1 and head2 where head1 has d more nodes than head2 
  ListNode* _getIntesectionNode(int d, ListNode* head1, ListNode* head2)
  {
    // Stand at the starting of the bigger list
    ListNode* current1 = head1;
    ListNode* current2 = head2;
    // Move the pointer forward
    for (int i = 0; i < d; i++) 
    {
      if (current1 == nullptr) 
        return nullptr;
      current1 = current1->next;
    }
    // Move both pointers of both list till they intersect with each other
    while (current1 && current2) 
    {
      if (current1 == current2)
        return current1;
      current1 = current1->next;
      current2 = current2->next;
    }
    return nullptr;
  }

  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) 
  {
    return getIntesectionNode(headA,headB);
  }
};