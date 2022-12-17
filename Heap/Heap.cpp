#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Heap
{
public:
  int *array;
  int capacity, size;
  int compare_child(int i);

public:
  Heap();
  void insert(int value);
  void display();
  int Delete();
  void Heap_Sort();
  void display_array();
};

void Heap::display_array()
{
  for (int i = 0; i < size; i++)
  {
    cout << array[i] << " ";
  }
}

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
  int current = size - 1, parent = floor((current) / 2);
  while (parent != current && array[current] > array[parent])
  {
    swap(array[current], array[parent]);
    current = parent;
    parent = floor((current) / 2);
  }
}

void Heap::display()
{
  int count = 0, power = 0;
  for (int i = 0; i < size; i++)
  {
    cout << array[i] << " ";
    if (power == i)
    {
      cout << endl;
      count++;
      power += pow(2, count);
    }
  }
  cout << endl;
}

int Heap::compare_child(int i)
{
  if ((2 * i + 2) < size)
  {
    if (array[2 * i + 1] < array[2 * i + 2])
    {
      return 2 * i + 2;
    }
    else
    {
      return 2 * i + 1;
    }
  }
  else if ((2 * i + 1) < size)
  {
    return 2 * i + 1;
  }
  else
  {
    return -1;
  }
}

int Heap::Delete()
{
  int res = array[0];
  int current = 0;
  swap(array[current], array[size - 1]);
  size--;
  int swap_child = compare_child(current);
  if (swap_child == -1)
  {
    return res;
  }
  while (array[current] < array[swap_child])
  {
    swap(array[current], array[swap_child]);
    current = swap_child;
    swap_child = compare_child(current);
    if (swap_child == -1)
    {
      return res;
    }
  }
  return res;
}

void Heap::Heap_Sort()
{
  int *new_array = new int[size];
  int size_backup = size;
  for (int i = 0; i < size_backup; i++)
  {
    new_array[i] = Delete();
  }
  for (int j = 0; j < size_backup; j++)
  {
    array[j] = new_array[j];
  }
  size = size_backup;
  delete[] new_array;
}

int main()
{
  Heap h;
  vector<int> v = {10, 27, 38, 82, 101, 9, 7, 6, 5, 3};
  for (auto i : v)
  {
    h.insert(i);
  }
  h.display();
  cout << endl;
  h.Heap_Sort();
  h.display_array();
  cout << endl;
  return 0;
}
