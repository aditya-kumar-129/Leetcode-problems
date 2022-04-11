// Question link :- https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

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
  ListNode* swapNodes(ListNode* head, int k)
  {
    ListNode* temp1 = head;
    ListNode* frontNode = nullptr;
    while (k--)
    {
      frontNode = temp1;
      temp1 = temp1->next;
    }
    ListNode* backNode = head;
    while (temp1)
    {
      temp1 = temp1->next;
      backNode = backNode->next;
    }
    swap(frontNode->val, backNode->val);
    return head;
  }
};

