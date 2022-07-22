// Question link :- https://leetcode.com/problems/min-stack/

#include<bits/stdc++.h>
using namespace std;

// Brute force approach
// Time complexity:- O(q)
// Space Complexity :- O(n)

class MinStack {
public:
  stack<int> aux;
  stack<int> s;
  MinStack() {
  }

  void push(int val) {
    s.push(val);
    if (aux.empty() || aux.top() >= val)
      aux.push(val);
  }

  void pop() {
    if (s.top() == aux.top())
      aux.pop();
    s.pop();
  }

  int top() {
    return s.top();
  }

  int getMin() {
    if (aux.empty())
      return -1;
    else
      return aux.top();
  }
};