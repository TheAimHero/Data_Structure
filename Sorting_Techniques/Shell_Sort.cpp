#include <iostream>

using namespace std;

void Shell_Sort(int array[], int size) {
  for (int gap = size / 2; gap >=1 ; gap /= 2) {
    for (int i = gap; i < size; i++) {
      int temp = array[i];
      int j=i-gap;
      while (j > 0 && array[j] > temp) {
        array[j + gap] = array[j];
        j = j - gap;
      }
      array[j+gap]=temp;
    }
  }
}

int main() {
  int array[] = {10, 524, 1241, 315, 25134, 1346, 611, 526, 35, 21671};
  Shell_Sort(array, 10);
  for (int i = 0; i < 10; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
  return 0;
}
