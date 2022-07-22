// Question link :- https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/j-change-permutations-official/ojquestion
// Youtube video :- https://www.youtube.com/watch?v=yc0LunmJA1A
#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0;i < n;i++)
    cin >> arr[i];
  int target;
  cin >> target;

  int dp[target + 1];
  for (int i = 0;i <= target;i++)
    dp[i] = 0;

  dp[0] = 1;
  for (int i = 1;i < target + 1;i++)
    for (int j = 0;j < n;j++)
      if (arr[j] <= i)
        dp[i] += dp[i - arr[j]];
  cout << dp[target];
}