// Question link :- https://leetcode.com/problems/odd-even-linked-list/

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
  ListNode* oddEvenList(ListNode* head)
  {
    if (head == nullptr)
      return nullptr;
    ListNode* oddNode = head, * evenNode = head->next;
    ListNode* evenNodeRef = evenNode;
    while (true)
    {
      if (!oddNode || !evenNode || !(evenNode->next))
      {
        oddNode->next = evenNodeRef;
        break;
      }
      oddNode->next = evenNode->next;
      oddNode = oddNode->next;
      if(!oddNode->next)
      {
        evenNode->next=nullptr;
        oddNode->next = evenNodeRef;
        break;
      }
      evenNode->next = oddNode->next;
      evenNode = evenNode->next;
    }
    return head;
  }
};