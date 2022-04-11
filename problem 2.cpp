// Question link :- https://leetcode.com/problems/add-two-numbers/

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

  ListNode* addTwoNumbers(struct ListNode* first, struct ListNode* second)
  {
    ListNode* res = nullptr, * temp;
    int carry = 0, newval;
    while (first != nullptr || second != nullptr || carry != 0)
    {
      newval = carry;
      if (first)
        newval += first->val;
      if (second)
        newval += second->val;
      carry = newval / 10;
      newval = newval % 10;
      ListNode* newNode = new ListNode(newval);
      if (!res)
        res = newNode, temp = newNode;
      else
        temp->next = newNode, temp = temp->next;
      if (first)
        first = first->next;
      if (second)
        second = second->next;
    }
    // res = reverse(res);
    return res;
  }
};