// Question link :- https://leetcode.com/problems/minimum-path-sum/
// Youtube video :- https://www.youtube.com/watch?v=bUSaenttI24

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int knapSack(int bagCapacity, int weight[], int profit[], int size)
  {
    int dp[size + 1][bagCapacity + 1];

    for (int i = 0;i <= size;i++) {
      for (int j = 0;j <= bagCapacity;j++) {
        // first cell
        if (i == 0 && j == 0)
          dp[i][j] = 0;
        // first row
        else if (i == 0)
          dp[i][j] = 0;
        // first column
        else if (j == 0)
          dp[i][j] = 0;
        // remaining cell
        else
        {
          // If we choose the current object
          if (j - weight[i - 1] >= 0)
            dp[i][j] = max(profit[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
          // if we don't choose the current object 
          else
            dp[i][j] = dp[i - 1][j];
        }
      }
    }
    return dp[size][bagCapacity];
  }
};

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, w;
    cin >> n >> w;
    int val[n];
    int wt[n];
    for (int i = 0;i < n;i++)
      cin >> val[i];
    for (int i = 0;i < n;i++)
      cin >> wt[i];
    Solution ob;
    cout << ob.knapSack(w, wt, val, n) << endl;
  }
  return 0;
}