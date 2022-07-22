// Question link :- https://leetcode.com/problems/partition-list/

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* partition(ListNode* head, int x) {
    if (!head)
      return nullptr;
    ListNode* less = nullptr, * more = nullptr;
    ListNode* lessPrev = nullptr, * morePrev = nullptr;
    ListNode* curr = head;
    while (curr)
    {
      if (curr->val < x)
      {
        if (!lessPrev)
        {
          less = curr;
          lessPrev = curr;
        }
        else
        {
          less->next = curr;
          less = less->next;
        }
      }
      else if (curr->val >= x)
      {
        if (!morePrev)
        {
          morePrev = curr;
          more = curr;
        }
        else
        {
          more->next = curr;
          more = more->next;
        }
      }
      curr = curr->next;
    }
    if (!lessPrev)
    {
      more->next = nullptr;
      return morePrev;
    }
    else if (lessPrev && morePrev)
    {
      more->next = nullptr;
      less->next = morePrev;
    }
    return lessPrev;
  }
};