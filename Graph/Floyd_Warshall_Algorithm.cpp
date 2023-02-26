#include <bits/stdc++.h>
using namespace std;
/*
2
0 25
-1 0
*/
class Solution
{
  public:
  void shortest_distance(vector<vector<int>>& matrix)
  // this is a short method with three for loop
  {
    int node = matrix.size();
    for (int via = 0; via < node; via++)
    {
      for (int from = 0; from < node; from++)
      {
        for (int to = 0; to < node; to++)
        {
          if (matrix[from][via] != -1 && matrix[to][via] != -1)  // check if the path between form-->via exist and the path between via-->to exist
          {
            if (matrix[from][to] == -1)  // if the path exist then check if we are visiting the node for the first time and that node does not already have a preassigned weight that is is the value at that node equal to -1
            {
              matrix[from][to] = matrix[from][via] + matrix[via][to];  // if that is the case then it will have a value of the summantion of the distance between from--> via + via-->to
            }
            else
            {
              matrix[from][to] = min(matrix[from][to], matrix[from][via] + matrix[via][to]);  // and if we are not visiting the node for the first time then it will have the minimum value of the current value and the new distance via a new path
            }
          }
        }
      }
    }
  }
  /* {
    // Tripple for loop method
    int node = matrix.size();
    for (int from = 0; from < node; from++)
    {
      for (int to = 0; to < node; to++)
      {
        if (matrix[from][to] == -1)
        {
          matrix[from][to] = 1e9;
        }
        if (from == to)
        {
          matrix[from][to] = 0;
        }
      }
    }
    for (int via = 0; via < node; via++)
    {
      for (int from = 0; from < node; from++)
      {
        for (int to = 0; to < node; to++)
        {
          matrix[from][to] = min(matrix[from][to], matrix[from][via] + matrix[via][to]);
        }
      }
    }

    for (int from = 0; from < node; from++)
    {
      for (int to = 0; to < node; to++)
      {
        // to detect negative cycle
        //  if (matrix[form][to] < 0)
        // {
        //   cout << "Negative Cycle Detected\n";
        //   return;
        // }
        if (matrix[from][to] == 1e9)
        {
          matrix[from][to] = -1;
        }
      }
    }
    return;
  } */
};

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> matrix(n, vector<int>(n, -1));
  for (int i = 0; i < n; i++)

    for (int j = 0; j < n; j++)

      cin >> matrix[i][j];

  Solution obj;
  obj.shortest_distance(matrix);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << matrix[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}
