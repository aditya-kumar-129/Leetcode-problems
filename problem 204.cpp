// Question link :- https://leetcode.com/problems/count-primes/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countPrimes(int n) {
    if (n < 2)
      return 0;
    vector<bool> primes(n, true);
    primes[0] = false;
    primes[1] = false;
    for (int i = 2;i * i < n;i++)
      if (primes[i])
        for (int j = i * 2;j <= n;j += i)
          primes[j] = false;
    
    int count = 0;
    for (auto it : primes)
      if (it == 1)
        count++;
    return count;
  }
};