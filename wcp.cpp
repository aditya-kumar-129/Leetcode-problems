#include<bits/stdc++.h>
using namespace std;

void dfs(vector<pair<int, int>> graph[], int starting_house_no, int& minimum_weight, vector<bool>& vis, int& ending_house_no)
{
  vis[starting_house_no] = true;
  for (auto i : graph[starting_house_no])
  {
    if (vis[i.first] == false)
    {
      minimum_weight = min(minimum_weight, i.second);
      ending_house_no = i.first;
      dfs(graph, i.first, minimum_weight, vis, ending_house_no);
    }
  }
}

vector<vector<int>> solve(int no_of_house, int no_of_pipes, vector<int> a, vector<int> b, vector<int> d)
{
  vector<vector<int>> ans;
  vector<bool> in(no_of_house + 1, false);
  vector<bool> out(no_of_house + 1, false);
  vector<bool> vis(no_of_house + 1, false);

  vector<pair<int, int>> graph[no_of_house + 1];

  for (int i = 0; i < a.size(); i++)
  {
    in[b[i]] = true;
    out[a[i]] = true;
    graph[a[i]].push_back(make_pair(b[i], d[i]));
  }

  for (int starting_house_no = 1; starting_house_no <= no_of_house; starting_house_no++)
  {
    if (in[starting_house_no] == false && out[starting_house_no] == true && vis[starting_house_no] == false)
    {
      int minimum_weight = INT_MAX;
      int ending_house_no;
      dfs(graph, starting_house_no, minimum_weight, vis, ending_house_no);
      ans.push_back({ starting_house_no, ending_house_no, minimum_weight });
    }
  }
  return ans;
}

int main()
{
  int no_of_house = 9, no_of_pipes = 6;
  vector <int> a = { 7,5,4,2,9,3 };
  vector <int> b = { 4,9,6,8,7,1 };
  vector <int> w = { 98,72,10,22,17,66 };
  vector<vector<int>> ans = solve(no_of_house, no_of_pipes, a, b, w);
  for (auto it : ans)
  {
    for (auto e : it)
      cout << e << " ";
    cout << endl;
  }
}