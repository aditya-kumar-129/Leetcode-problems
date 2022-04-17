#include<bits/stdc++.h>
using namespace std;

struct node {
  int source, destination, weight;
  node(int source, int destination, int weight) {
    this->source = source;
    this->destination = destination;
    this->weight = weight;
  }
};

bool comp(node a, node b)
{
  return a.weight < b.weight;
}

int findParent(int vertex, vector<int>& parent)
{
  if (vertex == parent[vertex])  return vertex;
  return findParent(parent[vertex], parent);
}

void unionn(int vertex1, int vertex2, vector<int>& parent, vector<int>& rank)
{
  vertex1 = findParent(vertex1, parent);
  vertex2 = findParent(vertex2, parent);
  if (rank[vertex1] < rank[vertex2])
    parent[vertex2] = vertex1;
  else if (rank[vertex1] > rank[vertex2])
    parent[vertex1] = vertex2;
  else
  {
    parent[vertex2] = vertex1;
    rank[vertex1]++;
  }
}

int main()
{
  int no_of_vertex, no_of_edge;
  cin >> no_of_vertex >> no_of_edge;
  vector<node> edges;
  for (int i = 0;i < no_of_edge;i++)
  {
    int u, v, wt;
    cin >> u >> v >> wt;
    edges.push_back(node(u, v, wt));
  }
  sort(edges.begin(), edges.end(), comp);
  vector<int> parent(no_of_vertex);
  // Implementing DSU
  for (int i = 0;i < no_of_vertex;i++)
    parent[i] = i;
  vector<int> rank(no_of_vertex, 0);
  int cost = 0;
  vector<pair<int, int>> mst;
  for (auto it : edges)
  {
    if (findParent(it.destination, parent) != findParent(it.source, parent))
    {
      cost += it.weight;
      mst.push_back({ it.source,it.destination });
      unionn(it.source, it.destination, parent, rank);
    }
  }
  cout << cost << endl;
  for (auto it : mst)
    cout << it.first << "--->" << it.second << endl;
  return 0;
}