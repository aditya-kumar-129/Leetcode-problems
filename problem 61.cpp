/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
  ListNode *rotateRight(ListNode *head, int k)
  {
    if (head == NULL || head->next == NULL)
      return head;
    int count = 0;
    ListNode *current = head;
    while (current != NULL)
    {
      count++;
      current = current->next;
    }
    k = k % count;
    if (k == 0)
      return head;
    ListNode *current_list = head;
    while (current_list->next != NULL)
      current_list = current_list->next;
    k = count - k;
    ListNode *temp = head;
    int i = 0;
    while (i < k - 1)
    {
      temp = temp->next;
      i++;
    }
    current_list->next = head;
    head = temp->next;
    temp->next = NULL;
    return head;
  }
};