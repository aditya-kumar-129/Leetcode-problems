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