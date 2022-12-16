#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

class Heap
{
private:
  int *array;
  int capacity, size;

public:
  Heap();
  void insert(int value);
};

Heap::Heap()
{
  cout << "Enter the capacity of the array :\n";
  cin >> capacity;
  array = new int[capacity];
  size = 0;
}

void Heap::insert(int value)
{
  if (size > capacity)
  {
    return;
  }
  array[size] = value;
  size++;
  int parent = size;
  while ()
  {
  }
}
