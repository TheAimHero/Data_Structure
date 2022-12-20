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
  node **hash_array;
  int hash(int value); 
  node *new_node(int value);
 public:
  void Insert(int value);
  
};

node *new_node(int value)
{
  node *temp=new node;
  temp->data=value;
  temp->next=NULL;
  return temp;
}

void Hash::Insert(int value)
{
  int index=hash(value);
  if (hash_array[index]==NULL) {
  hash_array[index]=new_node(value);
  }
}

int main() {
  Hash h;
  for (int i = 0; i < 10; i++) {
    if (h.hash_array[i] == NULL) {
      cout << "Null ";
    } else {
      cout << "Not Null ";
    }
  }
}
