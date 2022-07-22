// Question link :- https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/count-a+b+c+subsequences-official/ojquestion
// Youtube video :- https://www.youtube.com/watch?v=IV9pbZsi5cc

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int fun(string& s) {
    int n = s.size();
    int a =0;
    int ab =0;
    int abc =0;

    for(int i=0;i<n;i++){
      if(s[i]=='a')
        a = 2*a+1;
      else if(s[i]=='b')
        ab = 2*ab + a;
      else
        abc = 2*abc + ab;
    }
    return abc;
  }
};