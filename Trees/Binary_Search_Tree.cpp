#include <bits/stdc++.h>
using namespace std;

class node {
public:
  node *left_child, *right_child;
  int data;
};

class Binary_Search_Tree {
public:
  node *root = NULL;
  void lvl_order_display();
  node *search(node *temp, int value);
  void create(vector<int> a);
  node *insert(node *temp, int value);
  node *rem(node *temp, int value);
  int height(node *temp);
  node *in_order_predecessor(node *temp);
  node *in_order_successor(node *temp);
};

node *Binary_Search_Tree::search(node *temp, int value) {
  if (temp == NULL) {
    cout << "Value not found.";
    return NULL;
  }

  if (temp->data == value) {
    cout << "Value found.";
    return temp;
  } else if (temp->data > value) {
    search(temp->left_child, value);
  } else {
    search(temp->right_child, value);
  }
  return NULL;
}

void Binary_Search_Tree::lvl_order_display() {
  std::queue<node *> q;
  q.push(root);
  q.push(NULL);
  while (!q.empty()) {
    node *temp = q.front();
    q.pop();
    if (temp == NULL) {
      std::cout << "\n";
      if (!q.empty()) {
        q.push(NULL);
      }
    } else {

      std::cout << temp->data << "  ";
      if (temp->left_child) {
        q.push(temp->left_child);
      }
      if (temp->right_child) {
        q.push(temp->right_child);
      }
    }
  }
}

node *Binary_Search_Tree::insert(node *temp, int value) {
  if (temp == NULL) {
    node *new_node = new node;
    new_node->data = value;
    new_node->left_child = new_node->right_child = NULL;
    return new_node;
  } else if (temp->data > value) {
    temp->left_child = insert(temp->left_child, value);
  } else if (temp->data < value) {
    temp->right_child = insert(temp->right_child, value);
  }
  return temp;
}

void Binary_Search_Tree::create(vector<int> arr) {
  for (auto i : arr) {
    insert(root, i);
  }
}

int Binary_Search_Tree::height(node *temp) {
  int x, y;
  x = y = 0;
  if (temp == NULL) {
    return 0;
  }
  x = height(temp->right_child);
  y = height(temp->right_child);
  if (x > y) {
    return x + 1;
  } else {
    return y + 1;
  }
}

node *Binary_Search_Tree::in_order_predecessor(node *temp) {
  node *predecessor = temp;
  while (predecessor && predecessor->right_child != NULL) {
    predecessor = predecessor->right_child;
  }
  return predecessor;
}

node *Binary_Search_Tree::in_order_successor(node *temp) {
  node *successor = temp;
  while (successor && successor->left_child != NULL) {
    successor = successor->left_child;
  }
  return successor;
}

node *Binary_Search_Tree::rem(node *temp, int value) {
  if (temp == NULL) {
    return NULL;
  }
  if (temp->right_child == NULL && temp->left_child == NULL) {
    if (temp == root) {
      root = NULL;
    }
    free(temp);
    return NULL;
  }
  if (temp->data > value) {
    temp->left_child = rem(temp->left_child, value);
  } else if (temp->data < value) {
    temp->right_child = rem(temp->right_child, value);
  } else {
    if (height(temp->right_child) > height(temp->left_child)) {
      node *successor = in_order_successor(temp->right_child);
      temp->data = successor->data;
      temp->right_child = rem(temp->right_child, successor->data);
    } else {
      node *predecessor = in_order_predecessor(temp->left_child);
      temp->data = predecessor->data;
      temp->left_child = rem(temp->left_child, predecessor->data);
    }
  }
  return temp;
}

int main() {
  Binary_Search_Tree a;
  vector<int> arr = {30, 20, 10, 15, 25, 40, 50, 45};
  for (auto i : arr) {
    a.root = a.insert(a.root, i);
  }
  a.lvl_order_display();
}
/*
30 20 10 15 2540 50 45
*/
