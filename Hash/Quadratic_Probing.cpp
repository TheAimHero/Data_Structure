#include <cmath>
#include <iostream>

using namespace std;

#define SIZE 10

class Quadratic_Probing {
private:
  int array[SIZE];
  int hash(int value);

public:
  Quadratic_Probing();
  void insert(int value);
  void display();
  int search(int value);
};

Quadratic_Probing::Quadratic_Probing() {
  for (int i = 0; i < SIZE; i++) {
    array[i] = -1;
  }
}

int Quadratic_Probing::hash(int value) {
  int i = 0, index = value % 10;
  for (int i = 0; i < SIZE; i++) {
    if (array[index + int(pow(i, 2))] % SIZE == -1) {
      return (index + int(pow(i, 2))) % SIZE;
    }
  }
  cout << "Array full";
  return -1;
}

void Quadratic_Probing::insert(int value) {
  int index = hash(value);
  array[index] = value;
  return;
}

void Quadratic_Probing::display() {

  for (int i = 0; i < SIZE; i++) {
    cout << array[i] << " ";
  }
}

int Quadratic_Probing::search(int value) {
  int index = value % 10;
  for (int i = 0; i < SIZE; i++) {
    if (array[(index + int(pow(i, 2))) % SIZE]==value) {
      return (index + int(pow(i, 2))) % SIZE;
    }
  }
  cout << "Not found";
  return -1;
}

int main() {
  Quadratic_Probing l;
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
