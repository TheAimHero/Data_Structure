#include <cstddef>
#include <functional>
#include <iostream>

using namespace std;

class node {
public:
  int data;
  node *next;
};

class Hash {
public:
  node *hash_array[10];
  int hash(int value);
  node *new_node(int value);

public:
  Hash();
  int search(int value);
  void insert(int value);
};

int Hash::search(int value) {
  int index = hash(value);
  node *temp = hash_array[index];
  while (temp != NULL && temp->data <= value) {
    if (temp->data == value) {
      return temp->data;
    }
  temp = temp->next;
  }
  return -1;
}

Hash::Hash() {
  for (int i = 0; i < 10; i++) {
    hash_array[i] = NULL;
  }
}

int Hash::hash(int value) { return value % 10; }

node *Hash::new_node(int value) {
  node *temp = new node;
  temp->data = value;
  temp->next = NULL;
  return temp;
}

void Hash::insert(int value) {
  int index = hash(value);
  node *temp = hash_array[index];
  if (temp == NULL) {
    hash_array[index] = new_node(value);
    return;
  }
  if (temp->data > value) {

    node *bkp = temp;
    temp = new_node(value);
    temp->next = bkp;
    return;
  }
  while (temp->next != NULL && temp->next->data < value) {
    temp = temp->next;
  }
  node *bkp = temp->next;
  temp->next = new_node(value);
  temp->next->next = bkp;
}

int main() {
  Hash h;
  h.insert(10);
  h.insert(20);
  h.insert(21);
  cout<<h.search(21);
  cout << "\n";
}
