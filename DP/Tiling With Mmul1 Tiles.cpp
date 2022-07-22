// Question link :- https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/tiling2-official/ojquestion
// Youtube video :- https://www.youtube.com/watch?v=_c_R-uIi-zU

#include <bits/stdc++.h>
using namespace std;

// function to count the total number of ways
int countWays(int n, int m)
{
  int count[n + 1];
  count[0] = 0;
  for (int i = 1; i <= n; i++) {
    if (i > m)
      count[i] = count[i - 1] + count[i - m];
    // base cases and for i = m = 1
    else if (i < m || i == 1)
      count[i] = 1;
    // i == m
    else
      count[i] = 2;
  }
  return count[n];
}

int main()
{
  int n, m;
  cin >> n >> m;
  cout << countWays(n, m);
  return 0;
}
