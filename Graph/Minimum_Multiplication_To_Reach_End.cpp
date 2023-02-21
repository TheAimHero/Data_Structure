#include <bits/stdc++.h>

using namespace std;
/*
3
2 5 7
3 30
*/
class Solution
{
  public:
  int minimumMultiplications(vector<int>& arr, int start, int end)
  {
    vector<int> steps(1e5, 1e9);
    queue<pair<int, int>> q;  // steps,number
    q.push({ 0, start });
    steps[start] = 0;
    while (!q.empty())
    {
      pair<int, int> current = q.front();
      int current_steps = current.first, current_number = current.second;
      q.pop();
      for (auto i : arr)
      {
        int number = (current_number * i) % 100000;
        if (steps[number] > current_steps + 1)
        {
          steps[number] = current_steps + 1;
          if (number == end)
          {
            return current_steps + 1;
          }
          q.push({ current_steps + 1, number });
        }
      }
    }
    return -1;
  }
};

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  int start, end;
  cin >> start >> end;
  Solution obj;
  cout << obj.minimumMultiplications(arr, start, end) << endl;
}
