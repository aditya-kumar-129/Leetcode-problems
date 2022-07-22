// Question link :- https://leetcode.ca/all/276.html
// Youtube video :- https://www.youtube.com/watch?v=kh48JLieeW8

#include <bits/stdc++.h>
using namespace std;

int main() { 
  int n; cin >> n;
  int k; cin >> k;

  int sameColor = k;
  int differentColor = k * (k - 1);
    int sum = sameColor + differentColor;

  for (int i = 3;i <= n;i++) {
    sameColor = differentColor;
    differentColor = sum * (k-1); 
    sum = sameColor + differentColor;
  }

  cout<<sameColor + differentColor;
}
