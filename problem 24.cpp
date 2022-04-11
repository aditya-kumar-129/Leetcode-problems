// Question link :- https://leetcode.com/problems/swap-nodes-in-pairs/

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
  ListNode* swapPairs(ListNode* head) 
  {
    if(!head || !head->next)
      return head;
    ListNode * firstNode = head,*secondNode = head->next;
    head = secondNode;
    while(true)
    {
      ListNode* nextNode = secondNode->next;
      secondNode->next = firstNode;
      // In case if the linked list contains odd no of nodes
      if(!nextNode || !nextNode->next)
      {
        firstNode->next = nextNode;
        break;
      }
      // In case when you have more than two nodes remaining to swap then we have to point to th nextNode->next. Visualise this by making the answer and have a look on the links formed  
      firstNode ->next = nextNode->next;
      firstNode = nextNode;
      secondNode = firstNode->next;
    }
    return head;
  }
};