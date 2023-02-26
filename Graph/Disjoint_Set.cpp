#include <iostream>
#include <vector>

using namespace std;

class Disjoint_Set
{
  private:
  vector<int> parent, rank, size;

  public:
  Disjoint_Set(int nodes)
  {
    parent.resize(nodes + 1);
    rank.resize(nodes + 1, 1);
    size.resize(nodes + 1, 1);
    for (int i = 0; i <= nodes; i++)
    {
      parent[i] = i;
    }
  }

  int Find_parent(int node)
  {
    if (parent[node] == node)
    {
      return node;
    }
    return parent[node] = Find_parent(parent[node]);
  }

  void Union_By_Rank(int node1, int node2)
  {
    int ultimate_parent_node1 = Find_parent(node1);
    int ultimate_parent_node2 = Find_parent(node2);
    if (ultimate_parent_node1 == ultimate_parent_node2) return;
    if (rank[ultimate_parent_node1] > rank[ultimate_parent_node2])
    {
      parent[ultimate_parent_node2] = ultimate_parent_node1;
    }
    else if (rank[ultimate_parent_node1] < rank[ultimate_parent_node2])
    {
      parent[ultimate_parent_node1] = ultimate_parent_node2;
    }
    else
    {
      parent[ultimate_parent_node2] = ultimate_parent_node1;
      rank[ultimate_parent_node1]++;
    }
  }

  void Union_By_Size(int node1, int node2)
  {
    int ultimate_parent_node1 = Find_parent(node1);
    int ultimate_parent_node2 = Find_parent(node2);
    if (ultimate_parent_node1 == ultimate_parent_node2) return;
    if (size[ultimate_parent_node1] > size[ultimate_parent_node2])
    {
      parent[ultimate_parent_node2] = ultimate_parent_node1;
      size[ultimate_parent_node1] += size[ultimate_parent_node2];
    }
    else
    {
      parent[ultimate_parent_node2] = ultimate_parent_node1;
      size[ultimate_parent_node1] += size[ultimate_parent_node2];
    }
  }
};

int main()
{
  Disjoint_Set dj(7);
  dj.Union_By_Rank(1, 2);
  dj.Union_By_Rank(2, 3);
  dj.Union_By_Rank(4, 5);
  dj.Union_By_Rank(6, 7);
  dj.Union_By_Rank(5, 6);
  if (dj.Find_parent(3) == dj.Find_parent(7))
  {
    cout << "Same\n";
  }
  else
  {
    cout << "Not Same\n";
  }
  dj.Union_By_Rank(3, 7);
  if (dj.Find_parent(3) == dj.Find_parent(7))
  {
    cout << "Same\n";
  }
  else
  {
    cout << "Not Same\n";
  }
  return 0;
}
