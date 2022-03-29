// Question link :- https://leetcode.com/problems/next-permutation/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void nextPermutation(vector<int>& arr) {
    int index1 = -1, index2 = -1;
    int N = arr.size();
    for (int i = 0; i < N - 1; i++)
    {
      if (arr[i] < arr[i + 1])
      {
        index1 = i;
        index2 = i + 1;
      }
    }
    // if the below condition satisfies then it means that the number is already in descending order and it's next permuatation is obtained when you sort the element 
    if (index1 == -1)
      reverse(arr.begin(), arr.end());
    else
    {
      int mx = arr[index1], smallest = index2;
      for (int i = index2; i < N; i++)
        if (arr[i] > mx && arr[i] < arr[smallest])
          smallest = i;
      swap(arr[smallest], arr[index1]);
      sort(arr.begin() + index2, arr.end());
    }
  }
};