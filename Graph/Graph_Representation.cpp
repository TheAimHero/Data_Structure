/*
The first input that are given are two numbers n and m
n represents the number of nodes and m represents the number of edges
eg. 4 4 -- this means that there are four nodes and 4 edges
the next given input is of m lines that has the information about the nodes
eg. 1,4 -- this tells that there is a edge between 1 and 4

there is no relation between the number of nodes and the number of edges
 */

/*
There are two ways in which a graph can be stored that are  Adjacency Matrix and Adjacency List

Adjacency Matrix :
  We have to check if the nodes have 1 or 0 based indexing
  If they have 1 based indexing then we have to create a matrix M of dimension M[n+1][n+1]
  Then we mark the edges at their respective places
    eg. edge 1,4 will be marked as M[1][4]=1 and M[4][1]=1 (in case of weighted graph we will mark the position with the given weight)

Adjacency List :
  We use array of empty list to store the edges
    eg. vector<int> arr[n+1] (if we have to store a weighted matrix we will create a array of vectors with pairs in it )
      (the first element will contain the neighbour and the second element will contain the weight of the node)
  Then we push the edges in their respective places
    eg. edge 1,4 will be stored as
      arr[1].push_back(4);
      arr[4].push_back(1);

 */

#include <iostream>
#include <vector>

using namespace std;

void Adjacency_Matrix()
{
  int n, m;
  cin >> n >> m;
  int arr[m + 1][m + 1];
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    arr[a][b] = 1;
    arr[b][a] = 1;
  }
}

void Adjacency_List()
{
  int n, m;
  cin >> n >> m;
  vector<int> arr[n + 1];
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    arr[a].push_back(b);
    arr[b].push_back(a);
  }
}
