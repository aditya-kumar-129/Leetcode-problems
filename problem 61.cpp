// Question link :- https://leetcode.com/problems/rotate-list/

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


#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
  ListNode* rotateRight(ListNode* head, int k)
  {
    if (head == nullptr || head->next == nullptr)
      return head;

    // Finding the length of the linked list
    int count = 0;
    ListNode* current = head;
    while (current)
    {
      count++;
      current = current->next;
    }

    // Take the modulo value of k
    k = k % count;
    if (k == 0)
      return head;

    // loop for Pointing to the last node
    ListNode* current_list = head;
    while (current_list->next)
      current_list = current_list->next;

    // Get the count of kth node whose next is to make NULL
    k = count - k;
    ListNode* temp = head;
    int i = 0;
    while (i < k - 1)
    {
      temp = temp->next;
      i++;
    }
    current_list->next = head;
    head = temp->next;
    temp->next = nullptr;
    return head;
  }
};