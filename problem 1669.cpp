// Question link :- https://leetcode.com/problems/merge-in-between-linked-lists/

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
  ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2)
  {
    ListNode* firstPrev = nullptr, * firstAfter = nullptr;
    ListNode* curr = list1;
    while (a--)
    {
      firstPrev = curr;
      curr = curr->next;
    }
    curr = list1;
    while (b--)
      curr = curr->next;
    firstAfter = curr->next;
    firstPrev->next = list2;
    curr = list2;
    while (curr->next)
      curr = curr->next;
    curr->next = firstAfter;
    return list1;
  }
};