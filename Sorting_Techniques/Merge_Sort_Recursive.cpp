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

void Merge_Sort_Recursive(int array[],int low,int high)
{
  if (low<high) {
 int mid=(low+high)/2;
    Merge_Sort_Recursive(array , low, mid);
    Merge_Sort_Recursive(array , mid+1 , high );
    merge(array , low, high, mid);
  }
}

int main()
{
  int array[] = {10, 524, 34, 487, 624, 167, 8548, 35,
                 68, 624, 1315, 134, 526, 1346, 1611};
  Merge_Sort_Recursive(array,0, 14);
   for (int i = 0; i < 15; i++) {
      cout << array[i] << " ";
    }
    cout << endl;
  return 0;
}
