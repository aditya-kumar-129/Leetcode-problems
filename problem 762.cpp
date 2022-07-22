// Question link :- https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool seiveOfErathonesis(int primes[],int n)
  {
    primes[0]=0,primes[1]=0;
    for(int i=2;i<sqrt(n);i++)
      if(primes[i])
        for(int j=i;j<=n;j+=i)
          primes[j]=false;
  }

  int countPrimeSetBits(int left, int right) {
    int totalCount =0;
    int primes[right + 1] = { 1 };
    seiveOfErathonesis(primes,right);
    for(int i=left;i<=right;i++)
    {
      int totalSetBits = __builtin_popcount(i);
      if(primes[totalSetBits])
        totalCount++;
    }
    return totalCount;
  }
};

