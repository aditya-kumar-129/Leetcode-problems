#include<bits/stdc++.h>
using namespace std;

int fun(vector<int> v, int k)
{
  unordered_map<int, int> m;
  int n = v.size();
  if (n < k)
    return -1;

  int maxi = -1, sum = 0;
  for (int i = 0;i < k;i++) {
    m[v[i]]++;
    sum += v[i];
  }

  for (int i = 1;i < n - k;i++) {
    m[v[i - 1]]--;
    if (m[v[i - 1]] == 0)
      m.erase(v[i - 1]);
    m[v[i + k - 1]]++;
    sum = sum - v[i - 1] + v[i + k - 1];
    if (m.size() == k)
      maxi = max(maxi, sum);
  }
  return maxi;
}

int main()
{
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0;i < n;i++)
    cin >> v[i];
  int k;
  cin >> k;
  int b = fun(v, k);
  cout << b;
}