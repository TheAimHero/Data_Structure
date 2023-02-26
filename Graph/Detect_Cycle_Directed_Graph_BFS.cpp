#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

pair<vector<int>, vector<vector<int>>> Adj_list(int node, int edges)  // create the graph from the edges given
{
  int u, v;
  vector<vector<int>> store(node);
  vector<int> in_degree(node, 0);
  for (int i = 0; i < edges; i++)
  {
    cin >> u >> v;
    store[u].push_back(v);
    in_degree[v]++;  // calcualate the in_degree
    // in_degree is the number of edges going in-to a particular node
  }
  pair<vector<int>, vector<vector<int>>> store_pair;
  store_pair.first = in_degree;
  store_pair.second = store;
  return store_pair;
}

int Topo_Sort(vector<vector<int>> ip, vector<int>& in_degree, queue<int>& q, int node)  // topo sort does not work in a cyclic
// and if the algorithm does not work then it indicates that the graph has a cycle
{
  int count{};
  while (!q.empty())
  {
    int current = q.front();
    q.pop();
    count++;  // if this count turns out to be equal to the number of nodes then it can be said that no cycle exist
    // but if the cycle exist then the in_degree for all the nodes will become zero without visiting all the nodes and the count will remain less than the number of nodes
    for (auto i : ip[current])
    {
      in_degree[i]--;  // reduce the in_degree if the node is visited
      if (in_degree[i] == 0)  // if the in_degree is zero push in queue
      {
        q.push(i);
      }
    }
  }
  return count;
}

int main()
{
  int node, edges;
  cin >> node >> edges;
  pair<vector<int>, vector<vector<int>>> store_pair = Adj_list(node, edges);
  vector<vector<int>> ip = store_pair.second;
  vector<int> visited(node, 0), in_degree = store_pair.first;
  queue<int> q;
  for (int i = 0; i < node; i++)
  {
    if (in_degree[i] == 0)
    {
      q.push(i);  // initial setup of the Topo_Sort algorithm involves pushing all the nodes with initial in_degree as zero in the queue
      // this is becuase the nodes with in_degree as zero can never be a part of a cycle
    }
  }
  int count = Topo_Sort(ip, in_degree, q, node);
  if (count == node)
  {
    std::cout << "Cycle Not Detected" << std::endl;
  }
  else
  {
    std::cout << "Cycle Detected" << std::endl;
  }
  return 0;
}
