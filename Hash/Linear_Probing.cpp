#include <iostream>

using namespace std;

#define SIZE 10

class Linear_Probing {
private:
  int array[SIZE];
  int hash(int value);

public:
  Linear_Probing();
  void insert(int value);
  void display();
  int search(int value);
};

Linear_Probing::Linear_Probing() {
  for (int i = 0; i < SIZE; i++) {
    array[i] = -1;
  }
}

int Linear_Probing::hash(int value) {
  int i = 0, index = value % 10;
  while (array[index + i] % SIZE != -1) {
    i++;
  }
  return (index + i) % SIZE;
}

void Linear_Probing::insert(int value) {
  int index = hash(value);
  array[index] = value;
  return;
}

void Linear_Probing::display() {

  for (int i = 0; i < SIZE; i++) {
    cout << array[i] << " ";
  }
}

int Linear_Probing::search(int value) {
  int index = value % SIZE;
  int i = 0;
  while (array[(index + i) % SIZE] != value) {
    i++;
  }
  if (array[(index + i) % 10] == value) {
    return 1;
  }
  return 0;
}

int main() {
  Linear_Probing l;
  l.insert(10);
  l.insert(14);
  l.insert(24);
  l.insert(33);
  l.insert(2);
  l.insert(1);
  l.insert(200);
  l.display();
  return 0;
}
