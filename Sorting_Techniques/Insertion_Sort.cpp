#include <algorithm>
#include <iostream>
#include <type_traits>
#include <utility>

using namespace std;

void swap(int *a, int *b) {
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

void Insertion_Sort(int array[], int size) {
  int  j, x;

  for (int i = 1; i < size; i++) {
    j = i - 1;
    x = array[i];
    while (j > -1 && array[j] > x) {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = x;
  }
}

int main() {
  int array[] = {10, 524, 1241, 315, 25134, 1346, 611, 526, 35, 21671};
  Insertion_Sort(array, 10);
  for (int i = 0; i < 10; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
  return 0;
}
