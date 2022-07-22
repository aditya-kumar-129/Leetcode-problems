// Question link :- https://www.pepcoding.com/resources/online-java-foundation/dynamic-programming-and-greedy/partition-into-subsets-official/ojquestion
// Youtube video :- https://www.youtube.com/watch?v=IiAsqfjhZnY

#include <bits/stdc++.h>
using namespace std;

int main() {
  long long int no_of_people, no_of_teams;
  cin >> no_of_people >> no_of_teams;
  if (no_of_people == 0 || no_of_teams == 0 || no_of_people < no_of_teams) {
    cout << 0;
    return 0;
  }

  vector<vector<long long int>> dp(no_of_teams + 1, vector<long long int>(no_of_people + 1,0));
  for (long long int teams = 1;teams <= no_of_teams;teams++) {
    for (long long int people = 1;people <= no_of_people;people++) {
      if (teams > people) {
        dp[teams][people] = 0;
      }
      else if (teams == people) {
        dp[teams][people] = 1;
      }
      else {
        dp[teams][people] = (dp[teams][people - 1] * teams) + dp[teams - 1][people - 1];
      }
    }
  }
  cout << dp[no_of_teams][no_of_people];
}