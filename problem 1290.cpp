// Question link :- https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

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
  int getDecimalValue(ListNode* head) 
  {
    int result =0;
    while (head)
    {
      result = result <<1 + (head->val);
      head = head->next;
    }
    return result;
  }
};

// Method :- 2
// Reverse the List and use the basics that is used to convert a binary number to decimal

class Solution {
public:
  ListNode* reverseList(ListNode* head)
  {
    ListNode* current = head;
    ListNode* prev = nullptr, * next = nullptr;
    while (current != nullptr)
    {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
    head = prev;
    return head;
  }
  int getDecimalValue(ListNode* head)
  {
    head = reverseList(head);
    int result = 0;
    int i = 0;
    while (head)
    {
      result += pow(2, i) * head->val;
      head = head->next;
      i++;
    }
    return result;
  }
};

class Solution {
public:
  int getDecimalValue(ListNode* head)
  {
    string result = "";
    while (head)
    {
      result += to_string(head->val);
      head = head->next;
    }
    reverse(result.begin(), result.end());
    int sum = 0;
    for (int i = 0;i < result.size();i++)
      sum += pow(2, i) * (result[i] - '0');
    return sum;
  }
};