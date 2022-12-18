#include <iostream>

using namespace std;

void Selection_Sort(int array[], int size) {
  for (int i = 0; i < size; i++) {
    int min = i;
    for (int j = i; j < size; j++) {
      if (array[j] < array[min]) {
        min=j;
      }
    }
    swap(array[min], array[i]);
  }
}

int main() {
  int array[] = {10, 524, 1241, 315, 25134, 1346, 611, 526, 35, 21671};
  Selection_Sort(array, 10);
  for (int i = 0; i < 10; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
  return 0;
}




