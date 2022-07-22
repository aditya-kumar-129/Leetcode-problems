// Question link :- https://leetcode.com/problems/next-greater-node-in-linked-list/

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
  vector<int> nextLargerNodes(ListNode* head) {
    stack<pair<int, int>> s;
    ListNode* curr = head;
    int count = 0;
    while (curr)
    {
      count++;
      curr = curr->next;
    }
    vector<int> ans(count, 0);
    curr = head;
    int i = 0;
    while (curr)
    {
      if (s.empty())
        s.push(make_pair(i, curr->val));
      else
      {
        if (s.top().second < curr->val)
        {
          while (s.top().second < curr->val)
          {
            ans[s.top().first] = curr->val;
            s.pop();
          }
          s.push(make_pair(i, curr->val));
        }
        else
          s.push(make_pair(i,curr->val));
      }
      i++;
      curr = curr->next;
    }
    return ans;
  }
};