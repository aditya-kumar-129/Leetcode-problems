// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//   int no_of_vertex, no_of_edge;
//   vector<pair<int, int>> adj[no_of_vertex];

//   int source, destination, weight;
//   for (int i = 0;i < no_of_edge;i++)
//   {
//     cin >> source >> destination >> weight;
//     adj[source].push_back(make_pair(destination, weight));
//     adj[destination].push_back(make_pair(source, weight));
//   }

//   int parent[no_of_vertex];
//   int key[no_of_vertex];
//   bool mstSet[no_of_vertex];

//   for (int i = 0;i < no_of_vertex;i++)
//   {
//     key[i] = INT_MAX;
//     mstSet[i] = false;
//     parent[i] = -1;
//   }

//   key[0] = 0;
//   parent[0] = -1;

//   for (int count = 0;count < no_of_vertex - 1;count++)
//   {
//     // Finding the minimum value at each iteration which has not been included in the MST
//     int mini = INT_MAX, index;
//     for (int i = 0;i < no_of_vertex;i++)
//     {
//       if (mstSet[i] == false && key[i] < mini)
//       {
//         mini = key[i];
//         index = i;
//       }
//     }

//     // Setting its value to be true so that in the next iteration it will not be included.
//     mstSet[index] = true;

//     for (auto it : adj[index])
//     {
//       int adjacent_vertex = it.first;
//       int weight = it.second;
//       if (mstSet[adjacent_vertex] == false && weight < key[adjacent_vertex])
//       {
//         parent[adjacent_vertex] = index;
//         key[adjacent_vertex] = weight;
//       }
//     }
//   }

//   for (int i = 1;i < no_of_vertex;i++)
//     cout << parent[i] << "--->" << i << endl;
// }


// https://www.geeksforgeeks.org/prims-algorithm-using-priority_queue-stl/

#include<bits/stdc++.h>
using namespace std;

int main()
{
  int no_of_vertex, no_of_edge;
  vector<pair<int, int>> adj[no_of_vertex];

  int source, destination, weight;
  for (int i = 0;i < no_of_edge;i++)
  {
    cin >> source >> destination >> weight;
    adj[source].push_back(make_pair(destination, weight));
    adj[destination].push_back(make_pair(source, weight));
  }

  int parent[no_of_vertex];
  int key[no_of_vertex];
  bool mstSet[no_of_vertex];

  for (int i = 0;i < no_of_vertex;i++)
  {
    key[i] = INT_MAX;
    mstSet[i] = false;
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  key[0] = 0;
  parent[0] = -1;

  pq.push({ 0,0 });

  for (int count = 0;count < no_of_vertex - 1;count++)
  {
    // Finding the minimum value at each iteration which has not been included in the MST
    int vertex_to_be_inserted_in_MST = pq.top().second;
    pq.pop();

    // Setting its value to be true so that in the next iteration it will not be included.
    mstSet[vertex_to_be_inserted_in_MST] = true;

    for (auto it : adj[vertex_to_be_inserted_in_MST])
    {
      int adjacent_vertex = it.first;
      int weight = it.second;
      if (mstSet[adjacent_vertex] == false && weight < key[adjacent_vertex])
      {
        parent[adjacent_vertex] = vertex_to_be_inserted_in_MST;
        pq.push({ key[adjacent_vertex],adjacent_vertex });
        key[adjacent_vertex] = weight;
      }
    }
  }

  for (int i = 1;i < no_of_vertex;i++)
    cout << parent[i] << "--->" << i << endl;
}