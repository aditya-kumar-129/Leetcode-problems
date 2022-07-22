// Question link :- https://leetcode.ca/all/265.html
// Youtube video :- https://www.youtube.com/watch?v=kh48JLieeW8

#include <bits/stdc++.h>
using namespace std;

// Optimised Approach
// Time complexity :- O(n^2)
int main()
{
  int n; cin >> n;
  int no_of_colors; cin >> no_of_colors;

  vector<vector<int> > costs(n, vector<int>(no_of_colors, 0));
  for (int i = 0;i < costs.size();i++)
    for (int j = 0;j < costs[0].size();j++)
      cin >> costs[i][j];

  vector<vector<int> > dp(n, vector<int>(no_of_colors, 0));
  int least = INT_MAX;
  int second_least = INT_MAX;
  for (int j = 0;j < costs[0].size();j++) {
    dp[0][j] = costs[0][j];
    // Finding the least and second least value of the 1st row
    if (costs[0][j] <= least) {
      second_least = least;
      least = costs[0][j];
    }
    else if (costs[0][j] <= second_least)
      second_least = costs[0][j];
  }

  for (int i = 1; i < dp.size(); i++) {
    int new_least = INT_MAX;
    int new_second_least = INT_MAX;
    for (int j = 0;j < dp[0].size();j++) {
      if (least == dp[i - 1][j])
        dp[i][j] = costs[i][j] + second_least;
      else
        dp[i][j] = costs[i][j] + least;
      // Finding the least and second least value of the generated row so that these values can be used in the next iteration
      if (dp[i][j] <= new_least) {
        new_second_least = new_least;
        new_least = dp[i][j];
      }
      else if (dp[i][j] <= new_second_least)
        new_second_least = dp[i][j];
    }
    // Updating the least and second least value
    least = new_least;
    second_least = new_second_least;
  }
  cout << least;
  return 0;
}

// Brute Force Approach
// Time complexity :- O(n^3)
int main()
{
  int n; cin >> n;
  int no_of_colors; cin >> no_of_colors;

  vector<vector<int> > costs(n, vector<int>(no_of_colors, 0));
  for (int i = 0;i < costs.size();i++)
    for (int j = 0;j < costs[0].size();j++)
      cin >> costs[i][j];

  vector<vector<int> > dp(n, vector<int>(no_of_colors, 0));
  for (int j = 0;j < costs[0].size();j++)
    dp[0][j] = costs[0][j];

  for (int i = 1; i < dp.size(); i++) {
    for (int j = 0;j < dp[0].size();j++) {
      int minimum_value = INT_MAX;
      for (int k = 0;k < costs[0].size();k++)
        if (j != k)
          minimum_value = min(minimum_value, dp[i - 1][k]);

      dp[i][j] = minimum_value + costs[i][j];
    }
  }
  int ans = INT_MAX;
  for (int j = 0;j < dp[0].size();j++)
    ans = min(ans, dp[n - 1][j]);

  cout << ans;
  return 0;
}