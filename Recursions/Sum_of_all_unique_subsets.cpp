#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void subset_sum(vector<int> ip, vector<int>& final, int index, int sum)
{
  if (index == ip.size())
  {
    final.push_back(sum);
    return;
  }
  for (int i = index; i < ip.size(); i++)
  {
    if (ip[i] == ip[i - 1] && i != index)
    {
      continue;
    }
    subset_sum(ip, final, index + 1, sum += ip[index]);
    subset_sum(ip, final, index + 1, sum -= ip[index]);
  }
}

int main()
{
  vector<int> ip = { 1, 1, 1, 5, 3, 3, 6, 6 }, final;
  sort(ip.begin(), ip.end());
  subset_sum(ip, final, 0, 0);
  sort(final.begin(),final.end());
  for (auto i : final)
  {
    cout << i << " ";
  }
  return 0;
}
