#include <iostream>

using namespace std;

void merge(int array[], int low, int high, int part)
{
  int i = low, j = part + 1;
  int array_temp[high - low + 1], k = 0;
  while (i <= part && j <= high)
  {
    if (array[i] < array[j])
    {
      array_temp[k] = array[i];
      i++;
      k++;
    }
    else
    {
      array_temp[k] = array[j];
      j++;
      k++;
    }
  }
  for (; i <= part; i++)
  {
    array_temp[k] = array[i];
    k++;
  }
  for (; j <= high; j++)
  {
    array_temp[k] = array[j];
    k++;
  }
  k = 0;
  for (int p = low; p <= high; p++)
  {
    array[p] = array_temp[k];
    k++;
  }
}

void Merge_Sort(int array[], int size)
{
  int i = 2, high, low, mid;
  for (; i <= size; i = i * 2)
  {
    for (int j = 0; i + j - 1 <= size; j = j + i)
    {
      low = j;
      high = j + i - 1;
      mid = (low + high) / 2;
      merge(array, low, high, mid);
    }
    if (high < size)
    {
      merge(array, high + 1, size, (high + (i / 2)));
    }
  }
  if ((i / 2) - 1 < size)
  {
    merge(array, 0, size, (size / 2));
  }
}

int main()
{
  int array[] = {10, 524, 34, 487, 624, 167, 8548, 35,
                 68, 624, 1315, 134, 526, 1346, 1611};
  Merge_Sort(array, 14);
   for (int i = 0; i < 15; i++) {
      cout << array[i] << " ";
    }
    cout << endl;
  return 0;
}
