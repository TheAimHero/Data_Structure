#include <iostream>

using namespace std;

#define SIZE 10

class Double_Hashing {
private:
  int array[SIZE];
  int hash(int value);

public:
  Double_Hashing();
  void insert(int value);
  void display();
  int search(int value);
};

Double_Hashing::Double_Hashing() {
  for (int i = 0; i < SIZE; i++) {
    array[i] = -1;
  }
}

int Double_Hashing::hash(int value) {
  int i = 0, index = value % 10;
  while (array[(index + i * (7 * (value % 7))) % SIZE] != -1) {
    i++;
  }
  return (index + i * (7 * (value % 7))) % SIZE;
}

void Double_Hashing::insert(int value) {
  int index = hash(value);
  array[index] = value;
  return;
}

void Double_Hashing::display() {

  for (int i = 0; i < SIZE; i++) {
    cout << array[i] << " ";
  }
}

int Double_Hashing::search(int value) {
  int i = 0, index = value % SIZE;
  for (int i = 0; i < SIZE; i++) {
    if (array[index + (i * (7 - (value % 7))) % SIZE]) {
      return index + (i * (7 - (value % 7))) % SIZE;
    }
  }
  cout << "Element not found ";
  return -1;
}

int main() {
  Double_Hashing l;
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
