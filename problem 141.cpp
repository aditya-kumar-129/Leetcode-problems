// Question link :- https://leetcode.com/problems/linked-list-cycle/

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
  bool hasCycle(ListNode* head) {
    ListNode *slow = head,*fast = head;
    bool flag = false;
    while(fast && fast->next)
    {
      slow= slow->next;
      fast=fast->next->next;
      if(slow==fast)
      {
        flag=true;
        break;
      }
    }
    return flag;
  }
};