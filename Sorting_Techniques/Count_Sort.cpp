#include <algorithm>
#include <iostream>

using namespace std;

void Count_Sort(int array[], int size) {
  int max = *max_element(array, array + size);
  max++;
  int *hash = new int[max]{};
  for (int i = 0; i < size; i++) {
    hash[array[i]]++;
  }
  int k = 0;
  for (int j = 0; j < max; j++) {
    while (hash[j] > 0) {
      array[k] = j;
      hash[j]--;
      k++;
    }
  }
}

int main() {
  int array[] = {10, 524, 34,   487, 624, 167,  8548, 35,
                 68, 624, 1315, 134, 526, 1346, 1611};
  Count_Sort(array, 15);
  for (int i = 0; i < 15; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
  return 0;
}
