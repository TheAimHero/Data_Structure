#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

class Heapify {
private:
public:
  void make_heap(int array[], int size);
  int compare_child(int array[], int i, int size);
  void display(int array[],int size);
};

int Heapify::compare_child(int array[], int i, int size) {
  if ((2 * i + 2) < size) {
    if (array[2 * i + 1] < array[2 * i + 2]) {
      return 2 * i + 2;
    } else {
      return 2 * i + 1;
    }
  } else if ((2 * i + 1) < size) {
    return 2 * i + 1;
  } else {
    return -1;
  }
}

void Heapify::make_heap(int array[], int size) {
  int current = size - 1;
  while (current >= 0) {
    int swap_child = compare_child(array, current, size);
    if (swap_child == -1) {
      current--;
      continue;
    } else if (array[current] < array[swap_child]) {
      swap(array[current], array[swap_child]);
      current = swap_child;
      continue;
    } else {
      current--;
    }
  }
  return;
}

void Heapify::display(int array[], int size)
{
    for (int i = 0; i < size; i++) {

    cout << array[i] << " ";
  
}}

int main() {
  Heapify h;
  int *array = new int[10]{5, 10, 30, 20, 35, 40, 15};
  h.make_heap(array, 7);
    h.display(array, 7);
  cout << endl;

  return 0;
}
