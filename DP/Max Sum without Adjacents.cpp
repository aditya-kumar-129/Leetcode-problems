// Question link :- https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1
// Youtube video :- https://www.youtube.com/watch?v=VT4bZV24QNo

#include <bits/stdc++.h>
using namespace std;

// Optimum method
// Space Complexity :- O(1)
class Solution {
public:
  int findMaxSum(int* arr, int n) {
    int include = arr[0];
    int exclude = 0;
    for (int i = 1;i < n;i++) {
      int newInclude = exclude + arr[i];
      int newExclude = max(include, exclude);
      include = newInclude;
      exclude = newExclude;
    }
    return max(include, exclude);
  }
};

// Brute Force Approach
// Space complexity :- O(2*n)
class Solution {
public:
  int findMaxSum(int* arr, int n) {
    int dp[2][n];
    for (int i = 0;i < 2;i++)
      for (int j = 0;j < n;j++)
        dp[i][j] = 0;

    dp[0][0] = arr[0];
    dp[1][0] = 0;
    for (int i = 1;i < n;i++) {
      for (int j = 0;j < 2;j++) {
        dp[0][i] = dp[1][i - 1] + arr[i];
        dp[1][i] = max(dp[0][i - 1], dp[1][i - 1]);
      }
    }
    return max(dp[0][n - 1], dp[1][n - 1]);
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    Solution ob;
    auto ans = ob.findMaxSum(arr, n);
    cout << ans << "\n";
  }
  return 0;
}