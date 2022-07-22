// Question link :- https://www.pepcoding.com/resources/online-java-foundation/recursion-backtracking/target-sum-subsets-official/ojquestion
// Youtube video :- https://www.youtube.com/watch?v=tRpkluGqINc

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

  bool dp[n + 1][target + 1];
  for(int i=0;i<=n;i++)
    for(int j=0;j<=target;j++)
      dp[i][j]=false;
  for (int i = 0;i < n + 1;i++) {
    for (int j = 0;j < target + 1;j++) {
      // first cell
      if (i == 0 && j == 0)
        dp[i][j] = true;
      // first row
      else if (i == 0)
        dp[i][j] = false;
      // first column
      else if (j == 0)
        dp[i][j] = true;
      // rest of the cell
      else {
        // if the ith number does not participate
        if (j < arr[i - 1])
          dp[i][j] = dp[i - 1][j];
        // if the ith number participates
        if (j >= arr[i - 1])
          dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
      }
    }
  }
  cout << dp[n][target];
}