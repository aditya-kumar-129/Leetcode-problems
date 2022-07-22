// Question link :- https://leetcode.com/problems/palindrome-linked-list/

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
  stack<int> st;
  bool isPalindrome(ListNode* head) {
    ListNode* temp = head;
    while (temp)
    {
      st.push(temp->val);
      temp = temp->next;
    }
    temp = head;
    while (temp)
    {
      if (st.top() != temp->val)
        return false;
      else
        st.pop();
      temp = temp->next;
    }
    return true;
  }
};