#include <climits>
#include <iostream>
#include <limits>

using namespace std;

int partition(int array[], int low, int high) {
  int i = low, j = high;
  int pivot = array[i];
  do {
    do {
      i++;
    } while (array[i] <= pivot);
    do {
      j--;
    } while (array[j] > pivot);
    if(i<j){swap(array[i],array[j]);}
  } while (i < j);
  swap(array[low], array[j]);
  return j;
}

void Quick_Sort(int array[], int low, int high) {
  int part;
  if (low < high) {
    part = partition(array, low, high);
    Quick_Sort(array, low, part);
    Quick_Sort(array, part + 1, high);
  }
}

int main() {
  int array[] = {10,  524, 1241, 315,   25134,    1346,
                 611, 526, 35,   21671, INT32_MAX};
  Quick_Sort(array, 0, 10);
  for (int i = 0; i < 10; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
  return 0;
}
