#include <algorithm>
#include <iostream>

using namespace std;

void
Bubble_Sort (int arrray[], int size)
{
  for (int i = 0; i < size; i++)
    {
      bool flag = true;
      for (int j = 1; j < size; j++)
        {
          if (arrray[j] > arrray[j - 1])
            {
              swap (arrray[j], arrray[j - 1]);
              flag = false;
            }
        }
      if (flag)
        {
          return;
        }
    }
  return;
}
int
main ()
{
  int array[] = { 12, 34, 64, 13, 6375, 14, 62, 554 };
  Bubble_Sort (array, 8);
  for (int i = 0; i < 8; i++)
    {
      cout << array[i] << " ";
    }
  return 0;
}
